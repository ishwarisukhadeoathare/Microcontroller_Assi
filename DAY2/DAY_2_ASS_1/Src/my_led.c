/*
 * my_led.c
 *
 *  Created on: 16-Sept-2026
 *      Author: pranav
 */

#include"my_led.h"

void led_init()
{
	RCC->AHB1ENR |= BV(3);

	GPIOD->MODER |= (BV(24) | BV(26) | BV(28) | BV(30));
	GPIOD->MODER &= ~(BV(25) | BV(27) | BV(29) | BV(31));

	GPIOD->OTYPER &= ~(BV(12) | BV(13) | BV(14) | BV(15));
	GPIOD->OSPEEDR &= ~(BV(24) | BV(25) | BV(26) | BV(27) | BV(28) | BV(29) | BV(30) | BV(31));
	GPIOD->PUPDR &= ~(BV(24) | BV(25) | BV(26) | BV(27) | BV(28) | BV(29) | BV(30) | BV(31));
}

void led_12()
{
	GPIOD->ODR |= (BV(12));
	DelayMs(1000);
	GPIOD->ODR &= ~(BV(12));
}

void led_13()
{
	GPIOD->ODR |= (BV(13));
	DelayMs(1000);
	GPIOD->ODR &= ~(BV(13));
}

void led_14()
{
	GPIOD->ODR |= (BV(14));
	DelayMs(1000);
	GPIOD->ODR &= ~(BV(14));
}

void led_15()
{
	GPIOD->ODR |= (BV(15));
	DelayMs(1000);
	GPIOD->ODR &= ~(BV(15));
}
