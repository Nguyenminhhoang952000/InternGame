#pragma once
#include"StateBase.h"


class ClosedState:public StateBase {
public:
	void close(StateContext* text);
	void lock(StateContext* text);
	void unlock(StateContext* text);
	void open(StateContext* text);

};