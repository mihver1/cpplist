#ifndef _LIST_H_
#define _LIST_H_

#include<algorithm>

//using std::swap;

template <class T>
class list{
    private:
        class node{
            public:
                node* left;
                node* right;
                T val;
            
            node(const T &value, node* left, node* right):
                value(value), left(left), right(right) {
            }
        };
    
        node* __left__, __right__;
        size_t __size__;
    public:
        
        list(){
            __left__ = __right__ = new node(T(), 0, 0);
            __size__ = 0;
        }
        
        list(const& list lst){
            __left__ = __right__ = new node(T(), 0, 0);
            for(iterator it = l.begin(); it!=l.end(); ++it) {
                push_back(*it);
            }
        }
        
        ~list(){
            node* temp_node = __left__;
            while(temp_node){
                node* temp2_node = temp_node->right;
                delete temp_node;
                temp_node = temp2_node;
            }
        }
        
        void copy(list& lst){
            std::swap(__left__, lst.__left__);
            std::swap(__right__, lst.__right__);
            std::swap(__size__, lst.__size__);
        }
        
        list& operator= (list l){
            copy(l);
            return this;
        }
        
        void clear(){
            list empty;
            copy(empty);
        }
        
        void push_back(const T& val){
            insert(end(), val);
        }
        
        void pop_back(){
            erase(--end());
        }
        
        T const& back() const{
            return *(--back());
        }
        
        void push_front(const T& val){
            insert(begin(), val);
        }
        
        void pop_front(){
            erase(begin());
        }
        
        T const& front(){
            return *(begin());
        }
        
        class iterator : public std::iterator<std::bidirectional_iterator_tag, node>{
            public:
                node* _node;
                
                iterator(node* _node): node(_node){}
                iterator(const iterator& it): _node(it.node){}
                
                bool operator==(const iterator &it) const {
                    return _node == it._node;
                }
                
                bool operator!=(const iterator &it) const {
                    return _node != it._node;
                }
                
                T& operator*(){
                    return _node->val;
                }
                
                iterator& operator++ () {
                    assert(_node->right);
                    _node = _node->right;
                    return *this;
                }
                
                iterator operator++ (int) {
                    assert(_node->right);
                    iterator tmp(*this);
                    _node = _node->right;
                    return *tmp;
                }

        };
}

#endif