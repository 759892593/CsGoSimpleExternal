#include "lilpump.h"
#include "OOF.h"
#include "define.h"

uintptr_t enginetools::getentbyindex(int i) {
	uintptr_t player = Mem::Read<uintptr_t>(Hack.Client + OOF::signatures::dwEntityList + (i * 0x10));

	return player;
}

void enginetools::SetViewAngle(Vector aimat) {
	
	Mem::Write<Vector>(Hack.__ClientStauts + OOF::signatures::dwClientState_ViewAngles,aimat);
}

Vector enginetools::GetAngle() { 
	Vector a;
	a = Mem::Read<Vector>(Hack.__ClientStauts + OOF::signatures::dwClientState_ViewAngles); 
	return a; 
}

void enginetools::SendPacket(bool a) {
	Mem::Write<bool>(Hack.Engine + OOF::signatures::dwbSendPackets, a);

}
void enginetools::Jump() { Mem::Write<int>(Hack.Client + OOF::signatures::dwForceJump, 6); }
void enginetools::Fire() { Mem::Write<int>(Hack.Client + OOF::signatures::dwForceAttack, 6); }
void enginetools::UnFire() { Mem::Write<int>(Hack.Client + OOF::signatures::dwForceAttack, 4); }

void Mem::WriteMem(uintptr_t address, LPVOID lpBuffer, uintptr_t size) { WriteProcessMemory(Hack.__HandleProcess, (LPVOID)address, lpBuffer, size, 0); }
void Mem::ReadMem(uintptr_t address, LPVOID lpBuffer, uintptr_t size) { ReadProcessMemory(Hack.__HandleProcess, (LPVOID)address, lpBuffer, size, 0); }


void Glow(int i, Color c, bool fullblom) 
{
	int a = i * 56;

	GlowBool b(true,false, fullblom);

	uintptr_t glowobj = Mem::Read<uintptr_t>(Hack.Client + OOF::signatures::dwGlowObjectManager);
	Mem::Write<Color>(glowobj + (a + 0x4), c);
	Mem::Write<GlowBool>(glowobj + (a + 0x24), b);
}

string getName(int index) //Entity index 1...32
{
	

	
	struct player_info
	{
		__int64         unknown;            //0x0000 
		union
		{
			__int64       steamID64;          //0x0008 - SteamID64
			struct
			{
				__int32     xuid_low;
				__int32     xuid_high;
			};
		};
		char            szName[128];        //0x0010 - Player Name
		int             userId;             //0x0090 - Unique Server Identifier
		char            szSteamID[20];      //0x0094 - STEAM_X:Y:Z
		char            pad_0x00A8[0x10];   //0x00A8
		unsigned long   iSteamID;           //0x00B8 - SteamID 
		char            szFriendsName[128];
		bool            fakeplayer;
		bool            ishltv;
		unsigned int    customfiles[4];
		unsigned char   filesdownloaded;
	} var;
		
	memset(&var, 0, sizeof(var));

	uintptr_t userInfoTable = Mem::Read<uintptr_t>(Hack.__ClientStauts + OOF::signatures::dwClientState_PlayerInfo);
	uintptr_t items = Mem::Read<uintptr_t>(Mem::Read<uintptr_t>(userInfoTable + 0x40) + 0xC); // 0x3C

	var = Mem::Read<player_info>(Mem::Read<uintptr_t>(items + 0x28 + ((index - 1) * 0x34)));
	string name = string(var.szName);
	//cout << name << endl;
	return name;
	


}


#define MULTIPLAYER_BACKUP    150
#include <thread>




