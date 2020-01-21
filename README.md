# DIC_Terrace_Farming
Inter IIT Tech Meet 2019
# Abstract
MaRS IIT Roorkee has developed an autonomous bot to perform agricultural tasks for terrace farming. This
bot can perform functionalities like seeding, watering, ploughing and harvesting of the crops. It is itself
unique in a way that the bot can climb up and down the manmade steps in the terrace farming.
# Motivation
The UN Food and Agriculture Organization predicts that we need to boost worldwide food production by 70
percent over the next several decades in order to feed the anticipated population of 2050. Many regions in
India are hilly with sparse crop production, which with proper planning can be graded to better agricultural
spots.
Terrace farming is widely practiced in India in the states of Meghalaya, Uttarakhand, Himachal
Pradesh and Haryana. Among the 34 million people inhabitant in the Himalayan region, a large percentage of
the population are dependent on hill farming. 15.8 percent of the total area of Himalayas i.e. 53.8 million
Hectares are farmlands and 37 percent are sloping lands of various degrees. Being an integral part of the
farming culture in India, the farmers are predominantly facing challenges in practicing the same. This project
aims to provide a technical, cost-effective and reliable solution to the challenges faced by the farmers while
practicing terrace farming.
**The challenges faced in terrace farming are:**
1) Narrow terraces make it difficult for the farmers to navigate. These also prevent the use of heavy
machinery or animal power thus the farmers have to rely on locally made agricultural tools which are
appropriate to narrow terraces. The use of improper tools and methods lead to poor yields.
2) Improper irrigation methods and shortage of watering systems hamper the growth of the crops.
3) Wider terraces demand the use of draft animals as a source of farm power. Sometimes farmers are
compelled to use manual labour even for ploughing.
4) Steeper slopes make it difficult for the farmers to mobilise the farming tools. It drastically increases
the labour demand and hence increasing the cost of production.
# Mechanical Aspect of the Design

## Traversal
• The bot uses 4-wheel differential drive to traverse on the soil
surface. Two central idler wheels are provided for extra stability
while climbing the steps and traversing on uneven surfaces.<br>
• For this drive we are using Mega Torque Planetary DC geared motor
of 300RPM and torque capacity of 92kg-cm, enough to carry out
tasks like Ploughing and Seeding. The chassis of bot is made up of
square steel pipes, arc welded together for rigidity.

## Climbing
• We divided bot into 3-wheel assemblies in which front and back are containing 2 wheels, 2 motors
and a lead screw but the middle assembly contains 4 caster wheels and a lead screw so that the bot
does not topple, while one of the front or back wheel assemblies is in the air.<br>
• In the first step, the whole body will be lifted by actuating the lead screws of middle and rear wheel
assemblies. Then the bot will move forward until the front wheels rest above the step.<br>
• In the second step, the Middle Caster Wheels will be pulled back up and the bot will move forward by
actuating the back wheels to rest on the stair on front and middle wheels.<br>
• In the last step, the back wheels will be pulled up, this time the front wheels will be actuating and it
will move the bot forward and the bot would have climbed up.<br>
• The bot also has an ability to lift itself above the crop for traversing in the field.

## Ploughing
• After reading about different Ploughing mechanisms we used Disc Harrow mechanism instead of disc
Plough. Because when we visited fields of “Bhatta Gaon”, we found out that the thickness of Topsoil
for cultivation is less in comparison to that of plains and we can encounter stones while deep
ploughing.<br>
• Using a Disc Harrow mechanism for
shallow ploughing would be more
appropriate and will save the Tool from
wear and tear. Simultaneously it will use
less Power per unit area.<br>
• A special concave disk having an angle of
curvature of around 15-25 degrees has
been used. This angle determines the
ploughing depth. More the angle more is
the depth of plough and more is the power
to drive the operation.<br>
• The discs also maintain an angle of 40-45
degrees with the direction of travel which
helps it in rotation and opening of the soil
by scooping it out simultaneously.

## Watering
• Keeping in mind that a reservoir has already been provided, we are using a pipe with a pump that
will water the crops using the sprinkle irrigation method close to the roots of the crops.<br>
• The bot will have a solenoid-valve for electronically controlling the water given to the crops. The
concept of the watering mechanism is designed so as to minimize the water consumption along with
maintaining the net yield.

