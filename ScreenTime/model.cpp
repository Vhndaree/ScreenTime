#include <string>
#include <ctime>

class ProcessDetail {
private:
    std::string processName;
    std::string processPath;
    std::string windowTitle;
    std::time_t startDateTime;
    std::time_t endDateTime;
    int timeDiff;

public:
    ProcessDetail(std::string name = "", std::string path = "", std::string title = "", std::time_t st = 0) {
        processName = name;
        processPath = path;
        windowTitle = title;
        startDateTime = st;
        endDateTime = 0;
    }

    std::string GetWindowTitle() {
        return windowTitle;
    }
    void SetWindowTitle(std::string title) {
        windowTitle = title;
    }

    std::string GetProcessPath() {
        return processPath;
    }
    void SetProcessPath(std::string path) {
        processPath = path;
    }

    std::string GetProcessName() {
        return processName;
    }
    void SetProcessName(std::string name) {
        processName = name;
    }

    std::time_t GetStartDateTime() {
        return startDateTime;
    }
    void SetStartDateTime(std::time_t dateTime) {
        startDateTime = dateTime;
    }

    std::time_t GetEndDateTime() {
        return endDateTime;
    }
    void SetEndDateTime(std::time_t dateTime) {
        endDateTime = dateTime;
    }

    int GetTimeDiff() {
        return timeDiff;
    }
    void SetTimeDiff(int diff) {
        timeDiff = diff;
    }

    boolean Valid() {
        return windowTitle != "" && processPath != "" && processName != "" && startDateTime != 0 && endDateTime != 0;
    }

    boolean isInitiated() {
        return windowTitle != "" && processPath != "" && processName != "" && startDateTime != 0;
    }
};