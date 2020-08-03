#ifndef __CREATE_TASK__
#define __CREATE_TASK__
#include "Task.hpp"

class CreateTask : public Task
{
public:
	CreateTask();
	void execute() const;
};

#endif