#include "gambar.h"


//objek dapat berupa peluru atau pesawat
typedef struct{
	titik posisi;	//posisi objek, titik tengah objek
	int kecepatan;  //kecepatan objek bergerak
	int arah;		//kemana objek mengarah
	int isTabrakan; //flag untuk mengecek apakah kolisi terjadi
}objekTabrak;

objekTabrak pesawat[100];
objekTabrak peluru[100];


void cekTabrakanObjek(int offset);   //cek apakah terdapat peluru yang berada sejauh offset dari pesawat, 
								     //jika iya kedua objek memiliki isTabrakan true
void hancurObjek(objekTabrak* o);	 //hilangkan objek pesawat dari memori
void jalanObjek();					 //ganti posisi seluruh objek sesuai kecepatan dan arah
void spawnObjek(char t, titik p);	 //membuat objek baru(a=pesawat; b=peluru) pada posisi p
//=============================================================================================================================================
void gambarObjek();					 //menggambar seluruh objek dengan ke buffer, posisi objek berada di dalam gambar;
void gambarHancur(titik p);			 //menggambar animasi hancur pada titik p;
