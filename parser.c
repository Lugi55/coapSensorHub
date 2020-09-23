/*
 * parser.c
 *
 *  Created on: 12.09.2020
 *      Author: Heimgartner
 */

#include "parser.h"

s0x1E3_Frame_t *ps0x1E3_Frame;
s0x2E3_Frame_t *ps0x2E3_Frame;
s0x3E3_Frame_t *ps0x3E3_Frame;
s0x4E3_Frame_t *ps0x4E3_Frame;
sModule_t *psModule1;
sModule_t *psModule2;
sModule_t *psModule3;
sModule_t *psModule4;
sModule_t *psModule5;
sModule_t *psModule6;
sModule_t *psModule7;



//////////////////////
//get pointer for Frames
//////////////////////
void parser_set_ps0x1E3_Frame(s0x1E3_Frame_t *_ps0x1E3_Frame){
    ps0x1E3_Frame = _ps0x1E3_Frame;
}
void parser_set_ps0x2E3_Frame(s0x2E3_Frame_t *_ps0x2E3_Frame){
    ps0x2E3_Frame = _ps0x2E3_Frame;
}
void parser_set_ps0x3E3_Frame(s0x3E3_Frame_t *_ps0x3E3_Frame){
    ps0x3E3_Frame = _ps0x3E3_Frame;
}
void parser_set_ps0x4E3_Frame(s0x4E3_Frame_t *_ps0x4E3_Frame){
    ps0x4E3_Frame = _ps0x4E3_Frame;
}
void parser_set_psModule1(sModule_t *_psModule1){
    psModule1 = _psModule1;
}
void parser_set_psModule2(sModule_t *_psModule2){
    psModule2 = _psModule2;
}
void parser_set_psModule3(sModule_t *_psModule3){
    psModule3 = _psModule3;
}
void parser_set_psModule4(sModule_t *_psModule4){
    psModule4 = _psModule4;
}
void parser_set_psModule5(sModule_t *_psModule5){
    psModule5 = _psModule5;
}
void parser_set_psModule6(sModule_t *_psModule6){
    psModule6 = _psModule6;
}
void parser_set_psModule7(sModule_t *_psModule7){
    psModule7 = _psModule7;
}



//////////////////////
//parse CanMsg
//////////////////////
void parser_parseCanMsg(tCANMsgObject sCANMessage){
    switch(sCANMessage.ui32MsgID){
        case 0x1E3:
                parser_parse1E3(sCANMessage);
            break;
        case 0x2E3:
                parser_parse2E3(sCANMessage);
            break;
        case 0x3E3:
                parser_parse3E3(sCANMessage);
            break;
        case 0x4E3:
                parser_parse4E3(sCANMessage);
            break;
        case 0x181:
                parser_parseModule(sCANMessage,psModule1);
            break;
        case 0x182:
                parser_parseModule(sCANMessage,psModule2);
            break;
        case 0x183:
                parser_parseModule(sCANMessage,psModule3);
            break;
        case 0x184:
                parser_parseModule(sCANMessage,psModule4);
            break;
        case 0x185:
                parser_parseModule(sCANMessage,psModule5);
            break;
        case 0x186:
                parser_parseModule(sCANMessage,psModule6);
            break;
        case 0x187:
                parser_parseModule(sCANMessage,psModule7);
            break;
        default:
            UARTprintf("unexpected CAN ID\n");
            can_SetLedRed(true);
            break;
    }
}

