#include <string>

class ProcessDetail {
private:
    std::string processName;
    std::string processPath;
    std::string windowTitle;
    std::string startDateTime;
    std::string endDateTime;

public:
    ProcessDetail(std::string name = "", std::string path = "", std::string title = "", std::string st = "") {
        processName = name;
        processPath = path;
        windowTitle = title;
        startDateTime = st;
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

    std::string GetStartDateTime() {
        return startDateTime;
    }
    void SetStartDateTime(std::string dateTime) {
        startDateTime = dateTime;
    }

    std::string GetEndDateTime() {
        return endDateTime;
    }
    void SetEndDateTime(std::string dateTime) {
        endDateTime = dateTime;
    }

    boolean Valid() {
        return windowTitle != "" && processPath != "" && processName != "";
    }
};