#define neutron_analysis_class_cxx
//#include "./THaEvent.h"
#include <THaEvent.h>
#include "neutron_analysis_class.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <time.h>
#include <math.h>
#include "hand_class_basic_cuts.h"
#include "hand_class_veto_cuts2.h"
#include "hand_class_veto_cuts.h"
#include "hand_class_bar_th_cuts.h"
#include "hand_class_draw_basic.h"
#include "hand_class_fill_bar_by_bar_cuts.h"
#include "hand_class_draw_bar_by_bar_cuts.h"
#include "hand_class_fill_good_events.h"
#include "hand_class_draw_tof_nu.h"

void neutron_analysis_class::AsymLoop(int dataType)
{
	cout << "vvvvvvvvvvvvvvvvvvvvv neutron_analysis_class.C vvvvvvvvvvvvvvvvvvvvvv" << endl;

//	If includeVetos = false, then only good bars will be displayed. If 
//	includeVetos = true, then veto bars will be shown along with the good bars.

	bool includeVetos;
	bool findProtons;
	TString eventType;

	if (dataType==1) {includeVetos = false; findProtons = false; eventType = "No Vetos - ";}
	if (dataType==2) {includeVetos = true; findProtons = false; eventType = "Neutrons - ";}
	if (dataType==3) {includeVetos = true; findProtons = true; eventType = "Protons - ";}


	bool drawCuts = true;
//	bool drawCuts = false;

//	bool test = true;
	bool test = false;

	TString otherSpecs;
	if (!includeVetos) {otherSpecs = "Data, with NO veto cuts (protons + neutrons + other stuff) -- NO TDC CUT -- NO inGoodBar CUT";}
	if (includeVetos && !findProtons) {otherSpecs = "Data, with Neutron Vetoes -- NO TDC CUT -- NO inGoodBar CUT";}
	if (includeVetos && findProtons) {otherSpecs = "Data, with Proton Tracks -- NO TDC CUT -- NO inGoodBar CUT";}
	if (findProtons) {otherSpecs += "\nLooking for Protons...";}
	if (test) { otherSpecs += "\n !!!!!!!!!!!!!!THIS RUN IS IN TEST MODE!!!!!!!!!!!!!!!!!!!!";}
	otherSpecs += "\nOther: Nothing Special...";
	time_t seconds;
	seconds = time (NULL);
	int beginTime = seconds;
	string line = "";
	ifstream runNumberInputFile ("./input.file");
	getline(runNumberInputFile, line);
	int inRunNumber = atoi(line.c_str());
	int HeRunNumber = inRunNumber;
	if (inRunNumber<20533 || (inRunNumber>20570 && inRunNumber<21050)) {TString asymType = "ssa";}
	else {TString asymType = "dsa";}
	otherSpecs += "\nAsym Type: ";
	otherSpecs += asymType;
	cout << otherSpecs << endl;       
	cout << "HeRunNumber: " << HeRunNumber << endl;

	gROOT->SetStyle("Plain");
	cout << "Adding files to chain..." << endl;
	TChain *chainHe = new TChain("T");
	TString filenameHe;
	for (int t=0; t<1000; t++)
	{
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

// **************** Unknown, Q2=??? *******************
	cout << "Starting with default, Unknown Q2 dataset..." << endl;
	dataset = "Uknown, Q2=???";
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
	double nuMin = numin;
	double nuMax = numax;


// **************** Vertical, Q2=1.0 *******************
	if ((inRunNumber > 20578) && (inRunNumber < 20879))
	{
		cout << "Processing Vertically polarized, Q2=1.0 dataset..." << endl;
		dataset = "Vertical, Q2=1.0";
//		int HeRunNumber = 20596;
		int HeRunNumber = inRunNumber;
//		int endHeRunNumber = 20683;
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
		const int nuBins = 100;
		double nuMin = numin;
		double nuMax = numax;


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
		const int nuBins = 100;
		double nuMin = numin;
		double nuMax = numax;


	}
/*
// ********* Vertical, Q2=0.42 *******************
	if (((inRunNumber > 21193) && (inRunNumber < 21513)) && !(inRunNumber>21382 && inRunNumber<21388))
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
//		int TDCbins = 50;
//		double TDCmin = 700;
//		double TDCmax = 800;
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
		double nuMin = numin; 
		double nuMax = numax;


	}
*/

// **************************** Vertical, Q2=0.1 *******************
//      if ((inRunNumber > 20486) && (inRunNumber < 20541))
	if ((inRunNumber > 20400) && (inRunNumber < 20512))
	{
		cout << "Processing Vertically polarized, Q2=0.1 dataset..." << endl;
		dataset = "Vertical, Q2=0.1";
		int HeRunNumber = inRunNumber;
		int endHeRunNumber = inRunNumber;
		TString Q2 = "0.1";
		double q2min = 0.08;
		double q2max = 0.18;
		double numin = 0.01;
		double numax = 0.13;
		int Positionbins = 30;
		double Positionmin = -30;
		double Positionmax = 30;
//		int TDCbins = 40;
//		double TDCmin = 1325;
//		double TDCmax = 1525;
		int TDCbins = 100;
		double TDCmin = 0;
		double TDCmax = 3000;
/*		if (includeVetos)
		{
			TDCbins = 40;
			TDCmin = 1325;
			TDCmax = 1525;
		}
*/
		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;
/*		double goodTDCleftcutmin = 1390;
		double goodTDCleftcutmax = 1440;
		double goodTDCrightcutmin = 1390;
		double goodTDCrightcutmax = 1440;
		double vetoTDCcutmin = 1390;
		double vetoTDCcutmax = 1440;
*/
/*	
		double goodTDCleftcutmin = 10;
		double goodTDCleftcutmax = 3100;
		double goodTDCrightcutmin = 10;
		double goodTDCrightcutmax = 3100;
		double vetoTDCcutmin = 0;
		double vetoTDCcutmax = 3100;
*/	
		double goodTDCleftcutmin = 1000;
		double goodTDCleftcutmax = 1600;
		double goodTDCrightcutmin = 1000;
		double goodTDCrightcutmax = 1600;
		double vetoTDCcutmin = 1000;
		double vetoTDCcutmax = 1600;

		const int nuBins = 100;
		double nuMin = numin;
		double nuMax = numax;

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
	      
//		double goodTDCleftcutmin = 1;
//		double goodTDCleftcutmax = 1600;
//		double goodTDCrightcutmin = 1;
//		double goodTDCrightcutmax = 1600;
	

		double vetoTDCcutmin = 745;
		double vetoTDCcutmax = 780;
		const int nuBins = 10;
		double nuMin = numin;
		double nuMax = numax;
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
      
//		double goodTDCleftcutmin = 1;
//		double goodTDCleftcutmax = 1600;
//		double goodTDCrightcutmin = 1;
//		double goodTDCrightcutmax = 1600;

		double vetoTDCcutmin = 745;
		double vetoTDCcutmax = 780;
		const int nuBins = 10;
		double nuMin = numin;
		double nuMax = numax;
	}
// **************************** Hydrogen, Q2=0.5 *******************
	if ((inRunNumber > 21382) && (inRunNumber < 21388))
	{
		cout << "Processing Hydrogen, Q2=0.5 dataset..." << endl;
		dataset = "Hydrogen, Q2=0.5";
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
		double TDCmin = 600;
		double TDCmax = 900;
		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;
		double goodTDCleftcutmin = 720;
		double goodTDCleftcutmax = 780;
		double goodTDCrightcutmin = 720;
		double goodTDCrightcutmax = 780;
		double vetoTDCcutmin = 720;
		double vetoTDCcutmax = 780;
		const int nuBins = 10;
		double nuMin = numin;
		double nuMax = numax;


	}

// **************************** Longitudinal, Q2=0.4 *******************
	if ((inRunNumber > 21812) && (inRunNumber < 22138))
	{
		cout << "Processing Longitudinal polarized, Q2=0.4 dataset..." << endl;
		dataset = "Longitudinal, Q2=0.4";
		int HeRunNumber = inRunNumber;
		int endHeRunNumber = inRunNumber;
		TString Q2 = "0.4";
		double q2min = 0.4;
		double q2max = 0.65;
		double numin = 0.1;
		double numax = 0.4;
		int Positionbins = 30;
		double Positionmin = -30;
		double Positionmax = 30;
		int TDCbins = 100;
		double TDCmin = 1;
		double TDCmax = 1500;
		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;
		double goodTDCleftcutmin = 745;
		double goodTDCleftcutmax = 780;
		double goodTDCrightcutmin = 745;
		double goodTDCrightcutmax = 780;
		double vetoTDCcutmin = 745;
		double vetoTDCcutmax =780;
		const int nuBins = 10;
		double nuMin = numin;
		double nuMax = numax;


	}

// **************************** Transverse, Q2=0.4 *******************
	if (((inRunNumber > 21692) && (inRunNumber < 21801)) || ((inRunNumber > 22138) && (inRunNumber < 22312)))
	{
		cout << "Processing Transverse polarized, Q2=0.4 dataset..." << endl;
		dataset = "Transverse, Q2=0.4";
		int HeRunNumber = inRunNumber;
		int endHeRunNumber = inRunNumber;
		TString Q2 = "0.4";
		double q2min = 0.4;
		double q2max = 0.65;
		double numin = 0.1;
		double numax = 0.4;
		int Positionbins = 30;
		double Positionmin = -30;
		double Positionmax = 30;
		int TDCbins = 100;
		double TDCmin = 1;
		double TDCmax = 1500;
		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;
		double goodTDCleftcutmin = 745;
		double goodTDCleftcutmax = 780;
		double goodTDCrightcutmin = 745;
		double goodTDCrightcutmax = 780;
		double vetoTDCcutmin = 745;
		double vetoTDCcutmax = 780;
		const int nuBins = 10;
		double nuMin = numin;
		double nuMax = numax;


	}



// ^^^^^^^^^^^^^^^^^^^^^^ Define Kinematics Settings ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


	double xmin = 0.0;
	double xmax = 4.0;
	int bins = 50;

	TString outputPlotsHere = "./";
	if (dataType==1){ outputPlotsHere += "no_vetos-";}
	if (dataType==2){ outputPlotsHere += "neutron_cuts-";}
	if (dataType==3){ outputPlotsHere += "proton_cuts-";}


	TString outputRootString = outputPlotsHere;
	if (asymType=="ssa") {outputRootString += "hand_target";}
//	if (asymType=="dsa") {outputRootString += "hand_beam";}
	if (asymType=="dsa") {outputRootString += "hand_target";}
	outputRootString += "_asym_vs_nu_for_run_";
	outputRootString += HeRunNumber;
	outputRootString += ".root";
	TFile *outputRoot = new TFile(outputRootString,"RECREATE");

	outputRoot->Close();

	TString asymOutFileName = outputPlotsHere;
	if (asymType=="ssa") {asymOutFileName += "target";}
//	if (asymType=="dsa") {asymOutFileName += "beam";}
	if (asymType=="dsa") {asymOutFileName += "target";}
	asymOutFileName += "_asymmetry_for_run_";
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
			HANDleft[fillplane][fillbar] = new TH1F(plotHANDleft,titleHANDleft,TDCbins,TDCmin,TDCmax);
			HANDleftcut[fillplane][fillbar] = new TH1F(plotHANDleftcut,titleHANDleftcut,TDCbins,TDCmin,TDCmax);

			// The bit below is for the Right TDC		
			plotHANDright = "HANDright_p"; plotHANDright += fillplane; plotHANDright += "_b"; plotHANDright += fillbar;
			plotHANDrightcut = plotHANDright; plotHANDrightcut += "_cut";
			titleHANDright = "Right TDC for Plane #"; titleHANDright += fillplane; titleHANDright += ", PMT # "; titleHANDright += fillbar;
			titleHANDrightcut = titleHANDright; titleHANDrightcut += " cut";
			HANDright[fillplane][fillbar] = new TH1F(plotHANDright,titleHANDright,TDCbins,TDCmin,TDCmax);
			HANDrightcut[fillplane][fillbar] = new TH1F(plotHANDrightcut,titleHANDrightcut,TDCbins,TDCmin,TDCmax);

			// The bit below is for the bar-by-bar Theta cuts
			titleThetaCut = "Theta for plane "; titleThetaCut += fillplane; titleThetaCut += ", bar "; titleThetaCut += fillbar;
			plotThetaCut = "th_p"; plotThetaCut += fillplane; plotThetaCut += "_b"; plotThetaCut += fillbar;
			HeThetaCut[fillplane][fillbar] = new TH1F(plotThetaCut,titleThetaCut,60,-0.06,0.06);

			// The bit below is for the bar-by-bar Phi cuts
			titlePhiCut = "Phi plane "; titlePhiCut += fillplane; titlePhiCut += ", bar "; titlePhiCut += fillbar;
			plotPhiCut = "ph_p"; plotPhiCut += fillplane; plotPhiCut += "_b"; plotPhiCut += fillbar;
			HePhiCut[fillplane][fillbar] = new TH1F(plotPhiCut,titlePhiCut,60,-0.027,0.027);

			// The bit below is for the bar-by-bar Th:Ph cuts
			titleThetaPhiCut = "Theta & Phi for Plane "; titleThetaPhiCut += fillplane; titleThetaPhiCut += ", Bar "; titleThetaPhiCut += fillbar;
			plotThetaPhiCut = "thph_p"; plotThetaPhiCut += fillplane; plotThetaPhiCut += "_b"; plotThetaPhiCut += fillbar;
			HeThetaPhiBarCut[fillplane][fillbar] = new TH2F(plotThetaPhiCut, titleThetaPhiCut, 60, -0.027, 0.027, 60, -0.06, 0.06);
			thisBarNum++;
		}
	}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Define Bar-by-Bar Cut Settings ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



// vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv Define ToF & Nu  Settings vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
	int tofBins = 200;
//	int tofMin = 0;
//	int tofMax = 1600;
	int tofMin = 200;
	int tofMax = 1300;
	if (Q2=="0.4") {tofMax = 800;} 
//	int tofCutMin = 500;
//	int tofCutMax = 800;
	int tofCutMin = 625;
	int tofCutMax = 690;
	TString titleToFbasic = "ToFbasic";
	TString plotToFbasic = "ToFbasic";
	TH1F *ToFbasic = new TH1F(plotToFbasic,titleToFbasic,tofBins,tofMin,tofMax);

	TH1F* ToFgoodEvent[11];
	TH1F* ToFcut[11];
	TH1F* ToFup[11];
	TH1F* ToFdown[11];
	TH1F* nuAllCuts[11];
	TH1F* nuUpAllCuts[11];
	TH1F* nuDownAllCuts[11];
	TString titleToFgoodEvent;
	TString plotToFgoodEvent;
	TString titleToFcut;
	TString plotToFcut;
	TString titleToFup;
	TString plotToFup;
	TString titleToFdown;
	TString plotToFdown;
	TString titlenuAllCuts;
	TString titlenuUpAllCuts;
	TString titlenuDownAllCuts;
	TString plotnuAllCuts;
	TString plotnuUpAllCuts;
	TString plotnuDownAllCuts;

	TH1F* TDC1up[11];
	TH1F* TDC1dn[11];
	TH1F* TDC2up[11];
	TH1F* TDC2dn[11];
	TH1F* TDC3up[11];
	TH1F* TDC3dn[11];
	TH1F* TDC4up[11];
	TH1F* TDC4dn[11];
	TString titleTDC1up;
	TString titleTDC1dn;
	TString plotTDC1up;
	TString plotTDC1dn;
	TString titleTDC2up;
	TString titleTDC2dn;
	TString plotTDC2up;
	TString plotTDC2dn;
	TString titleTDC3up;
	TString titleTDC3dn;
	TString plotTDC3up;
	TString plotTDC3dn;
	TString titleTDC4up;
	TString titleTDC4dn;
	TString plotTDC4up;
	TString plotTDC4dn;
	int tdcBins = 300;
	double tdcMin = 0;
	double tdcMax = 3000;

	for (int i=0; i<11; i++)
	{
		titleToFgoodEvent = "ToFgoodEvent for nu bin ";
		titleToFgoodEvent += i;
		plotToFgoodEvent = "ToFgoodEvent_bin_";
		plotToFgoodEvent += i;
		titleToFcut = "ToFcut for nu bin ";
		titleToFcut += i;
		plotToFcut = "ToFcut_bin_";
		plotToFcut += i;
		titleToFup = "ToFup for nu bin ";
		titleToFup += i;
		plotToFup = "ToFup_bin_";
		plotToFup += i;
		titleToFdown = "ToFdown for nu bin ";
		titleToFdown += i;
		plotToFdown = "ToFdown_bin_";
		plotToFdown += i;
		titlenuAllCuts = "Nu for nu bin ";
		titlenuAllCuts += i;
		titlenuUpAllCuts = titlenuAllCuts;
		titlenuUpAllCuts = ", Spin Up";
		titlenuDownAllCuts = titlenuAllCuts;
		titlenuDownAllCuts = ", Spin Down";
		plotnuAllCuts = "nuAllCuts_bin_";
		plotnuAllCuts += i;
		plotnuUpAllCuts = "nuUpAllCuts_bin_";
		plotnuUpAllCuts += i;
		plotnuDownAllCuts = "nuDownAllCuts_bin_";
		plotnuDownAllCuts += i;
		titleTDC1up = "TDC Plane 1, Spin Up, for Nu Bin ";
		titleTDC1up += i;
		plotTDC1up += "TDC1up_bin_";
		plotTDC1up += i;
		titleTDC1dn = "TDC Plane 1, Spin Down, for Nu Bin ";
		titleTDC1dn += i;
		plotTDC1dn += "TDC1dn_bin_";
		plotTDC1dn += i;
		titleTDC2up = "TDC Plane 2, Spin Up, for Nu Bin ";
		titleTDC2up += i;
		plotTDC2up += "TDC2up_bin_";
		plotTDC2up += i;
		titleTDC2dn = "TDC Plane 2, Spin Down, for Nu Bin ";
		titleTDC2dn += i;
		plotTDC2dn += "TDC2dn_bin_";
		plotTDC2dn += i;
		titleTDC3up = "TDC Plane 3, Spin Up, for Nu Bin ";
		titleTDC3up += i;
		plotTDC3up += "TDC3up_bin_";
		plotTDC3up += i;
		titleTDC3dn = "TDC Plane 3, Spin Down, for Nu Bin ";
		titleTDC3dn += i;
		plotTDC3dn += "TDC3dn_bin_";
		plotTDC3dn += i;
		titleTDC4up = "TDC Plane 4, Spin Up, for Nu Bin ";
		titleTDC4up += i;
		plotTDC4up += "TDC4up_bin_";
		plotTDC4up += i;
		titleTDC4dn = "TDC Plane 4, Spin Down, for Nu Bin ";
		titleTDC4dn += i;
		plotTDC4dn += "TDC4dn_bin_";
		plotTDC4dn += i;
		if (i==0)
		{
			titleToFgoodEvent = "ToFgoodEvent Total";
			plotToFgoodEvent = "ToFgoodEvent_Total";
			titleToFcut = "ToFcut Total";
			plotToFcut = "ToFcut_Total";
			titleToFup = "ToFup Total";
			plotToFup = "ToFup_Total";
			titleToFdown = "ToFdown Total";
			plotToFdown = "ToFdown_Total";
			titlenuAllCuts = "Nu Total";
			titlenuUpAllCuts = "Nu Up Total";
			titlenuDownAllCuts = "Nu Down Total";
			plotnuAllCuts = "nuAllCuts_Total";
			plotnuUpAllCuts = "nuUpAllCuts_Total";
			plotnuDownAllCuts = "nuDownAllCuts_Total";
			titleTDC1up = "TDC Plane 1, Spin Up, Total";
			plotTDC1up += "TDC1up_Total";
			titleTDC1dn = "TDC Plane 1, Spin Down, Total";
			plotTDC1dn += "TDC1dn_Total";
			titleTDC2up = "TDC Plane 2, Spin Up, Total";
			plotTDC2up += "TDC2up_Total";
			titleTDC2dn = "TDC Plane 2, Spin Down, Total";
			plotTDC2dn += "TDC2dn_Total";
			titleTDC3up = "TDC Plane 3, Spin Up, Total";
			plotTDC3up += "TDC3up_Total";
			titleTDC3dn = "TDC Plane 3, Spin Down, Total";
			plotTDC3dn += "TDC3dn_Total";
			titleTDC4up = "TDC Plane 4, Spin Up, Total";
			plotTDC4up += "TDC4up_Total";
			titleTDC4dn = "TDC Plane 4, Spin Down, Total";
			plotTDC4dn += "TDC4dn_Total";
		}
		ToFgoodEvent[i] = new TH1F(plotToFgoodEvent,titleToFgoodEvent,tofBins,tofMin,tofMax);
		ToFcut[i] = new TH1F(plotToFcut,titleToFcut,tofBins,tofMin,tofMax);
		ToFup[i] = new TH1F(plotToFup,titleToFup,tofBins,tofMin,tofMax);
		ToFdown[i] = new TH1F(plotToFdown,titleToFdown,tofBins,tofMin,tofMax);
		if (includeVetos) {titlenuAllCuts += " with vetos";}
		if (includeVetos) {titlenuUpAllCuts += " with vetos";}
		if (includeVetos) {titlenuDownAllCuts += " with vetos";}
		else {titlenuAllCuts += " without vetos";}
		else {titlenuUpAllCuts += " without vetos";}
		else {titlenuDownAllCuts += " without vetos";}
		nuAllCuts[i] = new TH1F(plotnuAllCuts,titlenuAllCuts,nuBins,nuMin,nuMax);
		nuUpAllCuts[i] = new TH1F(plotnuUpAllCuts,titlenuUpAllCuts,nuBins,nuMin,nuMax);
		nuDownAllCuts[i] = new TH1F(plotnuDownAllCuts,titlenuDownAllCuts,nuBins,nuMin,nuMax);
		TDC1up[i] = new TH1F(plotTDC1up,titleDC1up,tdcBins,tdcMin,tdcMax);
		TDC1dn[i] = new TH1F(plotTDC1dn,titleDC1dn,tdcBins,tdcMin,tdcMax);
		TDC2up[i] = new TH2F(plotTDC2up,titleDC2up,tdcBins,tdcMin,tdcMax);
		TDC2dn[i] = new TH2F(plotTDC2dn,titleDC2dn,tdcBins,tdcMin,tdcMax);
		TDC3up[i] = new TH3F(plotTDC3up,titleDC3up,tdcBins,tdcMin,tdcMax);
		TDC3dn[i] = new TH3F(plotTDC3dn,titleDC3dn,tdcBins,tdcMin,tdcMax);
		TDC4up[i] = new TH4F(plotTDC4up,titleDC4up,tdcBins,tdcMin,tdcMax);
		TDC4dn[i] = new TH4F(plotTDC4dn,titleDC4dn,tdcBins,tdcMin,tdcMax);
	}
	nuUp = new TH1F("nuUp","Nu - Spin Up (e,e')",nuBins,nuMin,nuMax);
	nuDown = new TH1F("nuDown","Nu - Spin Down (e,e')",nuBins,nuMin,nuMax);

// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Define ToF & Nu  Settings ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	cout << "Processing cuts event-by-event..." << endl;
	int goodEvents=0;
	int allEvents=0;
	bool isGoodForAllBasic = true;
	bool madePastLVetoCuts = true;
	bool madePastRVetoCuts = true;
	bool madePastVetoCuts = true;
	bool notEdge = true;
	bool pastThetaCut = true;
	bool dpGood = true;
	bool targetGood = true;
	bool cerenkovGood = true;
	Int_t nbytes = 0, nb = 0;
	TString allVetos[5][32];
//	int whichplane = 0;
	int whichplane = 1;
	int endplane = 5;
//	if (SinglePlane) {whichplane = singleplane; endplane = singleplane+1;}
	int whichbar=0;
//	int whichbar=11;
	bool goodEvent;
	int nplane;
	int thisbar;
	bool useIf = false;
	bool useIfElse = false;
	bool useSwitch = false;
	bool goodToFcut = true;
	bool spinUp = true;
	bool spinDown = true;
	bool nuBinCut = true;
	double nuBinCutMin=0;
	double nuBinCutMax=0;
	double nuBinSize=0;
	bool inGoodBar = true;
	double HeChargeScale;
	double Helivetime;
	int i;
	TString outFileName = "./charge_lt_for_run_";
	outFileName += HeRunNumber;
	outFileName += ".txt";
	ofstream outFile;
	outFile.open(outFileName, ios::app);
	ifstream inFile (outFileName);
	TString newOutputFolder = ".";
	TString legendName = newOutputFolder;
	legendName = "/charge_lt_legend.txt";
	ofstream legend;
	legend.open(legendName, ios::app);

