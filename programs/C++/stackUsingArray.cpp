#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = (int)1e9 + 7;

template<typename T>

class Stack{
    private:
        int nextIndex;
        T *data;
        int capacity;
    
    public:
        Stack(){
            capacity = 4;
            data = new T[capacity];
            nextIndex = 0;
        }

        void push(T element){
            if(nextIndex == capacity){
                capacity*=2;
                T *newData = new T[capacity];
                for(int i=0;i<nextIndex;i++){
                    newData[i] = data[i];
                }
                delete [] data;
                data = newData;
                // cout<<"Stack full:(\n";
                // return ;
            }
            data[nextIndex++] = element;
        }

        T pop(){
            if(nextIndex == 0){
                cout<<"Stack empty:(\n";
                return 0; // INT_MIN #include <climits>
            }
            return data[--nextIndex];
        }

        T top(){
            if(nextIndex == 0){
                cout<<"Stack empty:(\n";
                return 0; // INT_MIN #include <climits>
            }
            return data[nextIndex-1];
        }

        int size(){
            return nextIndex;
        }

        bool isEmpty(){
            return nextIndex==0;
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

    cout<<s1.size()<<endl;
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

    cout<<s2.size()<<endl;
    cout<<s2.isEmpty()<<endl;
    
    return 0;
}
