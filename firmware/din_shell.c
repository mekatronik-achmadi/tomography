#include "din_shell.h"

adcsample_t vadc[12];
extern adcsample_t adc0,adc1,adc2,adc3;
extern SerialUSBDriver SDU1;

/**
 * @brief   Shell handler variable.
 */
static thread_t *shelltp = NULL;

/**
 * @brief   Handler function.
 */
static void cmd_adc(BaseSequentialStream *chp, int argc, char *argv[]) {

    (void)argv;
    (void)argc;
    uint8_t i;

    vadc[0] = adc0;
    vadc[1] = adc1;
    vadc[2] = adc2;
    vadc[3] = adc3;

    for(i=4;i<12;i++){
        vadc[i] = d_adc_mux(i);
    }

    chprintf(chp,"%4i,%4i,%4i,%4i,%4i,%4i,%4i,%4i,%4i,%4i,%4i,%4i\r\n",
            vadc[0],vadc[1],vadc[2],vadc[3],
            vadc[4],vadc[5],vadc[6],vadc[7],
            vadc[8],vadc[9],vadc[10],vadc[11]);
}

static void cmd_off(BaseSequentialStream *chp, int argc, char *argv[]) {

    (void)argv;
    (void)argc;
    (void)chp;

    d_ir_Off();
}

static void cmd_led(BaseSequentialStream *chp, int argc, char *argv[]) {

    (void)argv;
    (void)argc;
    (void)chp;

    uint8_t num;

    num=atoi(argv[0]);
    d_ir_numOn(num);
}

/**
 * @brief   Shell commands enumeration.
 */
static const ShellCommand commands[] = {
    {"adc",cmd_adc},
    {"off",cmd_off},
    {"led",cmd_led},
    {NULL, NULL}
};

/**
 * @brief   Shell configuration variable.
 */
static const ShellConfig shell_cfg = {
    (BaseSequentialStream *)&SDU1,
    commands
};

/**
 * @brief   Shell start function.
 */
void d_shell_start(void){
//    d_uart_start();
    d_usb_start();
    shellInit();
}

/**
 * @brief   Shell function.
 */
void d_shell_term(void){
#if USE_USB
    if (!shelltp && (SDU1.config->usbp->state == USB_ACTIVE))
          shelltp = shellCreate(&shell_cfg, SHELL_WA_SIZE, NORMALPRIO);
        else if (chThdTerminatedX(shelltp)) {
          chThdRelease(shelltp);    /* Recovers memory of the previous shell.   */
          shelltp = NULL;           /* Triggers spawning of a new shell.        */
        }
#else
    if (!shelltp)
      shelltp = shellCreate(&shell_cfg, SHELL_WA_SIZE, NORMALPRIO);
    else if (chThdTerminatedX(shelltp)) {
      chThdRelease(shelltp);
      shelltp = NULL;
    }
#endif
}
