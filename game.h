/*
 *  game.h
 *  iwanto3d
 *
 *  Created by Magnus Selin on 2012-06-25.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>

#include "menu.h"
#include "event_handler.h"
#include "game_states.h"
#include "session.h"

class Game{
private:
	Menu menu;
	InGame_Menu ingame_menu;
	
	Event_Handler * event_h;
	Game_States * game_state;
	Session * session;
	
	sf::RenderWindow * window;
	
	void update();
	void gameloop();
	void menuloop();
	void ingame_menuloop();
	
	// Session * sess;
	bool pause_if_in_menu;
	int ctr;
public:
	
	Game();
	void run();
	
};

#endif
