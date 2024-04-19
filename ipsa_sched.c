#include <stdio.h>
#include <pthread.h>

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"

/* Local includes. dans posix_gcc */
#include "console.h"

/* Priorities at which the tasks are created. */
#define task1priority					  ( tskIDLE_PRIORITY + 4 ) 
#define task2priority					  ( tskIDLE_PRIORITY + 3 )
#define task3priority					  ( tskIDLE_PRIORITY + 2 )
#define task4priority					  ( tskIDLE_PRIORITY + 1 )

/* The rate at which data is sent to the queue.  The times are converted from
 * milliseconds to ticks using the pdMS_TO_TICKS() macro. */
#define mainTASK_SEND_FREQUENCY_MS         pdMS_TO_TICKS( 200UL )
#define mainTIMER_SEND_FREQUENCY_MS        pdMS_TO_TICKS( 2000UL )
						
/* The values sent to the queue receive task from the queue send task and the
 * queue send software timer respectively. */
#define mainVALUE_SENT_FROM_TASK           ( 100UL )
#define mainVALUE_SENT_FROM_TIMER          ( 200UL )
/*
 * The tasks as described in the comments at the top of this file.
 */

static void task1(void * pvParameters);
static void task2(void * pvParameters);
static void task3(void * pvParameters);
static void task4(void * pvParameters);


/* A software timer that is started from the tick hook. */
//static TimerHandle_t xTimer = NULL;
void ipsa_sched(void)
{
xTaskCreate( task1, "Rx", configMINIMAL_STACK_SIZE, NULL, task1priority, NULL );                          
xTaskCreate( task2, "TX", configMINIMAL_STACK_SIZE, NULL, task2priority, NULL );
xTaskCreate( task3, "FX", configMINIMAL_STACK_SIZE, NULL, task3priority, NULL );
xTaskCreate( task4, "ZX", configMINIMAL_STACK_SIZE, NULL, task4priority, NULL );

/* Create the software timer, but don't start it yet. */
//xTimer = xTimerCreate( "Timer",xTimerPeriod,pdTRUE,NULL ); 

/*if( xTimer != NULL )
{
	xTimerStart( xTimer, 0 );
};*/

/* Start the tasks and timer running. */
vTaskStartScheduler();


/* If all is well, the scheduler will now be running, and the following
 * line will never be reached.  If the following line does execute, then
 * there was insufficient FreeRTOS heap memory available for the idle and/or
 * timer tasks	to be created.  See the memory management section on the
 * FreeRTOS web site for more details. */
for( ; ; )
{
}
};



static void task1(void * pvParameters){
	TickType_t xNextWakeTime;
    const TickType_t xBlockTime = mainTASK_SEND_FREQUENCY_MS;
    const uint32_t ulValueToSend = mainVALUE_SENT_FROM_TASK;
	xNextWakeTime = xTaskGetTickCount();
	for( ; ; )
    {
	console_print("Everything is working \n");
	vTaskDelayUntil( &xNextWakeTime, xBlockTime );
	}
};

static void task2(void * pvParameters){
	TickType_t xNextWakeTime;
    const TickType_t xBlockTime = mainTASK_SEND_FREQUENCY_MS;
    const uint32_t ulValueToSend = mainVALUE_SENT_FROM_TASK;
	xNextWakeTime = xTaskGetTickCount();
	for( ; ; )
    {
	int F=100;
	float C;
	C=(F-32)/1.8;
	console_print("%f \n",C);
	vTaskDelayUntil( &xNextWakeTime, xBlockTime );
	}
	//( void ) pvParameters;
	
};

static void task3(void * pvParameters){
	TickType_t xNextWakeTime;
    const TickType_t xBlockTime = mainTASK_SEND_FREQUENCY_MS;
    const uint32_t ulValueToSend = mainVALUE_SENT_FROM_TASK;
	xNextWakeTime = xTaskGetTickCount();
	for( ; ; )
    {
	long int a=20355432453,b=25432543;
	long int result;
	result=a*b;
	console_print("%ld \n",result);
	vTaskDelayUntil( &xNextWakeTime, xBlockTime );
	}
};

static void task4(void * pvParameters){
	( void ) pvParameters;
	int tab[50]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
	int low = 0;
	int high = 49;
	int key = 2;
	int mid = (low+high)/2;
	
	while(tab[mid]!=key){
		if(tab[mid]>key){
			high = mid-1;
			mid = (low+high)/2;   
		}
		else if(tab[mid]<key){
			low = mid+1;
			mid = (low+high)/2;
		}
		else{
			console_print("Le chiffre n'est pas dans le tableau \n");
		}
	}
	console_print("le chiffre %d est à l'index : %d \n",key, mid);
};