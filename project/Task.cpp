#include "Task.hpp"

Task::Task(const char* command)
{
	set_command(command);
}

void Task::set_command(const char* command)
{
	this->command = new char[strlen(command) + 1];
	strcpy(this->command, command);
}

Task::~Task()
{
	delete[] command;
}

char* Task::get_command() const
{
	char* copy = new char[strlen(command) + 1];
	strcpy(copy, command);
	return copy;
}