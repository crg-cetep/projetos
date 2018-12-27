#include <Ultrasonic.h>

//Pinagem
//Motor
int motor = 3; //pwm

//Ultrassom
int pino_trigger = 5;
int pino_echo = 6;

//Instancia o ultrasonic
Ultrasonic ultrasonic(pino_trigger, pino_echo);


void setup() {
  Serial.begin(9600);
  pinMode(motor,OUTPUT);
  
  //Retorno quando a bengala for ligada
  digitalWrite(motor,HIGH);
  delay(500);
  digitalWrite(motor,LOW);
}

void loop() {
  //Reconhecimento do terreno -- conversão para centimetros
  float cent;
  long microsec = ultrasonic.timing();
  cent = ultrasonic.convert(microsec, Ultrasonic::CM);
  
  //Serial monitor
  Serial.print("Distancia para o corpo mais prox: ");
  Serial.println(cent);
  
  //Testes
  if(cent <= 20 || cent >=0){
    digitalWrite(motor,HIGH);
  } else {
    digitalWrite(motor,LOW);
  }
}
