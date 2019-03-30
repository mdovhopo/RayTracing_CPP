/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <mdovhopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:44:09 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/03/30 16:26:38 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec.hpp>
#include <string>
#include <cmath>

float           rt::vec3::dot(rt::vec3& v)
{
	return (x * v.x + y * v.y + z * v.z);
}

rt::vec3            rt::vec3::cross(rt::vec3& v)
{
	return rt::vec3(y * v.z - z * v.y,
					z * v.x - x * v.z,
					x * v.y - y * v.x);
}

rt::vec3               rt::vec3::normalize(void)
{
	float one_over_sqrt = 1 / sqrt(this->dot(*this));
	return *this * one_over_sqrt;
}

std::ostream&   rt::operator<<(std::ostream& os, const rt::vec3& v)
{
	os << "x: " << v.x << " y: " << v.y << " z: " << v.z; 
	return os;
}

rt::vec3        rt::vec3::operator + (const rt::vec3 v)
{
	return rt::vec3(x + v.x, y + v.y, z + v.z);
}

rt::vec3        rt::vec3::operator + (const float n)
{
	return rt::vec3(x + n, y + n, z + n);
}

rt::vec3        rt::vec3::operator - (const rt::vec3 v)
{
	return rt::vec3(x - v.x, y - v.y, z - v.z);
}

rt::vec3        rt::vec3::operator - (const float n)
{
	return rt::vec3(x - n, y - n, z - n);
}

rt::vec3        rt::vec3::operator * (const rt::vec3 v)
{
	return rt::vec3(x * v.x, y * v.y, z * v.z);
}

rt::vec3        rt::vec3::operator * (const float n)
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

uint32_t		rt::vec3::to_rgb(void)
{
    return (int)(this->x) * 65536 + (int)(this->y) * 256 + (int)(this->z);
}

void			rt::Ray::to_screen(const uint32_t width, const uint32_t height, const float aspect_ratio)
{
	const float fov = tan(M_PI * 0.5f * 60 / 180.0f);
	this->dir.x = (2.0f * this->dir.x / (float)width - 1.0f) * aspect_ratio * fov;
	this->dir.y = (2.0f * this->dir.y / (float)height - 1.0f) * -1.0f * fov;
}