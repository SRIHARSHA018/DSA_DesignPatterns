#include<iostream>
#include<vector>

template<typename T>
class Node{
    public:
        T data;
        Node* next = nullptr;
};

template<typename TL>
class LinkedList{
    private:
        Node<TL>* _head = nullptr;
    
    public:
        LinkedList(){
            this->_head = nullptr;
        }
        ~LinkedList(){
            delete this->_head;
        }
        bool isEmpty(){
            return this->_head == nullptr;
        }
        void insertAt(TL data, int position){
            if(this->isEmpty()){
                this->insertNode(data);
                return;
            }
            Node<TL>* newnode = new Node<TL>();
            newnode->data = data;
            if(position==1){
                newnode->next = this->_head;
                this->_head = newnode;
                return;
            }            
            Node<TL>* curr_temp = this->_head;
            Node<TL>* prev_temp = this->_head;
            int pos_tracker = 1;
            while(curr_temp->next!=nullptr){
                if(pos_tracker == position-1){
                    curr_temp = curr_temp->next;
                    newnode->next = curr_temp;
                    prev_temp->next = newnode;
                    return;
                }
                pos_tracker++;
                prev_temp = prev_temp->next;
            }
            return;
        }
        void insertNode(TL data){
            Node<TL>* node = new Node<TL>();
            node->data = data;
            if(this->isEmpty()){
                this->_head = node;
                return;
            }
            Node<TL>* temp = this->_head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next = node;
            return;
        }
        void deleteNode(int position){
            if(this->isEmpty()){
                std::cout<<"List is empty";
                return;
            }
            Node<TL>* temp = this->_head;
            Node<TL>* prev_temp = this->_head;
            int pos_tracker = 1;
            if(position == 1){
                this->_head = this->_head->next;
                delete temp;
                return;
            }
            while(temp != nullptr){
                temp = temp->next;
                if(pos_tracker == position-1){
                    prev_temp->next = temp->next;
                    temp->next =nullptr;
                    delete temp;
                    return;
                }
                prev_temp=prev_temp->next;
                pos_tracker++;
            }
            if(pos_tracker<position){
                std::cout<<"Position out of range"<<std::endl;
            }
            return;

        }
        void display(){
            if(this->isEmpty()){
                std::cout<<"List is empty"<<std::endl;
                return;
            }
            Node<TL>* temp = this->_head;
            while(temp!=nullptr){
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }
            std::cout<<std::endl;
            return;
        }

};

int main(){
    LinkedList<int> lt;
    lt.insertNode(10);
    lt.insertNode(18);
    lt.insertNode(100);
    lt.display();
    lt.deleteNode(2);
    lt.deleteNode(1);
    lt.display();
    return 0;
}