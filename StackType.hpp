#include <string>
using namespace std;

struct NodeType {
    string data;
    NodeType* next;
};

class StackType {
    public: 
        StackType();
        ~StackType();
        void Push(string input);
        void Pop();
        string Top();
        bool IsEmpty() const;
        bool IsFull() const;

    private:
        string top;
        //NodeType* topPtr;  //not sure if adding "= nullptr;" is ok or not
        NodeType* topPtr = NULL;
        const int MAX_ITEMS = 50;
        array<string, 50> items;
};