## Seeding
• For dropping the seeds, a seed tank is attached on the bot that
directs the seeds to the outlet pipes using 3D printed discs
controlled by Johnson type DC motor. The tank contains 3
circular disc-like structures with grooves in them. These discs
are rotated by the motor.<br>
• The tank is divided into two-compartments, one compartment
contains the seed and the other compartment contains the
outlet. When the motor rotates the disc, the seeds are trapped
in the grooves and are transferred to the next compartment.
The seeds then fall to the ground through the outlet.<br>
• Cultivator is mounted at the bottom along with outlet pipes at
their back so they easily drop off seeds in the tillage so
formed.

## Harvesting
• Harvester consists of 2 cutting blade, operated by a geared DC motor using Spur Gears.<br>
• Both the blades will rotate with the same speed but in opposite direction, the blades share a common
cutting area which will ensure cutting of crop which comes in between them.<br>
• The harvester can be detached and can be mounted on bot when required.

# Electronics aspect of the bot
## Sensors Used
### 1. ULTRASONIC SENSOR: 
8 such sensors are used.<br>
Mainly used to maintain constant distance from wall while
traversing.
### 2. SOIL MOISTURE SENSOR:
1 moisture sensor is used to
take data inputs from the cultivated land.
### 3. TEMPERATURE SENSOR: 
1 temperature sensor is used
to get the temperature data from the field.
### 4. ROTARY ENCODER: 
3 rotary encoders is used to keep
track of the lead screws during their operation. The DC
motors used for the traversing of the bot has inbuilt encoders.
### 5. MPU 9250: 
1 such sensor is used. It contains gyroscope, accelerometer and magnetometer. It is used
to maintain the orientation of the bot.
### 6. BUMP SENSOR: 
4 bump sensors are used to determine the state of the bot in certain manoeuvres.
### 7. HALL SENSOR: 
Hall sensor is used to measure the distance travelled by the bot. Encoder cannot
be used on the ground wheels as the wheel can slip on the ground which will result in wrong
measurements.

## Micro-Controller
The microcontroller of the bot is the brain of the bot. Each and every function and maneuverer of the bot is
controlled by a microcontroller. It also helps the bot take decisions and decides the further course of
action. We have used Arduino Mega microcontroller board which depends on AT Mega microcontroller.
It includes digital input/output pins-54, where 16 pins are analogue inputs, 14 are used like PWM outputs hardware
serial ports **(UARTs)** – 4, a crystal oscillator-16 MHz, an ICSP header, a power jack, a USB connection, as well as
a RST button. This board mainly includes everything which is essential for supporting the microcontroller. So, the
power supply of this board can be done by connecting it to a PC using a USB cable, or battery or an AC-DC adapter.
This board can be protected from the unexpected electrical discharge by placing a base plate.

## Motor Driver
The DC motors used in the bot are being controlled by the microcontroller through a motor driver. A motor
driver enables the Arduino to control over the speed, direction and PWM of the motors.
We have used the Cytron MDD10A which is a dual-channel version of the MDD10C. Like MD10C, MDD10A
also supports locked-antiphase and sign-magnitude PWM signal. It uses full solid-state components that offers
faster response time and eliminates the wear and tear of the mechanical relay. It can support V-motor from
5V to 30VDC. With the pre soldered terminals, and on-board manual/test buttons, you can get started even
without any microcontroller.

### The Implication of PID
PID is short for proportional, integral and derivative. The name comes from the methods on how such
controller deals with disturbances in the system. However, such a controller is only in feedback systems.
The PID is used to correct the error of the bot while traversing.
**Trial and Error Method:** It is a simple method of PID controller tuning. While the system or controller is
working, we can tune the controller. In this method, first, we have to set Ki and Kd values to zero and
increase the proportional term (Kp) until the system reaches to oscillating behaviour. Once it is oscillating,
adjust Ki (Integral term) so that oscillations stop and finally adjust D to get a fast response.
**Process reaction curve technique:** It is an open-loop tuning technique. It produces a response when a step
input is applied to the system. Initially, we have to apply some control output to the system manually and
have to record the response curve. After that, we need to calculate slope, dead time, the rise time of the
curve and finally substitute these values in P, I and D equations to get the gain values of PID terms.<br><br>

