#include "pch.h"
#include "coordinates.h"


const double epsilon = 0.01;

TEST(GetDistance, Zero) {
	Coordinates coord1{};
	Coordinates coord2 = coord1;

	EXPECT_EQ(coord1.getDistance(coord2), 0);

	coord1.setX(1.25);
	coord1.setY(-2.025);
	coord1.setZ(10.107);

	coord2 = coord1;

	EXPECT_EQ(coord1.getDistance(coord2), 0);
}

TEST(GetDistance, NoZero) {
	Coordinates coord1{};
	Coordinates coord2{1, 0, 0};

	EXPECT_EQ(coord1.getDistance(coord2), 1);

	coord1 = { -1, 3, 0 };

	EXPECT_TRUE(std::abs(coord1.getDistance(coord2) - 3.6) < epsilon);
}