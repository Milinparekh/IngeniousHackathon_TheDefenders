first
 hit the commands into the raspberry pi for the one time setup

sudo apt-get  update
sudo apt-get upgrade

then insatll the motion library in rasoberry pi

sudo apt-get install motion

so you have to change the configuration for interfacing the live webcamera server,,

sudo nano /etc/motion/motion.conf

now set the parameter as followed

framerate 1000
quality 50
streamrate 1000
width 320
height 240
post capture 5
local host off

now enter the command 

sudo nano /etc/moion/motion
 in that make the daemon =yes


then   open the commond prompt temrinal of raspberry pi in that 
 
write the commond

sudo service motion start
sudo motion 

the  open the browser in raspberry pi 

write yur ip address in that  browser ended with the port name

suppose my ip is 
192.168.43.143:8082



and for th another camera  the ip

192.168.43.143:8083


then the screen will be right in front of you for the live camera surveillance through rapsberry pi.

