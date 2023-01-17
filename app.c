/***************************************************************************//**
 * @file
 * @brief Core application logic.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/
#include "em_common.h"
#include "app_assert.h"
#include "sl_bluetooth.h"
#include "gatt_db.h"
#include "app.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_iadc.h"
#include "em_gpio.h"
#include "sl_imu.h"
#include "stdio.h"
#include "em_i2c.h"
#include "em_emu.h"
#include "lmp91000.h"

#define CLK_SRC_ADC_FREQ          20000000 // CLK_SRC_ADC
#define CLK_ADC_FREQ              10000000 // CLK_ADC - 10MHz max in normal mode

#define IADC_INPUT_0_PORT_PIN     iadcPosInputPortBPin0;
#define IADC_INPUT_1_PORT_PIN     iadcNegInputPortBPin1;

#define IADC_INPUT_0_BUS          BBUSALLOC
#define IADC_INPUT_0_BUSALLOC     GPIO_BBUSALLOC_BEVEN0_ADC0
#define IADC_INPUT_1_BUS          BBUSALLOC
#define IADC_INPUT_1_BUSALLOC     GPIO_BBUSALLOC_BODD0_ADC0
// Defines
#define I2C_TXBUFFER_SIZE                 10
#define I2C_RXBUFFER_SIZE                 10

// Buffers
uint8_t i2c_txBuffer[I2C_TXBUFFER_SIZE];
uint8_t i2c_rxBuffer[I2C_RXBUFFER_SIZE];

// Transmission flags
volatile bool i2c_startTx;

static volatile int32_t sample;
static volatile double singleResult; // Volts


// The advertising set handle allocated from Bluetooth stack.
static uint8_t advertising_set_handle = 0xff;

static uint8_t counter = 0;

//static volatile int16_t a_vec[3];

/**************************************************************************//**
 * Application Init.
 *****************************************************************************/

void initCMU(void)
{
  // Enable clocks to the I2C and GPIO
  CMU_ClockEnable(cmuClock_I2C0, true);
  CMU_ClockEnable(cmuClock_GPIO, true);
}


//void initI2C(void)
//{
//  // Use default settings
//  I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
//
//  // Using PA0 (SDA) and PA1 (SCL) LMP2
//  GPIO_PinModeSet(gpioPortA, 0, gpioModeWiredAndPullUpFilter, 1);
//  GPIO_PinModeSet(gpioPortA, 1, gpioModeWiredAndPullUpFilter, 1);
//
//  // Route I2C pins to GPIO
//  GPIO->I2CROUTE[0].SDAROUTE = (GPIO->I2CROUTE[0].SDAROUTE & ~_GPIO_I2C_SDAROUTE_MASK)
//                        | (gpioPortA << _GPIO_I2C_SDAROUTE_PORT_SHIFT
//                        | (5 << _GPIO_I2C_SDAROUTE_PIN_SHIFT));
//  GPIO->I2CROUTE[0].SCLROUTE = (GPIO->I2CROUTE[0].SCLROUTE & ~_GPIO_I2C_SCLROUTE_MASK)
//                        | (gpioPortA << _GPIO_I2C_SCLROUTE_PORT_SHIFT
//                        | (6 << _GPIO_I2C_SCLROUTE_PIN_SHIFT));
//  GPIO->I2CROUTE[0].ROUTEEN = GPIO_I2C_ROUTEEN_SDAPEN | GPIO_I2C_ROUTEEN_SCLPEN;
//
//  // Initialize the I2C
//  I2C_Init(I2C0, &i2cInit);
//
//  // Set the status flags and index
//  i2c_startTx = false;
//
//  // Enable automatic STOP on NACK
//  I2C0->CTRL = I2C_CTRL_AUTOSN;
//}
//
//void lmp_read(uint8_t targetAddress, uint8_t *rxBuff) //i2c read function, used in other functions for communication with lmp91000
//{
//   uint8_t numBytes = 1;
//  // Transfer structure
//  I2C_TransferSeq_TypeDef i2cTransfer;
//  I2C_TransferReturn_TypeDef result;
//
//  // Initialize I2C transfer
//  i2cTransfer.addr          = LMP91000_I2C_ADDRESS;
//  i2cTransfer.flags         = I2C_FLAG_WRITE_READ; // must write target address before reading
//  i2cTransfer.buf[0].data   = &targetAddress;
//  i2cTransfer.buf[0].len    = 1;
//  i2cTransfer.buf[1].data   = rxBuff;
//  i2cTransfer.buf[1].len    = numBytes;
//
//  result = I2C_TransferInit(I2C0, &i2cTransfer);
//
//  // Send data
//  while (result == i2cTransferInProgress) {
//    result = I2C_Transfer(I2C0);
//  }
//
//}

