#ifndef LOGGER_H
#define LOGGER_H

#define DEBUG   0
#define INFO    1
#define WARNING 2
#define ERROR   3



void logger_init(char* filename);

void logger_log(int level, const char* format, ...);

void logger_close();

#endif
