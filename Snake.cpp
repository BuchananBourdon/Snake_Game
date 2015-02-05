#include <SDL/SDL.h>
#include "Snake.h"
#include "MapView.h"
#include "Food.h"
#include <iostream>
using namespace std;
Snake::Snake(int _x, int _y, MapView& map) : unspawnedSections(0)
{
	Section * newJoint = new Section(_x,_y,1,1,0); 	//head section, previous section is null
	cout<<"in snake constructor"<<endl;

	headSection = newJoint;

	Section * newJoint2 = new Section(_x-1,_y,1,1,newJoint);
	Section * newJoint3 = new Section(_x-2,_y,1,1,newJoint2);
	tailSection = newJoint3; //tail section

	map.setOccupancy(_x,_y,true);
	map.setOccupancy(_x-1,_y,true);
	map.setOccupancy(_x-2,_y,true);
}

Snake::~Snake()
{
	Section * currentSection = tailSection;
	while(currentSection)
	{
		Section * nextSection = currentSection->getPreviousSection();
		delete currentSection;
		currentSection = nextSection;
	}
}

int Snake::getX()
{
	return (headSection->getX());
}

int Snake::getY()
{
	return (headSection->getY());
}

bool Snake::move(MapView& map)
{
	Section * currentSection = tailSection;
	int _x = tailSection->getX();
	int _y = tailSection->getY();
	while(currentSection)
	{
		currentSection->update();
		currentSection = currentSection->getPreviousSection();
	}
	
	if(!isWithinBounds(map) || isIntersection(map)) return false;
	map.setOccupancy(headSection->getX(), headSection->getY(), true); //head will move, so update map

	if(unspawnedSections>0)
	{
		 addSection(_x,_y); 	//if we still need to spawn, then add a section
		unspawnedSections--;
	}
	else map.setOccupancy(_x,_y,false);		//if we dont, then no new section is added

	return true;
}							//  and we need to update the map

void Snake::setDirection(Section::direction newDir)
{
	headSection->setDirection(newDir);
}

bool Snake::eatFood(Food& food)
{
	if(food.getX() == headSection->getX() && food.getY() == headSection->getY())
	{	
		unspawnedSections+=3;
		return true;
	}
	else return false;
}

void Snake::addSection(int _x, int _y)
{
	Section * newJoint = new Section(_x, _y,1,1,tailSection);
	tailSection = newJoint;
}


bool Snake::isWithinBounds(MapView & map)
{
	int headX = headSection->getX();
	int headY = headSection->getY();

	cout<<"headY is: "<<headY<<endl;
	if(headX<1 || headX>map.getHorizontalTiles()-2 || headY<1 || headY>map.getVerticalTiles()-2)
	{
		cout<<"returning false"<<endl;
		return false;
	}
	else return true;
}

bool Snake::isIntersection(MapView& map)
{
	if(map.isOccupied(headSection->getX(),headSection->getY())) return true;
	else return false;
}


void Snake::draw(MapView& map)
{
	Section * currentJoint = tailSection;
	while(currentJoint)
	{
		currentJoint->draw(map);
		currentJoint=currentJoint->getPreviousSection();
	}

}
