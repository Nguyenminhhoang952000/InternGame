#include "class_StaticObject.h"
#include <iostream>

StaticObject::StaticObject() : BaseObject() 
{
}
StaticObject::StaticObject(std::string id, std::string name, Pos pos) : BaseObject(id, name, pos) 
{
}

StaticObject::~StaticObject() 
{
}

void StaticObject::move(int v_x, int v_y) {
	std::cout << this->getName() << " static - so not move" << std::endl;
}