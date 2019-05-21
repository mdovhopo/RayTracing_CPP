/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:22:59 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 19:48:08 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.hpp>

int32_t    find_closest_shape(const std::vector<std::unique_ptr<rt::Shape>>& shapes, float& tnear, rt::Ray& ray)
{
    int32_t index = -1;
    for (int i = 0; i < shapes.size(); i++)
        if (shapes[i]->intersect(ray, tnear))
            index = i;
    return index;
}

static rt::vec3    trace(const std::vector<std::unique_ptr<rt::Shape>>& shapes,
                  const std::vector<std::unique_ptr<rt::PointLight>>& lights,
                  rt::Ray ray, int depth)
{
    float       tnear = INFINITY;
    int32_t    index;
    rt::vec3    color;
    if ((index = find_closest_shape(shapes, tnear, ray)) < 0)
        return rt::vec3(0, 0, 0);
    rt::vec3 hit = ray.origin + ray.dir * tnear;
    rt::vec3 normal = shapes[index]->get_normal(hit, ray, tnear);
    float light = 0;
    for (int i = 0; i < lights.size(); i++)
        light += lights[i]->compute_light(rt::Ray(hit, normal), ray.dir * -1, shapes[index]->specular, shapes);
    color = shapes[index]->color * light;
    if (depth > MAX_RAY_DEPTH)
        return rt::vec3(0, 0, 0);
    if (shapes[index]->reflection > 0)
    {
        rt::vec3 inv_ray_dir = ray.dir * (-1.0f);
        rt::vec3 refl_dir = normal * 2 * normal.dot(inv_ray_dir) - inv_ray_dir;
        rt::vec3 refl_color = trace(shapes, lights, rt::Ray(hit, refl_dir), depth + 1);
        color = color * (1 - shapes[index]->reflection) + refl_color * shapes[index]->reflection;
    }
    return color;
}

void        thread_exec(rt::SDL& sdl,
    const std::vector<std::unique_ptr<rt::Shape>>& shapes,
    const std::vector<std::unique_ptr<rt::PointLight>>& lights, uint8_t& tid)
{
    for (int x = 0; x < sdl.getWidth(); x++)
         for (int y = tid; y < sdl.getHeight(); y += THREAD_NUM)
         {
            rt::Ray view(rt::vec3(0),rt::vec3(x, y, 1));
            view.to_screen(sdl.getWidth(), sdl.getHeight(), sdl.getWidth() / (float)sdl.getHeight());
            sdl.color_pixel((trace(shapes, lights, view , 0) * 255).clamp(0, 255).to_rgb(), x, y);
         }
}

void        rt_loop(rt::SDL& sdl, const std::vector<std::unique_ptr<rt::Shape>>& shapes,
                                    const std::vector<std::unique_ptr<rt::PointLight>>& lights)
{
    std::thread threads[THREAD_NUM];
    uint8_t *threads_ids = new uint8_t[THREAD_NUM];
    for (int i = 0; i < THREAD_NUM; i++)
    {
        threads_ids[i] = i;
        threads[i] = std::thread(thread_exec, std::ref(sdl), std::ref(shapes), std::ref(lights), std::ref(threads_ids[i]));
    }
    for (int i = 0; i < THREAD_NUM; i++)
        threads[i].join();
    delete [] threads_ids;
}
