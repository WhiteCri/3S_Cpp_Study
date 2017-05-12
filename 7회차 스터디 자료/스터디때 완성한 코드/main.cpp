#include <iostream>
using namespace std;
#include <fstream>
#include <cassert>

#include "AccessFile.h"
#include "LinkedList.h"

void printNode(const HighSchoolNode & node);

int main(void){
	ifstream in("c:\\data\\고등학교 정보2.txt");
	assert(!in.fail());
	char temp[1000];

	in.getline(temp,sizeof(temp));
	LinkedList link;
	AccessFile ac;
	Node * nodeP;
	while (in.eof() != true) {

		in.getline(temp, sizeof(temp));//파일에서 raw데이터로 한줄 읽기
		ac.initSstream(temp);//raw데이터 가공
		nodeP = new Node;//링크드리스트의 새로운 노드 메모리 생성
		nodeP->info = ac.makeNodeInfo();//생성한 메모리에 한줄 데이터 복사
		link.add_before_tail(nodeP);//링크드리스트에 꼬리 부분에 노드 붙이기
		///////////////////7회차 스터디
	}
	cout << "파일에서 한줄 씩 파싱 완료" << endl;
	return 0;
}

void printNode(const HighSchoolNode & node){
	int i;
	for(i=0;i<MAX_STR;i++)
		cout << i + 1 << " : "  <<  node.str[i] << endl;;
	for(i=0;i<MAX_NUMBER;i++)
		cout << i + 1 << " : "  << node.n[i] << endl;
}
