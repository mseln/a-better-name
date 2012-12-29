/*
 *  player.cpp
 *  S_01
 *
 *  Created by Magnus Selin on 12/27/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "player.h"

void Player::draw(){
	sf::Shape Rect = sf::Shape::Circle(p[0], 800 - p[1], 1, sf::Color(0, 255, 0));
	window->Draw(Rect);
}

void Player::update(player_input input, Object obj){
	if(input.fwd) p[0] += 1;
	if(input.bwd) p[0] -= 1;
	if(input.jmp) p[1] += 1;
	if(input.ddg) p[1] -= 1;
	
	p = obj.col_det(p);
}