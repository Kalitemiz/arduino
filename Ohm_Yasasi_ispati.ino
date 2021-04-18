/*
Tinkercad Devre linki : https://www.tinkercad.com/things/6awa2nXToig-copy-of-ohm-yasasi/editel?sharecode=uetCCy2kfBXTzO_e3rBGRg7CMxS5qJAUEcV-SC3iQBc
*/

float deger;
float akm = 0.0;
float akmA=0;
float okunanA;
int okunanADC=0;
//int okunanB;
void setup() {
  Serial.begin(9600);
}

void loop() {
okunanADC = analogRead(A0);
okunanA = okunanADC * 5 / 1024 ;// okunan her ADC değerinin V cinsinden karşılığı böyle bulunur.
akmA = okunanA/*Volt*/ / 330/*ohm*/;// Ohm Yasasına göre V=I.R buradan Akım I=V/R kullanılarak okunan ADC değeri 1 direnç için 330 a böldük.
akm = akmA * 1000;//akım değerini mA(miliAmper) e dönüştürdük.

int okunanBDC = analogRead(A1);
float okunanB = okunanBDC * 5 / 1024 ;
float akmB = okunanB / 660;
float Bakm = akmB *1000;

int okunanCDC = analogRead(A2);
float okunanC = okunanCDC * 5 / 1024 ;
float akmC = okunanC / 990;
float Cakm = akmC *1000;

Serial.print("Sırasıyla 1,2,3 dirençte Akim (mA):");
Serial.print(akm);
Serial.print(" - ");
Serial.print(Bakm);
Serial.print(" - ");
Serial.println(Cakm);
Serial.println("----");
delay (500);
}
