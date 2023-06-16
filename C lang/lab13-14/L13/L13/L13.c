#include <Windows.h>

#define SIZE 1500
#define COLORS_SIZE 4
#define MAGIC_NUM 10

const wchar_t* const MainWindowClass = L"CoolGraphique";

typedef struct coord {
	int x, y;
} coords;

COLORREF colors[COLORS_SIZE] = { RGB(255, 0, 0), RGB(255, 255, 0), RGB(255, 0, 255), RGB(0, 255, 255)};
RECT rct;
HDC hdcBack;
HBITMAP hbmBack;
coords snowCoords[SIZE];

void drawBackground(HDC hdc) {
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0));
	SelectObject(hdc, hBrush);
	Rectangle(hdc, 0, 0, 800, 300);

	hBrush = CreateSolidBrush(RGB(0, 255, 255));
	SelectObject(hdc, hBrush);
	Rectangle(hdc, 0, 300, 800, 600);
}

void drawTree(HDC hdc) {
	HBRUSH hBrush = CreateSolidBrush(RGB(63, 0, 15));
	SelectObject(hdc, hBrush);
	BeginPath(hdc);
	MoveToEx(hdc, 350, 500, NULL);
	LineTo(hdc, 450, 500);
	LineTo(hdc, 450, 450);
	LineTo(hdc, 350, 450);
	LineTo(hdc, 350, 500);
	EndPath(hdc);
	FillPath(hdc);

	hBrush = CreateSolidBrush(RGB(1, 50, 32));
	SelectObject(hdc, hBrush);
	BeginPath(hdc);
	MoveToEx(hdc, 200, 450, NULL);
	LineTo(hdc, 600, 450);
	LineTo(hdc, 550, 375);
	LineTo(hdc, 575, 375);
	LineTo(hdc, 525, 300);
	LineTo(hdc, 550, 300);
	LineTo(hdc, 500, 225);
	LineTo(hdc, 525, 225);
	LineTo(hdc, 475, 150);
	LineTo(hdc, 500, 150);
	LineTo(hdc, 400, 25);
	LineTo(hdc, 300, 150);
	LineTo(hdc, 325, 150);
	LineTo(hdc, 275, 225);
	LineTo(hdc, 300, 225);
	LineTo(hdc, 250, 300);
	LineTo(hdc, 275, 300);
	LineTo(hdc, 225, 375);
	LineTo(hdc, 250, 375);
	LineTo(hdc, 200, 450);
	EndPath(hdc);
	FillPath(hdc);
}

void snowInit() {
	for (int i = 0; i < SIZE; i++) {
		snowCoords[i].x = rand() % 800;
		snowCoords[i].y = rand() % 600;
	}
}

void drawSnow(HDC hdc, int x, int y) {
	SetPixel(hdc, x, y, RGB(255, 255, 255));
}

void InitializeBackBuffer(HWND hWnd, int w, int h) {
	HDC hdcWindow;

	hdcWindow = GetDC(hWnd);

	hdcBack = CreateCompatibleDC(hdcWindow);
	hbmBack = CreateCompatibleBitmap(hdcWindow, w, h);
	SaveDC(hdcBack);
	SelectObject(hdcBack, hbmBack);

	ReleaseDC(hWnd, hdcWindow);
}

void FinalizeBackBuffer() {
	if (hdcBack) {
		RestoreDC(hdcBack, -1);
		DeleteObject(hbmBack);
		DeleteDC(hdcBack);
		hdcBack = 0;
	}
}

void drawEllipses(HDC hdc) {
	HBRUSH hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 250, 400, 270, 420);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 530, 400, 550, 420);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 300, 350, 320, 370);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 480, 350, 500, 370);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 350, 300, 370, 320);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 430, 300, 450, 320);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 390, 250, 410, 270);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 390, 200, 410, 220);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 390, 150, 410, 170);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 390, 100, 410, 120);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 390, 350, 410, 370);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 340, 400, 360, 420);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 440, 400, 460, 420);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 320, 250, 340, 270);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 480, 250, 460, 270);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 340, 180, 360, 200);
	hBrush = CreateSolidBrush(colors[rand() % COLORS_SIZE]);
	SelectObject(hdc, hBrush);
	Ellipse(hdc, 460, 180, 440, 200);
}

void star(HDC hdc, int x, int y, COLORREF color) {
	HBRUSH hBrush = CreateSolidBrush(color);
	SelectObject(hdc, hBrush);
	BeginPath(hdc);
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, x + 10, y);
	LineTo(hdc, x + 20, y - 15);
	LineTo(hdc, x + 30, y);
	LineTo(hdc, x + 40, y);
	LineTo(hdc, x + 30, y + 10);
	LineTo(hdc, x + 35, y + 20);
	LineTo(hdc, x + 20, y + 13);
	LineTo(hdc, x + 5, y + 20);	
	LineTo(hdc, x + 10, y + 10);
	EndPath(hdc);
	FillPath(hdc);
}

LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HBRUSH hBrush;
	HDC hdc;

	switch (uMsg) {
	case WM_SIZE:
		GetClientRect(hWnd, &rct);
		FinalizeBackBuffer();
		InitializeBackBuffer(hWnd, rct.right, rct.bottom);
		break;
	case WM_CREATE:
		SetTimer(hWnd, MAGIC_NUM, 100, NULL);
		break;
	case WM_TIMER:
		if (wParam == MAGIC_NUM)
		{
			for (int i = 0; i < SIZE; i++) {
				snowCoords[i].y += 1;
			}
			InvalidateRect(hWnd, NULL, TRUE);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		drawBackground(hdcBack);
		star(hdcBack, 100, 100, RGB(255, 255, 0));
		star(hdcBack, 700, 200, RGB(255, 255, 0));
		star(hdcBack, 150, 250, RGB(255, 255, 0));
		drawTree(hdcBack);
		star(hdcBack, 380, 17, RGB(255, 0, 0));
		drawEllipses(hdcBack);
		for (int i = 0; i < SIZE; i++) {
			drawSnow(hdcBack, snowCoords[i].x, snowCoords[i].y);
			if (snowCoords[i].y > rct.bottom) {
				snowCoords[i].y = rand() % 100 - 100;
				snowCoords[i].x = rand() % 800;
			}
		}
		ValidateRect(hWnd, NULL);
		BitBlt(hdc, 0, 0, rct.right, rct.bottom, hdcBack, 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, MAGIC_NUM);
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wcex;
	HWND hwndMain;
	MSG msg;

	memset(&wcex, 0, sizeof(wcex));

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_GLOBALCLASS;
	wcex.lpfnWndProc = MainWindowProc;
	wcex.hCursor = LoadCursor(0, IDC_ARROW);
	wcex.lpszClassName = MainWindowClass;
	RegisterClassEx(&wcex);
	snowInit();
	hwndMain = CreateWindowEx(0, MainWindowClass, L"Graphics", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0, 800, 600, 0, 0, 0, NULL);

	while (GetMessage(&msg, 0, 0, 0)) {
		DispatchMessage(&msg);
	}

	return msg.wParam;
}