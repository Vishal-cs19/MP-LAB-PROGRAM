#include<stdio.h>
#include<reg51.h>

unsigned char xdataCommandWord _at_ 0xe803;
unsigned char xdataPortA _at_ 0xe800;
unsigned char xdataPortB _at_ 0xe801;
unsigned char xdataPresentFloor,RequestedFloor,Step = 0xf0;
unsigned long xdataCount,i;

Delay()
{
for(Count = 0; Count<= 4500; Count++);
}

Reset()

Page 1
{
Step = Step &amp; 0x0f;
PortA = Step;
Step = Step | 0xf0;
PortA = Step;
}
GoUp()
{
switch(RequestedFloor)
{
case 0x0d: while(Step &lt; 0xf3)
{
Step++;
PortA = Step;
Delay();
}
Reset();
break;

case 0x0b: while(Step < 0xf6)
{
Step++;
PortA = Step;
Delay();
}
Reset();
break;

case 0x07: while(Step < 0xf9)
{

Page 1

Step++;
PortA = Step;
Delay();
}
Reset();
break;

}
}

GoDown()
{
switch(RequestedFloor)
{
case 0x0d: while(Step > 0xf3)
{
Step--;
PortA = Step;
Delay();
}
Reset();
break;

case 0x0b: while(Step > 0xf6)
{
Step--;
PortA = Step;
Delay();
}
Reset();
break;

Page 1

case 0x0e: while(Step > 0xf0)
{
Step--;
PortA = Step;
Delay();
}
Reset();
break;

}
}

void main()
{
CommandWord = 0x82;
PortA = 0xf0;
PresentFloor = 0x0e;
while(1){
RequestedFloor = PortB;
RequestedFloor = RequestedFloor&amp; 0x0f;

if(RequestedFloor != 0x0f &amp;&amp;RequestedFloor != PresentFloor){
if(RequestedFloor&lt;PresentFloor)
GoUp();
else
GoDown();
PresentFloor = RequestedFloor;
}
RequestedFloor = PortB;
}
