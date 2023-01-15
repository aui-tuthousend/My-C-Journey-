#include <iostream>
using namespace std;
void printPattern(int n, char kata[], char katadua[])
{
	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {
			//untuk garis kiri atas ke bawah kanan
			if (j == i) {
				cout <<" "<<kata[i-1];
			}
			//untuk garis kiri bawah ke atas kanan
			else if (j == (n + 1 - i)) {
				cout <<" "<<katadua[i-1];
			//spacing
			}
			else {
				cout << " -";	
			}
		}
		cout << endl;
	}
}
