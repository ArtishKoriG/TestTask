#include "consoleLogger.h"

void ConsoleLogger::write(const std::multimap<double, std::pair<size_t, Coordinates>>& data)
{
    auto countAnsw = data.count(data.begin()->first);

    std::cout << "Number of answers: " << countAnsw << std::endl;
    auto iterMmap = data.begin();
    for (size_t i = 0; i < countAnsw; i++) {
        std::cout << "segment " << iterMmap->second.first << " " << "point " <<
            iterMmap->second.second.getX() << " " << iterMmap->second.second.getY() << " " <<
            iterMmap->second.second.getZ() << std::endl;
        iterMmap++;
    }
}
