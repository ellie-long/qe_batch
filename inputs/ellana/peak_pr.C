//e04012 pion rejector calibration ( Yi )



void peak_pr(Int_t nrunped=-1, Int_t nrun=-1, Int_t detid=0)
{
  char filename[100],psfile[250];
  Int_t dummy;
  TDatime date("2008-11-07 00:00:00"); //date for data we are using
  Int_t nevt = 1000000;
  //Int_t nrunped, nrun;
  Int_t ped;

  if (nrunped<0) {
    cout << "Enter the run number for pedastal run, or -1 if do not check pedastal" << endl;
    cin >> nrunped;
  }
  if (nrunped<0) ped=0;
  else ped=1;

  TTree *t1=0, *t2=0;
  if(ped){
    sprintf(filename,"/lustre/expphy/work/halla/gdh-4/prchiran/batch/inputs/e04007_ped_%d.root",nrunped);  // pedestal data file
    printf("%s openned\n",filename);
    f1 = new TFile(filename);
    t1 =  (TTree *)f1->Get("T"); 
  }

  if (nrun<0) {
    cout << "Enter run number to use" << endl;
    cin >> nrun;
  }

  if (nrun<0) break;
  sprintf(filename,"./ROOTfiles2/e06010_det_L_%d.root",nrun);
  printf("%s openned\n",filename);
  f2 = new TFile(filename);
  t2 =  (TTree *)f2->Get("T");
  
  Int_t i, j, chtot;
  Float_t ped_old[50], ped_new[50];
  Float_t amp_old[50], amp_new[50];
  Float_t peak_new[50], fit_okay[50];

  // align the single ph.e. peak to 100 for Prl1 and Prl2
  Float_t peak_pos[2]={100.,100.};
  // detector names
  TString detname[2]={"L.prl1","L.prl2"};

  Int_t imin, imax;
  char varname[100], cutname[100];
  if (detid == 0) {
    cout << "Which detector do you want to check? (1=Prl1, 2=Prl2, 0=Quit)" <<endl;
    cin >> detid;
  }

  if ( detid<=0 || detid>2 ) break;

  gStyle->SetOptLogy(0);
  c1 = new TCanvas("c1","Detector Calibration",900,800);
  c1->Print("tmpps.ps[");


  //////////////////////////////////////////////////////////////
  /// Pion Rejector
  //////////////////////////////////////////////////////////////

  if (detid==1 || detid==2){
    printf("Pion Rejector %d Calibration:\n\n", detid);
    sprintf(varname,"L.prl%d",detid);
    Int_t chtot=getdb(varname,ped_old,amp_old,date);
    cout<<"total number of PMTs: "<<chtot<<endl;
    TH1F* h1[50];
    TH1F* h2[50];
    for(Int_t i=0; i<chtot; i++){
      h1[i] = new TH1F(Form("h1_%d",i),"",100,400,600);
      h2[i] = new TH1F(Form("h2_%d",i),"",100,500,1500);
    }
    
    for(Int_t i=0; i<chtot; i++){
      if(i%4==0){
	c1->Clear();
	if (ped) c1->Divide(2,4);
	else c1->Divide(1,4);
      }
      if(i==0){
	cout<<" which pmt do you want to start with"<<endl;
	cin>>i;
      }
      h1[i]->Reset();
      h1[i]->SetBins(100,ped_old[i]-50,ped_old[i]+50);
      sprintf(cutname,"ADC %d, pedastal",i+1);
      h1[i]->SetTitle(cutname);
      TAxis *axisx=h1[i]->GetXaxis();
      axisx->SetLabelSize(0.05);
      TAxis *axisy=h1[i]->GetYaxis();
      axisy->SetLabelSize(0.05);
      
      h2[i]->Reset();
      h2[i]->SetBins(400,ped_old[i]+40,ped_old[i]+1500);
      sprintf(cutname,"ADC %d, single ph.e. peak",i+1);
      h2[i]->SetTitle(cutname);
      axisx=h2[i]->GetXaxis();
      axisx->SetLabelSize(0.05);
      axisy=h2[i]->GetYaxis();
      axisy->SetLabelSize(0.05);  
      
      ped_new[i]=ped_old[i];
      
      // pedastals
      if (ped) {
	c1->cd((i%4)*2+1);
	printf("now look for pedastal for ADC ch %d, from %d to %d\n",i+1, ped_old[i]-50, ped_old[i]+50);
	sprintf(varname,"%s.a[%d]>>h1_%d",(char*)detname[detid-1],i,i);
	sprintf(cutname,"%s.a[%d]>%d && %s.a[%d]<%d",(char*)detname[detid-1],i,ped_old[i]-50,(char*)detname[detid-1],i,ped_old[i]+50);
	cout<<varname<<";  "<<cutname<<endl;
	t1->Draw(varname,cutname,"",5000);
	
	imin=ped_old[i]-50; 
	imax=ped_old[i]+50;

	ped_new[i]=peak(h1[i],imin,imax,ped_old[i],1.5,1.5,2);

	TLine *a0 = new TLine(ped_new[i],0.,ped_new[i],h1[i]->GetMaximum());
	a0->SetLineColor(3);
	a0->Draw();
	
	TLine *a1 = new TLine(ped_old[i],0.,ped_old[i],h1[i]->GetMaximum());
	a1->SetLineColor(2);
	a1->Draw();
      }
      // end of pedestals
      
      c1->cd((i%4)*(1+ped)+1+ped);
      
      sprintf(varname,"%s.a[%d]>>h2_%d",(char*)detname[detid-1],i,i);
      //sprintf(cutname,"abs(%s.x-(%f))<0.05",(char*)detname[detid-1],1.2-(i%17)*0.15-0.05*(detid-1)); // piupoiupoiu

      sprintf(cutname,"%s.a_p[%d]>10.&&L.tr.n==1&&DL.evtype==3&&L.cer.asum_c<100",(char*)detname[detid-1],i);
      cout<<varname<<";  "<<cutname<<endl;
      
      t2->Draw(varname,cutname,"",nevt);

      // peak search
      if(amp_old[i]>0) {
	Float_t ori_peak = ped_old[i]+200.;// /amp_old[i];
	peak_new[i]=peak(h2[i],ped_old[i]+100,ori_peak+200,ori_peak,1.1,1.3,5);
        cout<< " Peak at ="<<peak_new[i]<<endl;
      }
      else Float_t ori_peak = 0;
      
      // end of peak search

      // plot new peak position
      if(peak_new[i]!=0&&peak_new[i]!=ped_new[i]) amp_new[i]=175./(peak_new[i]-ped_new[i]);
      cout<<"Peak after pedestal = " <<(peak_new[i]-ped_new[i]) << endl;
      cout<<"Amp new = " <<amp_new[i]<<endl;
      

      TLine *a0 = new TLine(peak_new[i],0.,peak_new[i],h2[i]->GetMaximum());
      a0->SetLineColor(3);
      a0->Draw();
      
      TLine *a1 = new TLine(ori_peak,0.,ori_peak,h2[i]->GetMaximum());
      a1->SetLineColor(2);
      a1->Draw();
      c1->Update();
      if(i%4==3||i==chtot-1) c1->Print("tmpps.ps");
      
      cout << "Enter 0 to exit, 1 to deny the fit, or 2 to accept the fit" <<endl;
      cin >> dummy;
      switch (dummy) {
      case 0:
	return;
	break;
      case 1:
	fit_okay[i]=0; 
	amp_new[i]=amp_old[i];
	break;
      case 2:
	fit_okay[i]=1;
	break;
      default:
	cout << "Invalid option" << endl;
	cout << "Exiting program ... " << endl;
	exit(1);
	/*if (atoi(dummy)==-1) break;
	else if (atoi(dummy)==0){fit_okay[i]=0; amp_new[i]=amp_old[i];}
	else fit_okay[i]=1;*/
      }

    }

    c1->Print("tmpps.ps]");
    sprintf(psfile,"mv tmpps.ps prl%d_%d.ps",detid,nrun);
    system(psfile);

    // output
    
    for (i=0;i<chtot;i++){
      if (fit_okay[i]==1){
	if (amp_new[i]) 
	  printf("channel %d: ped_o=%d ped_n=%d amp_o=%.3f amp_n=%.3f\n",
		 i+1, ped_old[i], ped_new[i], amp_old[i], amp_new[i]);
      }
      else printf("channel %d: ped_o=%d ped_n=%d amp_o=%.3f amp_new failed\n",
		  i+1, ped_old[i], ped_new[i], amp_old[i]);
    }


    sprintf(filename,"db_%s.dat.new",(char*)detname[detid-1]);
    FILE* newdbfile = fopen(filename,"w+");
    {
      fprintf(newdbfile, "ADC pedestals");
      for(i=0;i<chtot;i++){
	if(i%15==0) fprintf(newdbfile,"\n");
	fprintf(newdbfile, "%d   ",ped_new[i]);
      }
      fprintf(newdbfile, "\nEnergy calibration coefficients\n");
      for(i=0;i<chtot;i++){
	//if(i%15==0) fprintf(newdbfile,"\n");
	fprintf(newdbfile, "%d %.3f\n",i+1,amp_new[i]);
      }
    }
    fclose(newdbfile);
    

    printf("Replace the constants in file <db_%s.dat> by the following:\n\n",(char*)detname[detid-1]);
    printf("ADC pedestals");
    for(i=0;i<chtot;i++)  {
      if(i%15==0) printf("\n");
      printf("%d   ",ped_new[i]);
    };
    printf("\nEnergy calibration coefficients");
    for(i=0;i<chtot;i++) {
      if(i%15==0) printf("\n");
      printf("%.3f  ",amp_new[i]);
    }
     cout << endl;
    cout << "also saved in db_"<<detname[detid-1]<<".dat.new"<<endl;
    
  }
}

