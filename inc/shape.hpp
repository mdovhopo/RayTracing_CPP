/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:43:50 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/28 17:07:55 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_HPP
# define SHAPE_HPP

#include <vec.hpp>

namespace rt {

    class Shape {
        public:
            vec3 origin, color;
            float reflection, specular;
            Shape(vec3& o_, vec3& c_, float r_, float s_)
            : origin(o_), color(c_), reflection(r_), specular(s_) {}
            Shape(vec3& o_, vec3& c_)
            : origin(o_), color(c_), reflection(0), specular(-1) {}
            Shape()
            : origin(vec3()), color(vec3(1)), reflection(0), specular(-1) {}
            virtual ~Shape() {}
 	    virtual bool intersect(const Ray& r, float& tnear) = 0;
    };

    class Sphere : public Shape {
        public: 
        float radius;
        Sphere(vec3& o_, vec3& c_, float rad_, float refl_, float spec_) :
        Shape(o_, c_, refl_, spec_), radius(rad_) {}
        bool    intersect(const Ray& r, float& tnear);
        ~Sphere() {}
    };
}

#endif
