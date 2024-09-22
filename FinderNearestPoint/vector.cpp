#include "vector.h"

Vector::Vector(const Coordinates& p1, const Coordinates& p2) noexcept
{
	coord = { (p2.getX() - p1.getX()), (p2.getY() - p1.getY()), (p2.getZ() - p1.getZ()) };
}

double Vector::getScalarProduct(const Vector& other) const noexcept
{
	return coord.getX() * other.coord.getX() + coord.getY() * other.coord.getY()
		+ coord.getZ() * other.coord.getZ();
}

double Vector::getLen() const noexcept
{
	return std::sqrt(std::pow(coord.getX(), 2) + std::pow(coord.getY(), 2) + std::pow(coord.getZ(), 2));
}

Vector Vector::operator+(const Vector& other) const noexcept
{
	Vector tmp({ coord.getX() + other.coord.getX(),
	coord.getY() + other.coord.getY(), coord.getZ() + other.coord.getZ() });
	return tmp;
}

Vector& Vector::operator+=(const Vector& other) noexcept
{
	*this = *this + other;
	return *this;
}

Vector Vector::operator*(const double& scalar) const noexcept
{
	Vector tmp({ coord.getX() * scalar, coord.getY() * scalar, coord.getZ() * scalar });
	return tmp;
}

Vector& Vector::operator*=(const double& scalar) noexcept
{
	*this = *this * scalar;
	return *this;
}

Vector Vector::operator-(const Vector& other) const noexcept
{
	return *this + other * (-1.0);
}

Vector& Vector::operator-=(const Vector& other) noexcept
{
	*this = *this - other;
	return *this;
}
