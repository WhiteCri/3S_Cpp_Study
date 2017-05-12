/*
 * LinkedList.h
 *
 *  Created on: 2017. 4. 30.
 *      Author: TaeWook
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "AccessFile.h"
#include <vector>

typedef struct node{
	HighSchoolNode info;
	node * next;
	node * prev;
}Node;

class LinkedList:public AccessFile{
private:
	Node * head;
	Node * tail;
	size_t length;
	Node * cur;
public:
	LinkedList();
	~LinkedList();
	void add_ahead(const char * chp);
	void add_before_tail(const char * chp);

	bool search(const string & data, HighSchoolNode & getData);
	bool search_multi(const string & data,vector<HighSchoolNode> &getDatas);

	bool delete_element_with_string(const string &data);
	bool delete_element_with_string_multi(const string &data);

	void display();
	void makeFile(const string & filename);
	void sort(bool(*compare)(const Node * data1,
			const Node * data2));




	//compare function member
	friend bool compare_by_name(const Node * data1, const Node * data2);
	friend bool compare_by_class_number(const Node * data1, const Node * data2);

	size_t getLength();
};



#endif /* LINKEDLIST_H_ */
