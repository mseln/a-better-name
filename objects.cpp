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
	v[0][0] = 300;
	v[0][1] = 300;
	
	v[1][0] = 400;
	v[1][1] = 700;
	
	v[2][0] = 500;
	v[2][1] = 200;
	
	v[3][0] = 400;
	v[3][1] = 100;
	
	
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
	Polygon.AddPoint(v[0][0], 800 - v[0][1], sf::Color(255, 255, 255));
	Polygon.AddPoint(v[1][0], 800 - v[1][1], sf::Color(255, 255, 255));
	Polygon.AddPoint(v[2][0], 800 - v[2][1], sf::Color(255, 255, 255));
	Polygon.AddPoint(v[3][0], 800 - v[3][1], sf::Color(255, 255, 255));
	
	
	
	
	//sf::Shape Line0   = sf::Shape::Line(	v[0][0] + (v[0][0] - v[1][0]) / 2,					v[0][1] + (v[0][1] - v[1][1]) / 2,
	//										v[0][0] + (v[0][0] - v[1][0]) / 2 + n[3][0] * 400,	v[0][1] + (v[0][1] - v[1][1]) / 2 + n[3][1] * 100,
	//										2, sf::Color(255, 0, 0));

	sf::Shape Line0	  = sf::Shape::Line(200, 200, 400, 400, 2, sf::Color(255, 0, 0));
	
	//std::cout << v[0] << '\t' << v[1] << '\t' << v[2] << '\t' << v[3] << '\n';
	//std::cout	<< v[0][0] + (v[1][0] - v[0][0]) / 2					<< ' ' << (v[0][1] + (v[1][1] - v[0][1]) / 2)					<< ' '
	//			<< v[0][0] + (v[1][0] - v[0][0]) / 2 + n[0][0] * 100	<< ' ' << (v[0][1] + (v[1][1] - v[0][1]) / 2 + n[0][1] * 100)	<< '\n';
	//std::cout	<< v[1][0] + (v[2][0] - v[1][0]) / 2					<< ' ' << (v[1][1] + (v[2][1] - v[1][1]) / 2)					<< ' '
	//			<< v[1][0] + (v[2][0] - v[1][0]) / 2 + n[1][0] * 100	<< ' ' << (v[1][1] + (v[2][1] - v[1][1]) / 2 + n[1][1] * 100)	<< '\n';
	//std::cout	<< v[2][0] + (v[3][0] - v[2][0]) / 2					<< ' ' << (v[2][1] + (v[3][1] - v[2][1]) / 2)					<< ' '
	//			<< v[2][0] + (v[3][0] - v[2][0]) / 2 + n[2][0] * 100	<< ' ' << (v[2][1] + (v[3][1] - v[2][1]) / 2 + n[2][1] * 100)	<< '\n';
	//std::cout	<< v[3][0] + (v[0][0] - v[3][0]) / 2					<< ' ' << (v[3][1] + (v[0][1] - v[3][1]) / 2)					<< ' '
	//			<< v[3][0] + (v[0][0] - v[3][0]) / 2 + n[3][0] * 100	<< ' ' << (v[3][1] + (v[0][1] - v[3][1]) / 2 + n[3][1] * 100)	<< '\n';

	
	sf::Shape Line1   = sf::Shape::Line(v[0][0] + (v[1][0] - v[0][0]) / 2,					800 - (v[0][1] + (v[1][1] - v[0][1]) / 2),
									    v[0][0] + (v[1][0] - v[0][0]) / 2 + n[0][0] * 100,	800 - (v[0][1] + (v[1][1] - v[0][1]) / 2 + n[0][1] * 100),
										4, sf::Color(255, 0, 0));
	
	sf::Shape Line2   = sf::Shape::Line(v[1][0] + (v[2][0] - v[1][0]) / 2,					800 - (v[1][1] + (v[2][1] - v[1][1]) / 2),
									    v[1][0] + (v[2][0] - v[1][0]) / 2 + n[1][0] * 100,	800 - (v[1][1] + (v[2][1] - v[1][1]) / 2 + n[1][1] * 100),
										4, sf::Color(255, 0, 0));
	
	sf::Shape Line3   = sf::Shape::Line(v[2][0] + (v[3][0] - v[2][0]) / 2,					800 - (v[2][1] + (v[3][1] - v[2][1]) / 2),
									    v[2][0] + (v[3][0] - v[2][0]) / 2 + n[2][0] * 100,	800 - (v[2][1] + (v[3][1] - v[2][1]) / 2 + n[2][1] * 100),
										4, sf::Color(255, 0, 0));
	
	sf::Shape Line4   = sf::Shape::Line(v[3][0] + (v[0][0] - v[3][0]) / 2,					800 - (v[3][1] + (v[0][1] - v[3][1]) / 2),
									    v[3][0] + (v[0][0] - v[3][0]) / 2 + n[3][0] * 100,	800 - (v[3][1] + (v[0][1] - v[3][1]) / 2 + n[3][1] * 100),
										4, sf::Color(255, 0, 0));
	
	sf::Shape Line5   = sf::Shape::Line(v[0][0] + (v[1][0] - v[0][0]) / 2,					800 - (v[0][1] + (v[1][1] - v[0][1]) / 2),
									    v[0][0] + (v[1][0] - v[0][0]) / 2 + proj[0][0],		800 - (v[0][1] + (v[1][1] - v[0][1]) / 2 + proj[0][1]),
										4, sf::Color(0, 0, 255));
	
	sf::Shape Line6   = sf::Shape::Line(v[1][0] + (v[2][0] - v[1][0]) / 2,					800 - (v[1][1] + (v[2][1] - v[1][1]) / 2),
									    v[1][0] + (v[2][0] - v[1][0]) / 2 + proj[1][0],		800 - (v[1][1] + (v[2][1] - v[1][1]) / 2 + proj[1][1]),
										4, sf::Color(0, 0, 255));
	
	sf::Shape Line7   = sf::Shape::Line(v[2][0] + (v[3][0] - v[2][0]) / 2,					800 - (v[2][1] + (v[3][1] - v[2][1]) / 2),
									    v[2][0] + (v[3][0] - v[2][0]) / 2 + proj[2][0],		800 - (v[2][1] + (v[3][1] - v[2][1]) / 2 + proj[2][1]),
										4, sf::Color(0, 0, 255));
	
	sf::Shape Line8   = sf::Shape::Line(v[3][0] + (v[0][0] - v[3][0]) / 2,					800 - (v[3][1] + (v[0][1] - v[3][1]) / 2),
									    v[3][0] + (v[0][0] - v[3][0]) / 2 + proj[3][0],		800 - (v[3][1] + (v[0][1] - v[3][1]) / 2 + proj[3][1]),
										4, sf::Color(0, 0, 255));
	
	
	window->Draw(Polygon);
	window->Draw(Line1);
	window->Draw(Line2);
	window->Draw(Line3);
	window->Draw(Line4);
	window->Draw(Line5);
	window->Draw(Line6);
	window->Draw(Line7);
	window->Draw(Line8);
}

