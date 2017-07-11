
#include <systemc.h>
#include "vid_sync.h"


int sc_main (int argc , char *argv[])
{


	sc_clock clock("clock",10,SC_NS); // Create a 10ns period clock signal
	sc_signal <bool> reset;
	sc_signal <bool> vsync;
	sc_signal <bool> hsync;
	sc_signal <bool> valid;
	sc_signal <sc_uint<10> > data;
	vid_sync U_vid_sync("U_vid_sync");


	// Generate a clock and reset to drive the sim
	U_vid_sync.clock(clock);
	U_vid_sync.reset(reset);
	U_vid_sync.vsync(vsync);
	U_vid_sync.hsync(hsync);
	U_vid_sync.valid(valid);
	U_vid_sync.data(data);

    sc_trace_file *trace_f;
    trace_f = sc_create_vcd_trace_file("wave");

    sc_trace( trace_f, clock, "clock");
    sc_trace( trace_f, reset, "reset");
    sc_trace( trace_f, vsync, "vsync");
    sc_trace( trace_f, hsync, "hsync");
    sc_trace( trace_f, valid, "valid");
    sc_trace( trace_f, data, "data");

	// start simulation
	sc_start(20, SC_NS);
	reset = 1;
	sc_start(20, SC_NS);
	reset = 0;
	//sc_start(10*640*480*2, SC_NS);
	sc_start(20*640*480*2, SC_NS);

	return 0;
};
