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
	sf::Shape Rect = sf::Shape::Circle(p[0], 800 - p[1], 5, sf::Color(0, 255, 0));
	window->Draw(Rect);
}

void Player::update(player_input input, Object obj){
	if(input.fwd) p[0] += 10;
	if(input.bwd) p[0] -= 10;
	if(input.jmp) p[1] += 10;
	if(input.ddg) p[1] -= 10;
	
	v -= 0.01;
	p[1] += v;
	
	Vec2f chk_if_np_ok = obj.col_det(p);
	if(!(Vec2f(10000, 10000) == chk_if_np_ok))
		p = chk_if_np_ok;
	
	this->chk_col(obj);
}

void Player::chk_col(Object obj){
	const Vec2f * ov = new Vec2f[4]; ov = obj.get_v();
}