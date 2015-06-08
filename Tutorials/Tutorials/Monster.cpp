#include "Monster.h"

#include <iostream>
#include <string>

Monster::Monster()
{
	cout << "Hello Monster" << endl;
}

Monster::Monster(string name)
{
	_name = name;
}

void Monster::printName() 
{
	cout << "My name is: " << _name << endl;
}
