#include "State.h"
#include "Transition.h"

State::State(TStates state) {
	this->state = state;
}

State::State(TStates state, CBP callBack, Bulb* callBackLocation) {
	this->state = state;
	this->callBack = callBack;
	this->callBackLocation = callBackLocation;
	transitions = new LinkedList<Transition>();
	next = 0;
}

bool State::operator != (State& rhd) {
	return (this->state != rhd.state);
}

bool State::operator == (State& rhd) {
	return (this->state == rhd.state);
}

void State::AddTransition(State* from, State* to, GP guard, Bulb* guardLocation) {
	transitions->Insert(new Transition(from, to, guard, guardLocation));
}

void State::InvokeCallback() {
	(callBackLocation->*callBack)();
}

State* State::CheckGuards(bool* changed) {
	for (int n = 0; n < transitions->Count(); n++) {
		// Can not overload pointer operators so must dereference linked list to ensure [] works.
		if ((*transitions)[n]->InvokeGuard()) {
			*changed = true;
			return (*transitions)[n]->GetToState();
		}
	}
	return 0;
}