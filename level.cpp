/*
 *  level.cpp
 *  S_01
 *
 *  Created by Magnus Selin on 12/27/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "level.h"

Level::Level(sf::RenderWindow * w){
	window = w;
	
	nenv = 5;
	env = new Object[nenv];
	for (int i = 0; i < nenv; i++) env[i].init(window);
	
	env[0].set_vert(Vec2f(0,	0	), 0);
	env[0].set_vert(Vec2f(0,	50	), 1);
	env[0].set_vert(Vec2f(1200,	50	), 2);
	env[0].set_vert(Vec2f(1200,	0	), 3);
	
	env[1].set_vert(Vec2f(200,	150	), 0);
	env[1].set_vert(Vec2f(200,	220	), 1);
	env[1].set_vert(Vec2f(250,	200	), 2);
	env[1].set_vert(Vec2f(250,	150	), 3);
	
	env[2].set_vert(Vec2f(350,	150	), 0);
	env[2].set_vert(Vec2f(350,	200	), 1);
	env[2].set_vert(Vec2f(400,	210	), 2);
	env[2].set_vert(Vec2f(400,	150	), 3);
	
	env[3].set_vert(Vec2f(500,	40	), 0);
	env[3].set_vert(Vec2f(500,	50	), 1);
	env[3].set_vert(Vec2f(600,	150	), 2);
	env[3].set_vert(Vec2f(600,	40	), 3);
	
	env[4].set_vert(Vec2f(700,	100	), 0);
	env[4].set_vert(Vec2f(700,	150	), 1);
	env[4].set_vert(Vec2f(800,	200	), 2);
	env[4].set_vert(Vec2f(800,	100	), 3);
}

void Level::draw(){
	for (int i = 0; i < nenv; i++) env[i].draw();
}