/* startup.c */

#include <stdint.h>

extern unsigned int __stack;
//extern unsigned int __etext;
extern unsigned int __erodata;
extern unsigned int __data_start__;
extern unsigned int __data_end__;
extern unsigned int __bss_start__;
extern unsigned int __bss_end__;

extern int main(void);
//extern void SystemInit(void);

/* Cortex M0 core interrupt handlers */
void Reset_Handler(void);
void NMI_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void HardFault_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void SVC_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void DebugMon_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void PendSV_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void SysTick_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
/* LPC13xx specific interrupt handlers */
void WAKEUP_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void I2C_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void TIMER_16_0_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void TIMER_16_1_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void TIMER_32_0_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void TIMER_32_1_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void SSP_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void UART_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void USB_IRQ_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void USB_FIQ_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void ADC_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void WDT_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void BOD_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void EINT3_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void EINT2_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void EINT1_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));
void EINT0_Handler(void) __attribute__ ((weak, alias ("Dummy_Handler")));

void Dummy_Handler(void);
void _endless_loop__(void);

void *vector_table[] __attribute__ ((section(".vectors"))) = {
    &__stack,
    Reset_Handler,
    NMI_Handler,
    HardFault_Handler,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    SVC_Handler,
    DebugMon_Handler,
    0,
    PendSV_Handler,
    SysTick_Handler,

    /* LPC13xx specific interrupt vectors */
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler, WAKEUP_Handler,
    I2C_Handler,
    TIMER_16_0_Handler,
    TIMER_16_1_Handler,
    TIMER_32_0_Handler,
    TIMER_32_1_Handler,
    SSP_Handler,
    UART_Handler,
    USB_IRQ_Handler,
    USB_FIQ_Handler,
    ADC_Handler,
    WDT_Handler,
    BOD_Handler,
    EINT3_Handler,
    EINT2_Handler,
    EINT1_Handler,
    EINT0_Handler,
};

void Reset_Handler(void) {
    unsigned int *src, *dst;

    /* Copy data section from flash to RAM */
    src = &__erodata;
    dst = &__data_start__;
    while (dst < &__data_end__)
        *dst++ = *src++;

    /* Clear the bss section */
    dst = &__bss_start__;
    while (dst < &__bss_end__)
        *dst++ = 0;

    main();
}

void Dummy_Handler(void) {
    while (1)
        ;
}

void _endless_loop__(void) {
    while (1)
        ;
}
