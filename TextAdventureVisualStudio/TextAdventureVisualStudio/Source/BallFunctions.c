/******************************************************************************
filename    BallFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "gold piece".

******************************************************************************/
#include "stdafx.h"
#include "BallFunctions.h"
#include "GameState.h"
#include "GameFlags.h"
#include "Item.h"

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
	if (!GameFlags_IsInList(gameState->gameFlags, "BallScored"))
	{
		/* tell the user that something cool happens when they pick up the gold piece */
		printf("You have found the ball, its slippery but it will please the dog.\n");
		/* add to the user's score */
		GameState_ChangeScore(gameState, 5);
		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "BallScored");
	}
}


/* Build a "gold piece" object */
Item* Ball_Build()
{
	/* Create a "gold piece" item, using the functions defined in this file */
	return Item_Create("ball", "slippery ball is ball\n", true, NULL, Ball_Take, NULL);
}