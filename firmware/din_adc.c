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
 * @file    din_adc.c
 * @brief   ADC (for Mic) routine code.
 *
 * @addtogroup ADC
 * @{
 */

#include "din_adc.h"

/**
 * @brief   ADC buffer variable.
 */

static adcsample_t adcM;
static uint32_t sum_adcM;
static adcsample_t samples[ADC_GRP_NUM_CHANNELS * ADC_GRP_BUF_DEPTH];
adcsample_t adc0,adc1,adc2,adc3;
uint32_t sum_adc0,sum_adc1,sum_adc2,sum_adc3;

void adccb(ADCDriver *adcp, adcsample_t *buffer, size_t n){
  (void) buffer; (void) n;
  int i;
  if (adcp->state == ADC_COMPLETE) {
    sum_adc0=0;
    sum_adc1=0;
    sum_adc2=0;
    sum_adc3=0;
    sum_adcM=0;
    for(i=0;i<ADC_GRP_BUF_DEPTH;i++){
        sum_adc0=sum_adc0+samples[0+(i*ADC_GRP_NUM_CHANNELS)];
        sum_adc1=sum_adc1+samples[1+(i*ADC_GRP_NUM_CHANNELS)];
        sum_adc2=sum_adc2+samples[2+(i*ADC_GRP_NUM_CHANNELS)];
        sum_adc3=sum_adc3+samples[3+(i*ADC_GRP_NUM_CHANNELS)];
        sum_adcM=sum_adcM+samples[4+(i*ADC_GRP_NUM_CHANNELS)];
    }
    adc0=4095-(sum_adc0/ADC_GRP_BUF_DEPTH);
    adc1=4095-(sum_adc1/ADC_GRP_BUF_DEPTH);
    adc2=4095-(sum_adc2/ADC_GRP_BUF_DEPTH);
    adc3=4095-(sum_adc3/ADC_GRP_BUF_DEPTH);
    adcM=4095-(sum_adcM/ADC_GRP_BUF_DEPTH);
   }
 }

/**
 * @brief   ADC configuration variable.
 */
static const ADCConversionGroup adcgrpcfg = {
    FALSE,
    ADC_GRP_NUM_CHANNELS,
    adccb,
    NULL,
    /* HW dependent part.*/
    0,
    0,
    ADC_SMPR2_SMP_AN0(ADC_SAMPLE_239P5)|ADC_SMPR2_SMP_AN1(ADC_SAMPLE_239P5)|ADC_SMPR2_SMP_AN2(ADC_SAMPLE_239P5)|ADC_SMPR2_SMP_AN3(ADC_SAMPLE_239P5)|ADC_SMPR2_SMP_AN4(ADC_SAMPLE_239P5),
    0,
    ADC_SQR1_NUM_CH(ADC_GRP_NUM_CHANNELS),
    0,
    ADC_SQR3_SQ1_N(ADC_CHANNEL_IN0)|ADC_SQR3_SQ2_N(ADC_CHANNEL_IN1)|ADC_SQR3_SQ3_N(ADC_CHANNEL_IN2)|ADC_SQR3_SQ4_N(ADC_CHANNEL_IN3)|ADC_SQR3_SQ5_N(ADC_CHANNEL_IN4)
};

adcsample_t d_adc_mux(uint8_t nmux){
    p0(GPIOB,PI);

    switch (nmux) {
    case 4: //x5 101
        p1(GPIOA,PC);p0(GPIOA,PB);p1(GPIOA,PA);
        break;
    case 5: //x7 111
        p1(GPIOA,PC);p1(GPIOA,PB);p1(GPIOA,PA);
        break;
    case 6: //x6 110
        p1(GPIOA,PC);p1(GPIOA,PB);p0(GPIOA,PA);
        break;
    case 7: //x4 100
        p1(GPIOA,PC);p0(GPIOA,PB);p0(GPIOA,PA);
        break;
    case 8: //x2 010
        p0(GPIOA,PC);p1(GPIOA,PB);p0(GPIOA,PA);
        break;
    case 9: //x1 001
        p0(GPIOA,PC);p0(GPIOA,PB);p1(GPIOA,PA);
        break;
    case 10: //x0 000
        p0(GPIOA,PC);p0(GPIOA,PB);p0(GPIOA,PA);
        break;
    case 11: //x3 011
        p0(GPIOA,PC);p1(GPIOA,PB);p1(GPIOA,PA);
        break;
    default:
        p1(GPIOB,PI);
        break;
    }

    chThdSleepMilliseconds(10);

    return adcM;
}

static THD_WORKING_AREA(waADC, 128);
static THD_FUNCTION(thdADC, arg) {

    (void)arg;

    chRegSetThreadName("ADC Conversion");
    while (true) {
        chThdSleepMicroseconds(100);
        adcStartConversion(&ADCD1, &adcgrpcfg, samples, ADC_GRP_BUF_DEPTH);
    }
}

/**
 * @brief   ADC start function.
 */
void d_adc_start(void){
    palSetPadMode(GPIOA,0,PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOA,1,PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOA,2,PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOA,3,PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOA,4,PAL_MODE_INPUT_ANALOG);

    palSetPadMode(GPIOA,PA,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,PB,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOA,PC,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,PI,PAL_MODE_OUTPUT_PUSHPULL);

    adcStart(&ADCD1, NULL);
    chThdCreateStatic(waADC, sizeof(waADC), NORMALPRIO, thdADC, NULL);
}

/** @} */
