/*
 * endpoints.h
 *
 *  Created on: 21.06.2020
 *      Author: Heimgartner
 */

#ifndef ENDPOINTS_H_
#define ENDPOINTS_H_

#include "datatypes.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "can.h"
#include "coap.h"
#include "parser.h"

void build_rsp(void);
void endpoints_updateTopic(sTopic_t *psTopic, char *bufferString);
void endpoints_updateTopics(sTopic_t *psTopic, uint16_t len, char *jsonString);

void endpoints_Init1E3Frame(s0x1E3_Frame_t *ps0x1E3_Frame);
void endpoints_Init2E3Frame(s0x2E3_Frame_t *ps0x2E3_Frame);
void endpoints_Init3E3Frame(s0x3E3_Frame_t *ps0x3E3_Frame);
void endpoints_Init4E3Frame(s0x4E3_Frame_t *ps0x4E3_Frame);
void endpoints_InitModuleFrame(sModule_t *psModule);

static void ftoa(float n, char* res, int afterpoint);
static void reverse(char* str, int len);
static int intToStr(int x, char str[], int d);




#endif /* ENDPOINTS_H_ */
