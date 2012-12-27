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
	sf::Shape Rect = sf::Shape::Rectangle(p[0], 800 - p[1], p[0]+10, 800 - (p[1] + 10), sf::Color(255, 255, 255));
	window->Draw(Rect);
}

void Player::update(player_input input, Object obj){
	if(input.fwd) p[0] += 10;
	if(input.bwd) p[0] -= 10;
	if(input.jmp) {
		v = 10;
		in_air = true;
	}
	if(input.ddg);
	
	if(in_air) v -= 0.1;
	p[1] += v;
	
	this->chk_col(obj);
}

void Player::chk_col(Object obj){
	const Vec2f * ov = new Vec2f[4]; ov = obj.get_v();
	Vec2f np = p; np[1] += v;
	
	
	if(ov[3][1] > np[1]){
		p[1] = ov[3][1];
		v = 0;
		in_air = false;
	}
}