#include "ToastGame.h"

ToastGame::ToastGame(){

  m_state   = MAIN;
  t_setting = LIGHT;
  c_setting = TOAST; 

  isPlaying = false;
  bread = new Food( "*Wonder Bread", 100 );
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
  
  if( ma_settings != START_A){
    getInput();
    processInput();
    
    if( c_setting == TOAST ){
      toaster.setTemp( 175.0 );
      
      switch( t_setting ){
        case LIGHT: 
//          timer->setSeconds( 60 );
          break;
        case MILD:
 //         timer->setSeconds( 120 );
          break;
        case DARK:
//          timer->setSeconds( 180 );
          break;
        default:
          break;
      }
    }
    if( timer->getSeconds() < 1 ){
      isPlaying = false;
    }
  }
}

void ToastGame::processInput(){

  if( ma_settings == START_A ){
   cout << "FIRING UP!" << endl; 
  }else if( ma_settings == PEEK_INSIDE_A ){
    if( toaster.getIsTrayFull() ){
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
      cout << "There's a piece of " << bread->getName() << " inside!" << endl;
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    }else{
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
      cout << "        There's nothing inside!" << endl;
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    }
    m_state = OPEN_DOOR;
    ma_settings = NONE;
  }else if( ma_settings == OPEN_DOOR_A ){
    this->openDoor();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    cout << "                DOOR OPENED"<< endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    ma_settings = NONE;
  }else if( ma_settings == INSERT_FOOD_A ){
    if( !toaster.getIsDoorOpen() ){
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
      cout << "CANNOT INSERT FOOD, THE DOOR IS STILL CLOSED!"<< endl;
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
      m_state = MAIN;
    }else if( toaster.getIsTrayFull() ){
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
      cout << "  " << bread->getName() << " ALREADY INSIDE"<< endl;
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    }
    else{
      insertFood();
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
      cout << "             " << bread->getName() << " INSERTED"<< endl;
      cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    }

    ma_settings = NONE;
  }else if( ma_settings == CLOSE_DOOR_A ){
    closeDoor();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    cout << "                DOOR CLOSED "<< endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
    ma_settings = NONE;
  }

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
         ma_settings = OPEN_DOOR_A;
       }else if( m_state == OPEN_DOOR ){
         ma_settings = PEEK_INSIDE_A;
       }else if( m_state == INSERT_FOOD ){
         ma_settings = INSERT_FOOD_A;
       }else if( m_state == COOK_SETTING ){
         m_state = SET_FUNCTION;
       }
       else if( m_state == SET_FUNCTION ){
         m_state = TOAST_MENU;
         c_setting = TOAST;
       }
       else if( m_state == TOAST_MENU ){
         m_state = SET_FUNCTION;
         t_setting = LIGHT;
       }
       break;
     case 2:
       if( m_state == MAIN ){
         m_state = INSERT_FOOD;
       }else if( m_state == OPEN_DOOR ){
         m_state = MAIN; 
         ma_settings = CLOSE_DOOR_A;
       }else if( m_state == INSERT_FOOD ){
         m_state = COOK_SETTING; 
       }else if( m_state == COOK_SETTING ){
         m_state = SET_TEMPERATURE;
       }
       else if( m_state == SET_FUNCTION ){
         c_setting = BROIL; 
       }
       else if( m_state == TOAST_MENU ){
         m_state = SET_FUNCTION;
         t_setting = MILD;
       }
       break;
     case 3:
       if( m_state == MAIN ){
         m_state = COOK_SETTING;
       }else if( m_state == OPEN_DOOR ){
         m_state = INSERT_FOOD;
       }else if( m_state == INSERT_FOOD ){
         m_state = START;
         ma_settings = START_A;
       }else if( m_state == COOK_SETTING ){
         m_state = SET_TIME;
       }
       else if( m_state == SET_FUNCTION ){
         c_setting = WARM; 
       }
       else if( m_state == TOAST_MENU ){
         m_state = SET_FUNCTION;
         t_setting = DARK;
       }
       break;
     case 4:
       if( m_state == MAIN ){
         m_state = MAIN;
         ma_settings = CLOSE_DOOR_A;
       }else if( m_state == OPEN_DOOR ){
         m_state = COOK_SETTING;
         ma_settings = OPEN_DOOR_A;
       }else if( m_state == INSERT_FOOD ){
         m_state = MAIN;
         ma_settings = CLOSE_DOOR_A;
       }else if( m_state == COOK_SETTING ){
         m_state = MAIN;
       }
       else if( m_state == SET_FUNCTION ){
         c_setting = BAKE; 
       }
       break;
     case 5:
       if( m_state == MAIN ){
         m_state = START;
         ma_settings = START_A;
       }else if( m_state == OPEN_DOOR ){
         m_state = START;
         ma_settings = START_A;
       }else if( m_state == INSERT_FOOD ){
         m_state = KILL;
       }else if( m_state == SET_FUNCTION ){
         m_state = MAIN;
       }
       else if( m_state == COOK_SETTING ){
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
}

