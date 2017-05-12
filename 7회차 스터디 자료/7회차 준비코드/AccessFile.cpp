/*
 * AccessFile.cpp
 *
 *  Created on: 2017. 4. 24.
 *      Author: TaeWook
 */

#include "AccessFile.h"


AccessFile::~AccessFile() {
	// TODO Auto-generated destructor stub
}

void AccessFile::initSstream(const char * temp){
	v.clear();
	s = temp;//char * ���� ���ڿ��� string ��ü�� ������

	sst.clear();
	sst.str(s);//string ��ü�� ������ sst��ü�� ������.
	//�м��� ���ϰ� �ϱ� ���ؼ���

	string tmp;
	while(sst.eof()!=true){//��Ʈ���� ���� ���� ���� ������
		sst >> tmp;//sst�κ��� ���ڿ��� �ϳ� ���� �� tmp�� �����Ѵ�
		v.push_back(tmp);//tmp�� ���Ϳ� �߰��Ѵ�.
	}

}

const HighSchoolNode &AccessFile::makeNodeInfo(){
	size_t index = 0;
	size_t i;
	for(i=0;i<MAX_STR;i++){
		node.str[i] = v[index++];
	}
	for(i=0;i<MAX_NUMBER;i++)
		node.n[i] = String2Number(v[index++]);
	//while(v.size()!=0)
		//v.pop_back();


	return node;

}

int AccessFile::String2Number(string str){//���� ����� ���Ѻ���?
	const char * tmp = str.c_str();
	int returnValue = atoi(tmp);
	return returnValue;
}

