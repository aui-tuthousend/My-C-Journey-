#include <iostream>
#include "printpattern.h"
using namespace std;

int main()
{
	int n;
	cout<<"masukkan nilai= ";
	cin>> n;
	cout<<endl;
	char kata[n+7] = {'B', 'A', 'S', 'P', 'R', 'O', 'G'};
	char katadua[n+7] = {'G', 'O', 'R', 'P', 'S', 'A', 'B'};

	printPattern(n, kata, katadua);
	return 0;
}

