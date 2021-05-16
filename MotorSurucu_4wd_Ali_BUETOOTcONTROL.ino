//Arabaya Yüklendi çalışıyor.
//L298N Bağlantısı   https://www.youtube.com/watch?v=kE0Vrtbw4Vw
#include <SoftwareSerial.h>
  const int in1  = 4;  // L298N'in IN1 Girişi
  const int in2  = 5;  // L298N'in IN2 Girişi
  const int in3  = 6; // L298N'in IN3 Girişi
  const int in4  = 7;  // L298N'in IN4 Girişi
  const int e1  = 3;
  const int e2  = 9;
int bekle=3000;

SoftwareSerial bt_iletisim(2,3);//Rx,Tx

  void setup() {
    // Pinlerimizi belirleyelim
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);   
    pinMode(e1, OUTPUT);// enanle pinlerine bağlamak yeterli
    pinMode(e2, OUTPUT);       
    // 9600 baud hızında bir seri port açalım
    Serial.begin(9600);
    bt_iletisim.begin(9600);
}
 void solMotorIleri(){
      digitalWrite(in4, 0);
      digitalWrite(in3, 1);
    }
 void solMotorGeri(){
      digitalWrite(in4, 1);
      digitalWrite(in3, 0);
    }
    
 void sagMotorIleri(){
      digitalWrite(in2, 0);
      digitalWrite(in1, 1);
    }
 void sagMotorGeri(){
      digitalWrite(in2, 1);
      digitalWrite(in1, 0);
    }

void arabaIleri(){
sagMotorIleri();
solMotorIleri();
}
void arabaGeri(){
sagMotorGeri();
solMotorGeri();
}
void arabaSol(){
sagMotorIleri();
solMotorGeri();
}
void arabaSag(){
sagMotorGeri();
solMotorIleri();
}
void dur(){
       //Dur
      digitalWrite(in1, 0); 
      digitalWrite(in2, 0);
      digitalWrite(in3, 0);
      digitalWrite(in4, 0); 
      }

void loop() {
 
  if (bt_iletisim.available()) {
    char inByte = bt_iletisim.read();
     Serial.println(inByte); 
     if (digitalRead(inByte)==LOW){ dur(); }
 
  switch (inByte) {
      case 'F':
        arabaIleri();
        break;

      case 'B':
        arabaGeri();
        break;

      case 'R':
       arabaSag();
        break;

      case 'L':
        arabaSol();
        break;

      case 'S':
        dur();
        break;

      default:dur();
 }
//*********************
 } 
}
