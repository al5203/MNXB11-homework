void read() {
    
    Person person; 

    
    TFile file("tree_file.root", "READ");

    
    TTree* tree = dynamic_cast<TTree*>(file.Get("tree")); 

    
    tree->SetBranchAddress("person", &person);

  
    Int_t N = tree->GetEntries();

    
    for (Int_t i = 0; i < N; i++) {
        
        tree->GetEntry(i);

       
        std::cout << "Entry " << i << ": Age=" << person.GetAge() << ", Name=" << person.GetName() << std::endl;
    }

    TH2F* pxpyHist = new TH2F("pxpyHist", "Scatter Plot of px vs py", 100, -1.0, 1.0, 100, -1.0, 1.0);

   
    Int_t N = tree->GetEntries();
    for (Int_t i = 0; i < N; i++) {
        tree->GetEntry(i);

        
        pxpyHist->Fill(person.GetPx(), person.GetPy());
    }

    
    TCanvas* canvas = new TCanvas("canvas", "TH2 Drawing");
    pxpyHist->Draw("colz"); 

    
    canvas->Update();
    canvas->Modified();
    canvas->Print("pxpy_scatter.png"); 

    TCanvas* canvas = new TCanvas("canvas", "Scatter Plot Drawing");

    
    tree->Draw("px*py:pz", "person.GetMomentumMagnitude() > 10.0");

    
    canvas->Update();
    delete pxpyHist;
    delete canvas;

    
    

    file.Close();
}