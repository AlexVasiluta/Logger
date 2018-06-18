#include "logger.h"

int main()
{
    Logger logger;
	//startClock(&logger);
    setFile(&logger, "testerino.log");
	for(int i = 0; i <= 99999999; i++){}   
	log(logger, "This is an info message!");
    for(int i = 0; i <= 9999999; i++){}
    logWarn(logger, "This is a warning message!");
    for(int i = 0; i <= 999999; i++){}
    logErr(logger, "This is an error message!");
    return 0;
}
