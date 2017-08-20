ENTRY(loader)										/*name of the entry label*/

SECTIONS {
	. = 0x00100000;								/*code loaded at 1mb*/

	.text ALIGN (0x1000) :				/*align at 4kb*/
	{
		*(.text)										/*align all text sections from all files*/
	}

	.rodata ALIGN (0x1000) :			/*align at 4kb*/
	{
		*(.rodata)										/*align all read-only data sections from all files*/
	}

	.data ALIGN (0x1000) :				/*align at 4kb*/
	{
		*(.data)										/*align all data sections from all files*/
	}

	.bss ALIGN (0x1000) :					/*align at 4kb*/
	{
		*(.COMMON)									/*align all COMMON sections from all files*/
		*(.bss*)											/*align all bss sections from all files*/
	}

}
