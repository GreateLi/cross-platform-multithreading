 
#include "my_thread.h"
#include "threadTest.h"
 
my_thread::my_thread(void* arg){
	object = arg;
}

my_thread::~my_thread()
{
}

void my_thread::run()
{
	int nCount = 0;
	while (!IsBreak())
	{
		((threadTest*)object)->dealwith_thing(this);
		((threadTest*)object)->dealwith_thingTT(this);

	} 
}