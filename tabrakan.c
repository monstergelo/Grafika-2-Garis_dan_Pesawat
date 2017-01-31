#include "tabrakan.h" 
#include "tembakan.h" 
#include <math.h> 
#include <stdlib.h>
#include <time.h>

//cek apakah terdapat peluru yang berada sejauh offset dari pesawat
//jika iya kedua objek memiliki isTabrakan true

#define PI 3.14159265

extern int pesawatterakhir;
extern int peluruterakhir;
tembakan prime;
extern objekTabrak pesawat[1];
extern objekTabrak peluru[100];

void cekTabrakanObjek(int offset){
	int qq = pesawatterakhir;
	int ww = peluruterakhir;
	
	for (int i =0; i<qq ; i++){
		for (int j =0; j<ww ; j++){
			
			float jarak = sqrt((pesawat[i].posisi.x-peluru[j].posisi.x)*(pesawat[i].posisi.x-peluru[j].posisi.x)+(pesawat[i].posisi.y-peluru[j].posisi.y)*(pesawat[i].posisi.y-peluru[j].posisi.y));
			
			if (jarak<=offset){
				pesawat[i].isTabrakan=1;
				peluru[j].isTabrakan=1;
				
			}
		}
	}
}




//hilangkan objek pesawat dari memori
void hancurObjek(objekTabrak* o){
	o->isTabrakan=-1;
}


//ganti posisi seluruh objek sesuai kecepatan dan arah
void jalanObjek(){
	int qq = pesawatterakhir;
	int ww = peluruterakhir;
	
	double val = PI / 180.0;
	
	for (int i =0; i<qq ; i++){
		
		if(pesawat[i].isTabrakan==0){
			
			if(pesawat[i].arah<=180){
				pesawat[i].posisi.x = pesawat[i].posisi.x+(cos(pesawat[i].arah*val)*pesawat[i].kecepatan);
				pesawat[i].posisi.y = pesawat[i].posisi.y+(sin(pesawat[i].arah*val)*pesawat[i].kecepatan);
			}else{
				pesawat[i].posisi.x = pesawat[i].posisi.x+(cos(pesawat[i].arah*val)*pesawat[i].kecepatan);
				pesawat[i].posisi.y = pesawat[i].posisi.y-(sin(pesawat[i].arah*val)*pesawat[i].kecepatan);
			}
		}
	} 
	
	
	for (int i =0; i<ww ; i++){
		if(peluru[i].isTabrakan==0){
		peluru[i].posisi.x = peluru[i].posisi.x+(cos(peluru[i].arah*val)*peluru[i].kecepatan);
		peluru[i].posisi.y = peluru[i].posisi.y-(sin(peluru[i].arah*val)*peluru[i].kecepatan);
		}
	}
}


//membuat objek baru(a=pesawat; b=peluru) pada posisi p
void spawnObjek(char t, titik p){
	if (t=='a'){
		
		pesawat[pesawatterakhir].posisi = p;
		pesawat[pesawatterakhir].arah = 0;
		pesawat[pesawatterakhir].kecepatan = 5;
		pesawat[pesawatterakhir].isTabrakan = 0;
		pesawatterakhir++;
		
	}else if (t=='b'){
	
		peluru[peluruterakhir].posisi = p;
		peluru[peluruterakhir].kecepatan = 25;
		peluru[peluruterakhir].arah = 90 - prime.kemiringan;
		peluru[peluruterakhir].isTabrakan = 0;
		peluruterakhir++;
		
	}
	
	
}

