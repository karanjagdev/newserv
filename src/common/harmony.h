#ifndef _HARMONYCORE_H
#define _HARMONYCORE_H


#include "../common/harmserv.h"

void harmony_core_init();
void harmony_core_final();

extern struct HARMSRV_EA_FUNCS   *ea_funcs;
extern struct HARMSRV_HARM_FUNCS *harm_funcs;

#define HARMSW_EATHENA         0
#define HARMSW_RATHENA_GROUP   1

// Hercules recently introduced lots of 'interfaces', for reasons I can only speculate about.
// There is no apparent benefit from this change, but the code gets slower due to required memory
// dereferencing every time such an interface method is called. Plus it breaks pretty much all
// source modifications, including Harmony. If you have any plausible explanation for this
// please enlighten me at info@harmonize.it. Thanks!
#ifdef HARMONY_USE_POINTLESS_OOP_INTERFACE
	#define _athena_add_timer             iTimer->add_timer
	#define _athena_add_timer_interval    iTimer->add_timer_interval
	#define _athena_delete_timer          iTimer->delete_timer
	#define _athena_gettick               iTimer->gettick
#else
	#define _athena_add_timer             add_timer
	#define _athena_add_timer_interval    add_timer_interval
	#define _athena_delete_timer          delete_timer
	#define _athena_gettick               gettick
#endif

#endif

