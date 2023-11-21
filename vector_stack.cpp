#include <iostream>
#include <string>
#include <string_view>
#include <vector>

void printStack(const std::vector<int>& stack)
{
    std::cout << "\t(Stack:";
    
    for (auto element : stack)
        std::cout << " " << element;

    if (stack.empty())
        std::cout << " empty";

    std::cout << ")\n";
}

void pushAndPrint(std::vector<int>& stack, int val)
{
    stack.emplace_back(val);
    std::cout << "Push " << val;
    printStack(stack);
}

void popAndPrint(std::vector<int>& stack)
{
    stack.pop_back();
    std::cout << "Pop ";
    printStack(stack);
}

int main(){
    std::vector<int> stack{};

    printStack(stack);
    pushAndPrint(stack, 1);
    pushAndPrint(stack, 2);
    pushAndPrint(stack, 3);
    popAndPrint(stack);
    pushAndPrint(stack, 4);
    popAndPrint(stack);
    popAndPrint(stack);
    popAndPrint(stack);

    return 0;
}
