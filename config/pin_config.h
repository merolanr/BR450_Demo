#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[CMU]
// [CMU]$

// $[LFXO]
// [LFXO]$

// $[PRS.ASYNCH0]
// [PRS.ASYNCH0]$

// $[PRS.ASYNCH1]
// [PRS.ASYNCH1]$

// $[PRS.ASYNCH2]
// [PRS.ASYNCH2]$

// $[PRS.ASYNCH3]
// [PRS.ASYNCH3]$

// $[PRS.ASYNCH4]
// [PRS.ASYNCH4]$

// $[PRS.ASYNCH5]
// [PRS.ASYNCH5]$

// $[PRS.ASYNCH6]
// [PRS.ASYNCH6]$

// $[PRS.ASYNCH7]
// [PRS.ASYNCH7]$

// $[PRS.ASYNCH8]
// [PRS.ASYNCH8]$

// $[PRS.ASYNCH9]
// [PRS.ASYNCH9]$

// $[PRS.ASYNCH10]
// [PRS.ASYNCH10]$

// $[PRS.ASYNCH11]
// [PRS.ASYNCH11]$

// $[PRS.SYNCH0]
// [PRS.SYNCH0]$

// $[PRS.SYNCH1]
// [PRS.SYNCH1]$

// $[PRS.SYNCH2]
// [PRS.SYNCH2]$

// $[PRS.SYNCH3]
// [PRS.SYNCH3]$

// $[GPIO]
// GPIO SWV on PA03
#define GPIO_SWV_PORT                            gpioPortA
#define GPIO_SWV_PIN                             3

// [GPIO]$

// $[TIMER0]
// [TIMER0]$

// $[TIMER1]
// [TIMER1]$

// $[TIMER2]
// [TIMER2]$

// $[TIMER3]
// [TIMER3]$

// $[TIMER4]
// [TIMER4]$

// $[USART0]
// USART0 CLK on PD03
#define USART0_CLK_PORT                          gpioPortD
#define USART0_CLK_PIN                           3

// USART0 CS on PD02
#define USART0_CS_PORT                           gpioPortD
#define USART0_CS_PIN                            2

// USART0 CTS on PC01
#define USART0_CTS_PORT                          gpioPortC
#define USART0_CTS_PIN                           1

// USART0 RTS on PC02
#define USART0_RTS_PORT                          gpioPortC
#define USART0_RTS_PIN                           2

// USART0 RX on PD01
#define USART0_RX_PORT                           gpioPortD
#define USART0_RX_PIN                            1

// USART0 TX on PD00
#define USART0_TX_PORT                           gpioPortD
#define USART0_TX_PIN                            0

// [USART0]$

// $[USART1]
// [USART1]$

// $[I2C1]
// [I2C1]$

// $[PDM]
// [PDM]$

// $[LETIMER0]
// [LETIMER0]$

// $[IADC0]
// [IADC0]$

// $[I2C0]
// [I2C0]$

// $[EUART0]
// [EUART0]$

// $[PTI]
// PTI DFRAME on PC05
#define PTI_DFRAME_PORT                          gpioPortC
#define PTI_DFRAME_PIN                           5

// PTI DOUT on PC04
#define PTI_DOUT_PORT                            gpioPortC
#define PTI_DOUT_PIN                             4

// [PTI]$

// $[MODEM]
// [MODEM]$

// $[CUSTOM_PIN_NAME]
// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

