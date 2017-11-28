
#ifndef EX4_LIST_LIST_H
#define EX4_LIST_LIST_H

#include "Exceptions.h"

using namespace mtm::ListExceptions;

template <class T>
class List{
public:
    class node_t{
        T data;
        node_t* next;
        node_t* previous;

        public:
        //// Constructs a new node.
        //
        node_t():data(), next(nullptr), previous(nullptr){}
        //CopyConstructor
        //
        node_t(const node_t& node): data(node.getData()),next(node.getNext()),
                                    previous(node.getPrevious()){}
        //Destructor
        //
        ~node_t()= default;
        //Function returns the data in the node.
        //
        T& getData();
        //Function returns the const data in the node.
        //
        const T& getData() const;
        //Function sets the data in the node.
        // @param: data : the data which we want to set to the node.
        //
        void setData(T data);
        //Function returns a pointer to the next node.
        //
        node_t* getNext() const;
        //Function sets a pointer to the next node.
        // @param: node : the node which we want to set to the next node.
        //
        void setNext(node_t* node);
        //Function returns a pointer to the previous node.
        //
        node_t* getPrevious() const;
        //Function sets a pointer to the next node.
        // @param: node : the node which we want to set to the previous node.
        //
        void setPrevious(node_t* node);
        //Assignment operation
        // @param: node : the node which we want to copy to the object.
        //
        node_t& operator=(const node_t& node);
        //Equality operator
        // @param: node : the node which we want to compare to the object.
        //
        bool operator==(const node_t& node) const;
        //Difference operator
        // @param: node : the node which we want to compare to the object.
        //
        bool operator!=(const node_t& node) const;
    };

    class Iterator{
        const List* list;
        node_t* node;
    public:
        //// Constructs a new Iterator with the specified data.
        //
        // @param list : the list of the iterator.
        // @param node : the node that the iterator points to.
        //
        Iterator(const List* list, node_t* node);

        //CopyConstructor
        //
        Iterator(const Iterator& iterator)= default;

        friend class List;

        //add one operator. increase in one place the object and return the new
        // object. (++x)
        //
        Iterator& operator++();
        //add one operator. increase in one place the object and return the old
        // object. (x++)
        // @param: int : not a real param.
        //
        Iterator operator++(int);
        //sub one operator. deccrease in one place the object and return the new
        // object. (--x)
        //
        Iterator& operator--();
        //sub one operator. deccrease in one place the object and return the old
        // object. (x--)
        // @param: int :  not a real param.
        //
        Iterator operator--(int);
        //unary operator. returns the data of the node that the iterator is
        // pointing on.
        //
        T& operator*() const;
        //Equality operator
        // @param: iterator:the iterator which we want to compare to the object.
        //
        bool operator==(const Iterator& iterator) const;
        //Difference operator
        // @param: iterator:the iterator which we want to compare to the object.
        //
        bool operator!=(const Iterator& iterator) const;
        //Function returns a pointer to the list of the iterator.
        //
        const List* getList() const;
        //Function returns a pointer to the node of the iterator.
        //
        const node_t* getNode() const;

        //Assignment operation
        // @param: iterator : the iterator which we want to copy to the object.
        //
        Iterator& operator=(const Iterator& iterator)= default;
        //Destructor
        //
        ~Iterator()= default;
    };

private:
    int size;
    node_t* first;
    node_t* last;

    template <class Compare>
    void bubble_sort(int listSize, const Compare& compare);

    template <class Compare>
    int bubble(int listSize, const Compare& compare);

    static void swapFunc(Iterator& iterator);

    public:

    //// Constructs a new List.
    //
    List();
    //CopyConstructor
    //
    List(const List& list);
    //Destructor
    //
    ~List();
    //Function returns an iterator to the first node in the list.
    //
    Iterator begin() const;
    //Function returns an iterator to the last node in the list.
    //
    Iterator end() const;
    //Function inserts a new node to the list with a specific data, before the
    // iterator.
    // @param: data : the data which we want to insert to the new node.
    // @param: iterator: the iterator which we want to insert a node before him.
    //
    void insert(const T& data, Iterator iterator);
    //Function inserts a new node to the list with a specific data.
    // @param: data : the data which we want to insert to the new node.
    //
    void insert(const T& data);
    //Function removes a node which the specific iterator points to.
    // @param: iterator : the iterator which we want to remove his node.
    //
    void remove(Iterator iterator);

