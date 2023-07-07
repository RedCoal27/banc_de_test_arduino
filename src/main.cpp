#include <Arduino.h>
#include <SoftwareSerial.h>

#define RX_PIN DD3
#define TX_PIN DD2
#define NUM_GAUGES 1
#define MAX_NODE_ADDRESSES 98
#define MAX_SERIAL_LENGTH 10

SoftwareSerial rs485(RX_PIN, TX_PIN);

//les ID sont 06 et 07 (fin du numéro de série)

void enumerateGauges()
{
    // rs485.println("!C781 2");
    // rs485.println("#00:01!C781 2");
    rs485.println("#51:00!S750 07");
    delay(500);
    for(int i= 1;i<=98;i++){
        String test = "#";
        if(i<10){
            test = test + "0";
        }
        test = test + i + ":00!C781 0";
        Serial.println(test);
        rs485.println(test);
        int x = 0;
        while(!rs485.available() && x<1000){
            x++;
            delay(0.01);
        }
        if(x<1000)
            Serial.println(rs485.readStringUntil('\n'));
    }
}

void setup()
{
    Serial.begin(9600);
    rs485.begin(9600);

    enumerateGauges();

    // Ici vous pouvez insérer le code pour interagir avec les jauges une fois l'énumération terminée
}

void loop()
{
    // Insérer ici la logique de programme principale
}
