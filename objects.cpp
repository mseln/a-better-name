/*
 *  objects.cpp
 *  S_01
 *
 *  Created by Magnus Selin on 12/27/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "objects.h"

void Object::draw(){
	sf::Shape Polygon;
	Polygon.AddPoint(v[0][0], 800 - v[0][1], sf::Color(255, 255, 255));
	Polygon.AddPoint(v[1][0], 800 - v[1][1], sf::Color(255, 255, 255));
	Polygon.AddPoint(v[2][0], 800 - v[2][1], sf::Color(255, 255, 255));
	Polygon.AddPoint(v[3][0], 800 - v[3][1], sf::Color(255, 255, 255));
	
	window->Draw(Polygon);
}