//////////////////////
//decode CAN MSG
//////////////////////
void parser_parse1E3(tCANMsgObject sCANMessage){
    union16_t myUnion16;
    (sCANMessage.pui8MsgData[0] & 0x01) ? (ps0x1E3_Frame->AEC_State.RELAY.data.u = true) : (ps0x1E3_Frame->AEC_State.RELAY.data.u = false);
    (sCANMessage.pui8MsgData[0] & 0x02) ? (ps0x1E3_Frame->AEC_State.Low_Voltage_Warning.data.u = true) : (ps0x1E3_Frame->AEC_State.Low_Voltage_Warning.data.u = false);
    (sCANMessage.pui8MsgData[0] & 0x04) ? (ps0x1E3_Frame->AEC_State.High_Voltage_Warning.data.u = true) : (ps0x1E3_Frame->AEC_State.High_Voltage_Warning.data.u = false);
    (sCANMessage.pui8MsgData[0] & 0x08) ? (ps0x1E3_Frame->AEC_State.Open_Relay_Crash.data.u = true) : (ps0x1E3_Frame->AEC_State.Open_Relay_Crash.data.u = false);
    (sCANMessage.pui8MsgData[0] & 0x40) ? (ps0x1E3_Frame->AEC_State.Open_Relay_Error.data.u = true) : (ps0x1E3_Frame->AEC_State.Open_Relay_Error.data.u = false);
    ps0x1E3_Frame->AEC_SoC_pct.data.u = sCANMessage.pui8MsgData[1];
    (sCANMessage.pui8MsgData[2] == 0x00 && sCANMessage.pui8MsgData[3] == 0x00) ? (ps0x1E3_Frame->AEC_Errors.ERR_NO_ERROR.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_NO_ERROR.data.u = false);
    (sCANMessage.pui8MsgData[2] & 0x01) ? (ps0x1E3_Frame->AEC_Errors.ERR_SELFTEST.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_SELFTEST.data.u = false);
    (sCANMessage.pui8MsgData[2] & 0x02) ? (ps0x1E3_Frame->AEC_Errors.ERR_OVER_CURRENT.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_OVER_CURRENT.data.u = false);
    (sCANMessage.pui8MsgData[2] & 0x04) ? (ps0x1E3_Frame->AEC_Errors.ERR_OVER_VOLTAGE.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_OVER_VOLTAGE.data.u = false);
    (sCANMessage.pui8MsgData[2] & 0x08) ? (ps0x1E3_Frame->AEC_Errors.ERR_UNDER_VOLTAGE.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_UNDER_VOLTAGE.data.u = false);
    (sCANMessage.pui8MsgData[2] & 0x10) ? (ps0x1E3_Frame->AEC_Errors.ERR_DIGOVLD.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_DIGOVLD.data.u = false);
    (sCANMessage.pui8MsgData[2] & 0x20) ? (ps0x1E3_Frame->AEC_Errors.ERR_OVER_UNDER_TEMPERATURE.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_OVER_UNDER_TEMPERATURE.data.u = false);
    (sCANMessage.pui8MsgData[2] & 0x40) ? (ps0x1E3_Frame->AEC_Errors.ERR_PARAMINIT.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_PARAMINIT.data.u = false);
    (sCANMessage.pui8MsgData[2] & 0x80) ? (ps0x1E3_Frame->AEC_Errors.ERR_COMMUNICATION.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_COMMUNICATION.data.u = false);
    (sCANMessage.pui8MsgData[3] & 0x01) ? (ps0x1E3_Frame->AEC_Errors.ERR_HVIL.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_HVIL.data.u = false);
    (sCANMessage.pui8MsgData[3] & 0x02) ? (ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Plus.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Plus.data.u = false);
    (sCANMessage.pui8MsgData[3] & 0x04) ? (ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Minus.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Minus.data.u = false);
    (sCANMessage.pui8MsgData[3] & 0x08) ? (ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Pre_Charge.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Pre_Charge.data.u = false);
    (sCANMessage.pui8MsgData[3] & 0x10) ? (ps0x1E3_Frame->AEC_Errors.ERR_CELL_DELTA.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_CELL_DELTA.data.u = false);
    (sCANMessage.pui8MsgData[3] & 0x20) ? (ps0x1E3_Frame->AEC_Errors.ERR_Service.data.u = true) : (ps0x1E3_Frame->AEC_Errors.ERR_Service.data.u = false);
    (sCANMessage.pui8MsgData[4] == 0x00) ? (ps0x1E3_Frame->AEC_Warnings.ERR_NO_ERROR.data.u = true) : (ps0x1E3_Frame->AEC_Warnings.ERR_NO_ERROR.data.u = false);
    (sCANMessage.pui8MsgData[4] & 0x01) ? (ps0x1E3_Frame->AEC_Warnings.ERR_SELFTEST.data.u = true) : (ps0x1E3_Frame->AEC_Warnings.ERR_SELFTEST.data.u = false);
    (sCANMessage.pui8MsgData[4] & 0x02) ? (ps0x1E3_Frame->AEC_Warnings.ERR_OVER_CURRENT.data.u = true) : (ps0x1E3_Frame->AEC_Warnings.ERR_OVER_CURRENT.data.u = false);
    (sCANMessage.pui8MsgData[4] & 0x04) ? (ps0x1E3_Frame->AEC_Warnings.ERR_OVER_VOLTAGE.data.u = true) : (ps0x1E3_Frame->AEC_Warnings.ERR_OVER_VOLTAGE.data.u = false);
    (sCANMessage.pui8MsgData[4] & 0x08) ? (ps0x1E3_Frame->AEC_Warnings.ERR_UNDER_VOLTAGE.data.u = true) : (ps0x1E3_Frame->AEC_Warnings.ERR_UNDER_VOLTAGE.data.u = false);
    (sCANMessage.pui8MsgData[4] & 0x10) ? (ps0x1E3_Frame->AEC_Warnings.ERR_DIGOVLD.data.u = true) : (ps0x1E3_Frame->AEC_Warnings.ERR_DIGOVLD.data.u = false);
    (sCANMessage.pui8MsgData[4] & 0x20) ? (ps0x1E3_Frame->AEC_Warnings.ERR_OVER_UNDER_TEMPERATURE.data.u = true) : (ps0x1E3_Frame->AEC_Warnings.ERR_OVER_UNDER_TEMPERATURE.data.u = false);
    (sCANMessage.pui8MsgData[4] & 0x40) ? (ps0x1E3_Frame->AEC_Warnings.ERR_PARAMINIT.data.u = true) : (ps0x1E3_Frame->AEC_Warnings.ERR_PARAMINIT.data.u = false);
    (sCANMessage.pui8MsgData[4] & 0x80) ? (ps0x1E3_Frame->AEC_Warnings.ERR_COMMUNICATION.data.u = true) : (ps0x1E3_Frame->AEC_Warnings.ERR_COMMUNICATION.data.u = false);
    ps0x1E3_Frame->AEC_Error_from_Node_ID.data.u = sCANMessage.pui8MsgData[5];
    myUnion16.u8[0] = sCANMessage.pui8MsgData[6];
    myUnion16.u8[1] = sCANMessage.pui8MsgData[7];
    ps0x1E3_Frame->AEC_Voltage_V.data.u = myUnion16.u16;
}

