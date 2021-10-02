#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;

template<typename T>

class Node{
    public:

    T data;
    Node<T> *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template<typename T>

class Stack{

    Node<T> *head;
    int size;
    public:

    Stack(){
        head = NULL;
        size = 0;
    }

    void push(T data){
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop(){
        if(head==NULL){
            cout<<"Empty Stack"<<endl;
            return 0;
        }
        T data = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return data;
    }

    T top(){
        if(head==NULL){
            cout<<"Empty Stack"<<endl;
            return 0;
        }
        return head->data;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return head==NULL;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;

    cout<<s1.top()<<endl;

    cout<<s1.getSize()<<endl;
    cout<<s1.isEmpty()<<endl;

    Stack<char> s2;
    s2.push('a');
    s2.push('b');
    s2.push('c');
    s2.push('d');
    s2.push('e');

    cout<<s2.top()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;
    cout<<s2.pop()<<endl;

    cout<<s2.top()<<endl;

    cout<<s2.getSize()<<endl;
    cout<<s2.isEmpty()<<endl;
    
    return 0;
}
