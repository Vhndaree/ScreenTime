#include <string>

class ProcessDetail {
private:
    std::string processName;
    std::string processPath;
    std::string windowTitle;
public:
    ProcessDetail(std::string name = "", std::string path = "", std::string title = "") {
        processName = name;
        processPath = path;
        windowTitle = title;
    }
    std::string GetWindowTitle() {
        return windowTitle;
    }
    std::string GetProcessPath() {
        return processPath;
    }
    std::string GetProcessName() {
        return processName;
    }
    boolean Valid() {
        return windowTitle != "" && processPath != "" && processName != "";
    }
};

ProcessDetail getProcessNameFromWindowHandle(HWND hwnd) {
    std::string processPath = "", processName ="", windowTitle = "";
    DWORD dwPID;
    GetWindowThreadProcessId(hwnd, &dwPID);

    HANDLE handle = OpenProcess(
        PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
        FALSE,
        dwPID
    );

    if (handle) {
        TCHAR Buffer[MAX_PATH];
        if (GetModuleFileNameEx(handle, 0, Buffer, MAX_PATH)) {
            processPath = CW2A(Buffer);

            GetModuleBaseName(handle, 0, Buffer, MAX_PATH);
            processName = CW2A(Buffer);
            processName = processName.substr(0, processName.find("."));

            GetWindowText(hwnd, Buffer, sizeof(Buffer));
            windowTitle = CW2A(Buffer);
            CloseHandle(handle);
        }
    }

    ProcessDetail pd(processName, processPath, windowTitle);
    return pd;
}