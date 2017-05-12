/*
 * LinkedList.h
 *
 *  Created on: 2017. 5. 4.
 *      Author: TaeWook
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


#include "HighSchoolNode.h"
#include "AccessFile.h"
struct Node{
	HighSchoolNode info;
	Node * prev;
	Node * next;
};

class LinkedList:public AccessFile{
private:
	Node * head;
	Node * tail;
	Node * cur;//작업용 노드
	size_t length;
public:
	LinkedList();
	~LinkedList();
	void add_ahead(const char *chp);//상속 후 파라미터를 const char * chp로 바꿔 보자
	void add_before_tail(const char  * chp);//상속 후 파라미터를 const char * chp로 바꿔보자

	bool delete_element_with_string(const string &data);//삭제 기준은 학교이름
	bool search(const string & data, HighSchoolNode & getData);//search기준은 학교이름
	void display();//링크드리스트 출력 함수
};




#endif /* LINKEDLIST_H_ */







