

#ifndef _GATT_DB_H_
#define _GATT_DB_H_

tBleStatus Add_SerialPortService(void);
void Attribute_Modified_CB(uint16_t handle, uint8_t data_length, uint8_t *att_data);

extern uint16_t SerialPortServHandle, TXCharHandle, RXCharHandle;

#endif /* _GATT_DB_H_ */
