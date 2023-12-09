#include <iostream>
#include <string.h>
using namespace std;

class stack
{

private:
    int top;
    unsigned capacity;
    char *array;

public:
    stack(unsigned capacity)
    {
        this->capacity = capacity;
        top = -1;
        array = new char[capacity];
    }

    bool is_empty()
    {
        return top == -1;
    }
    bool is_full()
    {
        return top == capacity - 1;
    }

    void push(char item)
    {
        if (is_full())
        {
            cout << "stack is overflow" << endl;
            return;
        }

        array[++top] = item;
    }

    char pop()
    {
        if (is_empty())
        {
            cout << "stack is underflow" << endl;
            return '\0';
        }
        return array[top--];
    }
};

bool is_palindrome(char str[], int length)
{
    stack charstack(length);

    // push cahracter from stack
    for (int i = 0; i < length; i++)
    {
        charstack.push(str[i]);
    }

    // pop character stack from reverse string
    for (int i = 0; i < length; i++)
    {
        char reversechar = charstack.pop();

        if (reversechar != str[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char orignalstring[100];
    cout << "enter a string " << endl;
    cin.getline(orignalstring, 100);
    int length = strlen(orignalstring);

    if (is_palindrome(orignalstring, length))
    {
        cout << "string is palindrome" << endl;
    }
    else
    {
        cout << "string is not palindrome";
    }

    return 0;
}