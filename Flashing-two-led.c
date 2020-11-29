* Flashing two LEDs connected to relay contacts.
* Relays are connected to port lines P0.9 and P0.10
**************************************************************************/
#include &quot;includes.h&quot;
#include &quot;lpc214x.h&quot;
#define TASK_STK_SIZE 255 // Size of each task&#39;s stacks (# of WORDs)
#define TASK_START_ID 0 // Application tasks IDs
#define TASK_1_ID 1
#define TASK_2_ID 2
#define TASK_START_PRIO 0 // Application tasks priorities
#define TASK_1_PRIO 1
#define TASK_2_PRIO 2
OS_STK TaskStartStk[TASK_STK_SIZE]; // Startup task stack
OS_STK Task1Stk[TASK_STK_SIZE]; // Task 1 task stack
OS_STK Task2Stk[TASK_STK_SIZE]; // Task 2 task stack
static void TaskStartCreateTasks (void);
void Task1 (void *pdata);
void Task2 (void *pdata);
void TaskStart (void *pdata)
{
pdata = pdata; // Prevent compiler warning
rIODIR0 = 0X40000400; // Set P0.30 and P0.10 lines as
ouput lines
rIOSET0 = 0X00000400;
TaskStartCreateTasks(); // Create all other tasks
while(1)
{

OSTimeDlyHMSM(0, 0, 1, 0); // Wait one second

}
}
static void TaskStartCreateTasks (void)
{
OSTaskCreateExt(Task1, // Create Task 1
(void *)0,
&amp;Task1Stk[TASK_STK_SIZE - 1],
TASK_1_PRIO,
TASK_1_ID,
&amp;Task1Stk[0],
TASK_STK_SIZE,
(void *)0,
OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);
OSTaskCreateExt(Task2, // Create Task 2
(void *)0,
&amp;Task2Stk[TASK_STK_SIZE - 1],
TASK_2_PRIO,
TASK_2_ID,
&amp;Task2Stk[0],

TASK_STK_SIZE,
(void *)0,
OS_TASK_OPT_STK_CHK | OS_TASK_OPT_STK_CLR);
}
/**************************************************************************
* Task 1 : Switches On/Off Relay 2
**************************************************************************/
void Task1 (void *pdata)
{
long a;
pdata = pdata;
while(1)
{

a = rIOPIN0; // Read relay status
if(a &amp; 0x00000400 )
{
rIOCLR0 = 0X00000400; // Switch Off relay 2
}
else
{
rIOSET0 = 0X00000400; // Switch off relay 2
}
OSTimeDlyHMSM(0, 0, 1, 0); // Wait one second
}
}

/**************************************************************************
* Task 2 : Switches On/Off Relay 1
**************************************************************************/
void Task2 (void *pdata )
{
long a;
pdata = pdata;
while(1)
{

a = rIOPIN0; // Read relay status
if(a &amp; 0x40000000 )
{
rIOCLR0 = 0x40000000; // Switch Off relay 1
}
else
{
rIOSET0 = 0x40000000; // Switch On relay 1
}

OSTimeDlyHMSM(0, 0, 1, 0); // Wait two seconds
}
}
/**************************************************************************

* Main Function
**************************************************************************/
void C_vMain(void)
{
OS_STK *ptos;
OS_STK *pbos;
INT32U size;
vInitHaltHandlers(); // Initialize Handlers
pISR_IRQ = (U32)UCOS_IRQHandler;
OSInit(); // Initialize uC/OS-II
ptos = &amp;TaskStartStk[TASK_STK_SIZE - 1];
pbos = &amp;TaskStartStk[0];
size = TASK_STK_SIZE;
OSTaskCreateExt(TaskStart,
(void *)0,


ptos,
TASK_START_PRIO,
TASK_START_ID,
pbos,
size,
(voi *)),
OS_TASK_OPT_STK_CHK_|OS_TASK_OPT_STK_CLR);
FRMWRK_vStartTicker(OS_TICKS_PER_SEC);
OSStart();
}
void __gccmain()
{
}