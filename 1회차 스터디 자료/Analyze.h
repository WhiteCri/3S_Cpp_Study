#pragma once

//파일의 비밀번호를 하나씩 읽어오는 함수
//성공하면 1, 실패하면 0을 반환
//0을 반환하면 파일 커서는 처음으로 돌아감
int readFile(char str[]);//str : 읽은 비밀번호를 저장할 변수

//숫자로 시작하는 비밀번호의 갯수를 세는 함수
void saveNumberCnt(int ary[]);

//알파벳으로 시작하는 비밀번호의 갯수를 세는 함수
int returnAlphaCnt();

