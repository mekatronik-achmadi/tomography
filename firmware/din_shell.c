#include "din_shell.h"

extern adcsample_t adc0,adc1,adc2,adc3,adc4,adc5;
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

    chprintf(chp,"%4i,%4i,%4i,%4i,%4i,%4i\r\n",adc0,adc1,adc2,adc3,adc4,adc5);
}

static void cmd_on(BaseSequentialStream *chp, int argc, char *argv[]) {

    (void)argv;
    (void)argc;
    (void)chp;

    d_ir_allOn();
}

static void cmd_off(BaseSequentialStream *chp, int argc, char *argv[]) {

    (void)argv;
    (void)argc;
    (void)chp;

    d_ir_allOff();
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
    {"on",cmd_on},
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
