/*
 *  session.cpp
 *  TCoCD
 *
 *  Created by Magnus Selin on 2012-07-01.
 *  Copyright 2012 NR. All rights reserved.
 *
 */

#include "session.h"

Session::Session(sf::RenderWindow * w, Event_Handler * e){
	window = w;
	event_h = e;
	player = new Player(window);
	obj = new Object(window);
}

void Session::update(){
	event_h->update();
	
	p_input.bwd = event_h->pollSp('l');
	p_input.fwd = event_h->pollSp('r');
	p_input.jmp = event_h->pollSp('u');
	p_input.ddg = event_h->pollSp('d');
	
	player->update(p_input, *obj);
	
}
void Session::draw(){
	player->draw();
	obj->draw();
}