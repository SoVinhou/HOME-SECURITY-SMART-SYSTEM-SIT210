// DECOND PARTICLE ARGON DEVICE
int led = D6;
int buzzersensor = D5;

void setup() {
    pinMode(buzzersensor, OUTPUT);
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    
    //SUSBSCRIBE TO BUDDY SYSTEM
    //THIS SUBSCRIPTION WILL READ OUTPUT FROM THE FIRST PARTICLE ARGON DEVICES
    //THEN IT WILL PASS IN THE HANDLER PROCEDURE FOR THIS PROGRAM TO REACT ACCORDINGLY
    Particle.subscribe("Update:", myHandler);

}

//THIS METHOD WILL FLASH THE LED LIGHT AND BUZZ THE BUZZER
void myHandler(const char *eventName, const char *data)
{
  tone(D5, 450);
  delay(1000);
  noTone(D5);
  delay(1000);
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
  tone(D5, 450);
  delay(1000);
  noTone(D5);
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
  tone(D5, 450);
  delay(1000);
  noTone(D5);
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);

}
