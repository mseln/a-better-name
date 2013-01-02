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
	Polygon.AddPoint(v[0][0], 760 - v[0][1], sf::Color(100, 100, 100));
	Polygon.AddPoint(v[1][0], 760 - v[1][1], sf::Color(100, 100, 100));
	Polygon.AddPoint(v[2][0], 760 - v[2][1], sf::Color(100, 100, 100));
	Polygon.AddPoint(v[3][0], 760 - v[3][1], sf::Color(100, 100, 100));
	
	window->Draw(Polygon);
}

Vec2f project(Vec2f a, Vec2f b, Vec2f x, sf::RenderWindow * w){
	Vec2f r, n;
	
	r = (a - b).normalize();
	n = Vec2f(r[1], -r[0]);
	
	float t = ( n[0] * (x[1] - a[1]) + n[1] * (- x[0] + a[0]) ) / (n[0] * r[1] - n[1] * r[0]);
	
	Vec2f p = t * r + a;
	Vec2f q = t * n + a;
	
	sf::Shape circle1 = sf::Shape::Circle(p[0], 760-p[1], 5, sf::Color::Green);
	// sf::Shape circle2 = sf::Shape::Circle(q[0], 760-q[1], 5, sf::Color::Red);
	
	sf::Shape line2 = sf::Shape::Line(p[0], 760-p[1], p[0] + r[0] * 50, 760-(p[1] + r[1] * 50), 2, sf::Color::Green);
	sf::Shape line1 = sf::Shape::Line(p[0], 760-p[1], p[0] + n[0] * -10000, 760-(p[1] + n[1] * -10000), 2, sf::Color::Red);
	
	w->Draw(circle1);
	// w->Draw(circle2);
	w->Draw(line1);
	w->Draw(line2);
	
	
	return p;
}

Vec2f Object::col_det(Vec2f np){
	Vec2f ret_val = np;
	
	// The direction vectors of the edges
	Vec2f r[4];
	r[0] = (v[0] - v[1]).normalize();
	r[1] = (v[1] - v[2]).normalize();
	r[2] = (v[2] - v[3]).normalize();
	r[3] = (v[3] - v[0]).normalize();
	
	project(v[0], v[1], np, window);
	project(v[1], v[2], np, window);
	project(v[2], v[3], np, window);
	project(v[3], v[0], np, window);
	
	// Line-Line intersection: n = n[i] + np, r = r[i] + v[i]
	float t[4];
	for(int i = 0; i < 4; i++)
		t[i] = ( n[i][0] * (v[i][1] - np[1]) + n[i][1] * (- v[i][0] + np[0]) ) / (n[i][1] * r[i][0] - n[i][0] * r[i][1]);
	
	// Projection vectors: (from edge to point)
	bool col = true; Vec2f oproj[4];
	for(int i = 0; i < 4; i++){
		oproj[i][0] = proj[i][0] = np[0] - (t[i] * r[i][0] + v[i][0]);
		oproj[i][1] = proj[i][1] = np[1] - (t[i] * r[i][1] + v[i][1]);
		oproj[i] = oproj[i].normalize();
	}
	
	// Shortest distance to edge projection:
	if((oproj[0] + n[0]) == Vec2f(0, 0) and 
	   (oproj[1] + n[1]) == Vec2f(0, 0) and 
	   (oproj[2] + n[2]) == Vec2f(0, 0) and 
	   (oproj[3] + n[3]) == Vec2f(0, 0) ){
		int shrtst = 100000000, index;
		for(int i = 0; i < 4; i++)
			if( shrtst > proj[i].magnitude()  ){
				shrtst = proj[i].magnitude();
				index = i;
			}
		ret_val = Vec2f(t[index] * r[index][0] + v[index][0], t[index] * r[index][1] + v[index][1]);
	}
	
	// If collision, return the nearest projection point on the edge from the point
	return ret_val;
}

