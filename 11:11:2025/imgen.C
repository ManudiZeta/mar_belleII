void imgen(string name_file)
{
    if(name_file == "../../../vpho_Jpsi_isr_n_REC.root")
    {
        gStyle->SetOptStat(1);
        ifstream in_file("../../../vpho_Jpsi_isr_n_REC.root");
        
        if(!in_file)
        {
            cout<<"The root file doesn't exist. Generate it. \n";
            return;
        }
        in_file.close();
        TFile myf("../../../vpho_Jpsi_isr_n_REC.root");
        
        TTree *tree = (TTree*)myf.Get("tree");
        TCanvas *tela = new TCanvas();
        
        tree->Draw("vpho_r_mRecoil>>h(100,0,10)");
        TH1* h = (TH1*)gDirectory->Get("h");
        h->SetXTitle("m_{recoil} [GeV]");
        h->SetYTitle("counts []");
        h->SetTitle("Recoil mass of p+, #pi-, #gamma");
        tela->SaveAs("images/mRecoil_Jpsi.pdf");
        
        tree->Draw("gamma_mRecoil>>h(100,0,11)");
        h = (TH1*)gDirectory->Get("h");
        h->SetXTitle("m_{recoil} [GeV]");
        h->SetYTitle("counts []");
        h->SetTitle("Recoil mass of #gamma");
        tela->SaveAs("images/mRecoil_gamma_Jpsi.pdf");
        
        gStyle->SetOptStat(0);
        
        
        myf.Close();
        delete tela;
    }
    
    else if(name_file == "../../../vpho_Jpsi_isr_n_REC_kin.root")
    {
        gStyle->SetOptStat(1);
        ifstream in_file("../../../vpho_Jpsi_isr_n_REC_kin.root");
        
        if(!in_file)
        {
            cout<<"The root file doesn't exist. Generate it. \n";
            return;
        }
        in_file.close();
        TFile myf("../../../vpho_Jpsi_isr_n_REC_kin.root");
        
        TTree *tree = (TTree*)myf.Get("tree");
        TCanvas *tela = new TCanvas();
        
        tree->Draw("vpho_r_mRecoil>>h(100,0.9395642,0.939566)");
        TH1* h = (TH1*)gDirectory->Get("h");
        h->SetXTitle("m_{recoil} [GeV]");
        h->SetYTitle("counts []");
        h->SetTitle("Recoil mass of p+, #pi-, #gamma");
        tela->SaveAs("images/mRecoil_Jpsi_kin.pdf");
        
        tree->Draw("gamma_mRecoil>>h(100,0,11)");
        h = (TH1*)gDirectory->Get("h");
        h->SetXTitle("m_{recoil} [GeV]");
        h->SetYTitle("counts []");
        h->SetTitle("Recoil mass of #gamma");
        tela->SaveAs("images/mRecoil_gamma_Jpsi_kin.pdf");
        
        gStyle->SetOptStat(0);
        
        
        myf.Close();
        delete tela;
    }
    
    else if (name_file == "isrVEC_list_gamma_MC.root")
    {
        gStyle->SetOptStat(1);
        ifstream in_file("../../../isrVEC_list_gamma_MC.root");
        
        if(!in_file)
        {
            cout<<"The root file doesn't exist. Generate it. \n";
            return;
        }
        in_file.close();
        TFile myf("../../../isrVEC_list_gamma_MC.root");
        
        
        TTree *tree = (TTree*)myf.Get("tree");
        TCanvas *tela = new TCanvas();
        
        tree->Draw("p>>h(100,0,7)");
        TH1* h = (TH1*)gDirectory->Get("h");
        h->SetXTitle("p [GeV]");
        h->SetYTitle("counts []");
        h->SetTitle("ISR #gamma momentum from generator");
        tela->SaveAs("images/VECISR_p_MC.pdf");
        
        tree->Draw("theta>>h(100,0,3.2)");
        h = (TH1*)gDirectory->Get("h");
        h->SetXTitle("#theta [rad]");
        h->SetYTitle("counts []");
        h->SetTitle("ISR #gamma theta from generator");
        tela->SaveAs("images/VECISR_theta_MC.pdf");
        
        gStyle->SetOptStat(0);
        
        
        myf.Close();
        delete tela;
    }
}

