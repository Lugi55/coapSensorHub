

#include "endpoints.h"


char bufferString[500] = {};
const uint16_t rsplen = 3000;
static char rsp[3000] = "";

s0x1E3_Frame_t s0x1E3_Frame;
s0x2E3_Frame_t s0x2E3_Frame;
s0x3E3_Frame_t s0x3E3_Frame;
s0x4E3_Frame_t s0x4E3_Frame;
sModule_t sModule1;
sModule_t sModule2;
sModule_t sModule3;
sModule_t sModule4;
sModule_t sModule5;
sModule_t sModule6;
sModule_t sModule7;



//////////////////////
//setup endpoint module
//////////////////////
void endpoint_setup(void){

    endpoints_Init1E3Frame(&s0x1E3_Frame);
    endpoints_Init2E3Frame(&s0x2E3_Frame);
    endpoints_Init3E3Frame(&s0x3E3_Frame);
    endpoints_Init4E3Frame(&s0x4E3_Frame);
    endpoints_InitModuleFrame(&sModule1);
    endpoints_InitModuleFrame(&sModule2);
    endpoints_InitModuleFrame(&sModule3);
    endpoints_InitModuleFrame(&sModule4);
    endpoints_InitModuleFrame(&sModule5);
    endpoints_InitModuleFrame(&sModule6);
    endpoints_InitModuleFrame(&sModule7);

    parser_set_ps0x1E3_Frame(&s0x1E3_Frame);
    parser_set_ps0x2E3_Frame(&s0x2E3_Frame);
    parser_set_ps0x3E3_Frame(&s0x3E3_Frame);
    parser_set_ps0x4E3_Frame(&s0x4E3_Frame);
    parser_set_psModule1(&sModule1);
    parser_set_psModule2(&sModule2);
    parser_set_psModule3(&sModule3);
    parser_set_psModule4(&sModule4);
    parser_set_psModule5(&sModule5);
    parser_set_psModule6(&sModule6);
    parser_set_psModule7(&sModule7);

    build_rsp();
    UARTprintf("setup endpoints\n");
}



