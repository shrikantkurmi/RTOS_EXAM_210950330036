#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>

 QueueHandle_t task_queue ;
 void Task1 (void *pv)
 {
     while(1)
     {
         printf("task1  priority %d :\n",uxTaskPriorityGet(NULL));
         vTaskDelay(1000 / portTICK_PERIOD_MS);
     }
 }
 void Task2 (void *pv)
 {
     while(1)
     {
         printf("task2  priority %d :\n",uxTaskPriorityGet(NULL));
         vTaskDelay(2000 / portTICK_PERIOD_MS);
     }
 }
 void Task3 (void *pv)
 {
     while(1)
     {
         printf("task3  priority %d :\n",uxTaskPriorityGet(NULL));
         vTaskDelay(5000 / portTICK_PERIOD_MS);
     }
 }
 void Task4( void *pv)
 {
     int task_data = 0;
     while(1)
     {
         task_data ++;
         printf("task4 : task_data %d\n ",task_data);
         xQueueSend(task_queue,&task_data,portMAX_DELAY);
         vTaskDelay(4000 / portTICK_PERIOD_MS);
     }
 }


 void Task5( void *pv)
 {
     int task5_data = 0;
     while(1)
     {
         xQueueReceive(task_queue,&task5_data,portMAX_DELAY);

         printf("task5 recieved data  : task5_data %d\n ",task5_data);
        
         vTaskDelay(4000 / portTICK_PERIOD_MS);
     }
 }





void  app_main ()
{
 BaseType_t result1,result2,result3,result4,result5;
    task_queue = xQueueCreate(10,sizeof(int));
   result1 = xTaskCreate(Task1,"task1",2048,NULL,5,NULL);
   result2 = xTaskCreate(Task2,"task2",2048,NULL,6,NULL);
   result3 = xTaskCreate(Task3,"task3",2048,NULL,7,NULL);
   result4 = xTaskCreate(Task4,"task4",2048,NULL,8,NULL);
   result5 = xTaskCreate(Task5,"task5",2048,NULL,9,NULL);
   / if(result1 = pdPASS)
    {
        printf("task1 is created \n");
    }
    if(result2 = pdPASS)
    {
        printf("task2 is created \n");
    }
    if(result3 = pdPASS)
    {
        printf("task3 is created \n");
    }
    if(result4 = pdPASS)
    {
        printf("task4 is created \n");
    }
    if(result5 = pdPASS)
    {
        printf("task5 is created \n");
    } 

}
