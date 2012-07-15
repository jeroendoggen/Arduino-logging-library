#include <Logging.h>

void setup()
{
#if LOGLEVEL > 0
  Log.begin(LOGLEVEL, 115200L);
#endif
}

void loop()
{
#if LOGLEVEL >= LOG_LEVEL_ERRORS
  Log.Error("Error message");
#endif

#if LOGLEVEL >= LOG_LEVEL_INFOS
  Log.Info("Info message");
#endif

#if LOGLEVEL >= LOG_LEVEL_DEBUG
  Log.Debug("Debug message");
#endif

#if LOGLEVEL >= LOG_LEVEL_VERBOSE
  Log.Verbose("Verbose message");
#endif

  Log.setLogLevel(4);
  Serial.println("");

  delay(5000);
}
