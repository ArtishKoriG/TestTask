#pragma once
#include <cmath>
#include "coordinates.h"

class Vector final {
public:
	Vector() noexcept = default;
	Vector(const Coordinates& coord) noexcept : coord(coord) {}
	Vector(const Coordinates& p1, const Coordinates& p2) noexcept;

	void setCoord(const Coordinates& newCoord) noexcept { coord = newCoord; }

	auto getCoord() const noexcept { return coord; }
	double getScalarProduct(const Vector& other) const noexcept;
	double getLen() const noexcept;

	Vector operator+(const Vector& other) const noexcept;
	Vector& operator+=(const Vector& other) noexcept;
	Vector operator*(const double& scalar) const noexcept;
	Vector& operator*=(const double& scalar) noexcept;
	Vector operator-(const Vector& other) const noexcept;
	Vector& operator-=(const Vector& other) noexcept;

	bool operator==(const Vector&) const = default;
private:
	Coordinates coord;
};