#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "Analyze.h"
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;


int readFile(char **str) {////////////
	static FILE *fp2 = fopen("c:\\data\\rockyou.txt", "r");
	assert(fp2!=NULL);

	char temp[200];

	//메모리 정리
	if (*str != NULL){////////
		free(*str);////////////
		*str = NULL;////////
	}

	//비밀번호 읽기
	if (fgets(temp, sizeof(temp), fp2) != NULL) {
		temp[strlen(temp) - 1] = '\0';

		//메모리 할당
		*str = (char *) malloc(sizeof(char) * strlen(temp) + 1);

		//문자열 복사
		strcpy(*str, temp);////////
		return 1;
	}
	else fseek(fp2,SEEK_SET,0);//파일커서가 맨 끝에 도달한 경우,
	//파일 커서를 앞으로 되돌린다.
	return 0;
}

void initPasswordInfo(TotalInfo * info)/*
: info 구조체를 초기화한다. info의 total 멤버를 0으로 초기화하며,
each구조체배열도 초기화한다. char Number[3]은 00부터 99까지
순서대로 초기화하며, cnt는 0으로 초기화한다.
*/
{
	int i;
	char temp[10];

	for(i=0;i<10;i++){
		temp[0] ='0';
		itoa(i,temp+1,10);
		strcpy(info->each[i].Number,temp);
		info->each[i].cnt = 0;
	}
	for(i=10;i<100;i++){
		itoa(i,temp,10);//숫자를 문자열로 변환
		strcpy(info->each[i].Number,temp);//Name초기화
		info->each[i].cnt = 0;
	}

	info->total = 0;
}

void savePasswordInfo(TotalInfo * info)
/*패스워드의 정보를 저장하는 함수
while(1){
-1. 패스워드를 읽는다. 함수를 종료한다.
-2.  total 값을 하나 증가시킨다.
	if(패스워드의 앞 두자리가 숫자 두 개로 시작하면)
 	2-1. 앞 두자리를 정수로 변환한다.
	2-1. 변환한 정수를 each구조체배열의 index로 사용하여, 구조체에 접	근 후 cnt값을 하나 증가시킨다.
	ex)만약 앞자리가 “31”이면, 정수 31로 변환 후 each[31].cnt++; 수행
-3. 1로 돌아간다.
}
*/
{
	char *str = NULL;
	char temp[3];
	temp[2] = '\0';
	int target;

	while(readFile(&str)!=0){
		info->total++;
		if(strlen(str) > 1){
			temp[0] = str[0];
			temp[1] = str[1];
			if(('0' <= temp[0] && temp[0] <= '9') && ('0'<= temp[1] && temp[1] <= '9')){//비밀번호가 숫자
				//두 개로 시작하면
				target = atoi(temp);
				info->each[target].cnt++;
			}
		}
	}
}

void showPasswordInfo(TotalInfo info)
/*패스워드의 정보를 출력한다.
savePasswordInfo함수를 이용해 정리한 파일의 패스워드 정보를 모니터에 출력한다.
출력양식)
“00” : 302451 회
“01” : 123215 회
*/
{
	int i;
	for(i=0;i<100;i++){
		cout << "\"" << info.each[i].Number << "\"  :  " << setw(6) <<
				info.each[i].cnt << " 회" << endl;
	}
}

void fileSavePasswordInfo(TotalInfo info)
/*
 *  패스워드 숫자 사용 빈도수 top 10을 파일에 출력한다. 파일입출력은 Absolute C++책을 참고하여 작성한다.
 */
{
	NumberCnt temp;
	int i;
	int j;
	TotalInfo target = info;
	for(i=0;i<10;i++){//top 10만 필요하므로, 10개까지만 버블정렬한다.
		for(j=i+1;j<100;j++)
			if(target.each[i].cnt < target.each[j].cnt){
				temp = target.each[i];
				target.each[i] = target.each[j];
				target.each[j] = temp;
			}
	}

	ofstream outFile;
	outFile.open("c:\\data\\TopRankPassword.txt");

	outFile << "Writer :  박태욱"<< endl;
	outFile << "Date : "<< __DATE__ << endl;
	outFile << "Time : "<<__TIME__<<endl << endl << endl;

	for(i=0;i<10;i++){
		outFile << "Rank "<< setw(2)<<i+1 << ": \"" << target.each[i].Number
				<< "\" (count : " << setw(6)<< target.each[i].cnt << ")" << endl;
	}

	outFile.close();



}

void filesSavePasswordInfo_total(TotalInfo info)
/*
 * info구조체의 내용을 전부 파일에 출력한다.
 */
{
	ofstream outFile;
	outFile.open("c:\\data\\PasswordInfo.txt");
	if(outFile.fail()){
		cout << "fileOpenError!!"<< endl;
		exit(1);
	}
	int i;
	for(i=0;i<100;i++){
		outFile << "\"" << info.each[i].Number << "\" (count : " << info.each[i].cnt << ")" << endl;
	}
	outFile.close();
}

