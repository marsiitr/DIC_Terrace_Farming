# DIC_Terrace_Farming
## Inter IIT Tech Meet 2019

![alt text](https://github.com/visvash/DIC_Terrace_Farming/blob/master/Images%20and%20Videos/Images/Team%20Photo.jpg "Team MaRS @Inter IIT Tech-meet 8.0")

### Abstract:
MaRS IIT Roorkee has developed an autonomous bot to perform agricultural tasks for terrace farming. This
bot can perform functionalities like seeding, watering, ploughing and harvesting of the crops. It is itself
unique in a way that the bot can climb up and down the manmade steps in the terrace farming.

![alt text](https://github.com/visvash/DIC_Terrace_Farming/blob/master/Images%20and%20Videos/Images/Final%20Bot%20View%201.jpg "Terrace Farming Robot")

To view more images of the final bot, click [here.](https://github.com/visvash/DIC_Terrace_Farming/tree/master/Images%20and%20Videos/Images "DIC_Terrace_Farming_Robot")



### Challenges faced in Terrace Farming:
* Narrow terraces make it difficult for the farmers to navigate. These also prevent the use of heavy machinery or animal power thus the farmers have to rely on locally made agricultural tools which are appropriate to narrow terraces. The use of improper tools and methods lead to poor yields.
* Improper irrigation methods and shortage of watering systems hamper the growth of the crops.
* Wider terraces demand the use of draft animals as a source of farm power. Sometimes farmers are compelled to use manual labour even for ploughing.
* Steeper slopes make it difficult for the farmers to mobilise the farming tools. It drastically increases the labour demand and hence increasing the cost of production.

## Mechanical Aspects of the Design

### Traversal
* The bot uses 4-wheel differential drive to traverse on the soil surface. Two central idler wheels are provided for extra stability while climbing the steps and traversing on uneven surfaces.
* For this drive we are using Mega Torque Planetary DC geared motor of 300RPM and torque capacity of 92kg-cm, enough to carry out tasks like Ploughing and Seeding. The chassis of bot is made up of square steel pipes, arc welded together for rigidity.

### Climbing
* We divided bot into 3-wheel assemblies in which front and back are containing 2 wheels, 2 motors and a lead screw but the middle assembly contains 4 caster wheels and a lead screw so that the bot does not topple, while one of the front or back wheel assemblies is in the air.
* In the first step, the whole body will be lifted by actuating the lead screws of middle and rear wheel assemblies. Then the bot will move forward until the front wheels rest above the step.
* In the second step, the Middle Caster Wheels will be pulled back up and the bot will move forward by actuating the back wheels to rest on the stair on front and middle wheels.
* In the last step, the back wheels will be pulled up, this time the front wheels will be actuating and it will move the bot forward and the bot would have climbed up.
* The bot also has an ability to lift itself above the crop for traversing in the field.

![alt text](https://github.com/visvash/DIC_Terrace_Farming/blob/master/Images%20and%20Videos/Images/Downstair%20Motion%20Process.jpeg "Climbing Process")

### Ploughing
* The thickness of Topsoil for cultivation in terraces is less in comparison to that of plains and we can encounter stones while deep ploughing.
* Using a Disc Harrow mechanism for shallow ploughing would be more appropriate and will save the Tool from wear and tear. Simultaneously it will use less Power per unit area.
* A special concave disk having an angle of curvature of around 15-25 degrees has been used. This angle determines the ploughing depth. More the angle more is the depth of plough and more is the power to drive the operation.
* The discs also maintain an angle of 40-45 degrees with the direction of travel which helps it in rotation and opening of the soil by scooping it out simultaneously.

![alt text](https://github.com/visvash/DIC_Terrace_Farming/blob/master/Mechanical%20Design/Images/PLOUGH/Plough%20Prototype.PNG "Plough")

### Watering
* The bot will have a solenoid-valve for electronically controlling the water given to the crops. 
* The concept of the watering mechanism is designed so as to minimize the water consumption along with maintaining the net yield.

![alt text](https://github.com/visvash/DIC_Terrace_Farming/blob/master/Mechanical%20Design/Images/WATERING/Watering%20Mechanism%20Labelled%20Design.png "Watering Mechanism Design")

### Seeding
* For dropping the seeds, a seed tank is attached on the bot that directs the seeds to the outlet pipes using 3D printed discs controlled by Johnson type DC motor. The tank contains 3 circular disc-like structures with grooves in them. These discs are rotated by the motor.
* The tank is divided into two-compartments, one compartment contains the seed and the other compartment contains the outlet. When the motor rotates the disc, the seeds are trapped in the grooves and are transferred to the next compartment. The seeds then fall to the ground through the outlet.
* Cultivator is mounted at the bottom along with outlet pipes at their back so they easily drop off seeds in the tillage so formed.

### Harvesting
• Harvester consists of 2 cutting blade, operated by a geared DC motor using Spur Gears.<br>
• Both the blades will rotate with the same speed but in opposite direction, the blades share a common
cutting area which will ensure cutting of crop which comes in between them.<br>
• The harvester can be detached and can be mounted on bot when required.

![alt text](https://github.com/visvash/DIC_Terrace_Farming/blob/master/Mechanical%20Design/Images/HARVESTOR/Harvester%201.jpg "Harvester")


## Electronic Aspects of the Bot
### Sensors Used
#### ULTRASONIC SENSOR: 
8 such sensors are used.<br>

#### SOIL MOISTURE SENSOR:
1 moisture sensor is used to take data inputs from the cultivated land.
#### TEMPERATURE SENSOR: 
1 temperature sensor is used to get the temperature data from the field.
#### ROTARY ENCODER: 
3 rotary encoders is used to keep track of the lead screws during their operation. The DC motors used for the traversing of the bot has inbuilt encoders.
#### MPU 9250: 
1 such sensor is used. It contains gyroscope, accelerometer and magnetometer. It is used to maintain the orientation of the bot.
#### BUMP SENSOR: 
4 bump sensors are used to determine the state of the bot in certain manoeuvres.
#### HALL SENSOR: 
Hall sensor is used to measure the distance travelled by the bot. Encoder cannot be used on the ground wheels as the wheel can slip on the ground which will result in wrong measurements.

### Micro-Controller
The microcontroller of the bot is the brain of the bot. Each and every function and maneuverer of the bot is
controlled by a microcontroller. It also helps the bot take decisions and decides the further course of
action. We have used Arduino Mega microcontroller board which depends on AT Mega microcontroller.
It includes digital input/output pins-54, where 16 pins are analogue inputs, 14 are used like PWM outputs hardware
serial ports **(UARTs)** – 4, a crystal oscillator-16 MHz, an ICSP header, a power jack, a USB connection, as well as
a RST button. This board mainly includes everything which is essential for supporting the microcontroller. So, the
power supply of this board can be done by connecting it to a PC using a USB cable, or battery or an AC-DC adapter.
This board can be protected from the unexpected electrical discharge by placing a base plate.

![alt text](https://github.com/visvash/DIC_Terrace_Farming/blob/master/Images%20and%20Videos/Images/Micro%20Controller.PNG "Sample Micro-Controller Image")


## Motor Driver
We have used the Cytron MDD10A which is a dual-channel version of the MDD10C. Like MD10C, MDD10A
also supports locked-antiphase and sign-magnitude PWM signal. 

### The Implication of PID
PID is short for proportional, integral and derivative.
The PID is used to correct the error of the bot while traversing.

The correction value is given as<br>
**Correction = kp(error) + kd(error- previous_error)**
## Working of the IoT (Web Page)
The readings from the different types of sensors (moisture, humidity, temperature etc) will be taken
by a microcontroller and transferred wirelessly to a database. The readings will be stored in the database
using file handling. The files with the reading will be sorted according to the nodes present on field.<br>
All the sensors are connected to the **Arduino AT Mega microcontroller**, which will be responsible for
registering the input data from the sensors. Since Arduino AT-Mega does not have a in-built Wi-Fi or
Bluetooth system, so a **ESP-8266 NODE-MCU** can be used to transfer the data wirelessly to the database.
The transfer of data from Arduino to the esp8266 can take place through interrupt pins, then the esp8266
will create a local server, another python script will run on a device having the database which will read the
data from the esp8266 and store it in a database using file handling. The micro-header named
**ESP_MICRO.h** is a very important header file needed for the esp8266 to transfer the data.<br>
After the data is stored in the database in a sorted manner, we will need to render the files to the web
page which will display the data to the user. 
<br><br>

### Steps and Sequence of execution :-
1) Firstly, ensure proper connection of sensors with the Esp8266.
2) Go to the folder named **IoT codes** present inside the **src** folder.
3) Navigate inside to the **Esp8266 code** folder and Upload the file named **integrated.ino** in the Esp266.
4) Upon running the code in Esp8266, it will generate an URL which needs to copied and pasted in the file named **PYTHON_READER.py**(generally the url remains same if the wifi connection of the Esp is not changed).
5) Run the file named **PYTHON_READER.py** in the ubuntu terminal. (Upon execution, the data from sensors transmitted by Esp8266 will be read and written as a local text file)
6) Finally run the **main.py** in the ubuntu terminal. It will generate an URL.
7) Copy paste the URL in the browser to get to the web page.

Note: The arrangement of the files inside the folder should be same as shown in the folder "IoT codes".<br><br>

### Web-Page
<img src="Images and Videos/Images/web_page.jpg">


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
<br>
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



## Team Members
[Annushree](https://github.com/annushree21)<br>
[Avdesh Kumar Ranwa]()<br>
[Debaditya Barman](https://github.com/ItZ-Debaditya)<br>
[Dhruv Shehgal]( https://github.com/Dhruv1064)<br>
[Naveen Chandra Rai](https://github.com/ncr38)<br>
[Ruchika Guntewar](https://github.com/RuchikaGuntewar)<br>
[Shashi Muchkund](https://github.com/smuchkund)<br>
[Shubham Goyal](https://github.com/shubham491981)<br>
[Tabish Madni](https://github.com/Tmadni)<br>
[Visvash Attri](https://github.com/visvash)<br>

## Mentors
[Anant Shandalya](github.com/Anant-Shandilya)<br>
[Shubhanshu Aggrawal](https://github.com/Shubhanshu07)
