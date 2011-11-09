/* 
 * File:   main.cpp
 * Author: davidbethke
 *
 * Created on November 8, 2011, 8:59 PM
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * 
 */
template<class T>
class queue{
    T *first, *last;
    string qName;
public:
    queue(string n="",T *f=NULL, T*l=NULL):qName(n),first(f),last(l){}
    void enqueue(string);
    void enqueue(T*);
    void dequeue();
    void showqueue();
    void insert(string, int);
    bool insertAfter(string,string);
    T* getItem(string);
    string getQName();
};
struct node{
    string name;
    node *next;
    node(string n="",node *p=NULL):name(n),next(p){}
};
struct node2{
    string name;
    node2 *next;
    node2(string n="",node2 *p=NULL):name(n),next(){}
};
struct Course{
    string name;
    string description;
    Course *next;
    Course(string n="",string d="",Course *p=NULL):name(n),description(d),next(p){}
};
class Student{
public:
    string name;
    string id;
    Student *next;
    queue<Course> *courses;
    Student(string n="", string i="", queue<Course> *c=new queue<Course>("CourseList"), Student *p=NULL):name(n),id(i),courses(c),next(p){}
    void setCourse(Course );
    
};

int main(int argc, char** argv) {
    queue<node> q1;
    queue<node2> q2;
    queue<Student> s1("StudentList");
    s1.enqueue("Student1");
    
    s1.enqueue("Student2");
    s1.enqueue("Student3");
    s1.enqueue("Student4");
    s1.enqueue(new Student("Student5","005",new queue<Course>("CourseList5")));
    
    s1.showqueue();
    Student *temp;
    temp=s1.getItem("Student1");
    if(temp){
        temp->id="001";
       
        temp->courses->enqueue("Course1");
        temp->courses->getItem("Course1")->description="Im a Course1";
    }
    else
        cout << "Student1 not found"<<endl;
    cout <<"id"<<endl;
    cout <<temp->id<<endl;
    cout <<temp->courses->getItem("Course1")->name<<endl;
    cout <<temp->courses->getItem("Course1")->description<<endl;
    
    temp=s1.getItem("Student2");
    if(temp){
        temp->id="002";
       
        temp->courses->enqueue("Course2");
        temp->courses->getItem("Course2")->description="Im a Course2";
    }
    else
        cout << "Student2 not found"<<endl;
    cout <<"id"<<endl;
    cout <<temp->id<<endl;
    cout <<temp->courses->getItem("Course2")->name<<endl;
    cout <<temp->courses->getItem("Course2")->description<<endl;
    
    temp=s1.getItem("Student5");
    cout <<"id05"<<endl;
    cout <<temp->id<<endl;
    cout <<temp->courses->getQName()<<endl;
    temp->courses->enqueue(new Course("Course5","im a Course5"));
    //temp->courses->getItem("Course5")->description="Im Course5";
    cout <<temp->courses->getItem("Course5")->description<<endl;
    
    
    /*
    q1.enqueue("Dave");
    q2.enqueue("Kitty");
    q1.enqueue("Elsa");
    q2.enqueue("Target");
    q1.showqueue();
    q2.showqueue();
    q1.dequeue();
    q1.showqueue();
    //q2.dequeue();
    //q2.showqueue();
    q1.enqueue("person1");
    q1.enqueue("person2");
    q1.enqueue("person3");
    q1.showqueue();
    cout << "Insert at pos 3"<<endl;
    q1.insert("InsertedPerson", 3);
    q1.showqueue();
    if(q2.insertAfter("Kitty","Tony"))
    {
        cout << "InsertAfter success"<<endl;
        q2.showqueue();
    }
    else{
        cout<<"InsertAfter failed"<<endl;
        q2.showqueue();
    }
     */
    return 0;
}
template<class T>
void queue<T>::enqueue(string name){
    T *temp=new T(name);
    if (first==NULL) first=temp;
    else last->next=temp;
    last=temp;
       
}
template<class T>
void queue<T>::enqueue(T *t){
    if(first==NULL)first=t;
    else last->next=t;
    last=t;
}
template<class T>
void queue<T>::dequeue(){
    if(first== NULL){cout << "Empty List"<<endl;return;}
    T *temp=first;
    first=first->next;
    delete temp;
}
template<class T>
void queue<T>::showqueue(){
    T *temp=first;
    cout<<qName<<" Queue Start--"<<endl;
    while(temp!=NULL){
        cout << temp->name<<endl;
        temp=temp->next;
    }
    cout<<"Queue End--"<<endl;
}
template<class T>
void queue<T>::insert(string n, int pos){
    T *temp=first;
    T *iTemp= new T(n);
    for(int i=0; i<pos;i++)
    {
        if(temp==NULL){cout <<"Invalid Insert Position"<<endl;return;}
        temp=temp->next;
    }
    iTemp->next=temp->next;
    temp->next=iTemp;
    
}
template<class T>
bool queue<T>::insertAfter(string p1, string p2){
    T *temp=first;
    T *iTemp= new T(p2);
    bool success=false;
    while(temp != NULL){
        if (temp->name== p1){
            iTemp->next=temp->next;
            temp->next= iTemp;
            success=true;
        }
        temp=temp->next;
    }
    return success;
    
}
template<class T>
T* queue<T>::getItem(string n){
    T *temp2=NULL;
    T *temp=first;
    while(temp != NULL){
        if(temp->name == n)
            return temp; 
        temp=temp->next;
    }
    return temp2;
}
void Student::setCourse(Course c){
    courses->enqueue(c.name);
}
template<class T>
string queue<T>::getQName(){
    return qName;
}

