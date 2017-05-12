/*
 * Stack.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: TaeWook
 */

#ifndef STACK_H_
#define STACK_H_


class Stack{
private:
	DataType *sPtr;
	int size;
	int top;

public:
	Stack();
	Stack(int size);
	Stack(const Stack &stk);//복사생성자
	Stack(const DataType * dataArray,const int &size);
	//DataType의 배열과 크기를 인자로 받아, 그 배열의 내용으로 스택을 초기화 하는 생성자.
	Stack(const Stack &stk1, const Stack &stk2);
	//스택 두개를 인자로 받아, 두 스택의 내용으로 새로운 스택을 생성하는 생성자.
	//첫 번째 스택을 먼저, 두 번째 스택을 나중에 쌓는다.
	~Stack();

	//get, set 멤버함수
	int getSize(void);//size를 리턴하는 함수.
	int getTop(void);//top의 위치를 리턴하는 함수.
	void setSize(int size);
	void setTop(int top);
	
	void clearStack(void);

	int push(const DataType& data);//push함수. 성공하면 true, 반대면 false
	int pop(DataType &target);//pop함수. 위와 같다.

	Stack &operator=(const Stack &stk);//대입 연산자 오버로딩
	Stack &operator=(const int &number);//대입 연산자 오버로딩 2


	Stack operator+(const Stack &stk);//+ 연산자 오버로딩
	//첫 번째 스택 위에 두 번째 스택을 더한 스택을 구현해서, 리턴한다.
	//ex) 스택 1에 [1,2,3 이 있고 스택 2에 [4,5,6 이 있다면
	//더한 결과인 스택 3은 [1,2,3,4,5,6 이 되어야 한다.
	Stack operator+(const DataType &data);//+ 연산자 오버로딩
	//push와 기능이 같음. 단 실패시 "+ 연산자 오버로딩 에러!"메세지를 띄운다.

	Stack operator-(const int &number);//- 연산자 오버로딩
	//정수와 연산을 해서, 그 정수 만큼 정보를 pop하는 함수.(이정도면 이미 코드 다 줬다)
	//만약 가진 정보의 갯수보다 number의 크기가 더 크다면, 최대한 pop한 후 오류메세지 출력
	//ex)[1,2,3 짜리 stk스택에 stk - 5 연산을 수행하면 stk를 [(비어있음) 으로 만든 후
	//"스택 자료 부족!"메세지를 띄운다.
};



#endif /* STACK_H_ */
