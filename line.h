/*
-Author:		Ronald Quiroz
-Professor:		P. Allen
-Course:		COP 2001 summer2020
-File:			line.h
-Purpose:		header file for a line class that represent a line object with Point one and two, float slope, y-intercept,
				length, and angle.
*/
#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line
{
public:
	//-----------------------------------------------------------
	//	constructors
	//-----------------------------------------------------------
	Line();										//default constructor.
	Line(Point* pointA, Point* pointB);			//property constructor with 2 points.
	Line(Point* pointA, float slopeValue);		//property constructor with point + slope.

	//-----------------------------------------------------------
	//	accessors
	//-----------------------------------------------------------
	Point* getPoint1();
	Point* getPoint2();
	float getSlope();
	void  setSlope(float value);
	float getYintercept();
	void  setYintercept(float value);
	float getLength();
	void  setLength(float value);
	float getAngle();
	void  setAngle(float value);

	//-----------------------------------------------------------
	//	member methods
	//-----------------------------------------------------------
	void slopeFrom2Point();
	void slopeIntercept();
	void lineLength();
	void lineAngle();
	void calculate();


private:
	Point point1;
	Point point2;
	float slope;
	float y_intercept;
	float length;
	float angle;


};










#endif
