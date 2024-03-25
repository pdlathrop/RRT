#include <vector>
#include "RRT.h"


std::vector<obstacle> createObstacles(int numObs, float minSide, float maxSide, int bound){
  //create a numObs-long random obstacle list defining rectangular obstacles of minimum side length minSide and max length maxSide
  std::vector<obstacle> obstacles;
  float obsDiff = maxSide - minSide;
  for(int i = 0; i < numObs; i++){
    float x1 = randFloat()*bound;
    float y1 = randFloat()*bound;
    obstacle newObs{x1, x1+randFloat()*obsDiff, y1, y1+randFloat()*obsDiff};
    obstacles.push_back(newObs);
  }
  return obstacles;
}