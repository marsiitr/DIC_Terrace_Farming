long Time, Time1 = 0;
bool auto_mode=0;
bool manual_mode=1;
bool seeder1=0;
bool harvester1=0;
int value_fbump=0;
int value_mbump=0;
int value_bbump=0;
int manual_speed=90;


int harvester = 40;
int pwm_harvester = 8;

int seeder = 38;
int pwm_seeder = 5;

int sensor = 40;
int pwm_sensor = 8;

int main_state=0;

int solenoid = 38;
int x=47,y=35,z=37,r=25,d=23;
int internal_sensor=0;



/////////////////////////GYRO////////////////////////
#include <MPU9250.h>

MPU9250 IMU;
int sig = 7;
int16_t gyro[3] = {0, 0, 0};
int16_t acc[3] = {0, 0, 0};
float gyroBias[3]  = {0, 0, 0};
float accelBias[3] = {0, 0, 0};
int dt;
long Time_gyro;
double s=0;
double angle = 00.00;
double first_reading=0;
double correction = 0;
double angle_kp = 2.5, angle_kd = 3.9;

int p = 0;
int time0 = 0;

double t;
double angle_error = 0, angle_derror = 0, angle_perror = 0, angle_correction = 0;

void getgyro()
{
  
  IMU.readGyroData(gyro);
  dt = micros() - Time_gyro;

  angle += (gyro[2]-s)*dt/131.0/1000000.0;
  Time_gyro = micros();
  Serial.println("angle=");
  Serial.println(angle);
}



/////////////////////////////ULTRA///////////////////////////////


#include <NewPing.h>
#define SONAR_NUM 8
#define MAX_DISTANCE 75
#define PING_INTERVAL 20

unsigned long pingTimer[SONAR_NUM]; // When each pings.
unsigned int ultradistance[SONAR_NUM]; // Store ping distances.
uint8_t currentSensor = 0; // Which sensor is active.

int frdistance = 0, fldistance = 0, topdistance = 0, brdistance = 0, front_height, middle_height, back_height ,  bldistance = 0;

double velocity_correction = 0, kp_velocity = 2.3, velocity_error = 0, kd_velocity = 2.7, velocity_derror = 0, velocity_perror = 0;
double dis_correction = 0, kp_dis = 2, dis_error = 0, kd_dis = 3.5, dis_derror = 0, dis_perror = 0;

NewPing sonar[SONAR_NUM] =
{ // Sensor object array.
  NewPing(A3, A2, MAX_DISTANCE),
  NewPing(A4, A5, MAX_DISTANCE),
  NewPing(A8, A9, MAX_DISTANCE),
  NewPing(A6, A7 , MAX_DISTANCE),
  NewPing(A0, A1, MAX_DISTANCE),
  NewPing(A14, A15, MAX_DISTANCE),
  NewPing(A12, A13 , MAX_DISTANCE),
  NewPing(44, 46, MAX_DISTANCE),

};
void pingdistance()
{

  for (uint8_t i = 0; i < SONAR_NUM; i++)
  {
    if (millis() >= pingTimer[i]) {
      pingTimer[i] += PING_INTERVAL * SONAR_NUM;
      if (i == 0 && currentSensor == SONAR_NUM - 1)
      {
        oneSensorCycle();
      } // Do something with results.
      sonar[currentSensor].timer_stop();
      currentSensor = i;
      ultradistance[currentSensor] = 0;
      sonar[currentSensor].ping_timer(echoCheck);
    }

  }

}
void echoCheck()
{ // If ping echo, set distance to array.
  if (sonar[currentSensor].check_timer())
    ultradistance[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;

}

void oneSensorCycle()
{ // Do something with the results.
  fldistance = ultradistance[0];
  topdistance = ultradistance[1];
  frdistance = ultradistance[2];
  brdistance = ultradistance[3];
  bldistance = ultradistance[4];
  front_height = ultradistance[7];
  middle_height = ultradistance[6];
  back_height = ultradistance[5];

  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    Serial.print(i);
    Serial.print("=");
    Serial.print(ultradistance[i]);
    Serial.println("cm ");
  }

}

