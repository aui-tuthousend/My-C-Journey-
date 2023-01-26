#include <iostream>
using namespace std;

void menu() {
	cout<<"MENU :\n"
		<<"1. Menghitung Volume Balok\n"
		<<"2. Lihat Hasil 	Volume Balok\n"
		<<"3. Menghitung Volume Kubus\n"
		<<"4. Lihat Hasil Volume kubus\n"
		<<"5. Penjumlahan Volume\n";
}

int volBalok(int jumlahBalok, int pbalok[], int lbalok[], int tbalok[], int vbalok[]) {
	for (int i=0; i<jumlahBalok; i++) {
		cout<<"\nVolume Balok "<<i+1<<":\n\n"
			<<"Masukkan Panjang : ";
		cin>>pbalok[i];
		cout<<"Masukkan Lebar : ";
		cin>>lbalok[i];
		cout<<"Masukkan Tinggi : ";
		cin>>tbalok[i];
		
		vbalok[i] = pbalok[i]*lbalok[i]*tbalok[i];
	}
	
}

int main() {
	int menyu, jumlahBalok, jumlahKubus;
	int dec = -1; int dec2 = -1;
	char lanjut;
	int panjangBalok[10];
	int lebarBalok[10];
	int tinggiBalok[10];
	int volumeBalok[10];
	int sisiKubus[10];
	int volumeKubus[10];
	do {
		system("cls");
		menu();
		cout<<"Masukkan Pilihan : "; cin>>menyu;
		switch (menyu) {
			case 1:
				cout<<"\nmasukkan berapa banyak volume balok yang akan dihitung : ";
				cin>> jumlahBalok;
				volBalok(jumlahBalok, panjangBalok, lebarBalok, tinggiBalok, volumeBalok);
				dec++;
				break;
			case 2:
				if (dec==-1) {
					cout<<"\nAnda Belum Menginput Volume Balok\n";
					break;
				}
				for (int i=0; i<jumlahBalok; i++) {
					cout<<"\nVolume Balok "<<i+1<<" : "<<volumeBalok[i]<<endl;
				}
				break;
			case 3:
				cout<<"\nmasukkan berapa banyak volume Kubus yang akan dihitung : ";
				cin>>jumlahKubus;
				for (int i=0; i<jumlahKubus; i++) {
					int tempSisi;
					cout<<"\nVolume Kubus "<<i+1<<":\n\n"
						<<"Masukkan Sisi : ";
					cin>>tempSisi;
					volumeKubus[i] = tempSisi*tempSisi*tempSisi;
					dec2++;				
				}
				break;
			case 4:
				if (dec2==-1 ) {
					cout<<"\nAnda Belum Menginput Volume Balok\n";
					break;
				}
				for (int i=0; i<jumlahKubus; i++) {
					cout<<"\nVolume Kubus "<<i+1<<" : "<<volumeKubus[i]<<endl;
				}
				break;
			case 5:
				if (dec==-1 || dec2==-1 ) {
					cout<<"\nAnda Belum Menginput Volume Kubus / Volume Balok\n";
					break;
				}
				int temp, temp2, hasil;
				for (int i=0; i<jumlahBalok; i++)
					cout<<"\nVolume Balok "<<i+1<<" : "<<volumeBalok[i];
					
				cout<<endl;
				for (int j=0; j<jumlahKubus; j++)
					cout<<"\nVolume Kubus "<<j+1<<" : "<<volumeKubus[j];
				
				cout<<"\n\nPilih volume Balok ke : ";
				cin>>temp;
				
				if(temp>dec+1) {
					cout<<"Index tidak ada!";
					break;
				}
				
				cout<<"Pilih Volume Kubus ke : ";
				cin>>temp2;
				
				if(temp2>dec2+1) {
					cout<<"Index tidak ada!";
					break;
				}
				
				hasil = volumeBalok[temp-1] + volumeKubus[temp2-1];
				cout<<"\nHasil Penjumlahan : "<<hasil<<endl;
			default:
				cout<<"\nPilihan Tidak Tersedia!";
				break;
		}
	
	cout<<"\nApakah Ingin Lanjut(y/n) : ";
	cin>>lanjut;
	
	} while (lanjut == 'y');
	
}
