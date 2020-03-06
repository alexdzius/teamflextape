/******************************************************************************
filename    ExitDoorFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "exit door".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "ExitDoorFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_EndGame */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;


/* Helper: The action performed when the exit door is used. */
void ExitDoor_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Item* Ball; /* the gold piece in the user's inventory */
	Item* bamboo; /* the egg in the user's inventory */

	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* find the gold piece in the user's inventory */
	Ball = ItemList_FindItem(gameState->inventory, "ball");

	/* find the egg in the user's inventory */
	bamboo = ItemList_FindItem(gameState->inventory, "bamboo");

	/* check if both items are in the user's inventory */
	if ((bamboo == NULL) || (Ball == NULL))
	{
		/* both items were not found - tell the user about the problem and take no further action */
		printf("You still need both the ball and bamboo to crave the shibas sustenance!\n");
		return;
	}
	else {
		GameState_EndGame(gameState, "Congratulations!  You leave with all of the treasures, and you win the game!\n");
	}
	/* the user has won the game! end the game, and let them know what happened. */
	
}


/* Build a "exit door" object */
Item* ExitDoor_Build()
{
	/* Create a "exit door" item, using the functions defined in this file */
	return Item_Create("exit", "The exit door is the exit door so you must exit through the exit door.\n", false, ExitDoor_Use, NULL, NULL);
}