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
	Node * cur;//�۾��� ���
	size_t length;
public:
	LinkedList();
	~LinkedList();
	void add_ahead(const char *chp);//��� �� �Ķ���͸� const char * chp�� �ٲ� ����
	void add_before_tail(const char  * chp);//��� �� �Ķ���͸� const char * chp�� �ٲ㺸��

	bool delete_element_with_string(const string &data);//���� ������ �б��̸�
	bool search(const string & data, HighSchoolNode & getData);//search������ �б��̸�
	void display();//��ũ�帮��Ʈ ��� �Լ�
};




#endif /* LINKEDLIST_H_ */







