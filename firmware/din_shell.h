#ifndef DIN_SHELL_H
#define DIN_SHELL_H

#include "ch.h"
#include "hal.h"

#include "chprintf.h"
#include "shell.h"

#include "math.h"
#include "stdlib.h"
#include "stdio.h"

#include "din_uart.h"
#include "din_ir.h"
#include "din_usb.h"

#define USE_USB         TRUE

#define SHELL_WA_SIZE   THD_WORKING_AREA_SIZE(512)
#define THREAD_WA_SIZE  THD_WORKING_AREA_SIZE(128)

void d_shell_start(void);
void d_shell_term(void);

#endif // DIN_SHELL_H
