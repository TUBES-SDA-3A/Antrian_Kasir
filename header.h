typedef const char *infochar;
typedef struct Pembeli *address_P;
typedef struct List_Barang *address_B;
typedef struct List_BarangBelian *address_BB;
typedef struct Antrian *address_A;

typedef struct Pembeli
{
    infochar namaPembeli;
    address_BB BarangBelian;
    int uangPembeli;
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
    int hargaTotal;
    int jumlahBarang;
    address_BB next;
} List_BarangBelian;

typedef struct Antrian
{
    Pembeli namaPembeli;
    address_A next;
} Antrian;

typedef struct Kasir
{
    int Nomor;
    address_A next;
    infochar namaKasir;
} datakasir;

#endif
