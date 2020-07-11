void downstair()
{
  // Serial.println("downstair");

  if ( downstair_state == 0)
  {
    if (front_height < 30)
    {
      
      backwheel_forward(40,40);
      frontwheel_forward(40,40);
    }
    else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
        pingdistance();
      }
      downstair_state = 1;
    }
  

  }
  else if ( downstair_state == 1 )
  {
          if (counter1 > -61000 )
      {
        front_lead_down(200);
      }
    else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
      pingdistance();
      }
      downstair_state = 2;
    }
  }

  
  else if (downstair_state == 2)
  {
    if (middle_height < 40)
    {
      backwheel_forward(40,40);
      frontwheel_forward(40,40);
    }

    else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
        pingdistance();
      }
      downstair_state = 3;
    }
  }

  else  if (downstair_state == 3)
  {
    if (counter2 > -60000 )
    {
       middle_lead_down(180);
    }
    else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
      pingdistance();
      }
      downstair_state = 4;
    }
  }

else if(downstair_state==4)
{
      Time1=millis();
      while(millis()-Time1<300 )
      {
       front_lead_down(150);
      }
      analogWrite(pwm1,0);
      analogWrite(pwm2,0);
      stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
        pingdistance();
      }
    downstair_state = 5;
    }
  else if (downstair_state == 5)
  {
    if (back_height < 25)
    {
      backwheel_forward(40,40);
      frontwheel_forward(40,40);
    }
    else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
        pingdistance();
      }
      downstair_state = 6;
    }
   
  }

else if (downstair_state == 6){
  
    if (counter3 > -60000 )
    {
       back_lead_down(200);
    }

        else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 1000) {
        pingdistance();
      }
      downstair_state = 7;
    }
  }
  
else if (downstair_state==7){
    if ( counter2 <-1000 )
    {
     middle_lead_up(150);
    }
 
    else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 1000) {
        pingdistance();
      }
      downstair_state = 8;
    }
  }

 else if ( downstair_state == 8)
  {
    if (middle_height >20)
    {
      pid_bf_lead();
      if (counter1 <-600 )
      {
        front_lead_up(f_pwm);
      }
      else
      {
        front_lead_up(0);
      }

      if (counter3 < -600 )
      {
        back_lead_up(b_pwm);
      }
      else
      {
        back_lead_up(0);
      }
    }
    else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
        pingdistance();
      }
      downstair_state = 9;
    }
  }
  else if(downstair_state == 9){
    while(angle<75){
//    pingdistance();
    rotateleft(75);
    }
    downstair_state=10;
  }

  else
  {
    stopbot();
    main_state=1;
    Time = millis();
    while (millis() - Time < 5000) {
     pingdistance();
      }
  }
  //
  //
//            Serial.print("1==");
//            Serial.println(counter1);
  //          Serial.print("2==");
  //          Serial.println(counter2);
  //          Serial.print("3==");
  //          Serial.println(counter3);
}
