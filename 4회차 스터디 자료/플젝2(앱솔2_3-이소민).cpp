#include <iostream>
using namespace std;

int main()
{
	int dollar;
	int coupon;
	int chocolate = 0;

	cin >> dollar;
	chocolate += dollar; // �޷��� �� �� �ִ� ���ݷ�

	coupon = chocolate;
	while (coupon > 7) // �������� �ٲܼ� �ִ� ���ݷ�
	{
		coupon = coupon - 7;
		chocolate = chocolate + 1;
		coupon = coupon + 1;
	}

	cout << "�� �� �ִ� ���ݷ��� " << chocolate << "��, ���� ������ " << coupon <<"��" << endl;
	return 0;
}