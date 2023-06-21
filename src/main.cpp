#include <Arduino.h>
#include <Wire.h>
#include <mcp.h>


#define chipAddrIn = 0x20;
#define chipAddrOut = 0x27;
#define GPIOA = 0x12; // PortA reg addr
#define GPIOB = 0x13; // PortB reg addr
#define IODIRA = 0x00; // PortA direction reg addr
#define IODIRB = 0x01; // PortB direction reg addr                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                void setup() {
#define INTCONA = 0x08;
#define INTFA = 0x0e;
#define INTCAPA = 0x10;
#define IOCON = 0x0a;
#define GPINTENA = 0x04;
#define IPOLA = 0x02;
#define DEFVALA = 0x06;
#define GPPUA = 0x0c;
#define GPPUB = 0x0d;


int a =0; 
    
byte pin0 ;
byte pin1 ;  

  byte AOut;
  
void mcu_write(int Addr,int registre,int value){
    Wire.beginTransmission(Addr);
    Wire.write(registre); // IOCON dir register
    Wire.write(value); // 
    Wire.endTransmission();
}


  void setup()
  {
  Wire.begin();

  Serial.begin(9600);
  mcu_write(chipAddrIn,GPPUA,0x0f);
  mcu_write(chipAddrIn,IODIRA,0xff);//input
  mcu_write(chipAddrIn,IPOLA, 0x00);//polarité 
  
  mcu_write(chipAddrOut,IODIRA,0x00);//output
 
  }

  
  void loop()
  {
  //pinMode( 13, OUTPUT );
  //mcpIn.pinMode(0, OUTPUT);
  //digitalWrite(13,LOW);
  //mcpIn.digitalWrite(0,LOW);
  //delay(1000);
  //digitalWrite(13,HIGH);
  //mcpIn.digitalWrite(0,HIGH);
  delay(3000);
  


  Wire.beginTransmission(chipAddrIn);
  Wire.write(GPIOA);
  Wire.endTransmission();
  delay(10);
  Wire.requestFrom(chipAddrIn,1); // IOCON dir register
  if(Wire.available()){
    pin0 = Wire.read();
  
    
    //pin0 = mcpIn.digitalRead(0);
    //pin1 = mcpIn.digitalRead(1);
    Serial.print("Digital Input ");
    Serial.println(pin0,BIN);
    //Serial.print("Digital Input 1 --> ");
    //Serial.println(pin1,BIN);
    }

  AOut = !AOut;
  Serial.println(AOut);
  mcu_write(chipAddrOut,GPIOA,AOut);

  }
