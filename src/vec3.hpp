#pragma once
#include <ostream>

/// <summary>
/// TODO:
///		declare vector3
///		negative vec3
/// 
///		vector addition
///		dot product
///		vector product
///		vector substraction
///		scalar multiplication
///		scalar division
///		magnitude or length
///Assumptions every thing in float
/// </summary>
class vec3
{
private:
	float _x;
	float _y;
	float _z;

public:
	vec3(float x, float y, float z);
	vec3(vec3 const& other) : _x(other._x), _y(other._y), _z(other._z) {}	
	vec3() : _x(0), _y(0), _z(0) {}
	vec3(float val) : _x(val), _y(val), _z(val) {}
	vec3(float x, float y) : _x(x), _y(y), _z(0) {}
	
	inline float get_x() const { return _x; }
	inline float get_y() const { return _y; }
	inline float get_z() const { return _z; }
	vec3 operator-() const { 
		return vec3(-_x, -_y, -_z); 
	}

	vec3 operator-(vec3 other) const{
		return vec3(_x - other.get_x(), _y - other.get_y(), _z - other.get_z());
	}
	vec3 operator+(vec3 other) const {
		return vec3(_x + other.get_x(), _y + other.get_y(), _z + other.get_z());
	}

	vec3 operator*(float scalar) const {
		return vec3(scalar*_x, scalar * _y, scalar * _z);
	}
	vec3 operator/(float scalar) const {
		return vec3( _x/ scalar,  _y / scalar,  _z / scalar);
	}
	float length() const {
		return sqrt(_x * _x + _y * _y + _z * _z);
	}
	vec3 unit_vector() const {
		float length = this->length();
		return vec3(_x /length , _y / length, _z / length);
	}
	vec3 operator*(vec3 other) const {
		return vec3(_y * other.get_z() - other.get_y() * _z,
			_z * other.get_x() - _x * other.get_z(),
			_x * other.get_y() - _y * other.get_x()
		);
	}
	//dot product
	float dot(vec3 other) const {
		return _x * other.get_x() + _y * other.get_y() + _z * other.get_z();
	}
	
};



inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.get_x() << ", " << v.get_y() << ", " << v.get_z();
}
