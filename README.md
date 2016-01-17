# Arduino logging library

Easy to use logging library for the Arduino platform.

## Why?
Most people developing code for the Arduino add "Serial.println()" statements to their code while debugging.
Later on, this debugging code is removed or commented out.
This leaves you with ugly code with a lot of lines that are commented out or with some extra work when you want to debug the same code again later on.

## How?
This library provides an alternative debugging method, with different debugging levels to enable/disable several messages at the same time, without commenting out the code.
 * Log.Info("info message")
 * Log.Error("an error message");
 * Log.Debug("Debug message");
