/*
 cse 331 hw3, Chenshu Xu, 02/15/2017
 */

#include <fstream>
using namespace std;
#include<iostream>
using std::cin; using std::cout; using std::endl;using std::ostream;

#include<string>
using std::string;
#include <random>

template<typename T>
class Node {
private:
    T data_; //data carries the number
    Node* right_child; //right child points to the node on the right
    Node* left_child; //left child points to the node on the left
public:
    Node();
    Node(T data);
    void insert(T);
    void insert(Node<T>*&, Node<T>*&);
    void pre_orderDFS_print();
    void in_orderDFS_print();
    void post_orderDFS_print();
    string pre_order_str(Node<T>*, string);
    string in_order_str(Node<T>*, string);
    string post_order_str(Node<T>*, string);
};

/*
 default constructor
 */
template<typename T>
Node<T>::Node(){
    data_ = NULL;
    right_child = nullptr;
    left_child = nullptr;
}

/*
 Constructor that creates a Node and sets its data to a value of type T
 */
template<typename T>
Node<T>::Node(T data){
    data_ = data;
    right_child = nullptr;
    left_child = nullptr;
}

/*
 insert method
 takes a value of type T
 creates a new node
 sets the new node in left child subtree if value is smaller or equal to
 father node
 sets the new node in right child subtree if value is bigger than father node
*/
template<typename T>
void Node<T>::insert(T s){
    Node<T>* n = new Node<T>(s);
    Node<T>* a = this;
    insert(a, n);
    
}

/*
 insert recurse function
 */
template<typename T>
void Node<T>::insert(Node<T>*& father_node, Node<T>*& child_node){
    if (father_node == nullptr){
        father_node = child_node;
    }else{
        if ((*father_node).data_ > (*child_node).data_){
            insert(father_node->left_child, child_node);
        }else if ((*father_node).data_ < (*child_node).data_){
            insert(father_node->right_child, child_node);
        }
    }
}


template<typename T>
void Node<T>::pre_orderDFS_print(){
    string result = "";
    Node<T>* a = this;
    string s = pre_order_str(a, result);
    s.pop_back();
    cout << s << endl;
}

template<typename T>
void Node<T>::in_orderDFS_print(){
    string result = "";
    Node<T>* a = this;
    string s = in_order_str(a, result);
    s.pop_back();
    cout << s << endl;
}

template<typename T>
void Node<T>::post_orderDFS_print(){
    string result = "";
    Node<T>* a = this;
    string s = post_order_str(a, result);
    s.pop_back();
    cout << s << endl;
}


template<typename T>
string Node<T>::pre_order_str(Node<T>* ptr, string result){
    if (ptr == nullptr){
        return result;
    }else{
        result = result + std::to_string(ptr->data_) + " ";
        result = pre_order_str(ptr->left_child, result);
        result = pre_order_str(ptr->right_child, result);
    }
    return result;
}

template<typename T>
string Node<T>::in_order_str(Node<T>* ptr, string result){
    if (ptr == nullptr){
        return result;
    }else{
        result = in_order_str(ptr->left_child, result);
        result = result + std::to_string(ptr->data_) + " ";
        result = in_order_str(ptr->right_child, result);
    }
    return result;
}

template<typename T>
string Node<T>::post_order_str(Node<T>* ptr, string result){
    if (ptr == nullptr){
        return result;
    }else{
        result = post_order_str(ptr->left_child, result);
        result = post_order_str(ptr->right_child, result);
        result = result + std::to_string(ptr->data_) + " ";
    }
    return result;
}
//----------------------------------------------------------------------



int main(int argc, char *argv[]) {
    if ( argc != 2 ) {// argc should be 2 for correct execution
        // We print argv[0] assuming it is the program name
        cout<<"usage: "<< argv[0] <<" <filename>\n";
    } else {
        // We assume argv[1] is a filename to open
        ifstream the_file ( argv[1] );
        // Always check to see if file opening succeeded
        
        if ( !the_file.is_open() ) {
            cout<<"Could not open file\n";
        } else {
            char x;
            // the_file.get ( x ) returns false if the end of the file
            //  is reached or an error occurs
            string num_str;
            vector<int> num_vec;
            while ( the_file.get ( x ) ){
                //cout<< "char x is:" << x << endl;
                
                if (x == ' '){
                    //cout << "num_str is:" <<num_str<<"end" << endl;
                    int temp = atoi(num_str.c_str());
                    num_vec.push_back(temp);
                    num_str = "";
                }
                
                if (x != ' '){
                    num_str = num_str + x;
                }
            }
            if (num_str != "") {
                int temp = atoi(num_str.c_str());
                num_vec.push_back(temp);
            }    
                
            int first_value = num_vec[0];
            Node<int> BST(first_value);
            
            for (int element : num_vec ){
                //cout << element << endl;
                BST.insert(element);
            }
            
            cout << "Pre-order traversal: ";
            BST.pre_orderDFS_print();
            
            cout << "In-order traversal: ";
            BST.in_orderDFS_print();
            
            cout << "Post-order traversal: ";
            BST.post_orderDFS_print();
        }
        
    }
    
}