void gambarHancur(titik p) {
	
	//titik pe = {p.x,p.y};
	static int i = 0;
	static int stage = 0;
	
	//titik pd = {p.x+10,p.y-10};
	if(i<10 && stage == 0){
		warna c = {255, 10+20*i, 0, 255};
		bufferDrawCircle(p, 10-1*i, c);
		i++;
	}
	else{
		stage = 1;
	}
	

	if(i>0 && stage == 1){
		warna c = {255, 200-15*i, 0, 255};
		bufferDrawCircle(p, 20-2*i, c);
		i--;
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


//**************************************************************************************************
void gambarObjek() {
	int i_pesawat, i_peluru, i, j;
	
	// Gambar pesawat
	for(i_pesawat = 0; i_pesawat < 1; i_pesawat++) {
		if(pesawat[i_pesawat].isTabrakan != -1){
			titik d = pesawat[i_pesawat].posisi;
			titik e = {d.x + 20, d.y+10};
			
			
			// Kepala pesawat
			// for (i=0; i<10; i++) {
			// 	warna c = {235+i*2, 235+i*2, 235+i*2, 255};
			// 	bufferDrawCircle(e, 10-1*i, c);
			// }
			
			// Sayap kiri
			warna x = {255,255,255,255};
			titik m1 = {d.x + 0-5, d.y + 0-10};
			titik m2 = {d.x + 0-5, d.y + 10-10};
			titik m3 = {d.x + 15-5, d.y + 10-10};
			titik m4 = {d.x + 15-5, d.y + 0-10};
			titik m[4];
			m[0] = m1;
			m[1] = m2;
			m[2] = m3;
			m[3] = m4;
			bufferDrawPlane(m, x, 4);


			
			// Body
			titik mb1 = {d.x + 0-27, d.y + 0};
			titik mb2 = {d.x + 0-27, d.y + 21};
			titik mb3 = {d.x + 50-27, d.y + 21};
			titik mb4 = {d.x + 50-27, d.y + 0};
			titik mb[4];
			mb[0] = mb1;
			mb[1] = mb2;
			mb[2] = mb3;
			mb[3] = mb4;
			bufferDrawPlane(mb, x, 4);
			
			// Sayap kanan
			titik mr1 = {d.x + 0-5, d.y + 11+ 10};
			titik mr2 = {d.x + 0-5, d.y + 25+ 10};
			titik mr3 = {d.x + 15-5, d.y + 25+ 10};
			titik mr4 = {d.x + 15-5, d.y + 11+ 10};
			titik mr[4];
			mr[0] = mr1;
			mr[1] = mr2;
			mr[2] = mr3;
			mr[3] = mr4;
			bufferDrawPlane(mr, x, 4);
			
			// Ekor
			titik me1 = {d.x + 0-35, d.y + 0 - 7};
			titik me2 = {d.x + 0-35, d.y + 28 - 7};
			titik me3 = {d.x + 10-35, d.y + 28 - 7};
			titik me4 = {d.x + 10-35, d.y + 0 - 7};
			titik me[4];
			me[0] = me1;
			me[1] = me2;
			me[2] = me3;
			me[3] = me4;
			bufferDrawPlane(me, x, 4);
		}
	}
	
	
	// Gambar peluru
	for(i_peluru = 0; i_peluru < 99; i_peluru++) {
		if(peluru[i_peluru].isTabrakan != -1){
			/*kepala peluru*/
			titik d = peluru[i_peluru].posisi;
			// for (i=0; i<5; i++) {
			// 	warna c = {200, 150+20*i, 0, 255};
			// 	bufferDrawCircle(d, 5-1*i, c);
			// }

			warna x = {255,255,255,255};
			titik mp1 = {d.x + 0-5, d.y + 0+3};
			titik mp2 = {d.x + 0-5, d.y + 20+3};
			titik mp3 = {d.x + 10-5, d.y + 20+3};
			titik mp4 = {d.x + 10-5, d.y + 0+3};
			titik mp[4];
			mp[0] = mp1;
			mp[1] = mp2;
			mp[2] = mp3;
			mp[3] = mp4;
			bufferDrawPlane(mp, x, 4);
		}
	}
}


//**************************************************************************************************
void gambarObjek2() {
	int i_pesawat, i_peluru, i, j;
	
	// Gambar pesawat
	for(i_pesawat = 0; i_pesawat < 1; i_pesawat++) {
		if(pesawat[i_pesawat].isTabrakan != -1){
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
	}
	
	
	// Gambar peluru
	for(i_peluru = 0; i_peluru < 1; i_peluru++) {
		if(peluru[i_peluru].isTabrakan != -1){
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
}

