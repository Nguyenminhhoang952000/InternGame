#include<iostream>
#include"OpennedState.h"
#include"StateContext.h"
using namespace std;

void OpennedState::close(StateContext* text) {
	cout << "Door closed successfully" << endl;
	text->setState(new ClosedState);
}
void OpennedState::lock(StateContext* text) {
	cout << "Currently open, cannot be locked." << endl;
}
void OpennedState::unlock(StateContext* text) {
	cout << "Currently open, can't unlock" << endl;
}
void OpennedState::open(StateContext* text) {
	cout << "Currently the door is open " << endl;
}