Vector enginetools::GetCmdAngle()
{
	int iCurrentSequenceNumber = Mem::Read<int>(Hack.__ClientStauts + OOF::signatures::clientstate_last_outgoing_command);
	iCurrentSequenceNumber += 2;
	uintptr_t dwUserCMD = Mem::Read<uintptr_t>(Hack.Client + OOF::signatures::dwInput + 0xF4);
	dwUserCMD += (iCurrentSequenceNumber % 150);
	UserCmd_t Cmd = Mem::Read<UserCmd_t>(dwUserCMD);
	cout << " Cmd.m_iCmdNumber :" << Cmd.m_iCmdNumber << " iCurrentSequenceNumber:" << iCurrentSequenceNumber << endl;
	if (Cmd.m_iCmdNumber == iCurrentSequenceNumber) {
		enginetools::SendPacket(true);
		cout << " Cmd Match !!!" << endl;
		Beep(1000, 500);
		system("pause");
	}
	//return Mem::Read<Vector>(dwUserCMD + 0xC);
	return Cmd.m_vecViewAngles;
}
UserCmd_t enginetools::GetUserCmd(int seqnum)
{
	int iCurrentSequenceNumber = seqnum + 2;
	uintptr_t dwUserCMD = Mem::Read<uintptr_t>(Hack.Client + OOF::signatures::dwInput + 0xF4);
	dwUserCMD += (iCurrentSequenceNumber % 150);
	UserCmd_t Cmd = Mem::Read<UserCmd_t>(dwUserCMD);
	return Cmd;
}
int enginetools::GetiCurrentSequenceNumber()
{
	int iCurrentSequenceNumber = Mem::Read<int>(Hack.__ClientStauts + OOF::signatures::clientstate_last_outgoing_command);

	return iCurrentSequenceNumber;
}

#define MAX_TEXT_SIZE  15
void enginetools::SetClanTag(string tagstring)
{
	static bool allocit = false;
	const char* tag = tagstring.c_str();
	const char* name = "BLANK";
	HANDLE ProcessHandle = Hack.__HandleProcess;

	/*
		51						push	ecx
		52						push	edx
		B9 00 00 00 00			mov		ecx, tag
		BA 00 00 00 00			mov	    edx, name
		E8 00 00 00 00			call	0
		83 04 24 0A				add		dword ptr [esp], 0A
		68 00 00 00 00			push	engine.dll + OFFSET
		C3						ret
		5A						pop		edx
		59						pop		ecx
		C3						ret
		00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
		00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
	*/
	unsigned char Shellcode[] =
		"\x51"
		"\x52"
		"\xB9\x00\x00\x00\x00"
		"\xBA\x00\x00\x00\x00"
		"\xE8\x00\x00\x00\x00"
		"\x83\x04\x24\x0A"
		"\x68\x00\x00\x00\x00"
		"\xC3"
		"\x5A"
		"\x59"
		"\xC3"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
		"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";

	unsigned int SHELLCODE_SIZE = sizeof(Shellcode) - 0x21;
	unsigned int TAG_SIZE = (strlen(tag) > MAX_TEXT_SIZE) ? MAX_TEXT_SIZE : strlen(tag);
	unsigned int NAME_SIZE = (strlen(name) > MAX_TEXT_SIZE) ? MAX_TEXT_SIZE : strlen(name);
	unsigned int DATA_SIZE = TAG_SIZE + NAME_SIZE + 2;
	LPVOID ShellCodeAdr = 0;
	if (!allocit)
	{
		LPVOID ShellCodeAddress = VirtualAllocEx(ProcessHandle,
			0,
			SHELLCODE_SIZE + DATA_SIZE,
			MEM_COMMIT | MEM_RESERVE,
			PAGE_EXECUTE_READWRITE
		);

		DWORD dwTagAddress = (DWORD)ShellCodeAddress + SHELLCODE_SIZE;
		DWORD dwNameAddress = (DWORD)ShellCodeAddress + SHELLCODE_SIZE + TAG_SIZE + 1;
		DWORD dwSetClanAddress = Hack.Engine + OOF::signatures::dwSetClanTag;

		memcpy(Shellcode + 0x3, &dwTagAddress, sizeof(DWORD));
		memcpy(Shellcode + 0x8, &dwNameAddress, sizeof(DWORD));
		memcpy(Shellcode + 0x16, &dwSetClanAddress, sizeof(DWORD));
		memcpy(Shellcode + SHELLCODE_SIZE, tag, TAG_SIZE);
		memcpy(Shellcode + SHELLCODE_SIZE + TAG_SIZE + 1, name, NAME_SIZE);

		WriteProcessMemory(ProcessHandle, ShellCodeAddress, Shellcode, SHELLCODE_SIZE + DATA_SIZE, 0);
		ShellCodeAdr = ShellCodeAddress;
		allocit = true;
	}

	HANDLE hThread = CreateRemoteThread(ProcessHandle, NULL, NULL, (LPTHREAD_START_ROUTINE)ShellCodeAdr, NULL, NULL, NULL);
	WaitForSingleObject(hThread, INFINITE);
	//VirtualFreeEx(ProcessHandle, ShellCodeAddress, 0, MEM_RELEASE);

}