PID in our bot is used to correct the error in the path when the bot traverses. In order to run the bot parallel
to a wall, two ultrasonic sensors attached to the side of the bot gives a continuous reading of the distance of
the bot from the wall. Two ultrasonic sensors are used to maintain the orientation. The difference in the
reading of these sensor implies the error the bot has to overcome to maintain proper orientation and path.
This is where the PID comes into play.<br>
The correction value is given as<br>
**Correction = kp(error) + kd(error- previous_error)**
## Working of the IOT (Web Page)
One of the problems faced by the farmers in terrace farming is the lack of data from the land but this feature
of the Agritech bot is the solution to the problem faced. The Agritech robot is envisioned to make the farmers
smart, robust and decrease the human dependency.<br>
The readings from the different types of sensors (moisture, humidity, temperature etc) will be taken
by a microcontroller and transferred wirelessly to a database. The readings will be stored in the database
using file handling. The files with the reading will be sorted according to the nodes present on field. A node
is a region/area on the actual cultivated land whose details can be obtained in order to analyse the condition
of the soil and the crops.<br>
All the sensors are connected to the **Arduino AT Mega microcontroller**, which will be responsible for
registering the input data from the sensors. Since Arduino AT-Mega does not have a in-built Wi-Fi or
Bluetooth system, so a **ESP-8266 NODE-MCU** can be used to transfer the data wirelessly to the database.
The transfer of data from Arduino to the esp8266 can take place through interrupt pins, then the esp8266
will create a local server, another python script will run on a device having the database which will read the
data from the esp8266 and store it in a database using file handling. The micro-header named
**ESP_MICRO.h** is a very important header file needed for the esp8266 to transfer the data.<br>
After the data is stored in the database in a sorted manner, we will need to render the files to the web
page which will display the data to the user. The web page is thus an essential entity here. The web page
contains a responsive replica of the land under cultivation. A basic snapshot of the web page looks like the
picture as shown below.
<br><br>
The table on the right-hand side is the replica of the cultivated land and in our case is the arena for the problem statement. The table is responsive and will respond to the click of the user. Each step is divided into different nodes. It is the region where the Agritech bot will take the readings from the sensors. The user has to click on the submit button on the nodes whose conditions/readings he wants to analyse. The details of the sensor reading will be displayed on the box present on the right-hand side of the web page. The data from the database will be rendered to the website using flask. A note/message can be delivered regarding what can be expected of the readings.

## Traversing
<p> • Traversing occurs with the help of ultrasonic sensors. Which is used to maintain a constant distance
from the wall.<br>
• After starting, the bot will stop successively after a fixed distance and take readings of various
sensors and water the zone accordingly.<br>
• Ploughing will occur automatically as the bot moves.<br>
• After detecting the end of the arena, the bot will take a 180 degree turn in the clockwise direction and
move back to the respective starting zone.<br>
• After detecting red or yellow region, bot will do the required action i.e. climbing up or down the
steps.<br></p>

## Step Up Manoeuvre
• For climbing mechanism, 3 lead screws are actuated using 3 DC motors, which lift the whole body in
3 steps.<br>
• In the first step, the whole body will be lifted by actuating the lead screws of middle and rear wheel
assemblies. Then the bot will move forward until the front wheels rest above the step. A bump sensor
will detect that the front wheels have touched the ground. The front colour sensor will detect the change
  in the zone for the prior part of the bot (yellow to red).<br>
• In the second step, the Middle Wheels will be pulled back up and the bot will move forward to rest on
  the stair on front and middle wheels.<br>
• In the last step, the back wheels will be pulled up and the bot would have climbed up.<br>
• The step-down manoeuvre is the opposite of the step up manoeuvre.<br>
• The bot also has an ability to lift itself above the crop for traversing in the field.<br>

