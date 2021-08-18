#pragma once
#include"StateBase.h"
#include"ClosedState.h"


class OpennedState:public StateBase {
public:
	void close(StateContext* text);
	void lock(StateContext* text);
	void unlock(StateContext* text);
	void open(StateContext* text);

};