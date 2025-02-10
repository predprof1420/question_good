#define LS A3      // левый датчик
#define CS A4
#define RS A5      // правый датчик
 
/*-------- определение выходов ------*/
#define LM1 4       // левый двигатель
#define LM2 5       // левый двигатель
#define RM1 7       // правый двигатель
#define RM2 6       // правый двигатель

#include <NewPing.h>
 
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 400
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
 

void setup()
{
  pinMode(LS, INPUT);
  pinMode(CS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  
}

void loop(){
  if (sonar.ping_cm() > 5){

  if((digitalRead(LS)) && !(digitalRead(CS)) && (digitalRead(RS)))    // Движение вперед
  
   
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(CS)) && digitalRead(RS))     // Поворот направо
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1,LOW );
    digitalWrite(RM2, LOW);
  }
  
  if(digitalRead(LS) && !(digitalRead(CS)) && !(digitalRead(RS)))     // Поворот налево
  {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(CS)) && !(digitalRead(RS)))     // остановка
  {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
  }
  }
  if (sonar.ping_cm() <= 5)
  {
   digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW); 
  }
}