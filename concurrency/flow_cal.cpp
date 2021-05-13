#include <cstdio>
#include "tbb/flow_graph.h"
#include <fmt/core.h>

using namespace tbb::flow;

auto square(){
    return [](int v){ return v*v; };
}
auto cube(){
    return [](int v){ return v*v*v; };
}
class sum {
  int &my_sum;
public:
  sum( int &s ) : my_sum(s) {}
  int operator()( tuple< int, int > v ) {
    my_sum += get<0>(v) + get<1>(v);
    return my_sum;
  }
};

int main() {
  int result = 0;

  graph g;
  broadcast_node<int> input(g); 
  function_node<int,int> squarer( g, unlimited, square() );
  function_node<int,int> cuber( g, unlimited, cube() );
  join_node< tuple<int,int>, queueing > join( g );
  function_node<tuple<int,int>,int>
      summer( g, serial, sum(result) );
  make_edge( input, squarer );
  make_edge( input, cuber );
  make_edge( squarer, get<0>( join.input_ports() ) );
  make_edge( cuber, get<1>( join.input_ports() ) );
  make_edge( join, summer );
  for (int i = 1; i <=10; ++i)
      input.try_put(i);
  g.wait_for_all();

  fmt::print("Final result is {}.", result);
  return 0;
}

//https://www.threadingbuildingblocks.org/docs/help/reference/flow_graph/message_flow_graph_example.html
