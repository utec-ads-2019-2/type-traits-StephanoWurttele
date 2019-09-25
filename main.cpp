#include <iostream>

#include "test/tester.h"

using namespace std;

int main(int argc, char const *argv[]) {
    TraitsList<Integer> integers;
    for(int i=0;i<5;i++){
        integers.insert(4 * i + 3);
        cout<<endl<<endl;
    }
    integers.insert(3);
    integers.insert(2);
    integers.insert(5);
    integers.insert(1);
    integers.print();
    integers.remove(1);
    integers.print();
    integers.remove(11);
    integers.remove(7);
    integers.print();
    cout<<integers.find(2);
    Tester::execute();
    
    // Da segmentation fault con Move
    //SelfList<int> Movelist(SelfList<int>::Move);
    SelfList<int> Movelist(SelfList<int>::Count);
    //SelfList<int> Movelist(SelfList<int>::Transpose);
    Movelist.insert(5);
    Movelist.remove(3);
    Movelist.remove(5);
    Movelist.print();
    cout<<"Inserting"<<endl;
    Movelist.insert(1);
    Movelist.print();
    Movelist.insert(2);
    Movelist.insert(3);
    Movelist.insert(4);
    Movelist.insert(5);
    for(int i=0;i<Movelist.size();i++){
        cout<<Movelist[i]<<" ";
    }
    cout<<endl;
    cout<<"Testing finds:"<<endl;
    cout<<"Finding 1"<<endl;
    Movelist.find(1);
    Movelist.print();
    cout<<"Found 1, moving to 4"<<endl;
    Movelist.find(4);
    Movelist.print();
    cout<<"Found 4, moving to 5"<<endl;
    Movelist.find(5);
    Movelist.print();
    cout<<"Found 5, moving to 2"<<endl;
    Movelist.find(2);
    Movelist.find(2);
    Movelist.find(2);
    Movelist.print();
    cout<<"Found 2, moving to 3"<<endl;
    Movelist.find(3);
    Movelist.find(3);
    Movelist.find(3);
    Movelist.find(3);
    Movelist.print();
    cout<<"Found 3, moving to 5"<<endl;
    Movelist.find(5);
    Movelist.find(5);
    Movelist.find(5);
    Movelist.find(5);
    Movelist.print();
    cout<<"Finished finding. Testing others"<<endl;
    Movelist.insert(5);
    Movelist.remove(3);
    Movelist.print();
    Movelist.remove(5);
    Movelist.print();
    Movelist.remove(2);
    Movelist.remove(1);
    Movelist.remove(4);
    Movelist.remove(5);

    return EXIT_SUCCESS;
}    