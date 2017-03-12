/*
 * Analyze.cpp
 *
 *  Created on: 2017. 3. 12.
 *      Author: TaeWook
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int readFile(char str[]) {
	static FILE *fp2 = fopen("c:\\data\\rockyou.txt", "r");
	assert(fp2!=NULL);

	char temp[200];

	//메모리 정리
	if (str != NULL){
		free(str);
		str = NULL;
	}

	//비밀번호 읽기
	if (fgets(temp, sizeof(temp), fp2) != NULL) {
		temp[strlen(temp) - 1] = '\0';

		//메모리 할당
		str = (char *) malloc(sizeof(char) * strlen(temp) + 1);

		//문자열 복사
		strcpy(str, temp);
		return 1;
	}
	else fseek(fp2,SEEK_SET,0);//파일커서가 맨 끝에 도달한 경우,
	//파일 커서를 앞으로 되돌린다.
	return 0;
}

void saveNumberCnt(int ary[])
//숫자로 시작하는 비밀번호의 갯수를 세는 함수
//int ary : 각 방번호에 해당되는 숫자로 시작하는 비밀번호의 갯수를 저장
//ex) 0으로 시작하는 비밀번호는 ary[0]에 저장
{

}

int returnAlphaCnt()
//알파벳으로 시작하는 비밀번호의 갯수를 세는 함수
//대소문자 구별 X, 갯수만 셉시다.
{
	return 0;
}

