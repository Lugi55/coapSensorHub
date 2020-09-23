/*
 * datatypes.h
 *
 *  Created on: 16.09.2020
 *      Author: Heimgartner
 */

#ifndef DATATYPES_H_
#define DATATYPES_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef enum{
    FLOAT,
    INT,
    UINT,
    BOOL
}sType_t;

typedef union{
    float f;
    bool b;
    uint16_t u;
    int16_t s;
}sData_t;

typedef struct{
    sType_t type;
    sData_t data;
    float scalingFactor;
    char topicString[50];
}sTopic_t;

typedef struct{
    sTopic_t ERR_NO_ERROR;
    sTopic_t ERR_SELFTEST;
    sTopic_t ERR_OVER_CURRENT;
    sTopic_t ERR_OVER_VOLTAGE;
    sTopic_t ERR_UNDER_VOLTAGE;
    sTopic_t ERR_DIGOVLD;
    sTopic_t ERR_OVER_UNDER_TEMPERATURE;
    sTopic_t ERR_PARAMINIT;
    sTopic_t ERR_COMMUNICATION;
    sTopic_t ERR_HVIL;
    sTopic_t ERR_Contactor_Plus;
    sTopic_t ERR_Contactor_Minus;
    sTopic_t ERR_Contactor_Pre_Charge;
    sTopic_t ERR_CELL_DELTA;
    sTopic_t ERR_Service;
}sAEC_Errors_t;

typedef struct{
    sTopic_t ERR_NO_ERROR;
    sTopic_t ERR_SELFTEST;
    sTopic_t ERR_OVER_CURRENT;
    sTopic_t ERR_OVER_VOLTAGE;
    sTopic_t ERR_UNDER_VOLTAGE;
    sTopic_t ERR_DIGOVLD;
    sTopic_t ERR_OVER_UNDER_TEMPERATURE;
    sTopic_t ERR_PARAMINIT;
    sTopic_t ERR_COMMUNICATION;
}sAEC_Warnings_t;

typedef struct{
    sTopic_t RELAY;
    sTopic_t Low_Voltage_Warning;
    sTopic_t High_Voltage_Warning;
    sTopic_t Open_Relay_Crash;
    sTopic_t Open_Relay_Error;
}sState_bit_t;

typedef struct{
    sTopic_t ERR_NO_ERROR;
    sTopic_t ERR_CHIPSYS;
    sTopic_t ERR_OVER_CURRENT;
    sTopic_t ERR_OVER_VOLTAGE;
    sTopic_t ERR_UNDER_VOLTAGE;
    sTopic_t ERR_OVER_UNDER_TEMPERATURE;
    sTopic_t ERR_COMM_COMMON;
}Module_Errors_t;

typedef struct{
    sState_bit_t AEC_State;
    sTopic_t AEC_SoC_pct;
    sAEC_Errors_t AEC_Errors;
    sAEC_Warnings_t AEC_Warnings;
    sTopic_t AEC_Error_from_Node_ID;
    sTopic_t AEC_Voltage_V;
}s0x1E3_Frame_t;

typedef struct{
    sTopic_t AEC_System_Maximum_String_Cell_Voltage_V;
    sTopic_t AEC_System_Minimum_String_Cell_Voltage_V;
    sTopic_t AEC_System_Heater_Status;
    sTopic_t AEC_SoH_pct;
    sTopic_t AEC_Hottest_Module_Temperature_C;
    sTopic_t AEC_Coldest_Module_Temperature_C;
    sTopic_t AEC_SW_Version;
    sTopic_t AEC_Relays_Status;
}s0x2E3_Frame_t;

typedef struct{
    sTopic_t AEC_Remaining_Capacity_Ah;
    sTopic_t AEC_Time_Remaining_mins;
    sTopic_t AEC_Lifetime_Charged_kWh;
    sTopic_t AEC_ISO_Monitor_kOhm;
}s0x3E3_Frame_t;


typedef struct{
    sTopic_t AEC_Permitted_Charge_Current_Amp;
    sTopic_t AEC_Permitted_Discharge_Current_Amp;
    sTopic_t AEC_Alive_Counter;
    sTopic_t AEC_Current_Amp;
}s0x4E3_Frame_t;

typedef struct{
    sTopic_t Module_Maximum_String_Cells_Voltage_V;
    sTopic_t Module_Minimum_String_Cells_Voltage_V;
    Module_Errors_t Module_Errors;
    sTopic_t Module_Heater_Status;
    sTopic_t Module_Maximum_Module_Temperature_C;
    sTopic_t Module_Minimum_Module_Temperature_C;
    sTopic_t Module_Voltage_mV;
}sModule_t;

typedef union{
    uint8_t u8[2];
    uint16_t u16;
    int16_t s16;
}union16_t;



#endif /* DATATYPES_H_ */
