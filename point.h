/*
-Author:		Ronald Quiroz
-Professor:		P. Allen
-Course:		COP 2001 summer2020
-File:			point.h.
-Purpose:		header file for a point class that represent a point object with x and y coordinates.
*/
#ifndef	POINT_H
#define	POINT_H

class Point
{
public:
	//-----------------------------------------------------------
	//	constructors
	//-----------------------------------------------------------
	Point();					//default 
	Point(float valueX, float valueY);	//property constructor
	Point(Point* point);		//copy constructor

	//-----------------------------------------------------------
	//	accessors
	//-----------------------------------------------------------
	float getX();
	void setX(float value);
	float getY();
	void setY(float value);

	//-----------------------------------------------------------
	//	member methods
	//-----------------------------------------------------------
	bool isEmpty();


private:
	float x;
	float y;
};






#endif