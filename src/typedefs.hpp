#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <limits>

#include "vec3.hpp"
#include "Interval.h"
#include "Hittable.hpp"

using point = vec3;
using color = vec3;

constexpr float aspectRatio(float width, float height) {
    return width / height;
}

constexpr float infinity = std::numeric_limits<float>::infinity();
constexpr float pi = 3.1415926535897932385f;