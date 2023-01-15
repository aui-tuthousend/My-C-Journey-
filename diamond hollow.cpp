#include<iostream>
using namespace std;

main()
{
	int n, var;
	
	cout<<"Masukkan jumlah bintang: ";
	cin>>n;
	cout<<"\n";
	
	if (n<=0 || !n>>var)
		cout<<"Nek ngelebokno seng nggenah su";
		
	for (int i=0; i<n; i++)
	{
		for(int j=0; j<(2*n); j++)
		{
			if (i+j <= n-1) //segitiga atas kiri
				cout<<"*";
			else
				cout<<" ";
			
			if ((i+n) <= j) //segitiga atas kanan
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<endl;
	}
	
	for (int i = 0; i<n; i++)
	{
		for (int j=0; j<(2*n); j++)
		{
			if(i>=j) //segitiga bawah kiri
				cout<<"*";
			else
				cout<<" ";
			
			if(i>=(2*n-1)-j) //segitiga bawah kanan
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<endl;
	}
}


