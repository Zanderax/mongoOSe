#ifndef IOC_H
#define IOC_H

char * getFrameBuffer();
int write( char * buf, unsigned int len );
void clear_screen();
void read_cell( int pos, char * character, char * color );
void write_cell( int pos, char character, char color );
void fb_move_cursor(unsigned short pos);
void move_lines_up();
void move_line_up( int l );
int lctp( int l, int c ); // Line Column to Position
void fb_move_cursor(unsigned short pos);

#endif //IOC_H
