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

#include <iostream>
#include <SFML/Graphics.hpp>
#include "vec2f.h"

class Object{
private:
	sf::RenderWindow * window;
	
	Vec2f v[4];
	Vec2f n[4];
	Vec2f proj[4];
	
public:
	Object(sf::RenderWindow * w);
	void draw();
	Vec2f * get_v(){return v;}
	Vec2f * get_n(){return n;}
	Vec2f col_det(Vec2f np, Vec2f op);
};

#endif