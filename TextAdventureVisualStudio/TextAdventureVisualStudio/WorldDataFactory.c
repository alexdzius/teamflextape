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
	room = Room_Create("You Awaken. As you groggily open your eyes, you realize that the surrounding room is a prison cell with a locked bamboo door.The lack of natural light combined with the water leaking from the rooms stone crevices show that you’re in some kind of dungeon.");
	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	Room_AddRoomExit(room, "North", 10);
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
	room = Room_Create("Ascending to the next floor, you find a door with a symbol of an ox on it. \nYou open the door, only to find yourself in a room that looks like the interior of the famous fast-food establishment, Burger Shogun. From behind the serving counter, a figure in golden, red and blue samurai armor leaps to face you. (Was he just waiting there the whole time?) \n\"Halt!\" he screams. \"I am, like, the defender of this floor, BURGER SHOGUN EMPLOYEE! You shall, like, die or whatever! But before you do, like, you gotta try our new softserve! \nOur new machine is made of neverbreakium, which is, like, completely invulnerable to all things except pandas, and like, I see you got one there, but like, please don't break it.\" The only obvious exit is a door to the EAST labeled \"SOFT SERVE\".");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "east", 21);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

	/* TODO REQUIRED: Add a gold piece to the list of items in the room */

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
	Room_AddRoomExit(room, "west", 21);
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
	room = Room_Create("As the door behind you seals shut, you enter a room with a tall podium. On top of the podium appears to be a RAT.\nThe RAT does not seem to be very menacing at first.\n\nThen you hear a ticking sound.\n\nUpon closer inspection, you realize there is BOMB strapped to the RAT.Judging by the timer on the BOMB, you have 15 minutes before the bomb goes off.\nTo the WEST is a small KITCHEN, not to be confused with the KITCHEN from the previous floor. That's a different KITCHEN.\nTo the EAST is some other unknown ROOM.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "north", 1);
	Room_AddRoomExit(room, "west", 31);
	Room_AddRoomExit(room, "east", 1);
	/* TODO BASIC: Add exit shortcuts for "e" and "crack" */

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
	/* Return the new room */
	return room;
}
Room* Room3b_Build()
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

	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
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
	room = Room_Create("The Shiba has mutated into a superior being, but the Panda fights him off - do not forget to LOOK for bamboo and the Ball. You could look SOUTH or NORTH\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "north", 57);
	Room_AddRoomExit(room, "south", 58);
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
	room = Room_Create("Theres a lot of different things here, maybe somewhere there's bamboo hidden? If not, just go WEST, EAST or SOUTH.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	Room_AddRoomExit(room, "west", 56);
	Room_AddRoomExit(room, "south", 58);
	Room_AddRoomExit(room, "east", 59);
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
	room = Room_Create("There appears to be some green stuff here, maybe something of use? If not, you can always go WEST, EAST or NORTH.\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	Room_AddRoomExit(room, "west", 56);
	Room_AddRoomExit(room, "north", 57);
	Room_AddRoomExit(room, "east", 59);
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
	room = Room_Create("This part mostly has a beautiful sunset, though you hear roars and pain from the back, is something here? If not, go WEST, SOUTH or EAST\n");
	/* TODO REQUIRED: Add an Exit "east" to Room 0 */
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	/* TODO REQUIRED: Add a gold piece to the list of items in the room */
	Room_AddRoomExit(room, "west", 57);
	Room_AddRoomExit(room, "south", 58);
	Room_AddRoomExit(room, "east", 60);
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
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	ItemList_AddItem(Room_GetItemList(room), Ball_Build());
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
	ItemList_AddItem(Room_GetItemList(room), Bamboo_Build());
	ItemList_AddItem(Room_GetItemList(room), Ball_Build());
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
	WorldData_SetRoom(worldData, 40, Room4_Build());
	/* last floor levels*/
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