///////////////////////WHEEL_MOTOR///////////////////////

double v1 = 0, v2 = 0, v3 = 0, v4 = 0;

int fr = 26;
int pwm1 = 4;
int fl = 43;
int pwm2 = 12;
int br = 32;
int pwm3 = 7;
int bl = 41;
int pwm4 = 11;


void backwheel_forward(int a,int b)
{
  digitalWrite(br, HIGH);
  analogWrite(pwm3, a);
  digitalWrite(bl, HIGH);
  analogWrite(pwm4, b);
}


///////////////////////////////////////////////////////////////////////

void backwheel_backward()
{
  digitalWrite(br, LOW);
  analogWrite(pwm3, 40);
  digitalWrite(bl, LOW);
  analogWrite(pwm4, 40);
}


///////////////////////////////////////

void frontwheel_forward(int a, int b)
{
  digitalWrite(fr, HIGH);
  analogWrite(pwm1, a);
  digitalWrite(fl, HIGH);
  analogWrite(pwm2, b);
}


////////////////////////////////////////

void frontwheel_backward()
{
  digitalWrite(fr, LOW);
  analogWrite(pwm1, 40);
  digitalWrite(fl, LOW);
  analogWrite(pwm2, 40);
}




////////////////////////////////LEADMOTORS///////////////////////////////////////

int lead_bm_error = 0, lead_bm_perror = 0, lead_bm_derror = 0, correction_lead_bm = 0;
double kp_lead_bm = 0.005, kd_lead_bm = 0;
int upstair_state = 0, variable = 0;

int lead_bf_error = 0, lead_bf_perror = 0, lead_bf_derror = 0, correction_lead_bf = 0;
double kp_lead_bf = 0.005, kd_lead_bf = 0;
int downstair_state = 0;

double m_pwm = 0, b_pwm = 0, f_pwm = 0;

int f = 40;
int pwmf = 8;
#define a1 19
#define b1  A11
float theta1c = 0;
long int temp1, counter1 = 0;


int m = 38;
int pwmm = 5;
#define a2 18
#define b2  A10
float theta2c = 0;
long int temp2, counter2 = 0;


int b = 49;
int pwmb = 6;
int lead1=40;
int lead1_pwm=8;
int lead2=40;
int lead2_pwm=8;
int lead_speed=150;
#define a3 2
#define b3  3
float theta3c = 0;
long int temp3, counter3 = 0;

int lead_bf_error_up = 0, lead_bf_perror_up = 0, lead_bf_derror_up = 0, correction_lead_bf_up = 0;
double kp_lead_bf_up = 0.005, kd_lead_bf_up = 0;
void pid_bf_lead_up()
{
  lead_bf_error_up = counter1 - counter3;
  lead_bf_derror_up = lead_bf_error_up - lead_bf_perror_up;
  correction_lead_bf_up = kp_lead_bf_up * lead_bf_error_up + kd_lead_bf_up * lead_bf_derror_up;
  lead_bf_perror_up = lead_bf_derror_up;
  b_pwm =200-correction_lead_bf_up;
  f_pwm =200 +correction_lead_bf_up;

  if(b_pwm>255){
    b_pwm=255;
  }
  if(b_pwm<0){
    b_pwm=0;
    }
      if(f_pwm>255){
    f_pwm=255;
  }
  if(f_pwm<0){
    f_pwm=0;
    }
  }
void pid_bm_lead()
{
  lead_bm_error = counter3 - counter2;
  lead_bm_derror = lead_bm_error - lead_bm_perror;
  correction_lead_bm = kp_lead_bm * lead_bm_error + kd_lead_bm * lead_bm_derror;
  lead_bm_perror = lead_bm_derror;
  b_pwm = 111 - correction_lead_bm;
  m_pwm = 220 + correction_lead_bm;
    if(b_pwm>255){
    b_pwm=255;
  }
  if(b_pwm<0){
    b_pwm=0;
    }
      if(m_pwm>255){
    m_pwm=255;
  }
  if(m_pwm<0){
    m_pwm=0;
    }
}