//////////////////////
//decode 2E3 Frame
//////////////////////
void parser_parse2E3(tCANMsgObject sCANMessage){
    ps0x2E3_Frame->AEC_System_Maximum_String_Cell_Voltage_V.data.u = sCANMessage.pui8MsgData[0];
    ps0x2E3_Frame->AEC_System_Minimum_String_Cell_Voltage_V.data.u = sCANMessage.pui8MsgData[1];
    (sCANMessage.pui8MsgData[2]) ? (ps0x2E3_Frame->AEC_System_Heater_Status.data.b = true) : (ps0x2E3_Frame->AEC_System_Heater_Status.data.b = false);
    ps0x2E3_Frame->AEC_SoH_pct.data.u = sCANMessage.pui8MsgData[3];
    ps0x2E3_Frame->AEC_Hottest_Module_Temperature_C.data.s = sCANMessage.pui8MsgData[4];
    ps0x2E3_Frame->AEC_Coldest_Module_Temperature_C.data.s = sCANMessage.pui8MsgData[5];
    ps0x2E3_Frame->AEC_SW_Version.data.u = sCANMessage.pui8MsgData[6];
    (sCANMessage.pui8MsgData[7] & 0x01) ? (ps0x2E3_Frame->AEC_Relays_Status.data.u = true) : (ps0x2E3_Frame->AEC_Relays_Status.data.u = false);
}

//////////////////////
//decode CAN MSG
//////////////////////
void parser_parse3E3(tCANMsgObject sCANMessage){
    union16_t myUnion16;
    myUnion16.u8[0] = sCANMessage.pui8MsgData[0];
    myUnion16.u8[1] = sCANMessage.pui8MsgData[1];
    ps0x3E3_Frame->AEC_Remaining_Capacity_Ah.data.u = myUnion16.u16;
    myUnion16.u8[0] = sCANMessage.pui8MsgData[2];
    myUnion16.u8[1] = sCANMessage.pui8MsgData[3];
    ps0x3E3_Frame->AEC_Time_Remaining_mins.data.u = myUnion16.u16;
    myUnion16.u8[0] = sCANMessage.pui8MsgData[4];
    myUnion16.u8[1] = sCANMessage.pui8MsgData[5];
    ps0x3E3_Frame->AEC_Lifetime_Charged_kWh.data.u = myUnion16.u16;
    myUnion16.u8[0] = sCANMessage.pui8MsgData[6];
    myUnion16.u8[1] = sCANMessage.pui8MsgData[7];
    ps0x3E3_Frame->AEC_ISO_Monitor_kOhm.data.u = myUnion16.u16;
}

