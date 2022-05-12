#include "tracing.h"
#include <math.h>

#include "test.h"

void	print_ray(t_ray *ray)
{
	printf("ray :\n");
	print_vec3(&ray->direction);
}

t_bool	hit_sphere(t_object *object, t_ray ray, t_hit_record *record)
{
	t_sphere	*sphere;
	t_vec3		co;
	double		a;
	double		half_b;
	double		c;
	double		discriminant;
	double		sqrtd;
	double		root;

	sphere = object->element;
	co = sub_vec3(ray.origin, sphere->center);
	a = dot_vec3(ray.direction, ray.direction);
	half_b = dot_vec3(ray.direction, co);
	c = dot_vec3(co, co) - sphere->radius_square; 
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < record->min || record->max < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < record->min || record->max < root)
			return (FALSE);
	}
	record->distance_from_ray_origin = root;
	record->hit_point = get_point_ray_reach(ray, root);
	record->normal = div_vec3_t(sub_vec3(record->hit_point, sphere->center), sphere->radius); // get_unit으로 바꿀것

	// set normal
	record->front_face = (dot_vec3(ray.direction, record->normal) < 0);
	if (record->front_face == FALSE)
		record->normal = mul_vec3_t(record->normal, -1);

	record->albedo = object->albedo;
	return (TRUE);
}

t_bool	hit_object(t_object *object, t_ray ray, t_hit_record *record)
{
	t_bool	is_hitting;
	
	is_hitting = FALSE;
	if (object->type == SPHERE)
		is_hitting = hit_sphere(object, ray, record);
	if (object->type == PLANE)
		is_hitting = hit_plane(object, ray, record);
	return (is_hitting);
}

t_bool	hit_objects(t_objects *objects, t_ray ray, t_hit_record *record)
{
	t_bool			is_hitting;
	t_hit_record	tmp_record;

	tmp_record = *record;
	is_hitting = FALSE;
	while (objects)
	{
		if (hit_object(objects->content, ray, record))
		{
			is_hitting = TRUE;
			record->max = record->distance_from_ray_origin;
		}
		objects = objects->next;
	}
	return (is_hitting);
}
