#include "Person.h"
ClassImp(Person);


Person::Person() :
    myPrivateData(0) /
{
    
}

Person::Person(Int_t age) :
    myPrivateData(static_cast<Double_t>(age))
   {
    
   }


Person::~Person() {
    
}
