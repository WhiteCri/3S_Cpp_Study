#include "LinkedList.h"

LinkedList::LinkedList(){
	head = new Node;
	tail = new Node;

	head->prev = nullptr;
	head->next = tail;
	tail->prev = head;
	tail->next = nullptr;

	length = 0;
}
LinkedList::~LinkedList(){
	delete head;
	delete tail;
}

void LinkedList::add_ahead(Node * data){
	data->prev = head;
	data->next = head->next;
	head->next->prev = data;
	head->next = data;
	length++;
}

void LinkedList::add_before_tail(Node * data){
	data->prev = tail->prev;
	data->next = tail;
	tail->prev->next = data;
	tail->prev = data;
	length++;
}

















