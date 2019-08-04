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
    enum TOAST_SETTING{ 
      LIGHT = 0x00,
      MILD = 0x01,
      DARK = 0x02 
    } t_setting = LIGHT;
    enum COOK_SETTING{ 
      TOAST = 0x00, 
      BROIL = 0x01, 
      WARM  = 0x02, 
      BAKE  = 0x03 
    } c_setting = TOAST;
    enum MENU_STATE{ 
      KILL,
      MAIN,
      OPEN_DOOR, 
      INSERT_FOOD,
      COOK_SETTING,
      SET_FUNCTION, 
      SET_TEMPERATURE,
      SET_TIME
    } m_state = MAIN;
    string t_setting_str[3] = { "Light", "Mild", "Dark" };
    string c_setting_str[4] = { "Toast", "Broil", "Warm", "Bake" };

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


