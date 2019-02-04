#ifndef DIN_IR_H
#define DIN_IR_H

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "shell.h"

#define L_0 9 // GPIOB
#define L_1 8 // GPIOB
#define L_2 7 // GPIOB
#define L_3 6 // GPIOB

#define LI 5 // GPIOB
#define LA 4 // GPIOB
#define LB 3 // GPIOB

#define LC 15 //GPIOA

#define l0 palClearPad
#define l1 palSetPad

void d_ir_start(void);
void d_ir_Off(void);
void d_ir_numOn(uint8_t num);

#endif // DIN_IR_H
