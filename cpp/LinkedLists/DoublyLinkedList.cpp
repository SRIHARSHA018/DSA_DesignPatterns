#include<iostream>



template<typename T>
class Node{
    public:
        T data;
        Node* next;
        Node* prev;
        Node(T data){
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

template<typename T>
class DoublyLinkedList{
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        DoublyLinkedList():head(nullptr),tail(nullptr){}
        ~DoublyLinkedList(){
            Node<T>* curr = this->head;
            while(curr!=nullptr){
                Node<T>* temp = curr->next;
                delete curr;
                curr = temp;
            }
        }
        
        void insertFront(T data){
            Node<T>* new_node = new Node<T>(data);
            if(this->head==nullptr){
                this->head = new_node;
                this->tail = new_node;
                return;
            }
            new_node->next = this->head;
            this->head->prev = new_node;
            this->head = new_node;
        }

        void display(){
            if(this->head==nullptr){
                std::cout<<"List is empty"<<std::endl;
                return;
            }
            Node<T>* it = this->head;
            while(it!=nullptr){
                std::cout<<it->data<<" ";
                it=it->next;
            }
            std::cout<<std::endl;
        }

        void insertEnd(T data){
            Node<T>* new_node = new Node<T>(data);
            if(this->head==nullptr){
                this->head = new_node;
                this->tail = new_node;
                return;
            }
            this->tail->next = new_node;
            new_node->prev = this->tail;
            this->tail = new_node;
        }

        bool deleteNode(T data){
            if(this->head==nullptr){
                std::cout<<"List is empty to delete"<<std::endl;
                return false;
            }
            Node<T>* curr  = this->head;
            while(curr->next!=nullptr && curr->data!=data){
                curr = curr->next;
            }
            if(curr->next==nullptr && curr->data!=data){
                return false;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            curr->next = nullptr;
            curr->prev = nullptr;
            delete curr;
            return true;
        }

};

int main() {
    DoublyLinkedList<int> list;

    std::cout << "Inserting elements at the front:" << std::endl;
    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.display(); // Expected output: 30 20 10

    std::cout << "\nInserting elements at the end:" << std::endl;
    list.insertEnd(40);
    list.insertEnd(50);
    list.display(); // Expected output: 30 20 10 40 50

    std::cout << "\nDeleting a node with value 20:" << std::endl;
    if (list.deleteNode(20)) {
        std::cout << "Node deleted successfully." << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }
    list.display(); // Expected output: 30 10 40 50

    std::cout << "\nDeleting a non-existent node (value 100):" << std::endl;
    if (list.deleteNode(100)) {
        std::cout << "Node deleted successfully." << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }
    list.display(); // Expected output: 30 10 40 50

    return 0;
}
