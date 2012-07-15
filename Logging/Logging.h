#ifndef LOGGING_H
#define LOGGING_H

#include <inttypes.h>
#include <stdarg.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "defines.h"

#if LOGLEVEL > 0
extern "C"
{
#include <avr/io.h>
}

class Logging
{
  private:
    int _level;
    long _baud;
  public:
    Logging(){};
    
    void begin();
    void begin(int level, long baud);

    void setLogLevel(int level);

#if LOGLEVEL > 0
    void Error(char* msg, ...);
#endif

#if LOGLEVEL > 1
    void Info(char* msg, ...);
#endif

#if LOGLEVEL > 2
    void Debug(char* msg, ...);
#endif

#if LOGLEVEL > 3
    void Verbose(char* msg, ...);
#endif

  private:

#if LOGLEVEL > 0
    void print(const char *format, va_list args);
#endif
};

extern Logging Log;
#endif
#endif
