#include "pch.h"
#include "vector.h"

const double epsilon = 0.00001;

TEST(ScalarProduct, ZeroProduct) {
	Vector v1{};
	Vector v2{};

	EXPECT_EQ(v1.getScalarProduct(v2), 0);

	v1.setCoord({ 0, 2.75, 0 });
	v2.setCoord({-5.26, 0, 0});

	EXPECT_EQ(v1.getScalarProduct(v2), 0);

	v1.setCoord({ 3.2, 5.26, 10 });
	v2.setCoord({ -5.26, 3.2, 0 });

	EXPECT_EQ(v1.getScalarProduct(v2), 0);
}

TEST(ScalarProduct, NoZeroProduct) {
	Vector v1{ {1.5, 0, 0} };
	Vector v2{ {2, 0, 0} };

	EXPECT_EQ(v1.getScalarProduct(v2), 3);

	v1.setCoord({ 0, 2.75, 1 });
	v2.setCoord({ -5.26, 0, -7.76 });

	EXPECT_EQ(v1.getScalarProduct(v2), -7.76);

	v1.setCoord({ 3, 1, 10 });
	v2.setCoord({ -5.26, 3.2, 0 });

	EXPECT_TRUE(std::abs(v1.getScalarProduct(v2)) - 12.58 < epsilon);
}

TEST(GetLen, Zero) {
	Vector v1{};

	EXPECT_EQ(v1.getLen(), 0);
}

TEST(GetLen, NoZero) {
	Vector v1{{1, 1, 1}};

	EXPECT_EQ(v1.getLen(), std::sqrt(3));

	v1.setCoord({ -1, 0.1, 1 });

	EXPECT_EQ(v1.getLen(), std::sqrt(2.01));

	v1.setCoord({ -1, 0.1, -1.55 });

	EXPECT_EQ(v1.getLen(), std::sqrt(3.4125));

	v1.setCoord({ -1, -0.1, -1.55 });

	EXPECT_EQ(v1.getLen(), std::sqrt(3.4125));
}

TEST(OperatorPlus, Vector) {
	Vector v1{};
	Vector v2{};
	Vector zero{};

	EXPECT_EQ(zero, v2 + v1);

	v1.setCoord({ 1, -2, 10.75 });
	v2.setCoord({ -1, 2, -10.75 });

	EXPECT_EQ(zero, v2 + v1);

	v2.setCoord({1, 7.26, -3});

	Vector res{ {2, 5.26, 7.75} };
	EXPECT_EQ(res, v2 + v1);
}

TEST(OperatorMultiply, Scalar) {
	Vector v1{};
	Vector zero{};

	EXPECT_EQ(zero, v1 * 10.23);
	EXPECT_EQ(zero, v1 * -10.23);

	v1.setCoord({ 1, -3.5, 0 });
	Vector res{ {5, -17.5, 0} };

	EXPECT_EQ(res, v1 * 5);
}