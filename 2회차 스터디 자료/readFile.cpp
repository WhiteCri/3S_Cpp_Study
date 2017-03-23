int readFile(char (*str)[]) {////////////
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
		str = (char *) malloc(sizeof(char) * strlen(temp) + 1);

		//문자열 복사
		strcpy(*str, temp);////////
		return 1;
	}
	else fseek(fp2,SEEK_SET,0);//파일커서가 맨 끝에 도달한 경우,
	//파일 커서를 앞으로 되돌린다.
	return 0;
}