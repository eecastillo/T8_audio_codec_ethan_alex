#include <stdio.h>
#include <WM87313.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK66F18.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */
#include "freertos_i2c.h"
#include "task.h"
#include "semphr.h"
/* TODO: insert other definitions and declarations here. */
/*
 * @brief   Application entry point.
 */
SemaphoreHandle_t i2c_sem_bin;

void init_codec(void *parameters)
{
	uint8_t sucess = freertos_i2c_fail;
	sucess = config_codec();
	if(freertos_i2c_sucess == sucess)
	{
		PRINTF("Configuracion finalizada\n\r");
	}
	xSemaphoreGive(i2c_sem_bin);
	vTaskSuspend(NULL);
}

void codec_audio(void *parameters)
{

	xSemaphoreTake(i2c_sem_bin, portMAX_DELAY);

	for(;;)
	{
		/*TODO AUDIO FUNCTIONS*/
		vTaskDelay(pdMS_TO_TICKS(300));
	}
}

int main(void)
{
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    i2c_sem_bin = xSemaphoreCreateBinary();

    xTaskCreate(init_codec, "init_codec", 110, NULL, 1, NULL);
    xTaskCreate(codec_audio, "codec_audio", 110, NULL, 1, NULL);

    vTaskStartScheduler();

    while(1)
    {

    }
    return 0 ;
}
