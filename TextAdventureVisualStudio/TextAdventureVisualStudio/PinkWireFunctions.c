/******************************************************************************
filename    PinkWireFunctions.c
author      CJS
DP email
course      GAM100 ** I'll use this f*cking code in my project if I'd like

Brief Description:
This file defines the functions to create a specific item, the "brick".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "PinkWireFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
//#include "EggFunctions.h" /* Egg_Build */




/* Helper: The action performed when the brick is used. */
void PinkWire_Use(CommandContext context, GameState* gameState, WorldData* worldData)
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
	if (gameState->currentRoomIndex != 30)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("There is no PINK WIRE here.\n");
		return;
	}

	/* check if the cage has already been broken and scored */
	if (GameFlags_IsInList(gameState->gameFlags, "pinkSolution"))
	{
		/* the player already used the brick - inform the user of the problem and take no action */
		printf("You manage to get Busta Killa to chew the bamboo WIRE off of the BOMB.\n\nThe TIMER has stopped ticking.\n\nThe rat approaches you.\n'Thou hast passed the puzzle of the rat. Thou art worthy of continuing on thy quest. My final message is for thou to change the world. Farewell.'\nThe RAT fades to a place elsewhere, as the door to the NEXT FLOOR opens.\n");
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

		if (!GameFlags_IsInList(gameState->gameFlags, "pinkSolution"))
		{
			printf("You manage to get Busta Killa to chew the bamboo WIRE off of the BOMB.\n\nI think that did the triuheirbgjn9u439u77643bc9u0g720bnidc8084b4b7gv9fdu0viwhn420ibpdj0cvfg972340ub0c8hfrg7tt4y3vbfc0989549u243b0cv8hbvujfobvydshclol023ojzjiofbjnf20i2okjsllwh02pnksvpg0r3ipk2nbrgih0fvipdsjbgrngpsjig2pbgu593gopwjgk\n");
		}

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);

		/* Update the room description to reflect the change in the room */
		Room_SetDescription(room, "This is room 0.  You are in a display room.  There is a broken cage here.\n");


	}
}


/* Build a "brick" object */
Item* PinkWire_Build()
{
	/* Create a "brick" item, using the functions defined in this file */
	return Item_Create("pink wire", "AAAAAAAAAAHHHHHHHHH", true, PinkWire_Use, NULL, NULL);
}