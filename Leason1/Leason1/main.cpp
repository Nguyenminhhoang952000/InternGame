#include<iostream>
using namespace std;
//truyen tham chieu
void swap1(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
//truyen tham tri
void swap2(int& x, int& y) {
	int temp = x;
	x = y;
	x = temp;
}
int main() {
	int a, b;
	cout << "Nhap a: ";
	cin >> a;
	cout << "\nNhap b: ";
	cin >> b;
	//truyen tham chieu
	swap1(&a, &b);
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	//truyen tham tri
	swap2(a, b);
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;


}