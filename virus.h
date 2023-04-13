#pragma once
#include "genome.h"
#include "animal.h"
#include <vector>
#include <iostream>
class virus:genome
{
public:
	virus();
	bool CheckHarmfulVirus(vector <string> strings);
	void print();
	
};
