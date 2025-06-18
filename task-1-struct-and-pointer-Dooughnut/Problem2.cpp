#include<iostream>

using namespace std;

int main(){
    struct informasi
    {
        string plat= "DA1234MK";
        string kendaraan= "RUSH";
        string nama= "Andika Hartanto";
        string alamat= "Jl. kayutangi 1";
        string kota= "Banjarmasin";
        
    }info;
    
    cout<< "a. Plat Nomor Kendaraan : "<< info.plat <<endl;
    cout<< "b. Jenis Kendaraan : "<< info.kendaraan <<endl;
    cout<< "c. Nama Pemilik : "<< info.nama <<endl;
    cout<< "d. Alamat : "<< info.alamat <<endl;
    cout<< "e. Kota : "<< info.kota <<endl;

    return 0;
}