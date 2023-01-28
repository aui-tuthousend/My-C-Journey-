#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

using namespace std;
int input_pin = 0;
string namaMember [10][1];
int passMember [10][1];
int billing[10][1];
int totalMember = 1;

int cariMember(string tempMember) {
	int index = -1;
	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			if (namaMember[j][i]==tempMember) {
//				cout<<j<<" "<<i;
				index = j;
//				index2 = i;
//				break;
			}
			
//			else
//				cout<<"\n\t Member tidak ditemukan!";
//				break;
		}
	}
	return index;
}

int cariMember2(string tempMember) {
	int index2 = -1;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			if (namaMember[j][i]==tempMember) {
				index2 = i;
			}
		}
	}
	return index2;
}

int cariMember3(string tempMember) {
	int index3;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			if (namaMember[j][i]==tempMember) {
				index3 = -1;
			}
		}
	}
	return index3;
}

void menu() {
	cout<<"\n\t  +o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o+"
		<<"\n\t  |Selamat Datang di Warnet Joko Tinker!|"
		<<"\n\t  +o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o-o+"
		<<"\n\t  | Pilihan Menu:                       |"
		<<"\n\t  | [1]. Register Member                |"
		<<"\n\t  | [2]. Tambah Billing                 |"
		<<"\n\t  | [3]. Cek Billing                    |"
		<<"\n\t  | [4]. Exit                           |"
		<<"\n\t  |_____________________________________|"
		<<"\n\t  Pilih Menu: ";

	
}

void daftar() {
	cout<<"\n\tOo_________________________________________________oO"
		<<"\n\t|                 [Pilihan Member]                  |"
		<<"\n\t|---------------------------------------------------|"
		<<"\n\t|  No | Jenis |               Harga                 |"
		<<"\n\t|---------------------------------------------------|"
		<<"\n\t|  1  |  VIP  |          Rp.4000 per jam            |"
		<<"\n\t|  2  |  VvIP |          Rp.5000 per jam            |"
		<<"\n\to---------------------------------------------------o"
		<<"\n\tPilih Jenis Member: ";
}


int inputPin() {
	char input = '\0'; 
	int j = 0;
	char buff_input[7]; 
	while (1) { 
		input = (char) getch(); 
		cout << "*"; 
		buff_input[j] = input; 
		j++; 
		
		if (j>5) {
			input_pin = atoi(buff_input); 
			break;
		}
	}
	
	return input_pin;
}

int main () {
	int pilih, pilihJenis;
	int x = 0; int y = 0;
//	int index2 = -1;
	char input, ulang;
	string tempMember;
	do {
		system("cls");
//		cout<<namaMember[0][0]; cout<<namaMember[0][1];
		menu();
		cin>>pilih;
		switch (pilih) {
			case 1: {
				string nama1;
				int jumlah;
				system("cls");
				daftar();
				cin>>pilihJenis;
				if(pilihJenis==1){
					cout<<"\n\n\t [MEMBER VIP]"
						<<"\n\n\t (Minimal 6 huruf/karakter)"
						<<"\n\t Masukkan nama member: ";
					cin>>nama1;
					jumlah = nama1.length();
					if (jumlah<6){
						cout<<"\n\tNama member minimal 6 huruf/karakter";
						break;
					}
					int index3 = cariMember3 (nama1);
					if(index3 == -1){
						cout<<"\n\tUsername telah digunakan";
						break;
					}
					namaMember[x][0] = nama1;
					cout<<"\n\t (Pin Harus berupa 6 angka)"
						<<"\n\t Masukkan pin: ";
					passMember[x][0] = inputPin();
					passMember[x][0] = input_pin;
					x++;
//					totalMember++;
					break;
				}
			
				else if(pilihJenis==2){
					string nama2;
					int jumlah;
					cout<<"\n\n\t [MEMBER VvIP]"
						<<"\n\n\t (Minimal 6 huruf/karakter)"
						<<"\n\t Masukkan nama member: ";
					cin>>nama2;
					jumlah = nama2.length();
					if (jumlah<6){
						cout<<"\n\tNama member minimal 6 huruf/karakter";
						break;
					}
					int index3 = cariMember3 (nama2);
					if(index3 == -1){
						cout<<"\n\tUsername telah digunakan";
						break;
					}
					namaMember[y][1] = nama2;
					cout<<"\n\t (Pin Harus berupa 6 angka)"
						<<"\n\t Masukkan pin: ";
					passMember[y][1] = inputPin();
					passMember[y][1] = input_pin;
					y++;
//					totalMember++;
				}
				else {
					cout<<"\n\tJenis member tidak ada";
				}
				break;
			}
			case 2: {
				int harga; string member;
				if(x==0 && y==0) {
					cout<<"\n\tBelum ada member yang terdaftar";
					break;
				}
				cout<<"\n\tMasukkan nama member: ";
				cin>>tempMember;
				int index = cariMember(tempMember);
				int index2 = cariMember2(tempMember);
				if(index == -1|| index2 == -1) {
					cout<<"\n\tMember tidak ditemukan!";
					break;
				}
				if (index2 == 0)
					member = "VIP (4k/jam)";
				else if (index2 == 1)
					member = "VvIP (5k/jam)";
				cout<<"\n\tMember "<<member;
				cout<<"\n\tInput jumlah jam yang ingin anda tambah: ";
//				cout<<index<<" "<<index2;
				cin>>billing[index][index2];
				harga = billing[index][index2] * (index2+4);
				cout<<"\n\tTotal harga : "<<harga<<'k';
				
				break;
			}
			case 3: {
				string member;
				if(x==0 && y==0) {
					cout<<"\n\tBelum ada member yang terdaftar";
					break;
				}
				cout<<"\n\tMasukkan nama member: ";
				cin>>tempMember;
				int index = cariMember(tempMember);
				int index2 = cariMember2(tempMember);
				if(index == -1|| index2 == -1) {
					cout<<"\n\tMember tidak ditemukan!";
					break;
				}
				if (index2 == 0)
					member = "VIP";
				else if (index2 == 1)
					member = "VvIP";
				cout<<"\n\tNama member : "<<namaMember[index][index2]
					<<"\n\tJenis member : "<<member
					<<"\n\tSisa Billing yang tersisa : "<<billing[index][index2]<<" Jam";
				break;
			}
			case 4: {
				exit(0);
				break;
			}
			default : {
				cout<<"\n\tPilihan Menu tidak ada :D";
				break;
			}
		}
		cout<<"\n\n\tIngin Mengulang? [y/n] ";
		cin>>ulang;
	} while (ulang=='y');
}
