
void imgen_phsp()
{
    gStyle->SetOptStat(1);
    ifstream in_file("../../../vpho_p_pi_n_REC.root");
    
    if(!in_file)
    {
        cout<<"The root file doesn't exist. Generate it. \n";
        return;
    }
    in_file.close();
    TFile myf("../../../vpho_p_pi_n_REC.root");
    
    TTree *tree = (TTree*)myf.Get("tree");
    TCanvas *tela = new TCanvas();
    
    tree->Draw("vpho_mRecoil>>h(100,0,7.5)");
    TH1* h = (TH1*)gDirectory->Get("h");
    h->SetXTitle("m_{recoil} [GeV]");
    h->SetYTitle("counts []");
    h->SetTitle("REC mRecoil PHSP");
    tela->SaveAs("images/mRecoil_PHSP.pdf");
    
    tree->Draw("vpho_mRecoil>>h(100,0,7.5)","alpha<0.35");
    h = (TH1*)gDirectory->Get("h");
    h->SetXTitle("m_{recoil} [GeV]");
    h->SetYTitle("counts []");
    h->SetTitle("REC mRecoil PHSP");
    tela->SaveAs("images/mRecoil_PHSP_35.pdf");
    
    gStyle->SetOptStat(0);
    tree->Draw("vpho_pRecoilTheta:nbar_theta>>h(50, 0, 3.2, 50, 0, 3.2)","","colz");
    h = (TH2*)gDirectory->Get("h");
    h->SetXTitle("anti-n0 #theta [rad]");
    h->SetYTitle("pRecoil #theta [rad]");
    h->SetTitle("PHSP #theta REC");
    tela->SaveAs("images/theta_corr_rec_PHSP.pdf");
    
    tree->Draw("vpho_pRecoilTheta:nbar_theta>>h(50, 0, 3.2, 50, 0, 3.2)","alpha<0.35","colz");
    h = (TH2*)gDirectory->Get("h");
    h->SetXTitle("anti-n0 #theta [rad]");
    h->SetYTitle("pRecoil #theta [rad]");
    h->SetTitle("PHSP #theta REC");
    tela->SaveAs("images/theta_corr_rec_PHSP_35.pdf");
    
    tree->Draw("vpho_pRecoil:nbar_p>>h(100, 0, 50, 50, 0, 7.)","","colz");
    h = (TH2*)gDirectory->Get("h");
    h->SetXTitle("anti-n0 p [GeV]");
    h->SetYTitle("pRecoil p [GeV]");
    h->SetTitle("PHSP p REC");
    tela->SaveAs("images/p_corr_PHSP_rec.pdf");
    
    tree->Draw("vpho_eRecoil:nbar_clusterE>>h(50, 0, 7., 50, 0, 7.)","nbar_genMotherPDG == 300553","colz");
    h = (TH2*)gDirectory->Get("h");
    h->SetXTitle("anti-n0 clusterE [GeV]");
    h->SetYTitle("pRecoil E [GeV]");
    h->SetTitle("PHSP clusterE REC");
    tela->SaveAs("images/clusterE_corr_PHSP.pdf");
   
   
    myf.Close();
    delete tela;
    
}

void imgen_isr()
{
    gStyle->SetOptStat(1);
    ifstream in_file("../../../vpho_isr_gamma_REC.root");
    
    if(!in_file)
    {
        cout<<"The root file doesn't exist. Generate it. \n";
        return;
    }
    in_file.close();
    TFile myf("../../../vpho_isr_gamma_REC.root");
    
    TTree *tree = (TTree*)myf.Get("tree");
    TCanvas *tela = new TCanvas();
    
    tree->Draw("vpho_mRecoil>>h(100,0,10)");
    TH1* h = (TH1*)gDirectory->Get("h");
    h->SetXTitle("m_{recoil} [GeV]");
    h->SetYTitle("counts []");
    h->SetTitle("REC mRecoil ISR");
    tela->SaveAs("images/mRecoil_ISR.pdf");
    
    tree->Draw("vpho_mRecoil>>h(100,0,7.5)","alpha<0.35");
    h = (TH1*)gDirectory->Get("h");
    h->SetXTitle("m_{recoil} [GeV]");
    h->SetYTitle("counts []");
    h->SetTitle("REC mRecoil ISR");
    tela->SaveAs("images/mRecoil_ISR_35.pdf");
    
    gStyle->SetOptStat(0);
    tree->Draw("vpho_pRecoilTheta:nbar_theta>>h(50, 0, 3.2, 50, 0, 3.2)","","colz");
    h = (TH2*)gDirectory->Get("h");
    h->SetXTitle("anti-n0 #theta [rad]");
    h->SetYTitle("pRecoil #theta [rad]");
    h->SetTitle("ISR #theta REC");
    tela->SaveAs("images/theta_corr_rec_ISR.pdf");
    
    tree->Draw("vpho_pRecoilTheta:nbar_theta>>h(50, 0, 3.2, 50, 0, 3.2)","alpha<0.35","colz");
    h = (TH2*)gDirectory->Get("h");
    h->SetXTitle("anti-n0 #theta [rad]");
    h->SetYTitle("pRecoil #theta [rad]");
    h->SetTitle("ISR #theta REC");
    tela->SaveAs("images/theta_corr_rec_ISR_35.pdf");
    
    tree->Draw("vpho_pRecoil:nbar_p>>h(100, 0, 50, 50, 0, 7.)","","colz");
    h = (TH2*)gDirectory->Get("h");
    h->SetXTitle("anti-n0 p [GeV]");
    h->SetYTitle("pRecoil p [GeV]");
    h->SetTitle("ISR p REC");
    tela->SaveAs("images/p_corr_ISR_rec.pdf");
    
    tree->Draw("vpho_eRecoil:nbar_clusterE>>h(50, 0, 7., 50, 0, 7.)","nbar_genMotherPDG == 10022","colz");
    h = (TH2*)gDirectory->Get("h");
    h->SetXTitle("anti-n0 clusterE [GeV]");
    h->SetYTitle("pRecoil E [GeV]");
    h->SetTitle("ISR clusterE REC");
    tela->SaveAs("images/clusterE_corr_ISR.pdf");
   
   
    myf.Close();
    delete tela;
    
}

