/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:44:09 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/28 16:19:16 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec.hpp>
#include <string>
#include <cmath>

float           rt::vec3::dot(const rt::vec3& v)
{
	return (x * v.x + y * v.y + z * v.z);
}

rt::vec3            rt::vec3::cross(rt::vec3& v)
{
	return rt::vec3(y * v.z - z * v.y,
					z * v.x - x * v.z,
					x * v.y - y * v.x);
}

void                rt::vec3::normalize(void)
{
	float one_over_sqrt = 1 / sqrt(this->dot(*this));
	this->x *= one_over_sqrt;
	this->y *= one_over_sqrt;
	this->z *= one_over_sqrt;
}

std::ostream&   rt::operator<<(std::ostream& os, const rt::vec3& v)
{
	os << "x: " << v.x << " y: " << v.y << " z: " << v.z; 
	return os;
}

rt::vec3        rt::vec3::operator + (const rt::vec3& v)
{
	return rt::vec3(x + v.x, y + v.y, z + v.z);
}

rt::vec3        rt::vec3::operator + (const int& n)
{
	return rt::vec3(x + n, y + n, z + n);
}

rt::vec3        rt::vec3::operator - (const rt::vec3& v)
{
	return rt::vec3(x - v.x, y - v.y, z - v.z);
}

rt::vec3        rt::vec3::operator - (const int& n)
{
	return rt::vec3(x - n, y - n, z - n);
}

rt::vec3        rt::vec3::operator * (const rt::vec3& v)
{
	return rt::vec3(x * v.x, y * v.y, z * v.z);
}

rt::vec3        rt::vec3::operator * (const int& n)
{
	return rt::vec3(x * n, y * n, z * n);
}

rt::vec3        rt::vec3::clamp(const float& lo, const float& hi)
{
	return (rt::vec3(
		this->x > hi ? hi : this->x < lo ? lo : this->x,
		this->y > hi ? hi : this->y < lo ? lo : this->y,
		this->z > hi ? hi : this->z < lo ? lo : this->z
	));
}

rt::vec3        rt::vec3::clamp(const vec3& lo, const vec3& hi)
{
	return (rt::vec3(
		this->x > hi.x ? hi.x : this->x < lo.x ? lo.x : this->x,
		this->y > hi.y ? hi.y : this->y < lo.y ? lo.y : this->y,
		this->z > hi.z ? hi.z : this->z < lo.z ? lo.z : this->z
	));
}

float			rt::vec3::length(void)
{
	return (sqrt(this->dot(*this)));
}