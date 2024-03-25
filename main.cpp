/* Standalone program to create a 2D obstacle environment and search it with Rapidly Exploring Random Trees algorithm, performing connection tests with straight-line rasterizations, and returning a traversible path 
Author: Paul Lathrop
Date last edited: 3/25/24
*/

#include <cstdlib>
#include <iostream>
#include <locale>
#include <vector>
#include <cmath>
#include "RRT.h"

int main() {
  std::srand(time(NULL)); //set new random seed
  int bound = 10;
  int rastNum = 17;
  //create some obstacles
  std::vector<obstacle> obstacles = createObstacles(10,.5,2,bound);
  searchResult run1 = RRT(obstacles, node{0,0}, node{9,9}, 0.5, rastNum, bound);
  std::cout << run1.tree.size() << std::endl;
  std::vector<node> path = unwrap(run1, run1.tree.size()); //returns reverse order
  return 0;
}
