// Alexa Witkin 
// Nov 16. 2025
// Servo for CMPE3815 - Lock

#include <Servo.h>

void servoFunction() {
  int startPos = lock.read();  // read current position (0–180)
  int endPos = startPos + 90;

  // Limit to max 180 degrees
  if (endPos > 180) endPos = 180;

  // Move to unlocked position
  for (int pos = startPos; pos <= endPos; pos++) {
    lock.write(pos);
    delay(15);
  }

  // Wait 10 seconds
  delay(10000);

  // Move back to original position
  for (int pos = endPos; pos >= startPos; pos--) {
    lock.write(pos);
    delay(15);
  }
}


