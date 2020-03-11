/******************************************************************************
filename    ManualFunctions.c
author      CJS
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "manual".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "BrickFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "ManualFunctions.h" /* Manual_Build */


/* Helper: The action performed when the brick is taken. */


/* Helper: The action performed when the brick is used. */
void Manual_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* manual; /* The brick in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the brick out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("You must have the MANUAL before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 30 && gameState->currentRoomIndex != 31 && gameState->currentRoomIndex != 32)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the MANUAL here.\n");
		return;
	}

		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* Find the brick in the player's inventory - it should be there, since we are in the Inventory context */

		manual = ItemList_FindItem(gameState->inventory, "manual");

		/* Tell the user what they did */
		if (!GameFlags_IsInList(gameState->gameFlags, "pinkSolution"))
		{
			printf("The BOMB MANUAL reads as follows:\n'To set the BOMB, simply turn the timer on the BOMB to however long you would like the BOMB to wait for. Then run.\nTo disable the bomb, cut the PINK WIRE.'\n");
		}
		else if (!GameFlags_IsInList(gameState->gameFlags, "plaidSolution"))
		{
			printf("The BOMB MANUAL reads as follows:\n'To set the BOMB, simply turn the timer on the BOMB to however long you would like the BOMB to wait for. Then run.\nTo disable the bomb, cut the PLAID WIRE.'\n");
		}
		else if (!GameFlags_IsInList(gameState->gameFlags, "greySolution"))
		{
			printf("The BOMB MANUAL reads as follows:\n'To set the BOMB, simply turn the timer on the BOMB to however long you would like the BOMB to wait for. Then run.\nTo disable the bomb, cut the GREY WIRE.'\n");
		}
}


/* Build a "brick" object */
Item* Manual_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("manual", "A bomb defusal manual", true, Manual_Use, NULL, NULL);
}