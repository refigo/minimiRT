/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:36:44 by mgo               #+#    #+#             */
/*   Updated: 2022/05/12 14:32:20 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tracing.h"
#include "test.h"

static t_ray	get_pixel_ray(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.origin = cam->origin;
	ray.direction = get_unit_vec3(
						sub_vec3(
							add_vec3(
								add_vec3(
									cam->left_bottom, 
									mul_vec3_t(cam->horizontal_vec, u)), 
								mul_vec3_t(cam->vertical_vec, v)), 
							cam->origin));
	return (ray);
}

t_color3	get_pixel_color(t_scene *scene, t_ray pixel_ray)
{
	t_hit_record	record;

	record = init_hit_record();
	if (hit_objects(scene->world.objects, pixel_ray, &record))
		return (get_color_from_phong_lighting(scene, pixel_ray, record));
	else
		return (init_vec3(0, 0, 0)); // return black
}

void	trace_ray_and_draw_pixel(t_scene *scene, double u, double v, int x, int y)
{
	t_ray		pixel_ray;
	t_color3	pixel_color;

	pixel_ray = get_pixel_ray(&scene->camera, u, v);
	pixel_color = get_pixel_color(scene, pixel_ray);
	draw_pixel(scene, pixel_color, u, v, x, y);
	// write_color(&pixel_color);
}

void	drive_ray_tracing(t_scene *scene)
{
	int			x_coord;
	int			y_coord;
	double		u;
	double		v;
	t_mlx_info	*mlx_info;

	// printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
	y_coord = scene->canvas.height;
	while (--y_coord >= 0)
	{
		x_coord = -1;
		while (++x_coord < scene->canvas.width)
		{
			u = (double)x_coord / (scene->canvas.width - 1);
			v = (double)y_coord / (scene->canvas.height - 1);
			trace_ray_and_draw_pixel(scene, u, v, x_coord, y_coord);
		}
	}
	// mlx_put_image
	mlx_info = &scene->mlx_info;
	mlx_put_image_to_window(mlx_info->mlx, mlx_info->win, mlx_info->img, 0, 0);
}
