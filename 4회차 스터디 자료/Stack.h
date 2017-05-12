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
	Stack(const Stack &stk);//���������
	Stack(const DataType * dataArray,const int &size);
	//DataType�� �迭�� ũ�⸦ ���ڷ� �޾�, �� �迭�� �������� ������ �ʱ�ȭ �ϴ� ������.
	Stack(const Stack &stk1, const Stack &stk2);
	//���� �ΰ��� ���ڷ� �޾�, �� ������ �������� ���ο� ������ �����ϴ� ������.
	//ù ��° ������ ����, �� ��° ������ ���߿� �״´�.
	~Stack();

	//get, set ����Լ�
	int getSize(void);//size�� �����ϴ� �Լ�.
	int getTop(void);//top�� ��ġ�� �����ϴ� �Լ�.
	void setSize(int size);
	void setTop(int top);
	
	void clearStack(void);

	int push(const DataType& data);//push�Լ�. �����ϸ� true, �ݴ�� false
	int pop(DataType &target);//pop�Լ�. ���� ����.

	Stack &operator=(const Stack &stk);//���� ������ �����ε�
	Stack &operator=(const int &number);//���� ������ �����ε� 2


	Stack operator+(const Stack &stk);//+ ������ �����ε�
	//ù ��° ���� ���� �� ��° ������ ���� ������ �����ؼ�, �����Ѵ�.
	//ex) ���� 1�� [1,2,3 �� �ְ� ���� 2�� [4,5,6 �� �ִٸ�
	//���� ����� ���� 3�� [1,2,3,4,5,6 �� �Ǿ�� �Ѵ�.
	Stack operator+(const DataType &data);//+ ������ �����ε�
	//push�� ����� ����. �� ���н� "+ ������ �����ε� ����!"�޼����� ����.

	Stack operator-(const int &number);//- ������ �����ε�
	//������ ������ �ؼ�, �� ���� ��ŭ ������ pop�ϴ� �Լ�.(�������� �̹� �ڵ� �� ���)
	//���� ���� ������ �������� number�� ũ�Ⱑ �� ũ�ٸ�, �ִ��� pop�� �� �����޼��� ���
	//ex)[1,2,3 ¥�� stk���ÿ� stk - 5 ������ �����ϸ� stk�� [(�������) ���� ���� ��
	//"���� �ڷ� ����!"�޼����� ����.
};



#endif /* STACK_H_ */
