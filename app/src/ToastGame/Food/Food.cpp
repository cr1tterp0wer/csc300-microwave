#include "Food.h"

Food::Food(){
  this->isBurnt = false;
  this->energyDelta = 100;
  this->name = "Food";
}

Food::Food( string n, int e ){
  this->isBurnt = false;
  this->energyDelta = e;
  this->name = n;
}
Food::~Food(){}

void Food::setName( string& n ){
  this->name = n;
}

void Food::setEnergyDelta( int& e ){
  this->energyDelta = e;
}

void Food::setBurnt( bool& b ){
  this->isBurnt = b;
}

string Food::getName(){ return this->name; }
int Food::getEnergyDelta(){ return this->energyDelta; }
bool Food::getIsBurnt(){ return this->isBurnt; }





