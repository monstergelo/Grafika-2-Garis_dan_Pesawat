#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>

typedef struct{
    int r,g,b,a;
} warna;

typedef struct{
	int x;
	int y;
} titik;

//ganti dengan ukuran layar
unsigned char buffer_r[1366][700];
unsigned char buffer_g[1366][700];
unsigned char buffer_b[1366][700];
unsigned char buffer_a[1366][700];

void bufferDrawDot(titik p, warna c);	//mengganti nilai pixel dengan posisi p pada buffer dengan warna c
void refreshBuffer(titik p0, titik p1); //mengganti nilai seluruh pixel buffer menjadi background color untuk
void loadBuffer();						//memasukkan nilai buffer ke driver
//================================================
void bufferDrawLine(titik p0, titik p1, warna c);	//mmengganti nilai pixel sehingga tergambar garis dari p0 ke p1
void bufferDrawPlane(titik* p, , warna c);			//membuat bidang yang menyambungkan titik p[0] ke p[1], p[1] ke p[2], ...., p[n] ke p[0]
//================================================
void bufferDrawCircle(titik p, warna c);	//membuat lingkaran dengan p sebagai pusat
int  dotDistance(titik p1, titik p2);		//mengembalikan jarak antara p1 dan p2
//================================================
