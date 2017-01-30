#include "tembakan.h"
#include <time.h>

//memutar kemiringan tembakan ke kiri atau kanan
void puterTembakan(int a) {
	
}

//mengganti flag isTembak menjadi true dan mengganti jedaTembak
void tembakTembakan() {
	
	prime.isTembak = 1;
	
	// get the current time
	time_t seconds;
	seconds = time(NULL);
	
	prime.jedaTembak = seconds;

} 

//mengganti flag isTembak menjadi false;
void sudahTembak() {
	
	prime.isTembak = 0;

} 

//mengecek apakah waktu terakhir menembak telah berlalu 2 detik, jika iya return true
int cekJedaTembakan() {
	
	time_t curr_t;
	double diff_t;

	// get the current time
	time(&curr_t);

	// get the difference of seconds between current time and the last time of shooting
	diff_t = difftime(curr_t, prime.jedaTembak);
	
	if (diff_t > 2) {
		return 1;
	} else {
		return 0;
	}

} 

//menggambar tembakan pada buffer, posisi objek berada di dalam gambar
void gambarTembakan() {
	
	for (int i = 600; i < 950; i++) {
		for (int j = 550; j < 650; j++) {
			titik e = {j, i};
			warna x = {100,99,0,98};	
		
			bufferDrawDot(e, x);	
		}
	}
	
} 
