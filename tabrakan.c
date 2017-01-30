#include "tabrakan.h"
#include <stdlib.h>

void gambarHancur(titik p) {
	
	//titik pe = {p.x,p.y};
	int i = 0;
	
	//titik pd = {p.x+10,p.y-10};
	for (i=0;i<10;i++) {
		usleep(50000-(i*5000));
		warna c = {255, 10+20*i, 0, 255};
		bufferDrawCircle(p, 10-1*i, c);
	}
	for (;i>=0;i--) {
		usleep(100000-(i*10000));
		warna c = {255, 200-15*i, 0, 255};
		bufferDrawCircle(p, 20-2*i, c);
	}
	/* Use this one for bigger explosion
	 * 
	for (i=0;i<10;i++) {
		usleep(50000-(i*5000));
		warna c = {255, 10+20*i, 0, 255};
		bufferDrawCircle(p, 20-2*i, c);
	}
	for (;i>=0;i--) {
		usleep(100000-(i*10000));
		warna c = {255, 200-15*i, 0, 255};
		bufferDrawCircle(p, 40-4*i, c);
	}
	* */
}

void gambarObjek() {
	int i_pesawat, i_peluru, i, j;
	
	// Gambar pesawat
	for(i_pesawat = 0; i_pesawat < 1; i_pesawat++) {
		titik d = pesawat[i_pesawat].posisi;
		titik e = {d.x + 20, d.y+10};
		
		
		// Kepala pesawat
		for (i=0; i<10; i++) {
			warna c = {235+i*2, 235+i*2, 235+i*2, 255};
			bufferDrawCircle(e, 10-1*i, c);
		}
		
		// Sayap kiri
		for(i = 0; i < 15; i++) {
			for(j = 0; j < 25; j++){
				titik m = {d.x + i-5, d.y + j-10};
				warna x = {255-4*abs(10-i), 255-4*abs(10-i), 255-4*abs(10-i), 255};
				bufferDrawDot(m, x);
			}
		}
		
		// Body
		for(i = 0; i < 50; i++) {
			for(j = 0; j < 21; j++){
				titik m = {d.x + i-27, d.y + j};
				warna x = {255-5*abs(11-j), 255-5*abs(11-j), 255-5*abs(11-j), 255};
				bufferDrawDot(m, x);
			}
		}
		
		// Sayap kanan
		for(i = 0; i < 15; i++) {
			for(j = 0; j < 25; j++){
				titik m = {d.x + i-5, d.y + j+ 10};
				warna x = {255-5*abs(10-i), 255-5*abs(10-i), 255-5*abs(10-i), 255};
				bufferDrawDot(m, x);
			}
		}
		
		// Ekor
		for(i = 0; i < 10; i++) {
			for(j = 0; j < 28; j++){
				titik m = {d.x + i-35, d.y + j - 7};
				warna x = {255-5*abs(17-j), 255-5*abs(17-j), 255-5*abs(17-j), 255};
				bufferDrawDot(m, x);
			}
		}
	}
	
	
	// Gambar peluru
	for(i_peluru = 0; i_peluru < 1; i_peluru++) {
		titik d = peluru[i_peluru].posisi;
		for (i=0; i<5; i++) {
			warna c = {200, 150+20*i, 0, 255};
			bufferDrawCircle(d, 5-1*i, c);
		}
		for (i=0; i<10; i++) {
			for(j = 0; j < 20; j++){
				titik e = {d.x + i-5, d.y + j+3};
				warna x = {220, 200-10*abs(3-i), 0, 255};
				bufferDrawDot(e, x);
			}
		}
	}
}
