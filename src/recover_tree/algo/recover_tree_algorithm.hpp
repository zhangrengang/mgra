#ifndef RECOVER_TREE_ALGORITHM_HPP
#define RECOVER_TREE_ALGORITHM_HPP

namespace algo {

template<class graph_pack_t>
struct RecoverTreeAlgorithm {
    using mcolor_t = typename graph_pack_t::mcolor_type;
    using tree_t = structure::phyl_tree::BinaryTree<mcolor_t>;
    using tree_ptr = std::shared_ptr<tree_t>;
    using algo_ptr = std::shared_ptr<RecoverTreeAlgorithm>;

    virtual std::vector<tree_ptr> recover_trees() = 0;

    std::vector<tree_ptr> get_result() {
        auto recovered_trees = recover_trees();
        std::for_each(std::begin(recovered_trees), std::end(recovered_trees), [this](tree_ptr const &tree) {
            return finalize_tree(tree);
        });
        return recovered_trees;
    }

    virtual tree_ptr finalize_tree(tree_ptr const & tree) const {
        return tree;
    }

    virtual ~RecoverTreeAlgorithm() {
    }
};

}

#endif
