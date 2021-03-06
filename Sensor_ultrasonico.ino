/*
Talos Electronics
Rafael Lozano Rolón 
13/Septiembre/2015 
*/
#include <NewPing.h>//Libreria para sensor ultrasonico HC-SR04

NewPing sonar(11,12,300);//se declara los pines de trig, echo y distancia max, distancia max=500
const int Buzzer=2;//Declarar el pin 2 para la conexion del buzzer
const int led =3;//Declarar el pin 3 para la conexion del led 
int pausa;//guardamos el tiempo de espera entre parpadeo
int Distancia=0;//Variable que guardara la distancia medida por el sensor 

void setup() 
{
  pinMode(Buzzer,OUTPUT);//Definir el pin 2 como salida
   pinMode(led,OUTPUT);//Definir el pin 3 com0 salida
  Serial.begin(9600);//Iniciar comunicacion serial
}
 
void loop() 
{
  int Distancia= sonar.ping();
  Distancia=Distancia / US_ROUNDTRIP_CM;
  Serial.print(Distancia);
  Serial.println("cm");
  if(Distancia<50)//El led y buzzer encenderan cuando un objeto
  //se encuentre dentro del rango de 3cm y 50 cm
  {
    pausa=Distancia*20;//Calculo para hacer la pausa
    digitalWrite(Buzzer,HIGH);//Encender el buzzer
    digitalWrite(led,HIGH);//Encender el led 
    delay(pausa);//Esperar el tiempo de pausa
  }
  digitalWrite(Buzzer,LOW);//Apagar el buzzer
  digitalWrite(led,LOW);//Apagar el led
  delay(pausa);//Esperar el tiempo de pausa
}
