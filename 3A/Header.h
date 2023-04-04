/*
Kelompok : 3A
Anggota :
        * Daniel Reinhard Pandapotan Butar butar 221524006
        * Hasna Fitriyani Khairunissa  221524011
        * Muhammad Azharuddin Hamid  221524018
*/

#ifndef header_h
#define header_h
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

typedef const char *infochar;
typedef struct Pembeli *address_P;
typedef struct List_Barang *address_B;
typedef struct List_BarangBelian *address_BB;
typedef struct Antrian *address_A;

typedef struct Pembeli
{
    infochar namaPembeli;
    address_BB barangBelian;
    int uangPembeli;
    int hargaTotal;
    int noKasir;
    address_P next;
} Pembeli;

typedef struct List_Barang
{
    infochar nama;
    int stok;
    int harga;
} DataBarang;

typedef struct List_BarangBelian
{
    infochar namaBarang;
    int jumlahBarang;
    address_BB next;
} List_BarangBelian;

typedef struct Antrian
{
    Pembeli Pembeli;
    address_A next;
} Antrian;

typedef struct Kasir
{
    int Nomor;
    address_A next;
    infochar namaKasir;
} dataKasir;

#endif
