// Soccer Droids Team 21 
// z5248147 
// Author: HaohengDuan
// This program is used to control a robot to kick the
// ball, defend the goal and play as a part of a team.
// 11/11/2019


#include <Pixy2.h> //Add the Pixy Library to the program
Pixy2 pixy;



#define LEFT_SIDE 148
#define RIGHT_SIDE 168



int first_engine = 10;
int first_engine_01 = 8;
int first_engine_02 = 9;
int second_engine = 5;
int second_engine_01 = 7;
int second_engine_02 = 6;
int charge_piston = 2;
int fire_piston = 3;
int diffence_or_offence = 4;
bool check_movement = false; 
//indicator for if the robot is currently moving
long time_after_fired = 0; //time since fired




//Initialisation

void setup() {
    Serial.begin(9600);
    //Print pin locations into serial monitor
    Serial.println("Pin 2 and 3 are for piston");
    Serial.println("Pin 4 is for the switch");
    Serial.println("Pin 5 to 10 are for motors");
    Serial.println("Pin A4 and A5 are for Pixy");
    
    

    //Initialise pin settings
    //motor strength
    pinMode(first_engine, OUTPUT); //integer [0,255]
    pinMode(second_engine, OUTPUT); //integer [0,255]
    //motor directionals
    pinMode(first_engine_01, OUTPUT);
    pinMode(first_engine_02, OUTPUT);
    pinMode(second_engine_01, OUTPUT);
    pinMode(second_engine_02, OUTPUT);
    //Set startup defaults
    analogWrite(first_engine, 0);
    analogWrite(second_engine, 0);
    digitalWrite(first_engine_01, LOW);
    digitalWrite(first_engine_02, LOW);
    digitalWrite(second_engine_01, LOW);
    digitalWrite(second_engine_02, LOW);

    //Verify initialisation of Pixy
    Serial.println("Camera is initialising...");
    pixy.init();
    Serial.println("Pixy is Initialised.");

    //Initialise piston activator pins
    pinMode(charge_piston, OUTPUT);
    pinMode(fire_piston, OUTPUT);
    //Set default states
    digitalWrite(charge_piston, HIGH);
    digitalWrite(fire_piston, LOW);

    //Initialise defence/offense signal pin
    pinMode(diffence_or_offence, INPUT); //HIGH = offence LOW = defence

}



//Main Loop

void loop() {
    
    //Begin charging capacitor
    time_after_fired++; //start counting how long its been since firing
    digitalWrite(charge_piston, HIGH);
    //Check if switch is set to defence or offence  
    int present_mode = digitalRead(diffence_or_offence);

    if (present_mode = LOW) {
        defence_mode();
    } else if (present_mode = HIGH) {
        offence_mode();
    }
}



void offence_mode() {
    //Check if ball has been detected
    detect_ball();
    if (detect_ball() == false) {
        spin_clockwise(); //run find ball routine
        check_movement = false; //tell system it isn't currently moving
    } else if (detect_ball() != false) {
        int position = ball_position();
        //Centre ball with error of +-10 pixels
        if (position < LEFT_SIDE) {
            if (check_movement == false) {
                turn_anticlockwise();
            } else if (check_movement == true) {
                turn_left();
            }
        } else if (position > RIGHT_SIDE) {
            if (check_movement == false) {
                turn_clockwise();
            } else if (check_movement == true) {
                turn_right();
            }
        } else if (position >= LEFT_SIDE && position <= RIGHT_SIDE) { 
            //if centred move forward and begin checking distance of ball
            wheel_forward(); //move ball forward
            check_movement = true; //tell system it is currently moving
            int distance = ball_distance();
            if (distance >= 50 && time_after_fired > 40) { 
                //if ball comes close enough kick it and 
                //capacitor is charged **NEEDS TO BE TUNED**
                piston_launch();        
            }
        }
    }
}




void defence_mode() {
    //find the ball
    detect_ball();
    if (detect_ball() == false) {
        spin_clockwise; //find ball routine
    } else if (detect_ball() == true) { //if ball is found
        int position = ball_position(); //find out where the ball is
        //keep ball in centre of camera
        if (position < LEFT_SIDE) {
            turn_anticlockwise();
        } else if (position > RIGHT_SIDE) {
            turn_clockwise();
        } else if (position >= LEFT_SIDE && position <= RIGHT_SIDE) { 
            //wait until ball is 300mm away
            int distance = ball_distance();
            if (distance <= 79) { //**NEEDS TO BE TUNED TO 300mm
                full_power_forwards(); //charge at the ball
                delay(300);
                turn_clockwise(); 
                delay(500); //**NEEDS TO BE TUNED TO A HALF TURN
                wheel_forward();
                delay(400); //**NEEDS TO BE TUNED TO HOW FAR IT TRAVELLED
                turn_off_wheels();
                delay(5000);
            }
        }
    }
    
    
}







//Is the ball on screen?