void pid_bf_lead()
{
  lead_bf_error = counter3 - counter1;
  lead_bf_derror = lead_bf_error - lead_bf_perror;
  correction_lead_bf = kp_lead_bf * lead_bf_error + kd_lead_bf * lead_bf_derror;
  lead_bf_perror = lead_bf_derror;
  b_pwm = 111 - correction_lead_bf;
  f_pwm = 110 + correction_lead_bf;
    if(b_pwm>255){
    b_pwm=255;
  }
  if(b_pwm<0){
    b_pwm=0;
    }
      if(f_pwm>255){
    f_pwm=255;
  }
  if(f_pwm<0){
    f_pwm=0;
    }
}

void ai2() {
  if (digitalRead(b2) == !digitalRead(a2))
  {
    counter2--;
  } else {
    counter2++;
  }
}

////////////////////////////////////////////////////////////////////////////

void ai1() {
  if (digitalRead(b1) == !digitalRead(a1))
  {
    counter1++;
  } else {
    counter1--;
  }
}


/////////////////////////////////////////////////////////////////////////////


void ai3() {
  if (digitalRead(b3) == !digitalRead(a3))
  {
    counter3++;
  } else {
    counter3--;
  }
}

//////////////////////////////////////////////////////////////////////////////




void middle_lead_up(int b)
{
  digitalWrite(m, HIGH);
  analogWrite(pwmm, b);
}


/////////////////////////////////////////////////
void middle_lead_down(int a)
{
  digitalWrite(m, LOW);
  analogWrite(pwmm, a);
}

//////////////////////////////////////////////////
void front_lead_up(int c)
{
  digitalWrite(f, HIGH);
  analogWrite(pwmf, c);
}

/////////////////////////////////////////////////////////////////
void front_lead_down(int d)
{
  digitalWrite(f, LOW);
  analogWrite(pwmf, d);
}

///////////////////////////////////////////////////////////////////

void back_lead_up(int e)
{
  digitalWrite(b, HIGH);
  analogWrite(pwmb, e);
}

////////////////////////////////////////////////////////////////////////
void back_lead_down(int f)
{
  digitalWrite(b, LOW);
  analogWrite(pwmb, f);
}





////////////////////////////////////////////////////////////


void stopbot()
{
  analogWrite(pwm2, 0);
  analogWrite(pwm1, 0);
  analogWrite(pwm3, 0);
  analogWrite(pwm4, 0);
  analogWrite(pwmm, 0);
  analogWrite(pwmb, 0);
  analogWrite(pwmf, 0);
}

#include <PS3BT.h>



#include <usbhub.h>
// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#include <SPI.h>
#endif






//////////////    PS3
USB Usb;

