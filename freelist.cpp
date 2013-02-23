#include "freelist.h"

stack<EnumState*> Freelist::freelist;

EnumState * Freelist::get_new_state()
{
	if(freelist.size()==0)
		return new EnumState;
	EnumState* top=freelist.top();
	freelist.pop();
	return top;
}

void Freelist::delete_state(EnumState * state)
{
	if(freelist.size()>10000)
		delete state;
	else
		freelist.push(state);
}
