#include "vid_sync.h"

void vid_sync::Prc1()
{
   //Initialization
	vsync.write(0);
	hsync.write(0);
	valid.write(0);
	data.write(0);
   wait();

   while(true)
   {
	   wait();//vf_blank
	   vsync.write(1);
	   for(int v=0; v<480; v++)
	   {
		   hsync.write(1);
		   wait();
		   vsync.write(0);
		   hsync.write(0);
		   wait();//hf_blank
		   for(int h=0; h<640; h++)
		   {
			   data.write(h);
			   valid.write(1);
			   wait();
		   }
		   data.write(0);
		   valid.write(0);
	   }
   } //end of while(true)
}
