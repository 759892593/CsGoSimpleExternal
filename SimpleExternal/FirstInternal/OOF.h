#pragma once
#include <Windows.h>
#include <urlmon.h>
// 2018-12-22 00:10:32.287010600 UTC

namespace OOF {
	namespace netvars {
		extern DWORD m_vecOrigin ;
		extern DWORD m_lifeState ;
		extern DWORD m_iTeamNum ;
		extern DWORD m_iHealth ;
		extern DWORD m_dwBoneMatrix; 
		extern DWORD m_iShotsFired;
		extern DWORD m_aimPunchAngle;
		extern DWORD m_iGlowIndex;
		extern DWORD m_iCrosshairId;
		extern DWORD m_fFlags;
		extern DWORD m_bSpotted;
		extern DWORD m_bSpottedByMask;
	}
	namespace signatures {
		extern DWORD dwClientState ;
		extern DWORD dwEntityList ;
		extern DWORD dwClientState_ViewAngles ;
		extern DWORD dwLocalPlayer;
		extern DWORD dwbSendPackets;
		extern DWORD dwForceAttack;
		extern DWORD dwGlowObjectManager;
		extern DWORD dwForceJump;
		extern DWORD dwRadarBase;
		extern DWORD clientstate_last_outgoing_command;
		extern DWORD dwInput ;
	}
}