//(PS3BT)
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so
///* You can create the instance of the class in two ways */
//PS3BT PS3(&Btd); // This will just create the instance
PS3BT PS3(&Btd, 0x00, 0x1B, 0x10, 0x00, 0x17, 0xD9);
void setup()
{
 
Serial.begin(9600);//

  ps3_init();
  pingTimer[0] = millis() + 30; //first ping start in ms
  for (uint8_t i = 1; i < SONAR_NUM; i++)
    pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
  while (millis() < 2000)
  {
    pingdistance();
  }
    for(int i=0;i<1000;i++)
  { IMU.readGyroData(gyro);
    
    s+=gyro[2];
  }
  s=s/1000;

   IMU.readGyroData(gyro);
  dt = micros() - Time;
  angle += (gyro[2]-s)*dt/131.0/1000000.0;
  Time = micros();
  first_reading=angle;  
//  Serial.println("fr");
//  Serial.println(first_reading);
   angle=angle-first_reading;
   
  Serial3.begin(115200);
   

  pinMode(fr, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(fl, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(br, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(bl, OUTPUT);
  pinMode(pwm4, OUTPUT);
  pinMode(sig, OUTPUT);

  pinMode(f_bump, INPUT); //bump
  pinMode(m_bump, INPUT); //bump
  pinMode(b_bump, INPUT); //bump

  pinMode(a1, INPUT_PULLUP);
  pinMode(b1, INPUT_PULLUP);
  pinMode(f, OUTPUT);
  pinMode(pwmf, OUTPUT);
  pinMode(a2, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(m, OUTPUT);
  pinMode(pwmm, OUTPUT);
  pinMode(a3, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b, OUTPUT);
  pinMode(pwmb, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(a1), ai1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(a2), ai2, CHANGE);
  attachInterrupt(digitalPinToInterrupt(a3), ai3, CHANGE);

  pinMode(x,INPUT_PULLUP);
  pinMode(y,INPUT_PULLUP);
  pinMode(z,INPUT_PULLUP);
  pinMode(r,INPUT_PULLUP);
  pinMode(d,INPUT_PULLUP);
  pinMode(solenoid,OUTPUT);
  digitalWrite(solenoid,HIGH);
}


int number_harvestor = 0;


void correctangle()
{
  getgyro();
  angle_error = angle;
  angle_derror = angle_error  - angle_perror ;
  angle_perror = angle_error ;
  angle_correction = angle_kp * angle_perror + angle_kd * angle_derror;
  Serial.println("angle_correction");
  Serial.println(angle_correction);

}

void correctultra()
{
  if (fldistance > 0 && bldistance > 0 && number_harvestor == 0)
  {
    velocity_error = int((bldistance) - (fldistance));
    velocity_derror = velocity_error - velocity_perror;
    velocity_correction = kp_velocity * velocity_error + kd_velocity * velocity_derror;
    velocity_perror = velocity_error;

    dis_correction = 0;
    dis_error = 10 - (int(fldistance + bldistance) / 2);
    dis_derror = dis_error - dis_perror;
    dis_correction = kp_dis * dis_error + kd_dis * dis_derror;
    dis_perror = dis_error;
  }
  else if (frdistance > 0 && brdistance > 0 && number_harvestor == 1)
  {
    velocity_error = int(frdistance) - (brdistance);
    velocity_derror = velocity_error - velocity_perror;
    velocity_correction = kp_velocity * velocity_error + kd_velocity * velocity_derror;
    velocity_perror = velocity_error;

    dis_correction = 0;
    dis_error = -50 + (int(frdistance + brdistance) / 2);
    dis_derror = dis_error - dis_perror;
    dis_correction = kp_dis * dis_error + kd_dis * dis_derror;
    dis_perror = dis_error;
  }
//  Serial.print("velerror=");
//  Serial.println(velocity_error);
//  Serial.print("disterror=");
//  Serial.println(dis_error);
}

void straight()
{
//  Serial.println("abcde3");
  //    if(angle!=0)
  //    {
  correctangle();
  //    }
  correctultra();
  correction = (angle_correction + velocity_correction) / 2;
  Serial.println("correction");
  Serial.println(correction);

  v1 = 120 - correction - dis_correction; //110
  v2 = 120+ correction + dis_correction;
  v3 = 120 - correction - dis_correction; //100
  v4 = 120 + correction + dis_correction; //100


  if (v3 > 255) {
    v3 = 255;
  }
  if (v4 > 255) {
    v4 = 255;
  }
  if (v1 > 255) {
    v1 = 255;
  }
  if (v2 > 255) {
    v2 = 255;
  }
  if (v3 < 0) {
    v3 = 0;
  }
  if (v4 < 0) {
    v4 = 0;
  }
  if (v1 < 0) {
    v1 = 0;
  }
  if (v2 < 0) {
    v2 = 0;
  }
  //    Serial.println("v1");
  //    Serial.println(v1);
  //    Serial.println("v2");
  //    Serial.println(v2);
  //    Serial.println("v3");
  //    Serial.println(v3);
  //    Serial.println("v4");
  //    Serial.println(v4);
frontwheel_forward(v1,v2);
backwheel_forward(v3,v4);
}

void rotateleft(int b)
{
  //   Serial.println("xyz");
  getgyro();
  if (angle < 30)
  {
    digitalWrite(fr, HIGH);
    analogWrite(pwm1, 100);
    digitalWrite(br, HIGH);
    analogWrite(pwm3, 100);
    digitalWrite(fl, LOW);
    analogWrite(pwm2, 40);
    digitalWrite(bl, LOW);
    analogWrite(pwm4, 40);
  }
  else if (angle >= 30 && angle <= b)
  {
    digitalWrite(fr, HIGH);
    analogWrite(pwm1, 130);
    digitalWrite(br, HIGH);
    analogWrite(pwm3, 130);
    digitalWrite(fl, LOW);
    analogWrite(pwm2, 100);
    digitalWrite(bl, LOW);
    analogWrite(pwm4, 100);
  }

}

void rotateright(int a,int b)
{
//  Serial.println("xyz");
  getgyro();
  if (angle > a)
  {
    digitalWrite(fl, HIGH);
    analogWrite(pwm2, 100);
    digitalWrite(bl, HIGH);
    analogWrite(pwm4, 100);
    digitalWrite(fr, LOW);
    analogWrite(pwm1, 40);
    digitalWrite(br, LOW);
    analogWrite(pwm3, 40);
  }
  else if (angle <= a && angle >= b)
  {
    digitalWrite(bl, HIGH);
    analogWrite(pwm4, 130);
    digitalWrite(fl, HIGH);
    analogWrite(pwm2, 130);
    digitalWrite(fr, LOW);
    analogWrite(pwm1, 100);
    digitalWrite(br, LOW);
    analogWrite(pwm3, 100);
  }

}


 
int number_seeder = 0;


int number_sensor=0;

 

 
void loop()
{
Serial.print(manual_mode);
Serial.print("   ");
Serial.println(auto_mode);
ps3();//
//check_ps3();
if(PS3.getButtonClick(L1)&&harvester1==0)
{
  harvester1=1;
  }
  else if(PS3.getButtonClick(L1)&& harvester1==1)
  {
    harvester1=0;}
    if(harvester1==0)
    {
      digitalWrite(f,HIGH);
      analogWrite(pwmf,0);
      }
      else if (harvester1==1)
      {
       digitalWrite(f,HIGH);
      analogWrite(pwmf,100); }
      if(PS3.getButtonClick(R1)&&seeder1==0)
{
 seeder1=1;
  }
  else if(PS3.getButtonClick(R1)&& seeder1==1)
  {
    seeder1=0;}
    if(seeder1==0)
    {
      digitalWrite(b,HIGH);
      analogWrite(pwmb,0);
      }
      else if (seeder1==1)
      {
       digitalWrite(b,HIGH);
      analogWrite(pwmb,100); }
      

if (PS3.getButtonClick(SELECT)&&manual_mode==0)
{
  manual_mode=1;
  auto_mode=0;
  }
 else if (PS3.getButtonClick(START)&&manual_mode==1)
{
  manual_mode=0;
  auto_mode=1;
  }
  if(auto_mode==1&&manual_mode==0)
  {
  value_fbump=digitalRead(f_bump);
  value_bbump=digitalRead(b_bump);
  value_mbump=digitalRead(m_bump);
  pingdistance();

 if(digitalRead(d)==LOW )
  {
   // Serial.println("downstair");
     downstair();
     
  }

   else if(digitalRead(y)==LOW)
  {
     //Serial.println("upstair");
    upstair();
  }
    else if( digitalRead(z)==LOW)
  {
     //Serial.println("wallfollowseeder");
    wallfollow_seeder();
  }
      else if(digitalRead(x)==LOW)
  {
    //Serial.println("wallfollowsensor");
    wallfollow_sensor();
  }

    else if( digitalRead(r)==LOW)
  {
    //Serial.println("wallfollow_downstair");
    wallfollow_downstair();
  }

  else
  {
//      Serial.println("stopbot");
    stopbot();
  }
//  Serial.println(f_bump);
//  wallfollow();
//  upstair();
//Serial.println("counter1");
//Serial.println(counter1);
//Serial.println("counter3");
//Serial.println(counter3);
  }
  else if(manual_mode==1&&auto_mode==0)
  {
//forward movement code
if(PS3.getButtonClick(UP))
{manual_speed+=10;}
else if(PS3.getButtonClick(DOWN))
{
manual_speed-=10;  
}
if(PS3.getButtonClick(RIGHT))
{lead_speed+=10;}
else if(PS3.getButtonClick(LEFT))
{
lead_speed-=10;  
}
if(PS3.getButtonClick(TRIANGLE))
{
 // assign first lead screw pins to controlled lead screw
 lead1=f;
 lead1_pwm=pwmf;
 lead2=f;
 lead2_pwm=pwmf;
  }
  else if(PS3.getButtonClick(SQUARE))
  {
   //assign middle slider 
   lead1=m;
 lead1_pwm=pwmm;
 lead2=m;
 lead2_pwm=pwmm;
    }
    else if(PS3.getButtonClick(CROSS))
    {
      //assign last lead screw pins
      lead1=b;
 lead1_pwm=pwmb;
 lead2=b;
 lead2_pwm=pwmb;
      }
      else if (PS3.getButtonClick(CIRCLE))
      {
        lead1=f;
 lead1_pwm=pwmf;
 lead2=b;
 lead2_pwm=pwmb;//assign bot lead screw front and backward
        }
 if(PS3.getAnalogHat(LeftHatY) > 137)
{digitalWrite(lead1, LOW);
  analogWrite(lead1_pwm, lead_speed);
  digitalWrite(lead2, LOW);
  analogWrite(lead2_pwm, lead_speed);
  }
  else if(PS3.getAnalogHat(LeftHatY) < 117)
{digitalWrite(lead1, HIGH);
  analogWrite(lead1_pwm,lead_speed);
  digitalWrite(lead2, HIGH);
  analogWrite(lead2_pwm, lead_speed);
  }
  else
  {
    digitalWrite(lead1, HIGH);
  analogWrite(lead1_pwm, 0);
  digitalWrite(lead2, HIGH);
  analogWrite(lead2_pwm, 0);
    }
  
if(PS3.getAnalogHat(RightHatY) > 137)
{digitalWrite(br, LOW);
  analogWrite(pwm3, manual_speed);
  digitalWrite(bl, LOW);
  analogWrite(pwm4, manual_speed);
  digitalWrite(fr, LOW);
  analogWrite(pwm1, manual_speed);
  digitalWrite(fl, LOW);
  analogWrite(pwm2, manual_speed);}
  //backward movement code
else if(PS3.getAnalogHat(RightHatY) < 117)
{
 digitalWrite(br, HIGH);
  analogWrite(pwm3, manual_speed);
  digitalWrite(bl, HIGH);
  analogWrite(pwm4,manual_speed);
  digitalWrite(fr, HIGH);
  analogWrite(pwm1, manual_speed);
  digitalWrite(fl, HIGH);
  analogWrite(pwm2, manual_speed); }
  
  //right Turn code
  else if (PS3.getAnalogButton(R2)>150)
{
 digitalWrite(br, LOW);
  analogWrite(pwm3,manual_speed);
  digitalWrite(bl, HIGH);
  analogWrite(pwm4, manual_speed);
  digitalWrite(fr, LOW);
  analogWrite(pwm1, manual_speed);
  digitalWrite(fl, HIGH);
  analogWrite(pwm2, manual_speed); }
  else if (PS3.getAnalogButton(L2)>150)
{
 digitalWrite(br, HIGH);
  analogWrite(pwm3, manual_speed);
  digitalWrite(bl,LOW);
  analogWrite(pwm4, manual_speed);
  digitalWrite(fr,HIGH);
  analogWrite(pwm1, manual_speed);
  digitalWrite(fl, LOW);
  analogWrite(pwm2,manual_speed); }
  
  else
  {
    digitalWrite(br, HIGH);
  analogWrite(pwm3, 0);
  digitalWrite(bl, HIGH);
  analogWrite(pwm4, 0);
  digitalWrite(fr, HIGH);
  analogWrite(pwm1, 0);
  digitalWrite(fl, HIGH);
  analogWrite(pwm2, 0); }
    
    }

}
void  ps3()
{
  Usb.Task();
}
void ps3_init()
{
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USb CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 bluetooth Library Started"));
}
 
