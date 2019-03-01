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



int main() {

	Hack.RunProcess(); 
	Sleep(1000); 
	CBaseEntity localplayer;
	CBaseEntity Player[32]; 

	

	system("cls");
	localplayer.playerbase = Mem::Read<uintptr_t>(Hack.Client + OOF::signatures::dwLocalPlayer); 
	
	enginetools::SetClanTag("Skeet.cc");
	for (;;) {



		for (int i = 0; i <= 32; i++)
		{

			Player[i].playerbase = enginetools::getentbyindex(i);
			Player[i].Read();

			if (Player[i].playerbase == NULL || Player[i].health < 1 || Player[i].playerbase == localplayer.playerbase)
				continue;
			if (Player[i].team == localplayer.team)
				continue;

			localplayer.Read();

			Vector aimat = MATH::CalcAngle(localplayer.position, Player[i].position);

			if (GetAsyncKeyState(VK_MENU)) // ALT
				enginetools::SetViewAngle(aimat);

	
			
			Glow(Player[i].glowindex, Color(255, 0, 0, 255), false);

		
		}
		Sleep(1); 
	}
	


}
/*
	
*/