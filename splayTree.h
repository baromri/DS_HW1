//
//  splayTree.h
//  HW1

#ifndef splayTree_h
#define splayTree_h

template <class T>
class splayTree{
private:
    treeNode* root;
public:
    void insertNode(const T& data);
    void findNode(const T& data);
    void deleteNode(const T& data);
};
//need to add class iterator

template <class T>
class treeNode {
private:
    T data;
    treeNode<T> *parent, *left, *right;
public:
    //default c'tor;
    treeNode():data(),parent(nullptr),left(nullptr),right(nullptr){}
    //maybe need to add copy ctor, d'tor, assignment
    treeNode(const treeNode& node):data(node.getData), parent(node.getParent),right(node.getRight),left(node.getLeft){};
    ~treeNode() = default;
    void setParent(const treeNode& node){
        this.parent = node.getParent();
    }
    void setLeft(const treeNode& node){
        this.left = node.getLeft();
    }
    void setRight(const treeNode& node){
        this.right = node.getRight();
    }
    treeNode* getParent() const{
        return this.parent;
    }
    treeNode* getLeft() const{
        return this.left;
    }
    treeNode* getRight() const{
        return this.right;
    }
    const treeNode* getParent() const{
        return this.parent;
    }
    const treeNode* getLeft() const{
        return this.left;
    }
    const treeNode* getRight() const{
        return this.right;
    }
    T& getData(){
        return *this.data;
    }
    const T& getData() const{
        return this.data;
    }
    //?
    treeNode& operator=(const treeNode& node){
        //
    }
    bool operator==(const treeNode& node) const{
        return (this.data == node.getDate());
    }
    bool operator!=(const treeNode& node) const{
        return !(this == node);
    }
};


#endif /* splayTree_h */

