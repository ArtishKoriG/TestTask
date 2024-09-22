#pragma once
#include <memory>
#include "iLogger.h"


class Logger final {
public:
	Logger(std::shared_ptr<ILogger> strategy) noexcept : strategy(strategy) {}

	void setStrategy(std::shared_ptr<ILogger> strategy);
	void logData(const std::multimap<double, std::pair<size_t, Coordinates>>& data) const;
private:
	std::shared_ptr<ILogger> strategy;
};