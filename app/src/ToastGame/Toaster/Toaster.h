#pragma once
#include "../Food/Food.h"
#include<iostream>

using std::cout;
using std::endl;

class Toaster{

  private:
    double temperature;
    bool isDoorOpen;
    bool isTrayFull;
    bool isCooking;
    Food *food;

  public:
    Toaster();
    virtual ~Toaster();

    void setTemp( double& t );
    void setIsDoorOpen( bool b );
    void setIsTrayFull( bool b );
    void setIsCooking( bool b  );
    void setFood( Food &f );

    double getTemp();
    bool getIsDoorOpen();
    bool getIsTrayFull();
    bool getIsCooking();
    Food getFood();

};
