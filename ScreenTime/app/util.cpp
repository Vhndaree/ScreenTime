#include <ctime>
#include <iomanip>
#include <sstream>

std::string Now() {
    std::time_t rawTime;
    std::tm timeInfo;
    std::stringstream buffer;

    std::time(&rawTime);
    timeInfo = *std::localtime(&rawTime);
    buffer << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");

    return buffer.str();
}