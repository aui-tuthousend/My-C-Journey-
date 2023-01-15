#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;


//fungsi mengubah sebuah integer ke char dalam bentuk '*'
int inputPin()
{
	int input_pin = 0;
	char input = '\0'; //'\0' bermakna break;
	int j = 0;
	char buff_input[5]; //disini buff input adalah array, buff berarti buffer
	while (1) { //ketika j bernilai 1
		input = (char) getch(); //maka ia akan diubah ke variabel input yang bertipe data char
		cout << "*"; //lalu setiap char yang diinput akan diubah ke '*'
		buff_input[j] = input; //yang di input di variable input akan masuk ke array buff_input
		j++; //penambahan nilai setiap input yang dimasukkan
		
		if (j>3) {
			input_pin = atoi(buff_input); 
			break;
		}
	}
	
	return input_pin;
}

int main()
{
	int menu;
	int pin = 2211;
	long int saldo = 500000, nominal;
	printf("\n\t[----*ATM*----]\n");
	cout<<"\n\tMasukkan Pin: ";
	pin = inputPin();
	
	
	//proses pemasukan pin
	//jika user memasukkan pin yang salah maka nilai i akan bertamah 1
	for (int i=0; (pin!=2211); i++)
	{	
		
		//jika pin pertama salah maka:
		if (i == 1)
		{
			system("cls");
			system("color 4");
			cout << "\n\t[Wrong PIN!!!] \n";
			cout << "\n\t[You only have 2 attempt] \n";
			cout << "\n\t Please enter your pin: ";
			pin = inputPin();
			system("cls");
			
		}
		//jika pin kedua salah maka:
		else if(i == 2)
		{
			system("cls");
			cout << "\n\t[Wrong PIN!!!] \n";
			cout << "\n\t[You only have 1 attempt] \n";
			cout << "\n\t Please enter your pin: ";
			pin = inputPin();
			system("cls");
			
		}
		//jika pin ketiga salah maka nilai i akan berjumlah 3 dan akan exit program.
		else if(i == 3)
		{
			system("cls");
			cout << "\n\t[Sorry We Couldn't Access Your ATM!] \n";
			exit(0);
		}
	}
	
	//jika pin benar maka:
	while (pin == 2211)
	{
		system("cls");
		system("color 7");
		cout<<"\n\tPilihan Menu: "<<endl;
		cout<<"\n\t1. Saldo anda"<<endl;
		cout<<"\n\t2. Tarik tunai"<<endl;
		cout<<"\n\t0. Exit"<<endl<<endl;
		cout<<"\n\tPilih Menu: ";
		cin>>menu;
		system("cls");
		
		//masuk ke opsi menu
		switch(menu)
		{
			case 1:
				system("cls");
				cout<<"\n\tSisa saldo anda adalah Rp."<<saldo<<endl;
				break;
			case 2:
				cout<<"\n\tJumlah nominal harus berupa ratusan rupiah!"<<endl<<endl;
				cout<<"\n\tBatas penarikan saldo: Rp 700.000"<<endl;
				cout<<"\n\tMasukkan Nominal: "<<endl;
				cout<<"\n\t";
				cin>>nominal;
				
				if(nominal !=100000  && nominal !=200000 && nominal !=300000 && nominal !=400000 && nominal !=500000 && nominal !=600000 && nominal !=700000 )
				{
					system("cls");
					cout<<"\n\tNominal Tidak sesuai!"<<endl;
					cout<<"\n\tJumlah Penarikan Harus Kelipatan Rp 100.000!"<<endl;
					nominal * 1;
					break;
				}
				if(nominal<=saldo)
				{
					system("cls");
					saldo-=nominal;
					cout<<"\n\tSilahkan cek kembali uang anda!"<<endl;
					cout<<"\n\tSisa saldo anda Rp."<<saldo<<endl;
					break;
				}
				else
				{
					system("cls");
					cout<<"\n\tSaldo tidak cukup!"<<endl;
				}
				break;
			case 0:
				cout<<"\n\tTerimakasih Telah Menggunakan ATM!"<<endl;
				exit(0);
				
				break;
			default:
				cout<<"\n\tMenu tidak tersedia!"<<endl;
				break;
		} 
		
		//memberi opsi pertanyaan kepada user apakah user ingin melakukan transaksi lain
		perulangan:
		char ulang;
		cout<<"\n\n\tApakah anda ingin melakukan transaksi lagi?"<<endl;
		cout<<"\n\tKetik [y] untuk iya"<<endl;
		cout<<"\n\tKetik [t] untuk tidak"<<endl;
		cout<<"\n\t";
		cin>>ulang;
		
		switch (ulang)
		{
			//jika user memasukkan 'y' maka program akan mengulang dari looping while pin=2211
			case 'y':
				pin == 2211;
				break;
			//jika user memasukkan 't' maka akan exit program
			case 't':
				system("cls");
				cout<<"\n\tTerimakasih Telah Menggunakan ATM!"<<endl;
				exit(0);
				break;

			default:
				system("cls");
				cout<<"\n\tOpsi Tidak Tersedia!"<<endl;
				
				goto perulangan;
				cout<<"\n\t";
				cin>>ulang;
				
			while (ulang != 't' && ulang != 'y')
			{
				cout<<"\n\tOpsi Tidak Tersedia!"<<endl;
				goto perulangan;
			}
		}

	} 	
}
