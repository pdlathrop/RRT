#include "RRT.h"

float randFloat(){
  //between 0 and 1, some graininess based on what RAND_MAX is (32767?) but should be ok for most applications
  return (float)(rand()) / (float)(RAND_MAX);
}