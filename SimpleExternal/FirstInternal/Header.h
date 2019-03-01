#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include "OOF.h"

// it not mine so IDK what it does below this 

using namespace std;

class CHackProcess
{
public:

	PROCESSENTRY32 __gameProcess;
	HANDLE __HandleProcess;
	HWND __HWNDCss;
	uintptr_t Client;
	uintptr_t Engine;
	uintptr_t __ClientStauts;
	DWORD FindProcessName(const char *__ProcessName, PROCESSENTRY32 *pEntry)
	{
		PROCESSENTRY32 __ProcessEntry;
		__ProcessEntry.dwSize = sizeof(PROCESSENTRY32);
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hSnapshot == INVALID_HANDLE_VALUE) return 0;        if (!Process32First(hSnapshot, &__ProcessEntry))
		{
			CloseHandle(hSnapshot);
			return 0;
		}
		do {
			if (!_strcmpi(__ProcessEntry.szExeFile, __ProcessName))
			{
				memcpy((void *)pEntry, (void *)&__ProcessEntry, sizeof(PROCESSENTRY32));
				CloseHandle(hSnapshot);
				return __ProcessEntry.th32ProcessID;
			}
		} while (Process32Next(hSnapshot, &__ProcessEntry));
		CloseHandle(hSnapshot);
		return 0;
	}


	DWORD getThreadByProcess(DWORD __uintptr_tProcess)
	{
		THREADENTRY32 __ThreadEntry;
		__ThreadEntry.dwSize = sizeof(THREADENTRY32);
		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
		if (hSnapshot == INVALID_HANDLE_VALUE) return 0;

		if (!Thread32First(hSnapshot, &__ThreadEntry)) { CloseHandle(hSnapshot); return 0; }

		do {
			if (__ThreadEntry.th32OwnerProcessID == __uintptr_tProcess)
			{
				CloseHandle(hSnapshot);
				return __ThreadEntry.th32ThreadID;
			}
		} while (Thread32Next(hSnapshot, &__ThreadEntry));
		CloseHandle(hSnapshot);
		return 0;
	}

	DWORD GetModuleNamePointer(LPSTR LPSTRModuleName, DWORD __uintptr_tProcessId)
	{
		MODULEENTRY32 lpModuleEntry = { 0 };
		HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, __uintptr_tProcessId);
		if (!hSnapShot)
			return NULL;
		lpModuleEntry.dwSize = sizeof(lpModuleEntry);
		BOOL __RunModule = Module32First(hSnapShot, &lpModuleEntry);
		while (__RunModule)
		{
			if (!strcmp(lpModuleEntry.szModule, LPSTRModuleName))
			{
				CloseHandle(hSnapShot);
				return (DWORD)lpModuleEntry.modBaseAddr;
			}
			__RunModule = Module32Next(hSnapShot, &lpModuleEntry);
		}
		CloseHandle(hSnapShot);
		return NULL;
	}



	void runSetDebugPrivs()
	{
		HANDLE __HandleProcess = GetCurrentProcess(), __HandleToken;
		TOKEN_PRIVILEGES priv;
		LUID __LUID;
		OpenProcessToken(__HandleProcess, TOKEN_ADJUST_PRIVILEGES, &__HandleToken);
		LookupPrivilegeValue(0, "seDebugPrivilege", &__LUID);
		priv.PrivilegeCount = 1;
		priv.Privileges[0].Luid = __LUID;
		priv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		AdjustTokenPrivileges(__HandleToken, false, &priv, 0, 0, 0);
		CloseHandle(__HandleToken);
		CloseHandle(__HandleProcess);
	}



	void RunProcess()
	{
		runSetDebugPrivs();
		while (!FindProcessName("csgo.exe", &__gameProcess));
		while (!(getThreadByProcess(__gameProcess.th32ProcessID)));
		__HandleProcess = OpenProcess(PROCESS_ALL_ACCESS, false, __gameProcess.th32ProcessID);
		while (Client == 0x0) Client = GetModuleNamePointer("client_panorama.dll", __gameProcess.th32ProcessID);
		cout << "client_panoramd.dll : " << hex << Client << endl;
		while (Engine == 0x0) Engine = GetModuleNamePointer("engine.dll", __gameProcess.th32ProcessID);
		cout << "engine.dll : " << hex << Engine << endl;
		ReadProcessMemory(__HandleProcess,(PBYTE*)(Engine + OOF::signatures::dwClientState),&__ClientStauts,sizeof(uintptr_t),0);
		cout << "__ClientStauts : " << hex <<__ClientStauts << endl;
		__HWNDCss = FindWindow(NULL, "Counter-Strike: Global Offsensive");
	}
};

extern CHackProcess Hack;

