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
#include <iostream>
#include "datatypes.h"
#include "objects.h"
#include "view.h"
#include "vec2f.h"

class Player{
private:
	sf::RenderWindow * window;
	
	Vec2f p, op;
	Vec2f v;
	bool in_air;
	
	My_view * view;
	
	sf::Sprite sprite;
	sf::Image image;
	
	void chk_col(Object obj);
public:
	Player(sf::RenderWindow * w){ 
		window = w; 
		p[0] = 75; 
		p[1] = 200;
		op = p;
		v[0] = v[1] = 0;
		in_air = true;
		
		view = new My_view(window);
		
		
		if (!image.LoadFromFile("blooby.png"))
			std::cerr << "Couldn't load sprite!\n";
		else{ 
			sprite.SetImage(image);
			std::cerr << "Loading image complete...!\n";
		}
	}
	
	void draw();
	void update(player_input input, Object * obj);
};

#endif