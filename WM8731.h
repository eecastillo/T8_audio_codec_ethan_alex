/*
 * WM8731.h
 *
 *  Created on: Nov 13, 2020
 *      Author: eduar
 */

#ifndef WM8731_H_
#define WM8731_H_

#include "freertos_i2c.h"
#include "fsl_clock.h"
#include "fsl_port.h"
#include "stdint.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"

#define WM8731_ADDRESS 0x1A

#define LEFT_LINE_IN_REG     	0x00
#define RIGHT_LINE_IN_REG	 	0x01
#define LEFT_HEADPHONE_OUT_REG  0x02
#define RIGHT_HEADPHONE_OUT_REG 0x03
#define ANALOGUE_AUDIO_PATH_REG 0x04
#define DIGITAL_AUDIO_PATH_REG	0x05
#define POWER_DOWN_CTRL_REG		0x0C
#define DIG_AUDIO_INTERFACE_REG 0x07
#define SAMPLING_CTRL_REG		0x08
#define RESET_REG				0x0F
#define ENABLE_CODEC			0x12

#define I2C_SCL		2U
#define I2C_SDA		3U
#define BAUD_RATE	100000
#define I2C_DELAY	100

freertos_i2c_flag_t config_codec(void);

#endif /* WM8731_H_ */
