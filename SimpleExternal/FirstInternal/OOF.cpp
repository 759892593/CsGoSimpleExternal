#include "OOF.h"

namespace OOF {
	namespace netvars {
		uintptr_t m_vecOrigin = 0x138;
		uintptr_t m_lifeState = 0x25F;
		uintptr_t m_iTeamNum = 0xF4;
		uintptr_t m_iHealth = 0x100;
		uintptr_t m_dwBoneMatrix = 0x26A8;
		uintptr_t m_iShotsFired = 0xA370;
		uintptr_t m_aimPunchAngle = 0x302C;
		uintptr_t m_iGlowIndex = 0xA3F8;
		uintptr_t m_iCrosshairId = 0xB394;
		uintptr_t m_fFlags = 0x104;
		uintptr_t m_bSpotted = 0x93D;
		uintptr_t m_bSpottedByMask = 0x980;
		
	}
	namespace signatures {
		uintptr_t dwClientState = 0x58BCFC;
		uintptr_t dwEntityList = 0x4CDB07C;
		uintptr_t dwClientState_ViewAngles = 0x4D88;
		uintptr_t dwLocalPlayer = 0xCCA6B4;
		uintptr_t dwbSendPackets = 0xD234A;
		uintptr_t dwForceAttack = 0x310C780;
		uintptr_t dwGlowObjectManager = 0x521AFA8;
		uintptr_t dwForceJump = 0x517E234;
		uintptr_t dwRadarBase = 0x510FDBC;
		uintptr_t clientstate_last_outgoing_command = 0x4D24; // iCurrentSequenceNumber 
		uintptr_t dwInput = 0x5125E10;
		uintptr_t dwClientState_PlayerInfo = 0x52B8;
		uintptr_t dwSetClanTag = 0x896A0;
		uintptr_t m_bDormant = 0xED;
	}
}
// i away get offset from here v
//https://github.com/frk1/hazedumper/blob/master/csgo.cs