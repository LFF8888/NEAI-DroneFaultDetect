#ifndef __IIC_H__
#define __IIC_H__

void IIC_Start(void);
void IIC_Stop(void);
void IIC_WriteByte(uint8_t Byte);
uint8_t IIC_ReadByte(void);
void IIC_SendACK(uint8_t ACK);
uint8_t IIC_ReadACK(void);

#endif
