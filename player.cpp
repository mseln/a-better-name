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
	sf::Shape Rect = sf::Shape::Circle(p[0], 760 - p[1], 2, sf::Color(v.magnitude() * 200, 0, 255 - v.magnitude() * 200));
	window->Draw(Rect);
}

void Player::update(player_input input, Object * obj){
	if(input.fwd) v[0] += 0.01;
	if(input.bwd) v[0] -= 0.01;
	
	if(input.ddg) v[1] -= 0.01;
	if(input.jmp) v[1] += 0.01;
	
	
	op = p;
	p += v;
	
	Vec2f chkp = Vec2f(p[0], p[1]-4);
	Vec2f pu = p; pu[1] -= 4;
	p = obj[0].col_det(p); pu = obj[0].col_det(pu);
	p = obj[1].col_det(p); pu = obj[1].col_det(pu);
	p = obj[2].col_det(p); pu = obj[2].col_det(pu);
	p = obj[3].col_det(p); pu = obj[3].col_det(pu);
	p = obj[4].col_det(p); pu = obj[4].col_det(pu);
	v = p - op;
	
	if( !(pu == chkp) ){ 
		in_air = false;
	}
	else in_air = true;
	
	
	
	
	v[1] *= 0.999;
	v[0] *= 0.999;
	
	view->set(p[0], p[1]);
}