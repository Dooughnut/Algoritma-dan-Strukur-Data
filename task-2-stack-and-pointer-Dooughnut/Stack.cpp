#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

// write the definition (body) of the stack here using struct and array
// the elements of the stack are integers
struct Stack {
    int top;
    int data[MAX];  
}stacking;

// write the function to implement all the operation needed
// push, pop, isEmpty, isFull, display, reset, init
int kosong(){
    if (stacking.top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int penuh(){
    if (stacking.top == MAX-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void input(int value){
    if (kosong()==1){
        stacking.top++;
        stacking.data[stacking.top] = value;
        cout << "Data " << stacking.data[stacking.top]
             << " Masuk ke Stack " << endl;
    }
    else if (penuh()==0){
        stacking.top++;
        stacking.data[stacking.top] = value;
        cout << "Data " << stacking.data[stacking.top]
             << " Masuk ke Stack " << endl;        
    }
    else {
        cout << "tumpukan Penuh" << endl;
    }
}

void hapus(){
    if (kosong()==0){
        cout << "Data Teratas Sudah Terambil" << endl;
        stacking.top--;
    }
    else {
        cout << "Data Kosong" << endl;
    }
}

void tampil(){
    if (kosong()==0){
        for(int i = stacking.top; i >= 0; i--){
            cout << "\ntumpukan Ke " << i << " = " << stacking.data[i];
        }
        cout << endl;
    }
    else {
        cout << "tumpukan Kosong" << endl;
    }
}

void bersih(){
    stacking.top = -1;
    cout << "tumpukan Kosong !" << endl;
}

int ch;
char choice[2];
void init(){
    stacking.top = -1;
}

// write the menu function in main scope
// to insert, delete, display, reset, exit
int main(){
    init();
    do{
        cout << "\nSTACK" << endl;
        cout << "==============" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. CETAK STACK" << endl;
        cout << "4. BERSIHKAN STACK" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; cin >> choice;
        ch = atoi(choice);
        switch (ch)
        {
        case 1:
            int value;
            cout << "Masukkan Nilai: "; cin >> value;
            input(value);
            break;
        
        case 2:
            hapus();
            break;
            
        case 3:
            tampil();
            break;

        case 4:            
            bersih();
            break;
        
        default:
            cout << "TERIMA KASIH" << endl;
            break;
        }
        cout << "Tekan tombol apa saja untuk melanjutkan";
        getch();
        system("cls");
    }
    while (ch < 5);    
    
    return 0;
}