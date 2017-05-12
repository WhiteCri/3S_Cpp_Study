#include <iostream>
using namespace std;
#include <fstream>
#include <cassert>

#include "AccessFile.h"
#include "LinkedList.h"

void printNode(const HighSchoolNode & node);

int main(void){
	ifstream in("c:\\data\\����б� ����2.txt");
	assert(!in.fail());
	char temp[1000];

	in.getline(temp,sizeof(temp));
	LinkedList link;
	AccessFile ac;
	Node * nodeP;
	while (in.eof() != true) {

		in.getline(temp, sizeof(temp));//���Ͽ��� raw�����ͷ� ���� �б�
		ac.initSstream(temp);//raw������ ����
		nodeP = new Node;//��ũ�帮��Ʈ�� ���ο� ��� �޸� ����
		nodeP->info = ac.makeNodeInfo();//������ �޸𸮿� ���� ������ ����
		link.add_before_tail(nodeP);//��ũ�帮��Ʈ�� ���� �κп� ��� ���̱�
		///////////////////7ȸ�� ���͵�
	}
	cout << "���Ͽ��� ���� �� �Ľ� �Ϸ�" << endl;
	return 0;
}

void printNode(const HighSchoolNode & node){
	int i;
	for(i=0;i<MAX_STR;i++)
		cout << i + 1 << " : "  <<  node.str[i] << endl;;
	for(i=0;i<MAX_NUMBER;i++)
		cout << i + 1 << " : "  << node.n[i] << endl;
}
