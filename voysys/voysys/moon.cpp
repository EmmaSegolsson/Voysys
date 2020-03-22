using namespace std;
#include <iostream>

const double EPSILON = 10e-15;

#include "Vec3.h";
#include "moon.h";

// Explicit constructor
moon::moon() {
	position = { 0, 0, 0 };
	velocity = { 0, 0, 0 };
}

// Constructor
moon::moon(int xPos, int yPos, int zPos)
{
	position = { xPos, yPos, zPos };
	velocity = { 0, 0, 0 };
}


// Getters
int moon::getX() const {
	return position.getX();
}

int moon::getY() const {
	return position.getY();
}

int moon::getZ() const {
	return position.getZ();
}

Vec3 moon::getPosition() {
	return position;
}

Vec3 moon::getVelocity() {
	return velocity;
}


// Memberfunction
// X
void moon::addXGravity(int coord1, int coord2, int coord3) {

	if (position.getX() > coord1) {
		velocity.addX(-1);
	}
	else if (position.getX() < coord1) {
		velocity.addX(1);
	}

	if (position.getX() > coord2) {
		velocity.addX(-1);
	}
	else if (position.getX() < coord2) {
		velocity.addX(1);
	}

	if (position.getX() > coord3) {
		velocity.addX(-1);
	}
	else if (position.getX() < coord3) {
		velocity.addX(1);
	}
}
// Y
void moon::addYGravity(int coord1, int coord2, int coord3) {

	if (position.getY() > coord1) {
		velocity.addY(-1);
	}
	else if (position.getY() < coord1) {
		velocity.addY(1);
	}

	if (position.getY() > coord2) {
		velocity.addY(-1);
	}
	else if (position.getY() < coord2) {
		velocity.addY(1);
	}

	if (position.getY() > coord3) {
		velocity.addY(-1);
	}
	else if (position.getY() < coord3) {
		velocity.addY(1);
	}
}
// Z
void moon::addZGravity(int coord1, int coord2, int coord3) {

	if (position.getZ() > coord1) {
		velocity.addZ(-1);
	}
	else if (position.getZ() < coord1) {
		velocity.addZ(1);
	}

	if (position.getZ() > coord2) {
		velocity.addZ(-1);
	}
	else if (position.getZ() < coord2) {
		velocity.addZ(1);
	}

	if (position.getZ() > coord3) {
		velocity.addZ(-1);
	}
	
else if (position.getZ() < coord3) {
		velocity.addZ(1);
	}
}

void moon::updatePosition() {
	position = position + velocity;
}

int moon::calculatePotentialEnergy(){
	int x = abs(position.getX());
	int y = abs(position.getY());
	int z = abs(position.getZ());
	int tot = ( x + y + z );
	return tot;
}

int moon::calculateKineticEnergy() {
	return ( abs( velocity.getX() ) + abs( velocity.getY() ) + abs( velocity.getZ() ) );
}

int moon::totalEnergy() {
	return (calculatePotentialEnergy() * calculateKineticEnergy());
}
