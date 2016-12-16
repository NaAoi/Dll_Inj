#include <Windows.h>
#include <stdio.h>

int main(int argc,char **argv){

	char path[]="C:\\spy.dll";

	int pid=atoi(argv[1]);

	HANDLE hProcess=OpenProcess(PROCESS_ALL_ACCESS,FALSE,pid);

	void *datamemory=VirtualAllocEx(hProcess,NULL,sizeof(path),MEM_COMMIT,PAGE_READWRITE);

	WriteProcessMemory(hProcess,datamemory,(void *)path,sizeof(path),NULL);

	HMODULE kernel32=GetModuleHandle((LPCWSTR)"kernel32");

	FARPROC loadlibrary=GetProcAddress(kernel32,"LoadLibraryA");

	HANDLE hThread=CreateRemoteThread(hProcess,NULL,0,(LPTHREAD_START_ROUTINE)loadlibrary,datamemory,0,NULL);

	if(!hThread){printf("error");exit(0);}

	WaitForSingleObject(hThread,INFINITE);

	CloseHandle(hThread);

	VirtualFreeEx(hProcess,datamemory,sizeof(path),MEM_RELEASE);

	return 0;
}