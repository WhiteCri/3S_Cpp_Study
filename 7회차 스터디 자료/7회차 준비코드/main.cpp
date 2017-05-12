#include <iostream>
using namespace std;
#include <fstream>
#include <cassert>

#include "AccessFile.h"
#include "LinkedList.h"

void showNode(const HighSchoolNode & data);


int main(void){
	cout << "���� ���� �о������..."<<endl;
	ifstream in("c:\\data\\����б� ����2.txt");
	assert(!in.fail());

	int cin_fake_info;

	char temp[1000];
	in.getline(temp,sizeof(temp));//ù ������ ������


	cout << "LinkedList ������ ȣ�� ��..."<<endl<<endl;
	LinkedList lp;

	cout << "���߱�� ����ũ ���� �޴���. 1 �Է��� ���� ����"<<endl;
	cin >> cin_fake_info;

	cout << "add_before_tail�� �̿��� ���Ͽ��� ������ �а� ��带 �����ϴ���.."<<endl<<endl;
	while(1){
		if(in.eof())
			break;
		in.getline(temp,sizeof(temp));
		lp.add_before_tail(temp);
	}
	cout << "���߱�� ����ũ ���� �޴���. 1 �Է��� ���� ����"<<endl;
	cin >> cin_fake_info;

	cout << "display()�Լ� �۵���" << endl;
	lp.display();
	cout << "���߱�� ����ũ ���� �޴���. 1 �Է��� ���� ����"<<endl;
	cin >> cin_fake_info;

	string temp_location = "���뿹������б�";
	HighSchoolNode tempNodeInfo;
	cout << "���뿹������б� ��带 ã�� ��...(3��° �б� ����)"<<endl;
	lp.search(temp_location,tempNodeInfo);
	cout << "��� ���� ���-"<<endl;
	showNode(tempNodeInfo);

	cout << "���߱�� ����ũ ���� �޴���. 1 �Է��� ���� ����"<<endl;
	cin >> cin_fake_info;

	string temp_location2 = "��������б�";
	lp.delete_element_with_string(temp_location2);
	lp.display();
	cout << "��Ű���б� ���(�ڿ��� �ι�°)�� �����߽��ϴ�." << endl;


	cout << "���߱�� ����ũ ���� �޴���. 1 �Է��� ���� ����"<<endl;
	cin >> cin_fake_info;

	cout << "����������ٴ�...�������� �Լ� �ڵ带 �ۼ��ϼ���..."<<endl;
	cin >> cin_fake_info;
}

void showNode(const HighSchoolNode & data){
	cout << "main.c�� showNode�Լ� �۵���.."<<endl;
	size_t i;
	for(i=0;i<MAX_STR;i++)
		cout << data.str[i] << "  ";
	for(i=0;i<MAX_NUMBER;i++)
		cout << data.n[i] << " ";
	cout << endl;
}
