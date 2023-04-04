#include"queue.h"


void Enqueue_Pembeli(Queue_P *Q, Queue_BB *P, infochar Y, infotype Z){ // check
//Queue_P *Q telah berubah setelah melakukan operasi enqueue pada antrian pembeli.
//address_P yang berisi data pembeli baru telah ditambahkan pada posisi terakhir dari linked list address_P yang merepresentasikan antrian pembeli.
	
	address_P a = NULL;
	address_BB b = NULL;
	
	Create_Node_Pembeli(&a);
	Create_Node_BarangBelian(&b);
	Isi_Node_Pembeli(&a, &b, Y, Z);
	Ins_Akhir_Pembeli(&(*Q),a);
	
}

void Enqueue_BarangBelian(Queue_BB *Q,infotype X, infochar Y, infotype Z){	// check
//Queue_BB *Q telah berubah setelah melakukan operasi enqueue pada antrian barang belian.
//address_BB yang berisi data barang belian baru telah ditambahkan pada posisi terakhir dari linked list address_BB yang merepresentasikan antrian barang belian.//
	
	address_BB a = NULL;
	
	Create_Node_BarangBelian(&a);
	Isi_Node_BarangBelian(&a, X, Y, Z);
	Ins_Akhir_BarangBelian(&(*Q),a);
	
}


void Dequeue_Antrian(Queue_A *Q,infochar *X){	
// memberikan nomor antrian dan nama di antrian
	
	Del_Awal_Antrian(&(*Q),&(*X));	// Q disini bertipe address A, dan X passing parameter by address
	
}
