#include <iostream>    // addding librarory 
#include <fstream>      /// for file management
#include <conio.h>
#include <string>
using namespace std;   
struct Node{
    string data;
    Node* next=NULL;
};
class Stack {
    private:
    Node * shead ;
    Node* top= shead;
     string data;
    public:
    Stack(){
        data="";
        shead=new Node();
    }
    void push(string data){
    if(shead==NULL)
        {
            shead->data=data;
             top= shead;
        }else{
            Node* node=new Node();
            node->data=data;
            top->next=node;
            top=node;
        }
  }
  string pop(){
    if(shead==NULL)
        return "";
    string item=top->data;
     if(top==shead){
        top= shead=NULL;
        
    }else{
        Node* current=shead;
        while(current->next!=top)
      current =  current->next;
     top=current;
     current->next=NULL;
    }
    return item;;
  }
  
};

class editor {

    private:
   Node* head=new Node();
   Stack undo ;
   Stack  redo ;
public:

void insert(){
    cout << "close the content by typing } at last" << endl;
    cout << " enter your text here  { ";
    Node* current=head;
    if(head==NULL)
       {
         cin >> head->data;
       }
    string word="";
    while( word != "}")  
    {
        Node* node = new Node();
        cin >> word;
         node->data=word;
         current->next=node;
         current=node;
    }  
}
void append(){
    cout << "close the content by typing } at last" << endl;
      Node* current=head;
        while(current->next !=NULL){
            cout << current->data  << " ";
            current= current->next;
        }
        cout << " " << "{  " ;
        string word ="";
        while(word != "}"){
            cin >> word ;
            Node* node =new Node();
            node->data=word;
            current->next=node;
            current =node;
        } 
}
void display(){
    cout << endl;
        Node* current=head;
        while(current->next !=NULL){
            cout << current->data  << " ";
            current= current->next;
        }
        cout << endl;
}
void update(){
    cout << "enter the word you want to replace " << endl;
    string word;
    cin >> word;
      if( word == " ") 
     {
         cout << "sorry you missed it  try again" << endl;
         return;
     }
    Node* current = head;
    while(current->data!=word and current!=NULL)
       current=current->next;
    if(current!=NULL)
        {
            cout << "enter the  new  word" << endl;;
            string new_word;
            cin >> new_word;
            current->data=new_word;
            cout << endl << "data updated"<< endl;
        }
    if(current==NULL)
      cout << "word not fount" << endl ;
}
void delete_word(){
    cout << endl;
    cout << "enter the word you want to delete "  << endl;
    string word;
    cin >> word;
    if( word == " ") 
     {
         cout << "sorry you missed it  try again" << endl;
         return;
     }
    Node* current=head;
    Node* prv = head;
    while( current!=NULL and current->data!=word ){
        cout << current->data << endl;
        prv=current;
        current=current->next;
    }
    cout <<"curren " << endl;
    if(current->data==word){
            prv->next=current->next;
            delete(current);
            cout <<  "word deleted " << endl;
            return;
    }
    cout <<"word not found" << endl;
    

}
void delete_all_data(){
    while(head!=NULL){
         Node* current=head;
         head=head->next;
         delete(current);
    }
    cout << "data data deleted" << endl;
}
void search(){
    cout << "Enter the word you want to search " << endl;
    string word;
    cin >> word;
    if( word == " ") 
     {
         cout << "sorry you missed it  try again" << endl;
         return;
     }
    Node* current=head;
    while(current->data!=word and current!=NULL)
        current=current->next;
    if(current->data==word){
        cout << current->data << " is written in our file" << endl;
        return ;
    }else
    cout << "sorry no match found" << endl;
}

void  undo_op(){

}



};

int input(){
    int in;
cout << " pleae enter the number  indicating the operation you want to perform" << endl;
    cout << " 1 for create new file"<< endl;
    cout << " 2 for  writing new content"  << endl;
       cin >> in;
       return in;
}
int main(){
      editor ed;
      ed.insert();
      ed.display();
      ed.delete_word();
      ed.display();
}