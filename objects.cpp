/*
 *  objects.cpp
 *  S_01
 *
 *  Created by Magnus Selin on 12/27/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "objects.h"

Object::Object(sf::RenderWindow * w){
	window = w;
	
	n[0][0] =   v[0][1] - v[1][1];
	n[0][1] = -(v[0][0] - v[1][0]);
	n[0] = n[0].normalize();
	
	n[1][0] =   v[1][1] - v[2][1];
	n[1][1] = -(v[1][0] - v[2][0]);
	n[1] = n[1].normalize();
	
	n[2][0] =   v[2][1] - v[3][1];
	n[2][1] = -(v[2][0] - v[3][0]);
	n[2] = n[2].normalize();
	
	n[3][0] =   v[3][1] - v[0][1];
	n[3][1] = -(v[3][0] - v[0][0]);
	n[3] = n[3].normalize();
}

void Object::update_chg(){
	n[0][0] =   v[0][1] - v[1][1];
	n[0][1] = -(v[0][0] - v[1][0]);
	n[0] = n[0].normalize();
	
	n[1][0] =   v[1][1] - v[2][1];
	n[1][1] = -(v[1][0] - v[2][0]);
	n[1] = n[1].normalize();
	
	n[2][0] =   v[2][1] - v[3][1];
	n[2][1] = -(v[2][0] - v[3][0]);
	n[2] = n[2].normalize();
	
	n[3][0] =   v[3][1] - v[0][1];
	n[3][1] = -(v[3][0] - v[0][0]);
	n[3] = n[3].normalize();
}

void Object::draw(){
	sf::Shape Polygon;
	Polygon.AddPoint(v[0][0], 760 - v[0][1], sf::Color(255, 0, 0));
	Polygon.AddPoint(v[1][0], 760 - v[1][1], sf::Color(255, 0, 0));
	Polygon.AddPoint(v[2][0], 760 - v[2][1], sf::Color(255, 0, 0));
	Polygon.AddPoint(v[3][0], 760 - v[3][1], sf::Color(255, 0, 0));
	
	window->Draw(Polygon);
}

Vec2f Object::col_det(Vec2f np){
	Vec2f ret_val = np;
	
	// The direction vectors of the edges
	Vec2f r[4];
	r[0] = (v[0] - v[1]).normalize();
	r[1] = (v[1] - v[2]).normalize();
	r[2] = (v[2] - v[3]).normalize();
	r[3] = (v[3] - v[0]).normalize();
	
	
	// Line-Line intersection: n = n[i] + np, r = r[i] + v[i]
	float t[4];
	for(int i = 0; i < 4; i++)
		t[i] = ( n[i][0] * (v[i][1] - np[1]) + n[i][1] * (- v[i][0] + np[0]) ) / (n[i][1] * r[i][0] - n[i][0] * r[i][1]);
	
	// Projection vectors: (from edge to point)
	bool col = true; Vec2f oproj[4];
	for(int i = 0; i < 4; i++){
		proj[i][0] = np[0] - (t[i] * r[i][0] + v[i][0]);
		proj[i][1] = np[1] - (t[i] * r[i][1] + v[i][1]);
	}
	
	// Shortest distance to edge projection:
	if((proj[0] + n[0]).magnitude() < proj[0].magnitude() and 
	   (proj[1] + n[1]).magnitude() < proj[1].magnitude() and 
	   (proj[2] + n[2]).magnitude() < proj[2].magnitude() and 
	   (proj[3] + n[3]).magnitude() < proj[3].magnitude()){
		int shrtst = 100000000, index;
		for(int i = 0; i < 4; i++)
			if( shrtst > proj[i].magnitude()  ){
				shrtst = proj[i].magnitude();
				index = i;
			}
		ret_val = Vec2f(t[index] * r[index][0] + v[index][0], t[index] * r[index][1] + v[index][1]);
	}
	
	// If collision, return the nearest projection point on a edge from the point
	return ret_val;
}