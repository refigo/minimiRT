/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 13:25:23 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing_utils.h"
#include "constant.h"
#include "libft.h"
#include "utils.h"

void	add_new_plane(t_objects **objects, char **splited)
{
	t_object	*object;
	t_plane		*plane;

	plane = malloc(sizeof(t_plane));
	object = malloc(sizeof(t_object));
	ft_assert(plane != FT_NULL, "Assert: malloc failed in add_new_plane");
	ft_assert(object != FT_NULL, "Assert: malloc failed in add_new_plane");
	plane->center = parse_vec3(splited[1]);
	plane->orientation = get_unit_vec3(parse_vec3(splited[2]));
	object->albedo = parse_vec3(splited[3]);
	object->element = plane;
	object->type = PLANE;
	ft_lstadd_back(objects, ft_lstnew(object)); //init scene에서 objects null 초기화
}