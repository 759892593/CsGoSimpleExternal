#include "OOF.h"

namespace OOF {
	namespace netvars {
		DWORD m_vecOrigin = 0x138;
		DWORD m_lifeState = 0x25F;
		DWORD m_iTeamNum = 0xF4;
		DWORD m_iHealth = 0x100;
		DWORD m_dwBoneMatrix = 0x26A8;
		DWORD m_iShotsFired = 0xA370;
		DWORD m_aimPunchAngle = 0x302C;
		DWORD m_iGlowIndex = 0xA3F8;
		DWORD m_iCrosshairId = 0xB394;
		DWORD m_fFlags = 0x104;
		DWORD m_bSpotted = 0x93D;
		DWORD m_bSpottedByMask = 0x980;
	}
	namespace signatures {
		DWORD dwClientState = 0x58BCFC;
		DWORD dwEntityList = 0x4CDB07C;
		DWORD dwClientState_ViewAngles = 0x4D88;
		DWORD dwLocalPlayer = 0xCCA6B4;
		DWORD dwbSendPackets = 0xD234A;
		DWORD dwForceAttack = 0x310C780;
		DWORD dwGlowObjectManager = 0x521AFA8;
		DWORD dwForceJump = 0x517E234;
		DWORD dwRadarBase = 0x510FDBC;
		DWORD clientstate_last_outgoing_command = 0x4D24; // iCurrentSequenceNumber 
		DWORD dwInput = 0x5125E10;
		
	}
}
// i away get offset from here v
//https://github.com/frk1/hazedumper/blob/master/csgo.cs