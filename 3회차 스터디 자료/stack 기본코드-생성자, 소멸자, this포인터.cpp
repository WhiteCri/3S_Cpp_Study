#include <iostream>
#include <string.h>
using namespace std;

class stack{
private:
	char ptr[50];
	int top;
	int Size;
public:
	void initStack();
	int push(char );
	int pop();

	int isFull(void);
	void clearStack(void);
};

void stack::initStack()
//스택 초기화 함수
//리턴값 : 없음
//ptr->모두 0,top : 0, Size:50
{
	int i;
	for(i=0;i<sizeof(ptr)/sizeof(ptr[0]);i++)
		ptr[i] = 0;
	Size = 50;
	top = 0;
}

int stack::push(char ch){
	if(isFull()== 0) return false;
	ptr[top] = ch;
	top++;
	return true;
}

int stack::pop(){
	if(top == 0) return false;
	top--;
	ptr[top]= 0;
	return true;
}

int stack::isFull(){
	return (top == Size);
}

void stack::clearStack(){
	int i;
		for(i=0;i<sizeof(ptr)/sizeof(ptr[0]);i++)
			ptr[i] = 0;
		Size = 50;
		top = 0;
}


