/******************************************************************************
filename    SnakeFunctions.c
author      Marvin Chan
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "gold piece".

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
#include "SnakeFunctions.h" /* Snake */
#include <stdio.h>
#include <ctype.h>

typedef struct WorldData WorldData;

/* Helper: The action performed when the bamboo is taken. */
void Snake_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	Room* room; /* The current room */
	ItemList** roomItemsPtr; /* The list of items in the current room */
	Item* snake; /* The snake in the player's inventory */
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
	roomItemsPtr = Room_GetItemList(room);
	if (roomItemsPtr == NULL)
	{
		return; /* take no action, as something is wrong - we should always have an item list */
	}
	/* Find the bamboo in the player's inventory - it should be there, since we are in the Inventory context */
	snake = ItemList_FindItem(gameState->inventory, "snake");

	/* Remove the brick from the user's inventory - they won't need it again */
	gameState->inventory = ItemList_Remove(gameState->inventory, snake);

	/* Tell the user what they did */
	printf("You got a snake!\n");

}

/* Build a "gold piece" object */
Item* Snake_Build()
{
	/* Create a "gold piece" item, using the functions defined in this file */
	return Item_Create("snake", "A snake. It acts like a snake and looks like a snake.\n", true, NULL, Snake_Take, NULL);
}