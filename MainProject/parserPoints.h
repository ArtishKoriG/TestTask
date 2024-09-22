#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "coordinates.h"
#include "constants.h"
#include "parserExceptions.h"

class ParserPoints{
public:
	void read(std::ifstream& is);

	auto getPoints() const noexcept { return points; }

private:
	std::vector<Coordinates> points;

	std::vector<std::string> getTokens(const std::string& str, const char delim) const noexcept;
};