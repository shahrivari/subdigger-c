#pragma once
#include "eesu.h"
#include <stack>

struct Freelist
{
	static stack<EnumState *> freelist;
	static EnumState * get_new_state();
	static void delete_state(EnumState * state);
};


