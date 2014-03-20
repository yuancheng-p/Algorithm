/* A stack with a getMin function which can return the minimum value in the stack;
 * All the pop, push, getMin functions are of complexity O(1)
 *
 * Mar 20 2014
 */
#include <iostream>
using namespace std;
#define SIZE 20


class Element
{
    public:
        Element(int value=0, int min_index=0, int pre_min_index=0)
        {
            this->value = value;
            this->min_index = min_index;
            this->pre_min_index = pre_min_index;
        }

    int value;
    int min_index;
    int pre_min_index;
};


class MinStack
{
    public:
        MinStack()
        {
            this->top = -1;
        }

        int pop()
        {
            if (-1 != top)
            {
                return e[top--].value;
            }
            else
            {
                cout << "the stack is empty!" << endl;
                return -1;
            }
        }

        void push(int value)
        {
            if (-1 == top)
            {
                this->e[++top].value = value;
                this->e[top].min_index = top;
                this->e[top].pre_min_index = top;
            }

            if (SIZE == top)
            {
                cout << "the stack is full!" << endl;
            }

            this->e[++top].value = value;

            if (value < this->e[e[top - 1].min_index].value)
            {
                this->e[top].min_index = top;
                this->e[top].pre_min_index = this->e[top - 1].min_index;
            }
            else
            {
                this->e[top].min_index = this->e[top - 1].min_index;
                this->e[top].pre_min_index = this->e[top - 1].pre_min_index;
            }
        }

        int getMin()
        {
            if (-1 != top)
            {
                return this->e[e[top].min_index].value;
            }
            else
            {
                cout << "the stack is empty!" << endl;
                return -1;
            }
        }

    private:
        Element e[SIZE];
        int top;
};


int main()
{
    MinStack stack;
    cout << "we push 8, 6, 4, 7 in the stack" << endl;
    stack.push(8);
    stack.push(6);
    stack.push(4);
    stack.push(7);
    cout << "the min is the stack:" << endl;
    cout << stack.getMin() << endl;

    cout << "pop two top elements:" << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    cout << "the min in the stack now:" << endl;
    cout << stack.getMin() << endl;

    return 0;
}
