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
#include "SnakeFunctions.h" /* ExitDoor_Build */
#include "WorkbenchFunctions.h" /* ExitDoor_Build */
#include "GameState.h" /* struct GameState, GameState_Create */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "BambooFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "EggFunctions.h" /* Egg_Build */
#include <stdio.h>
#include <ctype.h>/******************************************************************************
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
	room = Room_Create("You Awaken. As you groggily open your eyes, you realize that the surrounding room is a prison cell with a LOCKED bamboo door.\n You’re in some kind of dungeon. Your small cell contains a BRICK, some super interesting ground, and a green BALL. The cell door is locked.");
	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	
	/* TODO BASIC: Add room exit shortcut for "n" */

	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	ItemList_AddItem(Room_GetItemList(room), Ball_Build());
	ItemList_AddItem(Room_GetItemList(room), Brick_Build());

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
	room = Room_Create("After ascending the staircase, you are greeted with a large, open Dojo. Large stone statues of an Ox, Rat, Snake, and Dog are placed in the four corners of the room facing inwards.\n In the center of the Dojo stands a humanoid monkey, encased in red and gold plated armor, holding a wooden staff. he yells IS THY WORTHY OF MYYYY TREASURE?!\n IF THOU IS TRUUULY WORTHY, ONE MUST PROVETH THYSELF IN THE TOWER OF POWER *he points north* DEFEAT THE TOWERS CONTESTANTS AND YOU SHALL BE GRANTETH WITH THY TREAAASURE!! IF TREASURE IS NO INTEREST TO YOU, LEAVE *he points west*");

	/* TODO REQUIRED: Add an Exit "through the mirror" to Room 2 */
	/* TODO BASIC: Add exit shortcuts for "through mirror" and "mirror" */

	/* TODO REQUIRED: Add an Exit "south" back to Room 0 */
	/* TODO BASIC: Add room exit shortcut for "s" */
	Room_AddRoomExit(room, "north", 21);
	Room_AddRoomExit(room, "west", 11);
	/* TODO REQUIRED: Add a brick to the list of items in the room */

	/* return the new room */
	return room;
}

