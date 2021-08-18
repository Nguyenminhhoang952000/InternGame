#include<iostream>
#include"ClosedState.h"
#include"LockedState.h"
#include"OpennedState.h"
using namespace std;

void ClosedState::close(StateContext* text) {
	cout << "Currently locked" << endl;
}
void ClosedState::lock(StateContext* text) {
	cout << "Door locked successfully" << endl;
	text->setState(new LockedState);
}
void ClosedState::unlock(StateContext* text) {
	cout << "Door unlocked" << endl;
}
void ClosedState::open(StateContext* text) {
	cout << "Open successfully";
	text->setState(new OpennedState);
}