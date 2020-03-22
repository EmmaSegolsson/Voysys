#define _USE_MATH_DEFINES

#include "Vec3.h"

#include <iostream>
#include <algorithm>    // std::copy_if, std::distance
#include <numeric>		// std::accumulate
#include <vector>       // std::vector
#include <cmath>

//using namespace std;

const double EPSILON = 10e-15;

// Explicit constructor
Vec3::Vec3()
	: x{ 0 }, y{ 0 }, z{ 0 } {}


// Constructor
Vec3::Vec3(int xIn, int yIn, int zIn)
	: x{ xIn }, y{ yIn }, z{ zIn } {}



Vec3::Vec3(const Vec3 &inVec)
	: x{ inVec.getX() }, y{ inVec.getY() }, z{ inVec.getZ() } {}



// Getters
int Vec3::getX() const {
	return x;
}

int Vec3::getY() const {
	return y;
}

int Vec3::getZ() const {
	return z;
}

// Adders
void Vec3::addX(int n) {
	x = x + n;
}

void Vec3::addY(int n) {
	y += n;
}

void Vec3::addZ(int n) {
	z += n;
}


// Operators

Vec3 operator+(const Vec3 &lhs, const Vec3 &rhs) {
	Vec3 returnVec(lhs);

	returnVec += rhs;
	return returnVec;
}

Vec3 operator-(const Vec3 &lhs, const Vec3 &rhs) {
	Vec3 returnVec(lhs);

	returnVec -= rhs;
	return returnVec;
}

Vec3& Vec3::operator-=(const Vec3 &rhs) {
	x -= rhs.getX();
	y -= rhs.getY();
	z -= rhs.getZ();

	return *this;
}

Vec3& Vec3::operator+=(const Vec3 &rhs) {
	x += rhs.getX();
	y += rhs.getY();
	z += rhs.getZ();

	return *this;
}

Vec3& Vec3::operator*(double n) {
	x *= n;
	y *= n;
	z *= n;

	return *this;
}

Vec3& Vec3::operator/(double n) {
	x /= n;
	y /= n;
	z /= n;

	return *this;
}



// Member functions

void Vec3::norm() {
	if (abs(x) <= EPSILON && abs(y) <= EPSILON && abs(z) <= EPSILON) return;

	const double abs = sqrt((x * x) + (y * y) + (z * z));

	x = x / abs;
	y = y / abs;
	z = z / abs;
}
