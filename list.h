#ifndef _LIST_H_
#define _LIST_H_

#include<algorithm>
#include<cstdlib>
#include<cassert>

template <class T>
class list{
    private:
        class node{
            public:
                node* left;
                node* right;
                T val;
            
                node(const T &val, node* left, node* right):
                    val(val), left(left), right(right) {
                }
        };
    
        node* __left__;
        node* __right__;
        size_t __size__;
    public:
        
        list(){
            __left__ = __right__ = new node(T(), 0, 0);
            __size__ = 0;
        }
        
        list(const list& lst){
            __left__ = __right__ = new node(T(), 0, 0);
            for(const_iterator i = lst.begin(); i!=lst.end(); ++i){
                push_back(*i);
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
        
        class iterator : public std::iterator<std::bidirectional_iterator_tag, node>{
            public:
                node* _node;
                
                iterator(node* _node): _node(_node){}
                iterator(const iterator& it): _node(it._node){}
                
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
                    return tmp;
                }

                iterator& operator-- () {
                    assert(_node->left);
                    _node = _node->left;
                    return *this;
                }
                
                iterator operator-- (int) {
                    assert(_node->left);
                    iterator tmp(*this);
                    _node = _node->left;
                    return tmp;
                }
                
                
        };
        
        class const_iterator : public std::iterator<std::bidirectional_iterator_tag, const node> {
            public:
                const node* _node;

                const_iterator(const node* _node) : _node(_node) {}
                const_iterator(const const_iterator& it) : _node(it._node) {}

                bool operator==(const const_iterator& it) const {
                    return _node == it._node;
                }

                bool operator!=(const const_iterator& it) const {
                    return _node != it._node;
                }
        
                T const& operator*() const {
                    return _node->val;
                }

                const_iterator& operator++() {
                    assert(_node->right);
                    _node = _node->right;
                    return *this;
                }

                const_iterator operator++(int) {
                    assert(_node->right);
                    const_iterator tmp(*this); 
                    _node = _node->right;
                    return tmp;
                }

                const_iterator& operator--() {
                    assert(_node->left);
                    _node = _node->left;
                    return *this;
                }

                const_iterator operator--(int) {
                    assert(_node->left);
                    const_iterator tmp(*this); 
                    _node = _node->left;
                    return tmp;
                }
        };
        
        void swap(list& lst){
            std::swap(__left__, lst.__left__);
            std::swap(__right__, lst.__right__);
            std::swap(__size__, lst.__size__);
        }
        
        list& operator= (list l){
            swap(l);
            return *this;
        }
        
        void clear(){
            list empty;
            swap(empty);
        }
        
        void push_back(const T& val){
            insert(end(), val);
        }
        
        void pop_back(){
            erase(--end());
        }
        
        T const& back() const{
            return *(--end());
        }
        
        void push_front(const T& val){
            insert(begin(), val);
        }
        
        void pop_front(){
            erase(begin());
        }
        
        T const& front() const{
            return *(begin());
        }
        
        const_iterator begin() const {
            return const_iterator(__left__);
        }
        
        iterator begin() {
            return iterator(__left__);
        }
        
        const_iterator end() const {
            return const_iterator(__right__);
        }
        
        iterator end() {
            return iterator(__right__);
        }
        
        size_t size() const{
            return __size__;
        }
        
        iterator insert(const iterator& it, const T& val) {
            node* nd = it._node;
            node* new_node = new node(val, nd->left, nd);
            if(nd->left){
                nd->left->right = new_node;
            }
            nd->left = new_node;
            if(nd == __left__) {
                __left__ = new_node;
            }
            ++__size__;
            return iterator(new_node);
        }
        
        void erase(const iterator& it) {
            assert(!(it._node == __right__));
            node* nd = it._node;
            if (nd->left) {
                nd->left->right = nd->right;
            }
            if (nd->left) {
                nd->right->left = nd->left;
            }
            if (nd == __left__){
                __left__ = nd->right;
            }
            --__size__;
            delete nd;
        }
};

#endif