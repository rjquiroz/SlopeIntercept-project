/*
-Author:		Ronald Quiroz
-Professor:		P. Allen
-Course:		COP 2001 summer2020
-File:			slopeinterceptmain.cpp: source file for final project Slope-Intercept line with class objects.
-Purpose:		Design a program that permits the user to convert either two-point form or point-slope form into slopeintercept
				form, calculate the line’s length, angle, and degrees and graph the line with class objects.
*/
#include<iostream>
#include "opengl.h"
#include<math.h>
#include<iomanip>

#include "line.h"
#include "point.h"

//Global constants.
const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 400;
const char* WINDOW_TITTLE = "Linear Graph \0";

//mode for the options menu
enum Mode
{
	Exit = 3,
	TWO_POINT = 1,
	POINT_SLOPE = 2
};


//prototypes of each function
int getProblem();

Line get2Point();

Line getPointSlope();

Point getPoint();

void displayLine(Line* line);

void display2Pt(Line* line);

void displayPointSlope(Line* line);

void displaySlopeIntercept(Line* line);

void drawLine(OpenGL &window, Line* line);

int main()
{
	int input;
	Line line = Line();
	bool exit = false;	
	//while that exits the program when hit '3'
	while (exit == false)
	{
			input = getProblem();			//calls the main options menu.
			switch (input)
			{
			case TWO_POINT:					//if selected 1 asked for two points 
			{
				line = get2Point();																//setting 2 point in line properties.
				line.calculate();																//setting line properties.
				displayLine(&line);																//printing results.
				display2Pt(&line);																//display the line in 2 point form.
				displaySlopeIntercept(&line);													//display line in slope-intercept form.
				OpenGL window = OpenGL(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITTLE);				//creating the window.
				drawLine(window, &line);															//drawing the lines.
			}
				break;
			case POINT_SLOPE:
			{
				line = getPointSlope();
				line.calculate();
				displayLine(&line);
				displayPointSlope(&line);
				displaySlopeIntercept(&line);
				OpenGL window = OpenGL(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITTLE);
				drawLine(window, &line);
			}
				break;
			default: Exit;
				exit = true;
				break;
			}
			//char pause;
			//std::cin >> pause;
			std::cout << "\033[2J\033[1;1H";
	}

	return 0;
}

//returns an int, takes no parameters. asks the user the main options menu.
int getProblem()
{
	int input;
	std::cout << "Select the form that you would like to convert to slope-intercept form: \n 1) Two-point form (you know the two points of the line) \n 2) Point-slope form (you know the line's slope and one point) \n 3) Exit\n";
	std::cin >> input;
	
	return input;
}

//asks for 2 points separated by space and store them in a line and returns the same line. takes no parameters.
Line get2Point()
{
	Point point1 = Point();
	Point point2 = Point();
	std::cout << " Enter the first point: \n";
	point1 = getPoint();
	std::cout << "\n Enter the second point: \n";
	point2 = getPoint();

	Line line = Line(&point1, &point2);

	return line;
}

//asks for 1 point and the slope. store them in the line and returns same line. takes no parameters.
Line getPointSlope()
{
	Point point1 = Point();
	float slope;
	char one, two;
	std::cout << "Enter a point for the line: \n";
	point1 = getPoint();

	std::cout << "Enter the slope of the line: ";
	std::cin >> slope;

	Line line = Line(&point1, slope);
	return line;
}

//ask for the two points and store them. returns a point. takes no parameters.
Point getPoint()
{
	//Point point1 = Point();
	float x, y;
	char one, two;
	std::cout << "Enter X and Y coordinates separated by spaces: ";
	std::cin >> x >> y;

	Point point1 = Point(x,y);
	return point1;
}

//prints the results of every single value of the line. do not return anything. takes a line as a parameter.
void displayLine(Line* line)
{
	Point point1 = Point(line->getPoint1());
	Point point2 = Point(line->getPoint2());
	std::cout << "Line: \n";
	std::cout << "		Point-1 (" << point1.getX()  << ", " << point1.getY() << ")\n";
	std::cout << "		Point-2 (" << point2.getX()  << ", " << point2.getY() << ")\n";
	std::cout << std:: setprecision(3) << "		Slope = " << line->getSlope() << "\n";
	std::cout << "		Y-Intercept = " << line->getYintercept() << "\n";
	std::cout << std:: setprecision(3) <<  "		Length = " << line->getLength() << "\n";
	std::cout << std:: setprecision(3) << "		Angle = " << line->getAngle() << "\n";
}

//prints the line as 2 points form. do not return anything.takes a line as a parameter.
void display2Pt(Line* line)
{
	Point point1 = Point(line->getPoint1());
	Point point2 = Point(line->getPoint2());
	std::cout << "Two-point form:\n";
	std::cout << "     (" << point2.getY() << " - " << point1.getY() << ")\n";
	std::cout << "m =  --------------\n";
	std::cout << "     (" << point2.getX() << " - " << point1.getX() << ")\n";
}

//prints the line in a point-slope form. do not return anything. takes a line as a parameter.
void displayPointSlope(Line* line)
{
	Point point1 = Point(line->getPoint1());
	Point point2 = Point(line->getPoint2());
	std::cout << "Point-slope form:\n";
	std::cout << "		y - " << point1.getY() << " = " << line->getSlope() << "(x - " << point1.getX() << ")\n";

}

//prints the line as slope-intercept form. do not return anything. takes a line as a parameter.
void displaySlopeIntercept(Line* line)
{
	std::cout << "Slope-intercept form:\n";
	std::cout << "		y = " << line->getSlope() << "x + ( " << line->getYintercept() << ")\n\n";

}

//draws the line in the window. do not return anything. takes a window and a line as a parameter.
void drawLine(OpenGL& window, Line* line)
{
	Point point1 = Point(line->getPoint1());
	Point point2 = Point(line->getPoint2());
	unsigned char blue[4]{ 0, 255, 0, 0 };
	unsigned char red[4]{ 0, 0, 0, 255 };
	float xsize[] = {WINDOW_HEIGHT,1};
	float xposition[] = {0,WINDOW_HEIGHT/2};
	float ysize[] = {1,WINDOW_HEIGHT};
	float yposition[] = {WINDOW_WIDTH/2,0};
	float lposition[] = { WINDOW_WIDTH / 2 + point1.getX(), WINDOW_HEIGHT / 2 - point1.getY() };
	float lsize[] = {2, line->getLength()};
	while (!window.isClosing())
	{
		window.clearWindow(); // background color
		window.DrawSprite(xposition, xsize,blue, 180-180 ,false); // x-axis
		window.DrawSprite(yposition, ysize, blue, (0) , false); // y-axis
		window.DrawSprite(lposition, lsize, red, line->getAngle() -180, false); // line
		window.paintWindow();
		window.pollEvents();
	}
}
