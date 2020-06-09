#include <iostream>


class Stack{
private:
    int *_stk;
    int _size;
    int TOP;
    inline bool underflow(){ return (TOP == -1);}
    inline bool overflow(){ return (TOP == _size - 1);}
public:
    Stack(int size);
    ~Stack();
    void push(int item);
    int pop();
    bool isEmpty();
    void display();
};

Stack::Stack(int size){
    _stk = new int[size]; 
    TOP = -1;
    _size = size;
}

Stack::~Stack(){
    delete[] _stk; 
}

void Stack::push(int item){
    if(this -> overflow()){
        std::cout << "Error, overflow\n";
        return;
    }
    else{
        _stk[++TOP] = item;
    }
}

int Stack::pop(){
    if(this -> underflow()){
        std::cout << "Error, underflow\n";
        return 0;
    }
    else{
        return _stk[TOP--];
    }
}

bool Stack::isEmpty(){
    return (TOP == -1);
}

void Stack::display(){
    if(this -> isEmpty()){
        std::cout << "The stack is empty!\n";
        return;
    }
    else{
        for (size_t i = 0; i <= TOP; i++)
        {
            std::cout << _stk[i] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    Stack stack(10);
    int choice = 999;

    while(choice != 0){
        std::cin >> choice;
        int item = 0;
        switch(choice){
            case 1: //push
                std::cin >>item;
                stack.push(item);
                break;

            case 2: //pop
                std::cout << "The popped item is: " << stack.pop() << "\n";
                break;

            case 3: //display
                stack.display();
                break;
                
            case 4:
                std::cout << stack.isEmpty() << "\n";
                break;

            default:
                std::cout << "wrong choice\n";
        }
    }
    return 0;
}