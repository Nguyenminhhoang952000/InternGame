#include<iostream>
#include"LockedState.h"
#include"OpennedState.h"

using namespace std;

void LockedState::close(StateContext* text) {
	cout << "Currently locked, can not close" << endl;

}
void LockedState::lock(StateContext* text) {
	cout << "Currently locked, can not lock" << endl;

}
void LockedState::unlock(StateContext* text) {
	cout << "Unlocked successfully" << endl;
	text->setState(new OpennedState);

}
void LockedState::open(StateContext* text) {
	cout << "Currently locked, can not open" << endl;

}