#include <vector>
#include "RRT.h"

searchResult RRT(std::vector<obstacle>& obstacles, node xInit, node xGoal, float goalRad, int rastNum, int bound){
  //performs Rapidly-Exploring Random Tree search of bound*bound 2D space with obstacles defined in obstacles, initial node xInit, goal node xGoal, a radius of acceptible solution around goal goalRad
  //returns searchResult object made of tree and number of times connections are tested (oracleCount). A node within goalRad of xGoal is last element of tree.
  bool finished = false;
  std::vector<node> tree;
  xInit.parentInd = 0;
  tree.push_back(xInit);
  int oracleCount = 0;

  while(!finished){
    node randNode{randFloat()*bound,randFloat()*bound};
    randNode.parentInd = findParent(randNode, tree, bound);
    bool connectible = testConnection(tree[randNode.parentInd], randNode, obstacles, rastNum);
    oracleCount++;
    if(connectible){
      tree.push_back(randNode);
      if(nodeDist(randNode, xGoal) <= goalRad){
        finished = true;
      }
    }
  }
  return searchResult{tree, oracleCount};
}