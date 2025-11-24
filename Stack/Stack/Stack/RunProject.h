#pragma once

#include <string>
#include <iostream>
#include <unordered_map>
#include "MyStack.h"

std::unordered_map<char,int> precedence = {
	{'+',1},
	{'-',1},
	{'*',2},
	{'/',2},
	{'^',3},
	{'(',0},
	{')',0}
};

double RunProject() {
	LinkListBasedStack<char> opChar;
	LinkListBasedStack<double> opNum;

	while (char op = getchar()!= '=')
	{
		
	}

	return opNum.Top();
}
