/*
              DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE

 Copyright (C) 2018 Achmadi S.T.

 Everyone is permitted to copy and distribute verbatim or modified
 copies of this license document, and changing it is allowed as long
 as the name is changed.

            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION

  0. You just DO WHAT THE FUCK YOU WANT TO.
 */

/**
 * @file    din_adc.h
 * @brief   ADC (for Mic) routine header.
 *
 * @addtogroup ADC
 * @{
 */

#ifndef DIN_ADC_H
#define DIN_ADC_H

#include "ch.h"
#include "hal.h"

#define PA 5 //GPIOA
#define PB 6 //GPIOA
#define PC 7 //GPIOA
#define PI 0 //GPIOB

#define p0 palClearPad
#define p1 palSetPad

/**
 * @brief   ADC channel number.
 */
#define ADC_GRP_NUM_CHANNELS   5

/**
 * @brief   ADC buffer size.
 */
#define ADC_GRP_BUF_DEPTH      10

void d_adc_start(void);
adcsample_t d_adc_mux(uint8_t nmux);

#endif // DIN_ADC_H
/** @} */
