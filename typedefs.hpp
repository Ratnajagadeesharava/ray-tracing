#pragma once
#include "vec3.hpp"
typedef vec3 point;
typedef vec3 color;


constexpr float aspectRatio(float width, float height) {
	return width / height;
}