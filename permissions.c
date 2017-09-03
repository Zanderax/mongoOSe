#include "permissions.h"
#include "seg.h"

struct gdt
{
	unsigned int address;
	unsigned int size;
}__attribute__((packed));

struct gdt_entry 
{
	unsigned short 	limit_low; 
	unsigned short 	base_low; 
	unsigned char 	base_middle; 
	unsigned char 	access; 
	unsigned char 	granularity; 
	unsigned char 	access; 
}__attribute__((packed));

int instantiate_gdt( unsigned int size )
{
	//GDT needs at least 3 descriptors
	//Null descriptor, code segment, data segment
	if(size < 3)
		return -1;
	gdt_entry
}

void write_gdt( unsigned int address, unsigned int size)
{
	gdt new_gdt;
	new_gdt.address = address;
	new_gdt.size = size;
	loadgdt(&new_gdt);
}
