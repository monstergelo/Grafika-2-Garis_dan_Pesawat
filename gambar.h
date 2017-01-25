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
} color;

typedef struct{
	int x;
	int y;
}point ;

//ganti dengan ukuran layar
unsigned char buffer_r[1366][700];
unsigned char buffer_g[1366][700];
unsigned char buffer_b[1366][700];
unsigned char buffer_a[1366][700];

void bufferDrawDot(int x, int y, color c);
void refreshBuffer(int x0, int x1, int y0, int y1);
void loadBuffer();
