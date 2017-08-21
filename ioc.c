#include "ioc.h"
#include "io.h"

char * getFrameBuffer()
{
	return (char *)0x000B8000;
}

int write( char *buf, unsigned int len )
{
	int pos = 1920;
	unsigned int i;
	for( i = 0; i < len; ++i )
	{
		if (pos >= 2000)
		{
			move_lines_up();
			pos = 1920;
		}
		write_cell( pos++, buf[i], 15 );
	}
	move_lines_up();
	fb_move_cursor( 1921 );
	write_cell( 1920, '>', 15 );
	return i;
}

void move_lines_up()
{
	int l;
	for( l = 1; l < 25; ++l )
	{
		move_line_up(l);
	}
}

void move_line_up( int l )
{
	if(l==0)
		return;
	
	int c;
	char tmpChar, tmpColor;
	for( c = 0; c < 80; ++c )
	{
		read_cell( lctp(l,c), &tmpChar, &tmpColor );
		write_cell( lctp(l,c), 32, 15 );
		write_cell( lctp(l-1,c), tmpChar, tmpColor );
	}
}

int lctp( int l, int c )
{
	return (l%25)*80 + c;
}

void clear_screen()
{
	int pos;
	for( pos = 0; pos < 2000; ++pos )
	{
		write_cell( pos, 32, 15 );
	}
}

void read_cell( int pos, char * character, char * color )
{
	char * fb = getFrameBuffer(); 
	*character = fb[pos*2];
	*color = fb[pos*2+1];
}

void write_cell( int pos, char character, char color )
{
	char * fb = getFrameBuffer(); 
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
