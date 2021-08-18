#include<iostream>
#include<vector>
#include "class_Car.h"
#include "class_Motorbike.h"
#include "class_Tree.h"
#include "class_House.h"

int main() {
	std::vector<BaseObject*> list;

	BaseObject* car = new Car("620i", "BMW", { 2,2 });
	BaseObject* motorbike = new Motorbike("D1001", "Ducati", { 2,4 });
	BaseObject* tree = new Tree("201", "Tree : jackfruit ", { 1,1 });
	BaseObject* house = new House("V112", "House : Vinhome ", { 2,2 });
	list.push_back(car);
	list.push_back(motorbike);
	list.push_back(tree);
	list.push_back(house);

	std::cout << "Name : " << std::endl;
	for (auto obj : list) {
		std::cout << obj->getName() << std::endl;
	}
	std::cout << "\nPosition -> move : " << std::endl;
	for (auto obj : list) {
		obj->printPos();
	}
	std::cout << "\nMoving : " << std::endl;
	for (auto obj : list) {
		obj->move(10, 10);
	}
	std::cout << "\nPosition : " << std::endl;
	for (auto obj : list) {
		obj->printPos();
		delete tree;
		delete house;
		delete motorbike;
		delete car;
		list.clear();
		return 0;
	}

}