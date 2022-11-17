#include "../include/vec3.h"
#include "../include/vec2.h"
#include <cmath>

namespace ntshm {

vec3::vec3(): x(0.0f), y(0.0f), z(0.0f) {}
vec3::vec3(float _x, float _y, float _z): x(_x), y(_y), z(_z) {}
vec3::vec3(float _x, vec2 _yz): x(_x), y(_yz.x), z(_yz.y) {}
vec3::vec3(vec2 _xy, float _z): x(_xy.x), y(_xy.y), z(_z) {}

float vec3::length() {
	return std::sqrt((x * x) + (y * y) + (z * z));
}

vec3 vec3::normalize() {
	float l = length();

	return vec3(x / l,
		y / l,
		z / l);
}

std::string vec3::to_string() {
	return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
}

float dot(const vec3& a, const vec3& b) {
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

vec3 cross(const vec3& a, const vec3& b) {
	return vec3(a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}

}