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
	cout << "���� ���� �о������..."<<endl;
	ifstream in("c:\\data\\����б� ����2.txt");
	assert(!in.fail());


	char temp[1000];
	in.getline(temp,sizeof(temp));//ù ������ ������

	LinkedList lp;

	while(!in.eof()){
		in.getline(temp,sizeof(temp));
		lp.add_before_tail(temp);//��ũ�帮��Ʈ ���� �Ϸ�
	}


	lp.display();
	cin.get();
	lp.sort(compare_by_class_number);
	lp.makeFile("�б޼���_����.txt");

	lp.sort(compare_by_name);
	lp.makeFile("�б� �̸����� ����.txt");
	cin.get();
}

void showNode(const HighSchoolNode & data){
	cout << "main.c�� showNode�Լ� �۵���.."<<endl;
	size_t i;
	for(i=0;i<MAX_STR;i++)
		cout << data.str[i] << "  ";
	for(i=0;i<MAX_NUMBER;i++)
		cout << data.n[i] << " ";
	cout << endl;
}
