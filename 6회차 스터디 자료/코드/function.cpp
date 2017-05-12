#include <iostream>
using namespace std;
#include <fstream>
#include <cassert>

#include "AccessFile.h"

void printNode(const HighSchoolNode & node);

int main(void){
	ifstream in("c:\\data\\고등학교 정보2.txt");
	assert(!in.fail());
	char temp[1000];

	in.getline(temp,sizeof(temp));
	in.getline(temp,sizeof(temp));
	AccessFile af;
	af.initSstream(temp);
	HighSchoolNode node;
	node = af.makeNodeInfo();

	printNode(node);
	cin.get();
}

void printNode(const HighSchoolNode & node){
	int i;
	for(i=0;i<MAX_STR;i++)
		cout << i + 1 << " : "  <<  node.str[i] << endl;;
	for(i=0;i<MAX_NUMBER;i++)
		cout << i + 1 << " : "  << node.n[i] << endl;
}
