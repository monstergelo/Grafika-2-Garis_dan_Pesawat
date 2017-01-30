#include "tembakan.h"
#include "tabrakan.h"


void drawObjects();		//menggambar tembakan dan objekTabrak ke buffer
void preUpdate();		//(1)cek inputuser
void updatePosisi();	//(1)ubah posisi. (2)spawnObjek, (3)drawBuffer
void postUpdate();	 	//(1)cek kolisi, (2)loadbuffer ke layar

objekTabrak pesawat[1];
objekTabrak peluru[5];


int main()
{
	init_fb();
	warna c = {255,255,255,255};
	warna c0 = {255,255,255,255};
	c0.r += 30;
    c0.g += 30;
    c0.b += 30;

	//drawObjects();	

	//inisialisasi
	titik pl0 = {0,0};
	titik pl1 = {1366,700};

	titik p0 = {400,100};
	titik p1 = {600,600};
	titik p2 = {0,650};
	titik p3 = {500,650};

	titik pt[3];
	pt[0] = pl0;
	pt[1] = p0;
	pt[2] = p1;

	spawnObjek('a',p0);
	spawnObjek('b',p1);

	refreshBuffer(pl0,pl1);
	gambarObjek();

	bufferDrawLine(p1,pl0, c0);
	//bufferDrawPlane(pt, c, 3);
	loadBuffer();

	while(0)
	{
		// preUpdate();
		// updatePosisi();
		// postUpdate();	
		refreshBuffer(pl0,pl1);
		gambarObjek();
		loadBuffer();
		jalanObjek();	

		//usleep(17);  //60fps
		usleep(10000);
	}

	garbage_fb();

	return 0;
}



void drawObjects(){

}

void preUpdate(){

}

void updatePosisi(){

}

void postUpdate(){

}