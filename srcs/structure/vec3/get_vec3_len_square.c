/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec3_len_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgo <mgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:57:58 by mgo               #+#    #+#             */
/*   Updated: 2022/05/09 14:58:05 by mgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	get_vec3_len_square(t_vec3 vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}