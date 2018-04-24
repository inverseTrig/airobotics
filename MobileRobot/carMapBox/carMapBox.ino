#include <Servo.h> //servo library
#include <EEPROM.h> //EEPROM library
Servo myservo;     // create servo object to control servo
int Echo = A4;
int Trig = A5;
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;
int ENA = 5;
int ENB = 11;
int ABS = 150;
int rightDistance = 0, leftDistance = 0, middleDistance = 0;
int index = 0, angle = 10, isWrite = 0, i = 0, distanceTest = 0;
int isRight = 0, epsilon = 2;

void _mForward()
{
    analogWrite(ENA, ABS);
    analogWrite(ENB, ABS);
    digitalWrite(in1, HIGH); //digital output
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("go forward!");
}

void _mBack()
{
    analogWrite(ENA, ABS);
    analogWrite(ENB, ABS);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("go back!");
}

void _mleft()
{
    analogWrite(ENA, ABS);
    analogWrite(ENB, ABS);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    Serial.println("go left!");
}

void _mright()
{
    analogWrite(ENA, ABS);
    analogWrite(ENB, ABS);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    Serial.println("go right!");
}
void _mStop()
{
    digitalWrite(ENA, LOW);
    digitalWrite(ENB, LOW);
    Serial.println("Stop!");
}

void increment(int pointer)
{
	short value = EEPROM.read(pointer):
	value++;
	EEPROM.write(pointer.value);
}
/*Ultrasonic distance measurement Sub function*/
int Distance_test()
{
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(20);
    digitalWrite(Trig, LOW);
    float Fdistance = pulseIn(Echo, HIGH);
    Fdistance = Fdistance / 58;
    return (int)Fdistance;
}

int rightDistanceTest() {
    myservo.write(10); //10°-180°
    delay(300);
    int rD = Distance_test();
    delay(150);
    myservo.write(90);
    return rD;
}

int leftDistanceTest() {
    myservo.write(180);
    delay(300);
    int lD = Distance_test();
    delay(150);
    myservo.write(90);
    return lD;
}

void setup()
{
    myservo.attach(3); // attach servo on pin 3 to servo object
    Serial.begin(9600);
    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    _mStop();
}

void loop()
{
    _mStop();
    myservo.write(90); //setservo position according to scaled value
    delay(300);
    middleDistance = Distance_test();

    if (middleDistance <= 10) {                  // IF WALL!!
        isWrite = 1;
        rightDistance = rightDistanceTest();
        leftDistance = leftDistanceTest();
        if (rightDistance < leftDistance) {     // HAVE TO TURN LEFT!!
            _mleft();
            //EEPROM.write(i, 1);
            index = 0;
            rightDistance = 0;
            leftDistance = 0;
            delay(750);
        } else {                                // HAVE TO TURN RIGHT!!
            _mright();
            //EEPROM.write(i, 2);
            index = 0;
            rightDistance = 0;
            leftDistance = 0;
            delay(750);
        }
        //i++;
        _mStop();
    } else {
        rightDistance = rightDistanceTest();
        leftDistance = leftDistanceTest();
    
        if (rightDistance < leftDistance) { // Right is closer
            angle = 10;
            if (index == 0) {
                index = rightDistance;
            }
            else if (index - epsilon < rightDistance && rightDistance < index + epsilon) {
                index = rightDistance;
            }
            else if (rightDistance < index) {
                _mleft();
                delay(150);
            } else {
                _mright();
                delay(150);
            }
            index = rightDistance;
        } else {
            angle = 180;
            if (index == 0) {
                index = leftDistance;
            }
            else if (index - epsilon < leftDistance && leftDistance < index + epsilon) {
                index = leftDistance;
            }
            else if (leftDistance < index) {
                _mright();
                delay(150);
            } else {
                _mleft();
                delay(150);
            }
            index = leftDistance;
        }
        _mForward();
        if (isWrite == 1) {
          increment(i);
        }
        delay(250);
    }
}
