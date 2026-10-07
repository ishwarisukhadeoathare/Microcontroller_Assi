/*
 * my_led.c
 *
 *  Created on: 16-Sept-2026
 *      Author: ishwari
 */

#include"my_led.h"

void led_init()
{
	RCC->AHB1ENR |= BV(3);

	GPIOD->MODER |= (BV(24) | BV(26) | BV(28) | BV(30));
	GPIOD->MODER &= ~(BV(25) | BV(27) | BV(29) | BV(31));

	GPIOD->OTYPER |= (BV(12) | BV(13) | BV(14) | BV(15));

	GPIOD->OSPEEDR &= ~(BV(24) | BV(25) | BV(26) | BV(27) | BV(28) | BV(29) | BV(30) | BV(31));

	GPIOD->PUPDR &= ~(BV(25) | BV(27) | BV(29) | BV(31));
	GPIOD->PUPDR |= (BV(24) | BV(26) | BV(28) | BV(30));
}

void led_forward()
{
	GPIOD->ODR |= (BV(12));
	DelayMs(1000);

	GPIOD->ODR |= (BV(13));
	DelayMs(1000);

	GPIOD->ODR |= (BV(14));
	DelayMs(1000);

	GPIOD->ODR |= (BV(15));
	DelayMs(1000);
}

void led_backward()
{
	GPIOD->ODR &= ~(BV(15));
	DelayMs(1000);

	GPIOD->ODR &= ~(BV(14));
	DelayMs(1000);

	GPIOD->ODR &= ~(BV(13));
	DelayMs(1000);

	GPIOD->ODR &= ~(BV(12));
	DelayMs(1000);
}
