#include "coordinates.h"

double Coordinates::getDistance(const Coordinates& other) const noexcept
{
	return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2) + std::pow(z - other.z, 2));
}
