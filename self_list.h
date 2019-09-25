#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template <typename T>
class SelfList {
    public: 
        enum Method {
            Move, Count, Transpose
        };

    protected:
        Node<T>* head;
        Node<T>* tail;
        int sizes=0;
        Method method;

    public:
        SelfList(Method method) : head(nullptr), tail(nullptr) {this->method=method;};

        void insert(T data) {
            Node<T>* temp=new Node<T>(data);
            temp->data=data;
            if(sizes==0){
                this->head=temp;
                this->tail=this->head;
            }
            else{
                temp->prev=this->tail;
                this->tail->next=temp;
                this->tail=temp;
            }
            this->sizes++;
            
        }
        bool remove(T data){
            Node<T>* temp=head;
            for(int i=0;i<sizes;i++){
                if(temp->data==data){
                    if(i!=0){
                        temp->prev->next=temp->next;
                        temp->next->prev=temp->prev;
                    }
                    else{
                        if(sizes!=1)
                            this->head=this->head->next;
                    }
                    delete temp;
                    sizes--;
                    return true;
                }
                if(temp->next!=nullptr)
                    temp=temp->next;
            }
            if(sizes==0){
                this->head=nullptr;
                this->tail=nullptr;
            }
            return false;
        }  

        bool find(T data) {
            auto temp=head;
            Node<T>* temp2=nullptr;
            for (int i=0;i<sizes;i++){
                // Podrían ser métodos privados separados
                // Más aún, podrías sacar el bucle a una función externa
                if(temp->data==data){
                    if(method==Move){
                        if (i==0)
                            return true;
                        if(temp->next!=nullptr){
                            temp->next->prev=temp->prev;
                        }
                        temp->prev->next=temp->next;
                        temp->next=this->head;
                        this->head->prev=temp;
                        temp->prev=nullptr;
                        this->head=temp;
                        return true;
                    }
                
                    if(method==Count){
                        if (i==0){
                            temp->cuenta++;
                            return true;
                        }
                        int valor=0;                      
                        temp->cuenta++;
                        temp2=temp;
                        valor=temp2->cuenta;
                        while(temp->prev!=nullptr && valor>temp->prev->cuenta){
                            temp=temp->prev;
                        }

                        if(temp2!=temp){
                            if (temp2==tail){
                                temp2->prev->next=nullptr;
                                this->tail=temp2->prev;
                            }
                            else if(temp2==head)
                                temp2->next->prev=nullptr;
                            else{
                                temp2->next->prev=temp2->prev;
                                temp2->prev->next=temp2->next;
                            }
                            temp2->next=temp;
                            if(temp!=head){
                                temp2->prev=temp->prev;
                                temp2->prev->next=temp2;
                            }
                            temp2->next->prev=temp2;
                            if(temp==head){
                                temp2->prev=nullptr;
                                this->head=temp2;
                            }
                            else if (temp==tail){
                                temp2->next=nullptr;
                                this->tail=temp2;
                            }
                        }
                        temp=this->head;
                        for(int i=0;i<sizes-1;i++){
                            temp=temp->next;
                        }
                        return true;
                    }

                    if(method==Transpose){
                        if(i==0)
                            return true;
                        temp2=temp->prev;
                        if(temp!=this->tail){
                            temp->next->prev=temp2;
                            temp2->next=temp->next;
                            if(temp2!=this->head){
                                temp->prev=temp2->prev;
                                temp2->prev->next=temp;
                            }
                            else
                                this->head=temp;
                        }
                        else{
                            temp2->prev->next=temp;
                            temp->prev=temp2->prev;
                            this->tail=temp2;
                        }
                        temp->next=temp2;
                        temp2->prev=temp;
                        return true;
                    }
                }
                temp=temp->next;
            }
            return false;
        }

        T operator [] (int index){
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
            for(int i=0;i<sizes;i++){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }

        ~SelfList() {
            if(sizes!=0)
                this->head->killSelf();
        }
        
};

#endif