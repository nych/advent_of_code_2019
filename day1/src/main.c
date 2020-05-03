#include "../include/main.h"
#include <stdio.h>

int main(int argc, char **argv) {
	if (argc <= 1) {
		printf("[ERROR] - Mandatory attribute 'filepath' missing");
		return 1;
	}

	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("[ERROR] - Unable to open file");
		return 1;
	}

	int totalFuelRequired = 0;
	int bufferLength = 256;
	char buffer[bufferLength];
	while (fgets(buffer, bufferLength, file)) {
		int mass = atoi(buffer);
		int fuel;
		do
		{
			fuel = fuelForMass(mass);
			totalFuelRequired += fuel;
			mass = fuel;
		} while (fuel > 0);
	}

	printf("total fuel required %d\n", totalFuelRequired);
	return 0;
}

int fuelForMass(int mass) {
	int result = (mass / 3) - 2;
	return result > 0 ? result : 0;
}