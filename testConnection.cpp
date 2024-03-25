#include <vector>
#include "RRT.h"

bool testConnection(node node1, node node2, std::vector<obstacle>& obstacles, int rastNum){
  //simple connection test based on rasterizing straight line between node1 and node2 (with rastNum equally spread rasterizations), and checking all points for obstacle impact. Not perfect, better (and slower) with higher rastNum. Returns true if obstacle free straight line path exists, false otherwise.

  //create rasterizations 
  float xRange = node2.x - node1.x;
  float yRange = node2.y - node1.y;
  for(int i = 0; i < rastNum; i++){
    node testNode{node1.x + xRange*i/rastNum, node1.y + yRange*i/rastNum};
    for(int j = 0; j < obstacles.size(); j++){
      if(testNode.x >= obstacles[j].x1 && testNode.x <= obstacles[j].x2 && testNode.y >= obstacles[j].y1 && testNode.y <= obstacles[j].y2){
        return false;
      }
    }
  }
  return true;
}