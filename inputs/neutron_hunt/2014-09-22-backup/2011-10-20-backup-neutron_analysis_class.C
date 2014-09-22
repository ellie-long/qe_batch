#define MyClass_cxx
#include "MyClass.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <time.h>
#include <math.h>
#include "hand_class_basic_cuts.h"
#include "hand_class_veto_cuts.h"
#include "hand_class_bar_th_cuts.h"
#include "hand_class_draw_basic.h"
#include "hand_class_fill_bar_by_bar_cuts.h"
#include "hand_class_draw_bar_by_bar_cuts.h"
#include "hand_class_fill_good_events.h"
#include "hand_class_draw_tof_nu.h"

void MyClass::Loop()
{
	cout << "vvvvvvvvvvvvvvvvvvvvv neutron_analysis_class.C vvvvvvvvvvvvvvvvvvvvvv" << endl;

//      If includeVetos = false, then only good bars will be displayed. If 
//      includeVetos = true, then veto bars will be shown along with the good bars.
//	bool includeVetos = true;
	bool includeVetos = false;

//      bool drawCuts = true;
        bool drawCuts = false;

        
	time_t seconds;
	seconds = time (NULL);
	int beginTime = seconds;
	string line = "";
	ifstream runNumberInputFile ("./input.file");
	getline(runNumberInputFile, line);
	int inRunNumber = atoi(line.c_str());
	int HeRunNumber = inRunNumber;
	cout << "HeRunNumber: " << HeRunNumber << endl;

	gROOT->SetStyle("Plain");

	cout << "Adding files to chain..." << endl;
	TChain *chainHe = new TChain("T");
	TString filenameHe;
	for (int t=0; t<1000; t++)
	{
//		filenameHe = "/home/ellie/physics/e05-102/ellana/ROOTfiles/e05102_R_";
		filenameHe = "./e05102_R_";
		filenameHe += HeRunNumber;
		if (t != 0)
		{
			filenameHe += "_";
			filenameHe += t;
		}
		filenameHe += ".root";
		ifstream ifileHe(filenameHe);
		if (ifileHe)
		{
			cout << "Adding file to chainHe: " << filenameHe << endl;
			chainHe->Add(filenameHe);
		}
		else
		{
			cout << "File " << filenameHe << " does not exist. Ending here." << endl;
			t=999999999;
		}
	}


	TString dataset;

// vvvvvvvvvvvvvvvvvvvvvv Define Kinematics Settings vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

// **************** Vertical, Q2=1.0 *******************
	if ((inRunNumber > 20585) && (inRunNumber < 20879))
	{
		cout << "Processing Vertically polarized, Q2=1.0 dataset..." << endl;
		dataset = "Vertical, Q2=1.0";
	//              int HeRunNumber = 20596;
		int HeRunNumber = inRunNumber;
	//              int endHeRunNumber = 20683;
		int endHeRunNumber = inRunNumber;
		TString Q2 = "1.0";
		double q2min = 0.75;
		double q2max = 1.2;
		double numin = 0.3;
		double numax = 0.7;
		int Positionbins = 30;
		double Positionmin = -30;
		double Positionmax = 30;
		int TDCbins = 200;
		double TDCmin = 1300;
		double TDCmax = 1700;
		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;
		double goodTDCleftcutmin = 1385;
		double goodTDCleftcutmax = 1415;
		double goodTDCrightcutmin = 1385;
		double goodTDCrightcutmax = 1415;
		double vetoTDCcutmin = 1385;
		double vetoTDCcutmax = 1415;
		const int nuBins = 10;
		double nuMin = 0.35;
		double nuMax = 0.65;


	}

// **************************** Vertical, Q2=0.5 *******************
	if ((inRunNumber > 20889) && (inRunNumber < 21007))
	{
		cout << "Processing Vertically polarized, Q2=0.5 dataset..." << endl;
		dataset = "Vertical, Q2=0.5";
		int HeRunNumber = inRunNumber;
		int endHeRunNumber = inRunNumber;
		TString Q2 = "0.5";
		double q2min = 0.3;
		double q2max = 0.6;
		double numin = 0.1;
		double numax = 0.35;
		int Positionbins = 30;
		double Positionmin = -30;
		double Positionmax = 30;
		int TDCbins = 75;
		double TDCmin = 1300;
		double TDCmax = 1500;
		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;
		double goodTDCleftcutmin = 1385;
		double goodTDCleftcutmax = 1415;
		double goodTDCrightcutmin = 1385;
		double goodTDCrightcutmax = 1415;
		double vetoTDCcutmin = 1385;
		double vetoTDCcutmax = 1415;
		const int nuBins = 10;
		double nuMin = 0.125;
		double nuMax = 0.425;


	}

// ********* Vertical, Q2=0.42 *******************
	if ((inRunNumber > 21193) && (inRunNumber < 21513))
	{
		cout << "Processing Vertically polarized, Q2=0.42 dataset..." << endl;
		dataset = "Vertical, Q2=0.42";
		int HeRunNumber = inRunNumber;
		int endHeRunNumber = inRunNumber;
		TString Q2 = "0.42";
		double q2min = 0.33;
		double q2max = 0.51;
		double numin = 0.17;
		double numax = 0.3;
		int Positionbins = 30;
		double Positionmin = -30;
		double Positionmax = 30;
	//              int TDCbins = 50;
	//              double TDCmin = 700;
	//              double TDCmax = 800;
		int TDCbins = 150;
		double TDCmin = 0;
		double TDCmax = 1600;   
		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;
		double goodTDCleftcutmin = 730;
		double goodTDCleftcutmax = 770;
		double goodTDCrightcutmin = 740;
		double goodTDCrightcutmax = 780;
		double vetoTDCcutmin = 730; 
		double vetoTDCcutmax = 770; 
		const int nuBins = 10; 
		double nuMin = 0.35; 
		double nuMax = 0.65;


	}


// **************************** Vertical, Q2=0.1 *******************
//      if ((inRunNumber > 20486) && (inRunNumber < 20541))
	if ((inRunNumber > 20400) && (inRunNumber < 20541))
	{
		cout << "Processing Vertically polarized, Q2=0.1 dataset..." << endl;
		dataset = "Vertical, Q2=0.1";
		int HeRunNumber = inRunNumber;
		int endHeRunNumber = inRunNumber;
		TString Q2 = "0.1";
		double q2min = 0.08;
		double q2max = 0.18;
		double numin = 0.0;
		double numax = 0.13;
		int Positionbins = 30;
		double Positionmin = -30;
		double Positionmax = 30;
//		int TDCbins = 40;
//		double TDCmin = 1325;
//		double TDCmax = 1525;
		int TDCbins = 50;
		double TDCmin = 0;
		double TDCmax = 3100;

		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;
		double goodTDCleftcutmin = 1390;
		double goodTDCleftcutmax = 1440;
		double goodTDCrightcutmin = 1390;
		double goodTDCrightcutmax = 1440;
		double vetoTDCcutmin = 1390;
		double vetoTDCcutmax = 1440;
	/*
		double goodTDCleftcutmin = 10;
		double goodTDCleftcutmax = 3100;
		double goodTDCrightcutmin = 10;
		double goodTDCrightcutmax = 3100;
		double vetoTDCcutmin = 0;
		double vetoTDCcutmax = 3100;
	*/
		const int nuBins = 10;
		double nuMin = 0;
		double nuMax = 0.15;


	}

// ************* Longitudinal, Q2=1.0 *******************
	if ((inRunNumber > 22379) && (inRunNumber < 22445))
	{
		cout << "Processing Longitudinally polarized, Q2=1.0 dataset..." << endl;
		dataset = "Longitudinal, Q2=1.0";
	//              int HeRunNumber = 22451;
		int HeRunNumber = inRunNumber;
	//              int endHeRunNumber = 22451;
		int endHeRunNumber = inRunNumber;
	//              int endHeRunNumber = 22489;
		TString Q2 = "1.0";
		double q2min = 0.75;
		double q2max = 1.2;
		double numin = 0.3;
		double numax = 0.7;
		int Positionbins = 30;
		double Positionmin = -30;
		double Positionmax = 30;
		int TDCbins = 100;
		double TDCmin = 650;
		double TDCmax = 850;

	//              int TDCbins = 600;
	//              double TDCmin = 0;
	//              double TDCmax = 1600;

		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;

		double goodTDCleftcutmin = 745;
		double goodTDCleftcutmax = 775;
		double goodTDCrightcutmin = 750;
		double goodTDCrightcutmax = 780;

	//              double goodTDCleftcutmin = 645;
	//              double goodTDCleftcutmax = 875;
	//              double goodTDCrightcutmin = 650;
	//              double goodTDCrightcutmax = 880;
	/*      
		double goodTDCleftcutmin = 1;
		double goodTDCleftcutmax = 1600;
		double goodTDCrightcutmin = 1;
		double goodTDCrightcutmax = 1600;
	*/

		double vetoTDCcutmin = 745;
		double vetoTDCcutmax = 780;
		const int nuBins = 10;
		double nuMin = 0.35;
		double nuMax = 0.65;
	}

// ************* Transverse, Q2=1.0 *******************
	if ((inRunNumber > 22446) && (inRunNumber < 22490))
	{
		cout << "Processing Transverse polarized, Q2=1.0 dataset..." << endl;
		dataset = "Transverse, Q2=1.0";
	//              int HeRunNumber = 22451;
		int HeRunNumber = inRunNumber;
	//              int endHeRunNumber = 22451;
		int endHeRunNumber = inRunNumber;
	//              int endHeRunNumber = 22489;
		TString Q2 = "1.0";
		double q2min = 0.75;
		double q2max = 1.2;
		double numin = 0.3;
		double numax = 0.7;
		int Positionbins = 30;
		double Positionmin = -30;
		double Positionmax = 30;
		int TDCbins = 100;
		double TDCmin = 650;
		double TDCmax = 850;

//              int TDCbins = 600;
//              double TDCmin = 0;
//              double TDCmax = 1600;

		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;

		double goodTDCleftcutmin = 745;
		double goodTDCleftcutmax = 775;
		double goodTDCrightcutmin = 750;
		double goodTDCrightcutmax = 780;

//              double goodTDCleftcutmin = 645;
//              double goodTDCleftcutmax = 875;
//              double goodTDCrightcutmin = 650;
//              double goodTDCrightcutmax = 880;
/*      
		double goodTDCleftcutmin = 1;
		double goodTDCleftcutmax = 1600;
		double goodTDCrightcutmin = 1;
		double goodTDCrightcutmax = 1600;
*/
		double vetoTDCcutmin = 745;
		double vetoTDCcutmax = 780;
		const int nuBins = 10;
		double nuMin = 0.35;
		double nuMax = 0.65;
	}
// ^^^^^^^^^^^^^^^^^^^^^^ Define Kinematics Settings ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


	double xmin = 0.6;
	double xmax = 3.0;

	int bins = 50;

	TString outputPlotsHere = "./";

	TString outputRootString = outputPlotsHere;
	outputRootString += "hand_target_asym_vs_nu_for_run_";
	outputRootString += HeRunNumber;
	outputRootString += ".root";
	TFile *outputRoot = new TFile(outputRootString,"RECREATE");
//      TFile outputRoot(outputRootString,"RECREATE");

	outputRoot->Close();

	TString asymOutFileName = outputPlotsHere;
	asymOutFileName += "target_asymmetry_for_run_";
	asymOutFileName += HeRunNumber;
	asymOutFileName += ".txt";
	ofstream asymOutFile;
	asymOutFile.open(asymOutFileName);


	if (fChain == 0) return;

	fChain->SetBranchStatus("*",1);

	Int_t nentries = fChain->GetEntries();

// vvvvvvvvvvvvvvvvvvvvvvvvvvvvv Define Basic Cut Settings vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// The chunk below defines the histograms, titles, and variable definitions that will be 
// made for the Basic Cuts
	TString titledp = "dp Cut, Run ";
	titledp += HeRunNumber;
	TString titleTarget = "Target Cut";
	TString titleThetaPhiCut = "Theta and Phi";
	TString titlePsSh = "Preshower and Shower";
	TString titleQ2Nu = "Q2 and Nu";
	TString titlecerenkov = "Cerenkov Cut";
	TString titlePsShCut = "Preshower and Shower with all cuts";
	TString titlex = "Bjorken x ";
	TH1F *HedpNoCut = new TH1F("HedpNoCut",titledp,400,-0.08,0.08);
	TH1F *HedpCut = new TH1F("HedpCut",titledp,400,-0.08,0.08);
	TH1F *HeReactZNoCut = new TH1F("HeReactZNoCut",titleTarget,400,-0.3,0.3);
	TH1F *HeReactZCut = new TH1F("HeReactZCut",titleTarget,400,-0.3,0.3);
	TH2F *HeThetaPhiCut = new TH2F("HeThetaPhiCut",titleThetaPhiCut,100,-0.05,0.05,100,-0.1,0.1);
	TH2F *HePsShNoCut = new TH2F("HePsShNoCut",titlePsSh,200,1,2500,200,1,1500);
	TH2F *histQ2Nu = new TH2F("histQ2Nu",titleQ2Nu,200,numin,numax,200,q2min,q2max);
	TH1F *histcerenkov = new TH1F("histcerenkov",titlecerenkov,200,-25,2000);
	TH1F *histcerenkovcut = new TH1F("histcerenkovcut",titlecerenkov,200,-25,2000);
	TH2F *HePsShCut = new TH2F("HePsShCut",titlePsShCut,200,1,2500,200,1,1500);
	TH1F *histx = new TH1F("histx",titlex,bins,xmin,xmax);
	TH1F *histxcut = new TH1F("histxcut",titlex,bins,xmin,xmax);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Define Basic Cut Settings ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



// vvvvvvvvvvvvvvvvvvvvvvvvvvvvv Define Bar-by-Bar Cut Settings vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// The chunk below defines the histograms, titles, and variable definitions that will be used
// for the Bar-by-Bar cuts
	cout << "Defining Bar-by-Bar Histograms..." << endl;
	int maxbars;
	TString plotHANDleft; TString plotHANDleftcut;
	TString titleHANDleft; TString titleHANDleftcut;
	TH1F *HANDleft[5][32]; TH1F *HANDleftcut[5][32];

	TString plotHANDright; TString plotHANDrightcut;
	TString titleHANDright; TString titleHANDrightcut;
	TH1F *HANDright[5][32]; TH1F *HANDrightcut[5][32];

	TString titleThetaCut;
	TString plotThetaCut;
	TH1F *HeThetaCut[5][32];

	TString titlePhiCut;
	TString plotPhiCut;
	TH1F *HePhiCut[5][32];

	TString titleThetaPhiCut;
	TString plotThetaPhiCut;
	TH2F *HeThetaPhiBarCut[5][32];

	int thisBarNum = 0;

	for (int fillplane=1; fillplane<5; fillplane++)
	{
		if (fillplane==0) maxbars=32;
		if (fillplane==1) maxbars=30;
		if (fillplane==2) maxbars=24;
		if (fillplane==3) maxbars=22;
		if (fillplane==4) maxbars=12;
		for (int fillbar=0; fillbar<maxbars; fillbar++)
		{
			// The bit below is for the Left TDC
			plotHANDleft = "HANDleft_p"; plotHANDleft += fillplane; plotHANDleft += "_b"; plotHANDleft += fillbar;
			 plotHANDleftcut = plotHANDleft; plotHANDleftcut += "_cut";
			titleHANDleft = "Left TDC for Plane #"; titleHANDleft += fillplane; titleHANDleft += ", PMT # "; titleHANDleft += fillbar;
			titleHANDleftcut = titleHANDleft; titleHANDleftcut += " cut";
//			cout << "plotHANDleft: " << plotHANDleft << endl;
			HANDleft[fillplane][fillbar] = new TH1F(plotHANDleft,titleHANDleft,TDCbins,TDCmin,TDCmax);
			HANDleftcut[fillplane][fillbar] = new TH1F(plotHANDleftcut,titleHANDleftcut,TDCbins,TDCmin,TDCmax);

			// The bit below is for the Right TDC		
			plotHANDright = "HANDright_p"; plotHANDright += fillplane; plotHANDright += "_b"; plotHANDright += fillbar;
			plotHANDrightcut = plotHANDright; plotHANDrightcut += "_cut";
			titleHANDright = "Right TDC for Plane #"; titleHANDright += fillplane; titleHANDright += ", PMT # "; titleHANDright += fillbar;
			titleHANDrightcut = titleHANDright; titleHANDrightcut += " cut";
//			cout << "plotHANDright: " << plotHANDright << endl;
			HANDright[fillplane][fillbar] = new TH1F(plotHANDright,titleHANDright,TDCbins,TDCmin,TDCmax);
			HANDrightcut[fillplane][fillbar] = new TH1F(plotHANDrightcut,titleHANDrightcut,TDCbins,TDCmin,TDCmax);

			// The bit below is for the bar-by-bar Theta cuts
			titleThetaCut = "Theta for plane "; titleThetaCut += fillplane; titleThetaCut += ", bar "; titleThetaCut += fillbar;
			plotThetaCut = "th_p"; plotThetaCut += fillplane; plotThetaCut += "_b"; plotThetaCut += fillbar;
//			cout << "plotThetaCut: " << plotThetaCut << endl;
			HeThetaCut[fillplane][fillbar] = new TH1F(plotThetaCut,titleThetaCut,60,-0.06,0.06);

			// The bit below is for the bar-by-bar Phi cuts
			titlePhiCut = "Phi plane "; titlePhiCut += fillplane; titlePhiCut += ", bar "; titlePhiCut += fillbar;
			plotPhiCut = "ph_p"; plotPhiCut += fillplane; plotPhiCut += "_b"; plotPhiCut += fillbar;
//			cout << "plotPhiCut: " << plotPhiCut << endl;
			HePhiCut[fillplane][fillbar] = new TH1F(plotPhiCut,titlePhiCut,60,-0.027,0.027);

			// The bit below is for the bar-by-bar Th:Ph cuts
			titleThetaPhiCut = "Theta & Phi for Plane "; titleThetaPhiCut += fillplane; titleThetaPhiCut += ", Bar "; titleThetaPhiCut += fillbar;
			plotThetaPhiCut = "thph_p"; plotThetaPhiCut += fillplane; plotThetaPhiCut += "_b"; plotThetaPhiCut += fillbar;
//			cout << "titleThetaPhiCut: " << titleThetaPhiCut << endl;
//			cout << "plotThetaPhiCut: " << plotThetaPhiCut << endl;
//			HeThetaPhiCut[fillplane][fillbar] = new TH2F(plotThetaPhiCut,titleThetaPhiCut,60,-0.027,0.027,60,-0.06,0.06);
			HeThetaPhiBarCut[fillplane][fillbar] = new TH2F(plotThetaPhiCut, titleThetaPhiCut, 60, -0.027, 0.027, 60, -0.06, 0.06);
//			HeThetaPhiCut[thisBarNum] = new TH2F(plotThetaPhiCut,titleThetaPhiCut,60,-0.027,0.027,60,-0.06,0.06);
//			cout << "Made it through the loop..." << endl;
			thisBarNum++;
		}
	}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Define Bar-by-Bar Cut Settings ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv Define ToF & Nu  Settings vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
	int tofBins = 100;
//	int tofMin = 0;
//	int tofMax = 1600;
	int tofMin = 200;
	int tofMax = 1300;
//	int tofCutMin = 500;
//	int tofCutMax = 800;
	int tofCutMin = 660;
	int tofCutMax = 690;
	TString titleToFbasic = "ToFbasic";
	TString plotToFbasic = "ToFbasic";
	TH1F *ToFbasic = new TH1F(plotToFbasic,titleToFbasic,tofBins,tofMin,tofMax);
	TString titleToFgoodEvent = "ToFgoodEvent";
	TString plotToFgoodEvent = "ToFgoodEvent";
	TH1F *ToFgoodEvent = new TH1F(plotToFgoodEvent,titleToFgoodEvent,tofBins,tofMin,tofMax);
	TString titleToFcut = "ToFcut";
	TString plotToFcut = "ToFcut";
	TH1F *ToFcut = new TH1F(plotToFcut,titleToFcut,tofBins,tofMin,tofMax);

	TString titlenuAllCuts = "Target Spin Down vs. nu";
	if (includeVetos) {titlenuAllCuts += " with vetos";}
	else {titlenuAllCuts += " without vetos";}
	TString plotnuAllCuts = "nuAllCuts";
	TH1F *nuAllCuts = new TH1F(plotnuAllCuts,titlenuAllCuts,nuBins,nuMin,nuMax);
	TString titlenuUpAllCuts = "Target Spin Down vs. nu";
	if (includeVetos) {titlenuUpAllCuts += " with vetos";}
	else {titlenuUpAllCuts += " without vetos";}
	TString plotnuUpAllCuts = "nuUpAllCuts";
	TH1F *nuUpAllCuts = new TH1F(plotnuUpAllCuts,titlenuUpAllCuts,nuBins,nuMin,nuMax);
	TString titlenuDownAllCuts = "Target Spin Down vs. nu";
	if (includeVetos) {titlenuDownAllCuts += " with vetos";}
	else {titlenuDownAllCuts += " without vetos";}
	TString plotnuDownAllCuts = "nuDownAllCuts";
	TH1F *nuDownAllCuts = new TH1F(plotnuDownAllCuts,titlenuDownAllCuts,nuBins,nuMin,nuMax);
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Define ToF & Nu  Settings ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	cout << "Processing cuts event-by-event..." << endl;
	int goodEvents=0;
	int allEvents=0;
	bool isGoodForAllBasic = true;
	bool madePastLVetoCuts = true;
	bool madePastRVetoCuts = true;
	bool madePastVetoCuts = true;
	bool pastThetaCut = true;
	bool dpGood = true;
	bool targetGood = true;
	bool cerenkovGood = true;
	Int_t nbytes = 0, nb = 0;
	TString allVetos[5][32];


//      int whichplane = 0;
        int whichplane = 1;
        int endplane = 5;
//        if (SinglePlane) {whichplane = singleplane; endplane = singleplane+1;}
        int whichbar=0;
//      int whichbar=11;
	bool goodEvent;
	int nplane;
	int thisbar;
	for (Int_t jentry=0; jentry<nentries;jentry++) {
//	for (Int_t jentry=0; jentry<100000;jentry++) {
		if ((jentry%10000)==0) {cout << "Processing Event " << jentry << "..." << endl;}
//		cout << "Processing Event " << jentry << " with NA_n_plane[0]=" << NA_n_plane[0] << " & NA_n_pad[0]=" << NA_n_pad[0] << "..." << endl;
		Int_t ientry = LoadTree(jentry);
		goodEvent = true;
		allEvents = allEvents+1;
		madePastLVetoCuts = true;
		madePastRVetoCuts = true;
		madePastVetoCuts = true;
		isGoodForAllBasic = true;
		pastThetaCut = true;
		dpGood = true;
		targetGood = true;
		cerenkovGood = true;
		hand_class_basic_cuts(jentry, isGoodForAllBasic, HeRunNumber, Q2, dpGood, targetGood, cerenkovGood, HedpNoCut, HedpCut, HeReactZNoCut, HeReactZCut, HeThetaPhiCut, HePsShNoCut, histQ2Nu, histcerenkov, histcerenkovcut, HePsShCut, histx, histxcut, ToFbasic);
		if (isGoodForAllBasic)
		{
//		cout << "isGoodForAllBasic is good!" << endl;
//			q2Cut->Fill(PriKineR_Q2);
			nplane = ((int) NA_n_plane[0]) + 1;
			thisbar = (int) NA_n_pad[0];
			if ((nplane>-1 && nplane<5) && (thisbar>-1 && thisbar<34))
			{
//			cout << "Plane/Pad are good!" << endl;
	/*		int nplane = whichplane;
			int thisbar = whichbar;
			while ((nplane<endplane) && goodEvent)
			{
				if (nplane==0) maxbars=32;
				if (nplane==1) maxbars=30;
				if (nplane==2) maxbars=24;
				if (nplane==3) maxbars=22;
				if (nplane==4) maxbars=12;
//				if (SingleBar) {whichbar = singlebar; maxbars = singlebar + 1;}
				thisbar = whichbar;
//				while ((thisbar<maxbars) && goodEvent)
				while ((thisbar<maxbars))
				{

//					madePastLVetoCuts = true;
//					madePastRVetoCuts = true;
//					madePastVetoCuts = true;
					pastThetaCut = true;
	*/				hand_class_bar_th_cuts(Q2, nplane, thisbar, pastThetaCut);
					goodEvent = (goodEvent && pastThetaCut);
//					if (includeVetos && goodEvent) {hand_class_veto_cuts(nplane, thisbar, madePastLVetoCuts, madePastRVetoCuts, madePastVetoCuts, vetoTDCcutmin, vetoTDCcutmax, jentry, allVetos[nplane][thisbar]);}
					if (includeVetos) {hand_class_veto_cuts(nplane, thisbar, madePastLVetoCuts, madePastRVetoCuts, madePastVetoCuts, vetoTDCcutmin, vetoTDCcutmax, jentry, allVetos[nplane][thisbar]);}
//					cout << "allVetos[" << nplane << "][" << thisbar << "]: " << allVetos[nplane][thisbar] << endl;
					goodEvent = (goodEvent && madePastVetoCuts);
//					cout << "Going into fill_bar_by_bar with thisbar=" << thisbar << ", nplane=" << nplane << endl;
					hand_class_fill_bar_by_bar_cuts(HeRunNumber, nplane, thisbar, pastThetaCut, madePastLVetoCuts, madePastRVetoCuts, madePastVetoCuts, HANDleft[nplane][thisbar], HANDleftcut[nplane][thisbar], HANDright[nplane][thisbar], HANDrightcut[nplane][thisbar], HeThetaCut[nplane][thisbar], HePhiCut[nplane][thisbar], HeThetaPhiBarCut[nplane][thisbar], goodTDCleftcutmin, goodTDCleftcutmax, goodTDCrightcutmin, goodTDCrightcutmax);

//					cout << "jentry: " << jentry << ", goodEvent: " << goodEvent << endl;
	/*				thisbar++;
				}
				nplane++;
			}
	*/		}
			if (goodEvent && madePastVetoCuts)
			{
				goodEvents = goodEvents+1;
//				cout << "Going into hand_class_fill_good_events..." << endl;
				hand_class_fill_good_events(ToFgoodEvent, ToFcut, nuAllCuts, nuUpAllCuts, nuDownAllCuts, tofCutMin, tofCutMax);
			}
	
		}
		if (ientry < 0) break;
		nb = fChain->GetEntry(jentry);   nbytes += nb;
		// if (Cut(ientry) < 0) continue;
	}
	
	cout << "allEvents: " << allEvents << endl;
	cout << "goodEvents: " << goodEvents << endl;

	hand_class_draw_basic(HedpNoCut, HedpCut, HeReactZNoCut, HeReactZCut, HeThetaPhiCut, HePsShNoCut, histQ2Nu, histcerenkov, histcerenkovcut, HePsShCut, histx, histxcut, outputRootString, HeRunNumber);

	for (int i=whichplane; i<endplane; i++)
	{
		if (i==0) maxbars=32;
		if (i==1) maxbars=30;
		if (i==2) maxbars=24;
		if (i==3) maxbars=22;
		if (i==4) maxbars=12;
		for (int j=whichbar; j<maxbars; j++)
		{
//			cout << "allVetos[" << i << "][" << j << "]: " << allVetos[i][j] << endl;
			hand_class_draw_bar_by_bar_cuts(HeRunNumber, i, j, HANDleft[i][j], HANDleftcut[i][j], HANDright[i][j], HANDrightcut[i][j], HeThetaCut[i][j], HePhiCut[i][j], HeThetaPhiBarCut[i][j], allVetos[i][j], outputRootString);
		}
	}

	hand_class_draw_tof_nu(ToFbasic, ToFgoodEvent, ToFcut, nuAllCuts, nuUpAllCuts, nuDownAllCuts, outputRootString, HeRunNumber);




	TFile *outputRoot1 = new TFile(outputRootString,"UPDATE");

	asymOutFile.close();
	outputRoot1->Close();

	seconds = time (NULL);
	int endTime = seconds;
	int totalTimeInSeconds = endTime - beginTime;
	int days = floor(totalTimeInSeconds/(60*60*24));
	int hours = floor((totalTimeInSeconds - days*60*60*24)/(60*60));
	int minutes = floor((totalTimeInSeconds - days*60*60*24 - hours*60*60)/60);
	double secondsend = (totalTimeInSeconds - days*60*60*24 - hours*60*60 - minutes*60);


	cout << "This program has run for " << totalTimeInSeconds << " seconds (" << days << " Days, " << hours << " Hours, " << minutes << " Minutes, and " << secondsend << " Seconds)" <<  endl;
	cout << endl << "All done!" << endl << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^ neutron_analysis_class.C ^^^^^^^^^^^^^^^^^^^^^^" << endl;
}
