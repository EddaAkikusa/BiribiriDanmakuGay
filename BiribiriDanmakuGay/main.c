#include <WinSock2.h>
#include <Windows.h>
#include "resource.h"

extern IMAGE_DOS_HEADER __ImageBase;
HINSTANCE g_hInstance = &__ImageBase;

typedef struct _USERDATA
{
    WSAOVERLAPPED overlapped;
    HANDLE hIocp;
    HANDLE hTcpSock;
    BOOL bRunning;

} USERDATA;

static INT_PTR CALLBACK MainDialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
    {
        USERDATA* userData = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(USERDATA));
        SetWindowLongPtr(hWnd, GWLP_USERDATA, userData);
        return TRUE;
    }
    case WM_DESTROY:
    {
        USERDATA* userData = GetWindowLongPtr(hWnd, GWLP_USERDATA);
        HeapFree(GetProcessHeap(), 0, userData);
        return TRUE;
    }
    case WM_CLOSE:
    {
        EndDialog(hWnd, 0);
        return TRUE;
    }
    case WM_COMMAND:
    {
        switch (LOWORD(wParam))
        {
        case IDC_BUTTON_ACTION:
        {
            SendMessage(hWnd, WM_SETTEXT, 0, "弹幕基");
            return TRUE;
        }
        default:
            break;
        }
    }
    default:
        break;
    }
    return FALSE;
}

int WINAPI WinMain(HINSTANCE arg0, HINSTANCE arg1, LPSTR arg2, int arg3)
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    DialogBox(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG_MAIN), NULL, MainDialogProc);
    WSACleanup();
    return 0;
}
