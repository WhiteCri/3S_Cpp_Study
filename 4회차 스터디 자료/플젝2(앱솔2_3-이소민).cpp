#include <iostream>
using namespace std;

int main()
{
	int dollar;
	int coupon;
	int chocolate = 0;

	cin >> dollar;
	chocolate += dollar; // 달러로 살 수 있는 초콜렛

	coupon = chocolate;
	while (coupon > 7) // 쿠폰으로 바꿀수 있는 초콜렛
	{
		coupon = coupon - 7;
		chocolate = chocolate + 1;
		coupon = coupon + 1;
	}

	cout << "살 수 있는 초콜렛은 " << chocolate << "개, 남은 쿠폰은 " << coupon <<"개" << endl;
	return 0;
}