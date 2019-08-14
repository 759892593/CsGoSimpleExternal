#pragma once
#include <Windows.h>
#include <urlmon.h>
// 2018-12-22 00:10:32.287010600 UTC

/*
namespace OOF {
	namespace netvars {
		extern uintptr_t m_vecOrigin ;
		extern uintptr_t m_lifeState ;
		extern uintptr_t m_iTeamNum ;
		extern uintptr_t m_iHealth ;
		extern uintptr_t m_dwBoneMatrix; 
		extern uintptr_t m_iShotsFired;
		extern uintptr_t m_aimPunchAngle;
		extern uintptr_t m_iGlowIndex;
		extern uintptr_t m_iCrosshairId;
		extern uintptr_t m_fFlags;
		extern uintptr_t m_bSpotted;
		extern uintptr_t m_bSpottedByMask;
		extern uintptr_t m_aimPunchAngle;
		extern uintptr_t m_vecViewOffset;
	}
	namespace signatures {
		extern uintptr_t dwClientState ;
		extern uintptr_t dwEntityList ;
		extern uintptr_t dwClientState_ViewAngles ;
		extern uintptr_t dwLocalPlayer;
		extern uintptr_t dwbSendPackets;
		extern uintptr_t dwForceAttack;
		extern uintptr_t dwGlowObjectManager;
		extern uintptr_t dwForceJump;
		extern uintptr_t dwRadarBase;
		extern uintptr_t clientstate_last_outgoing_command;
		extern uintptr_t dwInput ;
		extern uintptr_t dwClientState_PlayerInfo;
		extern uintptr_t dwSetClanTag;
		extern uintptr_t m_bDormant;
	}
}

*/


namespace OOF {
	namespace netvars {
		static uintptr_t m_vecOrigin = 0x138;
		static uintptr_t m_lifeState = 0x25F;
		static uintptr_t m_iTeamNum = 0xF4;
		static uintptr_t m_iHealth = 0x100;
		static uintptr_t m_dwBoneMatrix = 0x26A8;
		static uintptr_t m_iShotsFired = 0xA380;
		static uintptr_t m_aimPunchAngle = 0x302C;
		static uintptr_t m_iGlowIndex = 0xA40C;
		static uintptr_t m_iCrosshairId = 0xB394;
		static uintptr_t m_fFlags = 0x104;
		static uintptr_t m_bSpotted = 0x93D;
		static uintptr_t m_bSpottedByMask = 0x980;
		static uintptr_t m_vecViewOffset = 0x108;
	}
	namespace signatures {
		static uintptr_t dwClientState = 0x590D8C;
		static uintptr_t dwEntityList = 0x4D05B34;
		static uintptr_t dwClientState_ViewAngles = 0x4D88;
		static uintptr_t dwLocalPlayer = 0xCF3A4C;
		static uintptr_t dwbSendPackets = 0xD2C5A;
		static uintptr_t dwForceAttack = 0x313722C;
		static uintptr_t dwGlowObjectManager = 0x5245F50;
		static uintptr_t dwForceJump = 0x51A91EC;
		static uintptr_t dwRadarBase = 0x513A894;
		static uintptr_t clientstate_last_outgoing_command = 0x4D24; // iCurrentSequenceNumber 
		static uintptr_t dwInput = 0x5150B80;
		static uintptr_t dwClientState_PlayerInfo = 0x52B8;
		static uintptr_t dwSetClanTag = 0x89890;
		static uintptr_t m_bDormant = 0xED;
	}
}

// i away get offset from here v
//https://github.com/frk1/hazedumper/blob/master/csgo.cs