/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:49:51 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 18:19:54 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.hpp>

float       rt::PointLight::compute_light(rt::Ray ray, rt::vec3 v, float spec,
                  const std::vector<std::unique_ptr<rt::Shape>>& shapes)
{
    float light = 0;
    rt::vec3 l = this->origin - ray.origin;
    float tnear = INFINITY;
    float index = find_closest_shape(shapes, tnear, ray);
    if (index < 0 || rt::length(ray.origin - this->origin) < rt::length(ray.origin - ray.origin + l * tnear))
    {
        float n_dot_l = ray.dir.dot(l);
        if (n_dot_l > 0)
            light += this->intensity * n_dot_l / (rt::length(ray.dir) * rt::length(l));
        if (spec > 0)
        {
            rt::vec3 r =  ray.dir * (2.0f * ray.dir.dot(l)) - l;
            float ray_dot_v = r.dot(v);
            light += this->intensity * pow(ray_dot_v / (rt::length(r) * rt::length(v)), spec);
        }
    }
    return light;
}
