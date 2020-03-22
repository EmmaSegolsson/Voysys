/*
	 MOON CLASS
*/

class moon {
public:
	// Constructors
	moon();
	moon(int xPos, int yPos, int zPos);

	// Decstructor
	~moon() = default;

	// Getters
	int getX() const;
	int getY() const;
	int getZ() const;
	Vec3 getVelocity();
	Vec3 getPosition();


	// Memberfuntion
	void addXGravity(int coord1, int coord2, int coord3);
	void addYGravity(int coord1, int coord2, int coord3);
	void addZGravity(int coord1, int coord2, int coord3);
	void updatePosition();
	int calculatePotentialEnergy();
	int calculateKineticEnergy();
	int totalEnergy();


protected:
	Vec3 position;
	Vec3 velocity;
};

