#pragma once
#include <cmath>

class Coordinates final {
public:

	Coordinates() noexcept = default;
	Coordinates(const double& x, const double& y, const double& z) noexcept : x(x), y(y), z(z) {}

	double getX() const noexcept { return x; }
	double getY() const noexcept { return y; }
	double getZ() const noexcept { return z; }

	void setX(const double& newX) noexcept { x = newX; }
	void setY(const double& newY) noexcept { y = newY; }
	void setZ(const double& newZ) noexcept { z = newZ; }

	double getDistance(const Coordinates& other) const noexcept;

	bool operator==(const Coordinates&) const = default;
private:
	double x, y, z;
};