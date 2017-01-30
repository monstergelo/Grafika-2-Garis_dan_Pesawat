#include "tabrakan.h" 
#include <math.h> 

//cek apakah terdapat peluru yang berada sejauh offset dari pesawat
//jika iya kedua objek memiliki isTabrakan true

int pesawatterakhir;
int peluruterakhir;

extern objekTabrak pesawat[100];
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
				
				printf("Tabrakan pesawat %d dan peluru %d \n",i,j);
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
	
	
	
	for (int i =0; i<qq ; i++){
		
		if(pesawat[i].isTabrakan==0){
		pesawat[i].posisi.x = pesawat[i].posisi.x-pesawat[i].kecepatan;
		}
	} 
	
	
	for (int i =0; i<ww ; i++){
		if(peluru[i].isTabrakan==0){
		peluru[i].posisi.x = peluru[i].posisi.x+(cos(peluru[i].arah)*peluru[i].kecepatan);
		peluru[i].posisi.y = peluru[i].posisi.y+(sin(peluru[i].arah)*peluru[i].kecepatan);
		}
	}
}


//membuat objek baru(a=pesawat; b=peluru) pada posisi p
void spawnObjek(char t, titik p){
	
	if (t=='a'){
		pesawat[pesawatterakhir].posisi = p;
		pesawat[pesawatterakhir].arah = 180;
		pesawat[pesawatterakhir].kecepatan = 10;
		pesawat[pesawatterakhir].isTabrakan = 0;
		pesawatterakhir++;
		
	}else if (t=='b'){
		
		int random = rand();
		
		peluru[peluruterakhir].posisi = p;
		peluru[peluruterakhir].kecepatan = 50;
		peluru[peluruterakhir].arah = random % 180;
		peluru[peluruterakhir].isTabrakan = 0;
		peluruterakhir++;
	}
}
