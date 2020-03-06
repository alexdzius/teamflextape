/******************************************************************************
filename    BambooFunctions.c
author      Alex Dzius
DP email    alex.dzius@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "bamboo".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "BambooFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "EggFunctions.h" /* Egg_Build */


/* Helper: The action performed when the bamboo is taken. */
void Bamboo_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* bamboo; /* The bamboo in the player's inventory */
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	if (gameState->currentRoomIndex == 58) {

		if (GameFlags_IsInList(gameState->gameFlags, "bambooTaken")) {
			printf("You already have enough bamboo, look for the ball!");
			return;
		}
		else {
			room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
			roomItemsPtr = Room_GetItemList(room);
			if (roomItemsPtr == NULL)
			{
				return; /* take no action, as something is wrong - we should always have an item list */
			}
			/* Find the bamboo in the player's inventory - it should be there, since we are in the Inventory context */
			bamboo = ItemList_FindItem(gameState->inventory, "bamboo");

			/* Remove the brick from the user's inventory - they won't need it again */
			gameState->inventory = ItemList_Remove(gameState->inventory, bamboo);

			/* Tell the user what they did */
			printf("You found the needed bamboo! Now don't forget the ball!\n");

		}

	}
}


/* Helper: The action performed when the bamboo is used. */
void Bamboo_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* bamboo; /* The bamboo in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the panda out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("you have no more bamboo.\n");
		/************************************************* DEATH CONDITION? *****************/
		return;
	}

	/* CAN BAMBOO BE USED HERE -- CONDITIONAL BASED ON ROOMS */
	if (gameState->currentRoomIndex != 0)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("bamboo is a long stick, you dont have it.\n");
		return;
	}
	/********************************************************************************** CHECK IF THIS WORKS AND/OR IS NEEDED *****************/
	/* check if the cage has already been broken and scored */
	if (gameState->currentRoomIndex == 55)
	{
		if (GameFlags_IsInList(gameState->gameFlags, "bambooUsed"))
		{
			/* the player already used the brick - inform the user of the problem and take no action */
			printf("The bamboo had been used.\n");
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

			/* Find the brick in the player's inventory - it should be there, since we are in the Inventory context */
			bamboo = ItemList_FindItem(gameState->inventory, "bamboo");

			/* Remove the brick from the user's inventory - they won't need it again */
			gameState->inventory = ItemList_Remove(gameState->inventory, bamboo);

			/* Tell the user what they did */
			printf("You have pleased the shiba. He now mutates into thicc shiba. He craves for more, but you dont have more. Panda will defend you\n");

			/* Add to the player's score */
			GameState_ChangeScore(gameState, 10);

			/* Update the room description to reflect the change in the room */
			Room_SetDescription(room, "The shiba is asserting dominance, the panda is defending you. Do what you must to safe your friend.\n");

			/* Add an egg to the current room, since the cage has been bashed open */
			*roomItemsPtr = ItemList_Add(*roomItemsPtr, Egg_Build());

			/* the gold piece has not been scored, so mark the flag */
			gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "bambooUsed");
		}
	}
	
}


/* Build a "panda" object */
Item* Bamboo_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("bamboo", "bamboo your loyal allys food", true, Bamboo_Use, Bamboo_Take, NULL);
}