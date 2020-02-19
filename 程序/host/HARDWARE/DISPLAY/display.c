#include "display.h"

//--定义全局变量--//
unsigned char code DIG_PLACE[8] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//位选控制   查表的方法控制
unsigned char code DIG_CODE[17] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
									0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
									//0、1、2、3、4、5、6、7、8、9、A、b、C、d、E、F的显示码 共阴极接法
unsigned char DisplayData[8]={0};	//用来存放要显示的8位数的值

/*******************************************************************************
* 函 数 名         : DigDisplay
* 函数功能		   : 使用数码管显示
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/

void DigDisplay()
{
	unsigned char i;
	unsigned int j;
	
	for(i=0; i<8; i++)
	{
		DisplayData[i] = DIG_CODE[i];
		GPIO_PLACE = DIG_PLACE[i];	 //发送位选
		GPIO_DIG = DisplayData[i];     //发送段码
		j = 10;						 //扫描间隔时间设定
		while(j--);	
		GPIO_DIG = 0x00;//消隐
	}
}