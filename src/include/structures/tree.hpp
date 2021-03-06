#ifndef TREE_HPP_
#define TREE_HPP_

#include "node.hpp"

namespace structure {

  template <class mcolor_t, template <typename> class node_t = Node>
  struct BinaryTree {
    using colored_node_t = node_t<mcolor_t>;
    using tree_t = BinaryTree<mcolor_t, node_t>;
    using tree_ptr = std::shared_ptr<tree_t>;
    using branch_t = std::pair<mcolor_t, mcolor_t>;
    using node_ptr = typename colored_node_t::node_ptr;
    using node_const_ptr = typename colored_node_t::node_const_ptr;

    BinaryTree(node_ptr root_node) : root(root_node), phylogentic_root_tree(true) {
    }

    BinaryTree(
        std::string const& st,
        std::unordered_map<std::string, size_t> const& genome_number,
        std::vector<std::string> const& priority_name)
        : root(std::make_shared<colored_node_t>(nullptr, st, genome_number, priority_name)),
          phylogentic_root_tree(false) {
      if (mcolor_t(root->get_left_child()->get_data(), root->get_right_child()->get_data(), mcolor_t::Union).size() ==
          priority_name.size()) {
        phylogentic_root_tree = true;
      }
    }

    node_const_ptr get_root() const {
      return root;
    }

    bool is_phylogenetic_root() const {
      return phylogentic_root_tree;
    }

    friend std::ostream& operator<<(std::ostream& out, tree_ptr const& tree) {
      out << tree->get_root();
      return out;
    }

  private:
    node_ptr root;
    bool phylogentic_root_tree;

    DECL_LOGGER("BinaryTree")
  };

}

#endif
