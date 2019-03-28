/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:11:55 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/28 17:28:18 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.hpp>
// #include <vec.hpp>

int     main(void)
{
    rt::vec3 v1(1, 2, 3), v2(1.3, 4.1, 0.1);
    rt::Shape *shape = new rt::Sphere(v1, v2, 1, 1, 100);

    std::vector<rt::Shape*> v;

    v.push_back(shape);

    std::cout << v[0]->intersect(rt::Ray(v1, v2));
    std::cout << v[0]->origin << std::endl;
    std::cout << v[0]->radius << std::endl;
    std::cout << v[0]->color << std::endl;
    std::cout << v[0]->reflection << std::endl;
    std::cout << v[0]->specular << std::endl;
    return (0);
}