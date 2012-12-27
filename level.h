/*
 *  level.h
 *  S_01
 *
 *  Created by Magnus Selin on 12/27/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <SFML/Graphics.hpp>

class Level{
private:
	sf::RenderWindow * window;
public:
	Level(sf::RenderWindow * w){ window = w; }
	void draw();
	void update();
};