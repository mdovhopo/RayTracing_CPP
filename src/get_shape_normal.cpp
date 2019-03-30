/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape_normal.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:17:35 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 18:18:12 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.hpp>

rt::vec3    rt::Sphere::get_normal(vec3& hit, Ray& ray, float tnear)
{
    return (hit - this->origin).normalize();
}

rt::vec3    rt::Cylinder::get_normal(vec3& hit, Ray& ray, float tnear)
{
    rt::vec3 axis_m_tnear = this->axis * tnear;
    rt::vec3 r_org_sub_cyl_org = ray.origin - this->origin;
    float m = ray.dir.dot(axis_m_tnear) + this->axis.dot(r_org_sub_cyl_org);
    return (hit - this->origin - this->axis * m).normalize();
}

rt::vec3    rt::Plane::get_normal(vec3& hit, Ray& ray, float tnear)
{
    return this->axis;
}

rt::vec3    rt::Cone::get_normal(vec3& hit, Ray& ray, float tnear)
{
    rt::vec3 axis_m_tnear = this->axis * tnear;
    rt::vec3 r_org_sub_cyl_org = ray.origin - this->origin;
    float m = ray.dir.dot(axis_m_tnear) + this->axis.dot(r_org_sub_cyl_org);
    return (hit - this->origin - this->axis * (1 + this->k * this->k) * m).normalize();
}