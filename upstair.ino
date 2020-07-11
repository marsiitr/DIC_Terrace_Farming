void upstair()
{
   if(upstair_state==0){
    
    if(middle_height<55){

    pid_bf_lead_up();
      if (counter1 > -61000)
      {
        front_lead_down(f_pwm);
      }
      else
      {
        front_lead_down(0);
      }

      if (counter3 > -60000 )
      {
        back_lead_down(b_pwm);
      }
      else
      {
        back_lead_down(0);
      }
    }
    else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
        pingdistance();
      }
      upstair_state = 1;
    }
  }

  else if(upstair_state==1){
    if(counter2>-57000){
      middle_lead_down(200);
   }
   else
   {
    stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
        pingdistance();
      }
      upstair_state = 2;
   }
  }

    else if(upstair_state==2){
    if(counter1<-1000){
      front_lead_up(150);
   }
   else
   {
    stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
        pingdistance();
      }
      upstair_state = 3;
   }
   }

  else if ( upstair_state == 3 )
  {

    if (front_height > 25 )
    {
//      Serial.println("gbvhybg");
      analogWrite(f_pwm,0);
      analogWrite(m_pwm,0);
      analogWrite(b_pwm,0);
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
      upstair_state = 4;
    }
  }
  else if (upstair_state == 4)
  {
    if ( counter2 <-2000 )
    {
     
      middle_lead_up(150);
    }

    else
    {
           // Serial.println("234567");
      stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
        pingdistance();
      }
      upstair_state = 5;
    }
  }
  //

  else  if (upstair_state == 5)
  {
    if (middle_height > 25)
    {
      analogWrite(f_pwm,0);
      analogWrite(m_pwm,0);
      analogWrite(b_pwm,0);
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
      upstair_state = 6;
    }
  }


  else if (upstair_state == 6)
  {
    if (counter3 <-1000 )
    {
      back_lead_up(150);
    }
    else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
        pingdistance();
       // Serial.println("abcdefgh");
      }
      upstair_state = 7;
//      delay(2000);
    }
   
  }

  else if (upstair_state == 7){
  
      Time1=millis();
      while(millis()-Time1<200 )
      {
        
       digitalWrite(f,LOW);
      analogWrite(pwmf,100);
      }
      analogWrite(pwmf,0);
      stopbot();
      Time = millis();
      while (millis() - Time < 2000) {
        pingdistance();
      }
     upstair_state=8;
  }
  
else if (upstair_state==8){
    if (back_height > 25)
    {
//      Serial.println("dhruv");
      frontwheel_forward(40,40);
      backwheel_forward(40,40);
    }
 
    else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 1000) {
        pingdistance();
      }
      upstair_state = 9;
    }
  }

  else if (upstair_state==9){

      Time = millis();
      while (millis() - Time < 1000) {
      frontwheel_forward(40,40);
      backwheel_forward(40,40);
      }
      upstair_state = 10;
    }
 

  else if (upstair_state==10){
      while (angle>-75) {
        pingdistance();
        rotateright(-30,-75);
      }
      upstair_state = 11;
    }
  else
  {
    stopbot();
    main_state=3;
  }
  //
  //
  //      //    Serial.print("1==");
  //      //    Serial.println(counter1);
  //          Serial.print("2==");
  //          Serial.println(counter2);
  //          Serial.print("3==");
  //          Serial.println(counter3);

}

  