    //Function finds the object due to the predicate. returns an iterator to the
    //first object which comply the predicate.
    //
    template<class Predicate>
    Iterator find(const Predicate& predicate);
    //Function sorts the list from small to big due to compare condition.
    //
    template<class Compare>
    void sort(const Compare& compare);
    //Function returns the size of the list.
    //
    int getSize() const ;

    //Assignment operation
    // @param: list : the list which we want to copy to the object.
    //
    List& operator=(const List& list);
    //Equality operator
    // @param: list : the list which we want to compare to the object.
    //
    bool operator==(const List& list) const;
    //Difference operator
    // @param: list : the list which we want to compare to the object.
    //
    bool operator!=(const List& list) const;
};

//***node_t***

template <class T>
T& List<T>::node_t::getData(){
    return data;
}

template <class T>
const T& List<T>::node_t::getData() const{
    return data;
}

template <class T>
void List<T>::node_t::setData(T data){
    this->data= data;
}

template <class T>
typename List<T>::node_t* List<T>::node_t::getNext() const{
    return next;
}

template <class T>
void List<T>::node_t::setNext(node_t* node){
    this->next= node;
}

template <class T>
typename  List<T>::node_t* List<T>::node_t::getPrevious() const{
    return previous;
}

template <class T>
void List<T>::node_t::setPrevious(node_t* node){
    this->previous= node;
}

template <class T>
typename List<T>::node_t& List<T>::node_t::operator=(const
                                                        List<T>::node_t& node){
    if(this==&node){
        return *this;
    }
    delete data;
    data=node.getData();
    next= node.getNext();
    previous= node.getPrevious();
    return *this;
}

template <class T>
bool List<T>::node_t::operator==(const List<T>::node_t& node) const{
    if(this== nullptr){
        return false;
    }
    return (data==node.getData() && next==node.getNext()
                       && previous==node.getPrevious());
}

template <class T>
bool List<T>::node_t::operator!=(const List<T>::node_t& node) const{
    return !(*this==node);
}



