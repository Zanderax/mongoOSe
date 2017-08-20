#include "ioc.h"
#include "io.h"

void clear_screen()
{
	int pos;
	for( pos = 0; pos < 2000; ++pos )
	{
		write_cell( pos, 32, 15 );
	}
}

void write_cell( int pos, char character, char color )
{
	char * fb = (char *)0x000B8000;
	fb[pos*2] = character;
	fb[pos*2+1] = color;
}

#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

/** fb_move_cursor:
*  Moves the cursor of the framebuffer to the given position
*
*  @param pos The new position of the cursor
*/
void fb_move_cursor(unsigned short pos)
{
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT,    pos & 0x00FF);
}