//void lmp_write(uint8_t targetAddress, uint8_t *txBuff) //i2c write function, used in other functions for communication with lmp91000
//{
//  uint8_t numBytes = 1;
//
//  // Transfer structure
//  I2C_TransferSeq_TypeDef i2cTransfer;
//  I2C_TransferReturn_TypeDef result;
//  uint8_t txBuffer[I2C_TXBUFFER_SIZE + 1];
//
//  txBuffer[0] = targetAddress;
//  for(int i = 0; i < numBytes; i++)
//  {
//      txBuffer[i + 1] = txBuff[i];
//  }
//
//  // Initialize I2C transfer
//  i2cTransfer.addr          = LMP91000_I2C_ADDRESS;
//  i2cTransfer.flags         = I2C_FLAG_WRITE;
//  i2cTransfer.buf[0].data   = txBuffer;
//  i2cTransfer.buf[0].len    = numBytes + 1;
//  i2cTransfer.buf[1].data   = NULL;
//  i2cTransfer.buf[1].len    = 0;
//
//  result = I2C_TransferInit(I2C0, &i2cTransfer);
//
//  // Send data
//  while (result == i2cTransferInProgress) {
//    result = I2C_Transfer(I2C0);
//  }
//}
//
//bool isReady(void) const
//{
//    return lmp_read(LMP91000_STATUS_REG)==LMP91000_READY;
//}
//
//void lock(void)
//{
//    lmp_write(LMP91000_LOCK_REG, LMP91000_WRITE_LOCK);
//}
//
//void unlock(void)
//{
//    lmp_write(LMP91000_LOCK_REG, LMP91000_WRITE_UNLOCK);
//}

////set transimpedance amplifier gain
//void setGain(uint8_t user_gain)
//{
//    unlock();
//    uint8_t data = read(LMP91000_TIACN_REG);
//    data &= ~(7 << 2); //clears bits 2-4
//    data |= (user_gain << 2); //writes to bits 2-4
//    lmp_write(LMP91000_TIACN_REG, data);
//}

