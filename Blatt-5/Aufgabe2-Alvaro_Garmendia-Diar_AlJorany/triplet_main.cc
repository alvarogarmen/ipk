#include "triplet.hh"
#include <iostream>
int main(){
    Triplet triplet = Triplet(42, 3.14, 'F');
    if(triplet.first()!=42 || triplet.second()!=3.14 || triplet.third()!='F'){
        std::cout<<"Error"<<std::endl;
    }
    triplet.setFirst(41);
    triplet.setSecond(1.69);
    triplet.setThird('A');
    if (triplet.first()!=41 || triplet.second()!=1.69 || triplet.third()!='A'){
        std::cout<<"Error"<<std::endl;
    }
    std::cout<<"If no error messages, it means this works"<<std::endl;
    return 0;
}