/*
  CNC.cpp - Biblioteca CNC.
  Criado por Luis Aurélio do Patrocinio, 24/05/2012.
*/

#include <Stepper.h>
#include <Servo.h>
#include <Arduino.h>
#include "CNC.h"

//Stepper stepperX;

CNC::CNC(int pinX[], int pinY[], int maxStepsX, int maxStepsY, int speed, int stepsPerRevolution, int srvPin){
//Criar uma função chamada stepperMotor para receber os steppers.


    //Configuração do stepper
//    Stepper stepperX(stepsPerRevolution, pinX[0], pinX[1], pinX[2], pinX[3]);
    Stepper stepperX(stepsPerRevolution, pinX[0], pinX[1], pinX[2], pinX[3]);
    //Stepper stepperX = new Stepper(stepsPerRevolution, pinX[0], pinX[1], pinX[2], pinX[3]);
//    stepperX = stepperMotor(pinX, stepsPerRevolution);
    Stepper stepperY(stepsPerRevolution, pinY[0], pinY[1], pinY[2], pinY[3]);

//this->_stepperX = stepperX;
//this->_stepperY = stepperY;


    this->_speed = speed;
    this->_stepsPerRevolution = stepsPerRevolution;
    this->_maxStepsX = maxStepsX;
    this->_maxStepsY = maxStepsY;
    this->_lastX = 0;
    this->_lastY = 0;

    //Configuração do servo
    Servo servoZ;
    this->_srvPin = srvPin;
}

void CNC::setupCNC(){
    //Setup stepper
    stepperX->setSpeed(_speed);
    stepperY->setSpeed(_speed);

    //Setup servo
    servoZ.attach(_srvPin);
    penUp();
}
/*
void CNC::line(int x_1, int y_1, int x_2, int y_2){
    if(x_1==x_2 || y_1==y_2){

        stepperX->step(x_1-_lastX);
        stepperY->step(y_1-_lastY);

        //Descer a caneta.
        penDown();

        stepperX->step(x_2-x_1);
        stepperY->step(y_2-y_1);

        //Subir a caneta.
        penUp();

        this->_lastX = x_2;
        this->_lastY = y_2;
    }
}

void CNC::rect(){
}

void CNC::circ(){
}

void CNC::selfTest(){
    for(int i=0; i<_maxStepsX; i++){
        stepperX->step(_stepsPerRevolution);
    }
    penDown();
    delay(250);
    penUp();
    delay(250);
    for(int i=0; i<_maxStepsY; i++){
        stepperY->step(_stepsPerRevolution);
    }
    penDown();
    delay(250);
    penUp();
    delay(250);
    for(int i=0; i<_maxStepsX; i++){
        stepperX->step(-_stepsPerRevolution);
    }
    penDown();
    delay(250);
    penUp();
    delay(250);
    for(int i=0; i<_maxStepsY; i++){
        stepperY->step(-_stepsPerRevolution);
    }
    penDown();
    delay(250);
    penUp();
    delay(250);
}
*/
void CNC::penDown(){
    pen(true);
}

void CNC::penUp(){
    pen(false);
}

void CNC::pen(bool state){
    if(state){
        servoZ.write(80);
    }else{
        servoZ.write(0);
    }
}

//void CNC::stepperMotor(int pin[], int stepsPerRevolution){
//    Stepper stepper(stepsPerRevolution, pin[0], pin[1], pin[2], pin[3]);
//    return stepper;
//}
