#include <cstdio>
#include <vector>
#include <queue>
#include <cstdlib>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* createTree(std::vector<TreeNode*> nodes)
{
    std::vector<TreeNode*> next = std::vector<TreeNode*>();
    TreeNode* root = nodes.front();
    next.push_back(nodes.front());
    nodes.erase(nodes.begin());

    while(!nodes.empty())
    {
        next.front()->left = *nodes.begin();
        next.push_back(next.front()->left);
        nodes.erase(nodes.begin());

        if (!nodes.empty())
        {
            next.front()->right = *nodes.begin();
            next.push_back(next.front()->right);
            nodes.erase(nodes.begin());
        }

        next.erase(next.begin());
    }

    return root;
}

// Função com três queues pra retornar uma árvore nova
TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
{
    if (!root1 || !root2)
        return !root1 ? (!root2 ? nullptr : root2) : root1;

    std::queue<TreeNode**> next;
    std::queue<TreeNode**> next1;
    std::queue<TreeNode**> next2;

    TreeNode* root = new TreeNode(root1->val + root2->val, new TreeNode(), new TreeNode());

    next.push(&root->left);
    next.push(&root->right);

    next1.push(&root1->left);
    next1.push(&root1->right);

    next2.push(&root2->left);
    next2.push(&root2->right);

    while(!next.empty())
    {
        if (*next1.front() == nullptr && *next2.front() == nullptr)
        {
            *next.front() = nullptr;
        }
        else
        {
            if ((*next1.front()) == nullptr)
            {
                (*next.front())->val = (*next2.front())->val;
                (*next.front())->left = (*next2.front())->left;
                (*next.front())->right = (*next2.front())->right;
            }
            else if (*next2.front() == nullptr)
            {
                (*next.front())->val = (*next1.front())->val;
                (*next.front())->left = (*next1.front())->left;
                (*next.front())->right = (*next1.front())->right;
            }
            else
            {
                (*next.front())->val = (*next1.front())->val + (*next2.front())->val;
                (*next.front())->left = new TreeNode();
                (*next.front())->right = new TreeNode();
                next.push(&(*next.front())->left);
                next.push(&(*next.front())->right);

                next1.push(&(*next1.front())->left);
                next1.push(&(*next1.front())->right);

                next2.push(&(*next2.front())->left);
                next2.push(&(*next2.front())->right);
            }
        }

        next.pop();
        next1.pop();
        next2.pop();
    }

    return root;
}

void recursiveMerge(TreeNode* &root, TreeNode* root1, TreeNode* root2)
{
    if (root1 == nullptr && root2 == nullptr)
    {
        root = nullptr;
        return;
    }
    if (root1 == nullptr)
    {
        root = new TreeNode(root2->val, root2->left, root2->right);
        return;
    }
    if (root2 == nullptr)
    {
        root = new TreeNode(root1->val, root1->left, root1->right);
        return;
    }

    root = new TreeNode(root1->val + root2->val);

    recursiveMerge(root->left, root1->left, root2->left);
    recursiveMerge(root->right, root1->right, root2->right);

}

TreeNode* recursiveMergeTrees(TreeNode* root1, TreeNode* root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return nullptr;
    if (root1 == nullptr || root2 == nullptr)
        return root1 == nullptr ? root2 : root1;

    TreeNode* root = new TreeNode(root1->val + root2->val);

    recursiveMerge(root->left, root1->left, root2->left);
    recursiveMerge(root->right, root1->right, root2->right);

    return root;
}

int main(int argc, char** argv)
{
    std::vector<TreeNode*> tree1 = std::vector<TreeNode*>({
        new TreeNode(1),
        new TreeNode(3),
        new TreeNode(2),
        new TreeNode(5)
    });
    std::vector<TreeNode*> tree2 = std::vector<TreeNode*>({
        new TreeNode(2),
        new TreeNode(1),
        new TreeNode(3),
        nullptr,
        new TreeNode(4),
        nullptr,
        new TreeNode(7)
    });

    TreeNode* root1 = createTree(tree1);
    TreeNode* root2 = createTree(tree2);

//    auto result = mergeTrees(root1, root2);
    auto result = recursiveMergeTrees(root1, root2);

    return 0;
}
