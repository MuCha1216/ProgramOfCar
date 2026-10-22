#include "stm32f10x.h"                  // Device header
#include "freertos.h"
#include "IRTracking.h"
#include "Motor.h"
#include "task.h"
#include "Series.h"
#include "Delay.h"
#include "Infrared.h"
#include "Key.h"
#include "LEDShow.h"

////定义任务句柄
//TaskHandle_t  Taskone_Handle = NULL;
//TaskHandle_t  Tasktwo_Handle = NULL;
//TaskHandle_t  Taskthree_Handle = NULL;
//TaskHandle_t  StarTask_Handle = NULL;

//void Taskone(void *pvParameters)
//{
//	while(1)
//	{
//		if(LeftIRTracking_Get() == 0 && RightIRTracking_Get() == 0)
//		{
//			Motor_Run(70,1000);
//		}
//		else if(LeftIRTracking_Get() == 1 && RightIRTracking_Get() == 0)
//		{
//			Motor_Right(50,500);
//		}
//		else if(LeftIRTracking_Get() == 0 && RightIRTracking_Get() == 1)
//		{
//			Motor_Left(50,500);
//		}
//		else if(LeftIRTracking_Get() == 1 && RightIRTracking_Get() == 1)
//		{
//			Motor_Stop();
//		}
//	}
//}

//void Tasktwo(void *pvParameters)
//{
//	while(1)
//	{
//		if(LeftIRObstacle_Get() == 1 && RightIRObstacle_Get() == 1)
//		{
//			Motor_Run(70,1000);
//		}
//		else if(LeftIRObstacle_Get() == 1 && RightIRObstacle_Get() == 0)
//		{
//			Motor_Left(50,500);
//		}
//		else if(LeftIRObstacle_Get() == 0 && RightIRObstacle_Get() == 1)
//		{
//			Motor_Right(50,500);
//		}
//		else if(LeftIRObstacle_Get() == 0 && RightIRObstacle_Get() == 0)
//		{
//			Motor_Stop();
//		}
//	}
//}

//void Taskthree(void *pvParameters)
//{
//	uint8_t buf[2];
//	uint8_t data_code=0; 
//	while(1)
//	{
//		if(ReceiveFlag == 1)
//		{
//			ReceiveFlag = 0; //清零
//			data_code=ReceiveData>>8;
//			ReceiveData = 0; //接收码清零
//			
//			buf[0] = data_code/16;
//			buf[1] = data_code%16;
//			
//		}
//    if(buf[0] == 11 && buf[1] == 1)
//		{
//			Motor_Left(70,2000);  // 前进2s
//		}
//		else if(buf[0] == 13 && buf[1] == 4)
//		{
//			Motor_Back(70,2000); // 后退2s
//		}
//		else if(buf[0] == 9 && buf[1] == 1)
//		{
//			Motor_Left(70,2000); //左转
//		}
//		else if(buf[0] == 14 && buf[1] == 1)
//		{
//			Motor_Right(70,2000); // 右转
//		}
//		else if(buf[0] == 8 && buf[1] == 1)
//		{
//			Motor_Stop(); // 停止
//		}
//		else
//		{
//			Motor_Stop(); // 停止
//		}
//	}
//}


////启动任务，负责专门创建其他任务
//void StarTask(void *pvParameters)
//{
//	taskENTER_CRITICAL();//进入临界区，防止在创建任务的过程中被打断
//	
////	xTaskCreate(Taskone,"Taskone",512,NULL,1,&Taskone_Handle);
////	xTaskCreate(Tasktwo,"Tasktwo",512,NULL,2,&Tasktwo_Handle);
//	xTaskCreate(Taskthree,"Taskthree",512,NULL,3,&Taskthree_Handle);
//	
//	taskEXIT_CRITICAL();//退出临界区
//	
//	vTaskDelete(StarTask_Handle);//启动任务已完成，删除自身以释放内存

void Car_Traction(void)
{
		if(LeftIRTracking_Get() == 0 && RightIRTracking_Get() == 0)
		{
			Motor_Run(70,1000);
		}
		else if(LeftIRTracking_Get() == 1 && RightIRTracking_Get() == 0)
		{
			Motor_Right(50,500);
		}
		else if(LeftIRTracking_Get() == 0 && RightIRTracking_Get() == 1)
		{
			Motor_Left(50,500);
		}
		else if(LeftIRTracking_Get() == 1 && RightIRTracking_Get() == 1)
		{
			Motor_Stop();
		}
}

