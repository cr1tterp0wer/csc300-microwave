#include "Toaster.h"

Toaster::Toaster(){
  isDoorOpen = false;
  isTrayFull = false;
  isCooking  = false;
  food = nullptr;
}
Toaster::~Toaster(){
  delete food;
}

void Toaster::setTemp( double& t ){
  this->temperature = t;
}
void Toaster::setIsDoorOpen( bool b ){
  isDoorOpen = b;  
}
void Toaster::setIsTrayFull( bool b ){
  isTrayFull = b;
}
void Toaster::setIsCooking( bool b  ){
  isCooking = b;
}
void Toaster::setFood( Food &f ){
  food = &f;
}

double Toaster::getTemp()    { return temperature; }
bool Toaster::getIsDoorOpen(){ return isDoorOpen;  }
bool Toaster::getIsTrayFull(){ return isTrayFull;  }
bool Toaster::getIsCooking() { return isCooking;   }
Food Toaster::getFood()      { return *food;       }

