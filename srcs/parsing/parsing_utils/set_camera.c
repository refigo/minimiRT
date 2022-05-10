/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mypark <mypark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:27:02 by mypark            #+#    #+#             */
/*   Updated: 2022/05/10 14:14:34 by mypark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "vec3.h"
#include "parsing_utils.h"

void	set_camera(t_camera *camera, char **splited)
{
	t_vec3	orientation;
	double	fov;

	copy_vec3(parse_vec3(splited[1]), &camera->origin);
	orientation = get_unit_vec3(parse_vec3(splited[2]));
	fov = parse_double(splited[3]);
}