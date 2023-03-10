

/**
  ******************************************************************************
  * @file    DTM_cmd_db.h
  * @author  AMG - RF Application team
  * @version V1.0.0
  * @date    20 November 2019
  * @brief   Autogenerated files, do not edit!!
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT STMicroelectronics</center></h2>
  ******************************************************************************
  */
#ifndef _DTM_CMD_DB_H_
#define _DTM_CMD_DB_H_


#include <stdint.h>
typedef uint16_t (*hci_command_process_and_response_type)(uint8_t *buffer_in, uint16_t buffer_in_length, uint8_t *buffer_out, uint16_t buffer_out_max_length) ;
typedef struct hci_command_table_type_s {
  uint16_t opcode;
  hci_command_process_and_response_type execute;
} hci_command_table_type;

extern const hci_command_table_type hci_command_table[164];
extern void send_event(uint8_t *buffer_out, uint16_t buffer_out_length, int8_t overflow_index);
extern void send_event_isr(uint8_t *buffer_out, uint16_t buffer_out_length, int8_t overflow_index);
/* NOTE: aci_hal_updater_start() function prototype: to be implemented on DTM context */
tBleStatus aci_hal_updater_start(void);
/* NOTE: aci_hal_get_firmware_details() function prototype: to be implemented on DTM context */
tBleStatus aci_hal_get_firmware_details(uint8_t *DTM_version_major,uint8_t *DTM_version_minor,uint8_t *DTM_version_patch,uint8_t *DTM_variant,uint16_t *DTM_Build_Number,uint8_t *BTLE_Stack_version_major,uint8_t *BTLE_Stack_version_minor,uint8_t *BTLE_Stack_version_patch,uint8_t *BTLE_Stack_development,uint16_t *BTLE_Stack_variant,uint16_t *BTLE_Stack_Build_Number);
/* NOTE:  aci_hal_transmitter_test_packets() function prototype: to be implemented on DTM context */
tBleStatus aci_hal_transmitter_test_packets(uint8_t TX_Frequency,uint8_t Length_Of_Test_Data, uint8_t Packet_Payload, uint16_t Number_Of_Packets);

/* Throughput test commands TBR */
tBleStatus aci_test_tx_notification_start(uint16_t Connection_Handle, uint16_t Service_Handle, uint16_t Char_Handle, uint16_t Value_Length);
tBleStatus aci_test_tx_write_command_start(uint16_t Connection_Handle, uint16_t Attr_Handle, uint16_t Value_Length);
tBleStatus aci_test_rx_start(uint16_t Connection_Handle, uint16_t Attribute_Handle, uint8_t Notifications_WriteCmds);
tBleStatus aci_test_stop(uint8_t TX_RX);
tBleStatus aci_test_report(uint32_t *TX_Notifications, uint32_t *RX_Notifications, uint16_t *RX_Data_Length, uint32_t *RX_Sequence_Errors);

#endif /* _DTM_CMD_DB_H_ */
