String inString = "";
int inChar = '0';

// the setup function runs once when you press reset or power the board
void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  // send an intro:
  Serial.println("\n\nEnter LED on duration:");
  Serial.println();
}

// the loop function runs over and over again forever
void loop()
{
  // Read serial input:
  while (Serial.available() > 0) {
    int duration = readInt();
    // check endline
    if (inChar == '\n') {
      Serial.print("Duration:");
      Serial.println(duration);
      // turn on LED as input duration
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(duration);                       
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      // reset values
      inString = "";
      inChar = '0';
    }
  }
}

int readInt()
{
  inChar = Serial.read();
  if (isDigit(inChar)) {
    // convert the incoming byte to a char
    // and add it to the string:
    inString += (char)inChar;
  }
  
  return inString.toInt();
}

