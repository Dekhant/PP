#pragma once
#include <iostream>
#include <string>
#include "ITask.h"

class Task : public ITask
{
private:
	int _value;

public:
	Task(int value) :
		_value(value)
	{

	}

	void Execute() override
	{
		std::cout << "Execute thread #";
		std::cout << std::to_string(_value) + "\n";
	}
};