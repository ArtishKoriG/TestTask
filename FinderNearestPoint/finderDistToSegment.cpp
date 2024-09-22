#include "finderDistToSegment.h"

void FinderDistToSegment::findDist(const Coordinates& target)
{
	size_t numberSegment = 1;
	for (const auto& segment : segments) {
		Vector vec1{ segment.getPoint1(), segment.getPoint2() }; // Вектор составляющий сегмент
		Vector vec2{ segment.getPoint1(), target }; // Вектор от первой точки сегмента до таргета
		Vector vec3{ segment.getPoint2(), target }; // Вектор от второй точки сегмента до таргета

		if (vec1.getScalarProduct(vec2) <= 0) {
			data.insert({ vec2.getLen(), std::make_pair(numberSegment, segment.getPoint1()) });
		}
		else if (vec1.getScalarProduct(vec3) >= 0) {
			data.insert({ vec3.getLen(), std::make_pair(numberSegment, segment.getPoint2()) });
		}
		else {
			Coordinates prOnSegment{}; // проекция targer на сегмент

			auto targetPr = vec1 - vec1 * ((vec1 - vec2).getScalarProduct(vec1) / std::pow(vec1.getLen(), 2));

			prOnSegment.setX(targetPr.getCoord().getX() + segment.getPoint1().getX());
			prOnSegment.setY(targetPr.getCoord().getY() + segment.getPoint1().getY());
			prOnSegment.setZ(targetPr.getCoord().getZ() + segment.getPoint1().getZ());

			double dist = target.getDistance(prOnSegment);

			data.insert({ dist, std::make_pair(numberSegment, prOnSegment) });
		}
		numberSegment++;
	}
}
