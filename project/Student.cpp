#include<iostream>
#include<fstream>
#include<cstring>
#include "Student.hpp"

using  namespace std;

void Student::CopyFrom(const Student& other)
{
	int len = strlen(other.getFirstName);
	char* FirstName = new char[len + 1];
	strcpy(FirstName,other.getFirstName); 
	
	int len1 = strlen(other.getLastName);
	char* LastName = new char[len + 1];
	strcpy(LastName, other.getLastName);

	Grade = other.getGrade;
	FN = other.FN;
}
void Student::Free()
{
	delete[] FirstName;
	delete[] LastName;

}

Student::Student()
{
	FN = 0;
	FirstName = nullptr;
	LastName = nullptr;
	Grade = 0;
}

Student::Student(int FN, const char* FirstName, const char* LastName, int Grade)
{
	setFN(FN);
	setFirstName(FirstName);
	setLastName(LastName);
	setGrade(Grade);
}


Student::~Student()
{
	delete[] FirstName;
	delete[] LastName;
}

void Student::setFN( int FN)
{
	if (FN < 0)
		this->FN = 0;
	else if (FN >=46000)
	{
		this->FN =46000;
	}
	else
		this->FN = FN;
}

void Student::setFirstName(const char* FirstName)
{
	if (this->FirstName != nullptr)
		delete[] this->FirstName;
	this->FirstName = new char[strlen(FirstName) + 1];
	strcpy (this->FirstName, FirstName);
}

void Student::setLastName(const char* LastName)
{
	if (this->LastName != nullptr)
		delete[] this->LastName;
	this->LastName = new char[strlen(LastName) + 1];
	strcpy(this->LastName, LastName);
}

void Student::setGrade(int Grade)
{
	if (Grade < 2 || Grade >6)
	{
		Grade = 0;
	}

	this->Grade = Grade;
}

int Student::getFN() 
{
	return FN;
}

char* Student::getFirstName() 
{
	return FirstName;
}

char* Student::getLastName()
{
	return LastName;
}

int Student::getGrade()
{
	return Grade;
}

Student&Student::operator=(const Student& oth)
{
	if (this != &oth)
	{
		void Free();
		FN = 0;
		Grade = 0;

		int len = strlen(oth.FirstName);
		FirstName = new char[len + 1];
		strcpy(FirstName, oth.FirstName);

		int len1 = strlen(oth.LastName);
		LastName = new char[len1 + 1];
		strcpy(LastName, oth.LastName);

		this->FN = FN;
		this->Grade = Grade;
	}
	return *this;
}

istream& operator>>(istream& is, Student& student)
{
	int FN;
	int Grade;
	size_t len = 100;
	char* FirstName = new char[len];
	char* LastName = new char[len];
	is >> FN >> FirstName >> LastName >> Grade;
	student.setFN(FN);
	student.setFirstName(FirstName);
	student.setLastName(LastName);
	student.setGrade(Grade);
	delete[] FirstName;
	delete[] LastName;
	return is;
}

ostream& operator<<(ostream& os,  Student& student)
{
	char* FirstName = student.getFirstName();
	char* LastName = student.getLastName();
	cout << student.getFN() << " " << FirstName << " " << LastName << " " << student.getGrade() << endl;
	delete[] FirstName;
	delete[] LastName;
	return os;
}

ofstream& operator<<(ofstream& os,  Student& student)
{
	int FN = student.getFN();
	int Grade = student.getGrade();
	char* FirstName = student.getFirstName();
	char* LastName = student.getLastName();
	unsigned int first_name_len = strlen(FirstName) + 1;
	unsigned int last_name_len = strlen(LastName) + 1;
	os.write((const char*)& FN, sizeof(unsigned long long))
		.write((const char*)& first_name_len, sizeof(unsigned int))
		.write((const char*)& FirstName, sizeof(char) * first_name_len)
		.write((const char*)& last_name_len, sizeof(unsigned int))
		.write((const char*)& LastName, sizeof(char) * last_name_len)
		.write((const char*)& Grade, sizeof(unsigned long long));
	delete[] FirstName;
	delete[] LastName;
	return os;
}

ifstream& operator>>(ifstream& is, Student& student)
{
	int FN;
	int Grade;
	unsigned int first_name_len;
	unsigned int last_name_len;
	is.read((char*)& FN, sizeof(unsigned long long))
		.read((char*)& first_name_len, sizeof(unsigned int));
	char* FirstName = new char[first_name_len + 1];
	is.read((char*)& FirstName, sizeof(char) * first_name_len)
		.read((char*)& last_name_len, sizeof(unsigned int));
	char* LastName = new char[last_name_len + 1];
	is.read((char*)& LastName, sizeof(char) * last_name_len)
		.read((char*)& Grade, sizeof(unsigned long long));
	FirstName[first_name_len + 1] = '\0';
	LastName[last_name_len + 1] = '\0';
	student.setFN(FN);
	student.setFirstName(FirstName);
	student.setLastName(LastName);
	student.setGrade(Grade);
	delete[] FirstName;
	delete[] LastName;
	return is;
}


