// FIRST PHOTON
// THESE DECLARATIONS SETS UP THE PINS FOR MOTION SENSOR
int inpPin = D2;  
int ledPin = D1;   
int PIRState = LOW;             
int val = 0;                    
int calibrateTime = 10000;      

bool calibrated() {
    return millis() - calibrateTime > 0;
}

void setLED( int state )
{
    digitalWrite(ledPin, state);
}

void setup()
{
    pinMode(inpPin, INPUT);   
    pinMode(ledPin, OUTPUT);
}

//THIS METHOD READ THE SENSOR INPUT
void Sensor() 
{
    val = digitalRead(inpPin);
}

//THIS METHOD WILL PUBLISH DATA ACCORDINGLY
void DataReport() {
    if (val == HIGH) 
    {
        if (PIRState == LOW)
        {
            Particle.publish("Update:", "Motion Detected"); //publish output to particle when MOTION is detected
            PIRState = HIGH;
            setLED(PIRState);
        }
    } 
    else 
    {
        if (PIRState == HIGH)
        {
            PIRState = LOW;
            setLED(PIRState);
        }
    }
}

void loop()
{
    //CHECK IF CALIBRATED
    if (calibrated())
    {
        Sensor();
        DataReport();
    }
}

