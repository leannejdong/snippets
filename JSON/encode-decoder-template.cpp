// left is chile right is sibling
#include<cassert>
#include<memory>
#include<vector>

namespace trees{
  template<class T>
  struct binary{
    T value;
    std::unique_ptr<binary<T>> left,
                               right;
  };
  template<class T>
  struct nary{
    T value;
    std::vector<nary<T>> children;
    
    auto operator<=>(const nary &)const = default;
  };
}

namespace trees{

  namespace detail{
    template<class T>
    std::unique_ptr<binary<T>> nary_to_binary_ptr_impl(const nary<T> &nary_parent,std::size_t index = 0ul){
      auto &nary_child = nary_parent.children[index];
      auto binary_child = std::make_unique<binary<T>>(binary{nary_child.value});
      if(nary_child.children.size())
        binary_child->left = nary_to_binary_ptr_impl(nary_child);
      if(index + 1 < nary_parent.children.size())
        binary_child->right = nary_to_binary_ptr_impl(nary_parent,index + 1);
      return binary_child;
    }
  }
  auto nary_to_binary(const auto &nary_tree){
    auto binary_tree = binary{nary_tree.value};
    if(nary_tree.children.size())
      binary_tree.left = detail::nary_to_binary_ptr_impl(nary_tree);
    return binary_tree;
  }

  template<class T>
  nary<T> binary_to_nary(const binary<T> &binary_tree){
    auto nary_tree = nary{binary_tree.value};
    for(auto binary_child = binary_tree.left.get();
        binary_child != nullptr;
        binary_child = binary_child->right.get())
      nary_tree.children.push_back(binary_to_nary(*binary_child));
    return nary_tree;
  }
 
}

int main(){
  trees::nary tree{
    .value = 1,
    .children = {
      {.value = 3,
       .children = {
         {.value = 5},
         {.value = 6}}},
      {.value = 2},
      {.value = 4}
    }
  };
  assert(tree == trees::binary_to_nary(trees::nary_to_binary(tree)));
}

/* first make the current-tree on 44, then on 45 in the for-loop initializer pick up the child on the left 
(child on left / sibling on right is the strategy).
and then walk over all the siblings of the child and add as children on the nary equivalent.
binary_child = binary_child->right.get() on line 47 is moving to next sibling.
the assert on line 67 checks that the "recoding" of the tree on line 55 is equivalent 
(ie was encoded and decoded without changing it).*/

// Thanks to John


