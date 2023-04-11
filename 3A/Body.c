#include "Header.h"

// List Pelanggan

bool isEmpty_Pembeli(address_P p)
{	// check
	/* 	I.S : tidak ada yang berubah, hanya menerima satu parameter berupa alamat dari node pembeli.
		F.S : fungsi ini mengembalikan nilai boolean, yaitu 1 jika queue pembeli kosong dan 0 jika queue pembeli tidak kosong.
	*/

	if (p == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Create_Node_Pembeli(address_P *headPembeli, address_P *newPembeli, address_BB *q, infochar Nama_Pembeli, int No_Kasir, int uangPembeli)
{	
	/* 	I.S : headPembeli dan newPembeli belum memiliki nilai atau masih kosong, dan address_BB q, infochar Nama_Pembeli, int No_Kasir, dan int uangPembeli diisi dengan nilai yang sesuai.
		F.S : terbentuknya sebuah node baru pada linked list pembeli dengan informasi yang sudah diisi dan disambungkan ke linked list.
	*/
	*newPembeli = (address_P)malloc(sizeof(Pembeli));

	address_P Traversal;

	if (isEmpty_Pembeli(*newPembeli))
	{
		printf("Node Belum di Alokasi\n");
	}
	else
	{
		(*newPembeli)->next = Nil;
		(*newPembeli)->barangBelian = *q;
		(*newPembeli)->namaPembeli = Nama_Pembeli;
		(*newPembeli)->noKasir = No_Kasir;
		(*newPembeli)->hargaTotal = 0;
		(*newPembeli)->uangPembeli = uangPembeli;
	}
	if (isEmpty_Pembeli(*headPembeli))
	{
		*headPembeli = *newPembeli;
	}
	else
	{
		Traversal = *headPembeli;
		while (!isEmpty_Pembeli(Traversal->next))
		{
			Traversal = Traversal->next;
		}
		(Traversal)->next = *newPembeli;
	}
}


/*************** Barang Belian ***************/

bool isEmpty_BarangBelian(address_BB p)
{	// check
	/* I.S : Alamat node barang belian (p) mungkin kosong (NULL) atau tidak kosong.
	   F.S : mengetahui apakah suatu node barang belian kosong atau tidak dengan melihat nilai boolean yang dikembalikan oleh fungsi ini.
	*/

	if (p == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Create_Node_BarangBelian(address_BB *headBarangBelian, address_BB *newBarangBelian, infochar nama_barang, int jumlah_barang)
{	// check
	/* I.S : - headAntrian merupakan pointer ke list antrian yang awalnya kosong atau NULL.
			 - newAntrian merupakan pointer yang belum dialokasikan ke memori.
			 - Pembeli merupakan data pembeli yang akan ditambahkan ke dalam node antrian.
	   F.S : newAntrian telah dialokasikan ke memori, emiliki nilai next yang diisi dengan NULL, dan memiliki nilai Pembeli yang diisi dengan Pembeli.
	*/

	address_BB transBB;

	*newBarangBelian = (address_BB)malloc(sizeof(List_BarangBelian));
	
	if (isEmpty_BarangBelian(*newBarangBelian))
	{
		printf("Node Belum di Alokasi\n");
	}
	else
	{
		(*newBarangBelian)->next = Nil;
		(*newBarangBelian)->namaBarang = nama_barang;
		(*newBarangBelian)->jumlahBarang = jumlah_barang;
	}

	if(isEmpty_BarangBelian(*headBarangBelian)){
		*headBarangBelian = *newBarangBelian;
	}else{
		transBB = *headBarangBelian;
		while(!isEmpty_BarangBelian(transBB->next)){
			transBB = (transBB)->next;
		}
		transBB = newBarangBelian;
 	}
}

void Del_Awal_BarangBelian(address_BB *p, infochar *X)
{	// check
	/* I.S : Terdapat sebuah node yang menjadi inputan fungsi Del_Awal_BarangBelian, dan pada awalnya node tersebut menunjuk ke head dari sebuah list.
	   F.S : Node pertama dari list telah dihapus dan nilai nama barang dari node tersebut disimpan pada variabel X.
	*/

	address_BB A;

	if (isEmpty_BarangBelian(*p))
	{
		printf("List Kosong");
	}
	else
	{
		A = *p;
		*X = Nama_Barang(A);
		*p = next(*p);
		A = NULL;
		free(A);
	}
}

// List Antrian
bool isEmpty_Antrian(address_A p)
{	// check
	/* I.S : belum mengetahui apakah address_A kosong atau tidak.
	   F.S : address_A p merupakan alamat dari head dari suatu linked list address_A yang akan dicek apakah kosong atau tidak.
	*/

	if (p == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Create_Node_Antrian(address_A *headAntrian,address_A *newAntrian, address_P Pembeli)
{	// check
	/* I.S : node antrian belum ada/belum dibuat
	   F.S : mengalokasikan node antrian
	*/

	address_A transA;

	*newAntrian = (address_A)malloc(sizeof(Antrian)); // membuat node sebesar list antrian
	
	if (isEmpty_Antrian(*newAntrian))
	{
		printf("Node Belum di Alokasi\n");
	}
	else
	{
		(*newAntrian) = Nil;				 // next yang ditunjuk p disii Nil
		(*newAntrian)->Pembeli = Pembeli; // nama yang ditunjuk p diisi nama
	}

	if (isEmpty_Antrian(*headAntrian))
	{
		*headAntrian = *newAntrian; // pointer diisi pNew
	}
	else
	{
		transA = *headAntrian;
		while (!isEmpty_Antrian((transA)->next))
		{				   // memeriksa next A apakah kosong
			transA = (transA)->next; // A diisi next A
		}
		(transA)->next = newAntrian;
	}
}

void Tampil_List_Antrian(address_A p)
{
	// Menampilkan seluruh isi Linked List, p parameter passing by value
	int i = 1;

	if (isEmpty_Antrian(p))
	{
		printf("List Kosong\n");
	}
	else
	{
		while (!isEmpty_Antrian(p))
		{
			printf("%d. %s", i, p->Pembeli->namaPembeli); // print yang ada di antrian
			p = next(p);								  // p diisi next p
			if (p != Nil)
			{ // jika p tidak sama dengan nil
				printf("\n");
			}
			i++; // lakukan ini sebanyak i
		}
		printf("\n");
	}
}

void Del_Awal_Antrian(address_A *p, infochar *X)
{

	address_A A;

	if (isEmpty_Antrian(*p))
	{								// memeriksa apakah antrian kosong
		printf("Antrian Kosong\n"); // jika kosong print
	}
	else
	{
		A = *p;		   // Antrian diisi address p
		*X = nama(A);  // mengalokasi dengan nama pada Antrian
		*p = next(*p); // pointer diisi next p
		A = NULL;	   // A diisi NIL
		free(A);	   // hampus A dari antrian
	}
}

void DelPBarangBelian(address_BB *BB, infochar X)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	/* Kamus Lokal */
	address_BB TransBB, Prec;
	bool found = false;
	/* Algoritma */
	Prec = Nil;
	TransBB = *BB;
	while ((TransBB != Nil) && (!found))
	{
		if (strcmp((TransBB)->namaBarang, X) == 0)
		{
			found = true;
		}
		else
		{
			Prec = TransBB;
			TransBB = (TransBB)->next;
		}
	} 

	if (found)
	{
		if (Prec == Nil && (TransBB)->next == Nil) /* Hanya 1 elemen */
		{
			TransBB->next = Nil;
		}
		else if (Prec == Nil) /* Ketemu di elemen 1*/
		{
			*BB = (TransBB)->next;
			TransBB->next = Nil;
		}
		else /* Ketemu di elemen list yang ditengah/akhir */
		{
			(Prec)->next = (TransBB)->next;
			TransBB->next = Nil;
		}
		DeAlokasi(TransBB);
	}
}

void DelPAntrian(address_P *Pembeli, address_A next)
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	/* Kamus Lokal */
	address_P  Prec, transP;
	bool found = false;
	/* Algoritma */
	Prec = Nil;
	transP = (*Pembeli);
	while ((transP != Nil) && (!found))
	{
		if (strcmp((transP)->namaPembeli, next) == 0)
		{
			found = true;
		}
		else
		{
			Prec = transP;
			transP = (transP)->next;
		}
	} 

	if (found)
	{
		if (Prec == Nil && (transP)->next == Nil) /* Hanya 1 elemen */
		{
			(transP)->next = Nil;
		}
		else if (Prec == Nil) /* Ketemu di elemen 1*/
		{
			(*Pembeli) = (transP)->next;
			(transP)->next = Nil;
		}
		else /* Ketemu di elemen list yang ditengah/akhir */
		{
			(Prec)->next = (transP)->next;
			(transP)->next = Nil;
		}
		DeAlokasi(transP);
	}
}

void Dequeue_Antrian(address_A *Q, infochar *X)
{
	// memberikan nomor antrian dan nama di antrian

	Del_Awal_Antrian(&(*Q), &(*X)); // Q disini bertipe address A, dan X passing parameter by address
}