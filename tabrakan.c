#include "tabrakan.h" 
#include <math.h> 

//cek apakah terdapat peluru yang berada sejauh offset dari pesawat
//jika iya kedua objek memiliki isTabrakan true

#define PI 3.14159265

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
		
	
	int random1 = rand() % 360;
	
		
		pesawat[pesawatterakhir].posisi = p;
		pesawat[pesawatterakhir].arah = random1;
		pesawat[pesawatterakhir].kecepatan = 10;
		pesawat[pesawatterakhir].isTabrakan = 0;
		pesawatterakhir++;
		
		printf("Angka random pesawat adalah %d \n",random1 );
	}else if (t=='b'){
	
	int random2 = rand() % 180;
	
		peluru[peluruterakhir].posisi = p;
		peluru[peluruterakhir].kecepatan = 50;
		peluru[peluruterakhir].arah = random2;
		peluru[peluruterakhir].isTabrakan = 0;
		peluruterakhir++;
		
		printf("Angka random peluru adalah %d \n",random2 );
	}
	
	
}
