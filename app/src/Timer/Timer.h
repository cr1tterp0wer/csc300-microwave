#pragma once
#include <ctime>

using std::time_t;

class Timer{

  //one hour
  static const int MAX_TIME = 3600;

  private:
    time_t currentTime;
    time_t prevTime;
    time_t secs;

  public:
    Timer( int s );
    virtual ~Timer();

    void   clearSeconds();
    int    getSeconds();
    void   setSeconds( int& s );
    bool   decrementSeconds();

    int getCurrentTime();
    int getPrevTime();
};

