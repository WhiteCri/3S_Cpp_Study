#include "LinkedList.h"
#include <iostream>
using namespace std;
#include <string>
LinkedList::LinkedList(){
	head = new Node;
	tail = new Node;
	cur = NULL;

	head->prev = NULL;
	head->next = tail;
	tail->prev = head;
	tail->next = NULL;

	length = 0;
}
LinkedList::~LinkedList(){
	delete head;
	delete tail;
}

void LinkedList::add_ahead(const char  * chp){
	initSstream(chp);

	Node *data;
	data = new Node;
	data->info = makeNodeInfo();

	data->prev = head;
	data->next = head->next;
	head->next->prev = data;
	head->next = data;
	length++;
}

void LinkedList::add_before_tail(const char  * chp){
	initSstream(chp);

	Node *data;
	data = new Node;
	data->info = makeNodeInfo();

	data->prev = tail->prev;
	data->next = tail;
	tail->prev->next = data;
	tail->prev = data;
	length++;
}

bool LinkedList::search(const string & data,HighSchoolNode & getData){
	this->cur = this->head->next;
	while(this->cur != this->tail){
		if(this->cur->info.str[2] == data){
			getData = this->cur->info;
			return true;
		}
		this->cur = this->cur->next;
	}
	return false;
}

void LinkedList::display(){
	this->cur = this->head->next;
	int i, cnt = 0;
	while(this->cur != this->tail){
		cout << ++cnt << " : ";
		for(i=0;i<MAX_STR;i++)
			cout << this->cur->info.str[i] << "  ";
		for(i=0;i<MAX_NUMBER;i++)
			cout << this->cur->info.n[i] << " ";
		cout << endl;
		this->cur = this->cur->next;
	}
}















