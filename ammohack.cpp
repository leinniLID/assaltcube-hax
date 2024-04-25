#include "includes.h"
int main()
{
	DWORD pID, baseModule, localPlayerPtr;
	int ammo = 9999;

	pID = GetProcessID(L"ac_client.exe");

	baseModule = GetModuleBaseAddress(pID, L"ac_client.exe");

	std::cout << pID << std::endl;
	std::cout << std::hex << baseModule << std::endl;

	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, NULL, pID);

	ReadProcessMemory(handle, (LPCVOID)(baseModule + 0x00183828), &localPlayerPtr, sizeof(localPlayerPtr), nullptr);

	std::cout << std::hex << localPlayerPtr << std::endl;

	while (true)
	{
		WriteProcessMemory(handle, (LPVOID)(localPlayerPtr + 0xEC), &ammo, sizeof(ammo), nullptr);
	}
}