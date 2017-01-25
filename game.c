#include "tembakan.h"
#include "tabrakan.h"


void drawObjects();		//menggambar tembakan dan objekTabrak ke buffer
void preUpdate();		//(1)cek inputuser
void updatePosisi();	//(1)ubah posisi. (2)spawnObjek, (3)drawBuffer
void postUpdate();	 	//(1)cek kolisi, (2)loadbuffer ke layar




int main()
{
	drawObjects();	


	while(1)
	{
		preUpdate();
		updatePosisi();
		postUpdate();	

		usleep(17);  //60fps
	}

	return 0;
}