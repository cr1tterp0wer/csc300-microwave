#include "Timer.h"
#include <iostream>
using namespace std;

Timer::Timer(){
  currentTime = std::time(0);
  prevTime = currentTime;
  this->secs = 20;
}
Timer::Timer( int s ){
  currentTime  = std::time(0); 
  prevTime = currentTime;
  
  if( s > MAX_TIME ){
    this->secs = MAX_TIME;
  }else
    this->secs = s;
}
Timer::~Timer(){}

void Timer::clearSeconds(){
  this->secs = 0;
}

int Timer::getSeconds(){
  return this->secs;
}

void Timer::setSeconds( int s ){

  if( s < MAX_TIME )
    this->secs = s; 
}

bool Timer::decrementSeconds(){

  currentTime = std::time(0);

  if( currentTime - prevTime >= 1 ){
    this->secs--;
    prevTime = currentTime;
    return true;
  }

  return false;
}


