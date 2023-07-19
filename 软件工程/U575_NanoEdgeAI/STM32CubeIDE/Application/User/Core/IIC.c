/*
 * IIC.c
 *
 *  Created on: Jul 16, 2023
 *      Author: LFF
 */

#define IIC_SDA_PIN GPIO_PIN_6
#define IIC_SCL_PIN GPIO_PIN_7
#define IIC_PIN_PORT GPIOD

#include "main.h"

void IIC_SDA(unsigned char Value)
{
		HAL_GPIO_WritePin(IIC_PIN_PORT, IIC_SDA_PIN, Value);
}

void IIC_SCL(unsigned char Value)
{
		HAL_GPIO_WritePin(IIC_PIN_PORT, IIC_SCL_PIN, Value);
}

uint8_t IIC_R_SDA(void)
{
	uint8_t Value;
	Value = HAL_GPIO_ReadPin(IIC_PIN_PORT, IIC_SDA_PIN);
	return Value;
}

void IIC_Start(void)
{
	IIC_SDA(1);
	IIC_SCL(1);
	IIC_SDA(0);
	IIC_SCL(0);
}

void IIC_Stop(void)
{
	IIC_SCL(0);
	IIC_SDA(0);
	IIC_SCL(1);
	IIC_SDA(1);
}

void IIC_WriteByte(uint8_t Byte)
{
	uint8_t i = 0;

	for(i = 0; i < 8; i++)
	{
		IIC_SDA(Byte & (0x80 >> i));
		IIC_SCL(1);
		IIC_SCL(0);
	}
}

uint8_t IIC_ReadByte(void)
{
	uint8_t i, Byte = 0x00;

	IIC_SDA(1);

	for(i = 0; i < 8; i++)
	{
		IIC_SCL(1);
		if(IIC_R_SDA() == 1)
			Byte |= (0x80 >> i);
		IIC_SCL(0);
	}

	return Byte;
}

void IIC_SendACK(uint8_t ACK)
{
	IIC_SDA(ACK);
	IIC_SCL(1);
	IIC_SCL(0);
}

uint8_t IIC_ReadACK(void)
{
	uint8_t ACK = 0;
	IIC_SDA(1);
	IIC_SCL(1);
	ACK = IIC_R_SDA();
	IIC_SCL(0);
	return ACK;
}
