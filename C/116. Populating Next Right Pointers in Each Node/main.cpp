#include <cstdio>
#include <cmath>
#include <queue>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

Node* createTree(std::vector<int> nodes)
{

    std::vector<Node*> next = std::vector<Node*>();
    Node* root = new Node(nodes.front());
    next.push_back(root);
    nodes.erase(nodes.begin());

    while(!nodes.empty())
    {
        next.front()->left = new Node(*nodes.begin());
        next.push_back(next.front()->left);
        nodes.erase(nodes.begin());

        if (!nodes.empty())
        {
            next.front()->right = new Node(*nodes.begin());
            next.push_back(next.front()->right);
            nodes.erase(nodes.begin());
        }

        next.erase(next.begin());
    }

    return root;
}

Node* connect(Node* root)
{
    if (root == nullptr)
        return nullptr;

    std::queue<Node*> nextQueue;
    nextQueue.push(root);
    int level = 0;
    int currentOffset;
    Node* aux = nextQueue.front();

    while(!nextQueue.empty())
    {
        currentOffset = std::pow(2, level++);

        for(int i = 0; i < currentOffset-1; i += 1)
        {
            aux = nextQueue.front();
            nextQueue.pop();
            aux->next = nextQueue.front();
            if (aux->left != nullptr)
            {
                nextQueue.push(aux->left);
                nextQueue.push(aux->right);
            }
        }

        aux = nextQueue.front();
        nextQueue.pop();
        aux->next = nullptr;

        if (aux->left != nullptr)
        {
            nextQueue.push(aux->left);
            nextQueue.push(aux->right);
        }
    }

    return root;
}

int main(int argc, char** argv)
{
    Node* root = createTree({1,2,3,4,5,6,7});
    Node* newRoot = connect(root);
    return 0;
}
