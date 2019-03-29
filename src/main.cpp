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

    float tnear = 0;

    std::vector<std::unique_ptr<rt::Shape>> v;

    v.emplace_back(new rt::Sphere(v1, v2, 1, 1, 100));
    std::cout << v[0]->intersect(rt::Ray(v1, v2), tnear) << std::endl;
    return (0);
}
