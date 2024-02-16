#include<iostream>
#include<vector>

template<typename T>
class Queue{
    private:
        std::vector<T> _internal_stack;
    public:
        void push(T element){
            this->_internal_stack.emplace_back(element);
        }
        bool isEmpty(){
            return this->_internal_stack.empty();
        }

        T pop(){
            if(this->isEmpty()){
                throw std::out_of_range("Stack is empty");
            }
            T element = this->_internal_stack.front();
            this->_internal_stack.erase(this->_internal_stack.begin());
            return element;
        }
        T peek(){
            if(this->isEmpty()){
                throw std::out_of_range("Stack is empty");
            }
            return this->_internal_stack.front();
        }
        void display(){
            if(this->isEmpty()){
                std::cout<<"Empty queue"<<std::endl;
            }
            // std::vector<T>::iterator it = this->_internal_stack.begin();
            for(auto it = this->_internal_stack.begin();it!=this->_internal_stack.end();it++){
                std::cout<<*it<<" ";
            }
            std::cout<<std::endl;
        }

};

int main(){
    // for integer
    Queue<int> st;
    st.push(11);
    st.push(12);
    st.push(10);
    st.display();
    st.pop();
    st.display();
    st.peek();
    st.display();
    // for strings
    Queue<std::string> st1;
    st1.push("Hey there");
    st1.push("I am sri");
    st1.display();
    st1.pop();
    st1.display();
    return 0;
}