Room* Room1a_Build()
{
	Room* room = NULL;

	room = Room_Create("You walk over to the door and open it, as you walk through, the door hits you on the way out. The door had a knife. You perish. Press Alt-F4 to Exit");


	return room;
}
/* TODO REQUIRED: FLOOR 2, SPAM MORE ROOMS WITH 2 PREFIX TO HAVE EXPANDED */
Room* Room2_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("Ascending to the next floor, you find a door with a symbol of an ox on it. \nYou open the door, only to find yourself in a room that looks like the interior of the famous fast-food establishment, Burger Shogun. From behind the serving counter, a figure in golden, red and blue samurai armor leaps to face you. \n(Was he just waiting there the whole time?) \"Halt!\" he screams. \"I am, like, the defender of this floor, BURGER SHOGUN EMPLOYEE! You shall, like, die or whatever! But before you do, like, you gotta try our new softserve! \nOur new machine is made of neverbreakium, which is, like, completely invulnerable to all things except pandas, and like, I see you got one there, but like, please don't break it.\" The only obvious exit is a door to the EAST labeled \"SOFT SERVE\".");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "east", 21);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* return the new room */
	return room;
}
Room* Room2a_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("Past the door is a huge, totally empty room, save for the SOFT SERVE MACHINE in the back. The only exit is the door to the WEST, which leads back into the main room.");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "west", 20);
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
	room = Room_Create("As the door behind you seals shut, you enter a room with a tall podium. On top of the podium appears to be a RAT.\nThe RAT does not seem to be very menacing at first.\n\nThen you hear a ticking sound.\n\nUpon closer inspection, you realize there is BOMB strapped to the RAT. Judging by the timer on the BOMB, you have 15 minutes before the bomb goes off.\nTo the WEST is a small KITCHEN, not to be confused with the KITCHEN from the previous floor. That's a different KITCHEN.\nTo the EAST is some other unknown ROOM.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "north", 1);
	Room_AddRoomExit(room, "west", 31);
	Room_AddRoomExit(room, "east", 32);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

	/* return the new room */
	return room;
}
Room* Room3a_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	   include an initial room description */
	room = Room_Create("As you enter the kitchen, the scent of bread and all-purpose cleaning solution fills the air.\nYou see a COUNTER, some CABINETS, and a FRIDGE.\n");

	/* Exits
	   add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "east", 30);  /* 1 = the room index this exit connects to */

	/* Items

	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* Return the new room */
	return room;
}
Room* Room3b_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	   include an initial room description */
	room = Room_Create("As you approach the unknown room, the room glows brighter ever so slowly. You notice a WORKBENCH, a WALL OF TOOLS, and some DRAWERS.\nThis room must have been used to build a bomb.\n");

	/* Exits
	   add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "west", 30);  /* 1 = the room index this exit connects to */

	/* Items
	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	ItemList_AddItem(Room_GetItemList(room), Workbench_Build());

	/* Return the new room */
	return room;
}
/* TODO REQUIRED: FLOOR 4, SPAM MORE ROOMS WITH 4 PREFIX TO HAVE EXPANDED */
Room* Room4_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("entrance hall\n");

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
	room = Room_Create("map room\n");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* weaponry room*/
	Room_AddRoomExit(room, "south", 44);
	/* main hallway */
	Room_AddRoomExit(room, "west", 40);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Snake_Build());
	/* return the new room */
	return room;
}
Room* Room4b_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("suspicious wizards chamber\n");

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
	room = Room_Create("snake knight main chamber\n");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* main entrance */
	Room_AddRoomExit(room, "south", 40);
	/* top hallway */
	Room_AddRoomExit(room, "north", 47);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Snake_Build());
	/* return the new room */
	return room;
}
Room* Room4d_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("top hallway\n");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* armory*/
	Room_AddRoomExit(room, "east", 48);
	/* blacksmith */
	Room_AddRoomExit(room, "west", 49);
	/* snake knight main chamber*/
	Room_AddRoomExit(room, "south", 43);
	/* staircase up */
	Room_AddRoomExit(room, "north", 50);
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
	room = Room_Create("weaponry\n");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* map room */
	Room_AddRoomExit(room, "north", 41);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Snake_Build());
	/* return the new room */
	return room;
}
Room* Room4f_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("bathroom\n");

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
	room = Room_Create("janitors closet\n");

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
	room = Room_Create("armory\n");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* top hallway */
	Room_AddRoomExit(room, "west", 47);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Snake_Build());
	/* return the new room */
	return room;
}
Room* Room4i_Build()
{
	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("blacksmith\n");

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* top hallway */
	Room_AddRoomExit(room, "east", 47);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	ItemList_AddItem(Room_GetItemList(room), Snake_Build());
	/* return the new room */
	return room;
}
/* TODO REQUIRED: FLOOR 5, SPAM MORE ROOMS WITH 0 PREFIX TO HAVE EXPANDED */
Room* Room5_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Call room with respective description */
	room = Room_Create("After defeating the Python DOWNstairs you can now see sharp. Busta killa rolls into a sushi out of fear, what's he up to? There's a door to the east, maybe that...\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "east", 51); 
	/* return the new room */
	return room;
}
Room* Room5a_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Call room with respective description */
	room = Room_Create("You enter through the door, and see a --- shiba? You are instantly reminded of the lord and savior doge, and you hope that the majesty in the EAST is truly him. In the NORTH and SOUTH there's a wonderful view worth looking at.\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "north", 52); /*outlook top*/
	Room_AddRoomExit(room, "south", 53); /* outlook bottom */
	Room_AddRoomExit(room, "east", 54); /* approach the shiba */
	/* return the new room */
	return room;
}
Room* Room5b_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Call room with respective description */
	room = Room_Create("A wonderful outlook, with a sunny afternoon in Japan. A tune of Pink Guy is heard in the background. A truly wonderful experience. Might wanna CALL your friend and SHOW him the view.\n");
	/* Added exit to respective direction needed*/
	Room_AddRoomExit(room, "back", 51);
	/* Added items to make interactions possible*/
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	/* return the new room */
	return room;
}
Room* Room5c_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Call room with respective description */
	room = Room_Create("A wonderful outlook, with a sunny afternoon in Japan. A tune of Pink Guy is heard in the background.A truly wonderful experience.Might wanna CALL your friend and SHOW him the view.\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "back", 51);
	Room_AddRoomExit(room, "die", 65);
	/* Added items to make interactions possible */
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	/* return the new room */
	return room;
}
Room* Room5d_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Call room with respective description */
	room = Room_Create("You approach the Shiba, it is doge! You scream of happiness and you really want to pet him. Doge seems to crave for bamboo, as he loves the Improbable Whopper from downstairs, [which you destroyed].\n Do you TAKE the bamboo and GIVE it, or do you CALL busta killa, and SATISFY him instead?\n Busta killa always craves for bamboo, if you displease him he may displease you...\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "panda", 55);
	Room_AddRoomExit(room, "search", 56);
	/* Added items to make interactions possible */
	ItemList_AddItem(Room_GetItemList(room), Panda_Build());
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* return the new room */
	return room;
}
Room* Room5e_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/


	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Call room with respective description */
	room = Room_Create("You fly out, looking around the view you admire literally just the ocean, japan is an island, dont forget. If you're done flying, you can USE the EXIT to finish your flight.\n");
	/* Added items to make interactions possible */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	return room;
}
Room* Room5f_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;
	/* Call room with respective description */
	room = Room_Create("DOGE is clearly a ROUND BOYE now, but Busta killa is preventing the apocalypse! Don't forget to GO NORTH or SOUTH to look for the distraction!\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "north", 57);
	Room_AddRoomExit(room, "south", 58);
	Room_AddRoomExit(room, "die", 66);
	/* return the new room */
	return room;
}
Room* Room5g_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/


	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Call room with respective description */
	room = Room_Create("The upper end has some things lying around, maybe theres bamboo here? If not, just go WEST, EAST or SOUTH - or just ACROSS the hall?\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "west", 56);
	Room_AddRoomExit(room, "south", 58);
	Room_AddRoomExit(room, "across", 59);
	Room_AddRoomExit(room, "east", 62);
	Room_AddRoomExit(room, "die", 66);
	/* return the new room */
	return room;
}
Room* Room5h_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Call room with respective description */
	room = Room_Create("There appears to be some green stuff here, maybe something of use? If not, you can always go WEST, EAST, SOUTH or NORTH.\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "west", 56);
	Room_AddRoomExit(room, "north", 57);
	Room_AddRoomExit(room, "east", 59);
	Room_AddRoomExit(room, "south", 63);
	/* return the new room */
	return room;
}
Room* Room5i_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;
	/* Call room with respective description */
	room = Room_Create("This part mostly has a beautiful sunset, though you hear roars and pain from the back, is something here? If not, go in ANY CARDINAL direction, or just zoom ACROSS the hall!\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "across", 57);
	Room_AddRoomExit(room, "west", 58);
	Room_AddRoomExit(room, "east", 60);
	Room_AddRoomExit(room, "south", 63);
	Room_AddRoomExit(room, "north", 62);
	/* Added items to make interactions possible */
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* return the new room */
	return room;
}
Room* Room5j_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Call room with respective description */
	room = Room_Create("There is the Ball! A rotund sphere equal to a massive chonker. It is perfect for the shiba. TAKE it and GO BACK, but go NORTH or WEST if you didnt find two things!!! [please its the lore].\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "west", 59);
	Room_AddRoomExit(room, "north", 64);
	Room_AddRoomExit(room, "back", 61);
	/* Added items to make interactions possible */
	ItemList_AddItem(Room_GetItemList(room), Ball_Build());
	return room;
}
Room* Room5k_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;
	/* Call room with respective description */
	room = Room_Create("The Shiba and Panda are still fighting. Give them the items.\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "panda", 55);
	/* return the new room */
	return room;
}
Room* Room5l_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/


	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Call room with respective description */
	room = Room_Create("There's a cliff bar here - not a cliff, just a bar. Though the JUMP down seems possible :flushed:. There's still items to look for though, stuff can be WEST, SOUTH, EAST.\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "west", 57);
	Room_AddRoomExit(room, "jump", 65);
	Room_AddRoomExit(room, "east", 64);
	Room_AddRoomExit(room, "south", 59);
	/* return the new room */
	return room;
}
Room* Room5m_Build()
{	
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;
	/* Call room with respective description */
	room = Room_Create("You find a small platform, seeing some boxes with things in it. Maybe something is here? If not, then just go WEST, EAST, or JUMP?\n");
	/* Added exits to respective directions needed*/
	Room_AddRoomExit(room, "west", 58);
	Room_AddRoomExit(room, "east", 59);
	Room_AddRoomExit(room, "jump", 65);
	Room_AddRoomExit(room, "die", 66);
	/* return the new room */
	return room;
}
Room* Room5n_Build()
{
	/****************** THIS IS THE LAST EXIT ROOM ********************/


	/* TODO: Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* TODO REQUIRED: Call Room_Create with the Room 2 description:
	"This is room 2.  The room is isolated from the others, but you can see a crack in the east wall, just large enough to get through.\n" */
	room = Room_Create("The corner of the room. I don't think theres anything here. So what are you gonna do, eat pant? I recommend just going south or west.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	Room_AddRoomExit(room, "west", 62);
	Room_AddRoomExit(room, "south", 60);
	Room_AddRoomExit(room, "die", 66);
	/* return the new room */
	return room;
}
Room* Room5o_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;
	/* Call room with respective description */
	room = Room_Create("Wow you literally died what did you think this would do bruh like what is this what you wanted is this what you all wanted???????\n You're stuck here now so go alt+f4 this thing now. Why did you want to die in such a beautiful game? That is really not acceptable.\n");
	/* return the new room */
	return room;
}
Room* Room5p_Build()
{


	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;
	/* Call room with respective description */
	room = Room_Create("You call busta killa, he comes with ease and consumes you with pleasure. You are now part of him. Game over - use the exit.\n");
	
	/* add item and flag TODO: ADD FLAG to make exit possible*/
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
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
	int roomCount = 67; /* FIX THIS ONCE DONE */

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room0_Build());
	/* TODO REQUIRED: add rooms 1 and 2 to the world data */
	WorldData_SetRoom(worldData, 10, Room1_Build());
	WorldData_SetRoom(worldData, 11, Room1a_Build());
	WorldData_SetRoom(worldData, 20, Room2_Build());
	WorldData_SetRoom(worldData, 20, Room2_Build());
	WorldData_SetRoom(worldData, 21, Room2a_Build());
	
	WorldData_SetRoom(worldData, 30, Room3_Build());
	WorldData_SetRoom(worldData, 31, Room3a_Build());
	WorldData_SetRoom(worldData, 32, Room3b_Build());
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
	WorldData_SetRoom(worldData, 62, Room5l_Build());
	WorldData_SetRoom(worldData, 63, Room5m_Build());
	WorldData_SetRoom(worldData, 64, Room5n_Build());
	WorldData_SetRoom(worldData, 65, Room5o_Build());
	WorldData_SetRoom(worldData, 66, Room5p_Build());
	/* please the shiba then win*/
	WorldData_SetRoom(worldData, 61, Room5k_Build());
	/* TODO ADVANCED: add additional advanced rooms */

	/* return the new object */
	return worldData;
}