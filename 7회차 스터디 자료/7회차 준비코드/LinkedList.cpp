/*
 * LinkedList.cpp
 *
 *  Created on: 2017. 4. 30.
 *      Author: TaeWook
 */


#include <iostream>
using namespace std;
#include "LinkedList.h"
#include <vector>
#include <fstream>
#include <cassert>
LinkedList::LinkedList(){
	this->cur = NULL;

	//메모리 생성
	this->head = new Node;
	assert(this->head != 0);
	this->tail = new Node;
	assert(this->tail != 0);

	//헤드 노드 포인터 정리
	this->head->prev = NULL;
	this->head->next = this->tail;

	//테일 노드 포인터 정리
	this->tail->prev = this->head;
	this->tail->next = NULL;

	this->length = 0;
}

LinkedList::~LinkedList(){
	delete this->head;
	delete this->tail;
}

void LinkedList::add_ahead(const char * chp){
	this->initSstream(chp);
	HighSchoolNode data = this->makeNodeInfo();

	this->cur = new Node;
	assert(this->cur != 0);
	this->cur->info = data;

	//새로생성한 노드의 포인터 정리
	this->cur->next = this->head->next;
	this->cur->prev = this->head;


	//주변 노드 정리
	this->head->next->prev = this->cur;
	this->head->next = this->cur;

	//갯수 증가
	this->length++;

}

void LinkedList::add_before_tail(const char * chp){
	this->initSstream(chp);
	HighSchoolNode data = this->makeNodeInfo();
	this->cur = new Node;
	this->cur->info =data;

	// 새로생성한 노드의 포인터 정리
	this->cur->next = this->tail;
	this->cur->prev = this->tail->prev;

	//주변 노드 정리
	this->tail->prev->next = this->cur;
	this->tail->prev = this->cur;

}

bool LinkedList::delete_element_with_string(const string & data){
	this->cur = this->head->next;
	while(this->cur != this->tail){//마지막까지 검사
		if(this->cur->info.str[2] == data)
			break;
		this->cur = this->cur->next;
	}
	if(this->cur == this->tail)//검사노드가 끝까지 왔다면 노드삭제를 실패한상황임
		return false;

	//삭제할 노드의 주변노드 정리
	this->cur->prev->next = this->cur->next;
	this->cur->next->prev =this->cur->prev;

	//노드 삭제
	delete this->cur;
	return true;
}

bool LinkedList::delete_element_with_string_multi(const string & data)
{
	int returnCheck = 0;
	this->cur = this->head->next;
	while(this->cur != this->tail){
		if(this->cur->info.str[2] == data){
			this->cur->prev->next = this->cur->next;
				this->cur->next =this->cur->prev;
				delete this->cur;
				returnCheck++;
		}
		this->cur = this->cur ->next;
	}

	if(returnCheck == 0)
		return false;
	else return true;
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

bool LinkedList::search_multi(const string &data,vector<HighSchoolNode> & getDatas){
	if(getDatas.size()!=0){
		cout << "벡터를 먼저 비어주세요!";
		return false;
	}

	this->cur = this->head->next;
	while(this->cur != this->tail){
		if(this->cur->info.str[2] == data)
			getDatas.push_back(this->cur->info);
	}
	if(getDatas.size() == 0)
		return false;
	else return true;
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

size_t LinkedList::getLength(){
	return this->length;
}

void LinkedList::makeFile(const string & filename){
	ofstream of;
	//파일 경로 설정
	string temp = "c:\\data\\";
	temp = temp + filename;
	//파일을 열기 위해 string에서 char *로 변환
	of.open(temp.c_str());

	int cnt = 0;
	this->cur = this->head->next;
	while(this->cur != this->tail){
		cnt++;
		of << cnt << " : ";
		for(int i=0;i<MAX_STR;i++)
			of << this->cur->info.str[i] << " ";
		for(int i=0;i<MAX_NUMBER;i++)
			of << this->cur->info.n[i] << " ";
		of << endl;
	}
	of.close();
}

void LinkedList::sort(bool(*compare)(const HighSchoolNode & data1,
			const HighSchoolNode & data2)){
	Node * i,*j;
	Node temp;
	Node * target;
	for(i=this->head->next;i != this->tail->prev;i = i->next){
		target = i;
		for(j=i;j !=this->tail;j = j->next)
			if(compare(i->info,j->info))
				target = j;
		temp = *target;
		*target = *i;
		*i = temp;
	}
}

void destroyVector(vector<HighSchoolNode> *vPtr){
	delete vPtr;
}

