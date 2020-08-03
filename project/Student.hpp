#pragma once
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;


class Student
{
public:
	Student();
	Student(int FN,const char* FirstName,const char* LastName, int Grade);
	~Student();
	void setFN(int FN);
	void setFirstName(const char* FirstName);
	void setLastName(const char* LastName);
	void setGrade(int Grade);
    int getFN(); 
	char* getFirstName(); 
	char* getLastName(); 
	int getGrade(); 
	Student & operator=(const Student& oth);
    friend ostream& operator<<(ostream&, const Student& other);
	friend ifstream& operator>>(ifstream& is, Student& student);
	friend ofstream& operator<<(ofstream& os, Student& student);
	//friend istream& operator>>(istream& is, Student& student);
private:
	int FN;
	char* FirstName;
	char* LastName;
	int Grade;
	void CopyFrom(const Student& other);
	void Free();

};
