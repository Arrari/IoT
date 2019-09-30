/*
 * Copyright (C) 2015 Kaspar Schleiser <kaspar@schleiser.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       example application for setting a periodic wakeup
 *
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 *
 * @}
 */

// Подключение библиотек
#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"
int state = 1;
// Обработчик прерывания по нажатию кнопки
void btn_handler(void *arg)
{
  	// Прием аргументов, передаваемых из главного потока.
  	(void)arg;
  	// Переключение состояния пина PC8
  	state = 0;
  	gpio_toggle(GPIO_PIN(PORT_C, 8));
	xtimer_usleep(5000000);
	gpio_toggle(GPIO_PIN(PORT_C, 8));
	state = 1;
}


int main(void)
{
  // Инициализация пина PA0, к которому подключена кнопка, как источника прерывания.
  // GPIO_RISING - прерывание срабатывает по фронту
  // btn_handler - имя функции обработчика прерывания
  // NULL - ничего не передаем в аргументах
  gpio_init_int(GPIO_PIN(PORT_A, 0), GPIO_IN, GPIO_RISING, btn_handler, NULL);
  // Инициализация пина PC8 на выход
	gpio_init(GPIO_PIN(PORT_C, 8), GPIO_OUT);	
	gpio_init(GPIO_PIN(PORT_C, 9), GPIO_OUT);

  while(state==1)
  {
	xtimer_usleep 	(500000);
  gpio_toggle(GPIO_PIN(PORT_C, 9));
  }

  return 0;
}
