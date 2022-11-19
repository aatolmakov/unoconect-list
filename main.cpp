#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>


using namespace std;


template <typename T>
struct node{
    T data = 0;
    node* next;
    node(T x){
    data = x;
    next = nullptr;
    }
};


template <typename T>
class list{
    node<T>* head;
public:
    list(){
        head = nullptr;
    }
    bool emptycheck();
    void push_front(T x);
    void push_back(T x);
    void pop_front();
    void pop_back();
    int find_elem(T x);
    void add_before(node<T>* ptr, T x);
    void delete_before(node<T>* ptr);
    list<T> operator+(list<T>);
    template <typename T2>
    friend ostream& operator<<(ostream& out, const list<T2> list);
};


template <typename T>
bool list<T>::emptycheck(){
    return head == nullptr;
}


template <typename T>
void list<T>::push_front(T x){
    node<T>* new_elem = new node<T>(x);
    new_elem -> next = head;
    head = new_elem;
}

template <typename T>
void list<T>::push_back(T x){
    node<T>* new_elem = new node<T>(x);
    node<T>* ptr = head;
    if(head == nullptr){
        head = new_elem;
        return;
    }
    node<T>* next = head;
    while(ptr -> next){
        ptr = ptr -> next;
    }
    ptr -> next = new_elem;
}

template <typename T>
void list<T>::pop_back(){
    node<T>* temp = head;
    if(head == nullptr){
        return;
    } else if(head -> next == nullptr){
        delete temp;
        head = nullptr;
    } else{
        while(temp -> next -> next){
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = nullptr;
    }
}


template <typename T>
void list<T>::pop_front(){
    if(head == nullptr){
    return;
    }
    node<T>* temp = head;
    head = head -> next;
    delete temp;
}

template <typename T>
int list<T>::find_elem(T x){
    node<T>* ptr = head;
    int index = -1;
    while(ptr -> next){
        index++;
        if(ptr -> data == x){
            return index;
        }
        ptr = ptr -> next;
    }
    if(ptr -> data != x){
        return -1;
    } else return index + 1;
}


template <typename T>
ostream& operator<<(ostream& out, const list<T> List){
    node<T>* ptr = List.head;
    while(ptr){
        out << ptr -> data << ' ';
        ptr = ptr -> next;
    }
    return out;
}

template <typename T>
void list<T>::add_before(node<T>* ptr, T x){
    node<T>* temp = head;
    while(temp -> next != ptr){
        temp = temp -> next;
    }
    node<T>* added = new node<T>;
    added -> next = ptr;
    added -> data = x;
    temp -> next = added;
}

template <typename T>
    void list<T>::delete_before(node<T>* ptr){
    node<T>* temp = head;
    while(temp -> next != ptr){
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = nullptr;
}
template <typename T>
    list<T> list<T>::operator+(list<T> a){
    list<T> ans;
    node<T>* temp1 = head;
    node<T>* temp2 = a.head;
    while(temp1){
        ans.push_back(temp1 -> data);
        temp1 = temp1 -> next;
    }
    while(temp2){
        ans.push_back(temp2 -> data);
        temp2 = temp2 -> next;
    }
    return ans;
}

int main(){
    //tests
}