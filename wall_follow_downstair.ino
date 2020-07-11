void wallfollow_downstair()
{


    int time5 = millis();
      while (millis() - time5 < 2000)
      {
        frontwheel_forward(200,200);
        backwheel_forward(200,200);
        pingdistance();
      }
//  Serial.println("walldown"
     digitalWrite(harvester,HIGH);
    analogWrite(pwm_harvester,150);
 if (fldistance > 0 && bldistance > 0 && number_harvestor == 0)
  {
    if (fldistance == bldistance )
    {
      angle = 0;
    }
    //Serial.println("abcde");
    if ( topdistance == 0 || topdistance > 75 )
    {
      straight();
    }
    else if (topdistance < 75 && topdistance != 0)
    {
      while (angle >-160)
      {
        rotateright(-30,-160);
      }
      int time5 = millis();
      while (millis() - time5 < 2000)
      {
        stopbot();
        getgyro();
        pingdistance();
      }
      number_harvestor = 1;
     
    }
  }

  else if (frdistance > 0 && brdistance > 0 && number_harvestor == 1)
  {
    if(abs(frdistance-brdistance)<10){
     angle=atan((frdistance-brdistance)/45);
     }
     else
     {
      angle+=160;
     }
    if (frdistance == brdistance )
    {
      angle = 0;
    }
//    Serial.println("pqrst");
    if (topdistance > 75 || topdistance == 0)
    {
      straight();
    }
    else if (topdistance < 75)
    {
      analogWrite(pwm_harvester,0);
      while (angle > -160)
      {
        pingdistance();
        rotateright(-30,-160);
      }
     
    }
    else
    {
      int time5 = millis();
      while (millis() - time5 < 2000)
      {
        stopbot();
        pingdistance();
       // Serial.println("klmno");
      } number_harvestor = 2;
    }
  }



  else 
  {
    stopbot();
    
    main_state=2;
  }
}
