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
	s = temp;//char * 형의 문자열을 string 객체에 저장함

	sst.clear();
	sst.str(s);//string 객체의 내용을 sst객체에 저장함.
	//분석을 편하게 하기 위해서임

	string tmp;
	while(sst.eof()!=true){//스트링의 제일 끝에 닿을 때까지
		sst >> tmp;//sst로부터 문자열을 하나 읽은 후 tmp에 저장한다
		v.push_back(tmp);//tmp를 벡터에 추가한다.
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

int AccessFile::String2Number(string str){//직접 만들게 시켜볼까?
	const char * tmp = str.c_str();
	int returnValue = atoi(tmp);
	return returnValue;
}

