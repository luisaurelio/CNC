/*
  CNC.h - Biblioteca CNC.
  Criado por Luis Aurélio do Patrocinio, 24/05/2012.
*/

#ifndef CNC_h
#define CNC_h

#include <Stepper.h>
#include <Servo.h>
#include <Arduino.h>


class CNC// : public Stepper
{
  public:
    CNC(int pinX[], int pinY[], int maxStepsX, int maxStepsY, int speed, int stepsPerRevolution, int srvPin);
    void setupCNC();
    void line(int x_1, int y_1, int x_2, int y_2);
    void rect();
    void circ();
	void selfTest();
	void penDown();
	void penUp();
//	Stepper* stepperX;
//	Stepper* stepperY;

  private:
    int _speed;
	int _stepsPerRevolution;
	int _maxStepsX;
	int _maxStepsY;
	int _lastX;
	int _lastY;
	int _srvPin;
	void pen(bool state);
//	Stepper stepperMotor(int pin[], int stepsPerRevolution);
//	Stepper *stepperX(int,int,int,int,int);
//	Stepper _stepperX(int,int,int,int,int);
//	Stepper _stepperY(int,int,int,int,int);
//	Stepper* stepperX(int,int,int,int,int);
//	Stepper* stepperY(int,int,int,int,int);
	Stepper* stepperX;
	Stepper* stepperY;
	Servo servoZ;
};

#endif
