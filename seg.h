#ifndef SEG_H
#define SEG_H

/* loadgdt
* Sends the address of a gdt struct that contains the address of the Global Descriptor Table to be loaded by the lgdt instruction.
*
* @param address The address of the gdt struct to be loaded
*/
void loadgdt( unsigned int address );

#endif //SEG_H
