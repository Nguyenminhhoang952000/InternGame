#include"StateContext.h"
#include"OpennedState.h"

//Default door open

StateContext::StateContext():State{ new OpennedState() }{}

StateContext::~StateContext() {
	delete State;

}
void StateContext::setState(StateBase* sb) {
	State = sb;
}
void StateContext::close() {
	State -> close(this);
}
void StateContext::lock() {
	State -> lock(this);
}
void StateContext::unlock() {
	State -> unlock(this);
}
void StateContext::open() {
	State -> open(this); 
}