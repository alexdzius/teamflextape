/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "BrickFunctions.h" /* Brick_Build */
#include "PandaFunctions.h" /* Panda_Build */
#include "BambooFunctions.h" /* Bamboo_Build */
#include "BallFunctions.h" /* Ball_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */



/******************************************************************************
	Build room TEMPLATE
    Use this example function to build additional rooms
******************************************************************************/
Room* RoomN_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	   include an initial room description */
	room = Room_Create("DEBUG: This is a template - Include a description for the room here\n");

	/* Exits
	   add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

	/* Items
	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* Return the new room */
	return room;
}


/* TODO REQUIRED: FLOOR -1 AND 0, SPAM MORE ROOMS WITH 0 PREFIX TO HAVE EXPANDED */
Room* Room0_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 0. It is a display room with a cage in the middle. You can see a jeweled egg inside the cage.  There is a crack in the west wall, but you can't fit through it from this side.\n" */
	
	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	/* TODO BASIC: Add room exit shortcut for "n" */

	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */

	/* TODO ADVANCED: (not required) update the description and add a room exit to the "east" */

	/* return the new room */
	return room;
}
/* TODO REQUIRED: FLOOR 1, SPAM MORE ROOMS WITH 1 PREFIX TO HAVE EXPANDED */
Room* Room1_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 1.  There is a large mirror here, and it shimmers as you approach.\n" */

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */

	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	/* TODO BASIC: Add room exit shortcut for "s" */

	/* TODO REQUIRED: Add a brick to the list of items in the room */

	/* return the new room */
	return room;
}
/* TODO REQUIRED: FLOOR 2, SPAM MORE ROOMS WITH 2 PREFIX TO HAVE EXPANDED */
Room* Room2_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
/* TODO REQUIRED: FLOOR 3, SPAM MORE ROOMS WITH 3 PREFIX TO HAVE EXPANDED */
Room* Room3_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
/* TODO REQUIRED: FLOOR 4, SPAM MORE ROOMS WITH 4 PREFIX TO HAVE EXPANDED */
Room* Room4_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("this is the entrance hall room thing");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* the map room thing*/
	Room_AddRoomExit(room, "east", 41);
	/* suspicious wizard's room*/
	Room_AddRoomExit(room, "west", 42);
	/* snake knight main chamber*/
	Room_AddRoomExit(room, "north", 43);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
Room* Room4a_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("this is the map room");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* weaponry room*/
	Room_AddRoomExit(room, "south", 44);
	/* main hallway */
	Room_AddRoomExit(room, "west", 40);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
Room* Room4b_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("suspicious wizards chamber");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* main entarnce*/
	Room_AddRoomExit(room, "east", 40);
	/* bathroom */
	Room_AddRoomExit(room, "south", 45);
	/* janitors closet */
	Room_AddRoomExit(room, "north", 46);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
Room* Room4c_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("snake knight main chamber");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* main entrance */
	Room_AddRoomExit(room, "south", 40);
	/* top hallway */
	Room_AddRoomExit(room, "north", 47);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
Room* Room4d_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("top hallway");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* armory*/
	Room_AddRoomExit(room, "east", 48);
	/* blacksmith */
	Room_AddRoomExit(room, "west", 49);
	/* snake knight main chamber*/
	Room_AddRoomExit(room, "south", 43);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
Room* Room4e_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("weaponry");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* map room */
	Room_AddRoomExit(room, "north", 41);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
Room* Room4f_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("bathroom");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* suspicious wizarsd room */
	Room_AddRoomExit(room, "north", 42);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
Room* Room4g_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("janitors closet");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* suspicious wizarsd room */
	Room_AddRoomExit(room, "south", 42);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
Room* Room4h_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("armory");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* top hallway */
	Room_AddRoomExit(room, "west", 47);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
Room* Room4i_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("blacksmith");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* top hallway */
	Room_AddRoomExit(room, "east", 47);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
