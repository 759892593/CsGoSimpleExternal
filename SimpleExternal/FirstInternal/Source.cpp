/*
  ████████╗██████╗  █████╗ ██╗███╗   ██╗███████╗██████╗ ████████╗██╗  ██╗ █████╗ ██╗
  ╚══██╔══╝██╔══██╗██╔══██╗██║████╗  ██║██╔════╝██╔══██╗╚══██╔══╝██║  ██║██╔══██╗██║
     ██║   ██████╔╝███████║██║██╔██╗ ██║█████╗  ██████╔╝   ██║   ███████║███████║██║
     ██║   ██╔══██╗██╔══██║██║██║╚██╗██║██╔══╝  ██╔══██╗   ██║   ██╔══██║██╔══██║██║
     ██║   ██║  ██║██║  ██║██║██║ ╚████║███████╗██║  ██║   ██║   ██║  ██║██║  ██║██║
     ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝
	Made By TrainerthaiCommunity aka Lnwtida , Meganoise , furryl0ver
	header.h by guidehacks (maybe)

	sry for bad english i will try my best \(._.)/
	pls dont care my filename and my s p a c e t y p e s t y l e 

*/	



#include "fuckfurry.h"
#include <iostream>
#include "vac bypass leak.hpp"
#include "include.h"

CHackProcess Hack;

CBaseEntity localplayer;

int get_closet_player()
{
	int closet_index = 99;
	float cur_distance = 99999.f;
	for (int i = 0; i <= 32; i++)
	{
		localplayer.Read();
		CBaseEntity player = enginetools::getentbyindex(i);
		player.Read();

		if (!player || player.health < 1 || player.playerbase == localplayer.playerbase)
			continue;
		if (player.team == localplayer.team)
			continue;

		float distance = MATH::flGetDistance(player.position ,localplayer.position);
		if (distance < cur_distance)
		{
			cur_distance = distance;
			closet_index = i;
		}
	}
	return closet_index;
}

void RCS()
{
	static Vector oldAimPunch;
	static Vector fixedAngle;
	localplayer.Read();
	if (localplayer.shootfired > 1)
	{
		Vector aimpunch = localplayer.punch_angle * 2.f;
		Vector viewangle = enginetools::GetAngle();
		fixedAngle.x = viewangle.x - (aimpunch.x - oldAimPunch.x);
		fixedAngle.y = viewangle.y - (aimpunch.y - oldAimPunch.y);

		MATH::clampAngle(fixedAngle);

		enginetools::SetViewAngle(fixedAngle);

		oldAimPunch = aimpunch;
	}
	else
	{
		oldAimPunch.x = 0;
		oldAimPunch.y = 0;
		fixedAngle.x = 0;
		fixedAngle.y = 0;
	}
}

int main() {

	Hack.RunProcess(); 
	Sleep(1000); 
	

	
	

	system("cls");
	localplayer.playerbase = Mem::Read<uintptr_t>(Hack.Client + OOF::signatures::dwLocalPlayer); 
	
	enginetools::SetClanTag("Skeet.cc");
	SetConsoleTitleA("Skeet.cc");
	cout << "[function]" << endl;
	cout << "fullbloom glow (only closet player)" << endl;
	cout << "rcs aimbot (alt + mouse 1)" << endl;
	cout << "radar hack" << endl;
	cout << "RCS" << endl;
	for (;;) {
		
		RCS();

		for (int i = 0; i <= 32; i++)
		{
			CBaseEntity player = enginetools::getentbyindex(get_closet_player());
			player.Read();

			if (!player || player.health < 1 || player.playerbase == localplayer.playerbase)
				continue;
			if (player.team == localplayer.team)
				continue;

	

			localplayer.Read();

			Vector aimat = MATH::CalcAngle(localplayer.geteyepos(), player.GetBonePos(8)) - localplayer.punch_angle * 2.f;
			if (GetAsyncKeyState(VK_MENU) && GetAsyncKeyState(0x1))
				enginetools::SetViewAngle(aimat);

			Mem::Write<bool>(player.playerbase + OOF::netvars::m_bSpotted, true);
			

			Glow(player.glowindex, Color(255, 0, 0, 255), true);
		}
		

		
		
		Sleep(1); 
	}
	


}
/*
	
*/