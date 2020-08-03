#pragma once
#ifndef __SEARCH_TASK__
#define __SEARCH_TASK__
#include "Task.hpp"

class SearchTask : public Task
{
public:
	SearchTask();
	void execute() const;
};

#endif