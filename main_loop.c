#include "main_loop.h"
#include "ioc.h"

int main_loop()
{
	serial_write('S');
	int i;
	for( i = 0; i < 100; ++i)
	{
		write( "Wake up Mr Freeman!", 20 );
		unsigned long t;
		for( t = 0; t < 8000000; ++t);
	}
	
	return 0;
}
