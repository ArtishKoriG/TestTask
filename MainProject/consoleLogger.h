#pragma once
#include <iostream>
#include "iLogger.h"

class ConsoleLogger final : public ILogger {
public:
	void write(const std::multimap<double, std::pair<size_t, Coordinates>>& data) override;
};