#include "lilpump.h"
#include "OOF.h"
#include "define.h"

DWORD enginetools::getentbyindex(int i) {
	DWORD player = Mem::Read<DWORD>(Hack.__dwordClient + OOF::signatures::dwEntityList + (i * 0x10));

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
	Mem::Write<bool>(Hack.__dwordEngine + OOF::signatures::dwbSendPackets, a);

}
void enginetools::Jump() { Mem::Write<int>(Hack.__dwordClient + OOF::signatures::dwForceJump, 6); }
void enginetools::Fire() { Mem::Write<int>(Hack.__dwordClient + OOF::signatures::dwForceAttack, 6); }
void enginetools::UnFire() { Mem::Write<int>(Hack.__dwordClient + OOF::signatures::dwForceAttack, 4); }

void Glow(int i) {
	int a = i * 56;
	Color c(255,0,0,255);

	GlowBool b(true,false,false);

	DWORD glowobj = Mem::Read<DWORD>(Hack.__dwordClient + OOF::signatures::dwGlowObjectManager);
	Mem::Write<Color>(glowobj + (a + 0x4), c);
	Mem::Write<GlowBool>(glowobj + (a + 0x24), b);
}

char* getName(int index)//Entity index 1...32
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
	DWORD userInfoTable = Mem::Read<DWORD>(Hack.__ClientStauts + 0x5240);
	DWORD items = Mem::Read<DWORD>(Mem::Read<DWORD>(userInfoTable + 0x40) + 0xC);

	var = Mem::Read<player_info>(Mem::Read<DWORD>(items + 0x28 + ((index - 1) * 0x34)));
	DWORD abc = Mem::Read<DWORD>(items + 0x28 + ((index - 1) * 0x34));
	// **player_info
	cout << index << " "<< Mem::Read<DWORD>(items + 0x28 + ((index - 1) * 0x34)) << endl;
	//cout << var.szName << endl;
	return var.szName;
}
#define MULTIPLAYER_BACKUP    150
#include <thread>




Vector enginetools::GetCmdAngle()
{
	int iCurrentSequenceNumber = Mem::Read<int>(Hack.__ClientStauts + OOF::signatures::clientstate_last_outgoing_command);
	iCurrentSequenceNumber += 2;
	DWORD dwUserCMD = Mem::Read<DWORD>(Hack.__dwordClient + OOF::signatures::dwInput + 0xF4);
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
	DWORD dwUserCMD = Mem::Read<DWORD>(Hack.__dwordClient + OOF::signatures::dwInput + 0xF4);
	dwUserCMD += (iCurrentSequenceNumber % 150);
	UserCmd_t Cmd = Mem::Read<UserCmd_t>(dwUserCMD);
	return Cmd;
}
int enginetools::GetiCurrentSequenceNumber()
{
	int iCurrentSequenceNumber = Mem::Read<int>(Hack.__ClientStauts + OOF::signatures::clientstate_last_outgoing_command);

	return iCurrentSequenceNumber;
}