//////////////////////
//decode CAN MSG
//////////////////////
void parser_parse4E3(tCANMsgObject sCANMessage){
    union16_t myUnion16;
    myUnion16.u8[0] = sCANMessage.pui8MsgData[0];
    myUnion16.u8[1] = sCANMessage.pui8MsgData[1];
    ps0x4E3_Frame->AEC_Permitted_Charge_Current_Amp.data.s = myUnion16.s16;
    myUnion16.u8[0] = sCANMessage.pui8MsgData[2];
    myUnion16.u8[1] = sCANMessage.pui8MsgData[3];
    ps0x4E3_Frame->AEC_Permitted_Discharge_Current_Amp.data.s = myUnion16.s16;
    ps0x4E3_Frame->AEC_Alive_Counter.data.u = sCANMessage.pui8MsgData[4];
    myUnion16.u8[0] = sCANMessage.pui8MsgData[5];
    myUnion16.u8[1] = sCANMessage.pui8MsgData[6];
    ps0x4E3_Frame->AEC_Current_Amp.data.s = myUnion16.s16;
}

//////////////////////
//decode CAN MSG
//////////////////////
void parser_parseModule(tCANMsgObject sCANMessage, sModule_t *psModule){
    union16_t myUnion16;
    psModule->Module_Maximum_String_Cells_Voltage_V.data.u = sCANMessage.pui8MsgData[0];
    psModule->Module_Minimum_String_Cells_Voltage_V.data.u = sCANMessage.pui8MsgData[1];
    (sCANMessage.pui8MsgData[2] == 0x00) ? (psModule->Module_Errors.ERR_NO_ERROR.data.b = true) : (psModule->Module_Errors.ERR_NO_ERROR.data.b = false);
    (sCANMessage.pui8MsgData[2] & 0x01) ? (psModule->Module_Errors.ERR_CHIPSYS.data.b = true) : (psModule->Module_Errors.ERR_CHIPSYS.data.b = false);
    (sCANMessage.pui8MsgData[2] & 0x02) ? (psModule->Module_Errors.ERR_OVER_CURRENT.data.b = true) : (psModule->Module_Errors.ERR_OVER_CURRENT.data.b = false);
    (sCANMessage.pui8MsgData[2] & 0x04) ? (psModule->Module_Errors.ERR_OVER_VOLTAGE.data.b = true) : (psModule->Module_Errors.ERR_OVER_VOLTAGE.data.b = false);
    (sCANMessage.pui8MsgData[2] & 0x08) ? (psModule->Module_Errors.ERR_UNDER_VOLTAGE.data.b = true) : (psModule->Module_Errors.ERR_UNDER_VOLTAGE.data.b = false);
    (sCANMessage.pui8MsgData[2] & 0x20) ? (psModule->Module_Errors.ERR_OVER_UNDER_TEMPERATURE.data.b = true) : (psModule->Module_Errors.ERR_OVER_UNDER_TEMPERATURE.data.b = false);
    (sCANMessage.pui8MsgData[2] & 0x80) ? (psModule->Module_Errors.ERR_COMM_COMMON.data.b = true) : (psModule->Module_Errors.ERR_COMM_COMMON.data.b = false);
    (sCANMessage.pui8MsgData[3] == 0x01) ? (psModule->Module_Heater_Status.data.b = true) : (psModule->Module_Heater_Status.data.b = false);
    psModule->Module_Maximum_Module_Temperature_C.data.s = sCANMessage.pui8MsgData[4];
    psModule->Module_Minimum_Module_Temperature_C.data.s = sCANMessage.pui8MsgData[5];
    myUnion16.u8[0] = sCANMessage.pui8MsgData[6];
    myUnion16.u8[1] = sCANMessage.pui8MsgData[7];
    psModule->Module_Voltage_mV.data.u = myUnion16.u16;
}









