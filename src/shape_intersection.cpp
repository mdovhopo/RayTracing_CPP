/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_intersection.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:18:51 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 18:19:33 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.hpp>

static bool bad_values_filter(float& tnear, rt::vec3 sol)
{
    if (sol.z < 0)
        return false;
    bool check = false;
    if (sol.x < tnear && sol.x > RAY_MIN_LENGTH && sol.x < RAY_MAX_LENGTH)
    {
		tnear = sol.x;
        check = true;
    }
	if (sol.y < tnear && sol.y > RAY_MIN_LENGTH && sol.y < RAY_MAX_LENGTH)
    {
	    tnear = sol.y;
        check = true;
    }
    return (check);
}

bool       rt::Sphere::intersect(Ray& r, float& tnear)
{
    rt::vec3  oc = r.origin - this->origin;
    float   a = r.dir.dot(r.dir);
    float   b = 2 * oc.dot(r.dir);
	float   c = oc.dot(oc) - this->radius * this->radius;
    return bad_values_filter(tnear, rt::solve_quadric(a, b, c));
}

bool        rt::Cylinder::intersect(Ray& r, float& tnear)
{
    float rdir_dot_axis = r.dir.dot(this->axis);
    rt::vec3 x = r.origin - this->origin;
    float a = r.dir.dot(r.dir) - rdir_dot_axis * rdir_dot_axis;
    float b = 2 * (r.dir.dot(x) - r.dir.dot(this->axis) * x.dot(this->axis));
    float c = x.dot(x) - x.dot(this->axis) * x.dot(this->axis) - this->radius * this->radius;
    return bad_values_filter(tnear, rt::solve_quadric(a, b, c));
} 

bool        rt::Plane::intersect(Ray& r, float& tnear)
{
    float v0 = r.origin.dot(this->axis);
    float vd = r.dir.dot(this->axis);
    if (vd == 0)
        return false;
    float t = -(v0 + this->far) / vd;
    if (t > 0)
        return bad_values_filter(tnear, rt::vec3(t, t, 1));
    return false;
}

bool        rt::Cone::intersect(Ray& r, float& tnear)
{
    rt::vec3 x = r.origin - this->origin;
    float rdir_dot_axis = r.dir.dot(this->axis);
    float x_dot_axis = x.dot(this->axis);
    float a = r.dir.dot(r.dir) - (1 + this->k * this->k) * rdir_dot_axis * rdir_dot_axis;
    float b = 2 * (r.dir.dot(x) - (1 + this->k * this->k) * rdir_dot_axis * x_dot_axis);
    float c = x.dot(x) - (1 + this->k * this->k) * x_dot_axis * x_dot_axis;
    return bad_values_filter(tnear, rt::solve_quadric(a, b, c));
}