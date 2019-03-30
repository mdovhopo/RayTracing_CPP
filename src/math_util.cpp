/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_util.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:07:25 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 15:43:51 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.hpp>

rt::vec3  rt::solve_quadric(float a, float b, float c)
{
    float disc = b * b - 4 * a * c;
    if (disc < 0)
        return (rt::vec3(0, 0, -1));
    return (rt::vec3((-b + (float)sqrt(disc)) / (2 * a), (-b - (float)sqrt(disc)) / (2 * a), 1));
}

float	rt::length(rt::vec3 v)
{
	return sqrt(v.dot(v));
}