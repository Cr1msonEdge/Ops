#include <iostream>
#include <Windows.h>	
#include <cstring>

int main()
{
	// путь к нашей библиотеке
	LPCSTR DllPath = "D:\\Ops\\ssDll\\x64\\Release\\ssDll.dll";

	// open a handle to target processs
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, 24512);

	// allocate memory for the dllpath in the target process
	// length of the path string + null terminator'
	LPVOID pDllPath = VirtualAllocEx(hProcess, 0, strlen(DllPath) + 1,
		MEM_COMMIT, PAGE_READWRITE);

	// пишем путь к адресу памяти we just allocated in the target process

	WriteProcessMemory(hProcess, pDllPath, (LPVOID)DllPath, strlen(DllPath) + 1, 0);

	// создаем тред в целевом процессе, который потом вызовет 
	// функцию LoadLibraryA указав dllpath как аргумент, после чего
	// программа вызовет нашу dll

	HANDLE hLoadThread = CreateRemoteThread(hProcess, 0, 0,
		(LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("Kernel32.dll"),
			"LoadLibraryA"), pDllPath, 0, 0);

	// ждем окончания работы загрузчика ядра
	WaitForSingleObject(hLoadThread, INFINITE);

	std::cout << "dll path: " << std::hex << pDllPath << std::endl;
	std::cin.get();

	// очищаем память расположенную по пути к dll
	VirtualFreeEx(hProcess, pDllPath, strlen(DllPath) + 1, MEM_RELEASE);
}
 