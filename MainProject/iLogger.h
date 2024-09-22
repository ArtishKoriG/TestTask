#pragma once
#include <map>
#include <utility>
#include "coordinates.h"

class ILogger {
public:
	virtual ~ILogger() = default;
	virtual void write(const std::multimap<double, std::pair<size_t, Coordinates>>& data) = 0;
};