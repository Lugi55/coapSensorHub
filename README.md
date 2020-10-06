# coapSensorHub

## Module
### main.c
`void udp_echo_recv(void *arg, struct udp_pcb *pcb, struct pbuf *p, struct ip_addr *addr, u16_t port)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ISR for udp echo server<br>
`void udp_echo_init(void)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;udp echo server init<br>
### can.c und can.h
`void can_IntHandler(void)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ISR for can messages<br>
`void can_Init(uint32_t ui32SysClock)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;init can peripherie<br>
`void can_PrettyPrint(tCANMsgObject sCANMessage)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;print can message over uart<br>
only for debugging purposes<br>
`eFifoStatus_t can_FifoPush(tCANMsgObject sCANMessage)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;push can message to fifo<br>
`eFifoStatus_t can_FifoPop(tCANMsgObject *sCANMessage)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pop can message out of fifo<br>
`void can_SetLedRed(bool s)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;can set led red<br>
`void can_SetLedGreen1(bool s)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;can set led green 1<br>
`void can_SetLedGreen2(bool s)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;can set led green 2<br>
`void can_Enable(void)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;enable can peripherie<br>
`void can_Disable(void)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;disable can peripherie<br>
### parser.c und parser.h
`void parser_set_ps0x1E3_Frame(s0x1E3_Frame_t *_ps0x1E3_Frame)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set pointer of Struckt<br>
`void parser_set_ps0x2E3_Frame(s0x2E3_Frame_t *_ps0x2E3_Frame)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set pointer of Struckt<br>
`void parser_set_ps0x3E3_Frame(s0x3E3_Frame_t *_ps0x3E3_Frame)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set pointer of Struckt<br>
`void parser_set_ps0x4E3_Frame(s0x4E3_Frame_t *_ps0x4E3_Frame)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set pointer of Struckt<br>
`void parser_set_psModule1(sModule_t *_psModule1)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set pointer of Struckt<br>
`void parser_set_psModule2(sModule_t *_psModule2)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set pointer of Struckt<br>
`void parser_set_psModule3(sModule_t *_psModule3)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set pointer of Struckt<br>
`void parser_set_psModule4(sModule_t *_psModule4)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set pointer of Struckt<br>
`void parser_set_psModule5(sModule_t *_psModule5)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set pointer of Struckt<br>
`void parser_set_psModule6(sModule_t *_psModule6)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set pointer of Struckt<br>
`void parser_set_psModule7(sModule_t *_psModule7)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;set pointer of Struckt<br>
`void parser_parseCanMsg(tCANMsgObject sCANMessage)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;parse can Message<br>
`void parser_parseNode(tCANMsgObject sCANMessage)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pares Module Frame<br>
`void parser_parse1E3(tCANMsgObject sCANMessage)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pares 1E3 Frame<br>
`void parser_parse2E3(tCANMsgObject sCANMessage)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pares 2E3 Frame<br>
`void parser_parse3E3(tCANMsgObject sCANMessage)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;pares 3E3 Frame<br>
`void parser_parse4E3(tCANMsgObject sCANMessage)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;parse 4E3 Frame<br>
`void parser_parseModule(tCANMsgObject sCANMessage, sModule_t *sModule)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;parse Module<br>
### endpoints.c und endpoints.h
`void build_rsp(void)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;make a response for discover function<br>
`void endpoints_updateTopic(sTopic_t *psTopic, char *bufferString)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;generate the plain text for get request<br>
`void endpoints_updateTopics(sTopic_t *psTopic, uint16_t len, char *jsonString)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;generate the plain text of multiple endpoints in a json string format<br>
`void endpoints_Init1E3Frame(s0x1E3_Frame_t *ps0x1E3_Frame)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;init 1E3 Frame<br>
`void endpoints_Init2E3Frame(s0x2E3_Frame_t *ps0x2E3_Frame)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;init 2E3 Frame<br>
`void endpoints_Init3E3Frame(s0x3E3_Frame_t *ps0x3E3_Frame)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;init 3E3 Frame<br>
`void endpoints_Init4E3Frame(s0x4E3_Frame_t *ps0x4E3_Frame)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;init 4E3 Frame<br>
`void endpoints_InitModuleFrame(sModule_t *psModule)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;init Module Frame<br>
### coap.c und coap.h
`int coap_parse(coap_packet_t *pkt, const uint8_t *buf, size_t buflen)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;parse a incoming UDP Frame<br>
`int coap_handle_req(coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;make a response Frame<br>
`int coap_build(uint8_t *buf, size_t *buflen, const coap_packet_t *pkt)`<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;flatten the struckt into a buffer<br>
### datatypes.h
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;defines mulitple struckts enums and unions

