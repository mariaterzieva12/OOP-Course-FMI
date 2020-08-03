#include "ExitTask.hpp"

ExitTask::ExitTask() : Task(Constants::EXIT) {}

void ExitTask::execute() const
{
	exit(1);
}