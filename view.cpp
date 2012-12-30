/*
 *  view.cpp
 *  S_01
 *
 *  Created by Magnus Selin on 12/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "view.h"

void My_view::set(float x, float y){
	if (p[0] - x > 100){
		p[0] = x + 100;
	}
	if (p[0] - x < -100){
		p[0] = x -  100;
	}
	if (p[1] - y > 20){
		p[1] = y + 20;
	}
	if (p[1] - y < -40){
		p[1] = y   -40;
	}
	
	s[0] = 300;
	s[1] = 200;
	
	view.SetCenter(p[0], 640 - p[1]);
	view.SetHalfSize(s[0], s[1]);
	
	window->SetView(view);
}