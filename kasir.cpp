#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <fstream>
#include "history.h"
using namespace std;

void menu() {
		cout<<"\n\t  ===================================\n"
		<<"\to|SELAMAT DATANG DI TOKO SEMBAKO JOKO|o\n"
			<<"\t  ===================================\n"
			<<"\n\t   Daftar barang\n"
			<<"\t  ==========================================="
			<<"\n\to| minyak ||  mie || gula ||  beras || garam |o\n"
			<<"\t  ==========================================="
			<<"\n\to| 20.000 || 3000 || 7000 || 25.000 || 2000  |o\n"
			<<"\t  ==========================================="
			<<"\n\t   Masukkan nama barang: ";
}


int cariBarang(string arr[], string cetak[], int size, string nama) {
	int index = -1;
	for (int i=0, j=-1; i<size; i++) {
		if (arr[i]==nama) {
			index = i;
			cetak[j] = arr[i];
	
			j++;
		}
	}
	
	if (index == -1) {
//		index = 7;
		system("cls");
		cout<<"\tbarang tidak ditemukan! "<<endl;
	}
	return index;
}

int main() {
	string printbarang[10];
	int tempjumlah[10];
	string barang[5] = {"minyak", "mie", "gula", "beras", "garam"};
	int harga[5] = {20000, 3000, 7000, 25000, 2000};
	string tempbarang[13]; string cetakBarang[10];
	char loop;
	int proses, index3, uang, susuk;
	int total = 0;
	int proses1;
	int struk=1;
	int jumlahstruk[13]; int arrtemp[13];
	

	for (int i=0; i<20; i++){
		menu();
		cin>>tempbarang[i];
		
		int index = cariBarang(barang, cetakBarang, 5, tempbarang[i]);
		while (index == -1) {
			menu();
			cin>>tempbarang[i];
			index = cariBarang(barang, cetakBarang, 5, tempbarang[i]);
		}
		
		cout<<"\n\tJumlah yang ingin anda beli: ";
		cin>>tempjumlah[i];
		
		jumlahstruk[i]=harga[index]*tempjumlah[i];
		cout<<"\n\tHarga "<<barang[index]<<": "<<harga[index]<<endl;

		cout<<"\t o> "<<jumlahstruk[i];
		total += jumlahstruk[i];

		cout<<"\n\n\tApakah anda ingin membeli barang lain (y/t)";
		cin>>loop;
		switch (loop) {
			
			case 't':
				system("cls");
				cout<<"\n\tTotal harga belanjaan anda: "<<total;
				
				while(1) {
					cout<<"\n\tInput nominal uang anda: ";
					cin>>uang;
				
					if (uang >= total){
						system("cls");
					cout<<"\n\n\t     -[STRUK BELANJA ANDA]-\n"
						<<"\t  ----------------------------  \n"
						<<"\t   QTY  ITEM            HARGA\n"
						<<"\t  ----------------------------  \n";
					for(int i=0; i<struk; i++) {
						cout<<"\t   0"<<tempjumlah[i]<<"   "<<tempbarang[i]
							<<setw(18)
							<<jumlahstruk[i]<<endl;
					}
					cout<<"\t  ----------------------------  \n"
						<<"\t   Total                "<<total
						<<"\n\t   Tunai                "<<uang
						<<"\n\t  ----------------------------";
					susuk = uang-total;
					if (susuk!=0) {
						cout<<"\n\t  Kembalian anda: "<<susuk;
					}
					cout<<"\n\t  Terimakasih telah berbelanja!\n\n";
					history(tempbarang, tempjumlah);
					exit(0);
					}
					else
						system("cls");
						cout<<"\n\tMaaf uang anda tidak cukup\n";
						cout<<"\n\tTotal harga belanjaan anda: "<<total;
						continue;
						break;
				}
				
				
			case 'y':
				struk++;
				system("cls");
				break;
			default:
				cout<<"\n\tInput salah!";
		}		
	}
}
