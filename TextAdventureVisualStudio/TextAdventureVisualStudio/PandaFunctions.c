/******************************************************************************
filename    PandaFunctions.c
author      Alex Dzius
DP email    alex.dzius@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "panda".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "PandaFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "EggFunctions.h" /* Egg_Build */


/* Helper: The action performed when the brick is taken. */
void Panda_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	/* PANDA TO BE YOUR FRIEND AFTER TAKE PANDA */
	if (gameState->currentRoomIndex == 52 || gameState->currentRoomIndex == 53) {
		printf("Busta Killa hears your call and comes excitedly. Do you SHOW him, or do you go BACK.\n");

	}
	else if (gameState->currentRoomIndex == 54) {
		printf("The Panda is at your side, do you SATISFY him or USE bamboo for the Shiba?\n");
	}
	else {
		printf("The Panda is your loyal ally now\n");
	}
	
}


/* Helper: The action performed when the panda is used. */
void Panda_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* panda; /* The brick in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the user is using the panda out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("The Panda doesn't hear you.\n");
		return;
	}

	/********************************************************************************** CHECK IF THIS WORKS AND/OR IS NEEDED *****************/
	if (gameState->currentRoomIndex == 54) {
		/* check if the cage has already been broken and scored */
		if (GameFlags_IsInList(gameState->gameFlags, "pandaAttack"))
		{
			/* the player already used the brick - inform the user of the problem and take no action */
			printf("Busta Killa already is tug-waring tHICC DOGE -- DONT DISAPPOINT HIM AND GO S E A R C H TO LOOK FOR THE ITEMS.\n");
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
			panda = ItemList_FindItem(gameState->inventory, "panda");

			/* Remove the brick from the user's inventory - they won't need it again */
			gameState->inventory = ItemList_Remove(gameState->inventory, panda);

			/* Tell the user what they did */
			printf("Busta killa roars out of pleasure. Though Doge is not fine with this. He begins to e x p a n d. DOGE became THICC SHIBA and SUDDENLY THROWS HIMSELF ON BUSTA KILLA. 'NOOOOO!' you scream, but you know you need to GO SEARCH for something to distract or feed DOGE!\n");

			/* Add to the player's score */
			GameState_ChangeScore(gameState, 10);

			/* Update the room description to reflect the change in the room */
			Room_SetDescription(room, "DOGE is engaging in fierce combat with Busta Killa. Don't forget to GO SEARCH for a distraction!\n");


			/* the gold piece has not been scored, so mark the flag */
			gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "pandaAttack");
		}
	}
	else if (gameState->currentRoomIndex == 52 || gameState->currentRoomIndex == 53) {
		printf("Busta killa begins to vibe to the music. He really vibin doe! You can always go BACK.\n");
	}
	else {
		printf("The Panda doesn't know what to do.\n");
		return;
	}
}


/* Build a "panda" object */
Item* Panda_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("panda", "panda your loyal ally", true, Panda_Use, Panda_Take, NULL);
}