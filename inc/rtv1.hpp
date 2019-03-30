/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:23:41 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 19:36:36 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_HPP
# define RTV1_HPP

// srd includes

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>
#include <thread>

#define THREAD_NUM 8

// libs

#include <SDL2/SDL.h>

// project includes

#include <vec.hpp>
#include <shape.hpp>
#include <sdl_abstraction.hpp>

// exit defines for SDL events

# define TYPE_RED_CROSS SDL_QUIT == event.type
# define TYPE_ESC SDL_KEYDOWN == event.type
# define ESCAPE_PRESSED SDL_SCANCODE_ESCAPE == event.key.keysym.scancode
# define QUIT_EVENT (TYPE_RED_CROSS) || (TYPE_ESC && ESCAPE_PRESSED)

// Ray Tracing defines

# define RAY_MIN_LENGTH 1e-3f
# define RAY_MAX_LENGTH 1.0e30f
# define MAX_RAY_DEPTH 5

// util math

namespace rt {

    rt::vec3  solve_quadric(float a, float b, float c);
    float     length(vec3 v);

}

// Ray tracing computation functions

void        rt_loop(rt::SDL& sdl, const std::vector<std::unique_ptr<rt::Shape>>& shapes,
                                    const std::vector<std::unique_ptr<rt::PointLight>>& lights);
int32_t    find_closest_shape(const std::vector<std::unique_ptr<rt::Shape>>& shapes, float& tnear, rt::Ray& ray);

#endif