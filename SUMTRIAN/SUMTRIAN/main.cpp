#include <iostream>
#include <vector>

//TODO: Determine best process for summing nodes

class Node
{
private:
    int _value;
    Node *_leftChild;
    Node *_rightChild;

public:
    Node(int value, Node *leftChild = nullptr, Node *rightChild = nullptr)
        : _value(value), _leftChild(leftChild), _rightChild(rightChild) {}
    inline void setLeftChild(Node *child)
    {
        _leftChild = child;
    }
    inline void setRightChild(Node *child)
    {
        _rightChild = child;
    }
    inline int sum()
    {
        if (!_leftChild && !_rightChild)
            return _value;

    }
};

int main()
{
    std::vector<int> results;

    Node* first_node;
    std::vector<Node*> last_row;
    std::vector<Node*> cur_row;

    int num_cases;
    std::cin >> num_cases;

    do
    {
        int num_lines, cur_line;
        std::cin >> num_lines;
        cur_line = 1;
        last_row.clear();

        do
        {
            if (cur_line == 1)
            {
                int val;
                std::cin >> val;
                first_node = new Node(val);
                last_row.push_back(first_node);
            }
            else
            {
                int val;
                for (int i = 0; i < cur_line; i++)
                {
                    std::cin >> val;
                    cur_row.push_back(new Node(val));
                }
                val = 0;
                for (auto tNode : last_row)
                {
                    tNode->setLeftChild(cur_row[val]);
                    tNode->setRightChild(cur_row[val++]);
                }
            }

            cur_line++;
        } while (--num_lines > 0);

        //Calculate sums
    } while (--num_cases > 0);
}