void ToastGame::render(){
  if( ma_settings != START_A ){
    displayDashboard(); 
    displayMenu();
  }else{
    while( timer->getSeconds() >= 1 ){
      if( timer->decrementSeconds() )
        cout << timer->getSeconds() << endl;
    }
  }
  
}

void ToastGame::insertFood(){
  toaster.setFood( *bread );
  toaster.setIsTrayFull( true );
}

void ToastGame::removeFood(){
  *bread = toaster.getFood();
}

void ToastGame::openDoor(){
  toaster.setIsDoorOpen( true );
}

void ToastGame::closeDoor(){
  toaster.setIsDoorOpen( false );
}

void ToastGame::setTime( int& t ){
  timer->setSeconds( t );
}

void ToastGame::startPrompt(){

  cout << "**************************************" << endl;
  cout << "***          Toaster Game          ***" << endl;
  cout << "**************************************" << endl;
}


void ToastGame::displayDashboard(){
  
  cout << "**************************************" << endl << endl;
  cout << "Timer: " << timer->getSeconds() << " secs" << endl;
  cout << "Toast Function: " << t_setting_str[ t_setting ] << endl;
  cout << "Cook Setting: "   << c_setting_str[ c_setting ] << endl << endl;
}

void ToastGame::displayMenu(){
  

  switch( m_state ){
    case MAIN:
      cout << "**************** MENU ****************" << endl;
      cout << "1. Open Door" << endl;
      cout << "2. Insert Food" << endl;
      cout << "3. Cook Settings" << endl;
      cout << "4. Close Door" << endl;
      cout << "5. Start" << endl;
      cout << "6. Exit" << endl;
      break;
    case OPEN_DOOR:
      cout << "************ OPENED DOOR ************" << endl;
      cout << "1. Peek Inside" << endl;
      cout << "2. Close Door" << endl;
      cout << "3. Insert Food" << endl;
      cout << "4. Cook Settings" << endl;
      cout << "5. Start" << endl;
      cout << "6. Exit" << endl;
      break;
    case INSERT_FOOD:
      cout << "************ INSERT FOOD ************" << endl;
      cout << "1. Insert " << bread->getName() << endl;
      cout << "2. Cook Settings" << endl;
      cout << "3. Start" << endl;
      cout << "4. Close Door" << endl;
      cout << "5. Cancel" << endl;
      break;
    case COOK_SETTING:
      cout << "********** COOK SETTINGS  **********" << endl;
      cout << "1. Set Function" << endl;
      cout << "2. Set Temperature" << endl;
      cout << "3. Set Time" << endl;
      cout << "4. Main Menu" << endl;
      cout << "5. Exit" << endl;
      break;
    case SET_FUNCTION:
      cout << "******** TOASTER FUNCTION  ********" << endl;
      cout << "1. Toast" << endl;
      cout << "2. Broil" << endl;
      cout << "3. Warm" << endl;
      cout << "4. Bake" << endl;
      cout << "5. Main Menu" << endl;
      break;
    case TOAST_MENU:

      cout << "*********** TOAST MENU ***********" << endl;
      cout << "1. Light" << endl;
      cout << "2. Mild" << endl;
      cout << "3. Dark" << endl;
      break;
    default:
      break;
  }
  cout << endl << "Select an option: " << endl;
}