////set internal resistance
//void setRLoad(uint8_t load)
//{
//    unlock();
//    uint8_t data = read(LMP91000_TIACN_REG);
//    data &= ~3; //clears 0th and 1st bits
//    data |= load; //writes to 0th and 1st bits
//    lmp_write(LMP91000_TIACN_REG, data);
//}
//
////places LMP in sleep mode (0.6 uA current)
//void sleep(void)
//{
//    uint8_t data = read(LMP91000_MODECN_REG);
//    data &= ~(0x07);
//    lmp_write(LMP91000_MODECN_REG, data);
//}
//
////sets device to 2-electrode potentiometric mode
//void setTwoLead(void)
//{
//    uint8_t data = read(LMP91000_MODECN_REG);
//    data &= ~(0x07);
//    data |= (0x01);
//    lmp_write(LMP91000_MODECN_REG, data);
//}
//
////sets device to 3-electrode potentiometric mode
//void setThreeLead(void)
//{
//    uint8_t data = read(LMP91000_MODECN_REG);
//    data &= ~(0x07);
//    data |= (0x03);
//    lmp_write(LMP91000_MODECN_REG, data);
//}
//
////places device in standby mode
//void standby(void)
//{
//    uint8_t data = read(LMP91000_MODECN_REG);
//    data &= ~(0x07);
//    data |= (0x02);
//    lmp_write(LMP91000_MODECN_REG, data);
//}
//
////measure current of cell
//void measureCell(void)
//{
//    uint8_t data = read(LMP91000_MODECN_REG);
//    data &= ~(0x07); //clears the first three bits
//    data |= (0x06);
//    lmp_write(LMP91000_MODECN_REG, data);
//}
//
//void getTemp(void)
//{
//    uint8_t data = read(LMP91000_MODECN_REG);
//    data |= (0x07);
//    write(LMP91000_MODECN_REG, data);
//}
//
//void lmp1_enable(void)
//{
//  // Using menb (PA13)
//  GPIO_PinOutClear(gpioPortA, 13); //set PA3 low (system enable)
//  //GPIO_PinOutClear(gpioPortA, pin); //set PA3 low (system enable)
//}
//
//void lmp1_disable(void)
//{
//  // Using menb (PA13)
//  GPIO_PinOutSet(gpioPortA, 13); //set PA3 disable (system disable)
//  //GPIO_PinOutSet(gpioPortA, pin); //set PA3 disable (system disable)
//}
//
//
void initIADC (void)
{
  // Declare init structs
  IADC_Init_t init = IADC_INIT_DEFAULT;
  IADC_AllConfigs_t initAllConfigs = IADC_ALLCONFIGS_DEFAULT;
  IADC_InitSingle_t initSingle = IADC_INITSINGLE_DEFAULT;
  IADC_SingleInput_t initSingleInput = IADC_SINGLEINPUT_DEFAULT;

  // Enable IADC0 and GPIO clock branches

  /* Note: For EFR32xG21 radio devices, library function calls to
   * CMU_ClockEnable() have no effect as oscillators are automatically turned
   * on/off based on demand from the peripherals; CMU_ClockEnable() is a dummy
   * function for EFR32xG21 for library consistency/compatibility.
   */
  CMU_ClockEnable(cmuClock_IADC0, true);
  CMU_ClockEnable(cmuClock_GPIO, true);

  // Reset IADC to reset configuration in case it has been modified by
  // other code
  IADC_reset(IADC0);

  // Select clock for IADC
  CMU_ClockSelectSet(cmuClock_IADCCLK, cmuSelect_FSRCO);  // FSRCO - 20MHz

  // Modify init structs and initialize
  init.warmup = iadcWarmupKeepWarm;

  // Set the HFSCLK prescale value here
  init.srcClkPrescale = IADC_calcSrcClkPrescale(IADC0, CLK_SRC_ADC_FREQ, 0);

  // Configuration 0 is used by both scan and single conversions by default
  // Use internal bandgap (supply voltage in mV) as reference
  initAllConfigs.configs[0].reference = iadcCfgReferenceInt1V2;
  initAllConfigs.configs[0].vRef = 1210;
  initAllConfigs.configs[0].analogGain = iadcCfgAnalogGain0P5x;

  // Divides CLK_SRC_ADC to set the CLK_ADC frequency
  initAllConfigs.configs[0].adcClkPrescale = IADC_calcAdcClkPrescale(IADC0,
                                             CLK_ADC_FREQ,
                                             0,
                                             iadcCfgModeNormal,
                                             init.srcClkPrescale);

  // Assign pins to positive and negative inputs in differential mode
  initSingleInput.posInput   = IADC_INPUT_0_PORT_PIN;
  initSingleInput.negInput   = IADC_INPUT_1_PORT_PIN;

  // Initialize the IADC
  IADC_init(IADC0, &init, &initAllConfigs);

  // Initialize the Single conversion inputs
  IADC_initSingle(IADC0, &initSingle, &initSingleInput);

  // Allocate the analog bus for ADC0 inputs
  GPIO->IADC_INPUT_0_BUS |= IADC_INPUT_0_BUSALLOC;
  GPIO->IADC_INPUT_1_BUS |= IADC_INPUT_1_BUSALLOC;
}

SL_WEAK void app_init(void)
{
  /////////////////////////////////////////////////////////////////////////////
  // Put your additional application init code here!                         //
  // This is called once during start-up.                                    //
  /////////////////////////////////////////////////////////////////////////////
  CHIP_Init();
  initIADC();
//  sl_imu_init();

//  // Configure sample rate
//  sl_imu_configure(10);
//
//  // Recalibrate gyro
//  sl_imu_calibrate_gyro();


}

/**************************************************************************//**
 * Application Process Action.
 *****************************************************************************/
SL_WEAK void app_process_action(void)
{
  /////////////////////////////////////////////////////////////////////////////
  // Put your additional application code here!                              //
  // This is called infinitely.                                              //
  // Do not call blocking functions from here!                               //
  /////////////////////////////////////////////////////////////////////////////
}

/**************************************************************************//**
 * Bluetooth stack event handler.
 * This overrides the dummy weak implementation.
 *
 * @param[in] evt Event coming from the Bluetooth stack.
 *****************************************************************************/
