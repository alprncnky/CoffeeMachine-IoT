#include <Servo.h>
Servo motor;

int selenoidMotor = 7;
int suMotor = 4;
int onOff = 5;

char data;
char komut;
int angle = 0;

int bikerecalistir=0;
int count=0;

void setup()                    
{
 Serial.begin(115200); 
 pinMode(onOff, OUTPUT);           //Sets the pin as an output
 pinMode(selenoidMotor, OUTPUT);
 pinMode(suMotor, OUTPUT);
 digitalWrite(onOff, HIGH); 
}

void baslangicAyar(){
 // motor ayarı
 motor.attach(9);
for(angle=0; angle<=20; angle++){
  motor.write(angle);
  delay(8);  
  }
  for(angle=00; angle>=0; angle--){
    motor.write(angle);
    delay(8);  
  }
  motor.detach();
}

void makineON(){
  digitalWrite(onOff, LOW);
  Serial.println("if 2 de");
}

void makineOFF(){
  digitalWrite(onOff, HIGH); 
  Serial.println("if 1 de");
}

void suMotoruCalistir(){
  Serial.println("suMotoruCalis");
  digitalWrite(suMotor,HIGH);
}

void suMotoruDurdur(){
  Serial.println("suMotoruDur");
  digitalWrite(suMotor,LOW);
}

void selenoid(int kackere)
{
  for(int i=0; i<kackere; i++){  
    digitalWrite(selenoidMotor,HIGH);
    delay(50);
    digitalWrite(selenoidMotor,LOW);
    delay(50);
  }
}

void kahveyiDok(int times){
  
 motor.attach(9);
 for(int j=0;j<times;j++){
  Serial.println("kahveyidök");
  for(int i=0;i<10;i++){     
        for(angle=0; angle<=100; angle++){
          motor.write(angle);
          delay(7);
        }

        selenoid(5);                                                                                                                                                                                                                                                                                                                                    
          
        for(angle=100; angle>=0; angle--){
          motor.write(angle);
          delay(7);  
        }         
   }
 }
 motor.detach();
}


void commandUpdate(char kmt){
  komut=kmt;
  Serial.println(komut);
  if(komut == '1'){
    activateMachine(1);
  }
  else if(komut == '2'){
    activateMachine(2);
  }
}


void activateMachine(int times){
  Serial.println("activateMachine");
  kahveyiDok(times);
  
  suMotoruCalistir();
  delay(9000*times);
  suMotoruDurdur();

  makineON();
  delay(45000);
  makineOFF();
}


// ************** Program **************
//**************************************

void loop()
{
  // motor adj.
  if(bikerecalistir<2){
    baslangicAyar();
    bikerecalistir++;
  }

// read data from WebService and update the command
  while (Serial.available() > 0)
   {
    data = (char)Serial.read();     //Giriş değerlerini oku.
    if (data != NULL){
      if(data == '1' || data == '2' || data == 'f'){
          commandUpdate(data);  // update komut send this data
        }
     }
   }
}

