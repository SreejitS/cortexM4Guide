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

#define MAX_TASKS		4

#define SIZE_TASK_STACK 		1024U
#define SIZE_SCHEDULER_STACK	1024U

#define SRAM_START				0x20000000U
#define SRAM_SIZE				( (96) * (1024))
#define SRAM_END				( (SRAM_START) + (SRAM_SIZE) )

#define T1_STACK_START			(SRAM_END)
#define T2_STACK_START			( (SRAM_END) - (1 * SIZE_TASK_STACK) )
#define T3_STACK_START			( (SRAM_END) - (2 * SIZE_TASK_STACK) )
#define T4_STACK_START			( (SRAM_END) - (3 * SIZE_TASK_STACK) )
#define SCHED_STACK_START		( (SRAM_END) - (4 * SIZE_TASK_STACK) )

#define TICK_HZ					1000U

#define CLOCK					4000000U
#define SYSTICK_TIM_CLK			CLOCK

#define DUMMY_XPSPR 		(1U<<24)

#endif /* MAIN_H_ */