void sl_bt_on_event(sl_bt_msg_t *evt)
{
  sl_status_t sc;
  bd_addr address;
  uint8_t address_type;
  uint8_t system_id[8];

  // GATT Response Variables
  size_t    sz    = 0;
  uint8_t*  p     = NULL;
  uint16_t  sent;
  uint8_t   status;           // Error codes

  sl_bt_evt_gatt_server_user_read_request_t *request;
  uint8_t currentVal;

  switch (SL_BT_MSG_ID(evt->header)) {
    // -------------------------------
    // This event indicates the device has started and the radio is ready.
    // Do not call any stack command before receiving this boot event!
    case sl_bt_evt_system_boot_id:

      // Extract unique ID from BT Address.
      sc = sl_bt_system_get_identity_address(&address, &address_type);
      app_assert_status(sc);

      // Pad and reverse unique ID to get System ID.
      system_id[0] = address.addr[5];
      system_id[1] = address.addr[4];
      system_id[2] = address.addr[3];
      system_id[3] = 0xFF;
      system_id[4] = 0xFE;
      system_id[5] = address.addr[2];
      system_id[6] = address.addr[1];
      system_id[7] = address.addr[0];

      sc = sl_bt_gatt_server_write_attribute_value(gattdb_system_id,
                                                   0,
                                                   sizeof(system_id),
                                                   system_id);
      app_assert_status(sc);

      // Create an advertising set.
      sc = sl_bt_advertiser_create_set(&advertising_set_handle);
      app_assert_status(sc);

      // Generate data for advertising
      sc = sl_bt_legacy_advertiser_generate_data(advertising_set_handle,
                                                 sl_bt_advertiser_general_discoverable);
      app_assert_status(sc);

      // Set advertising interval to 100ms.
      sc = sl_bt_advertiser_set_timing(
        advertising_set_handle,
        160, // min. adv. interval (milliseconds * 1.6)
        160, // max. adv. interval (milliseconds * 1.6)
        0,   // adv. duration
        0);  // max. num. adv. events
      app_assert_status(sc);
      // Start advertising and enable connections.
      sc = sl_bt_legacy_advertiser_start(advertising_set_handle,
                                         sl_bt_advertiser_connectable_scannable);
      app_assert_status(sc);
      break;

    // -------------------------------
    // This event indicates that a new connection was opened.
    case sl_bt_evt_connection_opened_id:
      break;

    // -------------------------------
    // This event indicates that a connection was closed.
    case sl_bt_evt_connection_closed_id:
      // Generate data for advertising
      sc = sl_bt_legacy_advertiser_generate_data(advertising_set_handle,
                                                 sl_bt_advertiser_general_discoverable);
      app_assert_status(sc);

      // Restart advertising after client has disconnected.
      sc = sl_bt_legacy_advertiser_start(advertising_set_handle,
                                         sl_bt_advertiser_connectable_scannable);
      app_assert_status(sc);
      break;

    case sl_bt_evt_gatt_server_user_read_request_id:

      request = &(evt->data.evt_gatt_server_user_read_request);
      switch (request->characteristic) {
        case gattdb_read_counter:
          currentVal = counter++;

          sz = sizeof(currentVal);
          p  = &currentVal;

          break;

        case gattdb_read_iadc:
          IADC_command(IADC0, iadcCmdStartSingle);

          // Wait for conversion to be complete
          while((IADC0->STATUS & (_IADC_STATUS_CONVERTING_MASK
                      | _IADC_STATUS_SINGLEFIFODV_MASK)) != IADC_STATUS_SINGLEFIFODV); //while combined status bits 8 & 6 don't equal 1 and 0 respectively

          // Get ADC result
          sample = IADC_pullSingleFifoResult(IADC0).data;
//          singleResult = (sample * 4.84) / 0xFFF;

          sz = sizeof(sample);
          p  =  (uint8_t*) &sample;

          break;

//        case gattdb_read_imu:
//          sl_imu_update();
//
//          while (!sl_imu_is_data_ready()) {
//            // wait
//          }
//
//          sl_imu_get_acceleration(a_vec);
//
//          int16_t sumOfElements = 0;
//          for(int i=0; i<2; i++)
//            {
//              sumOfElements += a_vec[i];
//            }
//
//          sz = sizeof(sumOfElements);
//          p  =  (uint8_t*) &sumOfElements;
//
//          break;
      }
      sl_bt_gatt_server_send_user_read_response(
          request->connection,
          request->characteristic,
          status,
          sz,
          p,
          &sent);
       break;
    ///////////////////////////////////////////////////////////////////////////
    // Add additional event handlers here as your application requires!      //
    ///////////////////////////////////////////////////////////////////////////

    // -------------------------------
    // Default event handler.
    default:
      break;
  }
}

