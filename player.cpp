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
	sprite.SetImage(image);
	
	
	sprite.SetPosition(p[0], 735 - p[1]);
	window->Draw(sprite);
	
}

void Player::update(player_input input, Object * obj){
	if(input.fwd) v[0] += 0.01;
	if(input.bwd) v[0] -= 0.01;
	
	if(input.ddg) v[1] -= 0.1;
	if(input.jmp) v[1] += 0.1;
	
	
	
	op = p;
	p += v;
	
	p = obj[0].col_det(p);
	p = obj[1].col_det(p);
	p = obj[2].col_det(p);
	p = obj[3].col_det(p);
	p = obj[4].col_det(p);
	
	v = p - op;
	
	v[1] -= 0.02;
	v[0] *= 0.999;
	
	
	
	
	
	view->set(p[0], p[1]);
}