#ifndef DIN_IR_H
#define DIN_IR_H

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "shell.h"

#define IR_0    3
#define IR_1    4
#define IR_2    5
#define IR_3    6
#define IR_4    7
#define IR_5    8

void d_ir_start(void);
void d_ir_allOn(void);
void d_ir_allOff(void);
void d_ir_numOn(uint8_t num);

#endif // DIN_IR_H
