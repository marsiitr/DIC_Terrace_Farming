void wallfollow_seeder()
{
 // Serial.println("seeder");
  int time5 = millis();
  while (millis() - time5 < 2000)
  {
    frontwheel_forward(150, 150);
    backwheel_forward(150, 150);
    pingdistance();
  }

  if (fldistance > 0 && bldistance > 0 && number_seeder == 0)
  {
    if (fldistance == bldistance )
    {
      angle = 0;
    }
    //Serial.println("abcde");
    if ( topdistance == 0 || topdistance > 75 )
    {
      //Serial.println("abcde2");
      straight();
      digitalWrite(seeder, HIGH);
      analogWrite(pwm_seeder, 70);
    }


    else if (topdistance < 75 && topdistance != 0)
    {
      int time5 = millis();
      while (millis() - time5 < 1000)
      {
        stopbot();
        pingdistance();
      }
      analogWrite(pwm_seeder, 0);
      while (front_height < 22)
      {
        pid_bf_lead_up();
        if (counter1 < 10000 )
        {
          //            Serial.println(f_pwm);
          front_lead_down(f_pwm);
        }
        else
        {
          front_lead_down(0);
        }

        if (counter3 < 10000 )
        {
          //            Serial.println("ijndj");
          back_lead_down(b_pwm);
        }
        else
        {
          back_lead_down(0);
        }
      }
      //      Serial.println("fghij");
      time5 = millis();
      while (millis() - time5 < 1000)
      {
        stopbot();
        pingdistance();
      }

      while (angle > - 165)
      {
        rotateright(-30, -165);
      }

       time5 = millis();
      while (millis() - time5 < 1000)
      {
        stopbot();
        pingdistance();
      }


      while (middle_height > 19)
      {
        pingdistance();
        pid_bf_lead();
        if (counter1 > 600 && f_bump == 0)
        {
          front_lead_up(f_pwm);
        }
        else
        {
          front_lead_up(0);
        }

        if (counter3 > 600 && b_bump == 0)
        {
          back_lead_up(b_pwm);
        }
        else
        {
          back_lead_up(0);
        }
      }

    }
    else
    {
      stopbot();
      number_seeder = 1;
    }
  }

  else if (frdistance > 0 && brdistance > 0 && number_seeder == 1)
  {
    if(abs(frdistance-brdistance)<10){
     angle=atan((frdistance-brdistance)/45);
     }
     else
     {
      angle+=160;
     }
    int time5 = millis();
    while (millis() - time5 < 1000)
    {
      stopbot();
      pingdistance();
    }

    if (frdistance == brdistance )
    {
      angle = 0;
    }
    if (topdistance > 75 || topdistance == 0)
    {
      digitalWrite(seeder, HIGH);
      analogWrite(pwm_seeder, 70);
      straight();
    }
    else if (topdistance < 75)
    {
      while (angle > -160)
      {
        rotateright(-30, -160);
      }
    }
    else
    {
      stopbot();
      Time = millis();
      while (millis() - Time < 1000) {
        pingdistance();
      }
    }

  }

  else
  {
    stopbot();
    main_state = 4;
    number_seeder = 2;
  }
}
