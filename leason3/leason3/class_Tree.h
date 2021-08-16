#pragma once
#include "class_StaticObject.h"

class Tree : public StaticObject
{
public:
	Tree();
	Tree(std::string id, std::string name, Pos pos);
	~Tree();
};