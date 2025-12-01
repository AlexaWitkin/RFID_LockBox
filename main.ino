#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

// ======== RFID ======== //
#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 rfid(SS_PIN, RST_PIN);  // Create MFRC522 instance
String uid = ""; // Init string that will store new NUID 

const String validID = "201831131";


// ======== SERVO ======== //
Servo lock; // create servo object for lock 
//int lockPos = 0; // variable to store position of Lock Servo

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	SPI.begin();			// Init SPI bus
	rfid.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
  Serial.println(F("This code scan the MIFARE Classsic NUID."));

  lock.attach(6); // lock is in pin D10
}

void loop() {
	//uid = "";
	//Serial.println(getUID());
	if (getUID() == validID) {
		Serial.println("Servo running");
		servoFunction();
	}
}
//201831131