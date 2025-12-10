#include <iostream>
using namespace std;

int main() {
	int N;
	int a,b;
	int kq;
	cin >> N;
	cin >> a >> b;
	if (b >= a * 2) {
		kq = a * N;
	} else {
		kq = (N/2) * b + (N%2) * a;
	}
	
	cout << kq;
	return 0;
}
