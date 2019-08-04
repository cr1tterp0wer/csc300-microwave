#pragma once
#include<iostream>
#include "./Food/Food.h"
#include "./Timer/Timer.h"
#include "./Toaster/Toaster.h"

using std::string;
using std::endl;

class ToastGame{

  private:
    short userInput;
    bool  isPlaying;
    Toaster toaster;
    Food    *bread;
    Timer   *timer;
    enum toastSetting{ LIGHT, MILD, DARK } t_setting       = LIGHT;
    enum cookSetting{ TOAST, BROIL, WARM, BAKE } c_setting = TOAST;
    enum menuState{ 
      KILL,
      MAIN,
      OPEN_DOOR, 
      INSERT_FOOD,
      COOK_SETTING,
      SET_FUNCTION, 
      SET_TEMPERATURE,
      SET_TIME
    } m_state = MAIN;

    void start();
    void update();
    void render();
    void cancel();
    void insertFood();
    void removeFood();
    void openDoor();
    void closeDoor();
    void setTime();
    void setToasterFunction();
    void setTemperature();
    void startPrompt();
    void getInput();
    void displayDashboard();
    void displayMenu();

  public:
    ToastGame();
    virtual ~ToastGame();

    void playGame();
};