void Car_Avoidance(void)
{
	if(LeftIRObstacle_Get() == 1 && RightIRObstacle_Get() == 1)
		{
			Motor_Run(70,1000);
		}
		else if(LeftIRObstacle_Get() == 1 && RightIRObstacle_Get() == 0)
		{
			Motor_Left(50,500);
		}
		else if(LeftIRObstacle_Get() == 0 && RightIRObstacle_Get() == 1)
		{
			Motor_Right(50,500);
		}
		else if(LeftIRObstacle_Get() == 0 && RightIRObstacle_Get() == 0)
		{
			Motor_Back(70,1000);
			Motor_Left(50,500);
		}
}

void ControlCar_Ircontrol() // 定义红外遥控器控制
{
  uint8_t buf[2];
	uint8_t data_code=0; 
	
	if(IR_Receiveflag == 1) //如果红外接收到
		{
			IR_Receiveflag = 0; //清零
			printf("红外接收码 %0.8X\r\n",IR_Receivecode);	//打印
			data_code=IR_Receivecode>>8;
			IR_Receivecode = 0; //接收码清零
			
			buf[0] = data_code/16;
			buf[1] = data_code%16;
			
		  printf("buf[0]:%d\r\n",buf[0]);
		  printf("buf[1]:%d\r\n",buf[1]);
		}
    if(buf[0] == 11 && buf[1] == 1)
		{
			Motor_Run(70,2000);  // 前进2s
		}
		else if(buf[0] == 13 && buf[1] == 4)
		{
			Motor_Back(70,2000); // 后退2s
		}
		else if(buf[0] == 9 && buf[1] == 1)
		{
			Motor_Left(70,2000); //左转
		}
		else if(buf[0] == 14 && buf[1] == 1)
		{
			Motor_Right(70,2000); // 右转
		}
		else if(buf[0] == 8 && buf[1] == 1)
		{
			Motor_Stop(); // 停止
		}
		else
		{
			Motor_Stop(); // 停止
		}
}
		
void Irscan(void)
{
	uint8_t Tim=0,Ok=0,Data,Num=0;
	
	while(1)
	{
	  if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)==1)
		{
			 Tim=IRremote_Counttime();//获得此次高电平时间

			 if(Tim>=250) break;//不是有用的信号

			 if(Tim>=200 && Tim<250)
			 {
			 	Ok=1;//收到起始信号
			 }
			 else if(Tim>=60 && Tim<90)
			 {
			 	Data=1;//收到数据 1
			 }
			 else if(Tim>=10 && Tim<50)
			 {
			 	Data=0;//收到数据 0
			 }

			 if(Ok==1)
			 {
			 	IR_Receivecode<<=1;
				IR_Receivecode+=Data;

				if(Num>=32)
				{
					IR_Receiveflag=1;
				    break;
				}
			 }
			 Num++;
		}
		ControlCar_Ircontrol();
	}
	EXTI_ClearITPendingBit(EXTI_Line8);	
}

unsigned  char Temp = 1;

int main(void)
{
	Motor_Init();
	IRTracking_Init();
	IRremote_Init();
	Serial_Init();	
	Key_Init();
	LEDShow_Init();
//	xTaskCreate(StarTask,"StarTask",128,NULL,1,&StarTask_Handle);//创建启动任务
//	vTaskStartScheduler();//启动freertos调度器，程序执行到这里将不再返回

	while(1)
	{
		if(Key_GetNum()==1)
		{
			GPIO_WriteBit(GPIOA,GPIO_Pin_11, Bit_SET);
			Delay_ms(20);
			Temp ++;
			GPIO_WriteBit(GPIOA,GPIO_Pin_11, Bit_RESET);
		}
		if(Temp>3)
		{
			Temp=1;
		}
		switch(Temp)
		{
			case 1:Digital_Display(1);Car_Traction();EXTI_DeInit();break;
			case 2:Digital_Display(2);Car_Avoidance();break;
			case 3:Digital_Display(3);Irscan();break;
		}
	}

}
