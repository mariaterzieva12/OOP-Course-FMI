#pragma once
#include "CreateTask.cpp"
#include "Student.hpp"
#include"Constants.hpp"

CreateTask::CreateTask() : Task(Constants::CREATE) {}

void CreateTask::execute() const
{
	ofstream file(Constants::DATABASE_NAME, ios::binary | ios::app);
	if (!file)
	{
		cerr << "Could not open " << Constants::DATABASE_NAME << "!" << endl;
		return;
	}
	Student student;
	std::cin >> student;
	file << student;
	file.close();
	cout << "Record saved!" << endl;
}
