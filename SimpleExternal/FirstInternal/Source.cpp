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

	Hack.RunProcess(); // Start Get Handle ModuleAdress etc
	Sleep(1000); // Wait 1 sec
	CBaseEntity localplayer; // create CBaseEntity to store localplayer
	CBaseEntity Player[32]; // create CBaseEntity as array to store all player

	system("cls");
	localplayer.playerbase = Mem::Read<DWORD>(Hack.__dwordClient + OOF::signatures::dwLocalPlayer); // get localplayeradr form localplayer offset
	

	for (;;) { // inf loop you can use while(true) to



		for (int i = 0; i < 32;i++)//loop i 0 to 32
		{

			Player[i].playerbase = enginetools::getentbyindex(i); // get entity adress by index
			Player[i].Read(); //read entity info

			if (Player[i].playerbase == NULL && Player[i].health < 1) // if playerbase not equal null and player hp less than 1 
				continue;											  //skip it because entity is invalid or dead

			localplayer.Read();										 //read localplayer info

			Vector a = MATH::CalcAngle(localplayer.position, Player[i].position); // calculate viewangle from player position and entity opsition

			if (GetAsyncKeyState(0x01)) // if press mouse1
				enginetools::SetViewAngle(a); // setviewangle to Vector a

		
			printf("Healt %d \n", Player[i].health); // print player hp as integer
			Glow(Player[i].glowindex);				 // call function glow by entityglowindex

		}
		Sleep(1); //make it less laggy
	}
	


}
/*
	
*/