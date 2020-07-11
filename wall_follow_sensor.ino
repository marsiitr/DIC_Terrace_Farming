 void wallfollow_sensor() 
 {

    
    if(fldistance>0 && bldistance>0 && number_sensor==0)
    {
        if(fldistance == bldistance )
         {
            angle=0;
         }
        //Serial.println("abcde");
        if( topdistance==0 || topdistance>150 )
        {
          // Serial.println("abcde2");
          straight();
        }
        else if(topdistance<150 && topdistance!=0 && internal_sensor==0)
        {
          stopbot();
          int reading=millis();
          while(millis()-reading<5000)
          {
            digitalWrite(solenoid,LOW);
            digitalWrite(sensor,HIGH);
            analogWrite(pwm_sensor,250);
            
          }
           reading=millis();
          while(millis()-reading<2000)
          {
            digitalWrite(solenoid,LOW);
            digitalWrite(sensor,LOW);
            analogWrite(pwm_sensor,250);
            
          }
          digitalWrite(solenoid,HIGH);
          analogWrite(pwm_sensor,0);
          internal_sensor=1;
        }
        
        else if(topdistance<150 && topdistance!=0 && internal_sensor==1)
        {
          while(angle>-160)
          {
            Serial.println("fghij");
            pingdistance();
            rotateright(-30,-160);
          }
           number_sensor=1;
        }
    }
    
    else if(frdistance>0 && brdistance>0 && number_sensor==1)
    {
        if(frdistance == brdistance )
         {
            angle=0;
         }
        if(topdistance>75 ||topdistance==0)
        {
          straight();
        }
          number_sensor=2;
        }
    



    else if(number_sensor==2)
    {
      stopbot();
      main_state=5;
    }
 }