//////////////////////
//init 1e3 struct
//////////////////////
void endpoints_Init1E3Frame(s0x1E3_Frame_t *ps0x1E3_Frame){
    strcpy(ps0x1E3_Frame->AEC_State.RELAY.topicString, "RELAY");
    ps0x1E3_Frame->AEC_State.RELAY.type = BOOL;
    ps0x1E3_Frame->AEC_State.RELAY.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_State.Low_Voltage_Warning.topicString, "Low_Voltage_Warning");
    ps0x1E3_Frame->AEC_State.Low_Voltage_Warning.type = BOOL;
    ps0x1E3_Frame->AEC_State.Low_Voltage_Warning.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_State.High_Voltage_Warning.topicString, "High_Voltage_Warning");
    ps0x1E3_Frame->AEC_State.High_Voltage_Warning.type = BOOL;
    ps0x1E3_Frame->AEC_State.High_Voltage_Warning.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_State.Open_Relay_Crash.topicString, "Open_Relay_Crash");
    ps0x1E3_Frame->AEC_State.Open_Relay_Crash.type = BOOL;
    ps0x1E3_Frame->AEC_State.Open_Relay_Crash.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_State.Open_Relay_Error.topicString, "Open_Relay_Error");
    ps0x1E3_Frame->AEC_State.Open_Relay_Error.type = BOOL;
    ps0x1E3_Frame->AEC_State.Open_Relay_Error.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_SoC_pct.topicString, "SoC_pct");
    ps0x1E3_Frame->AEC_SoC_pct.type = UINT;
    ps0x1E3_Frame->AEC_SoC_pct.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_NO_ERROR.topicString, "ERR_NO_ERROR");
    ps0x1E3_Frame->AEC_Errors.ERR_NO_ERROR.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_NO_ERROR.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_SELFTEST.topicString, "ERR_SELFTEST");
    ps0x1E3_Frame->AEC_Errors.ERR_SELFTEST.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_SELFTEST.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_OVER_CURRENT.topicString, "ERR_OVER_CURRENT");
    ps0x1E3_Frame->AEC_Errors.ERR_OVER_CURRENT.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_OVER_CURRENT.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_OVER_VOLTAGE.topicString, "ERR_OVER_VOLTAGE");
    ps0x1E3_Frame->AEC_Errors.ERR_OVER_VOLTAGE.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_OVER_VOLTAGE.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_UNDER_VOLTAGE.topicString, "ERR_UNDER_VOLTAGE");
    ps0x1E3_Frame->AEC_Errors.ERR_UNDER_VOLTAGE.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_UNDER_VOLTAGE.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_DIGOVLD.topicString, "ERR_DIGOVLD");
    ps0x1E3_Frame->AEC_Errors.ERR_DIGOVLD.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_DIGOVLD.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_OVER_UNDER_TEMPERATURE.topicString, "ERR_OVER_UNDER_TEMPERATURE");
    ps0x1E3_Frame->AEC_Errors.ERR_OVER_UNDER_TEMPERATURE.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_OVER_UNDER_TEMPERATURE.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_PARAMINIT.topicString, "ERR_PARAMINIT");
    ps0x1E3_Frame->AEC_Errors.ERR_PARAMINIT.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_PARAMINIT.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_COMMUNICATION.topicString, "ERR_COMMUNICATION");
    ps0x1E3_Frame->AEC_Errors.ERR_COMMUNICATION.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_COMMUNICATION.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_HVIL.topicString, "ERR_HVIL");
    ps0x1E3_Frame->AEC_Errors.ERR_HVIL.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_HVIL.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Plus.topicString, "ERR_Contactor_Plus");
    ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Plus.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Plus.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Minus.topicString, "ERR_Contactor_Minus");
    ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Minus.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Minus.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Pre_Charge.topicString, "ERR_Contactor_Pre_Charge");
    ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Pre_Charge.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_Contactor_Pre_Charge.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_CELL_DELTA.topicString, "ERR_CELL_DELTA");
    ps0x1E3_Frame->AEC_Errors.ERR_CELL_DELTA.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_CELL_DELTA.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Errors.ERR_Service.topicString, "ERR_Service");
    ps0x1E3_Frame->AEC_Errors.ERR_Service.type = BOOL;
    ps0x1E3_Frame->AEC_Errors.ERR_Service.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Warnings.ERR_NO_ERROR.topicString, "ERR_NO_ERROR");
    ps0x1E3_Frame->AEC_Warnings.ERR_NO_ERROR.type = BOOL;
    ps0x1E3_Frame->AEC_Warnings.ERR_NO_ERROR.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Warnings.ERR_SELFTEST.topicString, "ERR_SELFTEST");
    ps0x1E3_Frame->AEC_Warnings.ERR_SELFTEST.type = BOOL;
    ps0x1E3_Frame->AEC_Warnings.ERR_SELFTEST.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Warnings.ERR_OVER_CURRENT.topicString, "ERR_OVER_CURRENT");
    ps0x1E3_Frame->AEC_Warnings.ERR_OVER_CURRENT.type = BOOL;
    ps0x1E3_Frame->AEC_Warnings.ERR_OVER_CURRENT.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Warnings.ERR_OVER_VOLTAGE.topicString, "ERR_OVER_VOLTAGE");
    ps0x1E3_Frame->AEC_Warnings.ERR_OVER_VOLTAGE.type = BOOL;
    ps0x1E3_Frame->AEC_Warnings.ERR_OVER_VOLTAGE.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Warnings.ERR_UNDER_VOLTAGE.topicString, "ERR_UNDER_VOLTAGE");
    ps0x1E3_Frame->AEC_Warnings.ERR_UNDER_VOLTAGE.type = BOOL;
    ps0x1E3_Frame->AEC_Warnings.ERR_UNDER_VOLTAGE.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Warnings.ERR_DIGOVLD.topicString, "ERR_DIGOVLD");
    ps0x1E3_Frame->AEC_Warnings.ERR_DIGOVLD.type = BOOL;
    ps0x1E3_Frame->AEC_Warnings.ERR_DIGOVLD.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Warnings.ERR_OVER_UNDER_TEMPERATURE.topicString, "ERR_OVER_UNDER_TEMPERATURE");
    ps0x1E3_Frame->AEC_Warnings.ERR_OVER_UNDER_TEMPERATURE.type = BOOL;
    ps0x1E3_Frame->AEC_Warnings.ERR_OVER_UNDER_TEMPERATURE.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Warnings.ERR_PARAMINIT.topicString, "ERR_PARAMINIT");
    ps0x1E3_Frame->AEC_Warnings.ERR_PARAMINIT.type = BOOL;
    ps0x1E3_Frame->AEC_Warnings.ERR_PARAMINIT.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Warnings.ERR_COMMUNICATION.topicString, "ERR_COMMUNICATION");
    ps0x1E3_Frame->AEC_Warnings.ERR_COMMUNICATION.type = BOOL;
    ps0x1E3_Frame->AEC_Warnings.ERR_COMMUNICATION.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Error_from_Node_ID.topicString,"Error_from_Node_ID");
    ps0x1E3_Frame->AEC_Error_from_Node_ID.type = UINT;
    ps0x1E3_Frame->AEC_Error_from_Node_ID.scalingFactor = 1;
    strcpy(ps0x1E3_Frame->AEC_Voltage_V.topicString,"Voltage_V");
    ps0x1E3_Frame->AEC_Voltage_V.type = UINT;
    ps0x1E3_Frame->AEC_Voltage_V.scalingFactor = 0.25;
}

