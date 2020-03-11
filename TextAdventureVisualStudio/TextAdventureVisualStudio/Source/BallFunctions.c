/******************************************************************************
filename    BallFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "gold piece".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "BallFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
typedef struct WorldData WorldData;


/* Helper: The action performed when the gold piece is taken. */
void Ball_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* safety check on the parameters */
	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the gold piece has already been scored */
	if (!GameFlags_IsInList(gameState->gameFlags, "BallScored") && gameState->currentRoomIndex == 60)
	{
		/* tell the user that something cool happens when they pick up the gold piece */
		printf("You have found the ball, its slippery but it will please the dog.\n");
		/* add to the user's score */
		GameState_ChangeScore(gameState, 5);
		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "BallScored");
	}
}
void Ball_Use(CommandContext context, GameState* gameState, WorldData* worldData) {

	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* ball; /* The bamboo in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	if (gameState->currentRoomIndex == 0)
	{
		printf("The ball doesn't like you");
	}

	/* check if the user is using the panda out of their inventory */
	if (context != CommandContext_Item_Inventory)
	{
		/* the user doesn't have the brick - inform the user of the problem and take no action */
		printf("you have no more bamboo.\n");
		/************************************************* DEATH CONDITION? *****************/
		return;
	}

	if (gameState->currentRoomIndex == 61) {
		if (GameFlags_IsInList(gameState->gameFlags, "objectsUsed2")) {
			printf("You had done the right choice already. Use the Panda!\n");
			return;
		}
		else {
			/* get the current room */
			room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

			/* get the list of items in the current room */
			roomItemsPtr = Room_GetItemList(room);
			if (roomItemsPtr == NULL)
			{
				return; /* take no action, as something is wrong - we should always have an item list */
			}

			/* Find the brick in the player's inventory - it should be there, since we are in the Inventory context */
			ball = ItemList_FindItem(gameState->inventory, "ball");

			/* Remove the brick from the user's inventory - they won't need it again */
			gameState->inventory = ItemList_Remove(gameState->inventory, ball);

			/* Tell the user what they did */
			printf("You have pleased the shiba. He now mutates into thicc shiba. He thanks your action. Panda comes back to you\n");

			/* Add to the player's score */
			GameState_ChangeScore(gameState, 10);

			/* Update the room description to reflect the change in the room */
			Room_SetDescription(room, "The shiba is asserting dominance, but he loves you. GO with your friend for prosperity.\n");


			/* the gold piece has not been scored, so mark the flag */
			gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "objectsUsed2");
		}
	}


}

/* Build a "gold piece" object */
Item* Ball_Build()
{
	/* Create a "gold piece" item, using the functions defined in this file */
	return Item_Create("ball", "slippery ball is ball\n", true, Ball_Use, Ball_Take, NULL);
}