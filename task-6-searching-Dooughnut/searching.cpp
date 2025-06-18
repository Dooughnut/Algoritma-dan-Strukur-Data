#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void sequentialSearch(const vector<int> &nums, int target){//nums menunjukkan random number yg digenerate sedangkan target ya number yg mau dicari. parameter nums digunakan menggunakan vector untuk mempermudah mengukur isi dari random num. 
    vector<int> save; //menggunakan parameter vector untuk mempermudah mengukur berapa indeks yang disimpan 
  
    for (auto i = 0; i < nums.size(); i++){
        if (nums[i] == target) save.push_back(i); //menyimpan num yang dicari kedalam barisan vector lalu mengembalikan indeks dari target, dengan cara membandingkan satu persatu setiap num yang ada dengan target. dan jika ada, maka akan disimpan pada variabel integer save(?) 
    }

    if (save.empty()){//sistem boolean ngecek kosong apa ndak dari num yg dijadiin target
        cout << "Data yang anda cari tidak ditemukan!" << endl;
    }
    else{
        cout << "Data yang anda cari (" << target <<"), sebanyak " << save.size() << " ditemukan."<< endl;
        cout << "pada indeks ke-" ;
        for (auto i = 0; i < save.size(); i++){//simple loop untuk menampilkan data indeks sesuai dengan targetnya
            cout << save[i];
            if (i != save.size() - 1) cout << ", ";//kalau indeks masih blum kosong, maka bakal lanjut sampai habis
        }
        cout << "." << endl;
    } 
}

void binarySearch(const vector<int> &nums, int target){
    auto kiri = lower_bound(nums.begin(), nums.end(), target);//digunakan untuk mencari nilai value lebih kecil sama dengan dari value target dari section elemen pertama hingga terakhir.   
    auto kanan = upper_bound(nums.begin(), nums.end(), target);//digunakan untuk mencari nilai value lebih besar sama dengan dari value target dari section elemen pertama hingga terakhir.
    //dua diatas ini iterator      
    vector<int> tengah;//sebagai save-savean (hasil akhir(target)) dari pencarian binary search

    if (kiri != nums.end() && *kiri == target) {// disini "kiri" dibuat menajdi patokan untuk mencari targetnya. kiri != nums.end() digunakan untuk kiri ngecek apakah target ditemukan didalam vector (sama dengan atau lebih besar) karna jikalau kiri == nums.end() maka seluruh random number yg ada jadi lebih besar valuenya dari target. lalu kiri di dereferencingkan menjadi pointer dan mengambil value target agar kiri dapat dengan jelas untuk ngecek apakah target bener2 ada pada vector. 
        for (auto i = kiri; i != kanan; i++){//karna tadinya kiri di dereferencing, maka ini mengecek apakah target terdapat lebih dari satu pada nums, dan jika ia maka i++
            tengah.push_back(distance(nums.begin(), i));//mengembalikan value indeks target ke tengah dnegan menghitung dari banyak target ditemukan dari awal hingga akhir operasi
        }
    }
    if (tengah.empty()){//boolean untuk menentukan isinya tengah ni kosong apa ndak.
        cout<<"angka "<< target <<" tidak ditemukan!";
    } else {
        cout << "angka "<< target <<" ditemukan pada indeks: ";
        for (auto i = 0; i < tengah.size(); i++){//simple loop untuk menampilkan data indeks sesuai dengan targetnya
            cout << tengah[i];
            if (i != tengah.size() - 1) cout << ", ";//kalau indeks masih blum kosong, maka bakal lanjut sampai habis
        }
        cout<< "." <<endl;
    }
}

void clearScreen(){
    system("cls");
}

void explain(){

    cout<< "Sequential Search atau Linear Search adalah algoritma pencarian sederhana yang cara kerjanya sama seperti namanya sendiri, yaitu dengan cara membandingkan target value dengan keseluruhan data secara linear dari awal hingga akhir." << endl << "Advantage dari pemakaian algoritma ini ialah:" << endl <<"- Sistam algoritma yang sederhana dan mudah diimplementasikan "<< endl <<"- Pemakaian algoritma tidak perlu pada data yang telah tersortir" << endl <<"- Penggunaan yang cocok pada dataset sedikit" << endl << endl <<"Disadvantage dari pemakaian algoritma ini ialah: "<< endl <<"- Sistem algoritma yang kurang efisien, prosesnya memerlukan Waktu yang lama tergantung seberapa banyak dataset."<< endl << endl <<"Pada kompleksitas Waktu, best case scenario pada Sequential Search ialah O(1) sedangkan worst scenarionya ialah O(n). untuk kompleksitas ruangnya ialah O(1)."<< endl;

    cout<<"==============================================================================================================="<<endl;

    cout<<"Binary Search adalah algoritma pencarian yang cara kerjanya ialah dengan metode rekursif, melakukan operasinya dengan cara membandingkan target dengan indeks elemen ditengah array yang telah tersortir. Dan jika elemen indeks ditengah merupakan elemen yang dicari maka algoritma telah selesai. Dan jika elemen ditengah bukan yang dicari, maka algoritma akan memotong array menjadi dua bagian yaitu kiri dan kanan. jika elemen tengah lebih kecil dari pada target, maka algoritma akan melanjutkan pencarian pada sisi kanan dan jika sebaliknya maka pencarian akan dilanjutkan ke sisi kiri. Sistem ini akan diulang hingga elemen yang dicari telah didapatkan."<<endl<<"advantage dari pemakaian algoritma ini ialah:"<<endl<<"- Cocok pada penggunaan dataset besar"<<endl<<"- Mudah diterapkan"<<endl<<endl<<"Disadvantage dari pemakaian algoritma ini ialah:"<<endl<<"- Memerlukan dataset yang sudah terurut"<<endl<<"- Hanya dapat digunakan untuk struktur data yang memiliki dua arah gerak"<<endl<<endl<<"Pada kompleksitas Waktu, best case scenario pada binary search ialah O(1) sedangkan worst scenarionya ialah O(log n). untuk kompleksitas ruangnya ialah O(1)."<<endl;
}


int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                cout << "Generating 100 numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl << "Masukkan angka yang ingin dicari: "; cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                sort(nums.begin(), nums.end());// fungsi yang digunakan untuk sorting random numbernya

                cout << "Generating " << size <<" numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }

                cout << endl << "Masukkan angka yang ingin dicari: "; cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Programme was made by afrian pradipta rizky (2410817210028)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}