#include <iostream>
using namespace std;
#include <fstream>
#include <cassert>

#include "AccessFile.h"
#include "LinkedList.h"

void showNode(const HighSchoolNode & data);
bool compare_by_class_number(const Node * data1, const Node * data2){
	bool returnValue = (data1->info.n[17] > data2->info.n[17]);
	return returnValue;
}

bool compare_by_name(const Node * data1, const Node * data2){
	//cout << data1->info.str[1] << data2->info.str[1] << endl;
	//cin.get();
	return (data1->info.str[2] > data2->info.str[2]);
}

int main(void){
	cout << "파일 정보 읽어오는중..."<<endl;
	ifstream in("c:\\data\\고등학교 정보2.txt");
	assert(!in.fail());


	char temp[1000];
	in.getline(temp,sizeof(temp));//첫 라인은 버린다

	LinkedList lp;

	while(!in.eof()){
		in.getline(temp,sizeof(temp));
		lp.add_before_tail(temp);//링크드리스트 구성 완료
	}


	lp.display();
	cin.get();
	lp.sort(compare_by_class_number);
	lp.makeFile("학급수로_정렬.txt");

	lp.sort(compare_by_name);
	lp.makeFile("학교 이름으로 정렬.txt");
	cin.get();
}

void showNode(const HighSchoolNode & data){
	cout << "main.c의 showNode함수 작동중.."<<endl;
	size_t i;
	for(i=0;i<MAX_STR;i++)
		cout << data.str[i] << "  ";
	for(i=0;i<MAX_NUMBER;i++)
		cout << data.n[i] << " ";
	cout << endl;
}
