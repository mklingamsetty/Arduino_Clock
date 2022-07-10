#define SEC_IN1 13
#define SEC_IN2 2
#define SEC_IN3 3
#define SEC_IN4 4

#define MIN_IN1 5
#define MIN_IN2 6
#define MIN_IN3 7
#define MIN_IN4 8
 
#define HRS_IN1 9
#define HRS_IN2 10
#define HRS_IN3 11
#define HRS_IN4 12

#define M0_Pro false
#define AT328_Nano true

#if(M0_Pro == true)
#define One_Tick 1 //For 48Mhz
#elif(AT328_Nano == true)
#define One_Tick 1 //For 16Mhz 1 tick  = 4 us; For 8Mhz 1 tick = 8 us;
#endif


#define One_Second (1000000/One_Tick)

class STEPPER
{
  const int step_delay = 10;
  const int Full_Steps = 64; //for 28BYJ-48 stepper motor
  private:
  int Blue_Line;
  int Pink_Line;
  int Yellow_Line;
  int Orange_Line;
  int state;
  int rpm;
  

  public:
  STEPPER(int pin1, int pin2, int pin3, int pin4)
  {
    Blue_Line = pin1;
    Pink_Line = pin2;
    Yellow_Line = pin3;
    Orange_Line = pin4;
    state = 2;

    pinMode(Blue_Line, OUTPUT);
    pinMode(Pink_Line, OUTPUT);
    pinMode(Yellow_Line, OUTPUT);
    pinMode(Orange_Line, OUTPUT);

    digitalWrite(Blue_Line, HIGH);
    digitalWrite(Pink_Line, HIGH);
    digitalWrite(Yellow_Line, HIGH);
    digitalWrite(Orange_Line, HIGH);
  }

  public: void Full_Step_Clockwise(int steps)
  {
    for( int i = 0; i < steps; i++)
    {      
      switch (state)
      {
        case 2:
        { digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line,HIGH);
          
          state = 4;
          delay(step_delay);
          //break;
        }
         case 4:
        {
          digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, LOW);
          digitalWrite(Orange_Line,LOW);
          
          state = 6;
          delay(step_delay);
          //break;
        }
          case 6:
        {
          digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  LOW);
          digitalWrite(Yellow_Line, LOW);
          digitalWrite(Orange_Line,HIGH);
          state = 8;
          delay(step_delay);
          //break;
        }
          case 8:
        {
          digitalWrite(Blue_Line,  LOW);
          digitalWrite(Pink_Line,  LOW);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line,HIGH);
          state = 10;
          delay(step_delay);
          //break;
        }
          case 10:
        {
          digitalWrite(Blue_Line,  LOW);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line, LOW);
          state = 2;
          delay(step_delay);
          break;
        }
        default:
        {
          state = 2;
          break;
        }
      }
    }
   }

  public: void Full_Step_CClockwise(int steps)
  {
    for( int i = 0; i < steps; i++)
    {      
      switch (state)
      {
        case 2:
        {
          digitalWrite(Blue_Line,  LOW);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line, LOW);
          state = 4;
          delay(step_delay);
          //break;
        }
         case 4:
        {
          digitalWrite(Blue_Line,  LOW);
          digitalWrite(Pink_Line,  LOW);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line,HIGH);
          state = 6;
          delay(step_delay);
          //break;
        }
          case 6:
        {
          digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  LOW);
          digitalWrite(Yellow_Line, LOW);
          digitalWrite(Orange_Line,HIGH);
          state = 8;
          delay(step_delay);
          //break;
        }
          case 8:
        {
          digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, LOW);
          digitalWrite(Orange_Line,LOW);
          state = 10;
          delay(step_delay);
          //break;
        }
          case 10:
        {
          digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line,HIGH);
          state = 2;
          delay(step_delay);
          break;
        }
        default:
        {
          state = 2;
          break;
        }
      }
    }
   }

   public: void Half_Step_Clockwise(int steps)
   {
    for(int i = 0; i < steps; i++)
    {
      switch (state)
      {
        case 2:
        {
          digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line,HIGH);
          
          state = 3;
          delay(step_delay);
          //break;
        }
        case 3:
        {
          digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line,LOW);
          
          state = 4;
          delay(step_delay);
          //break;
        }
        case 4:
        {
          digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, LOW);
          digitalWrite(Orange_Line,LOW);
          
          state = 5;
          delay(step_delay);
          //break;
  
        }
        case 5:
        {
          digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, LOW);
          digitalWrite(Orange_Line,HIGH);
          
          state = 6;
          delay(step_delay);
          //break;
        }
        case 6:
        {
          digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  LOW);
          digitalWrite(Yellow_Line, LOW);
          digitalWrite(Orange_Line,HIGH);
          state = 7;
          delay(step_delay);
          //break;
        }
        case 7:
        {
          digitalWrite(Blue_Line,  HIGH);
          digitalWrite(Pink_Line,  LOW);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line,HIGH);
          state = 8;
          delay(step_delay);
          //break;
        }
        case 8:
        {
          digitalWrite(Blue_Line,  LOW);
          digitalWrite(Pink_Line,  LOW);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line,HIGH);
          state = 9;
          delay(step_delay);
          //break;
        }
        case 9:
        {
          digitalWrite(Blue_Line,  LOW);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line,HIGH);
          state = 10;
          delay(step_delay);
          //break;
        }
        case 10:
        {
          digitalWrite(Blue_Line,  LOW);
          digitalWrite(Pink_Line,  HIGH);
          digitalWrite(Yellow_Line, HIGH);
          digitalWrite(Orange_Line, LOW);
          delay(step_delay);
          state = 2;    
          break;
        }
        default:
        {
          state = 2;
          break;
        }
      }
    }   
   }
    
};

