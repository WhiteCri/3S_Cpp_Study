#include <iostream>
using namespace std;
#include <fstream>
#include <cassert>

#include "AccessFile.h"
#include "LinkedList.h"


int main(void){
	ifstream in("c:\\data\\����б� ����2.txt");
	assert(!in.fail());


	LinkedList link;
	char str[1000];

	in.getline(str,sizeof(str));//ù���� ������.


	while(!in.eof()){
		in.getline(str,sizeof(str));
		link.add_before_tail(str);
	}
	link.display();

	cin.get();
}




