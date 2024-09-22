#include "pch.h"
#include "parserPoints.h"

TEST(Parser, Empty) {
	std::ifstream is("empty.txt");

	ParserPoints pars{};
	pars.read(is);

	EXPECT_TRUE(pars.getPoints().empty());
}

TEST(Parser, NotEmpty) {
	std::ifstream is("notEmpty.txt");

	ParserPoints pars{};
	pars.read(is);

	Coordinates p0{};

	EXPECT_FALSE(pars.getPoints().empty());
	EXPECT_EQ(pars.getPoints().size(), 4);
	EXPECT_EQ(pars.getPoints()[0], p0);
}

TEST(Parser, InvalidData) {
	std::ifstream is("InvalidData.txt");

	ParserPoints pars{};

	EXPECT_THROW(pars.read(is), invalidInputData);
}