/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:11:55 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 19:42:11 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.hpp>

int         main(void)
{
    rt::SDL sdl("RT", 800, 600);

    // TODO add support for configuration files to prevent hardcoding objects
    // TODO perform calculations on GPU  

    std::vector<std::unique_ptr<rt::Shape>> shapes;
    std::vector<std::unique_ptr<rt::PointLight>> lights;

    shapes.emplace_back(new rt::Sphere(rt::vec3(2, 0, 5), rt::vec3(0.5, 0, 0.5), 1.0f, 1000.0f, 1.0f));
    shapes.emplace_back(new rt::Sphere(rt::vec3(-2, 0, 5), rt::vec3(0, 0.5, 0.5), 0, 100.0f, 1.0f));
    shapes.emplace_back(new rt::Cylinder(rt::vec3(0, 0, 5), rt::vec3(0, 0.8, 0), rt::vec3(0, 1, 0), 1, 0.5, 800.0f));
    shapes.emplace_back(new rt::Plane(rt::vec3(0, 0, 0), rt::vec3(0.3, 0.1, 0.3), rt::vec3(0, 1, 0), 1, 0, -1));

    lights.emplace_back(new rt::PointLight(rt::vec3(0, 5, -2), 1));

    rt_loop(sdl, shapes, lights);

    while (1)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        if (sdl.if_exit_event(event))
            break ;
        float x = SDL_GetTicks();
        rt_loop(sdl, shapes, lights);
        float y = SDL_GetTicks() - x;
        if (y != 0)
			std::cout << "Fps: " << 1000 / y << std::endl;
        sdl.update_window();
    }

    return (0);
}
