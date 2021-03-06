String inputString = "";
boolean stringComplete = false;
boolean goMesure = false,eau0=false,eau1=false,eau2=false,eau3=false,eau4 = false;
int ordre=0,i=0;
const int sensor0 = A0;
const int sensor1 = A1; 
const int sensor2 = A2; 
const int sensor3 = A3; 
const int sensor4 = A4; 
float sensorValue0=0,sensorValue1=0,sensorValue2=0,sensorValue3=0,sensorValue4=0;

unsigned long previousMillis=0,currentMillis=0;
unsigned long result0=0,result1=0,result2=0,result3=0,result4=0;

void setup() {
  
  Serial.begin(9600);
  inputString.reserve(200);
  Serial.println("Init");
  Serial.println("waiting for command : 1 = go, 2 = stop");
}

void loop() {
    if (stringComplete == true) {
      switch (ordre) {
        case 1:
          i++;
          Serial.print("mesure n°");
          Serial.print(i);
          Serial.println(" in progress");
          previousMillis = millis();
          stringComplete = false;
          ordre=0;
          goMesure = true;
          break;
        case 2:
          Serial.println("mesure stopped");
          stringComplete = false;
          ordre = 0;
          goMesure = false;
          eau0=false,eau1=false,eau2=false,eau3=false,eau4 = false;
          break;
       default:
          Serial.println("unknow command");
          stringComplete = false;
          ordre = 0;
       break;
        }
    }
    if (goMesure == true) {mesures();} 
    delay(1000);
}


void serialEvent() {
  while (Serial.available()>0) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
      ordre = inputString.toInt();
      inputString = "";
    }
    
  }
}

void mesures() {
   sensorValue0 = analogRead(sensor0);
   sensorValue0 = sensorValue0*100/1024;
   
   sensorValue1 = analogRead(sensor1);
   sensorValue1 = sensorValue1*100/1024;
   
   sensorValue2 = analogRead(sensor2);
   sensorValue2 = sensorValue2*100/1024;
   
   sensorValue3 = analogRead(sensor3);
   sensorValue3 = sensorValue3*100/1024;
   
   sensorValue4 = analogRead(sensor4);
   sensorValue4 = sensorValue4*100/1024;

     
   if (sensorValue0 >= 1){resultats(0); }
   if (sensorValue1 >= 1){resultats(1); }
   if (sensorValue2 >= 1){resultats(2); }
   if (sensorValue3 >= 1){resultats(3); }
   if (sensorValue4 >= 1){resultats(4); }
  }

  void resultats(int x) {
    switch (x) {
      case 0:
       if(eau0 == false) {
        currentMillis = millis();
        result0 = (currentMillis - previousMillis)/1000;
        Serial.print(" Water on sensor 0, time: ");
        Serial.print(result0);
        Serial.println(" sec");
        eau0=true;
         }
      break;
      
      case 1:
      if(eau1 == false) {
        currentMillis = millis();
        result1 = (currentMillis - previousMillis)/1000;
        Serial.print(" Water on sensor 1, time: ");
        Serial.print(result1);
        Serial.println(" sec");
        eau1=true;
        }
      break;
      
      case 2:
        if(eau2 == false) {
        currentMillis = millis();
        result2 = (currentMillis - previousMillis)/1000;
        Serial.print(" Water on sensor 2, time: ");
        Serial.print(result2);
        Serial.println(" sec");
        eau2=true;
        }

      break;
      
      case 3:
        if(eau3 == false) {
        currentMillis = millis();
        result3 = (currentMillis - previousMillis)/1000;
        Serial.print(" Water on sensor 3, time: ");
        Serial.print(result3);
        Serial.println(" sec");
        eau3=true;
        }
      break;
      
      case 4:
        if(eau4 == false) {
        currentMillis = millis();
        result4 = (currentMillis - previousMillis)/1000;
        Serial.print(" Water on sensor 4, time: ");
        Serial.print(result4);
        Serial.println(" sec");
        eau4=true;
        }
      break;      
    }
  }

