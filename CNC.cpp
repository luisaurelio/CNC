/*
  CNC.cpp - Biblioteca CNC.
  Criado por Luis Aurélio do Patrocinio, 24/05/2012.
*/

#include <Arduino.h>
#include "CNC.h"

CNC::CNC(int pinX[], int pinY[], int maxStepsX, int maxStepsY, int speed, int stepsPerRevolution, int srvPin){

    //Configuração do stepper
    Stepper stepperX(stepsPerRevolution, pinX[0], pinX[1], pinX[2], pinX[3]);
    Stepper stepperY(stepsPerRevolution, pinY[0], pinY[1], pinY[2], pinY[3]);

    stepperX.setSpeed(speed);
    stepperY.setSpeed(speed);

    this->_speed = speed;
    this->_stepsPerRevolution = stepsPerRevolution;
    this->_maxStepsX = maxStepsX;
    this->_maxStepsY = maxStepsY;
    this->_lastX = 0;
    this->_lastY = 0;

    //Configuração do servo
    Servo servoZ;
    servoZ.attach(srvPin);
}

void CNC::line(int x_1, int y_1, int x_2, int y_2){
    if(x_1==x_2 || y_1==y_2){

        stepperX->step(x_1-_lastX);
        stepperY->step(y_1-_lastY);

        //Incluir a rotina de descer a caneta.
        penDown();

        stepperX->step(x_2-x_1);
        stepperY->step(y_2-y_1);

        //Incluir a rotina de subir a caneta.
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
    delay(250);
    for(int i=0; i<_maxStepsY; i++){
        stepperY->step(_stepsPerRevolution);
    }
    delay(250);
    for(int i=0; i<_maxStepsX; i++){
        stepperX->step(-_stepsPerRevolution);
    }
    delay(250);
    for(int i=0; i<_maxStepsY; i++){
        stepperY->step(-_stepsPerRevolution);
    }
    delay(250);
}

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
