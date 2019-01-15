#include "din_ir.h"

void d_ir_start(void){
    palSetPadMode(GPIOB,IR_0,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,IR_1,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,IR_2,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,IR_3,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,IR_4,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,IR_5,PAL_MODE_OUTPUT_PUSHPULL);
}

void d_ir_allOn(void){
    palSetPad(GPIOB,IR_0);
    palSetPad(GPIOB,IR_1);
    palSetPad(GPIOB,IR_2);
    palSetPad(GPIOB,IR_3);
    palSetPad(GPIOB,IR_4);
    palSetPad(GPIOB,IR_5);
}

void d_ir_allOff(void){
    palClearPad(GPIOB,IR_0);
    palClearPad(GPIOB,IR_1);
    palClearPad(GPIOB,IR_2);
    palClearPad(GPIOB,IR_3);
    palClearPad(GPIOB,IR_4);
    palClearPad(GPIOB,IR_5);
}

void d_ir_numOn(uint8_t num){
    d_ir_allOff();

    switch (num) {
    case 0:
        palSetPad(GPIOB,IR_0);
        break;
    case 1:
        palSetPad(GPIOB,IR_1);
        break;
    case 2:
        palSetPad(GPIOB,IR_2);
        break;
    case 3:
        palSetPad(GPIOB,IR_3);
        break;
    case 4:
        palSetPad(GPIOB,IR_4);
        break;
    case 5:
        palSetPad(GPIOB,IR_5);
        break;
    default:
        d_ir_allOff();
        break;
    }
}
