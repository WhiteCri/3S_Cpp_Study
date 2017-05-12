#include <iostream>
using namespace std;
#include <fstream>
#include <cassert>

#include "AccessFile.h"
#include "LinkedList.h"

void showNode(const HighSchoolNode & data);


int main(void){
	cout << "파일 정보 읽어오는중..."<<endl;
	ifstream in("c:\\data\\고등학교 정보2.txt");
	assert(!in.fail());

	int cin_fake_info;

	char temp[1000];
	in.getline(temp,sizeof(temp));//첫 라인은 버린다


	cout << "LinkedList 생성자 호출 중..."<<endl<<endl;
	LinkedList lp;

	cout << "멈추기용 페이크 정보 받는중. 1 입력후 엔터 ㄱㄱ"<<endl;
	cin >> cin_fake_info;

	cout << "add_before_tail을 이용해 파일에서 정보를 읽고 노드를 구성하는중.."<<endl<<endl;
	while(1){
		if(in.eof())
			break;
		in.getline(temp,sizeof(temp));
		lp.add_before_tail(temp);
	}
	cout << "멈추기용 페이크 정보 받는중. 1 입력후 엔터 ㄱㄱ"<<endl;
	cin >> cin_fake_info;

	cout << "display()함수 작동중" << endl;
	lp.display();
	cout << "멈추기용 페이크 정보 받는중. 1 입력후 엔터 ㄱㄱ"<<endl;
	cin >> cin_fake_info;

	string temp_location = "전통예술고등학교";
	HighSchoolNode tempNodeInfo;
	cout << "전통예술고등학교 노드를 찾는 중...(3번째 학교 정보)"<<endl;
	lp.search(temp_location,tempNodeInfo);
	cout << "노드 정보 출력-"<<endl;
	showNode(tempNodeInfo);

	cout << "멈추기용 페이크 정보 받는중. 1 입력후 엔터 ㄱㄱ"<<endl;
	cin >> cin_fake_info;

	string temp_location2 = "명지고등학교";
	lp.delete_element_with_string(temp_location2);
	lp.display();
	cout << "잠신고등학교 노드(뒤에서 두번째)를 삭제했습니다." << endl;


	cout << "멈추기용 페이크 정보 받는중. 1 입력후 엔터 ㄱㄱ"<<endl;
	cin >> cin_fake_info;

	cout << "여기까지오다니...도전과제 함수 코드를 작성하세요..."<<endl;
	cin >> cin_fake_info;
}

void showNode(const HighSchoolNode & data){
	cout << "main.c의 showNode함수 작동중.."<<endl;
	size_t i;
	for(i=0;i<MAX_STR;i++)
		cout << data.str[i] << "  ";
	for(i=0;i<MAX_NUMBER;i++)
		cout << data.n[i] << " ";
	cout << endl;
}
