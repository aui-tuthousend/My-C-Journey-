#include <iostream>
#include <cstdlib>

using namespace std;
void gambarJanjarGenjang(int num_pat) {
	num_pat = abs(num_pat);	
    int flag_awal = 0;
    for (int i = 0; i < num_pat; i++) {
        // spacing
        for (int space = num_pat; space > i; space--) {
            cout << " ";
        }
        // spacing awal + bintang luar
        if (i < num_pat -1) cout << "*";
        if (flag_awal == 0) {
            flag_awal = 1;
            for (int bAwal = 0; bAwal < num_pat - 1; bAwal++) {
                cout << "*";
            }
        } else {
            if (i < num_pat -1) { 
                for (int bAwal = 0; bAwal < num_pat - 2; bAwal++) {
                    cout << " ";
                }
                if (flag_awal == 1) cout << "*";
            }
        }
        if (i < num_pat -1) cout << "\n";
        else {
            for (int bAwal = 0; bAwal < num_pat; bAwal++) {
                cout << "*";
            }
        }
    }

}
int main() {
	int input, num_pat;
	
	cout << "energen kukubima paswordnya? : ";
	cin >> input;
	
	
	cout << "input bintang : ";
	cin >> num_pat;
	
	if (input == 1) {
		gambarJanjarGenjang(num_pat);
	}
	
	
	return 0;
}
