/******************************************************************************
filename    CheeseFunctions.c
author      CJS
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "cheese".

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
void Cheese_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* cheese; /* The brick in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the brick out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("You must have the CHEESE before you can use it.\n");
		return;
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 30)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("You cannot use the CHEESE here.\n");
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
	cheese = ItemList_FindItem(gameState->inventory, "cheese");


	/* Tell the user what they did */
	printf("You manage to lure the RAT off of the podium with the CHEESE, allowing you a closer look at the BOMB.\n");
}


/* Build a "brick" object */
Item* Cheese_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("cheese", "cheese", true, Cheese_Use, NULL, NULL);
}