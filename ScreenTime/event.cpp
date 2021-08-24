#include "action.cpp"

void CALLBACK ScreenTimeWinActiveEventHandler(
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
            handleProcessDetail(hwnd);
        }
    }
}

void CALLBACK ScreenTimeWinDestroyEventHandler(
    HWINEVENTHOOK hWinEventHook,
    DWORD event,
    HWND hwnd,
    LONG idObject,
    LONG idChild,
    DWORD eventThreadId,
    DWORD dwmsEventTime
) {
    if (event == EVENT_OBJECT_DESTROY) {
        handleProcessDetail(hwnd);
    }
}