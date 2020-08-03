#pragma once
#include "SearchTask.hpp"
#include "Student.hpp"

SearchTask::SearchTask() : Task(Constants::SEQUENTIALSEARCH) {}

void SearchTask::execute() const
{
	ifstream file(Constants::DATABASE_NAME);
	if (!file)
	{
		std::cerr << "Could not open " << Constants::DATABASE_NAME << "!" << endl;
		return;
	}
	bool is_seen = false;
	Student student;
	while (file.peek() != EOF && !is_seen)
	{
		int FN;
		std::cin >> FN;
		file >> student;
		if (is_seen = student.getFN() == FN)
			cout << student;
	}
	file.close();
       cout << (is_seen ? "Record not found!" : "") << endl;
}