#include <iostream>
using namespace std;

//void poo (int *p) {
//	*p = (*p) + 1;
//}
void printArray(int (*arr)[3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main () {
//	int a = 10;
//	poo(&a);
//	cout<<a;

//	int A[5] = {2,3,4,5,6};
//	int *p;
//	p = A;
//	cout<<A<<endl;
//	cout<<*(A+2);

    int myArray[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int (*ptr)[3] = myArray;
    printArray(ptr, 2);
    
	int aray[5];
	int *poin = aray;
	
	//*(aray + i) == aray[i] 
	//(aray + i) == &aray[i]   

    return 0;

}
