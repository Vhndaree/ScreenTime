#include <ctime>
#include <iomanip>
#include <sstream>

std::time_t Now() {
    std::time_t t;
    std::time(&t);

    return t;
}

std::string FormattedTimeString(std::time_t t) {
    std::tm timeInfo;
    std::stringstream buffer;

    timeInfo = *std::localtime(&t);
    buffer << std::put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");

    return buffer.str();
}

int TimeDiffInSeconds(std::time_t t1, std::time_t t2) {
    double diff = difftime(t2, t1);
    return round(diff);
}