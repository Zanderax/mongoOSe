#include "ioc.h"
#include "main_loop.h"

int kmain(void)
{
	clear_screen();
	fb_move_cursor(0);
	main_loop();
	return 0;
}

