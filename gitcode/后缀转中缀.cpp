#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;
};

bool isOperator(const string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

TreeNode* createExpressionTree(const string& postfix) {
    stack<TreeNode*> nodeStack;
    string token;
    size_t pos = 0;

    while ((pos = postfix.find(" ")) != string::npos) {
        token = postfix.substr(0, pos);
        postfix.erase(0, pos + 1);

        if (!isOperator(token)) {
            TreeNode* node = new TreeNode();
            node->value = token;
            node->left = nullptr;
            node->right = nullptr;
            nodeStack.push(node);
        } else {
            TreeNode* rightNode = nodeStack.top();
            nodeStack.pop();

            TreeNode* leftNode = nodeStack.top();
            nodeStack.pop();

            TreeNode* operatorNode = new TreeNode();
            operatorNode->value = token;
            operatorNode->left = leftNode;
            operatorNode->right = rightNode;

            nodeStack.push(operatorNode);
        }
    }

    return nodeStack.top();
}

void printExpressionTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printExpressionTree(root->left);
    cout << root->value << " ";
    printExpressionTree(root->right);
}

int main() {
    string postfix = "5 7 + 4 *";
    TreeNode* expressionTree = createExpressionTree(postfix);

    cout << "Infix Expression: ";
    printExpressionTree(expressionTree);

    return 0;
}
