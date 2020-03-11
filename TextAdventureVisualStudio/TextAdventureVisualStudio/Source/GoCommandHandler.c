/******************************************************************************
filename    GoCommandHandler.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines functions that handle the "go" user command, which moves
the user from one room to another using defined exits.

******************************************************************************/
#include "stdafx.h" /* NULL, printf */
#include "GoCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetNextRoomIndex, Room_Print, INVALID_DIRECTION_ID */
#include "GameFlags.h"

/* Handles the "go" command, which moves the user to another room */
void HandleGoCommand(CommandData *command, GameState *gameState, WorldData *worldData)
{
	Room* currentRoom; /* the room we are currently in */
	int nextRoomIndex; /* the index of hte next room */

	/* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL)) 
	{
		return; /* take no action if the parameters are invalid */
	}

	/* get the current room, based on the user state */
	currentRoom = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/* get the next room index, based on the noun used with "go" */
	if (Room_GetNextRoomIndex(currentRoom, command->noun, &nextRoomIndex) == false)
	{
		/* there is no exit in that direction, so let the user know and take no other action */
		
		/* if its in room 50 which has option south then do the fire noise*/
		if (gameState->currentRoomIndex == 50) {
			printf("Bruh you can see the exit just go there ok thanks, dont go %s again\n", command->noun);
		}
		else if (gameState->currentRoomIndex == 54) {
			printf("Even with Doge pleased, something is happening to busta killa! This is not good, he is exploding! --- Nevermind, he just has wings now. You promptly mount him, and you two fly away into the abyss!\n");
		}
		else {
			printf("You cannot move %s.\n", command->noun);
		}
		return;
	}

	/* update the game state to move to the new room */
	if ((gameState->currentRoomIndex == 54 && nextRoomIndex == 55 && GameFlags_IsInList(gameState->gameFlags, "pandaAttack")) || (gameState->currentRoomIndex == 61 && nextRoomIndex == 55 && !GameFlags_IsInList(gameState->gameFlags, "objectsUsed") && !GameFlags_IsInList(gameState->gameFlags, "objectsUsed2"))) {
		printf("You cannot leave the room with the panda, he fights the shiba for you! Make sure you use the items.\n");
	}
	else {
		gameState->currentRoomIndex = nextRoomIndex;
		/* output the successful action */
		printf("You move %s.\n\n", command->noun);

		/* get the new room */
		currentRoom = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

		/* print the description of the new room */
		Room_Print(currentRoom);
	}
}