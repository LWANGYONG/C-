#pragma once
#include "Student.h"
class Teacher
{
	int t_age;
public:
	Teacher();
	~Teacher();
	friend class Student;
};

