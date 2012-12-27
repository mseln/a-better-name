/*
 *  objects.h
 *  S_01
 *
 *  Created by Magnus Selin on 12/27/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _OBJECTS_H_
#define _OBJECTS_H_

#include <SFML/Graphics.hpp>
#include "vec2f.h"

class Object{
private:
	sf::RenderWindow * window;
	
	Vec2f v[4];
	
public:
	Object(sf::RenderWindow * w){ 
		window = w;
		v[0][0] = 100;
		v[0][1] = 100;
		
		v[1][0] = 1100;
		v[1][1] = 100;
		
		v[2][0] = 1100;
		v[2][1] = 110;
		
		v[3][0] = 100;
		v[3][1] = 110;
	}
	void draw();
	Vec2f * get_v(){return v;};

};

#endif