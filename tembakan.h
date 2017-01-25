#include "gambar.h"

typedef struct{
	int kemiringan; //kemiringan moncong tembakan, kemiringan peluru yang keluar
	int jedaTembak; //waktu hingga bisa menembak lagi
	int isTembak;   //flag untuk tahu apakah tombol tembak ditekan
	point posisi;   //posisi tembakan
}tembakan;

void kontrolTembakan(tembakan* t); //mengecek pemecatan tombol, dan melakukan aksi yang sesuai
void puterTembakan(tembakan* t, int a); //memutar kemiringan tembakan ke kiri atau kanan
void tembakTembakan(tembakan* t); //mengganti flag isTembak menjadi true
void jedaTembakan(tembakan* t); //mengembalikkan flag isTembak menjadi flag
void gambarTembakan(tembakan* t); //menggambar tembakan pada buffer