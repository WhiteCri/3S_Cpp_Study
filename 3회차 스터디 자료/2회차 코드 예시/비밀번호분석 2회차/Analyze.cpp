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

	//�޸� ����
	if (*str != NULL){////////
		free(*str);////////////
		*str = NULL;////////
	}

	//��й�ȣ �б�
	if (fgets(temp, sizeof(temp), fp2) != NULL) {
		temp[strlen(temp) - 1] = '\0';

		//�޸� �Ҵ�
		*str = (char *) malloc(sizeof(char) * strlen(temp) + 1);

		//���ڿ� ����
		strcpy(*str, temp);////////
		return 1;
	}
	else fseek(fp2,SEEK_SET,0);//����Ŀ���� �� ���� ������ ���,
	//���� Ŀ���� ������ �ǵ�����.
	return 0;
}

void initPasswordInfo(TotalInfo * info)/*
: info ����ü�� �ʱ�ȭ�Ѵ�. info�� total ����� 0���� �ʱ�ȭ�ϸ�,
each����ü�迭�� �ʱ�ȭ�Ѵ�. char Number[3]�� 00���� 99����
������� �ʱ�ȭ�ϸ�, cnt�� 0���� �ʱ�ȭ�Ѵ�.
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
		itoa(i,temp,10);//���ڸ� ���ڿ��� ��ȯ
		strcpy(info->each[i].Number,temp);//Name�ʱ�ȭ
		info->each[i].cnt = 0;
	}

	info->total = 0;
}

void savePasswordInfo(TotalInfo * info)
/*�н������� ������ �����ϴ� �Լ�
while(1){
-1. �н����带 �д´�. �Լ��� �����Ѵ�.
-2.  total ���� �ϳ� ������Ų��.
	if(�н������� �� ���ڸ��� ���� �� ���� �����ϸ�)
 	2-1. �� ���ڸ��� ������ ��ȯ�Ѵ�.
	2-1. ��ȯ�� ������ each����ü�迭�� index�� ����Ͽ�, ����ü�� ��	�� �� cnt���� �ϳ� ������Ų��.
	ex)���� ���ڸ��� ��31���̸�, ���� 31�� ��ȯ �� each[31].cnt++; ����
-3. 1�� ���ư���.
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
			if(('0' <= temp[0] && temp[0] <= '9') && ('0'<= temp[1] && temp[1] <= '9')){//��й�ȣ�� ����
				//�� ���� �����ϸ�
				target = atoi(temp);
				info->each[target].cnt++;
			}
		}
	}
}

void showPasswordInfo(TotalInfo info)
/*�н������� ������ ����Ѵ�.
savePasswordInfo�Լ��� �̿��� ������ ������ �н����� ������ ����Ϳ� ����Ѵ�.
��¾��)
��00�� : 302451 ȸ
��01�� : 123215 ȸ
*/
{
	int i;
	for(i=0;i<100;i++){
		cout << "\"" << info.each[i].Number << "\"  :  " << setw(6) <<
				info.each[i].cnt << " ȸ" << endl;
	}
}

void fileSavePasswordInfo(TotalInfo info)
/*
 *  �н����� ���� ��� �󵵼� top 10�� ���Ͽ� ����Ѵ�. ����������� Absolute C++å�� �����Ͽ� �ۼ��Ѵ�.
 */
{
	NumberCnt temp;
	int i;
	int j;
	TotalInfo target = info;
	for(i=0;i<10;i++){//top 10�� �ʿ��ϹǷ�, 10�������� ���������Ѵ�.
		for(j=i+1;j<100;j++)
			if(target.each[i].cnt < target.each[j].cnt){
				temp = target.each[i];
				target.each[i] = target.each[j];
				target.each[j] = temp;
			}
	}

	ofstream outFile;
	outFile.open("c:\\data\\TopRankPassword.txt");

	outFile << "Writer :  ���¿�"<< endl;
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
 * info����ü�� ������ ���� ���Ͽ� ����Ѵ�.
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

