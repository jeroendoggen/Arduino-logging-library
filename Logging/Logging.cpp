#include "Logging.h"

#if LOGLEVEL > 0

/// Begin with default loglevel and baudrate. (LOG_LEVEL_DEBUG, 115200L)
void Logging::begin()
{
  begin(LOG_LEVEL_DEBUG, 115200L);
}

/// Begin with user selected loglevel and baudrate.
void Logging::begin(int level, long baud)
{
  _level = constrain(level,LOG_LEVEL_NOOUTPUT,LOG_LEVEL_VERBOSE);
  _baud = baud;
  Serial.begin(_baud);
}

/// Set the loglevel at runtime.
void Logging::setLogLevel(int level)
{
  _level = constrain(level,LOG_LEVEL_NOOUTPUT,LOGLEVEL);
  if(level > LOGLEVEL)
  {
    Error("Loglevel %d not possible", level);     // requested level
    Error("Selected level %d instead", _level);   // selected/applied level
  }
}

/// Output an error message. Output message contains ERROR: followed by original msg. Error messages are printed out, at every loglevel except 0
void Logging::Error(char* msg, ...)
{
  if (LOG_LEVEL_ERRORS <= _level)
  {
    Serial.print("Error: ");
    va_list args;
    va_start(args, msg);
    print(msg,args);
  }
}

/// Output an info message.
#if LOGLEVEL > 1
void Logging::Info(char* msg, ...)
{
  if (LOG_LEVEL_INFOS <= _level)
  {
    Serial.print("Info: ");
    va_list args;
    va_start(args, msg);
    print(msg,args);
  }
}
#endif

/// Output a debug message.
#if LOGLEVEL > 2
void Logging::Debug(char* msg, ...)
{
  if (LOG_LEVEL_DEBUG <= _level)
  {
    Serial.print("Debug: ");
    va_list args;
    va_start(args, msg);
    print(msg,args);
  }
}
#endif

/// Output a verbose message.
#if LOGLEVEL > 3
void Logging::Verbose(char* msg, ...)
{
  if (LOG_LEVEL_VERBOSE <= _level)
  {
    Serial.print("Verbose: ");
    va_list args;
    va_start(args, msg);
    print(msg,args);
  }
}
#endif

/// Helper function: does the actual printing.
void Logging::print(const char *format, va_list args)
{
// loop through format string
  for (; *format != 0; ++format)
  {
    if (*format == '%')
    {
      ++format;
      if (*format == '\0') break;
      if (*format == '%')
      {
        Serial.print(*format);
        continue;
      }
      if( *format == 's' )
      {
        register char *s = (char *)va_arg( args, int );
        Serial.print(s);
        continue;
      }
      if( *format == 'd' || *format == 'i')
      {
        Serial.print(va_arg( args, int ),DEC);
        continue;
      }
      if( *format == 'x' )
      {
        Serial.print(va_arg( args, int ),HEX);
        continue;
      }
      if( *format == 'X' )
      {
        Serial.print("0x");
        Serial.print(va_arg( args, int ),HEX);
        continue;
      }
      if( *format == 'b' )
      {
        Serial.print(va_arg( args, int ),BIN);
        continue;
      }
      if( *format == 'B' )
      {
        Serial.print("0b");
        Serial.print(va_arg( args, int ),BIN);
        continue;
      }
      if( *format == 'l' )
      {
        Serial.print(va_arg( args, long ),DEC);
        continue;
      }

      if( *format == 'c' )
      {
        Serial.print(va_arg( args, int ));
        continue;
      }
      if( *format == 't' )
      {
        if (va_arg( args, int ) == 1)
        {
          Serial.print("T");
        }
        else
        {
          Serial.print("F");
        }
        continue;
      }
      if( *format == 'T' )
      {
        if (va_arg( args, int ) == 1)
        {
          Serial.print("true");
        }
        else
        {
          Serial.print("false");
        }
        continue;
      }
    }
    Serial.print(*format);
  }
  Serial.println("");
}

Logging Log = Logging();
#endif
