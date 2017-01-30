#include "tembakan.h"
#include "tabrakan.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

void drawObjects();		//menggambar tembakan dan objekTabrak ke buffer
void *preUpdate();		//(1)cek inputuser
void updatePosisi();	//(1)ubah posisi. (2)spawnObjek, (3)drawBuffer
void postUpdate();	 	//(1)cek kolisi, (2)loadbuffer ke layar

objekTabrak pesawat[1];
objekTabrak peluru[5];
titik pl0 = {0,0};
titik pl1 = {1366,700};
pthread_t thread0; 		//thread input capture
int fd; 				//something-something keylogger
struct input_event ev;	//something-something keylogger
ssize_t n;
int user_input = -99;
titik p0 = {400,100};
titik p1 = {600,600};
titik p2 = {300,650};
titik p3 = {500,650};
titik p8 = {400, 400};
titik p9 = {0,0};
titik p10 = {1000,0};
titik p11 = {0,600};
titik p12 = {1000,700};

int main(){
//**setup-pendengar-keyboard********************************************************************
	// Input keyboard device file
    const char *dev = "/dev/input/by-path/pci-0000:00:14.0-usb-0:1:1.0-event-kbd";
    
    // Open device for reference
    fd = open(dev, O_RDONLY);

    // Check if device is opened
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }

//**setup-objek-game****************************************************************************
	init_fb();
	warna c = {255,255,255,255};
	warna c0 = {255,255,255,255};
	c0.r += 30;
    c0.g += 30;
    c0.b += 30;

	titik pt[3];
	pt[0] = pl0;
	pt[1] = p0;
	pt[2] = p1;

	spawnObjek('a',p0);

	while(1){
		refreshBuffer(pl0,pl1);
		gambarObjek();
		gambarTembakan();
		// bufferDrawLine(p8, p9, c);
		// bufferDrawLine(p8, p10, c);
		// bufferDrawLine(p8, p11, c);
		// bufferDrawLine(p8, p12, c);
		puterTembakan(2);
		loadBuffer();
		usleep(100000);
	}	

//**game-loop***********************************************************************************
	// pthread_create(&thread0, NULL, preUpdate, NULL);
	// while(1)
	// {
	// 	//preUpdate();
	// 	updatePosisi();
	// 	postUpdate();	
	// 	usleep(17);
	// 	puterTembakan(10);
	// }

//**garbaging***********************************************************************************
	//pthread_join(thread0, NULL);
	garbage_fb();
    fflush(stdout);
    fprintf(stderr, "%s.\n", strerror(errno));
	return 0;
}



void *preUpdate(){
	while(1){
		// get stored value on keyboard device reference file
	    n = read(fd, &ev, sizeof ev);
	    // check if no stored value on device file
	    if (n == (ssize_t)-1) {

	    }

	    // if keystroke is stored on keyboard device reference file
	    if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2){
	        if(ev.value == 1){ // when it pressed, 0 is released
	            switch(ev.code){
	                case 57:
	                    // Space trigger
	                    user_input = 0;
	                    break;

	                case 105:
	                    // Left arrow trigger
	                    user_input = -1;
	                    break;

	                case 106:
	                    // Right arrow trigger
	                    user_input = 1;
	                    break;

	                default:
	                    break;

	            }
	        }
	    }
	}
}

void updatePosisi(){
	if(user_input == 0){
		spawnObjek('b',p1);
		user_input = -99;
	}
	else if(user_input == 1){
		puterTembakan(user_input);
		user_input = -99;
	}
	else if(user_input == -1){
		puterTembakan(user_input);
		user_input = -99;
	}

	refreshBuffer(pl0,pl1);
	gambarObjek();
	gambarTembakan();
	jalanObjek();
}

void postUpdate(){
	cekTabrakanObjek(30);

	for(int i=0; i<1; i++){
		if(pesawat[i].isTabrakan == 1){
			gambarHancur(pesawat[i].posisi);
			pesawat[i].isTabrakan = -1;
		}
	}

	for(int i=0; i<5; i++){
		if(peluru[i].isTabrakan == 1){
			peluru[i].isTabrakan = -1;
		}
	}

	loadBuffer();
}