#include "logger.hpp"

int main()
{
    Logger log;
    log.setFile("testerino.log");
    for(int i = 0; i <= 999999; i++){}
    log.logInfo("This is an info message!");
    for(int i = 0; i <= 999999; i++){}
    log.logWarning("This is a warning message!");
    for(int i = 0; i <= 999999; i++){}
    log.logError("This is an error message!");
    return 0;
}