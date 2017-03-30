#pragma once


typedef struct _numberCnt{
	char Number[3];//00 ���� ���� �� ���� �����ϴ� �н����带 ����
	int cnt;//�н������� ���� Ƚ�� ����
}NumberCnt;


typedef struct _totalInfo{
	NumberCnt each[100];//00~99�� ���� �����
	int total;//�˻��� �ڷ��� ������ ������ ����. ������ ���� ������ ������ �ϳ��� ������ų ��
}TotalInfo;



//function member
int readFile(char** str);//���� �б�� �Լ�

void initPasswordInfo(TotalInfo * info);

void savePasswordInfo(TotalInfo * info);

void showPasswordInfo(TotalInfo info);

void fileSavePasswordInfo(TotalInfo info);

void filesSavePasswordInfo_total(TotalInfo info);
