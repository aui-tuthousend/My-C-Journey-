#include <iostream>
using namespace std;

//note: ingat pointer adalah letak memori
int main () {
	//pointer in multidimensions array
	int B[2][3];
	//aray B ini sama dengan "dua" 1-Dimensi array yang beranggotakan 3 integer
	//menyambungkan dengan pointer
	int (*p)[3] = B;
	//statement diatas (*p) sama dengan me-return pointer ke 1-D aray yang beranggotakan 3 integer
	
	//print B sama halnya dengan print &B[0]
	//print *B == B[0] == &B[0][0]
	
	//bagaimana jika print B+1 or &B[1] ... maka dia akan meng-output anggota pertama dari aray ke 2 dari sebuah 1-D aray / B[1][0]
	// bagaimana jika print *(B+1) sama halnya dengan B[1] == &B[1][0]
	//so what if *(B+1) + 2? = maka akan meng-output anggota ke 3 dari aray ke-2
	//statement diatas == *(B+1)+2 == B[1]+2 == &B[1][2]
	
	//what if *(*B+1)??  pertama kita lihat *B bermakna B[0] dan +1 brarti melangkah ke anggota ke-2 dari aray pertama
	//atau &B[0][1], dan '*' didepan akan me-ngdereference dari &B[0][1], maka akan menjadi B[0][1]
	// -> *(*B+1) == *(B[0]+1) == *(&B[0][1]) == B[0][1]
	
	//B[i][j] = *(B[i] + j)
	//        = *(*(B+i) + j) sama dengan baris code nomor 19
}
