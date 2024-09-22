#include <iostream>
#include <fstream>
#include "parserPoints.h"
#include "segmentLine.h"
#include "finderDistToSegment.h"
#include "logger.h"
#include "consoleLogger.h"


int main()
{
    std::string filename{};
    std::cout << "Enter the name of the input file: ";
    std::cin >> filename;
    std::ifstream is{ filename };
    if (!is) {
        std::cout << "The file could not be opened";
        return 1;
    }
    std::cout << "Enter the coordinates x, y and z of the target point: ";

    double targetX, targetY, targetZ;
    std::cin >> targetX >> targetY >> targetZ;

    Coordinates target{ targetX, targetY, targetZ };

    ParserPoints parser{};
    
    try {
        parser.read(is);
    }
    catch (...) {
        std::cout << invalidInputData{}.what() << std::endl;
        return 1;
    }
    auto points = parser.getPoints();

    if (points.size() < 2 ) {
        std::cout << "Input file is empty or didn't enough data" << std::endl;
        return 1;
    }

    std::vector<SegmentLine> segments{};

    for (size_t i = 0; i < points.size() - 1; i++) {
        segments.push_back({ points[i], points[i + 1] });
    }

    FinderDistToSegment finder{ segments };

    finder.findDist(target);

    auto data = finder.getData();

    std::shared_ptr<ILogger> consoleLog = std::make_shared<ConsoleLogger>();
    std::unique_ptr<Logger> logger = std::make_unique<Logger>(consoleLog);

    logger->logData(data);
    return 0;
}
