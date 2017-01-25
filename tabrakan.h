#include "gambar.h"


//objek dapat berupa peluru atau pesawat
typedef struct{
	point posisi;	//posisi objek
	int kecepatan;  //kecepatan objek bergerak
	int arah;		//kemana objek mengarah
	int isTabrakan; //flag untuk mengecek apakah kolisi terjadi
}objekTabrak;

objekTabrak[100] pesawat;
objekTabrak[100] peluru;

void cekTabrakanObjek(int offset);   //melakukan iterasi seluruh peluru terhadap seluruh pesawat, jika tabrakan isTabrakan menjadi true
void hancurObjek(objekTabrak* o);	 //hilangkan objek pesawat dari memori
void hancurPesawatObjek(int i);		 //hilangkan objek pesawat dengan index i
void hancurPeluruObjek(int i);		 //hilangkan objek peluru dengan index i
void jalanObjek();					 //ganti posisi seluruh objek sesuai kecepatan dan arah
void jalanObjek(objekTabrak* o);	 //ganti posisi objek sesuai kecepatan dan arah
void spawnObjek(char t, point p);	 //membuat objek baru(a=pesawat; b=peluru) pada posisi p
void gambarObjek();					 //menggambar seluruh objek ke buffer;
void gambarObjek(objekTabrak* o);	 //menggambar objek ke buffer;