Float_t peak(TH1F* tmph, Float_t imin, Float_t imax, Float_t peak_old, Float_t sig_l, Float_t sig_r, Int_t loop_time){

  Float_t peak_new = 0;
  imin = histo_min(tmph, imin, peak_old);
  imax = histo_min(tmph, peak_old, imax);

  tmph->Fit("gaus","","",imin,imax);
  TF1* fit1 = tmph->GetFunction("gaus");
  Float_t p0 = fit1->GetParameter(0);
  Float_t p1 = fit1->GetParameter(1);
  Float_t p2 = fit1->GetParameter(2);
  printf("Coarse fit result, peak: %.2f, sigma: %.2f\n",p1, p2);
  c1->Update();

  for (int ii = 0; ii < loop_time; ii++){
    Float_t tmpmin = p1-p2*sig_l;
    if (imin>tmpmin||imax<tmpmin) tmpmin=imin;
    Float_t tmpmax = p1+p2*sig_r;
    if (imax<tmpmax||imin>tmpmax) tmpmax=imax;
    printf("No.%d fine fit from %d to %d\n", ii+1, tmpmin, tmpmax);
    tmph->Fit("gaus","","",tmpmin,tmpmax);
    fit1 = tmph->GetFunction("gaus");
    p0 = fit1->GetParameter(0);
    p1 = fit1->GetParameter(1);
    p2 = fit1->GetParameter(2);
    printf("No.%d fit result: peak: %.2f, sigma: %.2f\n", ii+1, p1, p2);
    c1->Update();
  }

  if(p1>imin&&p1<imax) peak_new = p1;
  return peak_new;
}

