#pragma once
#include <Windows.h>
#include <urlmon.h>
// 2018-12-22 00:10:32.287010600 UTC

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