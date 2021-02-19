/*
-Author:		Ronald Quiroz
-Professor:		P. Allen
-Course:		COP 2001 summer2020
-File:			point.cpp.
-Purpose:		Implementation file for a point class that represent a point object with x and y coordinates.
*/
#include "point.h"
	
//-----------------------------------------------------------
//	constructors
//-----------------------------------------------------------
//default constructor
Point::Point()
{
	x = 0.0f;
	y = 0.0f;
}

//property constructor
Point::Point(float valueX, float valueY)
{
	x = valueX;
	y = valueY;
}

//copy constructor
Point::Point(Point* point)
{
	x = point->x;
	y = point->y;
}


//-----------------------------------------------------------
//	accessors(getters and setters)
//-----------------------------------------------------------
float  Point::getX() { return x; }
void   Point::setX(float value) { x = value; }
float  Point::getY() { return y; }
void   Point::setY(float value) { y = value; }

//-----------------------------------------------------------
//	member methods
//-----------------------------------------------------------

//is Empty method; return a bool true if both x and y are 0. 
//takes a point as parameter.
bool Point::isEmpty()
{
	bool empty = true;
	if ( !(x||y)==0)
		empty = false;

	return empty;
}