## Cost Structure

 |Component       | Number used  | Cost INR|
 |---|----|---|
 | Planetary Geared Motor    |     4     |   19,996|
  |Arduino Mega 2560     |         1     |    800|
  |Node MCU Esp8266    |           1    |        260|
  |Motor Driver       |            6        |  15,000|
  |Battery            |           3      |  4997|
  |Heavy Duty Wheels   |             4          |    900|
  |Caster Wheels        |           4     |   200|
  |Johnson motor             |  5     |        1996|
  |Rotary Encoder     |             3   |        4497|
  |Ultrasonic Sensor  |             5    |         900|
  |Mpu9250           |             1    |          190|
  |Dht11 temperature  |              1     |     108|
  |Soil Moisture Sensor  |            1    |        75|
  |Bump Sensor           |           4     |        400|
  |Lead screw            |         3       |    2397|
  |Material for Body    |          ----   |        4000|
  |Manufacturing            |      ----  |         3500|
|**Total Cost- **   |     |   **60,216**|


## Future Improvement
### • Weed Detection:
Weed Removal Technology can be a boon for
the farmers because weeds reduce the yield and
quality of crops by competing for nutrients,
water and sunlight. Weeds intensify the pest and
disease problem by serving as alternate host.<br>
They also reduce the efficiency of harvesting
and hence resulting in land value reduction.
Further, removal of weeds can be done by
chemical sprays, that link to a wide range of
human health hazards and environmental pollution.
Removal of weed is a very labor intensive and time-consuming process and thus requires to
be automated.<br>
A **high-resolution camera** is mounted on the bot to capture live feed video. The detection tool uses
machine learning procedure based on support vector machines and blob analysis for effective
classification of weed.<br>
Training of the model is done based on 3 scenarios:<br>
1. Maximum crop sample.
2. Maximum weed sample.
3. Marginal weed and crop sample.

The trained module is expected to achieve a success percentage of 59-95% to detect the weed.

### • Solar Powered:
We are also planning to use the solar power supply to meet all the power demands, so that this bot
becomes accessible to even those regions of the country where electric supply is scarce. This Agritech
bot operates on 12V Li-ion battery which can be charged using solar power.

### Proposal for real life solution
Apart from the technical solution as proposed in this report, there are some other serious measurements that
needs to be undertaken by the government in order to ensure the smooth deployment of the bot.

1. A case study on Japan shows that in 1998 the country faced a steep decline in the percentage of hill
farming, over 3.8 percent of the nation’s farming land was abandoned by 1998. This was due to the
years of neglect and bias against the hill agriculture. The Japan government was able to realise the
gravity of the solution and imposed strict measures to reverse the trend.
2. What has happened in Japan, carries a very important message for the future of hill agriculture in
India. Looking deep inside the Uttarakhand hills, one finds that similar conditions is developing in
several areas of the Indian Himalayas and that hill agriculture in India faces a similar situation sooner
than later.
3. The government should impose a strategic turn around in its agricultural policies to revive the
already declining hill farming. They should also provide subsidies on technological solution which
tends to assist them. Our product also falls under this category. Surveys from Bhatta Gaon proves
that farmers are willing to use modern equipment but they are incapable of affording the such
solutions due to their already less income.<br>
One of the key findings of the survey of Bhatta Gaon is that the height of the steps is very high ranging from
350cm to 480cm. The vertical surface of the steps is irregular and also slanted at an angle of about 5-10
degrees from the perpendicular. These conditions make it very difficult for any logical bot to navigate
between the steps. The degree of manipulation in the bot to climb such high and irregular steps will decrease
the overall efficiency and performance of the bot in performing other agricultural functions. The problem
can be solved by customizing the steps of some degree so that the bot can perform efficiently that is to say
that the steps can be modified to smaller height and regular terrain on the vertical wall.

## Team Members
Annushree<br>
Avdesh Kumar Ranwa<br>
Debaditya Barman<br>
Dhruv Shehgal<br>
Naveen Chandra Rai<br>
Ruchika Guntewar<br>
Shashi Muchkund<br>
Shubham Goyal<br>
Tabish Madni<br>
Visvash Attri<br>

## Mentors
Anant Shandalya<br>
Shubhanshu Aggrawal
