#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"
template <typename Tr>
class TraitsList {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
    
    private:
        Node<T>* head;
        int sizes;
        Operation cmp;

        bool find(T data, Node<T> **&pointer) {
            while(*pointer){
                if(cmp((*pointer)->data,data)){
                    if(data==(*pointer)->data){
                        return true;
                    }
                }
                else{
                    return false;
                }
                pointer=&((*pointer)->next);
            }
            return false;
        }
        
    public:
        TraitsList() : head(nullptr) {
            this->sizes=0;
        };
        
        bool insert(T data) {
            Node<T>** temp2=&head;
            Node<T>* temp1=new Node<T>(data);
            if(!find(data,temp2)){
                sizes++;
                /*if(sizes==0){
                    this->head=temp1;
                }
                else{*/
                    temp1->next=(*temp2);
                    *temp2=temp1;
                //}
            }
        };
        bool remove(T data) {
            Node<T>** temp2=&head;
            if(find(data,temp2)){
                sizes--;
                *temp2=(*temp2)->next;
            }
            
        }  

        bool find(T data) {
            Node<T>** temp=&head;
            return(find(data,temp));
            
        }

        T operator [] (int index) {
            if (index>=sizes or index<0){
                throw out_of_range("Fuera de rango");
            }
            auto temp=head;
            while(index--){
                temp=temp->next;
            }
            return temp->data;
        }
        
        int size() {
            return sizes;
        }

        void print() {
            auto temp=head;
            cout<<"elements are: "<<endl;
            for(int i=0;i<this->sizes;i++){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }

        ~TraitsList() {
            if(sizes!=0)
                this->head->killSelf();
        }     
};

#endif