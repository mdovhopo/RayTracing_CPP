/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:43:50 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 16:57:17 by mdovhopo         ###   ########.fr       */
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
            Shape(vec3 o_, vec3 c_, float refl_, float spec_)
            : origin(o_), color(c_), reflection(refl_), specular(spec_) {}
            Shape()
            : origin(vec3()), color(vec3(1)){}
            virtual ~Shape() {}
 	        virtual bool intersect(Ray& r, float& tnear) = 0;
            virtual vec3 get_normal(vec3& hit, Ray& ray, float tnear) = 0;
    };

    class Sphere : public Shape {
        public: 
        float radius;
        Sphere(vec3 o_, vec3 c_, float refl_, float spec_, float rad_) :
        Shape(o_, c_, refl_, spec_), radius(rad_){}
        bool    intersect(Ray& r, float& tnear);
        vec3    get_normal(vec3& hit, Ray& ray, float tnear);
        ~Sphere() {}
    };

    class Cylinder : public Shape {
        public: 
        vec3 axis;
        float radius;
        Cylinder(vec3 o_, vec3 c_, vec3 axis_, float rad_, float refl_, float spec_) :
        Shape(o_, c_, refl_, spec_), axis(axis_.normalize()), radius(rad_){}
        bool    intersect(Ray& r, float& tnear);
        vec3    get_normal(vec3& hit, Ray& ray, float tnear);
        ~Cylinder() {}
    };

    class Plane : public Shape {
        public: 
        vec3 axis;
        float far;
        Plane(vec3 o_, vec3 c_, vec3 axis_, float far_, float refl_, float spec_) :
        Shape(o_, c_, refl_, spec_), axis(axis_.normalize()), far(far_) {}
        bool    intersect(Ray& r, float& tnear);
        vec3    get_normal(vec3& hit, Ray& ray, float tnear);
        ~Plane() {}
    };

    class Cone : public Shape {
        public: 
        vec3 axis;
        float k;
        Cone(vec3 o_, vec3 c_, vec3 axis_, float k_, float refl_, float spec_) :
        Shape(o_, c_, refl_, spec_), axis(axis_.normalize()), k(k_ / 2 * M_PI_180) {}
        bool    intersect(Ray& r, float& tnear);
        vec3    get_normal(vec3& hit, Ray& ray, float tnear);
        ~Cone() {}
    };

    class PointLight {
        public:
        vec3   origin; 
        float  intensivity;
        PointLight(vec3 o_, float intens_) : origin(o_), intensivity(intens_) {}
        float compute_light(rt::Ray ray, rt::vec3 v, float spec,
                  const std::vector<std::unique_ptr<rt::Shape>>& shapes);
    };

}

#endif