bool detect_ball() {
    //Locals
    bool outcome = false;


    //Scan for signature blocks
    pixy.ccc.getBlocks();

    //Enumerate any blocks
    int i = 0
    while (i < pixy.ccc.numBlocks) {
        //Is it the ball
        if (pixy.ccc.blocks[i].m_signature == 1) {
            outcome = true;
        }
        i++;
    }

    return outcome;
}






//Ball distance judged by width of detected block [0,316]

int ball_distance() {
    //Locals
    int distance = 2;

    //Get blocks
    pixy.ccc.getBlocks();

    //Determine how wide block is
    int i=0;
    while (i < pixy.ccc.numBlocks) {
        distance = pixy.ccc.blocks[i].m_width;
        i++;
    }
    return distance;
}




//Ball location by position [0,316]

int ball_position() {
    //Locals
    int position = 0;

    //Get blocks
    pixy.ccc.getBlocks();

    //Determine where the ball in on the x-axis
    int i = 0;
    while (i < pixy.ccc.numBlocks) {
        position = pixy.ccc.blocks[i].m_x; 
        i++;
    }
    return position;
}







//WHEEL POWER PROFILES


//Move forward
void wheel_forward() {
    //Set motor speeds to medium speed
    analogWrite(first_engine, 200);
    analogWrite(second_engine, 200);
    //Set both wheels to forward
    digitalWrite(first_engine_01, HIGH);
    digitalWrite(first_engine_02, LOW);
    digitalWrite(second_engine_01, HIGH);
    digitalWrite(second_engine_02, LOW);
}





//Turn wheels off
void turn_off_wheels() {
    //Set motor speeds to zero
    analogWrite(first_engine, 0);
    analogWrite(second_engine, 0);
    //Set all outputs to LOW
    digitalWrite(first_engine_01, LOW);
    digitalWrite(first_engine_02, LOW);
    digitalWrite(second_engine_01, LOW);
    digitalWrite(second_engine_02, LOW);
}



//Full power forward
void full_power_forwards() {
    //Set motor speeds to maximum speed
    analogWrite(first_engine, 255);
    analogWrite(second_engine, 255);
    //Set both wheels to forward
    digitalWrite(first_engine_01, HIGH);
    digitalWrite(first_engine_02, LOW);
    digitalWrite(second_engine_01, HIGH);
    digitalWrite(second_engine_02, LOW);
}






//Inch right
void turn_right() {
    //Reduce power in right wheel
    analogWrite(first_engine, 200);
    analogWrite(second_engine, 150);
    //Make sure both wheels are forward
    digitalWrite(first_engine_01, HIGH);
    digitalWrite(first_engine_02, LOW);
    digitalWrite(second_engine_01, HIGH);
    digitalWrite(second_engine_02, LOW);  
}




//Inch left
void turn_left() {
    //Reduce power in left wheel
    analogWrite(first_engine, 150);
    analogWrite(second_engine, 200);
    //Make sure both wheels are forward
    digitalWrite(first_engine_01, HIGH);
    digitalWrite(first_engine_02, LOW);
    digitalWrite(second_engine_01, HIGH);
    digitalWrite(second_engine_02, LOW);
}



//Spin clockwise
void spin_clockwise() {
    //Set slower speed for both motors so ball isn't blurry
    analogWrite(first_engine, 50);
    analogWrite(second_engine, 50);
    //Set forward for motor A
    digitalWrite(first_engine_01, HIGH);
    digitalWrite(first_engine_02, LOW);
    //Set backward for motor B
    digitalWrite(second_engine_01, LOW);
    digitalWrite(second_engine_02, HIGH);
}





//Turn ACW **needs engine power tuning**
void turn_anticlockwise() {
    //Ensure power states are equal in both wheels
    analogWrite(first_engine, 100);
    analogWrite(second_engine, 100);
    //Reverse power in left wheel
    digitalWrite(first_engine_01, LOW);
    digitalWrite(first_engine_02, HIGH);
    //Forward power in right wheel
    digitalWrite(second_engine_01, HIGH);
    digitalWrite(second_engine_02, LOW);
}




//Turn CW **needs engine power tuning**
void turn_clockwise() {
    //Ensure power states are equal in both wheels
    analogWrite(first_engine, 100);
    analogWrite(second_engine, 100);
    //Forward power in left wheel
    digitalWrite(first_engine_01, HIGH);
    digitalWrite(first_engine_02, LOW);
    //Reverse power in right wheel
    digitalWrite(second_engine_01, LOW);
    digitalWrite(second_engine_02, HIGH);
}






//Piston activate
void piston_launch() {
    //Cut off charging
    digitalWrite(charge_piston, LOW);
    delay(50);
    //Fire
    digitalWrite(fire_piston, HIGH);
    time_after_fired = 0;
    //Wait 0.1 sec
    delay(50);
    //Reset signal
    digitalWrite(fire_piston, LOW);
    digitalWrite(charge_piston, HIGH);

}
