//lmp91000.h
//Created on: Dec 14, 2022
//Author: Nick Merola

#ifndef LMP91000_H
#define LMP91000_H

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>




const double TEMP_INTERCEPT = 1555;
const double TEMPSLOPE = -8;
const uint8_t LMP91000_I2C_ADDRESS = 0X48;

const uint8_t LMP91000_STATUS_REG = 0x00;    /* Read only status register */
const uint8_t LMP91000_LOCK_REG=0x01;    /* Protection Register */
const uint8_t LMP91000_TIACN_REG=0x10;    /* TIA Control Register */
const uint8_t LMP91000_REFCN_REG=0x11;    /* Reference Control Register*/
const uint8_t LMP91000_MODECN_REG=0x12;    /* Mode Control Register */

const uint8_t LMP91000_READY=0x01;
const uint8_t LMP91000_NOT_READY=0x00;

const uint8_t LMP91000_TIA_GAIN_EXT=0x00; //default
const uint8_t LMP91000_TIA_GAIN_2P75K=0x04;
const uint8_t LMP91000_TIA_GAIN_3P5K=0x08;
const uint8_t LMP91000_TIA_GAIN_7K=0x0C;
const uint8_t LMP91000_TIA_GAIN_14K=0x10;
const uint8_t LMP91000_TIA_GAIN_35K=0x14;
const uint8_t LMP91000_TIA_GAIN_120K=0x18;
const uint8_t LMP91000_TIA_GAIN_350K=0x1C;

const uint8_t LMP91000_RLOAD_10OHM=0X00;
const uint8_t LMP91000_RLOAD_33OHM=0X01;
const uint8_t LMP91000_RLOAD_50OHM=0X02;
const uint8_t LMP91000_RLOAD_100OHM=0X03; //default

const uint8_t LMP91000_REF_SOURCE_INT=0x00; //default
const uint8_t LMP91000_REF_SOURCE_EXT=0x80;

const uint8_t LMP91000_INT_Z_20PCT=0x00;
const uint8_t LMP91000_INT_Z_50PCT=0x20; //default
const uint8_t LMP91000_INT_Z_67PCT=0x40;
const uint8_t LMP91000_INT_Z_BYPASS=0x60;

const uint8_t LMP91000_BIAS_SIGN_NEG=0x00; //default
const uint8_t LMP91000_BIAS_SIGN_POS=0x10;

const uint8_t LMP91000_BIAS_0PCT=0x00; //default
const uint8_t LMP91000_BIAS_1PCT=0x01;
const uint8_t LMP91000_BIAS_2PCT=0x02;
const uint8_t LMP91000_BIAS_4PCT=0x03;
const uint8_t LMP91000_BIAS_6PCT=0x04;
const uint8_t LMP91000_BIAS_8PCT=0x05;
const uint8_t LMP91000_BIAS_10PCT=0x06;
const uint8_t LMP91000_BIAS_12PCT=0x07;
const uint8_t LMP91000_BIAS_14PCT=0x08;
const uint8_t LMP91000_BIAS_16PCT=0x09;
const uint8_t LMP91000_BIAS_18PCT=0x0A;
const uint8_t LMP91000_BIAS_20PCT=0x0B;
const uint8_t LMP91000_BIAS_22PCT=0x0C;
const uint8_t LMP91000_BIAS_24PCT=0x0D;

const uint8_t LMP91000_FET_SHORT_DISABLED=0x00; //default
const uint8_t LMP91000_FET_SHORT_ENABLED=0x80;
const uint8_t LMP91000_OP_MODE_DEEP_SLEEP=0x00; //default
const uint8_t LMP91000_OP_MODE_GALVANIC=0x01;
const uint8_t LMP91000_OP_MODE_STANDBY=0x02;
const uint8_t LMP91000_OP_MODE_AMPEROMETRIC=0x03;
const uint8_t LMP91000_OP_MODE_TIA_OFF=0x06;
const uint8_t LMP91000_OP_MODE_TIA_ON=0x07;

const uint8_t LMP91000_WRITE_LOCK=0x01; //default
const uint8_t LMP91000_WRITE_UNLOCK=0x00;

const uint8_t LMP91000_NOT_PRESENT=0xA8;    // arbitrary library status code

const double TIA_GAIN[] = {2750,3500,7000,14000,35000,120000,350000};
const double TIA_BIAS[] = {0, 0.01, 0.02, 0.04, 0.06, 0.08, 0.1, 0.12, 0.14,
    0.16, 0.18, 0.2, 0.22, 0.24};
const uint8_t NUM_TIA_BIAS = 14;
const double TIA_ZERO[] = {0.2, 0.5, 0.67};



#endif /* LMP91000_H_ */
