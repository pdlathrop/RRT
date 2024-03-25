#include <vector>
#include "RRT.h"

std::vector<node> unwrap(searchResult lastRun, int startNodeIndex, int goalNodeIndex){
  //takes in searchResult object with tree field, traces back via parents from startNodeIndex start to index goalNodeIndex and returns reverse order path of nodes as a list
  //for when 0 index is not the start. returns vector of nodes, 0 index is goal, last index is start (reverse order)
  std::vector<node> returnList;
  bool reachedStart = false;
  int currIndex = goalNodeIndex;
  std::vector<node> searchTree = lastRun.tree;
  while(!reachedStart){
    returnList.push_back(searchTree[currIndex]);
    currIndex = searchTree[currIndex].parentInd;
    if(currIndex == startNodeIndex){ 
      reachedStart = true;
    }
  }
  return returnList;
}