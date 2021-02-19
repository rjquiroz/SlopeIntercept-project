/*
-Author:		Ronald Quiroz
-Professor:		P. Allen
-Course:		COP 2001 summer2020
-File:			line.cpp
-Purpose:		Implementation file for a line class that represent a line object with Point one and two, float slope, y-intercept,
				length, and angle.
*/

#include "line.h"
#include "point.h"
#include<math.h>
#include<iomanip>
//-----------------------------------------------------------
//	constructors
//-----------------------------------------------------------
//default constructor
Line::Line()
{
	point1 = Point();
	point2 = Point();
	 slope = 0.0f;
	 y_intercept = 0.0f;
	 length = 0.0f;
	 angle = 0.0f;
}

//property constructor with 2 points
Line::Line(Point* pointA, Point* pointB)
{
	point1 = pointA;
	point2 = pointB;
}

//property constructor with 1 point and the slope.
Line::Line(Point* pointA, float SlopeValue)
{
	point1 = pointA;
	slope = SlopeValue;
}

//-----------------------------------------------------------
//	accessors
//-----------------------------------------------------------
Point* Line::getPoint1() { return &point1; }
Point* Line::getPoint2() { return &point2; }
float Line::getSlope() { return slope; }
void  Line::setSlope(float value) { slope = value; }
float Line::getYintercept() { return y_intercept; }
void  Line::setYintercept(float value) { y_intercept = value; }
float Line::getLength() { return length; }
void  Line::setLength(float value) { length = value; }
float Line::getAngle() { return angle; }
void  Line::setAngle(float value) { angle = value; }

//-----------------------------------------------------------
//	Member methods
//-----------------------------------------------------------

//return void. no parameters. sets the slope property of line;
void Line::slopeFrom2Point()
{
	slope = ( point2.getY() - point1.getY() ) / (point2.getX() - point1.getX() );
}

//return void. no parameters. sets the y_intercpt property.
void Line::slopeIntercept()
{
	y_intercept = point1.getY() - ( slope * point1.getX() );
	if (point2.isEmpty())
	{
		point2.setX(0);
		point2.setY(y_intercept);
	}
}

//returns void. no parameters. sets the length property.
void Line::lineLength()
{
	length = sqrt(pow( ( point2.getX() - point1.getX() ), 2) + pow( ( point2.getY() - point1.getY() ), 2) );
}

//returns void. no parameters. sets the angle property.
void Line::lineAngle()
{
	const double PI = 3.14159265;
	float alfa = std::atan2(point2.getY() - point1.getY(), point2.getX() - point1.getX() );
	angle = fmod(90 - double(alfa * 180.0 / PI), 360);
}

//returns void. no parameters. calculates and sets the slope, y-intercepty, length and angle of the line based of 2 points
//or 1 point and a slope.
void Line::calculate()
{
	if (point2.isEmpty() )
	{
		slopeIntercept();
		lineLength();
		lineAngle();
	}
	else
	{
		slopeFrom2Point();
		slopeIntercept();
		lineLength();
		lineAngle();
	}
	
}