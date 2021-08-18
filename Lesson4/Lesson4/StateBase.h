#pragma once
using namespace std;
class StateContext;

class StateBase {
public:
	virtual void close(StateContext* text) = 0;
	virtual void lock(StateContext* text) = 0;
	virtual void unlock(StateContext* text) = 0;
	virtual void open(StateContext* text) = 0;

};