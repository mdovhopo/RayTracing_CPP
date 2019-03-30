/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_abstraction.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:19:58 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 18:15:48 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sdl_abstraction.hpp>


rt::SDL::SDL(const char * name, const uint32_t w_, const uint32_t h_) : width(w_), height(h_)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(name,
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				width, height, 0);
    surface = SDL_GetWindowSurface(window);
    bzero(surface->pixels, width * height * sizeof(int32_t));
    aspect_ratio = width / (float)height;
}

rt::SDL::~SDL()
{
    SDL_DestroyWindow(window);
}

uint32_t    rt::SDL::getWidth()
{
    return width;
}

uint32_t    rt::SDL::getHeight()
{
    return width;
}

float       rt::SDL::getAspectRatio()
{
    return aspect_ratio;
}

void    rt::SDL::update_window()
{
    SDL_UpdateWindowSurface(window);
}

void    rt::SDL::color_pixel(uint32_t color, uint32_t x, uint32_t y)
{
    ((uint32_t *)(this->surface->pixels))[y * width + x] = color;
}

bool    rt::SDL::if_exit_event(SDL_Event e)
{
    if (SDL_QUIT == e.type ||
       (SDL_KEYDOWN == e.type && SDL_SCANCODE_ESCAPE == e.key.keysym.scancode))
       return true;
    return false;
}
