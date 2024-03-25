#include "RRT.h"

int findParent(node randNode, std::vector<node> tree, int bound){
  //returns index of closest parent node in tree to randNode
  float minDist = 2*bound;
  int chosenParentInd;
  for(int i = 0; i < tree.size(); i++){
    if(nodeDist(randNode, tree[i]) < minDist){
      minDist = nodeDist(randNode, tree[i]);
      chosenParentInd = i;
    }
  }
  return chosenParentInd;
}