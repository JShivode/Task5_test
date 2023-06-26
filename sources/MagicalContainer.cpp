#include "MagicalContainer.hpp"
#include <algorithm>  // For using std::remove
#include <iostream>  
using namespace ariel;

// MagicalContainer class

/*void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}*/

MagicalContainer::~MagicalContainer(){
    
}

void MagicalContainer::addElement(int element) {
    // Find the correct position to insert the element
    auto it = std::lower_bound(my_elements.begin(), my_elements.end(), element);
    my_elements.insert(it, element);
}


void MagicalContainer::removeElement(int element) {
    auto it = std::find(my_elements.begin(), my_elements.end(), element);
    if (it == my_elements.end()) {
        throw std::runtime_error("Element not found in container.");
    }
    
    my_elements.erase(it);
}


int MagicalContainer::get(int index)
{
    return my_elements[static_cast<std::vector<int>::size_type>(index)];
}
int MagicalContainer::size() const {
    return my_elements.size();
}
// AscendingIterator //

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container2) : container(container2), index(0){}

std::vector<int>::value_type MagicalContainer::AscendingIterator::operator*() const{
    return container.get(static_cast<std::vector<int>::size_type>(index));
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    if(index<container.size())
        index++;
    else
        throw std::runtime_error("Already reached end.");

    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return index == other.index;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(index == other.index);
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return (index > other.index);
}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return (index < other.index);
}
bool MagicalContainer::AscendingIterator::operator>=(const AscendingIterator& other) const {
    return (index >= other.index);
}
bool MagicalContainer::AscendingIterator::operator<=(const AscendingIterator& other) const {
    return (index <= other.index);
}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator = (const AscendingIterator& other)  {
    throw std::runtime_error("Asignment prohibited.");
}


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    index =0;
    return AscendingIterator(container);
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator iter(container);
    iter.index = container.size();
    return iter;
}
//////////////////////////////////////

// SideCrossIterator //
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container)  //2 3 9 17
    : container(container), index(0) {}

std::vector<int>::value_type MagicalContainer::SideCrossIterator::operator*() const {
//return container.get(indexArray[index]);
return (index%2 != 0 ) ? container.get(container.size()-1-(index-1)/2) : container.get(index/2);
}     //0 4 1 2 2
    //  0 1 2 3 4                                           
                                                    
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
       if(index<container.size()) 
          ++index;  
       else
        throw std::runtime_error("Already reached end.");
                  
    return *this;
}
bool MagicalContainer::SideCrossIterator::operator<=(const SideCrossIterator& other) const{
    return index <= other.index;
}
bool MagicalContainer::SideCrossIterator::operator>=(const SideCrossIterator& other) const{
    return index >= other.index;
}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const{
    return index < other.index;
}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const{
    return index > other.index;
}




bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
   return index == other.index;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(index == other.index);
}
/*bool MagicalContainer::SideCrossIterator::operator = (const SideCrossIterator& other)  {
    throw std::runtime_error("Asignment prohibited.");
}*/

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    throw std::runtime_error("Assignment prohibited.");
}


MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    SideCrossIterator iter(container);
    iter.index = 0;        
    return iter;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {   // 2 25 3 17 9
    
    SideCrossIterator iter(container);        
    iter.index = container.size();
    return iter;
}
//////////////////////////////////////

bool MagicalContainer::isPrime(int n){ // https://www.geeksforgeeks.org/c-program-to-check-prime-number/
    if (n <= 1 || (n%2 ==0 && n>2))
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

//////

/*MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
    : container(container), index(0) {
        bool prm =false;
        for(int x=0; x<container.size();x++)
        {
           if(isPrime(container.get(x)))
               {
                index = x;
                prm = true;
                break;
               }
        }
        if(!prm)
           index = container.size();
    }*/

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
    : container(container), index(0) {
        bool prm =false;
        for(int x=0; x<container.size();x++)
        {
           if(isPrime(container.get(static_cast<std::vector<int>::size_type>(x))))
               {
                index = x;
                prm = true;
                break;
               }
        }
        if(!prm)
           index = container.size();
    }

//MagicalContainer::PrimeIterator::~PrimeIterator(){}

std::vector<int>::value_type MagicalContainer::PrimeIterator::operator*() const {
    return container.get(static_cast<std::vector<int>::size_type>(index));
}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    if(index>=container.size())
        throw std::runtime_error("Incrementing out of bound.");
    int idx = index;
    idx++;
    while (idx < static_cast<int>(container.size()) &&
           !MagicalContainer::isPrime(container.
              get(static_cast<std::vector<int>::size_type>(idx)))) 
    {
        idx++;
    }  
    index = idx; 
    // if(MagicalContainer::isPrime(container.get(static_cast<std::vector<int>::size_type>(idx)))) 
       
    //      index = idx;       
    // else
    //      index = container.size();

    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return index == other.index;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(index == other.index);
}

bool MagicalContainer::PrimeIterator::operator>=(const PrimeIterator& other) const {
    return (index >= other.index);
}
bool MagicalContainer::PrimeIterator::operator<=(const PrimeIterator& other) const {
    return (index <= other.index);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return (index > other.index);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return (index < other.index);
}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator = (const PrimeIterator& other) {
    throw std::runtime_error("Asignment prohibited.");
}


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    PrimeIterator iter(container);
    if (!isPrime(container.get(static_cast<std::vector<int>::size_type>(iter.index))))
        ++iter;
    return iter;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator iter(container);
   /* int temp=container.size()-1;
    while(iter.index<container.size())
    {
     if(isPrime(container.get(iter.index)))
       temp = iter.index;
     iter.index++;  
    }
    iter.index = temp;*/

    iter.index = iter.container.size();
    return iter;
}

MagicalContainer::PrimeIterator::~PrimeIterator(){}



