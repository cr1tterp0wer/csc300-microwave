#include<iostream>
#include "./Timer/Timer.h"
#include<iostream>

using std::cout;
using std::endl;

int main(){

  Timer t( 10 );  
  
  cout << t.getCurrentTime(); 

  while( t.getSeconds() > 1 ){
    if( t.decrementSeconds() ){
      cout << t.getSeconds() << endl;
    }
  }
  
  return 0;
}
