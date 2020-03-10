/******************************************************************************
filename    SnakeFunctions.c
author      Marvin Chan
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "gold piece".

******************************************************************************/
#include "stdafx.h"
#include "SnakeFunctions.h"
#include "GameState.h"
#include "GameFlags.h"
#include "Item.h"

typedef struct WorldData WorldData;


/* Build a "gold piece" object */
Item* Snake_Build()
{
	/* Create a "gold piece" item, using the functions defined in this file */
	return Item_Create("snake", "A snake. It acts like a snake and looks like a snake.\n", true, NULL, NULL, NULL);
}