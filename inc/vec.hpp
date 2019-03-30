/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:23:43 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 16:57:00 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_HPP
# define VEC_HPP

#include <iostream>
#include <string>
#include <cmath>

#ifndef M_PI_180
# define M_PI_180 0.01745329251
#endif

namespace rt {

    class vec3 {
    public:
        float x, y, z;
        vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
        vec3(float xyz_) : x(xyz_), y(xyz_), z(xyz_) {}
        vec3() : x(0), y(0), z(0) {}
        friend std::ostream&    operator << (std::ostream& os, const vec3& v);
        vec3             operator + (const vec3 v);
        vec3             operator + (const float n);
        vec3             operator - (const vec3 n);
        vec3             operator - (const float n);
        vec3             operator * (const vec3 n);
        vec3             operator * (const float n);
        vec3        clamp(const float& lo, const float& hi);
        vec3        clamp(const vec3& lo, const vec3& hi);
        float       length(void);
        vec3        normalize(void);
        float       dot(vec3& v);
        vec3        cross(vec3& v);
        uint32_t    to_rgb(void);
    };

    struct Ray {
        vec3 origin, dir;
        Ray(vec3 o_, vec3 d_) : origin(o_), dir(d_) {}
        void    to_screen(const uint32_t width, const uint32_t height, const float aspect_ratio);
    };

}

#endif