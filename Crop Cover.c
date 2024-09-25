#include < dht.h>
#include < Wire.h>
#include < LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0 x 27 , 16 ,
2 ) ; dht DHT;
12
#define DHT11_PIN 8 // digital pin we're connected
to int cangle = 180; int angle = cangle;
#define DHTTYPE DHT11 // DHT 11
#include < Servo.h>
Servo myservo;
void setup () { lcd .
begin () ; lcd.
setCursor( 0 , 0) ;
lcd . print ( ( char )
223 ); lcd. print ((
char ) 223 ); lcd .
print ( "Rain Shield" )
; lcd . print (( char )
223 ); lcd. print ((
char ) 223 );
delay( 3000) ;
myservo. attach ( 9
); myservo. write(
cangle) ;
}
void loop () {
int d = DHT . read11 (
DHT11_PIN ); lcd . setCursor
( 0 , 0 ) ; lcd . print (
13
"Temp: " ) ; lcd . print (
DHT . temperature ) ; lcd .
print (( char ) 223 ) ; lcd .
print ( "C" ) ; lcd .
setCursor ( 0 , 1 ) ; lcd .
print ( "Humidity: " ) ; lcd
. print ( DHT . humidity ) ;
lcd . print ( "%" ) ;
float temp = DHT .
temperature ; float humi =
DHT. humidity ;
if ( temp > 35 && cangle != 180 && humi < 76 ) {
//Normal temperature
for ( int angle = cangle; angle <= 180 ;
angle++ ) { myservo . write ( angle ) ; delay
( 15 ) ; } lcd . setCursor ( 0 , 0 ) ; lcd .
print ( "Rain Shield " ) ; lcd . setCursor (
0 , 1 ) ; lcd . print ( "Deactivated " ) ;
cangle = 180 ; delay ( 2000 ) ;
} else if ( temp <= 35 && cangle != 0 && humi >=
76 ) { for ( int angle = cangle; angle >= 0 ;
angle-- ) { myservo . write ( angle ) ; delay ( 15
) ; } lcd . setCursor ( 0 , 0 ) ; lcd . print (
"Rain Shield " ) ; lcd . setCursor ( 0 , 1 ) ;
lcd . print ( "Activated " ) ; cangle = 0 ;
delay ( 2000 ) ; } delay ( 500 ) ;
}