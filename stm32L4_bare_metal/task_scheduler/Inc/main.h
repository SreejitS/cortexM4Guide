/*
 * main.h
 *
 *  Created on: May 18, 2020
 *      Author: sreej
 */

#ifndef MAIN_H_
#define MAIN_H_

//stack memory defines
/*
 *	SRAM :-
 *
 * -----------------------------------------------------------------------
 * |							|  SCED	 |	T4	 |	T3	 |	T2	 |	T1	 |
 * |							| stack	 | stack | stack | stack | stack |
 * |							|  1KB	 |	1KB	 |	1KB	 |	1KB	 |	1KB	 |
 * |							|		 |		 |		 |		 |		 |
 * -----------------------------------------------------------------------
 * 0x20000000															0x20018000 (96KB of SRAM)
 *
 *
 * */

#define MAX_TASKS		5 //4 user task + 1 idle task

#define SIZE_TASK_STACK 		1024U
#define SIZE_SCHEDULER_STACK	1024U

#define SRAM_START				0x20000000U
#define SRAM_SIZE				( (96) * (1024))
#define SRAM_END				( (SRAM_START) + (SRAM_SIZE) )

#define T1_STACK_START			(SRAM_END)
#define T2_STACK_START			( (SRAM_END) - (1 * SIZE_TASK_STACK) )
#define T3_STACK_START			( (SRAM_END) - (2 * SIZE_TASK_STACK) )
#define T4_STACK_START			( (SRAM_END) - (3 * SIZE_TASK_STACK) )
#define IDLE_STACK_START		( (SRAM_END) - (4 * SIZE_TASK_STACK) )
#define SCHED_STACK_START		( (SRAM_END) - (5 * SIZE_TASK_STACK) )

#define TICK_HZ					1000U

#define CLOCK					4000000U
#define SYSTICK_TIM_CLK			CLOCK

#define DUMMY_XPSPR 		(1U<<24)

#define TASK_READY_STATE 		0x00
#define TASK_BLOCK_STATE 		0xFF

#define DELAY_COUNT_1MS 		 1250U
#define DELAY_COUNT_1S  		(1000U * DELAY_COUNT_1MS)
#define DELAY_COUNT_500MS  		(500U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_250MS 		(250U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_125MS 		(125U  * DELAY_COUNT_1MS)

#define INTERRUPT_DISABLE() do{__asm volatile("MOV R0,#0x01");__asm volatile("MSR PRIMASK,R0");}while(0)
#define INTERRUPT_ENABLE() do{__asm volatile("MOV R0,#0x00");__asm volatile("MSR PRIMASK,R0");}while(0)

#endif /* MAIN_H_ */
