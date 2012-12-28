/*
 *  player.h
 *  S_01
 *
 *  Created by Magnus Selin on 12/27/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics.hpp>
#include "datatypes.h"
#include "objects.h"
#include "vec2f.h"

class Player{
private:
	sf::RenderWindow * window;
	
	Vec2f p;
	double v;
	bool in_air;
	
	void chk_col(Object obj);
public:
	Player(sf::RenderWindow * w){ window = w; p[0] = 10; p[1] = 790; v = 0; in_air = true;}
	
	void draw();
	void update(player_input input, Object obj);
	Vec2f get_np(){return Vec2f(p[0], p[1] + v);}
};

#endif