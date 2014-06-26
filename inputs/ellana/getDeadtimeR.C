//////////////////////////////////////////////////////////////////////
//
// getDeadtime.C
//  Bryan Moffit - April 2008
//
//  ROOT macro to extract some info from a BBNormAna output
//   to be displayed in the onlineGUI
#define DEBUG

struct triginfo {
  Int_t prescale[8];
  Int_t coda_events[8];
  Int_t scaler_events[8];
  Double_t livetime[8];
  Double_t deadtime[8];
  Double_t ave_livetime;
  Double_t ave_livetime_err;
  Int_t tot_events=0;
};


void getDeadtime()
{

  UInt_t runnumber=0;
  // Get the current runnumber
  THaRun *runinfo = (THaRun*)gROOT->FindObject("Run_Data");
  if(runinfo==NULL) return;
  runnumber = runinfo->GetNumber();

#ifdef DEBUG
  cout << "getDeadtime():  runnumber = " << runnumber << endl;
#endif

  // Use the runnumber to find the proper output file.
  // We will eventually use the def.h file to get the filename format.
  char *normana_fileformat = "./summaryfiles/RNormAna%d.log";

  TString normana_outputfile =
    Form(normana_fileformat,runnumber);
#ifdef DEBUG
  cout << "getDeadtime(): normana_outputfile = " << normana_outputfile
       << endl;
#endif

  triginfo sNormAnaFile = ParseFile(normana_outputfile);

  Double_t triggers[8] = {1,2,3,4,5,6,7,8};

  TGraph *gr = new TGraph(8,triggers,sNormAnaFile.deadtime);
  TString graph_title;
  if(sNormAnaFile.tot_events!=0) {
    graph_title = 
      Form("Trigger deadtime for first %d events",sNormAnaFile.tot_events);
  } else {
    graph_title = 
      Form("Trigger deadtime",sNormAnaFile.tot_events);
  }
  graph_title += 
    Form(". Weighted Average = %.2f #pm %.2f (%)",
	 100. - 100.*sNormAnaFile.ave_livetime,
	 100.*sNormAnaFile.ave_livetime_err);
	 
  gr->SetTitle(graph_title+";Trigger;Deadtime (%)");
  gr->SetMarkerStyle(20);
  gr->SetMarkerColor(kBlue);
  gr->SetMinimum(0);
  gr->SetMaximum(gr->GetHistogram()->GetMaximum()+10.); 
  gr->Draw("AP");
    

  delete runinfo;
    
  return;
}

triginfo 
ParseFile(TString normana_filename) 
{
  // Borrowed/Stolen routine from onlineGUI.
  // Reads in the Config File, and makes the proper calls to put
  //  the information contained into memory.

  triginfo sNormAnaFile;
  sNormAnaFile.tot_events=0;

  ifstream *fNormAnaFile = new ifstream(normana_filename);
  if(!fNormAnaFile) {
    cout << "getDeadtime(): Did not find output file: " <<
      normana_filename << endl;
    return sNormAnaFile;
  }

  TString comment = "#";
  vector<TString> svline;
  TString sinput, sline;
  Bool_t done=kFALSE;
  while (sline.ReadLine(*fNormAnaFile)||!done) {
    svline.clear();
    // Strip away leading and trailing spaces.
    sline = sline.Strip(TString::kBoth,' ');
    // If the line starts with a comment, skip it.
    if(sline.BeginsWith(comment)) continue;
    // If the line contains a comment, split it up into two and keep
    // the uncommented (first) part
    if(sline.Contains(comment)) {
      TObjArray *tmpoarr = sline.Tokenize(comment);
      TObjString *tmpostr = (TObjString*)tmpoarr->First();
      sline = tmpostr->GetString().Strip(TString::kTrailing,' ');
      delete tmpostr;
      delete tmpoarr;
    }
    TObjArray *tmpoarr2 = sline.Tokenize(" ");
    TIterator *next2 = tmpoarr2->MakeIterator();
    TObjString *tmpostr2;
    while((tmpostr2=(TObjString*)next2->Next())!=NULL) {
      svline.push_back(tmpostr2->GetString());
    }
    delete tmpostr2;
    delete next2;
    delete tmpoarr2;
    
    //  Get the trigger info here.
    if(svline[0].IsDigit()) {
      UInt_t trig = svline[0].Atoi();
      if(trig>8) continue;
      sNormAnaFile.prescale[trig-1] = svline[1].Atoi();
      sNormAnaFile.coda_events[trig-1] = svline[2].Atoi();
      sNormAnaFile.scaler_events[trig-1] = svline[3].Atoi();
      sNormAnaFile.livetime[trig-1] = 100.*svline[4].Atof();
      // If we have CODA events for this trigger calculate the deadtime
      if(svline[2].Atoi()!=0) { 
      sNormAnaFile.deadtime[trig-1] = 
	100. - sNormAnaFile.livetime[trig-1];
      } else sNormAnaFile.deadtime[trig-1] = 0.0;
#ifdef DEBUG
      cout << trig << " " << sNormAnaFile.livetime[trig-1] 
	   << " " << sNormAnaFile.deadtime[trig-1] << endl;
#endif
    }
    if(svline[0]=="Weighted") {
      sNormAnaFile.ave_livetime = svline[4].Atof();
      sNormAnaFile.ave_livetime_err = svline[6].Atof();
    }
    if(svline[0]=="Number") {
      sNormAnaFile.tot_events = svline[4].Atoi();
      break;
    }
    if( !fNormAnaFile->good() ) break;
  }
  fNormAnaFile->close();
  delete fNormAnaFile;

  return sNormAnaFile;
    
}

