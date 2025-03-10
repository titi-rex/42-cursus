/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:14:59 by louisa            #+#    #+#             */
/*   Updated: 2023/10/04 13:27:10 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h"

inline t_vec3d	ft_rotate_vec_x(t_vec3d v, float rad)
{
	t_vec3d	cpy;

	cpy.x = v.x;
	cpy.y = v.y * cos(rad) + v.z * -sin(rad);
	cpy.z = v.y * sin(rad) + v.z * cos(rad);
	return (cpy);
}

inline t_vec3d	ft_rotate_vec_y(t_vec3d v, float rad)
{
	t_vec3d	cpy;

	cpy.x = v.x * cos(rad) + v.z * sin(rad);
	cpy.y = v.y;
	cpy.z = v.x * -sin(rad) + v.z * cos(rad);
	return (cpy);
}

inline t_vec3d	ft_rotate_vec_z(t_vec3d v, float rad)
{
	t_vec3d	cpy;

	cpy.x = v.x * cos(rad) + v.y * -sin(rad);
	cpy.y = v.x * sin(rad) + v.y * cos(rad);
	cpy.z = v.z;
	return (cpy);
}

t_vec3d	math_vec_op(t_vec3d u, t_vec3d v, char op)
{
	t_vec3d	res;

	if (op == '-')
	{
		res.x = u.x - v.x;
		res.y = u.y - v.y;
		res.z = u.z - v.z;
	}
	else if (op == '+')
	{
		res.x = u.x + v.x;
		res.y = u.y + v.y;
		res.z = u.z + v.z;
	}
	else
	{
		res.x = u.y * v.z - u.z * v.y;
		res.y = u.z * v.x - u.x * v.z;
		res.z = u.x * v.y - u.y * v.x;
	}
	return (res);
}

t_vec3d	math_vec_k_prod(t_vec3d u, float k)
{
	t_vec3d	res;

	res.x = k * u.x;
	res.y = k * u.y;
	res.z = k * u.z;
	return (res);
}
