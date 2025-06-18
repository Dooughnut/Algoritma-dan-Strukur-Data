#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

// write the definition (body) of the queue here using struct and array
// the elements of the queue are char
 
struct Queue {
    int Front, Rear, size;
    int Q[MAX];
}antrian;

// write the function to implement all the operation needed
// enqueue, dequeue, isEmpty, isFull, display, reset, init
int isEmpty(){
    if (antrian.Front == antrian.Rear){
        return 1;}
    else{
        return 0;
    }
}

int isFull(){
    if ((antrian.Rear + 1) % antrian.size == antrian.Front) {
        return 1;}
    else{
        return 0;
    }
}

void INSERT(int x){
    if (isFull() == 1){
        cout << "Queue Penuh" << endl;
}
    else{
        antrian.Q[antrian.Rear] = x;
        cout << "Data: " << antrian.Q[antrian.Rear] << " Masuk ke dalam Queue " << endl;
        antrian.Rear = (antrian.Rear + 1) % antrian.size;
    }
}

void DELETE(){
    if (isEmpty() == 1){
        cout << "Queue kosong" << endl;
    }
    else{
        cout << "Data yang dihapus: " << antrian.Q[antrian.Front] << endl;
        antrian.Front = (antrian.Front + 1) % antrian.size;
    }
}

void CETAKLAYAR(){
    if(isEmpty()==1){
        cout << "Queue kosong" << endl;
    } else {
        int i = antrian.Front;
        while(i != antrian.Rear){
            cout << "Queue ke " << i << " = " << antrian.Q[i] << endl;
            i = (i + 1) % antrian.size;
        }
    }
}

void RESET(){
    antrian.Front = 0;
    antrian.Rear = 0;
    cout << "Queue telah di-reset" << endl;
}

void Inisialisasi(){
    antrian.Front = 0;
    antrian.Rear = 0;
    antrian.size = MAX; 
}

int PIL;
char PILIHAN[2];
// write the menu function in main scope
// to insert, delete, display, reset, exit

int main(){
    Inisialisasi();
    do{
        cout << "\nQUEUE" << endl;
        cout << "==============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET QUEUE" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);
        switch (PIL)
        {
        case 1:
            int x;
            cout << "Masukkan Nilai: "; cin >> x;
            INSERT(x);
            break;
        
        case 2:
            DELETE();
            break;
            
        case 3:
            CETAKLAYAR();
            break;
        
        case 4:
            RESET();
            break;
        
        default:
            cout << "TERIMA KASIH" << endl;
            break;
        }
        cout << "Tekan tombol apa saja untuk melanjutkan";
        getch();
        system("cls");
    }
    while (PIL < 5);

    return 0;
}