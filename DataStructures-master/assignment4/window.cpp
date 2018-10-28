#include <iostream>
#include "window.h"

using namespace std;
//Window wait time and longest time.
Window::Window(){
  idleTime=0;
  longestTime=0;

}


Window::~Window(){


}

bool Window::isIdle(){ //checks if the window object is empty or not 
  return student.timeNeededWindow==0;
}