//////////////////////
//init 2e3 struct
//////////////////////
void endpoints_Init2E3Frame(s0x2E3_Frame_t *ps0x2E3_Frame){
    strcpy(ps0x2E3_Frame->AEC_System_Maximum_String_Cell_Voltage_V.topicString,"AEC_System_Maximum_String_Cell_Voltage_V");
    ps0x2E3_Frame->AEC_System_Maximum_String_Cell_Voltage_V.type = UINT;
    ps0x2E3_Frame->AEC_System_Maximum_String_Cell_Voltage_V.scalingFactor = 0.02;
    strcpy(ps0x2E3_Frame->AEC_System_Minimum_String_Cell_Voltage_V.topicString,"AEC_System_Minimum_String_Cell_Voltage_V");
    ps0x2E3_Frame->AEC_System_Minimum_String_Cell_Voltage_V.type = UINT;
    ps0x2E3_Frame->AEC_System_Minimum_String_Cell_Voltage_V.scalingFactor = 0.02;
    strcpy(ps0x2E3_Frame->AEC_System_Heater_Status.topicString,"AEC_System_Heater_Status");
    ps0x2E3_Frame->AEC_System_Heater_Status.type = BOOL;
    ps0x2E3_Frame->AEC_System_Heater_Status.scalingFactor = 1;
    strcpy(ps0x2E3_Frame->AEC_SoH_pct.topicString,"SoH_pct");
    ps0x2E3_Frame->AEC_SoH_pct.type = UINT;
    ps0x2E3_Frame->AEC_SoH_pct.scalingFactor = 1;
    strcpy(ps0x2E3_Frame->AEC_Hottest_Module_Temperature_C.topicString,"Hottest_Module_Temperature_C");
    ps0x2E3_Frame->AEC_Hottest_Module_Temperature_C.type = INT;
    ps0x2E3_Frame->AEC_Hottest_Module_Temperature_C.scalingFactor = 1;
    strcpy(ps0x2E3_Frame->AEC_Coldest_Module_Temperature_C.topicString,"Coldest_Module_Temperature_C");
    ps0x2E3_Frame->AEC_Coldest_Module_Temperature_C.type = INT;
    ps0x2E3_Frame->AEC_Coldest_Module_Temperature_C.scalingFactor = 1;
    strcpy(ps0x2E3_Frame->AEC_SW_Version.topicString,"SW_Version");
    ps0x2E3_Frame->AEC_SW_Version.type = UINT;
    ps0x2E3_Frame->AEC_SW_Version.scalingFactor = 1;
    strcpy(ps0x2E3_Frame->AEC_Relays_Status.topicString,"Relays_Status");
    ps0x2E3_Frame->AEC_Relays_Status.type = BOOL;
    ps0x2E3_Frame->AEC_Relays_Status.scalingFactor = 1;
}


//////////////////////
//init 3e3 struct
//////////////////////
void endpoints_Init3E3Frame(s0x3E3_Frame_t *ps0x3E3_Frame){
    strcpy(ps0x3E3_Frame->AEC_Remaining_Capacity_Ah.topicString,"Remaining_Capacity_Amp");
    ps0x3E3_Frame->AEC_Remaining_Capacity_Ah.type = UINT;
    ps0x3E3_Frame->AEC_Remaining_Capacity_Ah.scalingFactor = 0.1;
    strcpy(ps0x3E3_Frame->AEC_Time_Remaining_mins.topicString,"Time_Remaining_mins");
    ps0x3E3_Frame->AEC_Time_Remaining_mins.type = UINT;
    ps0x3E3_Frame->AEC_Time_Remaining_mins.scalingFactor = 1;
    strcpy(ps0x3E3_Frame->AEC_Lifetime_Charged_kWh.topicString,"Lifetime_Charged_kWh");
    ps0x3E3_Frame->AEC_Lifetime_Charged_kWh.type = UINT;
    ps0x3E3_Frame->AEC_Lifetime_Charged_kWh.scalingFactor = 1;
    strcpy(ps0x3E3_Frame->AEC_ISO_Monitor_kOhm.topicString,"AEC_ISO_Monitor_kOhm");
    ps0x3E3_Frame->AEC_ISO_Monitor_kOhm.type = UINT;
    ps0x3E3_Frame->AEC_ISO_Monitor_kOhm.scalingFactor = 1;
}

//////////////////////
//init 4e3 struct
//////////////////////
void endpoints_Init4E3Frame(s0x4E3_Frame_t *ps0x4E3_Frame){
    strcpy(ps0x4E3_Frame->AEC_Permitted_Charge_Current_Amp.topicString,"Permitted_Charge_Current_Amp");
    ps0x4E3_Frame->AEC_Permitted_Charge_Current_Amp.type = INT;
    ps0x4E3_Frame->AEC_Permitted_Charge_Current_Amp.scalingFactor = 1;
    strcpy(ps0x4E3_Frame->AEC_Permitted_Discharge_Current_Amp.topicString,"Permitted_Discharge_Current_Amp");
    ps0x4E3_Frame->AEC_Permitted_Discharge_Current_Amp.type = INT;
    ps0x4E3_Frame->AEC_Permitted_Discharge_Current_Amp.scalingFactor = 1;
    strcpy(ps0x4E3_Frame->AEC_Alive_Counter.topicString,"Alive_Counter");
    ps0x4E3_Frame->AEC_Alive_Counter.type = UINT;
    ps0x4E3_Frame->AEC_Alive_Counter.scalingFactor = 1;
    strcpy(ps0x4E3_Frame->AEC_Current_Amp.topicString,"Current_Amp");
    ps0x4E3_Frame->AEC_Current_Amp.type = INT;
    ps0x4E3_Frame->AEC_Current_Amp.scalingFactor = 0.25;
}

