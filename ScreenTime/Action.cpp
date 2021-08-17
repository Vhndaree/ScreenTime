#include <string>
#include "model.cpp"
#include "util.cpp"

ProcessDetail PROCESS_DETAIL;

ProcessDetail getProcessNameFromWindowHandle(HWND hwnd) {
    std::string processPath = "", processName ="", windowTitle = "", startDateTime = "";
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
            startDateTime = Now();
            processPath = CW2A(Buffer);

            GetModuleBaseName(handle, 0, Buffer, MAX_PATH);
            processName = CW2A(Buffer);
            processName = processName.substr(0, processName.find("."));

            GetWindowText(hwnd, Buffer, sizeof(Buffer));
            windowTitle = CW2A(Buffer);
            CloseHandle(handle);
        }
    }

    ProcessDetail pd(processName, processPath, windowTitle, startDateTime);
    return pd;
}