
/*
==============================================
                  ADC_DEMO
==============================================
Description :
  This program turns on an LED connected to GPIO32, 
  GPIO33, and GPIO25, with a 10K Ohms potentiometer
  and a 5mm light sensor with a light resistance.
Engineers: 
  Althea Jane Cordova

Date: 
  16 September 2026
*/
//GPIO PINS
  const uint8_t POT = 36;
//variables
  int pot_val = 0;
  uint8_t const LED1 = 26;
  uint8_t const LED2 = 33;
  uint8_t const LED3 = 25;
  //pwm
 const int FREQ =5000;
 const uint8_t RES = 12;



void setup() {
  //ADC PIN
  Serial.begin(9600);
  pinMode(POT, INPUT);
  ledcAttach(LED1,FREQ,RES);
  ledcAttach(LED2,FREQ,RES);
  ledcAttach(LED3,FREQ,RES);

}

void loop() {
  // 
  Serial.println(pot_val);
  pot_val = analogRead(POT);
  if(pot_val < 1280){
    ledcWrite(LED1,4095);
    ledcWrite(LED2,0);
    ledcWrite(LED3,0);
    Serial.println("LVL1");

  }
  else if(pot_val >= 1280 && pot_val < 2048){
    ledcWrite(LED1,0);
    ledcWrite(LED2,4095);
    ledcWrite(LED3,0);
    Serial.println("LVL2");
  }
  else {
      ledcWrite(LED1,0);
      ledcWrite(LED2,0);
      ledcWrite(LED3,4095);
      Serial.println("LVL3");
    }
    delay(500); 
}