//////////////////////
//init module
//////////////////////
void endpoints_InitModuleFrame(sModule_t *psModule){
    strcpy(psModule->Module_Maximum_String_Cells_Voltage_V.topicString,"Maximum_String_Cells_Voltage_V");
    psModule->Module_Maximum_String_Cells_Voltage_V.type = UINT;
    psModule->Module_Maximum_String_Cells_Voltage_V.scalingFactor = 0.02;
    strcpy(psModule->Module_Minimum_String_Cells_Voltage_V.topicString,"Minimum_String_Cells_Voltage_V");
    psModule->Module_Minimum_String_Cells_Voltage_V.type = UINT;
    psModule->Module_Minimum_String_Cells_Voltage_V.scalingFactor = 0.02;
    strcpy(psModule->Module_Errors.ERR_NO_ERROR.topicString,"ERR_NO_ERROR");
    psModule->Module_Errors.ERR_NO_ERROR.type = BOOL;
    psModule->Module_Errors.ERR_NO_ERROR.scalingFactor = 1;
    strcpy(psModule->Module_Errors.ERR_CHIPSYS.topicString,"ERR_CHIPSYS");
    psModule->Module_Errors.ERR_CHIPSYS.type = BOOL;
    psModule->Module_Errors.ERR_CHIPSYS.scalingFactor = 1;
    strcpy(psModule->Module_Errors.ERR_OVER_CURRENT.topicString,"ERR_OVER_CURRENT");
    psModule->Module_Errors.ERR_OVER_CURRENT.type = BOOL;
    psModule->Module_Errors.ERR_OVER_CURRENT.scalingFactor = 1;
    strcpy(psModule->Module_Errors.ERR_OVER_VOLTAGE.topicString,"ERR_OVER_VOLTAGE");
    psModule->Module_Errors.ERR_OVER_VOLTAGE.type = BOOL;
    psModule->Module_Errors.ERR_OVER_VOLTAGE.scalingFactor = 1;
    strcpy(psModule->Module_Errors.ERR_UNDER_VOLTAGE.topicString,"ERR_UNDER_VOLTAGE");
    psModule->Module_Errors.ERR_UNDER_VOLTAGE.type = BOOL;
    psModule->Module_Errors.ERR_UNDER_VOLTAGE.scalingFactor = 1;
    strcpy(psModule->Module_Errors.ERR_OVER_UNDER_TEMPERATURE.topicString,"ERR_OVER_UNDER_TEMPERATURE");
    psModule->Module_Errors.ERR_OVER_UNDER_TEMPERATURE.type = BOOL;
    psModule->Module_Errors.ERR_OVER_UNDER_TEMPERATURE.scalingFactor = 1;
    strcpy(psModule->Module_Errors.ERR_COMM_COMMON.topicString,"ERR_COMM_COMMON");
    psModule->Module_Errors.ERR_COMM_COMMON.type = BOOL;
    psModule->Module_Errors.ERR_COMM_COMMON.scalingFactor = 1;
    strcpy(psModule->Module_Heater_Status.topicString,"Heater_Status");
    psModule->Module_Heater_Status.type = BOOL;
    psModule->Module_Heater_Status.scalingFactor = 1;
    strcpy(psModule->Module_Maximum_Module_Temperature_C.topicString,"Module_Maximum_Module_Temperature_C");
    psModule->Module_Maximum_Module_Temperature_C.type = INT;
    psModule->Module_Maximum_Module_Temperature_C.scalingFactor = 1;
    strcpy(psModule->Module_Minimum_Module_Temperature_C.topicString,"Module_Minimum_Module_Temperature_C");
    psModule->Module_Minimum_Module_Temperature_C.type = INT;
    psModule->Module_Minimum_Module_Temperature_C.scalingFactor = 1;
    strcpy(psModule->Module_Voltage_mV.topicString,"Module_Voltage_mV");
    psModule->Module_Voltage_mV.type = UINT;
    psModule->Module_Voltage_mV.scalingFactor = 1;
}


