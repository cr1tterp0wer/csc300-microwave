#pragma once
#include<iostream>
#include "./Food/Food.h"
#include "./Timer/Timer.h"
#include "./Toaster/Toaster.h"

using std::string;
using std::endl;
using std::cin;

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
    enum MENU_ACTION{
      NONE          = 0x00,
      INSERT_FOOD_A = 0x01,
      OPEN_DOOR_A   = 0x02,
      CLOSE_DOOR_A  = 0x03,
      START_A       = 0x04,
      PEEK_INSIDE_A = 0x05
    } ma_settings = NONE;
    enum MENU_STATE{ 
      KILL = 0x00,
      MAIN = 0x01,
      OPEN_DOOR = 0x02, 
      INSERT_FOOD = 0x03,
      COOK_SETTING = 0x04,
      SET_FUNCTION = 0x05, 
      SET_TEMPERATURE = 0x06,
      SET_TIME   =  0x07,
      START      = 0x08,
      TOAST_MENU = 0x09,
    } m_state = MAIN;
    string t_setting_str[3] = { "Light", "Mild", "Dark" };
    string c_setting_str[4] = { "Toast", "Broil", "Warm", "Bake" };

    void start();
    void update();
    void render();
    void insertFood();
    void removeFood();
    void openDoor();
    void closeDoor();
    void setTime( int& s );
    void startPrompt();
    void getInput();
    void processInput();
    void displayDashboard();
    void displayMenu();

  public:
    ToastGame();
    virtual ~ToastGame();

    void playGame();
};


