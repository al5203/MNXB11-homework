#include "TFile.h"
#include "TTree.h"
#include "TMath.h" 
#include "TRandom3.h" 


class Person {
public:
    Person() : age(0), name(""), px(0.0), py(0.0), pz(0.0) {CalculateMomentumMagnitude();}

    Person(int age, const std::string& name, Double_t px, Double_t py, Double_t pz) : age(age), name(name), px(px), py(py), pz(pz) {CalculateMomentumMagnitude();}
   Double_t GetMomentumMagnitude() const {
        return momentumMagnitude;
    }
    

private:
    int age;
    std::string name;
    Double_t px;
    Double_t py;
    Double_t pz;
    Double_t momentumMagnitude;
    void CalculateMomentumMagnitude() {
        momentumMagnitude = TMath::Sqrt(px * px + py * py + pz * pz);
    }
};

void write() {
    
    Int_t nEvents = 100;

    
    TFile file("output.root", "RECREATE");

    
    TTree tree("MyTree", "Tree with custom data");

    
    Person* person = nullptr;

    
    tree.Branch("person", &person);

    
    TRandom3 randomGenerator;

    
    for (Int_t i = 0; i < nEvents; i++) {
        
        person = new Person(TMath::Nint(randomGenerator.Uniform(1, 100)), "RandomName", 
                            randomGenerator.Gaus(0, 0.02), randomGenerator.Gaus(0, 0.02), randomGenerator.Gaus(0, 0.02));

        
        tree.Fill();

       
        delete person;
    }

    
    tree.Write();
    file.Write();
    file.Close();
}

int main(){
    fillTree();
    return 0;
}
