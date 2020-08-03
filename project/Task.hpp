#pragma once
#ifndef __TASK__
#define __TASK__
#include <cstring>
#include <iostream>
#include "Constants.hpp"

class Task
{
public:
	~Task();
	virtual void execute() const = 0;
	char* get_command() const;
protected:
	char* command = nullptr;
	Task(const char* command);
	void set_command(const char* command);
private:
	void copy(const Task& other);
};

#endif 
