
#include "Vec3.h";
#include "moon.h";

#include <iostream>
using namespace std;

const int theTime = 1000;


int main() {

	/****** Test input *******/
	moon moonIo(-7, -1, 6);
	moon moonEuropa(6, -9, -9);
	moon moonGanymede(-12, 2, -7);
	moon moonCallisto(4, -17, -12);


	/****** Example one *******
	moon moonIo(-1, 0, 2);
	moon moonEuropa(2, -10, -7);
	moon moonGanymede(4, -8, 8);
	moon moonCallisto(3, 5, -1);
	***************************/

	/****** Example two *******
	moon moonIo(-8, -10, 0);
	moon moonEuropa(5, 5, 10);
	moon moonGanymede(2, -7, 3);
	moon moonCallisto(9, -8, -3);
	***************************/

	// Add gravity
	for (int i = 0; i <= theTime; i++) {

		// Print test
		cout << "Step " << i << ": " << endl;
		cout << "pos=<x=" << moonIo.getPosition().getX() << ", "
			 <<		 "y=" << moonIo.getPosition().getY() << ", "
			 <<		 "z=" << moonIo.getPosition().getZ() << "> "
			 <<	"vel=<x=" << moonIo.getVelocity().getX() << ", "
			 <<		 "y=" << moonIo.getVelocity().getY() << ", "
			 <<		 "z=" << moonIo.getVelocity().getZ() << ">" << endl;
		cout << "pos=<x=" << moonEuropa.getPosition().getX() << ", "
			 <<		 "y=" << moonEuropa.getPosition().getY() << ", "
			 <<		 "z=" << moonEuropa.getPosition().getZ() << "> "
			 <<	"vel=<x=" << moonEuropa.getVelocity().getX() << ", "
			 <<		 "y=" << moonEuropa.getVelocity().getY() << ", "
			 <<		 "z=" << moonEuropa.getVelocity().getZ() << ">" << endl;
		cout << "pos=<x=" << moonGanymede.getPosition().getX() << ", "
			 <<		 "y=" << moonGanymede.getPosition().getY() << ", "
			 <<		 "z=" << moonGanymede.getPosition().getZ() << "> "
			 << "vel=<x=" << moonGanymede.getVelocity().getX() << ", "
			 <<		 "y=" << moonGanymede.getVelocity().getY() << ", "
			 <<		 "z=" << moonGanymede.getVelocity().getZ() << ">" << endl;
		cout << "pos=<x=" << moonCallisto.getPosition().getX() << ", "
			 <<		 "y=" << moonCallisto.getPosition().getY() << ", "
			 <<		 "z=" << moonCallisto.getPosition().getZ() << "> "
			 <<	"vel=<x=" << moonCallisto.getVelocity().getX() << ", "
			 <<		 "y=" << moonCallisto.getVelocity().getY() << ", "
			 <<		 "z=" << moonCallisto.getVelocity().getZ() << ">" << endl;

		// Calculate energy
		int energyIo = 0;
		int energyEuropa = 0;
		int energyGanymede = 0;
		int energyCallisto = 0;
		energyIo = moonIo.totalEnergy();
		energyEuropa = moonEuropa.totalEnergy();
		energyGanymede = moonGanymede.totalEnergy();
		energyCallisto = moonCallisto.totalEnergy();

		int totalEnergy = 0;
		totalEnergy = energyIo + energyEuropa + energyGanymede + energyCallisto;

		// Print energy
		cout << "Sum of total energy at step " << i << ": " << totalEnergy << endl << endl;


		// Adding Gravity
		moonIo.addXGravity( moonEuropa.getX(), moonGanymede.getX(), moonCallisto.getX() );
		moonIo.addYGravity(moonEuropa.getY(), moonGanymede.getY(), moonCallisto.getY());
		moonIo.addZGravity(moonEuropa.getZ(), moonGanymede.getZ(), moonCallisto.getZ());		
		
		moonEuropa.addXGravity(moonIo.getX(), moonGanymede.getX(), moonCallisto.getX() );
		moonEuropa.addYGravity(moonIo.getY(), moonGanymede.getY(), moonCallisto.getY());
		moonEuropa.addZGravity(moonIo.getZ(), moonGanymede.getZ(), moonCallisto.getZ());

		moonGanymede.addXGravity( moonEuropa.getX(), moonIo.getX(), moonCallisto.getX() );
		moonGanymede.addYGravity(moonEuropa.getY(), moonIo.getY(), moonCallisto.getY());
		moonGanymede.addZGravity(moonEuropa.getZ(), moonIo.getZ(), moonCallisto.getZ());

		moonCallisto.addXGravity( moonEuropa.getX(), moonGanymede.getX(), moonIo.getX() );
		moonCallisto.addYGravity(moonEuropa.getY(), moonGanymede.getY(), moonIo.getY());
		moonCallisto.addZGravity(moonEuropa.getZ(), moonGanymede.getZ(), moonIo.getZ());

		// Update the position
		moonIo.updatePosition();
		moonEuropa.updatePosition();
		moonGanymede.updatePosition();
		moonCallisto.updatePosition();

	}

	return 0;
}


