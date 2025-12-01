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

  // Wait 1 minute
  //delay(60000);
  delay(10000);

  // Move back to original position
  for (int pos = endPos; pos >= startPos; pos--) {
    lock.write(pos);
    delay(15);
  }
}

// void servoFunction(int lockPos) {
//   // put your main code here, to run repeatedly:
//   for (lockPos = 0; lockPos <= 90; lockPos += 1) { // go from 0-90 degrees 
//     // move in steps of 5 degrees
//     lock.write(lockPos);
//     delay(5); // wait 15ms for servo to get to position
//   }
//   delay(int(6e4)); // 60 second delay
//   for (lockPos = 80; lockPos >= 0; lockPos -= 1) { // go from 80-0 degrees on Lock Servo
//     lock.write(lockPos);
//     delay(5); // wait 15ms for servo to get to position
//   }
// }


