#include "parserPoints.h"

void ParserPoints::read(std::ifstream& is)
{
	if (!is) {
		return;
	}
	std::string line;
	while (std::getline(is, line)) {
		if (line.find(NODES) != std::string::npos || line == "") {
			continue;
		}
		auto tokens = getTokens(line, DELIM);
		if (tokens.size() > 3 || tokens.size() < 3) {
			throw invalidInputData{};
		}
		points.push_back({ std::stod(tokens[0]), std::stod(tokens[1]), std::stod(tokens[2]) });
	}
}

std::vector<std::string> ParserPoints::getTokens(const std::string& str, const char delim) const noexcept
{
	std::stringstream iss(str);
	std::string token;
	std::vector<std::string> tokens;
	while (std::getline(iss, token, delim)) {
		tokens.push_back(token);
	}
	return tokens;
}
