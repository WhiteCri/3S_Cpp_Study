#pragma once
#include <iostream>
using namespace std;

#ifndef MAX_STR
#define MAX_STR 10
#endif


#ifndef MAX_NUMBER
#define MAX_NUMBER 18
#endif

struct HighSchoolNode{
public:
	string str[MAX_STR];
	int n[MAX_NUMBER];
	size_t total_class;

};


