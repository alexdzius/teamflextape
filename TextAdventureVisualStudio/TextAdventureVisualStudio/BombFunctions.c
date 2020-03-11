/******************************************************************************
filename    BombFunctions.c
author      CJS
DP email    
course      GAM100 ** I'll use this f*cking code in my project if I'd like

Brief Description:
This file defines the functions to create a specific item, the "brick".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "BombFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
//#include "EggFunctions.h" /* Egg_Build */


/* Helper: The action performed when the brick is taken. */
void Bomb_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

}


/* Helper: The action performed when the brick is used. */
void Bomb_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */

	UNREFERENCED_PARAMETER(context);

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}


	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 0)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("There is no BOMB here.\n");
		return;
	}

	/* check if the cage has already been broken and scored */
	if (!GameFlags_IsInList(gameState->gameFlags, "bombDefused"))
	{
		/* the player already used the brick - inform the user of the problem and take no action */
		printf("The BOMB appears to have three wires: a PINK WIRE, a PLAID WIRE, and a GREY WIRE.\nAll seem to be made of bamboo.\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}




		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);

		/* Update the room description to reflect the change in the room */
		Room_SetDescription(room, "This is room 0.  You are in a display room.  There is a broken cage here.\n");

	}
}


/* Build a "brick" object */
Item* Bomb_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("bomb", "AAAAAAAAAAHHHHHHHHH", true, Bomb_Use, Bomb_Take, NULL);
}