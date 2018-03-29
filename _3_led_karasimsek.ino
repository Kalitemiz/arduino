int ledPins[]={2,3,4,};//2,3,4, sayilarini setup kısmında kullanmak üzere dizide tanımladık.
void setup() {
   
 for(int i = 0; i < 3; i++){ 
 pinMode(ledPins[i],OUTPUT);//sirasiyla 2,3,4 pinlerini çıkış pinleri olarak belirliyor.Eğer bu kısmı anlamadıysanız C programlama dili diziler Konusuna bakmanızı öneririm.
}
}
void loop() {
   
 for(int i=0;i<3;i++)
 {
 digitalWrite(ledPins[i],HIGH);//2,3,4 ledlerini aralarında 100 ms zaman aralıklarıyla yakar.
 delay(100);//
 }
 delay(100);//butun ledler yandıktan sonra 100ms bekler.
 
 for(int i=0;i<3;i++) { 
  digitalWrite(ledPins[i],LOW);//sırasıyla 2,3,4 ledlerini 100 ms zaman aralıklarıyla söndürür. delay(100);// } delay(200);// butun ledler söndükten sonra 200ms bekler. for(int i=2;i>=0;i--)
 } 
 //delay(50);
 delay (100);//bütün ledler söndükten sonra 100 ms bekler.
 
 for(int i=2;i>=0;i--)
 {
 digitalWrite(ledPins[i],LOW);//4,3,2 ledlerini sırasıyla ( ledleri sondan söndürmeye başlar) 100ms zaman aralıklarıyla söndürür.
 delay(100);//
 } 
 delay (200);//butun ledler söndükten sonra 200ms bekler.
  
}
//*/}
