#include "din_ir.h"

void d_ir_start(void){
    palSetPadMode(GPIOB,L_0,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,L_1,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,L_2,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,L_3,PAL_MODE_OUTPUT_PUSHPULL);

    palSetPadMode(GPIOB,LI,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LC,PAL_MODE_OUTPUT_PUSHPULL);
    palSetPadMode(GPIOB,LB,PAL_MODE_OUTPUT_PUSHPULL);

    palSetPadMode(GPIOA,LA,PAL_MODE_OUTPUT_PUSHPULL);
}

void d_ir_Off(void){
    palClearPad(GPIOB,L_0);
    palClearPad(GPIOB,L_1);
    palClearPad(GPIOB,L_2);
    palClearPad(GPIOB,L_3);

    palSetPad(GPIOB,LI);
}

static void d_ir_mux(uint8_t nmux){
    l0(GPIOB,LI);

    switch (nmux) {
    case 4: //x5 101
        l1(GPIOB,LC);l0(GPIOB,LB);l1(GPIOA,LA);
        break;
    case 5: //x7 111
        l1(GPIOB,LC);l1(GPIOB,LB);l1(GPIOA,LA);
        break;
    case 6: //x6 110
        l1(GPIOB,LC);l1(GPIOB,LB);l0(GPIOA,LA);
        break;
    case 7: //x4 100
        l1(GPIOB,LC);l0(GPIOB,LB);l0(GPIOA,LA);
        break;
    case 8: //x2 010
        l0(GPIOB,LC);l1(GPIOB,LB);l0(GPIOA,LA);
        break;
    case 9: //x1 001
        l0(GPIOB,LC);l0(GPIOB,LB);l1(GPIOA,LA);
        break;
    case 10: //x0 000
        l0(GPIOB,LC);l0(GPIOB,LB);l0(GPIOA,LA);
        break;
    case 11: //x3 011
        l0(GPIOB,LC);l1(GPIOB,LB);l1(GPIOA,LA);
        break;
    default:
        l1(GPIOB,LI);
        break;
    }
}

void d_ir_numOn(uint8_t num){
    d_ir_Off();

    switch (num) {
    case 0:
        palSetPad(GPIOB,L_0);
        break;
    case 1:
        palSetPad(GPIOB,L_1);
        break;
    case 2:
        palSetPad(GPIOB,L_2);
        break;
    case 3:
        palSetPad(GPIOB,L_3);
        break;
    case 4:
        d_ir_mux(num);
        break;
    case 5:
        d_ir_mux(num);
        break;
    case 6:
        d_ir_mux(num);
        break;
    case 7:
        d_ir_mux(num);
        break;
    case 8:
        d_ir_mux(num);
        break;
    case 9:
        d_ir_mux(num);
        break;
    case 10:
        d_ir_mux(num);
        break;
    case 11:
        d_ir_mux(num);
        break;
    default:
        d_ir_Off();
        break;
    }
}
