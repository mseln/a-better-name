/*
 *  view.h
 *  S_01
 *
 *  Created by Magnus Selin on 12/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _MY_VIEW_
#define _MY_VIEW_

#include <SFML/Graphics.hpp>
#include "vec2f.h"

class My_view{
private:
	
	sf::RenderWindow * window;
	
	Vec2f p;
	Vec2f s;
	sf::View view;
	
public:
	My_view(sf::RenderWindow * w){window = w;};
	void set(float x, float y);
};

#endif