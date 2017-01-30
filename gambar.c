// global_* dan GLOBAL_*
#include "framebuffer_init.h"

// deklarasi fungsi
#include "gambar.h"

//mengganti nilai pixel dengan posisi p pada buffer dengan warna c
void bufferDrawDot(titik p, warna c){
    if((p.x < 1) || (p.x > GLOBAL_LAYAR_X) || (p.y < 1) || (p.y > GLOBAL_LAYAR_Y)){
		return ;
	}

    long int position = (p.x + global_vinfo.xoffset) * (global_vinfo.bits_per_pixel / 8) + 
       (p.y + global_vinfo.yoffset) * global_finfo.line_length;

    if(global_vinfo.bits_per_pixel == 32){
        *(global_fbp + position) = c.b;
        *(global_fbp + position + 1) = c.g;
        *(global_fbp + position + 2) = c.r;
        *(global_fbp + position + 3) = c.a;
    }else{
        // assume 16 bit color
        int b = c.b;
        int g = c.g;
        int r = c.r;
        unsigned short int t = r<<11 | g << 5 | b;
        *((unsigned short int*)(global_fbp + position)) = t;
    }
}

//mengganti nilai seluruh pixel buffer menjadi background color untuk
void refreshBuffer(titik p0, titik p1){
    warna warna_default = {25, 25, 255, 255};

    // 
    //       *1
    // *0
    // 
    int i, j;
    if(p0.x < p1.x && p0.y < p1.y){
        for(i = p0.x; i < p1.x; i++)
            for(j = p0.y; j < p1.y; j++){
                buffer_r[i][j] = warna_default.r;
                buffer_g[i][j] = warna_default.g;
                buffer_b[i][j] = warna_default.b;
                buffer_a[i][j] = warna_default.a;
            }
        
        return;
    }
        

    // 
    // *1
    //       *0
    // 
    if(p0.x > p1.x && p0.y < p1.y){
        for(i = p1.x; i < p0.x; i++)
            for(j = p0.y; j < p1.y; j++){
                buffer_r[i][j] = warna_default.r;
                buffer_g[i][j] = warna_default.g;
                buffer_b[i][j] = warna_default.b;
                buffer_a[i][j] = warna_default.a;
            }
        
        return;
    }

    // 
    //       *0
    // *1
    // 
    if(p0.x > p1.x && p0.y > p1.y){
        for(i = p1.x; i < p0.x; i++)
            for(j = p1.y; j < p0.y; j++){
                buffer_r[i][j] = warna_default.r;
                buffer_g[i][j] = warna_default.g;
                buffer_b[i][j] = warna_default.b;
                buffer_a[i][j] = warna_default.a;
            }
        
        return;
    }

    // 
    // *0
    //       *1
    // 
    if(p0.x < p1.x && p0.y > p1.y){
        for(i = p0.x; i < p1.x; i++)
            for(j = p1.y; j < p0.y; j++){
                buffer_r[i][j] = warna_default.r;
                buffer_g[i][j] = warna_default.g;
                buffer_b[i][j] = warna_default.b;
                buffer_a[i][j] = warna_default.a;
            }
        
        return;
    }
}

//memasukkan nilai buffer ke driver
void loadBuffer(){
    int i, j;

    titik titik_sementara;
    warna warna_sementara;
    warna warna_kosong = {0, 0, 0, 0};
    for(i = 0; i < GLOBAL_LAYAR_X; i++)
        for(j = 0; j < GLOBAL_LAYAR_Y; j++){
            titik_sementara.x = i;
            titik_sementara.y = j;

            if(buffer_r[i][j] && buffer_g[i][j] &&
            buffer_b[i][j] && buffer_a[i][j]){
                warna_sementara.r = buffer_r[i][j];
                warna_sementara.g = buffer_g[i][j];
                warna_sementara.b = buffer_b[i][j];
                warna_sementara.a = buffer_a[i][j];
            }else{
                warna_sementara = warna_kosong;
            }

            bufferDrawDot(titik_sementara, warna_sementara);
        }
}

void bufferDrawLine(titik p0, titik p1, warna c){
	int dx, dy, x, y, x_end, p, c1, c2;
	titik p2;
	
	dx = abs(p0.x - p1.x);
	dy = abs(p0.y - p1.y);
	
	p = 2 * dx - dy;
	c1 = 2 * dy;
	c2 = 2 * (dy-dx);
	
	if (p0.x > p1.x) {
		x = p1.x;
		y = p1.y;
		x_end = p0.x;
	} else {
		x = p0.x;
		y = p0.y;
		x_end = p1.x;
	}
	
	//setpixel(x, y)
	p2.x = x;
	p2.y = y;
	bufferDrawDot(p2, c);
	
	while (x < x_end) {
		if (dy <= dx) {
			x++;
		
			if (p < 0) {
				p += c1;
			} else {
				y++;
				p += c2;
			}
		} else {
			y++;
		
			if (p < 0) {
				p += c1;
			} else {
				x++;
				p += c2;
			}
		}
		
		
		//setpixel(x,y)
		p2.x = x;
		p2.y = y;
		bufferDrawDot(p2, c);
	}
}

void bufferDrawPlane(titik* p, warna c){
	int i;
	int size = (sizeof(p)-1)/sizeof(titik); //ini -1 karena ntar yg 
											//terakhir barengin ama 0 di luar loop
	for (i = 0; i < size; i++) {
		bufferDrawLine(p[i], p[i+1], c);
	}
	
	bufferDrawLine(p[i], p[0], c);
}

void bufferDrawCircle(titik p, warna c){

}

int  dotDistance(titik p1, titik p2){
    return 0;
}
