/*
 * AccessFile.h
 *
 *  Created on: 2017. 4. 24.
 *      Author: TaeWook
 */

#ifndef ACCESSFILE_H_
#define ACCESSFILE_H_

#include <iostream>
using namespace std;

#include <vector>
#include <sstream>
#include <string>
#include <cstdlib>
#include "HighSchoolNode.h"

class AccessFile {
private:
	vector<string> v;
	string s;
	stringstream sst;
	HighSchoolNode node;
public:
	~AccessFile();
	void initSstream(const char * temp);
	int String2Number(string str);
	const HighSchoolNode &makeNodeInfo();
};

#endif /* ACCESSFILE_H_ */
