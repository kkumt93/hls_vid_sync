#ifndef VID_SYNC_H
#define VID_SYNC_H

#include <systemc.h>

SC_MODULE(vid_sync)
{
	//Ports
	sc_in  <bool>  clock;
	sc_in  <bool>  reset;
	sc_out <bool>  vsync;
	sc_out <bool>  hsync;
	sc_out <bool>  valid;
	sc_out <sc_uint<10> > data;

	//Variables

	//Process Declaration
	void Prc1();

	//Constructor
	SC_CTOR(vid_sync)
	{
		//Process Registration
		SC_CTHREAD(Prc1,clock.pos());
		reset_signal_is(reset,true);

	}
};

#endif
