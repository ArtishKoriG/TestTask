#pragma once
#include "Coordinates.h"

class SegmentLine final{
public:
	SegmentLine() noexcept = default;
	SegmentLine(const Coordinates& p1, const Coordinates& p2 = {}) noexcept : p1(p1), p2(p2) {}

	void setPoint1(const Coordinates& p) noexcept { p1 = p; }
	void setPoint2(const Coordinates& p) noexcept { p2 = p; }

	auto getPoint1() const noexcept { return p1; }
	auto getPoint2() const noexcept { return p2; }
private:
	Coordinates p1, p2;
};