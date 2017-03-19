#include <stdio.h>

#include <iostream>
using namespace std;

#include "Analyze.h"

int main(void) {

	cout << "# 비밀번호 분석 프로그램을 시작합니다."<<endl<<endl<<endl;

	int numberArray[10] = { 0 };
	int alphaCnt = 0;
	char *str = NULL;

	///////////////////////////
	//0~9로 시작하는 비밀번호의 갯수 세기
	saveNumberCnt(numberArray);
	alphaCnt = returnAlphaCnt();
	//알파벳으로 시작하는 비밀번호의 갯수 세기.
	///////////////////////////


	//결과 출력
	int i;
	for (i = 0; i < 10; i++)
		cout << i + 1 << "로 시작하는 비밀번호의 갯수 : " << numberArray[i] << endl;
	cout << "알파벳으로 시작하는 비밀번호의 갯수 : " << alphaCnt << endl;

	//테스트 코드
	int cnt = 0;
	while(1){
		if(readFile(str) == 1)
			cnt++;
		else break;
	}
	cout << "검사한 자료의 갯수 : "<<cnt << endl;
	return 0;
}
