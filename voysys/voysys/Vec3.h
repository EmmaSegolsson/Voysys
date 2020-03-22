/*#define _USE_MATH_DEFINES


#include <iostream>
#include <algorithm>    // std::copy_if, std::distance
#include <numeric>		// std::accumulate
#include <vector>       // std::vector*/
#include <cmath>

//using namespace std;


class Vec3 {
public:
	// Constructors
	Vec3();
	Vec3(int xIn, int yIn, int zIn);
	Vec3(const Vec3 &inVec);// = default;

	// Decstructor
	~Vec3() = default;

	// Operators
	Vec3& operator+=(const Vec3 &rhs);
	Vec3& operator-=(const Vec3 &rhs);
	Vec3& operator*(double n);
	Vec3& operator/(double n);
	friend Vec3 operator+(const Vec3 &lhs, const Vec3 &rhs);
	friend Vec3 operator-(const Vec3 &lhs, const Vec3 &rhs);

	// Getters
	int getX() const;
	int getY() const;
	int getZ() const;

	// Adders
	void addX(int x);
	void addY(int y);
	void addZ(int z);

	// Member functions
	void norm();

protected:
	int x;
	int y;
	int z;
};

