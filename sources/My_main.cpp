#include <iostream>
#include "MagicalContainer.hpp"

/*
cd sources
clang++-14 My_main.cpp MagicalContainer.cpp -o main
./main
*/

using namespace ariel;
int main() {
    // Create a MagicalContainer and add some elements
    MagicalContainer container1;
    container1.addElement(17);
    container1.addElement(2);
    container1.addElement(25);
    container1.addElement(9);
    container1.addElement(3);
    container1.addElement(5);
    container1.addElement(6);
    container1.addElement(19);
    MagicalContainer container2;
    container2.addElement(1);
    container2.addElement(2);
    container2.addElement(5);
    container2.addElement(9);
    container2.addElement(8);
    container2.addElement(10);
    container2.addElement(6);
    container2.addElement(27);

    // Print container1 size
    std::cout << "Size of container: " << container1.size() << std::endl;

    // Use AscendingIterator to display elements in ascending order
    std::cout << "Elements in ascending order:\n";
    MagicalContainer::AscendingIterator ascIter(container1);
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it) {
        std::cout << *it << ' ';   // 2 3 9 17 25
    }
    std::cout << std::endl;

    // Use DescendingIterator to display elements in descending order
    std::cout << "Elements in cross order:\n";
    MagicalContainer::SideCrossIterator crossIter(container1);
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 25 3 17 9
    }
    std::cout << std::endl;

    // Use PrimeIterator to display prime numbers only
    std::cout << "Prime numbers:\n";
    MagicalContainer::PrimeIterator primeIter(container1);
    std::cout<<"First element: "<<*primeIter<<std::endl;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
        std::cout << *it << ' ';  // 2 3 17 
    }
    std::cout << std::endl;

    // Remove an element from the container and display the size
    container1.removeElement(9);
    std::cout << "Size of container after removing an element: " << container1.size() << std::endl;

    MagicalContainer::AscendingIterator ascIter2(container2);

    while(ascIter2 < ascIter2.end())
    {
        std::cout<<"["<<*ascIter2<<"] ";
        ++ascIter2;
    }
    std::cout <<std::endl;

    MagicalContainer::SideCrossIterator crossIter1(container2);

    while(crossIter1 < crossIter1.end())
    {
        std::cout<<"["<<*crossIter1<<"] ";
        ++crossIter1;
    }
    std::cout <<std::endl;

    MagicalContainer::PrimeIterator primeIter1(container1);

    while(primeIter1 < primeIter1.end())
    {
        std::cout<<"["<<*primeIter1<<"] ";
        ++primeIter1;
    }
    std::cout <<std::endl;

    try{
        ascIter = ascIter2;
    }
    catch (std::exception& e){
        std::cout<<"Exception thrown: "<<e.what()<<std::endl;
    }

    try{
         container1.removeElement(77);
    }
    catch (std::exception& e){
        std::cout<<"Exception thrown: "<<e.what()<<std::endl;
    }

    MagicalContainer cont3;
    cont3.addElement(1);
    cont3.addElement(4);
    cont3.addElement(6);
    std::cout<<"Printing an empty string here:"<<std::endl;
    MagicalContainer::PrimeIterator prm3(cont3);
    try{        
    for(prm3.begin(); prm3<prm3.end();++prm3)
       std::cout<<" -- "<<*prm3<<std::endl;
    }
    catch(std::exception& excp){ 
        std::cout <<"Exceptoin thrown: "<<excp.what()<<std::endl;
    }

    cont3.addElement(2);
    MagicalContainer::PrimeIterator prm3_2(cont3);
    std::cout<<"Printing a non empty string here:"<<std::endl;
    
    try{        
    for(prm3_2.begin(); prm3_2<prm3_2.end();++prm3_2)
       std::cout<<" -- "<<*prm3_2<<std::endl;
    }
    catch(std::exception& excp){ 
        std::cout <<"Exceptoin will not be thrown: "<<excp.what()<<std::endl;
    }

    MagicalContainer::PrimeIterator itr4(cont3);
    try{itr4 = prm3;}
    catch(std::exception& excp){ 
        std::cout <<"Exceptoin thrown: "<<excp.what()<<std::endl;
    }
    return 0;
}
