import processing.serial.*;
Serial myPort;
String val;
int range,i=0;float pos;
void setup(){
 size(550,500);
  
  String portName = "COMx";//x=your arduino port number
  myPort = new Serial(this, portName, 115200);
  background(255);
}
void draw(){
 if ( myPort.available() > 0) {
  val = myPort.readStringUntil('\n');   
  if(val!=null)
  {    String[] nums=split(val,"p");//splitting the recevied data searated by 'p'
          if(nums.length==3)
     {
     range=int(nums[0]); //string to integer conversion 
     pos=float(nums[1]);
     i=int(nums[2]);
    if(i==180){
  background(255);
     }
      }
  }
}
translate(25,-50);
line(250,500,250-2*(range*cos(pos)),500-2*(range*sin(pos))); 
}