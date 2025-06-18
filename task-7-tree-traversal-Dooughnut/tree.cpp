#include <iostream>
#include <conio.h>
#include <stdlib.h>
//to erase all comment, use //.* and replace all with space*
using namespace std;

struct Node { 
    int data; //variable yang menyimpan data
    Node *left; //pointer yang memanggil ulang struct yang mana berisikan variable yang menyimpan data 
    Node *right;
};

void insert(Node **root, int newData){ //fungsi memasukkan data 
	if (*root == nullptr){ //state pertama ketika pointer root kosong
		Node *newNode; //mendeklarasikan pointer baru newNode ke struct
		newNode = new Node; //mengalokasikan newNode ke memori dinamis sebesar data yang ada pada struct Node

		newNode -> data = newData; //mendeklarasikan value varable data yang = newData dengan cara mengakses variable data menggunakan pointer newNode
		newNode -> left = nullptr; //penggunaan nullptr daripada NULL ialah untuk mengindari ambiguitas. dari yg kupahami nullptr itu artinya alamatnya kosong sedangkan NULL saja itu = 0, jadi 0 itu lebih masuk ke tipe data integer or some... idfk 
		newNode -> right = nullptr; 

		*root = newNode; //memasukkan alamat newNode kedalam **root yang membuat keduanya terhubung

		cout << "Data has been added\n";
	}
	else if (newData < (*root) -> data){// jika data sudah ada dan datanya lebih kecil dari data yg sudah tersedia, maka akan dimasukkan ke root sebelah kiri
		insert(&((*root)->left), newData);
	}
	else if (newData > (*root) -> data){ // yang ini kesebelah kanan kalo datanya lebih besar dair yg data awal
		insert(&((*root)->right), newData);
	}
	else if (newData == (*root) -> data){ //jika memasukkan data yang sama, maka print"data-e wes ono"
		cout << "Data is already exist\n";
	}
}

void preOrder(Node *root){ //fungsi preorder, menampilkan data sesuai urutan dari root awal lalu ke kiri lalu kekanan
	if (root != nullptr){
		cout << root -> data << ' ';
		preOrder (root -> left);
		preOrder (root -> right);
	}
}

void inOrder(Node *root){ //fungsi inorder, menampilkan data mulai dari root paling kiri lalu ke root awal lalu barulah kekanan
	if (root != nullptr){
		inOrder (root -> left);
		cout << root -> data << ' ';
		inOrder (root -> right);
	}
}

void postOrder(Node *root){ //fungsi postorder, menampikkan data dari root kiri lalu ke root kanan melewati root utama. setelah root kanan habis barulah ke root utama
	if (root != nullptr){
		postOrder (root -> left);
		postOrder (root -> right);
		cout << root -> data <<' ';
	}
}

// side quest
void printTree(){

};

void freeTree(Node **root){ //membebaskan memori yang dialokasikan dan digunakan selama penggunaan program
	if (*root != nullptr) {
	freeTree(&((*root)->left)); //rekursif ngehapus root dikiri 
	freeTree(&((*root)->right));
	delete *root; //ini lah operator yang menghapus/membebaskan memori yang digunakan/alokasikan
	*root = nullptr; //deklarasikan state awal root ke nullptr
	}
}

int main(){
    int opt, val;
    Node *tree;
    tree = NULL;

    do {
    	system("cls");

	cout << "1. Insert\n";
	cout << "2. PreOrder\n";
	cout << "3. InOrder\n";
	cout << "4. PostOrder\n";
	cout << "5. clear\n";
	cout << "6. Exit\n";
	
	cout << "\nOption: "; cin >> opt;

	switch (opt) {

		case 1:
			cout << "\n Input:";
			cout << "\n ------";
			cout << "\n New data: ";
			cin >> val;
			insert(&tree, val);
			break;

		case 2:
			cout << "PreOrder Traversal\n";
			cout << "==========================\n";
			if (tree == NULL) {
				cout << "Tree is empty!\n";
			}
			else {
				preOrder(tree);
			}
			break;

		case 3:
			cout << "InOrder Traversal\n";
			cout << "==========================\n";
			if (tree == NULL) {
				cout << "Tree is empty!\n";
			}
			else {
				inOrder(tree);
			}
			break;

		case 4:
			cout << "PostOrder Traversal\n";
			cout << "==========================\n";
			if (tree == NULL) {
				cout << "Tree is empty!\n";
			}
			else {
				postOrder(tree);
			}
			break;

		case 5:
			cout<<"attempting clearing the memory\n";
			freeTree(&tree);
			cout<<"checking the memory\n";
			inOrder(tree);
			if (tree == nullptr){
				cout<<"memory cleared succesfuly\n";
			}
			else {
				cout<<"memory cleared unsuccesfully\n";
			}
			break;
			
		case 6:
			return 0;

		default:
			cout << "Option is not valid! Please re-enter your option";
			break;
	}
	
	getch();
    } while(opt != 6);
    return 0;
}