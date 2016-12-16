#include <Windows.h>
#include <stdio.h>

#pragma comment(lib,"user32")

BOOL WINAPI DllMain(HINSTANCE hInstance,DWORD fdwReason,LPVOID lpvReserved){

	MessageBox(NULL,TEXT("HELLO WORLD"),TEXT("TITLE"),MB_OK);

	return TRUE;
}