//***iterator***

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator++(){ //++x
    this->node=this->node->getNext();
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator++(int){  //x++
    Iterator dummy(this->list,this->node);
    this->node=this->node->getNext();
    return dummy;
}

template <class T>
typename List<T>::Iterator& List<T>::Iterator::operator--(){ //--x
    this->node=this->node->getPrevious();
    return *this;
}

template <class T>
typename List<T>::Iterator List<T>::Iterator::operator--(int){  //x--
    Iterator dummy(this->list,this->node);
    this->node=this->node->getPrevious();
    return dummy;
}

template <class T>
T& List<T>::Iterator::operator*() const{
    if(*this->node == *this->list->last){
        throw ElementNotFound();
    }else{
        return this->node->getData();
    }
}

template <class T>
bool List<T>::Iterator::operator!=(const Iterator& iterator) const{
    return !(*this==iterator);
}

template <class T>
const List<T>* List<T>::Iterator::getList() const{
    return this->list;
}

template <class T>
const typename List<T>::node_t* List<T>::Iterator::getNode() const{
    return this->node;
}

template <class T>
bool List<T>::Iterator::operator==(const Iterator& iterator) const{
    return (&(*this->list->end().node) == &(*iterator.list->end().node)
       && *this->node == *iterator.node);
}

template <class T>
List<T>::Iterator::Iterator(const List<T> *list, List<T>::node_t* node) : list(list),
                                                              node(node){}



//***list***
                                                              //constructor
template <class T>
List<T>::List(): size(0){
    node_t* dummy=new node_t;
    first=dummy;
    last=dummy;
}

                                                             //CopyConstructor
template <class T>
List<T>::List(const List<T>& list): size(0){
     node_t* dummy=new node_t;
     first=dummy;
     last=dummy;
     if(list.size==0) {
         return;
     }//copy all the list
     List<T>::Iterator i = list.begin();
     while(i.node!=list.last){
          this->insert(i.node->getData());
          i.node=i.node->getNext();
     }
}

template <class T>
List<T>::~List() {                                        //Destructor
    List<T>::Iterator i = this->begin();
    List<T>::Iterator temp = i;
    while(this->begin()!= this->end()){
        i.node=i.node->getNext();
        remove(temp);
        temp=i;
    }
    delete (this->last);
    return;
}

template <class T>
typename List<T>::Iterator List<T>::begin()const {
    List<T>::Iterator first(this,this->first);
    return first;
}

template <class T>
typename List<T>::Iterator List<T>::end()const {
    List<T>::Iterator last(this,this->last);
    return last;
}

template <class T>
void List<T>::insert(const T& data, Iterator iterator){
    if(*this != *iterator.list){
        throw ElementNotFound();
    }
    node_t* new_node = new node_t;
    new_node->setPrevious(iterator.node->getPrevious());
    //there is no node before the first
    if(iterator.node != first) {
        (iterator.node->getPrevious())->setNext(new_node);
    }else{    //the new node is first (before the iterator)
        first= new_node;
    }
    new_node->setNext(iterator.node);
    iterator.node->setPrevious(new_node);
    new_node->setData(data);
    size++;
}

template <class T>
void List<T>::insert(const T& data){
    node_t* new_node = new node_t;
    new_node->setPrevious(last->getPrevious());
    //there is no node before the first
    if(size!=0) {
        (last->getPrevious())->setNext(new_node);
    }else{    //the new node is first and only node in the list
        first=new_node;
    }
    new_node->setNext(last);
    last->setPrevious(new_node);
    new_node->setData(data);
    size++;
}

template <class T>
void List<T>::remove(Iterator iterator){
    if((this != iterator.list) || (this->size == 0)){
        throw ElementNotFound();
    }
    if(iterator.node == last){
        throw ElementNotFound();
    }
    if(iterator.node != first){
        iterator.node->getPrevious()->setNext(iterator.node->getNext());
    } else {
        first=first->getNext();
    }
    (iterator.node->getNext())->setPrevious(iterator.node->getPrevious());
    size--;

    delete iterator.node;
}

template <class T>
template <class Predicate>
typename List<T>::Iterator List<T>::find(const Predicate& predicate){
    for(Iterator it = this->begin(); it != this->end() ; ++it) {
        if (predicate(it.node->getData())) {
            return it;
        }
    }
    return this->end();
}

template <class T>
template <typename Compare>
void List<T>::sort(const Compare& compare){
    bubble_sort( this->size, compare);
}

template <class T>
template <typename Compare>
void List<T>::bubble_sort(int listSize, const Compare& compare){
    int not_sorted = 1;
    while((listSize > 1) && not_sorted)
        not_sorted = bubble( listSize--, compare);
}

template <class T>
template <typename Compare>
int List<T>::bubble( int listSize, const Compare& compare){
    int swapped = 0;
    Iterator it= begin();
    for(int i=0; i<listSize-1; i++){
        if(!compare(it.node->getData(),(it.node->getNext())->getData())){
            swapFunc(it);
            swapped = 1;
        }
        it++;
    }
    return swapped;
}

template <class T>
void List<T>::swapFunc(Iterator& iterator){
    T hold= iterator.node->getData();
    iterator.node->setData((iterator.node->getNext())->getData());
    (iterator.node->getNext())->setData(hold);
}

template <class T>
int List<T>::getSize() const{
    return size;
}

template <class T>
List<T>& List<T>::operator=(const List& list){
    if(*this == list){
        return *this;
    }
    //delete the exist list from the object
    if(size!=0) {
        List<T>::Iterator i = this->begin();
        List<T>::Iterator temp = i;
        while(this->begin()!= this->end()){
            i.node=i.node->getNext();
            remove(temp);
            temp=i;
        }
    }
    if(list.size == 0){ // if we want to copy the fields from an empty list
                        // the list is already empty after the delete.
        return *this;
    }
    //copy the new list to the object
    List<T>::Iterator i = list.begin();
    while(i.node!=list.last){
        this->insert(i.node->getData());
        i.node=i.node->getNext();
    }
    return *this;
}


template <class T>
bool List<T>::operator==(const List<T>& list) const{
    if (size==list.getSize()) {
        Iterator argument_it= list.begin();
        for (Iterator object_it = this->begin(); object_it != this->end();
                                                                 ++object_it) {
            if(argument_it==list.end()){
                return false;
            }
            if (object_it.node->getData() != argument_it.node->getData()) {
                return false;
            }
            argument_it++;
        }
        return true;
    }
    return false;
}

template <class T>
bool List<T>::operator!=(const List<T>& list) const{
    return !(*this==list);
}

#endif //EX4_LIST_LIST_H
