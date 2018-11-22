#include <Ultrasonic.h>

//Motor e velocidade
int IN1 = 2;
int IN2 = 4;
int velocidadeA = 3;

//Ultrasom - pinos
int pino_trigger = 5;
int pino_echo = 6;

//Inicializa o sensor nos pinos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(IN1, OUTPUT); //Ponte H
  pinMode(IN2, OUTPUT); //Ponte H
  pinMode(velocidadeA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Ler as informacoes do sensor em cm:
  float cmMsec = ultrasonic.Ranging(CM);

  //testa a distancia para ver se o bowl esta vazio ou nao:
  if (cmMsec >= 15) {
    rodarMotor();
  }
  if (cmMsec <= 20) {
    pararMotor();
  }
  Serial.println(cmMsec);
  delay(1000);
}

void rodarMotor() {
  digitalWrite(IN1, HIGH); //5V
  digitalWrite(IN2, LOW); //0V
  //Velocidade baixa (150 medio, 230 alto) PWM = 0 a 255
  analogWrite(velocidadeA,255);
}
void pararMotor() {
  digitalWrite(IN1, HIGH); // 5V   ==  Freio
  digitalWrite(IN2, HIGH); // 5V   ==
}
