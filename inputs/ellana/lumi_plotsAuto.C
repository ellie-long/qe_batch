//This plots some interesting lumi stuff (to be determined).  Just enter the run number you are looking at.

//  to open a file, type >>  TFile *_file0 = TFile::Open("lumi_2921.root")

void lumi_plots(int therun){
  Bool_t NEWrun;
  Int_t runnumber;
  TString t;
  //cout<<"What is the run number?"<<endl;
  //cin>>runnumber;
  runnumber = therun;
  t = Form("LumiROOTFiles/lumi_%d.root",runnumber);
  
  TFile *_file0 = TFile::Open(t);
  
  //Here are the things to be plotted...
  
  // Define Canvas
  TCanvas* c1 = new TCanvas("c1","Lumi Data",820,10,800,800);
  c1->Divide(2,4);
  TPad* c1_1 = (TPad*)(c1->GetPrimitive("c1_1"));
  c1_1->SetBorderMode(0); 
  TPad* c1_2 = (TPad*)(c1->GetPrimitive("c1_2"));
  c1_2->SetBorderMode(0); 
  TPad* c1_3 = (TPad*)(c1->GetPrimitive("c1_3"));
  c1_3->SetBorderMode(0); 
  TPad* c1_4 = (TPad*)(c1->GetPrimitive("c1_4"));
  c1_4->SetBorderMode(0); 
  TPad* c1_5 = (TPad*)(c1->GetPrimitive("c1_5"));
  c1_5->SetBorderMode(0);
  TPad* c1_6 = (TPad*)(c1->GetPrimitive("c1_6"));
  c1_6->SetBorderMode(0);
  c1->cd(1);
  
  c1->cd(1);
  //f1->cd();
  TH1F* h1 = new TH1F ("h1","LumiSum1_u", 400, -0.1,0.1);
  lumi->Draw("evtype:Entry$");
  
  h1->SetTitle("Event Type");
  h1->SetLineColor(2);
  h1->GetXaxis()->SetTitle("Entry Number");
  h1->GetXaxis()->CenterTitle();
  h1->GetXaxis()->SetLabelSize(0.02);
  h1->GetXaxis()->SetTitleSize(0.0325);
  h1->GetYaxis()->SetLabelSize(0.03);
  
    
  c1->cd(2);
  TH1F* h2 = new TH1F ("h2","LumiSum1_d", 5000, -1.1,1.1);
  lumi->Draw("target:Entry$");
  
  h2->SetTitle("Target State");
  h2->SetLineColor(2);
  h2->GetXaxis()->SetTitle("Entry Number");
  h2->GetXaxis()->CenterTitle();
  h2->GetXaxis()->SetLabelSize(0.03);
  h2->GetXaxis()->SetTitleSize(0.0425);
  h2->GetYaxis()->SetLabelSize(0.03);
  
    
  c1->cd(3);
  TH1F* h3 = new TH1F ("h3","All Lumis(up) versus Entry", 100000, 0.0,1000000.0);
  lumi->Draw("(lumiSum1_u+lumiSum2_u+lumiSum3_u+lumiSum4_u+lumiSum5_u+lumiSum6_u+lumiSum7_u+lumiSum8_u):Entry$");
  h3->SetTitle("All Lumis Up (SUM)");
  h3->SetLineColor(2);
  h3->GetXaxis()->SetTitle("All 8 Target up");
  h3->GetXaxis()->CenterTitle();
  h3->GetXaxis()->SetLabelSize(0.03);
  h3->GetXaxis()->SetTitleSize(0.0425);
  h3->GetYaxis()->SetLabelSize(0.03);
  
  
  c1->cd(4);
  TH1F* h4 = new TH1F ("h4","All Lumis(d) vs. Entry", 100, -0.002,0.004);
  lumi->Draw("(lumiSum1_d+lumiSum2_d+lumiSum3_d+lumiSum4_d+lumiSum5_d+lumiSum6_d+lumiSum7_d+lumiSum8_d):Entry$");
  h4->SetLineColor(2);
  h4->GetXaxis()->SetTitle("All Lumis Down (SUM)");
  h4->GetXaxis()->CenterTitle();
  h4->GetXaxis()->SetLabelSize(0.03);
  h4->GetXaxis()->SetTitleSize(0.0425);
  h4->GetYaxis()->SetLabelSize(0.03);
  
  
  c1->cd(5);
  TH1F* h5 = new TH1F ("h5","BCMs", 100, 0.0,5.0);
  lumi->Draw("BCMupx10_u:Entry$");
  h5->SetLineColor(2);
  h5->GetXaxis()->SetTitle("BCM(upstream)x10 (target up)");
  h5->GetXaxis()->CenterTitle();
  h5->GetXaxis()->SetLabelSize(0.03);
  h5->GetXaxis()->SetTitleSize(0.0425);
  h5->GetYaxis()->SetLabelSize(0.03);
  
  
  /*
c1->cd(6);
TH1F* h6 = new TH1F ("h6","crap6", 100, -1000.0,1000.0);
lumi->Draw("((lumiSum1_u+lumiSum2_u+lumiSum3_u+lumiSum4_u+lumiSum5_u+lumiSum6_u+lumiSum7_u+lumiSum8_u)/(BCMdownx10_u)-(lumiSum1_d+lumiSum2_d+lumiSum3_d+lumiSum4_d+lumiSum5_d+lumiSum6_d+lumiSum7_d+lumiSum8_d)/(BCMdownx10_d))/((lumiSum1_u+lumiSum2_u+lumiSum3_u+lumiSum4_u+lumiSum5_u+lumiSum6_u+lumiSum7_u+lumiSum8_u)/(BCMdownx10_u)+(lumiSum1_d+lumiSum2_d+lumiSum3_d+lumiSum4_d+lumiSum5_d+lumiSum6_d+lumiSum7_d+lumiSum8_d)/(BCMdownx10_d)):event");
h6->SetLineColor(2);
h6->GetXaxis()->SetTitle("count_uu:event");
h6->GetXaxis()->CenterTitle();
h6->GetXaxis()->SetLabelSize(0.03);
h6->GetXaxis()->SetTitleSize(0.0425);
h6->GetYaxis()->SetLabelSize(0.03);
*/
c1->cd(6);
TH1F* h6 = new TH1F ("h6","count_u", 100, -1000.0,1000.0);
lumi->Draw("BCMupx10_d:Entry$");
h6->SetLineColor(2);
h6->GetXaxis()->SetTitle("BCM(upstream)x10 (target down)");
h6->GetXaxis()->CenterTitle();
h6->GetXaxis()->SetLabelSize(0.03);
h6->GetXaxis()->SetTitleSize(0.0425);
h6->GetYaxis()->SetLabelSize(0.03);


c1->cd(7);
TH1F* h7 = new TH1F ("h7","fastclock_u", 100, -1000.0,1000.0);
lumi->Draw("fastclock_u:Entry$");
h6->SetLineColor(2);
h6->GetXaxis()->SetTitle("103.7kHz clock(target up)");
h6->GetXaxis()->CenterTitle();
h6->GetXaxis()->SetLabelSize(0.03);
h6->GetXaxis()->SetTitleSize(0.0425);
h6->GetYaxis()->SetLabelSize(0.03);


c1->cd(8);
TH1F* h8 = new TH1F ("h8","count_u", 100, -1000.0,1000.0);
lumi->Draw("fastclock_d:Entry$");
h6->SetLineColor(2);
h6->GetXaxis()->SetTitle("103.7kHz clock(target down)");
h6->GetXaxis()->CenterTitle();
h6->GetXaxis()->SetLabelSize(0.03);
h6->GetXaxis()->SetTitleSize(0.0425);
h6->GetYaxis()->SetLabelSize(0.03);






}
