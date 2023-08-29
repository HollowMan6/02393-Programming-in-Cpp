#include <iostream>
#include <vector>

class TreeNode {
   public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* fibonacci_tree(int n) {
    if (n == 0 || n == 1) {
        return new TreeNode(1);
    }

    TreeNode* root = new TreeNode(n);
    root->left = fibonacci_tree(n - 2);
    root->right = fibonacci_tree(n - 1);
    return root;
}

void pre_order_traversal(TreeNode* node, std::vector<int>& result) {
    if (node == nullptr) {
        return;
    }
    result.push_back(node->value);
    pre_order_traversal(node->left, result);
    pre_order_traversal(node->right, result);
}

int tree_size(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + tree_size(node->left) + tree_size(node->right);
}

int tree_depth(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int left_depth = tree_depth(node->left);
    int right_depth = tree_depth(node->right);
    return 1 + std::max(left_depth, right_depth);
}

int count_leaves(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    if (node->left == nullptr && node->right == nullptr) {
        return 1;
    }
    return count_leaves(node->left) + count_leaves(node->right);
}

void fibonacci_info(int n) {
    TreeNode* root = fibonacci_tree(n);
    std::vector<int> pre_order;
    pre_order_traversal(root, pre_order);
    int size = tree_size(root);
    int depth = tree_depth(root);
    int leaves = count_leaves(root);

    std::cout << "Call tree in pre-order:";
    for (int val : pre_order) {
        std::cout << " " << val;
    }
    std::cout << std::endl;
    std::cout << "Call tree size: " << size << std::endl;
    std::cout << "Call tree depth: " << depth << std::endl;
    std::cout << "Call tree leaves: " << leaves << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    fibonacci_info(n);
    return 0;
}
