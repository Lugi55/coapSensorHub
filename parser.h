/*
 * parser.h
 *
 *  Created on: 12.09.2020
 *      Author: Heimgartner
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <driverlib/can.h>
#include <can.h>
#include <datatypes.h>



void parser_setup(  s0x1E3_Frame_t *_ps0x1E3_Frame,
                    s0x2E3_Frame_t *_ps0x2E3_Frame,
                    s0x3E3_Frame_t *_ps0x3E3_Frame,
                    s0x4E3_Frame_t *_ps0x4E3_Frame,
                    sModule_t *_psModule1,
                    sModule_t *_psModule2,
                    sModule_t *_psModule3,
                    sModule_t *_psModule4,
                    sModule_t *_psModule5,
                    sModule_t *_psModule6,
                    sModule_t *_psModule7);

void parser_set_ps0x1E3_Frame(s0x1E3_Frame_t *_ps0x1E3_Frame);
void parser_set_ps0x2E3_Frame(s0x2E3_Frame_t *_ps0x2E3_Frame);
void parser_set_ps0x3E3_Frame(s0x3E3_Frame_t *_ps0x3E3_Frame);
void parser_set_ps0x4E3_Frame(s0x4E3_Frame_t *_ps0x4E3_Frame);
void parser_set_psModule1(sModule_t *_psModule1);
void parser_set_psModule2(sModule_t *_psModule2);
void parser_set_psModule3(sModule_t *_psModule3);
void parser_set_psModule4(sModule_t *_psModule4);
void parser_set_psModule5(sModule_t *_psModule5);
void parser_set_psModule6(sModule_t *_psModule6);
void parser_set_psModule7(sModule_t *_psModule7);

void parser_parseCanMsg(tCANMsgObject sCANMessage);
void parser_parseNode(tCANMsgObject sCANMessage);
void parser_parse1E3(tCANMsgObject sCANMessage);
void parser_parse2E3(tCANMsgObject sCANMessage);
void parser_parse3E3(tCANMsgObject sCANMessage);
void parser_parse4E3(tCANMsgObject sCANMessage);
void parser_parseModule(tCANMsgObject sCANMessage, sModule_t *sModule);


#endif /* PARSER_H_ */