static const coap_endpoint_path_t path_well_known_core = {2,{".well-known", "core"}};
static const coap_endpoint_path_t path_CAN_AEC_State = {3,{"CAN","AEC","State"}};
static const coap_endpoint_path_t path_CAN_AEC_SoC_pct = {3,{"CAN","AEC","SoC_pct"}};
static const coap_endpoint_path_t path_CAN_AEC_Errors = {3,{"CAN","AEC","Errors"}};
static const coap_endpoint_path_t path_CAN_AEC_Warnings = {3,{"CAN","AEC","Warnings"}};
static const coap_endpoint_path_t path_CAN_AEC_Error_from_Node_ID = {3,{"CAN","AEC","Error_from_Node_ID"}};
static const coap_endpoint_path_t path_CAN_AEC_Voltage_V = {3,{"CAN","AEC","Voltage_V"}};
static const coap_endpoint_path_t path_CAN_AEC_System_Maximum_String_Cell_Voltage_V = {3,{"CAN","AEC","System_Maximum_String_Cell_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_AEC_System_Minimum_String_Cell_Voltage_V = {3,{"CAN","AEC","System_Minimum_String_Cell_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_AEC_System_Heater_Status = {3,{"CAN","AEC","System_Heater_Status"}};
static const coap_endpoint_path_t path_CAN_AEC_SoH_pct = {3,{"CAN","AEC","SoH_pct"}};
static const coap_endpoint_path_t path_CAN_AEC_Hottest_Module_Temperature_C = {3,{"CAN","AEC","Hottest_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_AEC_Coldest_Module_Temperature_C = {3,{"CAN","AEC","Coldest_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_AEC_SW_Version = {3,{"CAN","AEC","SW_Version"}};
static const coap_endpoint_path_t path_CAN_AEC_Relays_Status = {3,{"CAN","AEC","Relays_Status"}};
static const coap_endpoint_path_t path_CAN_AEC_Remaining_Capacity_Ah = {3,{"CAN","AEC","Remaining_Capacity_Ah"}};
static const coap_endpoint_path_t path_CAN_AEC_Time_Remaining_mins = {3,{"CAN","AEC","Time_Remaining_mins"}};
static const coap_endpoint_path_t path_CAN_AEC_Lifetime_Charged_kWh = {3,{"CAN","AEC","Lifetime_Charged_kWh"}};
static const coap_endpoint_path_t path_CAN_AEC_ISO_Monitor_kOhm = {3,{"CAN","AEC","ISO_Monitor_kOhm"}};
static const coap_endpoint_path_t path_CAN_AEC_Permitted_Charge_Current_Amp = {3,{"CAN","AEC","Permitted_Charge_Current_Amp"}};
static const coap_endpoint_path_t path_CAN_AEC_Permitted_Discharge_Current_Amp = {3,{"CAN","AEC","Permitted_Discharge_Current_Amp"}};
static const coap_endpoint_path_t path_CAN_AEC_Alive_Counter = {3,{"CAN","AEC","Alive_Counter"}};
static const coap_endpoint_path_t path_CAN_AEC_Current_Amp = {3,{"CAN","AEC","Current_Amp"}};
static const coap_endpoint_path_t path_CAN_Module1_Maximum_String_Cells_Voltage_V = {3,{"CAN","Module1","Maximum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module1_Minimum_String_Cells_Voltage_V = {3,{"CAN","Module1","Minimum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module1_Errors = {3,{"CAN","Module1","Errors"}};
static const coap_endpoint_path_t path_CAN_Module1_Heater_Status = {3,{"CAN","Module1","Heater_Status"}};
static const coap_endpoint_path_t path_CAN_Module1_Maximum_Module_Temperature_C = {3,{"CAN","Module1","Maximum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module1_Minimum_Module_Temperature_C = {3,{"CAN","Module1","Minimum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module1_Voltage_mV = {3,{"CAN","Module1","Voltage_mV"}};
static const coap_endpoint_path_t path_CAN_Module2_Maximum_String_Cells_Voltage_V = {3,{"CAN","Module2","Maximum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module2_Minimum_String_Cells_Voltage_V = {3,{"CAN","Module2","Minimum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module2_Errors = {3,{"CAN","Module2","Errors"}};
static const coap_endpoint_path_t path_CAN_Module2_Heater_Status = {3,{"CAN","Module2","Heater_Status"}};
static const coap_endpoint_path_t path_CAN_Module2_Maximum_Module_Temperature_C = {3,{"CAN","Module2","Maximum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module2_Minimum_Module_Temperature_C = {3,{"CAN","Module2","Minimum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module2_Voltage_mV = {3,{"CAN","Module2","Voltage_mV"}};
static const coap_endpoint_path_t path_CAN_Module3_Maximum_String_Cells_Voltage_V = {3,{"CAN","Module3","Maximum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module3_Minimum_String_Cells_Voltage_V = {3,{"CAN","Module3","Minimum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module3_Errors = {3,{"CAN","Module3","Errors"}};
static const coap_endpoint_path_t path_CAN_Module3_Heater_Status = {3,{"CAN","Module3","Heater_Status"}};
static const coap_endpoint_path_t path_CAN_Module3_Maximum_Module_Temperature_C = {3,{"CAN","Module3","Maximum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module3_Minimum_Module_Temperature_C = {3,{"CAN","Module3","Minimum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module3_Voltage_mV = {3,{"CAN","Module3","Voltage_mV"}};
static const coap_endpoint_path_t path_CAN_Module4_Maximum_String_Cells_Voltage_V = {3,{"CAN","Module4","Maximum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module4_Minimum_String_Cells_Voltage_V = {3,{"CAN","Module4","Minimum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module4_Errors = {3,{"CAN","Module4","Errors"}};
static const coap_endpoint_path_t path_CAN_Module4_Heater_Status = {3,{"CAN","Module4","Heater_Status"}};
static const coap_endpoint_path_t path_CAN_Module4_Maximum_Module_Temperature_C = {3,{"CAN","Module4","Maximum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module4_Minimum_Module_Temperature_C = {3,{"CAN","Module4","Minimum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module4_Voltage_mV = {3,{"CAN","Module4","Voltage_mV"}};
static const coap_endpoint_path_t path_CAN_Module5_Maximum_String_Cells_Voltage_V = {3,{"CAN","Module5","Maximum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module5_Minimum_String_Cells_Voltage_V = {3,{"CAN","Module5","Minimum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module5_Errors = {3,{"CAN","Module5","Errors"}};
static const coap_endpoint_path_t path_CAN_Module5_Heater_Status = {3,{"CAN","Module5","Heater_Status"}};
static const coap_endpoint_path_t path_CAN_Module5_Maximum_Module_Temperature_C = {3,{"CAN","Module5","Maximum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module5_Minimum_Module_Temperature_C = {3,{"CAN","Module5","Minimum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module5_Voltage_mV = {3,{"CAN","Module5","Voltage_mV"}};
static const coap_endpoint_path_t path_CAN_Module6_Maximum_String_Cells_Voltage_V = {3,{"CAN","Module6","Maximum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module6_Minimum_String_Cells_Voltage_V = {3,{"CAN","Module6","Minimum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module6_Errors = {3,{"CAN","Module6","Errors"}};
static const coap_endpoint_path_t path_CAN_Module6_Heater_Status = {3,{"CAN","Module6","Heater_Status"}};
static const coap_endpoint_path_t path_CAN_Module6_Maximum_Module_Temperature_C = {3,{"CAN","Module6","Maximum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module6_Minimum_Module_Temperature_C = {3,{"CAN","Module6","Minimum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module6_Voltage_mV = {3,{"CAN","Module6","Voltage_mV"}};
static const coap_endpoint_path_t path_CAN_Module7_Maximum_String_Cells_Voltage_V = {3,{"CAN","Module7","Maximum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module7_Minimum_String_Cells_Voltage_V = {3,{"CAN","Module7","Minimum_String_Cells_Voltage_V"}};
static const coap_endpoint_path_t path_CAN_Module7_Errors = {3,{"CAN","Module7","Errors"}};
static const coap_endpoint_path_t path_CAN_Module7_Heater_Status = {3,{"CAN","Module7","Heater_Status"}};
static const coap_endpoint_path_t path_CAN_Module7_Maximum_Module_Temperature_C = {3,{"CAN","Module7","Maximum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module7_Minimum_Module_Temperature_C = {3,{"CAN","Module7","Minimum_Module_Temperature_C"}};
static const coap_endpoint_path_t path_CAN_Module7_Voltage_mV = {3,{"CAN","Module7","Voltage_mV"}};


void endpoints_updateTopic(sTopic_t *psTopic, char *bufferString){
    switch(psTopic->type){
        case INT:
            (psTopic->scalingFactor==1) ? sprintf(bufferString,"%d",psTopic->data.s) : ftoa(fabs((float)psTopic->data.s*psTopic->scalingFactor), bufferString, 1);
            break;
        case UINT:
            (psTopic->scalingFactor==1) ? sprintf(bufferString,"%u",psTopic->data.u) : ftoa(fabs((float)psTopic->data.u*psTopic->scalingFactor), bufferString, 1);
            break;
        case FLOAT:
            ftoa(fabs(psTopic->data.f*psTopic->scalingFactor), bufferString, 1);
            break;
        case BOOL:
            if(psTopic->data.b == true){
                sprintf(bufferString,"true");
            }
            else{
                sprintf(bufferString,"false");
            }
            break;
        default:
            UARTprintf("data type for publish not known\n");
            can_SetLedRed(true);
    }
}


void endpoints_updateTopics(sTopic_t *psTopic, uint16_t len, char *jsonString){
    bufferString[0] = '\0';
    char buffer[20];
    strcat(jsonString,"{");
    int i;
    for(i=0;i<len;i++){
        switch(psTopic->type){
            case INT:
                sprintf(buffer,"%d",psTopic->data.s);
                break;
            case UINT:
                sprintf(buffer,"%u",psTopic->data.u);
                break;
            case FLOAT:
                ftoa(psTopic->data.f, buffer, 1);
                break;
            case BOOL:
                if(psTopic->data.b == true){
                    sprintf(buffer,"true");
                }
                else{
                    sprintf(buffer,"false");
                }
                break;
            default:
                UARTprintf("data type for publish not known\n");
                can_SetLedRed(true);
        }

        strcat(jsonString,"\"");
        strcat(jsonString,psTopic->topicString);
        strcat(jsonString,"\":");
        strcat(jsonString,"\"");
        strcat(jsonString,buffer);
        strcat(jsonString,"\",");
        psTopic++;
    }
    jsonString[strlen(jsonString)-1] = (char)0x7d;
}

static int handle_get_well_known_core(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    return coap_make_response(scratch, outpkt, (const uint8_t *)rsp, strlen(rsp), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_APPLICATION_LINKFORMAT);
}
static int handle_get_CAN_AEC_State(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopics((sTopic_t *)&s0x1E3_Frame.AEC_State,sizeof(s0x1E3_Frame.AEC_State)/sizeof(sTopic_t),bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_SoC_pct(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x1E3_Frame.AEC_SoC_pct,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Errors(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopics((sTopic_t *)&s0x1E3_Frame.AEC_Errors,sizeof(s0x1E3_Frame.AEC_Errors)/sizeof(sTopic_t),bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Warnings(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopics((sTopic_t *)&s0x1E3_Frame.AEC_Warnings,sizeof(s0x1E3_Frame.AEC_Warnings)/sizeof(sTopic_t),bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Error_from_Node_ID(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x1E3_Frame.AEC_Error_from_Node_ID,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x1E3_Frame.AEC_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_System_Maximum_String_Cell_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x2E3_Frame.AEC_System_Maximum_String_Cell_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_System_Minimum_String_Cell_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x2E3_Frame.AEC_System_Minimum_String_Cell_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_System_Heater_Status(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x2E3_Frame.AEC_System_Heater_Status,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_SoH_pct(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x2E3_Frame.AEC_SoH_pct,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Hottest_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x2E3_Frame.AEC_Hottest_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Coldest_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x2E3_Frame.AEC_Coldest_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_SW_Version(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x2E3_Frame.AEC_SW_Version,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Relays_Status(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x2E3_Frame.AEC_Relays_Status,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Remaining_Capacity_Ah(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x3E3_Frame.AEC_Remaining_Capacity_Ah,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Time_Remaining_mins(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x3E3_Frame.AEC_Time_Remaining_mins,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Lifetime_Charged_kWh(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x3E3_Frame.AEC_Lifetime_Charged_kWh,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_ISO_Monitor_kOhm(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x3E3_Frame.AEC_ISO_Monitor_kOhm,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Permitted_Charge_Current_Amp(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x4E3_Frame.AEC_Permitted_Charge_Current_Amp,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Permitted_Discharge_Current_Amp(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x4E3_Frame.AEC_Permitted_Discharge_Current_Amp,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Alive_Counter(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x4E3_Frame.AEC_Alive_Counter,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_AEC_Current_Amp(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic(&s0x4E3_Frame.AEC_Current_Amp,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module1_Maximum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule1.Module_Maximum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module1_Minimum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule1.Module_Minimum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module1_Errors(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopics((sTopic_t *)&sModule1.Module_Errors,sizeof(sModule1.Module_Errors)/sizeof(sTopic_t),bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module1_Heater_Status(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule1.Module_Heater_Status,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module1_Maximum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule1.Module_Maximum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module1_Minimum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule1.Module_Minimum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module1_Voltage_mV(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule1.Module_Voltage_mV,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module2_Maximum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule2.Module_Maximum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module2_Minimum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule2.Module_Minimum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module2_Errors(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopics((sTopic_t *)&sModule2.Module_Errors,sizeof(sModule2.Module_Errors)/sizeof(sTopic_t),bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module2_Heater_Status(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule2.Module_Heater_Status,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module2_Maximum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule2.Module_Maximum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module2_Minimum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule2.Module_Minimum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module2_Voltage_mV(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule2.Module_Voltage_mV,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module3_Maximum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule3.Module_Maximum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module3_Minimum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule3.Module_Minimum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module3_Errors(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopics((sTopic_t *)&sModule3.Module_Errors,sizeof(sModule3.Module_Errors)/sizeof(sTopic_t),bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module3_Heater_Status(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule3.Module_Heater_Status,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module3_Maximum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule3.Module_Maximum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module3_Minimum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule3.Module_Minimum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module3_Voltage_mV(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule3.Module_Voltage_mV,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module4_Maximum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule4.Module_Maximum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module4_Minimum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule4.Module_Minimum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module4_Errors(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopics((sTopic_t *)&sModule4.Module_Errors,sizeof(sModule4.Module_Errors)/sizeof(sTopic_t),bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module4_Heater_Status(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule4.Module_Heater_Status,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module4_Maximum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule4.Module_Maximum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module4_Minimum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule4.Module_Minimum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module4_Voltage_mV(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule4.Module_Voltage_mV,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module5_Maximum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule5.Module_Maximum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module5_Minimum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule5.Module_Minimum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module5_Errors(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopics((sTopic_t *)&sModule5.Module_Errors,sizeof(sModule5.Module_Errors)/sizeof(sTopic_t),bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module5_Heater_Status(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule5.Module_Heater_Status,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module5_Maximum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule5.Module_Maximum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module5_Minimum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule5.Module_Minimum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module5_Voltage_mV(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule5.Module_Voltage_mV,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module6_Maximum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule6.Module_Maximum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module6_Minimum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule6.Module_Minimum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module6_Errors(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopics((sTopic_t *)&sModule6.Module_Errors,sizeof(sModule6.Module_Errors)/sizeof(sTopic_t),bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module6_Heater_Status(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule6.Module_Heater_Status,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module6_Maximum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule6.Module_Maximum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module6_Minimum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule6.Module_Minimum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module6_Voltage_mV(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule6.Module_Voltage_mV,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module7_Maximum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule7.Module_Maximum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module7_Minimum_String_Cells_Voltage_V(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule7.Module_Minimum_String_Cells_Voltage_V,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module7_Errors(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopics((sTopic_t *)&sModule7.Module_Errors,sizeof(sModule7.Module_Errors)/sizeof(sTopic_t),bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module7_Heater_Status(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule7.Module_Heater_Status,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module7_Maximum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule7.Module_Maximum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module7_Minimum_Module_Temperature_C(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule7.Module_Minimum_Module_Temperature_C,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}
static int handle_get_CAN_Module7_Voltage_mV(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo){
    endpoints_updateTopic((sTopic_t *)&sModule7.Module_Voltage_mV,bufferString);
    return coap_make_response(scratch, outpkt, (uint8_t *)&bufferString, strlen(bufferString), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}



const coap_endpoint_t endpoints[] =
{
    {COAP_METHOD_GET, handle_get_well_known_core, &path_well_known_core, "ct=40"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_State, &path_CAN_AEC_State, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_SoC_pct, &path_CAN_AEC_SoC_pct, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Errors, &path_CAN_AEC_Errors, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Warnings, &path_CAN_AEC_Warnings, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Error_from_Node_ID, &path_CAN_AEC_Error_from_Node_ID, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Voltage_V, &path_CAN_AEC_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_System_Maximum_String_Cell_Voltage_V, &path_CAN_AEC_System_Maximum_String_Cell_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_System_Minimum_String_Cell_Voltage_V, &path_CAN_AEC_System_Minimum_String_Cell_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_System_Heater_Status, &path_CAN_AEC_System_Heater_Status, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_SoH_pct, &path_CAN_AEC_SoH_pct, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Hottest_Module_Temperature_C, &path_CAN_AEC_Hottest_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Coldest_Module_Temperature_C, &path_CAN_AEC_Coldest_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_SW_Version, &path_CAN_AEC_SW_Version, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Relays_Status, &path_CAN_AEC_Relays_Status, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Remaining_Capacity_Ah, &path_CAN_AEC_Remaining_Capacity_Ah, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Time_Remaining_mins, &path_CAN_AEC_Time_Remaining_mins, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Lifetime_Charged_kWh, &path_CAN_AEC_Lifetime_Charged_kWh, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_ISO_Monitor_kOhm, &path_CAN_AEC_ISO_Monitor_kOhm, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Permitted_Charge_Current_Amp, &path_CAN_AEC_Permitted_Charge_Current_Amp, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Permitted_Discharge_Current_Amp, &path_CAN_AEC_Permitted_Discharge_Current_Amp, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Alive_Counter, &path_CAN_AEC_Alive_Counter, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_AEC_Current_Amp, &path_CAN_AEC_Current_Amp, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module1_Maximum_String_Cells_Voltage_V, &path_CAN_Module1_Maximum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module1_Minimum_String_Cells_Voltage_V, &path_CAN_Module1_Minimum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module1_Errors, &path_CAN_Module1_Errors, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module1_Heater_Status, &path_CAN_Module1_Heater_Status, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module1_Maximum_Module_Temperature_C, &path_CAN_Module1_Maximum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module1_Minimum_Module_Temperature_C, &path_CAN_Module1_Minimum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module1_Voltage_mV, &path_CAN_Module1_Voltage_mV, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module2_Maximum_String_Cells_Voltage_V, &path_CAN_Module2_Maximum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module2_Minimum_String_Cells_Voltage_V, &path_CAN_Module2_Minimum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module2_Errors, &path_CAN_Module2_Errors, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module2_Heater_Status, &path_CAN_Module2_Heater_Status, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module2_Maximum_Module_Temperature_C, &path_CAN_Module2_Maximum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module2_Minimum_Module_Temperature_C, &path_CAN_Module2_Minimum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module2_Voltage_mV, &path_CAN_Module2_Voltage_mV, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module3_Maximum_String_Cells_Voltage_V, &path_CAN_Module3_Maximum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module3_Minimum_String_Cells_Voltage_V, &path_CAN_Module3_Minimum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module3_Errors, &path_CAN_Module3_Errors, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module3_Heater_Status, &path_CAN_Module3_Heater_Status, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module3_Maximum_Module_Temperature_C, &path_CAN_Module3_Maximum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module3_Minimum_Module_Temperature_C, &path_CAN_Module3_Minimum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module3_Voltage_mV, &path_CAN_Module3_Voltage_mV, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module4_Maximum_String_Cells_Voltage_V, &path_CAN_Module4_Maximum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module4_Minimum_String_Cells_Voltage_V, &path_CAN_Module4_Minimum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module4_Errors, &path_CAN_Module4_Errors, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module4_Heater_Status, &path_CAN_Module4_Heater_Status, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module4_Maximum_Module_Temperature_C, &path_CAN_Module4_Maximum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module4_Minimum_Module_Temperature_C, &path_CAN_Module4_Minimum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module4_Voltage_mV, &path_CAN_Module4_Voltage_mV, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module5_Maximum_String_Cells_Voltage_V, &path_CAN_Module5_Maximum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module5_Minimum_String_Cells_Voltage_V, &path_CAN_Module5_Minimum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module5_Errors, &path_CAN_Module5_Errors, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module5_Heater_Status, &path_CAN_Module5_Heater_Status, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module5_Maximum_Module_Temperature_C, &path_CAN_Module5_Maximum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module5_Minimum_Module_Temperature_C, &path_CAN_Module5_Minimum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module5_Voltage_mV, &path_CAN_Module5_Voltage_mV, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module6_Maximum_String_Cells_Voltage_V, &path_CAN_Module6_Maximum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module6_Minimum_String_Cells_Voltage_V, &path_CAN_Module6_Minimum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module6_Errors, &path_CAN_Module6_Errors, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module6_Heater_Status, &path_CAN_Module6_Heater_Status, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module6_Maximum_Module_Temperature_C, &path_CAN_Module6_Maximum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module6_Minimum_Module_Temperature_C, &path_CAN_Module6_Minimum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module6_Voltage_mV, &path_CAN_Module6_Voltage_mV, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module7_Maximum_String_Cells_Voltage_V, &path_CAN_Module7_Maximum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module7_Minimum_String_Cells_Voltage_V, &path_CAN_Module7_Minimum_String_Cells_Voltage_V, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module7_Errors, &path_CAN_Module7_Errors, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module7_Heater_Status, &path_CAN_Module7_Heater_Status, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module7_Maximum_Module_Temperature_C, &path_CAN_Module7_Maximum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module7_Minimum_Module_Temperature_C, &path_CAN_Module7_Minimum_Module_Temperature_C, "ct=0"},
    {COAP_METHOD_GET, handle_get_CAN_Module7_Voltage_mV, &path_CAN_Module7_Voltage_mV, "ct=0"},
    {(coap_method_t)0, NULL, NULL, NULL}
};


void build_rsp(void){
    uint16_t len = rsplen;
    const coap_endpoint_t *ep = endpoints;
    int i;
    int n;
    len--;
    for(n = 0; n<30; n++)
    {
        if (NULL == ep->core_attr) {
            ep++;
            continue;
        }
        if (0 < strlen(rsp)) {
            strncat(rsp, ",", len);
            len--;
        }
        strncat(rsp, "<", len);
        len--;
        for (i = 0; i < ep->path->count; i++) {
            strncat(rsp, "/", len);
            len--;

            strncat(rsp, ep->path->elems[i], len);
            len -= strlen(ep->path->elems[i]);
        }
        strncat(rsp, ">;", len);
        len -= 2;
        strncat(rsp, ep->core_attr, len);
        len -= strlen(ep->core_attr);
        ep++;
    }
}

//////////////////////
//float to string
//////////////////////
static void ftoa(float n, char* res, int afterpoint){
    int ipart = (int)n;
    float fpart = n - (float)ipart;
    int i = intToStr(ipart, res, 0);
    if (afterpoint != 0) {
        res[i] = '.';
        fpart = fpart * pow(10, afterpoint);
        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}

//////////////////////
//reverse string
//////////////////////
static void reverse(char* str, int len){
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

//////////////////////
//integer to string
//////////////////////
static int intToStr(int x, char str[], int d){
    int i = 0;
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }

    while (i < d)
        str[i++] = '0';
    reverse(str, i);
    str[i] = '\0';
    return i;
}
