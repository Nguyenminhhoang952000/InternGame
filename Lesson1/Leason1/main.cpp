#include<iostream>
using namespace std;
//truyen con tro
void swap1(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
//truyen tham chieu
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
	//truyen tham tro
	swap1(&a, &b);
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	//truyen tham chieu
	swap2(a, b);
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;


}