/* TODO REQUIRED: FLOOR 5, SPAM MORE ROOMS WITH 0 PREFIX TO HAVE EXPANDED */
Room* Room5_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("this is the stairs before the main room, south is downstairs and east is exit");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "east", 51); /****************************************** this will be the exit to room************/
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	/* return the new room */
	return room;
}
Room* Room5a_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("The final boss has arrived");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "north", 52); /*outlook top*/
	Room_AddRoomExit(room, "south", 53); /* outlook bottom */
	Room_AddRoomExit(room, "east", 54); /* approach the shiba */
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	/* return the new room */
	return room;
}
Room* Room5b_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("A wonderful outlook, with a sunny day in Japan. south back to center \n");
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "south", 51);
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	/* return the new room */
	return room;
}
Room* Room5c_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("A wonderful outlook, with a sunny day in Japan. north back to center \n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "north", 51);
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* return the new room */
	return room;
}
Room* Room5d_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("The shiba has assesed his dominance. You must contain the shiba completely \n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "panda", 55);
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* return the new room */
	return room;
}
Room* Room5e_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/


	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("You left the castle, now you are enjoying the sun on a flying panda. The EXIT is the end of the game.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	/* return the new room */
	return room;
}
Room* Room5f_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/


	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("You left the castle, now you are enjoying the sun on a flying panda. The EXIT is the end of the game.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	/* return the new room */
	return room;
}
Room* Room5g_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/


	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("You left the castle, now you are enjoying the sun on a flying panda. The EXIT is the end of the game.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	/* return the new room */
	return room;
}
Room* Room5h_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/


	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("You left the castle, now you are enjoying the sun on a flying panda. The EXIT is the end of the game.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	/* return the new room */
	return room;
}
Room* Room5i_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/


	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("You left the castle, now you are enjoying the sun on a flying panda. The EXIT is the end of the game.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	/* return the new room */
	return room;
}
Room* Room5j_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/


	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("You left the castle, now you are enjoying the sun on a flying panda. The EXIT is the end of the game.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	/* return the new room */
	return room;
}
Room* Room5k_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/


	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("The Shiba and Panda are still fighting. Give them the items.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	/* return the new room */
	return room;
}



/* ------------------------------------------------------- */
/* Create the world data for a new game */
/* ------------------------------------------------------- */
WorldData* CreateInitialWorldData()
{
	/* The new world data */
	WorldData* worldData;

	/* TODO REQUIRED: update room count to match the number of rooms you have created and added to the world
	   if this number doesn't match then your game will either crash or you will end up stuck in a broken room with no exits */
	int roomCount = 62; /* FIX THIS ONCE DONE */

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room0_Build());
	/* TODO REQUIRED: add rooms 1 and 2 to the world data */
	WorldData_SetRoom(worldData, 10, Room1_Build());
	WorldData_SetRoom(worldData, 20, Room2_Build());
	WorldData_SetRoom(worldData, 30, Room3_Build());
	/* last floor levels*/
	WorldData_SetRoom(worldData, 40, Room4_Build());
	WorldData_SetRoom(worldData, 41, Room4a_Build());
	WorldData_SetRoom(worldData, 42, Room4b_Build());
	WorldData_SetRoom(worldData, 43, Room4c_Build());
	WorldData_SetRoom(worldData, 44, Room4e_Build());
	WorldData_SetRoom(worldData, 45, Room4f_Build());
	WorldData_SetRoom(worldData, 46, Room4g_Build());
	WorldData_SetRoom(worldData, 47, Room4d_Build());
	WorldData_SetRoom(worldData, 48, Room4h_Build());
	WorldData_SetRoom(worldData, 49, Room4i_Build());
	/* pre fight*/
	WorldData_SetRoom(worldData, 50, Room5_Build());
	WorldData_SetRoom(worldData, 51, Room5a_Build());
	WorldData_SetRoom(worldData, 52, Room5b_Build());
	WorldData_SetRoom(worldData, 53, Room5c_Build());
	/* shiba choice */
	WorldData_SetRoom(worldData, 54, Room5d_Build());
	/* win level */
	WorldData_SetRoom(worldData, 55, Room5e_Build());
	/* search for ball and bamboo */
	WorldData_SetRoom(worldData, 56, Room5f_Build());
	WorldData_SetRoom(worldData, 57, Room5g_Build());
	WorldData_SetRoom(worldData, 58, Room5h_Build());
	WorldData_SetRoom(worldData, 59, Room5i_Build());
	WorldData_SetRoom(worldData, 60, Room5j_Build());
	/* please the shiba then win*/
	WorldData_SetRoom(worldData, 61, Room5k_Build());
	/* TODO ADVANCED: add additional advanced rooms */

	/* return the new object */
	return worldData;
}