#ifndef RRT_HEADER
#define RRT_HEADER
#include <vector>

struct node{
  //node class contains x and y coordinates and a parent index for use in trees (not graphs)
  float x;
  float y;
  int parentInd;
  node(float xCoord, float yCoord){
    //parent-less constructor
    x = xCoord;
    y = yCoord;
  }
};

struct searchResult{
  //for RRT return, tree and oracleCount being number of connections tested, for comparison purposes
  std::vector<node> tree;
  int oracleCount;
};

struct obstacle{
  //rectangular obstacles defined by bounds
  float x1;
  float x2;
  float y1; 
  float y2;
};

float randFloat();
float nodeDist(node node1, node node2);
int findParent(node randNode, std::vector<node> tree, int bound);
bool testConnection(node node1, node node2, std::vector<obstacle>& obstacles, int rastNum);
std::vector<obstacle> createObstacles(int numObs, float minSide, float maxSide, int bound);
std::vector<node> unwrap(searchResult lastRun, int goalNodeIndex);
std::vector<node> unwrap(searchResult lastRun, int startNodeIndex, int goalNodeIndex);
searchResult RRT(std::vector<obstacle>& obstacles, node xInit, node xGoal, float goalRad, int rastNum, int bound);

#endif 