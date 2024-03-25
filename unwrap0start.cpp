#include <vector>
#include "RRT.h"


std::vector<node> unwrap(searchResult lastRun, int goalNodeIndex){
  //takes in searchResult object with tree field, traces back via parents from 0 indexed start to index goalNodeIndex and returns reverse order path of nodes as a list
  //assuming index 0 is the start. returns vector of nodes, 0 index is goal, last index is start (reverse order)
  std::vector<node> returnList;
  bool reachedStart = false;
  int currIndex = goalNodeIndex;
  std::vector<node> searchTree = lastRun.tree;
  while(!reachedStart){
    returnList.push_back(searchTree[currIndex]);
    currIndex = searchTree[currIndex].parentInd;
    if(currIndex == 0){ //when 0 index is start
      reachedStart = true;
    }
  }
  //could reverse it but no real need
  return returnList;
}