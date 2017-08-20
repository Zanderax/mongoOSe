#ifndef IOC_H
#define IOC_H

/*void write( char * buf, unsigned int len );*/
void clear_screen();
void write_cell( int pos, char character, char color );
void fb_move_cursor(unsigned short pos);

#endif //IOC_H
