global loader										;entry point for ELF

MAGIC_NUMBER equ 0x1BADB002
FLAGS				 equ 0x0
CHECKSUM		 equ -MAGIC_NUMBER
																;magic number + checksum + flags should equal 0

section .bss
align 4
kernel_stack:									;label points to beginning of memory
	resb KERNEL_STACK_SIZE			;reserve stack for the kernel


section .text
align 4													;code myst be 4 byte aligned
	dd MAGIC_NUMBER								;write magic number to the machine code
	dd FLAGS											;ditto the flags
	dd CHECKSUM										;ditto the checksum

loader:													;the loader label defined as entry point in linker script
	mov eax, 0xCAFEBABE						;place the number 0xCAFEBABE in the eax reg

KERNEL_STACK_SIZE equ 4096			;size of stack in bytes

mov esp, kernel_stack + KERNEL_STACK_SIZE ;point esp to start of the stack

extern kmain
call kmain

.jobs:
	jmp .jobs
