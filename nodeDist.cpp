#include <cmath>
#include "RRT.h"

float nodeDist(node node1, node node2){
  return sqrt(pow(node1.x-node2.x,2)+pow(node1.y-node2.y,2));
}