/*
 * LinkedList.h
 *
 *  Created on: 2017. 5. 4.
 *      Author: TaeWook
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


#include "HighSchoolNode.h"

struct Node{
	HighSchoolNode info;
	Node * prev;
	Node * next;
};

class LinkedList{
private:
	Node * head;
	Node * tail;
	size_t length;
public:
	LinkedList();
	~LinkedList();
	void add_ahead(Node * data);
	void add_before_tail(Node * data);
};




#endif /* LINKEDLIST_H_ */







