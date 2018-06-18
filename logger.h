#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <stdbool.h>

// #define COLOR_INFO  "\033[1;37m"	
#define COLOR_WARN  "\033[1;33m"
#define COLOR_ERR   "\033[1;31m"
#define COLOR_RESET "\033[0m"

typedef struct Logger Logger;
struct Logger {
	const char* filename;
	bool filewrite, timerenabled;
	clock_t timer;
};

void startClock(Logger *logger)
{
	logger->timer = clock();
	logger->timerenabled = true;
}

// The REAL logger
int logList(Logger logger, const char* msg, va_list list)
{
	double time = 0.0;
	if(logger.timerenabled)
	{
		clock_t right_now = clock();
		time = ((double)(right_now - logger.timer)) / CLOCKS_PER_SEC;
		printf("%.5fs | ", time);
	}
	vprintf(msg, list);
	printf("\n");
	if(logger.filewrite)
	{
		FILE *file = fopen(logger.filename, "a");
		if(file == NULL)
		{
			fprintf(stderr, "Could not initialize file %s\n", logger.filename);
			return -1;
		}
		if(logger.timerenabled)
			fprintf(file, "%.5fs | ", time);
		vfprintf(file, msg, list);
		fprintf(file, "\n");
		fclose(file);
	}
	return 0;
}

// logs in white text
int log(Logger logger, const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	int rv = logList(logger, msg, args); 
	va_end(args);
	return rv;
}

// sets filename for later use
void setFile(Logger *logger, const char* filename) 
{
	FILE *file = fopen(filename, "w");
	fclose(file);
	logger->filewrite = true;
	logger->filename = filename; 
}

// logs in yellow text
int logWarn(Logger logger, const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	printf("%s", COLOR_WARN);
	int rv = logList(logger, msg, args);
	printf("%s", COLOR_RESET);
	va_end(args);
	return rv;
}

// logs in red text
int logErr(Logger logger, const char* msg, ...)
{
	va_list args;
	va_start(args, msg);
	printf("%s", COLOR_ERR);
	int rv = logList(logger, msg, args);
	printf("%s", COLOR_RESET);
	va_end(args);
	return rv;
}

#ifdef __cplusplus
}
#endif

