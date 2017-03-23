#include <iostream>
#include <string.h>
using namespace std;

struct stack{
private:
	char ptr[50];
	int top;
	int Size;
public:
	void initStack();
	int push(char );
	int pop(char *);

	int isFull(void);
	void clearStack(void);
};

void stack::initStack()
//스택 초기화 함수
//리턴값 : 없음
//ptr->모두 0,top : 0, Size:50
{

}

int stack::push(char ch){

}

int stack::pop(char* chp){

}

int stack::isFull(){

}

void stack::clearStack(){

}


