#include<iostream>

using namespace std;

int main(){
    struct informasi
    {
        int angka;
        string kata;
        char huruf[1];
    }info;

    cout << "a. Masukkan sebuah huruf = ";
    cin >> info.huruf;
    cout << "b. Masukkan sebuah kata = ";
    cin >> info.kata;
    cout << "c. Masukkan sebuah angka = ";
    cin >> info.angka;

     cout << "d. Huruf yang Anda masukan adalah = " << info.huruf << endl;
     cout << "e. kata yang Anda masukan adalah = " << info.kata<< endl;
     cout << "f. angka yang Anda masukan adalah = " << info.angka << endl;
    return 0;
}