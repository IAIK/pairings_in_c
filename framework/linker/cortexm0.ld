/* Linker script to configure memory regions. */

/* Created using Cortex-M0 linker-script-template for GCC available from
   CMSIS 3.0(http://www.onarm.com/CMSIS/) by https://github.com/viswesr .

   Should be use with GCC binary from https://launchpad.net/gcc-arm-embedded (Completely Open Source ARM Cortex-M/R GCC builds provided by ARM)
*/

MEMORY
{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 0x080000   /*  256k */
/*  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 0x040000   /*  256k */
  RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 0x001000   /* 4k */
}

/* Library configurations */
/*GROUP(libgcc.a libc.a libm.a libnosys.a)*/

/* Linker script to place sections and symbol values. Should be used together
 * with other linker script that defines memory regions FLASH and RAM.
 * It references following symbols, which must be defined in code:
 *   Reset_Handler : Entry of reset handler
 *
 * It defines following symbols, which code can use without definition:
 *   __exidx_start
 *   __exidx_end
 *   __etext
 *   __data_start__
 *   __preinit_array_start
 *   __preinit_array_end
 *   __init_array_start
 *   __init_array_end
 *   __fini_array_start
 *   __fini_array_end
 *   __data_end__
 *   __bss_start__
 *   __bss_end__
 *   __end__
 *   end
 *   __HeapLimit
 *   __StackLimit
 *   __StackTop
 *   __stack
 */
ENTRY(Reset_Handler)

SECTIONS
{
	.text :
	{
		KEEP(*(.vectors))
		*(.text*)

		. = ALIGN(4);
		
		KEEP(*(.init))
		KEEP(*(.fini))
		
		. = ALIGN(4);
	} > FLASH
	
	__etext = .;

	.rodata :
	{
		. = ALIGN(4);
		*(.rodata*)
		. = ALIGN(4);
	} > FLASH
	
	__erodata = .;
	
	.data : AT (__erodata)
	{
		__data_start__ = .;
		*(vtable)
		*(.data*)

		. = ALIGN(4);
		/* preinit data */
		PROVIDE_HIDDEN (__preinit_array_start = .);
		KEEP(*(.preinit_array))
		PROVIDE_HIDDEN (__preinit_array_end = .);

		. = ALIGN(4);
		/* init data */
		PROVIDE_HIDDEN (__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		PROVIDE_HIDDEN (__init_array_end = .);


		. = ALIGN(4);
		/* finit data */
		PROVIDE_HIDDEN (__fini_array_start = .);
		KEEP(*(SORT(.fini_array.*)))
		KEEP(*(.fini_array))
		PROVIDE_HIDDEN (__fini_array_end = .);

		. = ALIGN(4);
		/* All data end */
		__data_end__ = .;

	} > RAM 


	.bss : AT (__erodata + SIZEOF(.data))
	{
		__bss_start__ = .;
		*(.bss*)
		*(COMMON)
		__bss_end__ = .;
	} > RAM

	.heap :
	{
		__end__ = .;
		end = __end__;
		*(.heap*)
		__HeapLimit = .;
	} > RAM

	/* .stack_dummy section doesn't contains any symbols. It is only
	 * used for linker to calculate size of stack sections, and assign
	 * values to stack symbols later */
	.stack_dummy :
	{
		*(.stack)
	} > RAM

	/* Set stack top to end of RAM, and stack limit move down by
	 * size of stack_dummy section */
	__StackTop = ORIGIN(RAM) + LENGTH(RAM);
	__StackLimit = __StackTop - SIZEOF(.stack_dummy);
	PROVIDE(__stack = __StackTop);

	/* Check if data + heap + stack exceeds RAM limit */
	ASSERT(__StackLimit >= __HeapLimit, "region RAM overflowed with stack")
}

