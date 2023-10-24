#ifndef __PERSON_H__
#define __PERSON_H__

#include <TObject.h>

class Person : public TObject {
public:
    Person();                // Default constructor
    Person(Int_t age);      // Another constructor
    virtual ~Person();       // Destructor

private:
    Double_t myPrivateData; 
   
    ClassDef(Person, 1); 
};

#endif // __PERSON_H__
