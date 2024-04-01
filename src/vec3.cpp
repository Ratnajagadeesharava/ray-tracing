#include "vec3.hpp"

vec3::vec3(float x, float y, float z):_x(x),_y(y),_z(z)
{
	length = this->getLength();
}

