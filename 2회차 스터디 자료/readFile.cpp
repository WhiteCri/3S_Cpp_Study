#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

int readFile(char (*str)[]) {////////////
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
		str = (char *) malloc(sizeof(char) * strlen(temp) + 1);

		//���ڿ� ����
		strcpy(*str, temp);////////
		return 1;
	}
	else fseek(fp2,SEEK_SET,0);//����Ŀ���� �� ���� ������ ���,
	//���� Ŀ���� ������ �ǵ�����.
	return 0;
}