Vec2f Object::col_det(Vec2f np, Vec2f op){
	Vec2f r[4];
	r[0] = (v[0] - v[1]).normalize();
	r[1] = (v[1] - v[2]).normalize();
	r[2] = (v[2] - v[3]).normalize();
	r[3] = (v[3] - v[0]).normalize();
	
	float t[4];
	// Line-Line intersection: n = n[i] + np, r = r[i] + v[i]
	for(int i = 0; i < 4; i++)
		t[i] = ( n[i][0] * (v[i][1] - np[1]) + n[i][1] * (- v[i][0] + np[0]) ) / (n[i][1] * r[i][0] - n[i][0] * r[i][1]);
	
	//for(int i = 0; i < 4; i++){
	//	sf::Shape Circle = sf::Shape::Circle(t[i] * r[i][0] + v[i][0], 800 - (t[i] * r[i][1] + v[i][1]), 5, sf::Color(0, 0, 255));
	//	window->Draw(Circle);
	//}
	
	
	bool col = true; Vec2f oproj[4];
	for(int i = 0; i < 4; i++){
		proj[i][0] = np[0] - (t[i] * r[i][0] + v[i][0]);
		proj[i][1] = np[1] - (t[i] * r[i][1] + v[i][1]);
		
		// oproj[i][0] = op[0] - (t[i] * r[i][0] + v[i][0]);
		// oproj[i][1] = op[1] - (t[i] * r[i][1] + v[i][1]);
		
		// proj[i] = proj[i].normalize();
		//if(!(proj[i] == -n[i])) col = false;
	}
	
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
		//sf::Shape Circle = sf::Shape::Circle(10, 10, 3, sf::Color(255, 255, 0));
		//window->Draw(Circle);
		return Vec2f(t[index] * r[index][0] + v[index][0], t[index] * r[index][1] + v[index][1]);
	}
		
	//for(int i = 0; i < 4; i++) std::cout << proj[i] << '\t' << n[i] << '\n';
	//std::cout << '\n';
	
	return Vec2f(10000, 10000);
}