class MyClock
{
  private:
  unsigned int seconds, minutes, hours, days, years;

  public:
  MyClock(unsigned int s, unsigned int m, unsigned int h, unsigned int d, unsigned int y)
  {
    seconds = s;
    minutes = m;
    hours = h;
    days = d;
    years = y;
  }

  void increment_seconds(void)
  {
    //increment seconds
    seconds++;

    //if seconds is greater than a minute
    if(seconds >= 60)
    {
      //make seconds = 0            
      seconds = 0;
      
      minutes++;
      if(minutes >= 60)
      {
        minutes = 0;
        hours++;
        if(hours >= 24)
        {
          hours = 0;
          days++;
          if(days >= 364)
          {
            days = 0;
            years++;
          }
        }
      }
    } 
  }
  
  unsigned long getTime(void)
  {
    unsigned long temp = 0;
    temp = days;
    temp = temp << 8;
    temp |= hours;
    temp = temp << 8;
    
    temp |= minutes;
    temp = temp << 8;
    temp |= seconds;

    return temp;
  }

  unsigned int getMins(void)
  {
    return minutes;
  }

    unsigned int getHrs(void)
  {
    return hours;
  }
  
};

unsigned long time1 = 0;
unsigned long time2 = 0;
unsigned int mins_counter = 0;
unsigned int hrs_counter = 0;

STEPPER sec_stepper(SEC_IN1, SEC_IN2, SEC_IN3, SEC_IN4); //digital pins 1, 2, 3, 4
STEPPER min_stepper(MIN_IN1, MIN_IN2, MIN_IN3, MIN_IN4); //digital pins 5, 6, 7, 8
STEPPER hrs_stepper(HRS_IN1, HRS_IN2, HRS_IN3, HRS_IN4); //digital pins 9, 10, 11, 12

MyClock myClock(0, 0, 0, 0, 0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("I began");
  time1 = 0; //micros();
   
}

void loop()
{
  String message = " ";
  unsigned long currentTime = 0;

  //Get current timestamp
  time2 = micros();

  // if time difference is greater than 1s( 1s = 1000000 * 1 ms)
  if((time2 - time1) >= One_Second)
  {
    //save timestamp        
    time1 = time2; 

    //increment seconds
    myClock.increment_seconds();

    //run stepper motor clockwise (each full step takes 5 states * 10ms = 50ms delay)
    sec_stepper.Full_Step_CClockwise(2);
    

    //get current time
    currentTime = myClock.getTime();

    //run minutes stepper motor after each minute passes;
    if((myClock.getMins() != mins_counter))
    {
      mins_counter = myClock.getMins();

      //run the minutes stepper 
      min_stepper.Full_Step_Clockwise(1); //(each full step takes 5 states * 10ms = 50ms delay)  

      //run the hours stepper by half step
      hrs_stepper.Half_Step_Clockwise(1); //(each full step takes 10 states * 10ms = 100ms delay) 
    }

    //compose a time message
    message = "TIME: ";
    message += currentTime >> 24;
    message += ":";
    message += ((currentTime >> 16) & 0xFF);    
    message += ":";
    message += ((currentTime >> 8) & 0xFF);
    message += ":";
    message += ((currentTime >> 0) & 0xFF);

    //Display on serial port
    Serial.println(message);   
  }
  
}
