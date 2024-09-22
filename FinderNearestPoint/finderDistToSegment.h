#pragma once
#include <map>
#include <utility>
#include <vector>
#include "segmentLine.h"
#include "vector.h"


class FinderDistToSegment final {
public:
	FinderDistToSegment(const std::vector<SegmentLine>& segments) noexcept : segments(segments) {
		data = {};
	}

	void findDist(const Coordinates& target);
	auto getData() const noexcept { return data; }

	auto clearData() { data.clear(); }

private:
	std::multimap<double, std::pair<size_t, Coordinates>> data;
	const std::vector<SegmentLine> segments;
};