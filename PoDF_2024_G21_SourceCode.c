const int sensorpin = 27;
const int sensorpower = 9;
const int pumppin = 4; 

int sensor; 

const int delayTime = 1000; 

// "wet" and "dry" thresholdit, kalibrointi?
int thresh = 200;

void setup(){ 
  // pin:t ulostuloiksi
  pinMode(sensorpower,OUTPUT);
  pinMode(pumppin, OUTPUT_12MA);
  
  Serial.begin(9600);
}

void loop(){ 
  // Käynnistä anturi ja odota hetki
  digitalWrite(sensorpower,HIGH);
  delay(10);
  // luetaan sensoria
  sensor = analogRead(sensorpin);
  // sensori pois 
  digitalWrite(sensorpower,LOW);
  
  
  Serial.println(sensor);


if(sensor < thresh || sensor > 600){
    digitalWrite(pumppin, LOW); // Pumppu pois päältä
} else {
    digitalWrite(pumppin, HIGH); // Pumppu päälle
}
  
// Viive mittausten välissä
delay(delayTime);
}
