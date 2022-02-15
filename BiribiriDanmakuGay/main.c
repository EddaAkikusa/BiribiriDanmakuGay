#include "bdg.h"

static INT_PTR CALLBACK MainDialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
    {
        EndDialog(hWnd, 0);
        return TRUE;
    }
    case WM_COMMAND:
    {
        switch (LOWORD(IDC_BUTTON_ACTION))
        {
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
    DialogBox(GetInstance(), MAKEINTRESOURCE(IDD_DIALOG_MAIN), NULL, MainDialogProc);
    WSACleanup();
    return 0;
}
