#include "ToastGame.h"

ToastGame::ToastGame(){

  m_state   = MAIN;
  t_setting = LIGHT;
  c_setting = TOAST; 

  isPlaying = false;
  bread = new Food( "WonderBread", 100 );
  timer = new Timer( 5 );
}
ToastGame::~ToastGame(){}

void ToastGame::playGame(){
  
  isPlaying = true;

  startPrompt();
  displayDashboard();
  displayMenu();
  start();
}

void ToastGame::start(){
  
  //main loop
  while(isPlaying){
    update();
    render();
  }
}

void ToastGame::update(){

  timer->decrementSeconds();
  if( timer->getSeconds() < 1 ){
    isPlaying = false;
  }

  getInput();
}

void ToastGame::render(){
  displayDashboard(); 
  displayMenu();
}

void ToastGame::getInput(){

  userInput = 0;
  cin >> userInput; 
  
   //Process State
   //Process input
   switch( userInput ){
     case 1:
       if( m_state == MAIN ){
         m_state = OPEN_DOOR;
       }else if( m_state == OPEN_DOOR ){
         m_state = OPEN_DOOR;
       }else if( m_state == INSERT_FOOD ){
         insertFood();
       }else if( m_state == COOK_SETTING ){
         m_state = SET_FUNCTION;
       }else if( m_state == SET_FUNCTION ){

       }else if( m_state == SET_TEMPERATURE ){

       }else if( m_state == SET_TIME ){

       }
       break;
     case 2:
       if( m_state == MAIN ){
         m_state = INSERT_FOOD;
       }else if( m_state == OPEN_DOOR ){
         closeDoor();
         m_state = COOK_SETTING; 
       }else if( m_state == INSERT_FOOD ){
         m_state = COOK_SETTING; 
       }else if( m_state == COOK_SETTING ){
         m_state = SET_TEMPERATURE;
       }
       break;
     case 3:
       if( m_state == MAIN ){
         m_state = COOK_SETTING;
       }else if( m_state == OPEN_DOOR ){
         m_state = INSERT_FOOD;
       }else if( m_state == INSERT_FOOD ){
         m_state = START;
       }else if( m_state == COOK_SETTING ){
         m_state = SET_TIME;
       }
       break;
     case 4:
       if( m_state == MAIN ){
         closeDoor();
         m_state = MAIN;
       }else if( m_state == OPEN_DOOR ){
         m_state = COOK_SETTING;
       }else if( m_state == INSERT_FOOD ){
         closeDoor();
         m_state = MAIN;
       }else if( m_state == COOK_SETTING ){
         m_state = MAIN;
       }
       break;
     case 5:
       if( m_state == MAIN ){
         m_state = START;
       }else if( m_state == OPEN_DOOR ){
         m_state = START;
       }else if( m_state == INSERT_FOOD ){
         m_state = KILL;
       }else if( m_state == COOK_SETTING ){
         m_state = KILL;
       }
       break;
     case 6:
       if( m_state == MAIN ){
         m_state = KILL;
       }else if( m_state == OPEN_DOOR ){
         m_state = KILL;
       }
       break;
     default:
       cout << "Try again" << endl;
       break;
   }
  /*
     if( m_state == MAIN ){
     }else if( m_state == OPEN_DOOR ){
     }else if( m_state == INSERT_FOOD ){
     }else if( m_state == COOK_SETTING ){
     }


 */
}
void ToastGame::startPrompt(){

  cout << "**************************************" << endl;
  cout << "***          Toaster Game          ***" << endl;
  cout << "**************************************" << endl;
}


void ToastGame::displayDashboard(){
  
  cout << "**************************************" << endl << endl;
  cout << "Timer: " << timer->getSeconds() << " second(s) remaining." << endl;
  cout << "Toast Function: " << t_setting_str[ t_setting ] << endl;
  cout << "Cook Setting: " << c_setting_str[ c_setting ] << endl << endl;
}

void ToastGame::displayMenu(){
  
  cout << "**************** MENU ****************" << endl;

  switch( m_state ){
    case MAIN:
      cout << "1. Open Door" << endl;
      cout << "2. Insert Food" << endl;
      cout << "3. Cook Settings" << endl;
      cout << "4. Close Door" << endl;
      cout << "5. Start" << endl;
      cout << "6. Exit" << endl;
      break;
    case OPEN_DOOR:
      cout << "1. Peek Inside" << endl;
      cout << "2. Close Door" << endl;
      cout << "3. Insert Food" << endl;
      cout << "4. Cook Settings" << endl;
      cout << "5. Start" << endl;
      cout << "6. Exit" << endl;
      break;
    case INSERT_FOOD:
      cout << "1. Insert Bread" << endl;
      cout << "2. Cook Settings" << endl;
      cout << "3. Start" << endl;
      cout << "4. Close Door" << endl;
      cout << "5. Cancel" << endl;
      break;
    case COOK_SETTING:
      cout << "1. Set Function" << endl;
      cout << "2. Set Temperature" << endl;
      cout << "3. Set Time" << endl;
      cout << "4. Main Menu" << endl;
      cout << "5. Exit" << endl;
      break;
    default:
      break;
  }
  cout << endl << "Select an option: " << endl;

/*
cout << "1." << endl;
cout << "2." << endl;
cout << "3. " << endl;
cout << "4." << endl;
cout << "5." << endl;
cout << "6." << endl;
*/
}

void ToastGame::cancel(){

}

void ToastGame::insertFood(){

}

void ToastGame::removeFood(){

}

void ToastGame::openDoor(){

}

void ToastGame::closeDoor(){

}

void ToastGame::setTime(){

}

void ToastGame::setToasterFunction(){

}

void ToastGame::setTemperature(){

}







