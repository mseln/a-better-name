/*
 *  level.h
 *  S_01
 *
 *  Created by Magnus Selin on 12/27/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <SFML/Graphics.hpp>
#include "objects.h"

class Level{
private:
	sf::RenderWindow * window;
	
	Object * env;
	int nenv;
public:
	Level(sf::RenderWindow * w);
	void draw();
	void update();
	Object * get_env(){ return env; }
};

#endif