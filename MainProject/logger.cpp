#include "logger.h"

void Logger::setStrategy(std::shared_ptr<ILogger> strategy)
{
	this->strategy = strategy;
}

void Logger::logData(const std::multimap<double, std::pair<size_t, Coordinates>>& data) const
{
	if (!strategy) {
		return;
	}
	strategy->write(data);
}
