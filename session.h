/*
 *  session.h
 *  TCoCD
 *
 *  Created by Magnus Selin on 2012-07-01.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#ifndef _SESSION_H_
#define _SESSION_H_

#include <SFML/Graphics.hpp>
#include <iostream>

#include "event_handler.h"
#include "game_states.h"
#include "player.h"
#include "objects.h"
#include "level.h"

class Session{
private:
	sf::RenderWindow * window;
	Event_Handler * event_h;
	
	Player * player;
	player_input p_input;
	
	Level * lvl;

public:
	Session(sf::RenderWindow * w, Event_Handler * e);
	
	void update();
	void draw();	
};



#endif