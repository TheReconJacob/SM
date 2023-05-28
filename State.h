#pragma once
#include "stdafx.h"
#include "LinkedList.h"
#include "Transition.h"
class State
{
public:
	CBP callBack;
	Bulb* callBackLocation;
	State* next;
	TStates state;
	LinkedList<Transition>* transitions;

	void AddTransition(State* from, State* to, GP guard, Bulb* guardLocation);
	State* CheckGuards(bool* changed);
	void InvokeCallback();
	bool operator!=(State& rhd);
	bool operator==(State& rhd);
	State(TStates state);
	State(TStates state, CBP callBack, Bulb* callBackLocation);
};

