#include <iostream>
using namespace std;

#include "Analyze.h"

int main(void){
	TotalInfo info;
	initPasswordInfo(&info);
	savePasswordInfo(&info);
	showPasswordInfo(info);
	fileSavePasswordInfo(info);
	filesSavePasswordInfo_total(info);
	cin.get();
	return 0;
}
