#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

class FibonacciTree {
public:
    TreeNode* buildTree(int n) {
        if (n <= 1) {
            return new TreeNode(1);
        }
        TreeNode* root = new TreeNode(fibonacci(n + 1));
        root->left = buildTree(n - 1);
        root->right = buildTree(n - 2);
        return root;
    }

    void preOrderTraversal(TreeNode* node) {
        if (node != NULL) {
            cout << node->val << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    int calculateSize(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + calculateSize(node->left) + calculateSize(node->right);
    }

    int calculateDepth(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftDepth = calculateDepth(node->left);
        int rightDepth = calculateDepth(node->right);
        return 1 + max(leftDepth, rightDepth);
    }

    int calculateleafs(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        if (node->left == NULL && node->right == NULL) {
            return 1;
        }
        return calculateleafs(node->left) + calculateleafs(node->right);
    }
};

int main() {
    int n;
    cin >> n;

    FibonacciTree fibTree;
    TreeNode* root = fibTree.buildTree(n);

    cout << "Call tree in pre-order: ";
    fibTree.preOrderTraversal(root);
    cout << endl;

    cout << "Call tree size: " << fibTree.calculateSize(root) << endl;
    cout << "Call tree depth: " << fibTree.calculateDepth(root) << endl;
    cout << "Call tree leafs: " << fibTree.calculateleafs(root) << endl;

    return 0;
}
