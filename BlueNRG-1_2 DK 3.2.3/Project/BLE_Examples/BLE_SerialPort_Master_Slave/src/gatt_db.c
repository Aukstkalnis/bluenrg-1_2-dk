
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "ble_const.h" 
#include "bluenrg1_stack.h"
#include "osal.h"
#include "app_state.h"
#include "SDK_EVAL_Config.h"
#include "serial_port.h"

uint16_t SerialPortServHandle, TXCharHandle, RXCharHandle;

/* UUIDs */
Service_UUID_t service_uuid;
Char_UUID_t char_uuid;

/*******************************************************************************
* Function Name  : Add_SerialPort_Service
* Description    : Add the Serial Port service.
* Input          : None
* Return         : Status.
*******************************************************************************/
uint8_t Add_SerialPort_Service(void)
{
  uint8_t ret;

  /*
  UUIDs:
  D973F2E0-B19E-11E2-9E96-0800200C9A66
  D973F2E1-B19E-11E2-9E96-0800200C9A66
  D973F2E2-B19E-11E2-9E96-0800200C9A66
  */

  const uint8_t uuid[16] = {0x66,0x9a,0x0c,0x20,0x00,0x08,0x96,0x9e,0xe2,0x11,0x9e,0xb1,0xe0,0xf2,0x73,0xd9};
  const uint8_t charUuidTX[16] = {0x66,0x9a,0x0c,0x20,0x00,0x08,0x96,0x9e,0xe2,0x11,0x9e,0xb1,0xe1,0xf2,0x73,0xd9};
  const uint8_t charUuidRX[16] = {0x66,0x9a,0x0c,0x20,0x00,0x08,0x96,0x9e,0xe2,0x11,0x9e,0xb1,0xe2,0xf2,0x73,0xd9};

  Osal_MemCpy(&service_uuid.Service_UUID_128, uuid, 16);
  
  ret = aci_gatt_add_service(UUID_TYPE_128, &service_uuid, PRIMARY_SERVICE, 6, &SerialPortServHandle);
  if (ret != BLE_STATUS_SUCCESS) goto fail;    

  Osal_MemCpy(&char_uuid.Char_UUID_128, charUuidTX, 16);
  ret =  aci_gatt_add_char(SerialPortServHandle, UUID_TYPE_128, &char_uuid, 20, CHAR_PROP_NOTIFY, ATTR_PERMISSION_NONE, 0,
                16, 1, &TXCharHandle);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  Osal_MemCpy(&char_uuid.Char_UUID_128, charUuidRX, 16);
  ret =  aci_gatt_add_char(SerialPortServHandle, UUID_TYPE_128, &char_uuid, 20, CHAR_PROP_WRITE|CHAR_PROP_WRITE_WITHOUT_RESP, ATTR_PERMISSION_NONE, GATT_NOTIFY_ATTRIBUTE_WRITE,
                16, 1, &RXCharHandle);
  if (ret != BLE_STATUS_SUCCESS) goto fail;

  printf("Serial Port Service added.\nTX Char Handle %04X, RX Char Handle %04X\n", TXCharHandle, RXCharHandle);
  return BLE_STATUS_SUCCESS; 

fail:
  printf("Error while adding Serial Port service.\n");
  return BLE_STATUS_ERROR ;
}

/*******************************************************************************
* Function Name  : Attribute_Modified_CB
* Description    : Attribute modified callback.
* Input          : Attribute handle modified.
*                  Length of the data.
*                  Attribute data.
* Return         : None.
*******************************************************************************/
void Attribute_Modified_CB(uint16_t handle, uint16_t data_length, uint8_t *att_data)
{
  if(handle == RXCharHandle + 1)
  {
    for(int i = 0; i < data_length; i++)
      printf("%c", att_data[i]);
  }
  else if(handle == TXCharHandle + 2)
  {        
    if(att_data[0] == 0x01)
      APP_FLAG_SET(NOTIFICATIONS_ENABLED);
  }
}


