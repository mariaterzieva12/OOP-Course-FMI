#pragma once
#ifndef __EXIT_TASK__
#define __EXIT_TASK__
#include "Task.hpp"

class ExitTask : public Task
{
public:
	ExitTask();
	void execute() const;
};

#endif