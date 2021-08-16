void CALLBACK ScreenTimeEventHandler(
    HWINEVENTHOOK hWinEventHook,
    DWORD event,
    HWND hwnd,
    LONG idObject,
    LONG idChild,
    DWORD eventThreadId,
    DWORD dwmsEventTime
) {
    if (event == EVENT_SYSTEM_FOREGROUND) {
        if (IsWindowVisible(hwnd)) { 
            ProcessDetail pd = getProcessNameFromWindowHandle(hwnd);
            DBConnection();
        }
    }
}