#pragma once
#include <ostream>
#include <cmath>

class vec3
{
private:
	float _x;
	float _y;
	float _z;

public:
	vec3(float x, float y, float z) : _x(x), _y(y), _z(z) {}
	vec3(const vec3& other) : _x(other._x), _y(other._y), _z(other._z) {}
	vec3() : vec3(0, 0, 0) {}
	vec3(float val) : vec3(val, val, val) {}
	vec3(float x, float y) : vec3(x, y, 0) {}

	float get_x() const { return _x; }
	float get_y() const { return _y; }
	float get_z() const { return _z; }

	vec3 operator-() const {
		return vec3(-_x, -_y, -_z);
	}

	vec3 operator-(const vec3& other) const {
		return vec3(_x - other._x, _y - other._y, _z - other._z);
	}

	vec3 operator+(const vec3& other) const {
		return vec3(_x + other._x, _y + other._y, _z + other._z);
	}

	vec3 operator*(float scalar) const {
		return vec3(scalar * _x, scalar * _y, scalar * _z);
	}

	vec3 operator/(float scalar) const {
		return vec3(_x / scalar, _y / scalar, _z / scalar);
	}

	float getLength() const {
		return std::sqrt(_x * _x + _y * _y + _z * _z);
	}

	vec3 unit_vector() const {
		float length = getLength();
		return vec3(_x / length, _y / length, _z / length);
	}

	vec3 operator*(const vec3& other) const {
		return vec3(_y * other._z - other._y * _z,
			_z * other._x - _x * other._z,
			_x * other._y - _y * other._x);
	}

	float dot(const vec3& other) const {
		return _x * other._x + _y * other._y + _z * other._z;
	}
};

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.get_x() << ", " << v.get_y() << ", " << v.get_z();
}
