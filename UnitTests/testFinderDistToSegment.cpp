#include "pch.h"
#include"finderDistToSegment.h"

const Coordinates c1{ 0,0,0 };
const Coordinates c2{ 1,0,0 };
const Coordinates c3{ 2,1,0 };
const Coordinates c4{ 3,1,1 };

const std::vector<SegmentLine> ex1{ {c1, c2}, {c2, c3}, {c3, c4} };

TEST(FindDist, OnVector) {
	Coordinates target{ c1 };

	FinderDistToSegment finder{ ex1 };

	finder.findDist(target);

	Coordinates targetP(c1);

	std::multimap<double, std::pair<size_t, Coordinates>> mmap{};

	mmap.insert({ 0, std::make_pair(1, targetP) });

	EXPECT_EQ(finder.getData().count(finder.getData().begin()->first), 1);
	EXPECT_EQ(finder.getData().begin()->first, mmap.begin()->first);
	EXPECT_EQ(finder.getData().begin()->second.first, mmap.begin()->second.first);
	EXPECT_EQ(finder.getData().begin()->second.second, mmap.begin()->second.second);

	target = { c2 };
	targetP = { c2 };

	finder.clearData();
	finder.findDist(target);

	EXPECT_EQ(finder.getData().count(finder.getData().begin()->first), 2);

	mmap.clear();
	mmap.insert({ 0, std::make_pair(1, targetP) });
	mmap.insert({ 0, std::make_pair(2, targetP) });

	auto iter1 = mmap.begin();
	auto data = finder.getData();
	auto iter2 = data.begin();

	while (iter1 != mmap.end()) {
		EXPECT_EQ(iter2->first, iter1->first);
		EXPECT_EQ(iter2->second.first, iter1->second.first);
		EXPECT_EQ(iter2->second.second, iter1->second.second);
		iter1++;
		iter2++;
	}

}

TEST(FindDist, Example1) {
	Coordinates target{ 2, 0.5, 0.5 };

	FinderDistToSegment finder{ ex1 };
	finder.findDist(target);

	Coordinates p1{1.75, 0.75, 0 };
	Coordinates p2{2.25, 1, 0.25 };

	const double epsilon = 0.000001;

	auto data = finder.getData();
	auto iter = data.begin();

	EXPECT_EQ(data.count(finder.getData().begin()->first), 2);

	EXPECT_EQ(iter->second.first, 2);
	EXPECT_EQ(iter->second.second, p1);

	iter++;

	EXPECT_EQ(iter->second.first, 3);
	EXPECT_TRUE(iter->second.second.getX() - p2.getX() < epsilon);
	EXPECT_TRUE(iter->second.second.getY() - p2.getY() < epsilon);
	EXPECT_TRUE(iter->second.second.getZ() - p2.getZ() < epsilon);
}

TEST(FindDist, CheckPoint) {
	Coordinates target{};
	const Coordinates p1{ 1, 1, 1 };
	const Coordinates p2{ 5.25, 2, -3.27 };
	const std::vector<SegmentLine> segments{ {p1, p2} };

	FinderDistToSegment finder{ segments };

	finder.findDist(target);

	auto data = finder.getData();

	EXPECT_EQ(p1, data.begin()->second.second);

	target = { 100, 20, -30 };
	finder.clearData();

	finder.findDist(target);

	data = finder.getData();

	EXPECT_EQ(p2, data.begin()->second.second);


	const Coordinates p3{ 1, 1, 0 };
	const Coordinates p4{ 2.5, 2.5, 0 };
	const std::vector<SegmentLine> newSegments{ {p3, p4} };
	target = { 2, 2, 10 };

	FinderDistToSegment newFinder{ newSegments };
	newFinder.findDist(target);
	data = newFinder.getData();
	Coordinates proection{ 2, 2, 0 };

	EXPECT_EQ(proection, data.begin()->second.second);
}