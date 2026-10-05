/*
 * my_switch.c
 *
 *  Created on: 16-Sept-2026
 *      Author: pranav
 */
#include"my_switch.h"

void switch_init()
{
	RCC->AHB1ENR |= (BV(0));

	GPIOA->MODER &= ~(BV(1) | BV(0));
	GPIOA->OSPEEDR &= ~(BV(1) | BV(0));
	GPIOA->PUPDR &= ~(BV(1) | BV(0));
}

int switch_press()
{
	if(BV(0) & GPIOA->IDR)
	{
		while(BV(0) & GPIOA->IDR);
		return 1;
	}
	return 0;
}
