//All the dht functions should be used if you are using dth11(temperature sensor) in your project. They are commented in this file.


#include "ESP_MICRO.h" //Include the micro library 
//#include <DHTesp.h> //include this library if  you are using dht11 (temperature sensor)
//DHTesp dht;

//#define DHTpin 14    //D5 of NodeMCU is GPIO14
int testvariable = 0;
const int sensor_pin = A0; 
String S;
void setup(){
  Serial.begin(115200); // Starting serial port for seeing details
  start("ABC","12345678");  // EnAIt will connect to your wifi with given details
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");
  
  // Autodetect is not working reliable, don't use the following line
  // dht.setup(17);
 
  // use this instead: 
  //**dht.setup(DHTpin, DHTesp::DHT11); //for DHT11 Connect DHT sensor to GPIO 17
  //dht.setup(DHTpin, DHTesp::DHT22); //for DHT22 Connect DHT sensor to GPIO 17
}
void loop(){
  
  //delay(dht.getMinimumSamplingPeriod());
 //float humidity = dht.getHumidity();
 // float temperature = dht.getTemperature();
 
  float moisture_percentage;
  moisture_percentage = ( 100.00 - ( (analogRead(sensor_pin)/1023.00) * 100.00 ) );//taking the reading from the moisture sensor
  S= moisture_percentage;
 
  waitUntilNewReq();  //Waits until a new request from python come
  /* increases index when a new request came*/
  testvariable += 1;
  returnThisStr(S); //returns the reading to the python file, which will in turn render it to the web page.
}
