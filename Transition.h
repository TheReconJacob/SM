#pragma once
#include "stdafx.h"

class State;

class Transition
{
private:
	State* fromState;
	GP guardFunction;
	Bulb* guardLocation;
	Transition* next;
	State* toState;

public:
	State* GetToState();
	bool InvokeGuard();
	Transition(State* from, State* to, GP guardFunction, Bulb* guardLocation);
};

