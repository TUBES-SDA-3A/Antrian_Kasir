#include "Header.h"


// List Pelanggan

bool isEmpty_Pembeli(address_P p){ // check
/* 	I.S : tidak ada yang berubah, hanya menerima satu parameter berupa alamat dari node pembeli.
	F.S : fungsi ini mengembalikan nilai boolean, yaitu 1 jika queue pembeli kosong dan 0 jika queue pembeli tidak kosong.
*/ 
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_Pembeli (address_P *p){	// check
/* 	I.S : p terdefinisi tidak diketahui isinya 
	F.S : p mengalokasikan memori sebesar ukuran dari tipe data "List_Pembeli"
*/ 
	
	*p = (address_P)malloc(sizeof(Pembeli));
//	if(p != Nil){
//		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
//	}else{
//		printf("Gagal Alokasi\n");
//	}
	
}

void Isi_Node_Pembeli (address_P *p , address_BB *q, infochar Nama_Pembeli, int No_Kasir){ // check
/* I.S : Node Pembeli belum berisi apa-apa
   F.S : Pointer yang disimpan dalam variabel *p akan mengarah ke alamat node pembeli yang telah diisi dengan data-data yang diberikan.
*/
	
	if(isEmpty_Pembeli(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		BarangBelian(*p) = *q;
		Nama_Pembeli(*p) = Nama_Pembeli;
		No_Kasir(*p) = No_Kasir;
	}
	
}

void Ins_Akhir_Pembeli (address_P *p, address_P PNew){ // check
/* I.S : *p mengarah ke node pembeli yang masih bernilai NULL dan Alamat node pembeli yang baru (PNew) mungkin sudah dialokasikan memori atau belum dialokasikan memori.
   F.S : linked list node pembeli akan bertambah satu node dengan node terakhir yang menunjuk pada alamat node pembeli yang baru.
*/
	
	address_P A;
	if(isEmpty_Pembeli(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_Pembeli(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}


// List BarangBelian

boolean isEmpty_BarangBelian(address_BB p){  // check
/* I.S : Alamat node barang belian (p) mungkin kosong (NULL) atau tidak kosong.
   F.S : mengetahui apakah suatu node barang belian kosong atau tidak dengan melihat nilai boolean yang dikembalikan oleh fungsi ini.
*/
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_BarangBelian (address_BB *p){	// check
/* I.S : belum memesan tempat untuk node barang belian
   F.S : telah memesan tempat untuk node barang belian
*/
	
	*p = (address_BB)malloc(sizeof(List_BarangBelian));
	
}

void Isi_Node_BarangBelian (address_BB *p , infotype harga, infochar nama_barang, infotype jumlah_barang){	// check
/* I.S : node barang belian belum terisi
   F.S : nilai-nilai pada suatu node barang belian akan terisi dengan nilai yang diberikan pada parameter jika alamat 
   		 node barang belian tidak kosong. Namun, jika alamat node barang belian kosong, maka pesan "Node Belum di Alokasi" akan dicetak.
*/
	
	if(isEmpty_BarangBelian(*p)){
		printf("Node Belum di Alokasi\n");
	}else{
		next(*p) = Nil;
		Harga(*p) = harga;
		Nama_Barang(*p) = nama_barang;
		Jumlah_Barang(*p) = jumlah_barang;
	}
	
}

void Ins_Akhir_BarangBelian (address_BB *p, address_BB PNew){	// check
/* I.S : pointer mengarah ke node yang kosong
   F.S : node barang belian baru akan disisipkan ke dalam posisi terakhir atau ujung akhir dari linked list node barang belian, sehingga linked list tersebut akan terus bertambah panjang. Namun, 
   		 jika alamat pointer node barang belian yang diberikan kosong, maka node barang belian baru tidak akan disisipkan dan tidak terjadi perubahan pada linked list.
*/
	
	address_BB A;
	if(isEmpty_BarangBelian(*p)){
		*p = PNew;
	}else{	
		A = *p;
		while(!isEmpty_BarangBelian(next(A))){
			A = next(A);
		}
		next(A) = PNew;
	}
}


void Del_Awal_BarangBelian (address_BB * p, infochar * X){	// check
/* I.S : Pointer yang disimpan dalam variabel *p mungkin mengarah ke alamat node barang belian yang kosong (NULL)
   F.S : node barang belian pada posisi pertama atau ujung depan dari linked list node barang belian akan dihapus, sehingga linked list tersebut akan berkurang satu elemen. 
*/
	
	address_BB A;
	
	if(isEmpty_BarangBelian(*p)){
		printf("List Kosong");
	}else{
		A = *p;
		*X = Nama_Barang(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}
}

// List Antrian

boolean isEmpty_Antrian(address_A p){	// check
/* I.S : belum mengetahui apakah address_A kosong atau tidak.
   F.S : address_A p merupakan alamat dari head dari suatu linked list address_A yang akan dicek apakah kosong atau tidak.
*/
	
	if(p == NULL){
		return 1;
	}else{
		return 0;
	}
	
}

void Create_Node_Antrian (address_A *p){	// check
/* I.S : node antrian belum ada/belum dibuat
   F.S : mengalokasikan node antrian
*/
	
	*p = (address_A)malloc(sizeof(List_Antrian));	// membuat node sebesar list antrian
//	if(p != Nil){
//		printf("Alokasi Berhasil dengan Alamat : %p.\n",*p);
//	}else{
//		printf("Gagal Alokasi\n");
//	}
	
}

void Isi_Node_Antrian (address_A *p , infochar nama){	
// Mengisi node yang sudah dipesan dengan Nilai yang dikirimkan ,Periksa keberadaan P, Nilai diisi jika P tidak NULL
	
	if(isEmpty_Antrian(*p)){
		printf("Node Belum di Alokasi\n");	
	}else{
		next(*p) = Nil;		// next yang ditunjuk p disii Nil 
		nama(*p) = nama;	// nama yang ditunjuk p diisi nama
	}
	
}

void Tampil_List_Antrian (address_A p){		
// Menampilkan seluruh isi Linked List, p parameter passing by value
	int i = 1;
	
	if(isEmpty_Antrian(p)){	
		printf("List Kosong\n");
	}
	else{		
		while(!isEmpty_Antrian(p)){
			printf("%d. %s",i,&p->nama);	// print yang ada di antrian
			p = next(p);	// p diisi next p
			if(p != Nil){	// jika p tidak sama dengan nil 
				printf("\n");
			}
		i++; // lakukan ini sebanyak i	
		}
		printf("\n");
	}	
	
}

void Ins_Akhir_Antrian (address_A *p, address_A PNew){	
//  menambahkan elemen list (PNew) di akhir LinkedList 
	
	address_A A;
	if(isEmpty_Antrian(*p)){
		*p = PNew;	// pointer diisi pNew
	}else{	
		A = *p;
		while(!isEmpty_Antrian(next(A))){ // memeriksa next A apakah kosong 
			A = next(A);	// A diisi next A
		}
		next(A) = PNew;
	}
}


void Del_Awal_Antrian (address_A * p, infochar * X){	
	
	address_A A;
	
	if(isEmpty_Antrian(*p)){	// memeriksa apakah antrian kosong
		printf("Antrian Kosong\n");	// jika kosong print 
	}else{
		A = *p;	// Antrian diisi address p
		*X = nama(A);	// mengalokasi dengan nama pada Antrian
		*p = next(*p);	// pointer diisi next p
		A = NULL;	// A diisi NIL
		free(A);	// hampus A dari antrian
	}
	
}

void DelPBarangBelian (address_BB *BB, infochar X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	 /* Kamus Lokal */
	address_BB TransBB, Prec;
	bool found=false;
	 /* Algoritma */
		Prec = Nil;
	TransBB = First(*BB);
	while ((TransBB != Nil) && (!found))
	{
		 if (strcmp(Info(TransBB),X) == 0)
		 {	found = true;	}
		 else
		 {
		Prec = TransBB;
		TransBB = Next(TransBB);
		 }
	} /* P = Nil Atau Ketemu */

	if (found)
	{
		printf("Warga %s Berhasil Dihapus !",X);
		 if (Prec == Nil && Next(TransBB) == Nil)		/* Hanya 1 elemen */
		 {	First(*BB) = Nil;	}
		 else if (Prec == Nil)			/* Ketemu di elemen 1*/
		 {	First(*BB) = Next(TransBB);	}
		 else		/* Ketemu di elemen list yang ditengah/akhir */
		 {	Next(Prec) = Next(TransBB);	}
		 Next(BB) = Nil;
		 DeAlokasi (BB);
	}
}

void DelPAntrian (List * L, infotype X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	 /* Kamus Lokal */
	address P, Prec;
	boolean found=false;
	 /* Algoritma */
		Prec = Nil;
	P = First(*L);
	while ((P != Nil) && (!found))
	{
		 if (strcmp(Info(P),X) == 0)
		 {	found = true;	}
		 else
		 {
		Prec = P;
		P = Next(P);
		 }
	} /* P = Nil Atau Ketemu */

	if (found)
	{
		printf("Warga %s Berhasil Dihapus !",X);
		 if (Prec == Nil && Next(P) == Nil)		/* Hanya 1 elemen */
		 {	First(*L) = Nil;	}
		 else if (Prec == Nil)			/* Ketemu di elemen 1*/
		 {	First(*L) = Next(P);	}
		 else		/* Ketemu di elemen list yang ditengah/akhir */
		 {	Next(Prec) = Next(P);	}
		 Next(P) = Nil;
		 DeAlokasi (P);
	}
}

void Enqueue_Pembeli(address_P *Q, address_BB *P, infochar Y, int Z){ // check
	
	address_P a = NULL;
	address_BB b = NULL;
	
	Create_Node_Pembeli(&a);
	Create_Node_BarangBelian(&b);
	Isi_Node_Pembeli(&a, &b, Y, Z);
	Ins_Akhir_Pembeli(&(*Q),a);
	
}

void Enqueue_BarangBelian(address_BB *Q, int X, infochar Y, int Z){	// check
	
	address_BB a = NULL;
	
	Create_Node_BarangBelian(&a);
	Isi_Node_BarangBelian(&a, X, Y, Z);
	Ins_Akhir_BarangBelian(&(*Q),a);
	
}


void Dequeue_Antrian(address_A *Q, infochar *X){	
// memberikan nomor antrian dan nama di antrian
	
	Del_Awal_Antrian(&(*Q),&(*X));	// Q disini bertipe address A, dan X passing parameter by address
	
}