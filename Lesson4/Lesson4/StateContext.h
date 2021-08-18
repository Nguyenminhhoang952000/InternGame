#pragma once
#include"StateBase.h"


class StateContext {
private:
	StateBase* State;
public:
	StateContext();
	~StateContext();
	void setState(StateBase* sb);
	void close();
	void lock();
	void unlock();
	void open();


};
