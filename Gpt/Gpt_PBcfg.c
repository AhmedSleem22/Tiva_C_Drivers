 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_PBcfg.c
 *
 * Description: Post Build Configuration Source file for Dio Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "Gpt.h"

/*
 * Module Version 1.0.0
 */

/* PB structure used with Dio_Init API */
const Gpt_ConfigType Gpt_Configuration = {
                                          GPT_TIMER0, GPT_TIMERA, GPT_INPUT_EDAGE_TIME, GPT_16BITS, GPT_COUNTUP, 0x00000000
                                            };
