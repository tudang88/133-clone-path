#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include "Graph.h"

using namespace std;
// DO NOT MAKE CHANGES TO CAPTUREOUTPUT FUNCTION //
inline string captureOutput(function<void()> func) {
    std::stringstream buffer;
    std::streambuf* sbuf = std::cout.rdbuf();
    cout.rdbuf(buffer.rdbuf());
    func();
    cout.rdbuf(sbuf);
    return buffer.str();
}
/**
 * helper for printout
*/


static void test() {
  /**
   * test case 1
  */
  {
      cout<<"===============TEST 1 START================="<<endl;
      cout<<"adjencyList: [[2,4],[1,3],[2,4],[1,3]]"<<endl;
      // create node
      Node *node1 = new Node(1);
      Node *node2 = new Node(2);
      Node *node3 = new Node(3);
      Node *node4 = new Node(4);
      // create edges
      node1->neighbors = {node2, node4};
      node2->neighbors = {node1, node3};
      node3->neighbors = {node2, node4};
      node4->neighbors = {node1, node3};
    // test
      Solution solution;
      std::string expected = captureOutput([&]() {
        solution.printGraph(node1);
        }
      );
      cout<< "EXPECTED:";
      cout << expected<< endl;


      auto result = solution.cloneGraph(node1);
      std::string output = captureOutput([&]() {
        solution.printGraph(result);
        }
      );
      cout<< "ACTUAL:";
      cout << output<< endl;
      // ASSERTION
      cout << (output == expected ? "PASS\n" : "FAIL\n");

  }

    /**
   * test case 1
  */
  {
      cout<<"===============TEST 2 START================="<<endl;
      cout<<"adjencyList: [[2,4],[1,3],[2,4],[1,3]]"<<endl;
      // create node
      Node *node1 = new Node(1);
      Node *node2 = new Node(2);
      Node *node3 = new Node(3);
      Node *node4 = new Node(4);
      // create edges
      node1->neighbors = {node2, node4};
      node2->neighbors = {node1, node3};
      node3->neighbors = {node2, node4};
      node4->neighbors = {node1, node3};
    // test
      Solution solution;
      std::string expected = captureOutput([&]() {
        solution.printGraph(node1);
        }
      );
      cout<< "EXPECTED:";
      cout << expected<< endl;


      auto result = solution.dfs(node1);
      std::string output = captureOutput([&]() {
        solution.printGraph(result);
        }
      );
      cout<< "ACTUAL:";
      cout << output<< endl;
      // ASSERTION
      cout << (output == expected ? "PASS\n" : "FAIL\n");

  }
}
/**
 * main function
*/
int main(int argc, const char** argv) {
  test();
  return 0;
}


