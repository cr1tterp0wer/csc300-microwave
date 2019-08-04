#pragma once
#include<string>

using std::string;

class Food{
  
  private:
    string name;
    int energyDelta;
    bool isBurnt;

  public:
    Food();
    Food( string n, int e );
    virtual ~Food();
    
    string getName();
    int getEnergyDelta();
    bool getIsBurnt();

    void setName( string& s );
    void setEnergyDelta( int& e );
    void setBurnt( bool& b );

};