// This section will put the 3He root data into doubles so that
// it can be calculated through C++ instead of as histograms
// ****************************************************************************************************************
	int HeNumberOfEvents;
	double HeIsSpinValid;
	double HeEvTypeBits;
	double HeRunNum;
	double HeSpin;
	double g0helicity;
	int HeRunNumberForArray;
	double He_edtm;
	double He_fclk;
	double He_u3c;
	double He_u3pp;
	double He_u3pm;
	double He_u3mm;
	double He_u3mp;
	double He_u1c;
	double He_u1pp;
	double He_u1pm;
	double He_u1mm;
	double He_u1mp;
	double He_u10c;
	double He_u10pp;
	double He_u10pm;
	double He_u10mm;
	double He_u10mp;
	double He_d3c;
	double He_d3pp;
	double He_d3pm;
	double He_d3mm;
	double He_d3mp;
	double He_d1c;
	double He_d1pp;
	double He_d1pm;
	double He_d1mm;
	double He_d1mp;
	double He_d10c;
	double He_d10pp;
	double He_d10pm;
	double He_d10mm;
	double He_d10mp;
	double He_t1c;
	double thisRunCharge;
	double thisRunTargetChargeUp;
	double thisRunTargetChargeDown;
	double thisRunBeamChargeUp;
	double thisRunBeamChargeDown;
	double thisRunError;
	double t1c0Tot=0;
	double t1cUpTot=0;
	double t1cDownTot=0;
	double t1c0Initial = 0;
	double t1cUpInitial = 0;
	double t1cDownInitial = 0;
	double t1c0Final = 0;
	double t1cUpFinal = 0;
	double t1cDownFinal = 0;
	double ugCharge0Tot=0;
	double ugChargeUpTot=0;
	double ugChargeDownTot=0;
	double ugCharge0Initial = 0;
	double ugChargeUpInitial = 0;
	double ugChargeDownInitial = 0;
	double ugCharge0Final = 0;
	double ugChargeUpFinal = 0;
	double ugChargeDownFinal = 0;
	double oldHeState;
	bool newHeState = false;
	bool firstTime = true;
	bool TDCsanity = true;
	HeNumberOfEvents = int(chainHe->GetEntries());
	chainHe->SetBranchAddress("he3R.IsSpinValid", &HeIsSpinValid);
	chainHe->SetBranchAddress("he3R.Spin", &HeSpin);
	chainHe->SetBranchAddress("g0hel.R.helicity", &g0helicity);
	chainHe->SetBranchAddress("D.evtypebits", &HeEvTypeBits);
	chainHe->SetBranchAddress("g.runnum", &HeRunNum);
	chainHe->SetBranchAddress("evright_u3c", &He_u3c);
	chainHe->SetBranchAddress("evright_u3pp", &He_u3pp);
	chainHe->SetBranchAddress("evright_u3pm", &He_u3pm);
	chainHe->SetBranchAddress("evright_u3mm", &He_u3mm);
	chainHe->SetBranchAddress("evright_u3mp", &He_u3mp);
	chainHe->SetBranchAddress("evright_u1c", &He_u1c);
	chainHe->SetBranchAddress("evright_u1pp", &He_u1pp);
	chainHe->SetBranchAddress("evright_u1pm", &He_u1pm);
	chainHe->SetBranchAddress("evright_u1mm", &He_u1mm);
	chainHe->SetBranchAddress("evright_u1mp", &He_u1mp);
	chainHe->SetBranchAddress("evright_u10c", &He_u10c);
	chainHe->SetBranchAddress("evright_u10pp", &He_u10pp);
	chainHe->SetBranchAddress("evright_u10pm", &He_u10pm);
	chainHe->SetBranchAddress("evright_u10mm", &He_u10mm);
	chainHe->SetBranchAddress("evright_u10mp", &He_u10mp);
	chainHe->SetBranchAddress("evright_d3c", &He_d3c);
	chainHe->SetBranchAddress("evright_d3pp", &He_d3pp);
	chainHe->SetBranchAddress("evright_d3pm", &He_d3pm);
	chainHe->SetBranchAddress("evright_d3mm", &He_d3mm);
	chainHe->SetBranchAddress("evright_d3mp", &He_d3mp);
	chainHe->SetBranchAddress("evright_d1c", &He_d1c);
	chainHe->SetBranchAddress("evright_d1pp", &He_d1pp);
	chainHe->SetBranchAddress("evright_d1pm", &He_d1pm);
	chainHe->SetBranchAddress("evright_d1mm", &He_d1mm);
	chainHe->SetBranchAddress("evright_d1mp", &He_d1mp);
	chainHe->SetBranchAddress("evright_d10c", &He_d10c);
	chainHe->SetBranchAddress("evright_d10pp", &He_d10pp);
	chainHe->SetBranchAddress("evright_d10pm", &He_d10pm);
	chainHe->SetBranchAddress("evright_d10mm", &He_d10mm);
	chainHe->SetBranchAddress("evright_d10mp", &He_d10mp);
	chainHe->SetBranchAddress("evright_t1c", &He_t1c);
	chainHe->SetBranchAddress("evright_edtmc", &He_edtm);
	chainHe->SetBranchAddress("evright_fclkc", &He_fclk);

	cout << "Number of events: " << HeNumberOfEvents << endl;
	chainHe->GetEntry(1);
	double initial_t1count = He_t1c;
	double initial_ugChargeCount = He_u3c;
	HeRunNumberForArray = int(HeRunNum);
	int HePrevRunNumber = HeRunNumberForArray;
	int HeRunNumPlace = 0;
	double HePrev_u3c = He_u3c;
	double He_u3p = 0;
	double He_u3m = 0;
	double He_u3c_real = 0;
	double He_u3c_real_for_event = 0;
	double HeEndOfRun_u3c = 0;
	double HeEndOfRun_u3p = 0;
	double HeEndOfRun_u3m = 0;
	int HeRealNumOfRuns = 1;
	double HeRatio = 1e-15;
	int HeTrueRunCounter = 0;
	double HeChargeScale = 1e-15;
	int HeTriggerstotal = 0;
	int HeTriggersUp = 0;
	int HeTriggersDown = 0;
	int BeamTriggersUp = 0;
	int BeamTriggersDown = 0;
	int HeT2total = 0;
	int HeT2up = 0;
	int HeT2down = 0;
	int BeamT2up = 0;
	int BeamT2down = 0;
	int thisRunNumber = 0;
	int goodBasic = 0;
	double goodBasicPct;
	double goodEventsPct;

	if (int(HeSpin)==1)
	{
		t1cUpInitial = He_t1c;
		ugChargeUpInitial = ((He_u3c-He_edtm) - 490.0*(He_fclk/(103.7*1000.0)))/2067.7;
	}
	if (int(HeSpin)==0)
	{
		t1c0Initial = He_t1c;
		ugCharge0Initial = ((He_u3c-He_edtm) - 490.0*(He_fclk/(103.7*1000.0)))/2067.7;
	}
	if (int(HeSpin)==-1)
	{
		t1cDownInitial = He_t1c;
		ugChargeDownInitial = ((He_u3c-He_edtm) - 490.0*(He_fclk/(103.7*1000.0)))/2067.7;
	}
	oldHeState = HeSpin;

	Int_t maxentries;
	if (test) {maxentries = 1000;}
	if (!test) {maxentries = nentries;}
	cout << "maxentries = " << maxentries << endl;
	for (Int_t jentry=0; jentry<maxentries;jentry++) 
	{
		if (!test && ((jentry%10000)==0)) {cout << eventType << "Processing Event " << jentry << "..." << endl;}
		if (test && (jentry%100)==0) {cout << eventType << "Processing Event " << jentry << "..." << endl;}
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
			goodEvent = true;
			goodBasic = goodBasic + 1;
		}
		else {goodEvent = false;}

		if (isGoodForAllBasic)
		{
			nplane = ((int) NA_n_plane[0]) + 1;
			thisbar = (int) NA_n_pad[0];
			if ((nplane>-1 && nplane<5) && (thisbar>-1 && thisbar<34))
			{
				if (!includeVetos) {goodEvent = (goodEvent && inGoodBar);}
				if (includeVetos && !findProtons) {hand_class_veto_cuts(nplane, thisbar, madePastLVetoCuts, madePastRVetoCuts, madePastVetoCuts, vetoTDCcutmin, vetoTDCcutmax, jentry, allVetos[nplane][thisbar], useIf, useIfElse, useSwitch, includeVetos, notEdge);}
				if (includeVetos && findProtons) {hand_class_veto_cuts2(nplane, thisbar, madePastLVetoCuts, madePastRVetoCuts, madePastVetoCuts, vetoTDCcutmin, vetoTDCcutmax, jentry, allVetos[nplane][thisbar], useIf, useIfElse, useSwitch, includeVetos);}
				goodEvent = (goodEvent && madePastVetoCuts);
				hand_class_fill_bar_by_bar_cuts(HeRunNumber, nplane, thisbar, pastThetaCut, madePastLVetoCuts, madePastRVetoCuts, madePastVetoCuts, HANDleft[nplane][thisbar], HANDleftcut[nplane][thisbar], HANDright[nplane][thisbar], HANDrightcut[nplane][thisbar], HeThetaCut[nplane][thisbar], HePhiCut[nplane][thisbar], HeThetaPhiBarCut[nplane][thisbar], goodTDCleftcutmin, goodTDCleftcutmax, goodTDCrightcutmin, goodTDCrightcutmax);
			}
			else {goodEvent = false;}

			if (goodEvent)
			{
				goodEvents = goodEvents+1;
				for (int k=0; k<11; k++) 
				{
					hand_class_fill_good_events(ToFgoodEvent[k], ToFcut[k], ToFup[k], ToFdown[k], nuAllCuts[k], nuUp, nuDown, tofCutMin, tofCutMax, nuMin, nuMax, nuBins, asymType,k, nuUpAllCuts[k], nuDownAllCuts[k], TDC1up[k], TDC1dn[k], TDC2up[k], TDC2dn[k], TDC3up[k], TDC3dn[k], TDC4up[k], TDC4dn[k]);
				}
			}
	
		}

		if (dataType==1)
		{
// vvvvvvvvvvvvvvvvvvvvvv The massive chunk below outputs the charge and livetime information for each run vvvvvvvvvvvvvvvvvvvvvv
			i = jentry;
			chainHe->GetEntry(i);
			HeTriggerstotal++;
			if (int(HeSpin)==1)
			{
				HeTriggersUp++;
			}
			if (int(HeSpin)==-1)
			{
				HeTriggersDown++;
			}
			if (int(g0helicity)==1)
			{
				BeamTriggersUp++;
			}
			if (int(g0helicity)==-1)
			{
				BeamTriggersDown++;
			}
			if (i<(maxentries-1))
			{
				fChain->GetEntry(i+1);
				if (HeSpin != oldHeState) {newHeState = true;}
			}
			fChain->GetEntry(i);
			if (newHeState || (i==(maxentries-1)))
			{
				if (int(HeSpin)==1)
				{
					t1cUpFinal = He_t1c;
					t1cUpTot = t1cUpTot + (t1cUpFinal - t1cUpInitial);
					ugChargeUpFinal = ((He_u3c-He_edtm) - 490.0*(He_fclk/(103.7*1000.0)))/2067.7;
					ugChargeUpTot = ugChargeUpTot + (ugChargeUpFinal - ugChargeUpInitial);
				}
				if (int(HeSpin)==0)
				{
					t1c0Final = He_t1c;
					t1c0Tot = t1c0Tot + (t1c0Final - t1c0Initial);
					ugCharge0Final = ((He_u3c-He_edtm) - 490.0*(He_fclk/(103.7*1000.0)))/2067.7;
					ugCharge0Tot = ugCharge0Tot + (ugCharge0Final - ugCharge0Initial);
				}
				if (int(HeSpin)==-1)
				{
					t1cDownFinal = He_t1c;
					t1cDownTot = t1cDownTot + (t1cDownFinal - t1cDownInitial);
					ugChargeDownFinal = ((He_u3c-He_edtm) - 490.0*(He_fclk/(103.7*1000.0)))/2067.7;
					ugChargeDownTot = ugChargeDownTot + (ugChargeDownFinal - ugChargeDownInitial);
				}
				newHeState = false;
			}
			if (i<(maxentries-1))
			{
				fChain->GetEntry(i+1);
				if (HeSpin != oldHeState)
				{
					if (int(HeSpin)==1)
					{
						t1cUpInitial = He_t1c;
						ugChargeUpInitial = ((He_u3c-He_edtm) - 490.0*(He_fclk/(103.7*1000.0)))/2067.7;
					}
					if (int(HeSpin)==0)
					{
						t1c0Initial = He_t1c;
						ugCharge0Initial = ((He_u3c-He_edtm) - 490.0*(He_fclk/(103.7*1000.0)))/2067.7;
					}
					if (int(HeSpin)==-1)
					{
						t1cDownInitial = He_t1c;
						ugChargeDownInitial = ((He_u3c-He_edtm) - 490.0*(He_fclk/(103.7*1000.0)))/2067.7;
					}
					oldHeState = HeSpin;
				}
				fChain->GetEntry(i);
			}
			HeRunNumberForArray = int(HeRunNum);
			He_u3c_real_for_event = He_u3c - HePrev_u3c;
			if (int(HeEvTypeBits)==2)
			{
				HeT2total++;
				if (int(HeSpin)==1)
				{
					HeT2up++;
				}
				if (int(HeSpin)==-1)
				{
					HeT2down++;
				}
				if (int(g0helicity)==1)
				{
					BeamT2up++;
				}
				if (int(g0helicity)==-1)
				{
					BeamT2down++;
				}
			}

			HePrev_u3c = He_u3c;
			HeChargeScale = HeChargeScale + thisRunCharge;
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
		}
		if ((allEvents%10000)==0)) 
		{
			goodBasicPct = goodBasic/allEvents*100.0;
			goodEventsPct = goodEvents/allEvents*100.0;
			cout << "	allEvents: " << allEvents << endl;
			cout << "	goodBasic: " << goodBasic << " (" << goodBasicPct << "%)" << endl;
			cout << "	goodEvents: " << goodEvents << " (" << goodEventsPct << "%)" << endl;
		}
		nb = fChain->GetEntry(jentry);   nbytes += nb;
	}
	TString HeRunNumberString = "Run ";
	HeRunNumberString += HeRunNumber;
	He_u3c_real = 0;
	He_u3p = 0;
	He_u3m = 0;
	chainHe->GetEntry(i-1);
	double t1_scalar = He_t1c - initial_t1count;
	HeEndOfRun_u3c = He_u3c;
	HeEndOfRun_u3p = He_u3pp + He_u3pm;
	HeEndOfRun_u3m = He_u3mm + He_u3mp;
	thisRunCharge = HeEndOfRun_u3c;
	thisRunTargetChargeUp = HeEndOfRun_u3p;
	thisRunTargetChargeDown = HeEndOfRun_u3m;
	thisRunBeamChargeUp = He_u3pp + He_u3mp;
	thisRunBeamChargeDown = He_u3mm + He_u3pm;

	if (dataType==1) {outFile << HeRunNumberString << "\n" << thisRunCharge << "\n" << HeT2total << "\n" << HeTriggerstotal << "\n" << thisRunTargetChargeUp << "\n" << HeT2up << "\n" << HeTriggersUp << "\n" << thisRunTargetChargeDown << "\n" << HeT2down << "\n" << HeTriggersDown << "\n" << thisRunBeamChargeUp << "\n" << BeamT2up << "\n" << BeamTriggersUp << "\n" << thisRunBeamChargeDown << "\n" << BeamT2down << "\n" << BeamTriggersDown << "\n" << t1_scalar << "\n" << t1cUpTot << "\n" << t1c0Tot << "\n" << t1cDownTot << "\n" << ugChargeUpTot << "\n" << ugCharge0Tot << "\n" << ugChargeDownTot << "\n" << ugChargeUpInitial << "\n" << ugCharge0Initial << "\n" << ugChargeDownInitial << "\n\n"; }
        outFile.close();

    if (dataType==1) {legend << "HeRunNumberString\nthisRunCharge\nHeT2total\nHeTriggerstotal\nthisRunTargetChargeUp\nHeT2up\nHeTriggersUp\nthisRunTargetChargeDown\nHeT2down\nHeTriggersDown\nthisRunBeamChargeUp\nBeamT2up\nBeamTriggersUp\nthisRunBeamChargeDown\nBeamT2down\nBeamTriggersDown\nt1_scalar\nt1cUpTot\nt1c0Tot\nt1cDownTot\nugChargeUpTot\nugCharge0Tot\nugChargeDownTot\nugChargeUpInitial\nugCharge0Initial\nugChargeDownInitial\n\n"; }
   legend.close();	
	cout << "allEvents: " << allEvents << endl;
	cout << "goodBasic: " << goodBasic << endl;
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
			hand_class_draw_bar_by_bar_cuts(HeRunNumber, i, j, HANDleft[i][j], HANDleftcut[i][j], HANDright[i][j], HANDrightcut[i][j], HeThetaCut[i][j], HePhiCut[i][j], HeThetaPhiBarCut[i][j], allVetos[i][j], outputRootString);
		}
	}

	for (int i=0; i<11; i++)
	{
		hand_class_draw_tof_nu(ToFbasic, ToFgoodEvent[0], ToFcut[0], ToFup[0], ToFdown[0], nuAllCuts[0], ToFgoodEvent[i], ToFcut[i], ToFup[i], ToFdown[i], nuAllCuts[i], nuUp, nuDown, outputRootString, HeRunNumber, i, nuUpAllCuts[i], nuDownAllCuts[i], TDC1up[i], TDC1dn[i], TDC2up[i], TDC2dn[i], TDC3up[i], TDC3dn[i], TDC4up[i], TDC4dn[i]);
	}

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

	if (includeVetos)
	{
		cout << "Vetos ARE included." << endl;
		if (useIf) {cout << "Used 'If' statments in vetos..." << endl;}
		if (useIfElse) {cout << "Used 'If/Else' statments in vetos..." << endl;}
		if (useSwitch) {cout << "Used 'Switch' statments in vetos..." << endl;}
	}
	else { cout << "Vetos are NOT included" << endl; }
	cout << otherSpecs << endl;       
	cout << "This program has run for " << totalTimeInSeconds << " seconds (" << days << " Days, " << hours << " Hours, " << minutes << " Minutes, and " << secondsend << " Seconds)" <<  endl;

/*	if (test)
	{
		TString exitst;
		cout << "Are you ready to finish?" << endl;
		cin >> exitst;
	}
*/
	cout << endl << "All done!" << endl << endl;
	cout << "^^^^^^^^^^^^^^^^^^^^^ neutron_analysis_class.C ^^^^^^^^^^^^^^^^^^^^^^" << endl;
}
