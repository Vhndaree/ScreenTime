#include <string>

class ProcessDetail {
private:
    std::string processPath;
    std::string windowTitle;
public:
    ProcessDetail(std::string path = "", std::string title = "") {
        processPath = path;
        windowTitle = title;
    }
};

ProcessDetail getProcessNameFromWindowHandle(HWND hwnd) {
    std::string processPath = "", windowTitle = "";
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

            GetWindowText(hwnd, Buffer, sizeof(Buffer));
            windowTitle = CW2A(Buffer);
            CloseHandle(handle);
        }
    }

    ProcessDetail pd(processPath, windowTitle);
    return pd;
}