#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int 
uchar code table1[]=" Yanhonggang ";
uchar code table2[]=" 208120729 " ;
sbit RS=P1^0;
sbit RW=P1^1;
sbit E=P1^2;
uchar i;	
void delay(uint ms)
{
uint n;
for(;ms>0;ms--)
for(n=124;n>0;n--);
}
void write_Instruction(uchar Instruction)
{
RS=0;
RW=0;
E=0;
P0=Instruction;
delay(5);
E=1;
delay(5);
E=0;
}
void write_Data(uchar Data)
{
RS=1;
RW=0;
E=0;
P0=Data;
delay(5);
E=1;
delay(5);
E=0;
}
void Init()
{
EA=1;
EX0=1;
EX1=1;
delay(15);
write_Instruction(0x38);
delay(5);
write_Instruction(0x38);
delay(5);
write_Instruction(0x38);
delay(5);
write_Instruction(0x38);
write_Instruction(0x38);
write_Instruction(0x08);
write_Instruction(0x01);
write_Instruction(0x06);
write_Instruction(0x0c);
}

void main()
{


Init();
while(1);




 
} 	 
 void  lcd() interrupt  0		  //外部中断  0
{

  
 write_Instruction(0x01);


write_Instruction(0x80+0x40);
for(i=0;i<11;i++)
 {
	write_Data(table2[i]);
	
  }
 

}
void lcd1() interrupt 2		  //外部中断  1
{

write_Instruction(0x01);
write_Instruction(0x80);

for(i=0;i<13;i++)
{
write_Data(table1[i]);

}




}