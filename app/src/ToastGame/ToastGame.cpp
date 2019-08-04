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
       if( m_state == 0x01 ){
         m_state = OPEN_DOOR;
       }else if( m_state == 0x02 ){
         m_state = OPEN_DOOR;
       }else if( m_state == 0x03 ){
         insertFood();
       }else if( m_state == 0x04 ){
         m_state = SET_FUNCTION;
       }
       break;
     case 2:
       break;
     case 3:
       break;
     case 4:
       break;
     case 5:
       break;
     case 6:
       break;
     default:
       break;
   }
   
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





