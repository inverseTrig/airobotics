#include <Servo.h> //servo library
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
int index = 0, angle = 10;

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

#ifdef send
    Serial.print("middleDistance=");
    Serial.println(middleDistance);
#endif

    myservo.write(10); //10°-180°
    delay(300);
    rightDistance = Distance_test();
    delay(150);
    myservo.write(90);

#ifdef send
    Serial.print("rightDistance=");
    Serial.println(rightDistance);
#endif

    myservo.write(180);
    delay(500);
    leftDistance = Distance_test();
    delay(150);
    myservo.write(90);


#ifdef send
    Serial.print("leftDistance=");
    Serial.println(leftDistance);
#endif

    if (rightDistance < leftDistance) {
        angle = 10;
        if (rightDistance < index) {
            _mleft();
            delay(100);
        } else {
            _mright();
            delay(100);
        }
        index = rightDistance;
    }
    else {
        angle = 180;
        if (leftDistance < index) {
            _mright();
            delay(100);
        } else {
            _mleft();
            delay(100);
        }
        index = leftDistance;
    }

    if (middleDistance <= 20)
    {
        _mStop();
    }
    else
    {
        _mForward();
        delay(500);
    }
}