Float_t histo_min(TH1F* tmph, Float_t xmin, Float_t xmax){
  Float_t hmin = tmph->GetBinLowEdge(1);
  Float_t binw = tmph->GetBinWidth(1);
  Int_t nbins = tmph->GetNbinsX();
  Int_t imin = (xmin-hmin)/binw+1;
  if(imin<1) imin=1;
  Int_t imax = (xmax-hmin)/binw;
  if(imax>nbins) imax=nbins;
  Int_t min_bin = imin;
  Float_t min = tmph->GetBinContent(imin);
  for (Int_t i=imin+1; i<= imax; i++){
    Float_t tmpy = tmph->GetBinContent(i);
    if(tmpy<min){
      min_bin=i;
      min=tmpy;
    }
  }
  min = tmph->GetBinCenter(min_bin);
  return min;
}

Float_t histo_max(TH1F* tmph, Float_t xmin, Float_t xmax){
  Float_t hmin = tmph->GetBinLowEdge(1);
  Float_t binw = tmph->GetBinWidth(1);
  Int_t nbins = tmph->GetNbinsX();
  Int_t imin = (xmin-hmin)/binw+1;
  if(imin<1) imin=1;
  Int_t imax = (xmax-hmin)/binw;
  if(imax>nbins) imax=nbins;
  Int_t max_bin = imin;
  Float_t max = tmph->GetBinContent(imin);
  for (Int_t i=imin+1; i<= imax; i++){ 
    Float_t tmpy = tmph->GetBinContent(i);
    if(tmpy>max){
      max_bin=i;
      max=tmpy;
    }
  }
  max = tmph->GetBinCenter(min_bin);
  return max;
}

Int_t getdb(TString detname, Float_t* ped_old, Float_t* amp_old, TDatime date){
  FILE* dbfile = THaAnalysisObject::OpenFile((char*)detname,date,"","r",1);
  char buf[256];
  Int_t detnn[2];
  for (Int_t j=0;j<2;j++) fgets(buf,256,dbfile); // get two dummy lines from data file
  Int_t k = fscanf(dbfile,"%d %d",detnn,detnn+1);
  Int_t pmtn=0;
  char dum1[100];
  char dum2[100];
  if(k==2) pmtn=detnn[0]*detnn[1];
  if(pmtn==0){
    cout<<"Incorrect database, check it.. "<<endl;
    return 0;
  }
  while(fgets(buf,256,dbfile)){
    if(buf[0] == '#' || buf[0] == '\n' )
      continue;
    sscanf(buf,"%s%s",dum1,dum2);
    if(strcmp(dum1,"ADC")==0&&strcmp(dum2,"pedestals")==0){
      for (Int_t j=0;j<pmtn;j++){
	fscanf(dbfile,"%f",ped_old+j);
	//	cout<<j+1<<": "<<ped_old[j]<<endl;
      }
      break;
    }
  }
  while(fgets(buf,256,dbfile)){
    if(buf[0] == '#' || buf[0] == '\n' )
      continue;
    sscanf(buf,"%s%s",dum1,dum2);
    if(strcmp(dum1,"Energy")==0&&strcmp(dum2,"calibration")==0){
      for (Int_t j=0;j<pmtn;j++){
	fscanf(dbfile,"%f",amp_old+j);
	//	cout<<j+1<<": "<<amp_old[j]<<endl;;
      }
      break;
    }
  }
  return pmtn;
}
