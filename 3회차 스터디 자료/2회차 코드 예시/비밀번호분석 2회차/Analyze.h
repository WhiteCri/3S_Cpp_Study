#pragma once


typedef struct _numberCnt{
	char Number[3];//00 등의 숫자 두 개로 시작하는 패스워드를 저장
	int cnt;//패스워드의 출현 횟수 저장
}NumberCnt;


typedef struct _totalInfo{
	NumberCnt each[100];//00~99개 숫자 저장용
	int total;//검사한 자료의 개수를 저장할 변수. 파일을 읽을 때마다 개수를 하나씩 증가시킬 것
}TotalInfo;



//function member
int readFile(char** str);//파일 읽기용 함수

void initPasswordInfo(TotalInfo * info);

void savePasswordInfo(TotalInfo * info);

void showPasswordInfo(TotalInfo info);

void fileSavePasswordInfo(TotalInfo info);

void filesSavePasswordInfo_total(TotalInfo info);
