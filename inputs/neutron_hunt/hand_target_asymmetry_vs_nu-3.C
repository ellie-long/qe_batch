// ***************************************************
//
// This script will plot the target single spin asymmetry with
// neutron cuts included. It will do this by looking
// at the number of unique helicity up(down) events in each
// bar, plotting them, then adding the plots together
// for each bar with a final asymmetry found at the
// end.
//
// 2011-02-07
// Elena Long
//
// Edited to include:
//	2011-02-09
//		Better error analysis
//		Final asymmetry text file
//	2011-08-17
//		Edited to focus on and include cuts
//		on theta for each bar (Added hand_define_bar_th.h)
//	2011-09-08
//		Added extra histograms that are added to the
//		*.root file and can be seen after analysis
//	2011-09-13
//		Added ToF histogram before the main loop
// ***************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include "hand_define_vetos.h"
#include "hand_define_bar_th.h"
#include "hand_draw.h"
#include "hand_basic_cuts.h"
#include "hand_draw_vetos.h"
#include "hand_draw_antivetos.h"
#include "hand_scaling_factors.h"
using namespace std;
// Search for HAND to get to the PMT definitions

void hand_target_asymmetry_vs_nu_3(){

	cout << "Running hand_target_asymmetry_vs_nu..." << endl;

//	TFormula::SetMaxima(1000000,1000,1000000);
	TString otherSpecs = "No thetacuts on ToF";

	string line = "";
	ifstream runNumberInputFile ("./input.file");
	getline(runNumberInputFile, line);
	int inRunNumber = atoi(line.c_str());

	cout << "Run Number: " << inRunNumber << endl;

	bool includeVetos;
// 	If includeVetos = false, then only good bars will be displayed. If 
//	includeVetos = true, then veto bars will be shown along with the good bars.
	includeVetos = true;
//	includeVetos = false;

	bool includeAntivetos;
// 	If includeAntivetos = false, then only good bars will be displayed. If 
//	includeAntivetos = true, then antiveto bars will be shown along with the good bars.
//	includeAntivetos = true;
	includeAntivetos = false;

	bool antivetosAsVetos;
//	If antivetosAsVetos = false, then the antivetos will not be included in the veto cut
//	If antivetosAsVetos = true, then the antivetos will be included in the veto cut
//	Discusses elsewhere, antivetos are the bars immediately following a goodBar
	antivetosAsVetos = false;
//	antivetosAsVetos = true;

//	bool drawCuts = true;
	bool drawCuts = false;

//	backgroundOnly will show only background events if true, neutron/proton events if false
//	bool backgroundOnly = true;
	bool backgroundOnly = false;

// 	The SinglePlane and SingleBar booleans skip the loop that goes over
// 	ever bar into just a single plane and/or a single bar.
	bool SinglePlane;
	bool SingleBar;
	int singleplane;
	int singlebar;
//	SinglePlane = true;
	SinglePlane = false;
	singleplane = 2;
//	SingleBar = true;
	SingleBar = false;
	singlebar = 10;

	TString dataset;
/*
	int HeRunNumber = 22441;
	int endHeRunNumber = 22441;
	TString Q2 = "1.0";
	double q2min = 0.75;
	double q2max = 1.2;
	double numin = 0.3;
	double numax = 0.7;
	int Positionbins = 30;
	double Positionmin = -30;
	double Positionmax = 30;
	int TDCbins = 100;
	double TDCmin = 700;
	double TDCmax = 800;
	int ADCbins = 700;
	double ADCmin = -100;
	double ADCmax = 11100;
	double goodTDCleftcutmin = 752;
	double goodTDCleftcutmax = 775;
	double goodTDCrightcutmin = 752;
	double goodTDCrightcutmax = 775;
	double vetoTDCcutmin = 750;
	double vetoTDCcutmax = 785;
*/

// **************** Vertical, Q2=1.0 *******************
	if ((inRunNumber > 20585) && (inRunNumber < 20879))
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


// **************************** Vertical, Q2=0.1 *******************
//	if ((inRunNumber > 20486) && (inRunNumber < 20541))
	if ((inRunNumber > 20400) && (inRunNumber < 20541))
	{
		cout << "Processing Vertically polarized, Q2=0.1 dataset..." << endl;
		dataset = "Vertical, Q2=0.1";
		int HeRunNumber = inRunNumber;
		int endHeRunNumber = inRunNumber;
//		int HeRunNumber = 20404;
//		int endHeRunNumber = 20407;
		TString Q2 = "0.1";
		double q2min = 0.08;
		double q2max = 0.18;
		double numin = 0.0;
		double numax = 0.13;
		int Positionbins = 30;
		double Positionmin = -30;
		double Positionmax = 30;
		int TDCbins = 40;
		double TDCmin = 1325;
		double TDCmax = 1525;
//		int TDCbins = 50;
//		double TDCmin = 0;
//		double TDCmax = 3100;

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
		double goodTDCleftcutmin = 10;
		double goodTDCleftcutmax = 3100;
		double goodTDCrightcutmin = 10;
		double goodTDCrightcutmax = 3100;
		double vetoTDCcutmin = 0;
		double vetoTDCcutmax = 3100;

		const int nuBins = 10;
		double nuMin = 0;
		double nuMax = 0.15;


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
		double nuMin = 0.35;
		double nuMax = 0.65;


	}
/*
	int HeRunNumber = 21714;
	int endHeRunNumber = 22248;
	TString Q2 = "0.52";
	double q2min = 0.33;
	double q2max = 0.62;
	double numin = 0.17;
	double numax = 0.35;
	int Positionbins = 30;
	double Positionmin = -30;
	double Positionmax = 30;
	int TDCbins = 50;
	double TDCmin = 700;
	double TDCmax = 800;
	int ADCbins = 700;
	double ADCmin = -100;
	double ADCmax = 11100;
	double goodTDCleftcutmin = 730;
	double goodTDCleftcutmax = 770;
	double goodTDCrightcutmin = 740;
	double goodTDCrightcutmax = 780;
	double vetoTDCcutmin = 730;
	double vetoTDCcutmax = 770;
*/

// ************* Longitudinal, Q2=1.0 *******************
	if ((inRunNumber > 22379) && (inRunNumber < 22445))
	{
		cout << "Processing Longitudinally polarized, Q2=1.0 dataset..." << endl;
		dataset = "Longitudinal, Q2=1.0";
//		int HeRunNumber = 22451;
		int HeRunNumber = inRunNumber;
//		int endHeRunNumber = 22451;
		int endHeRunNumber = inRunNumber;
//		int endHeRunNumber = 22489;
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


//		int TDCbins = 600;
//		double TDCmin = 0;
//		double TDCmax = 1600;

		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;

		double goodTDCleftcutmin = 745;
		double goodTDCleftcutmax = 775;
		double goodTDCrightcutmin = 750;
		double goodTDCrightcutmax = 780;

//		double goodTDCleftcutmin = 645;
//		double goodTDCleftcutmax = 875;
//		double goodTDCrightcutmin = 650;
//		double goodTDCrightcutmax = 880;
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
//		int HeRunNumber = 22451;
		int HeRunNumber = inRunNumber;
//		int endHeRunNumber = 22451;
		int endHeRunNumber = inRunNumber;
//		int endHeRunNumber = 22489;
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


//		int TDCbins = 600;
//		double TDCmin = 0;
//		double TDCmax = 1600;

		int ADCbins = 700;
		double ADCmin = -100;
		double ADCmax = 11100;

		double goodTDCleftcutmin = 745;
		double goodTDCleftcutmax = 775;
		double goodTDCrightcutmin = 750;
		double goodTDCrightcutmax = 780;

//		double goodTDCleftcutmin = 645;
//		double goodTDCleftcutmax = 875;
//		double goodTDCrightcutmin = 650;
//		double goodTDCrightcutmax = 880;
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

//	const int nuBins = 50;
//	const int nuBins = 10;
//	double nuMin = 0.35;
//	double nuMax = 0.65;

	double xmin = 0.6;
	double xmax = 3.0;

	int bins = 50;

	TString outputPlotsHere = "./";

	TString outputRootString = outputPlotsHere;
	outputRootString += "hand_target_asym_vs_nu_for_run_";
	outputRootString += HeRunNumber;
	outputRootString += ".root";
	TFile *outputRoot = new TFile(outputRootString,"RECREATE");
//	TFile outputRoot(outputRootString,"RECREATE");

	outputRoot->Close();

	TString asymOutFileName = outputPlotsHere;
	asymOutFileName += "target_asymmetry_for_run_";
	asymOutFileName += HeRunNumber;
	asymOutFileName += ".txt";
	ofstream asymOutFile;
	asymOutFile.open(asymOutFileName);

	// Although declared here, the goodTDCcut is actually made down below where  it can be included
	// in the loop so that it is easy to have it change for each good bar when done one at a time.
	// However, the left and right min and max TDC values are defined here
	TCut goodTDCcut = "";

	TChain* chainHe = new TChain("T");
	TString filenameHe;

	for (int thisHeRunNumber=HeRunNumber; thisHeRunNumber<(endHeRunNumber+1); thisHeRunNumber++)
	{
/*		// Skipping Vertical Non-Production Runs
		if(thisHeRunNumber==20591){thisHeRunNumber=20596;}
		if(thisHeRunNumber==20731){thisHeRunNumber=20738;}
		if(thisHeRunNumber==20732){thisHeRunNumber=20738;}
		if(thisHeRunNumber==20733){thisHeRunNumber=20738;}
		if(thisHeRunNumber==20734){thisHeRunNumber=20738;}
		if(thisHeRunNumber==20736){thisHeRunNumber=20738;}
		if(thisHeRunNumber==20737){thisHeRunNumber=20738;}
		if(thisHeRunNumber==20762){thisHeRunNumber=20789;}
		if(thisHeRunNumber==20763){thisHeRunNumber=20789;}
		if(thisHeRunNumber==20764){thisHeRunNumber=20789;}
		if(thisHeRunNumber==20791){thisHeRunNumber=20814;}
		if(thisHeRunNumber==20792){thisHeRunNumber=20814;}

		// Skipping Longitudinal Non-Production Runs
		if(thisHeRunNumber==22380){thisHeRunNumber=22393;}
		if(thisHeRunNumber==22389){thisHeRunNumber=22393;}
		if(thisHeRunNumber==22425){thisHeRunNumber=22436;}
		if(thisHeRunNumber==22426){thisHeRunNumber=22436;}

		// Skipping Transverse Non-Production Runs
		if(thisHeRunNumber==22461){thisHeRunNumber=22465;}

*/
		for (int t=0; t<1000; t++)
		{
//			filenameHe = "/home/ellie/physics/e05-102/ellana/ROOTfiles/e05102_R_";
			filenameHe = "./e05102_R_";
			filenameHe += thisHeRunNumber;
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
			TFile fileHe(filenameHe);
		}
	}

	gStyle->SetPalette(1);

	TCut cut = ""; TCut kinematics = ""; TCut eventtype = ""; TCut dp = ""; TCut target = "";
	TCut tracks = ""; TCut thph = ""; TCut xbj = ""; TCut pssh = ""; TCut cerenkov = "";
	TCut q2nu = ""; TCut basic = ""; TCut cuts = "";

	TString imageCutsTitle = outputPlotsHere;
	imageCutsTitle += "HAND_plots_Run_Num_";
	imageCutsTitle += HeRunNumber;
	imageCutsTitle += "-";
	imageCutsTitle += endHeRunNumber;
	imageCutsTitle += "_basic_cuts";
	if (includeVetos) imageCutsTitle += "_with_vetos";
	if (includeAntivetos) {imageCutsTitle += "_with_antivetos";}
	if (antivetosAsVetos && includeAntivetos) {imageCutsTitle += "_as_vetos";}
	imageCutsTitle += ".png";

	hand_basic_cuts(cut, kinematics, eventtype, dp, target, tracks, thph, xbj, pssh, cerenkov, q2nu, basic, cuts, imageCutsTitle, HeRunNumber, endHeRunNumber, chainHe, numin, numax, q2min, q2max, bins, xmin, xmax, drawCuts, Q2, outputRootString);

	TFile *outputRoot1 = new TFile(outputRootString,"UPDATE");

	TString cutstring = TString(cuts);
	cout << "Cuts: " << cutstring << endl;
// **********************************************************************************************
	gStyle->SetOptFit(1111);
        TString veto1plane = "";
        TString veto1bar = "";
        TString veto2plane = "";
        TString veto2bar = "";
        TString veto3plane = "";
        TString veto3bar = "";
        TString veto4plane = "";
        TString veto4bar = "";
        TString veto5plane = "";
        TString veto5bar = "";
        TString veto6plane = "";
        TString veto6bar = "";
        TString antiveto1plane = "";
        TString antiveto1bar = "";
        TString antiveto2plane = "";
        TString antiveto2bar = "";
        TString antiveto3plane = "";
        TString antiveto3bar = "";
        TString allVetos = "";
        TString allAntivetos = "";
        TString vetoTDCslSt = "";
        TString vetoTDCsrSt = "";
        TCut vetoTDCsl = "";
        TCut vetoTDCsr = "";
        TCut vetoTDCs = "";
        TString antivetosTDCslSt = "";
        TString antivetosTDCsrSt = "";
	int maxbars = 0;
	int vetoplane = 0;
	int padBins = 0;
	double padMin = 0;
	double padMax = 0;

	double thetaMin;
	double thetaMax;
	TString thetaCutSt;
	TCut thetaCut;


// **********************************************************************************************
// This bit of code should set the charge and livetime scaling factors
        double HeChargeScale; double Helivetime;
        double HeChargeScaleUp; double HelivetimeUp;
        double HeChargeScaleDown; double HelivetimeDown;
        double BeamChargeScaleUp; double BeamlivetimeUp;
        double BeamChargeScaleDown; double BeamlivetimeDown;
        hand_scaling_factors(HeRunNumber, endHeRunNumber, HeChargeScale, Helivetime, HeChargeScaleUp, HelivetimeUp, HeChargeScaleDown, HelivetimeDown, BeamChargeScaleUp, BeamlivetimeUp, BeamChargeScaleDown, BeamlivetimeDown);
	HeChargeScale = 0.00001 * int(HeChargeScale * 100000.0 + 0.5);
	HeChargeScaleUp = 0.00001 * int(HeChargeScaleUp * 100000.0 + 0.5);
	HeChargeScaleDown = 0.00001 * int(HeChargeScaleDown * 100000.0 + 0.5);
	BeamChargeScaleUp = 0.00001 * int(BeamChargeScaleUp * 100000.0 + 0.5);
	BeamChargeScaleDown = 0.00001 * int(BeamChargeScaleDown * 100000.0 + 0.5);
	Helivetime = 0.0001 * int(Helivetime * 10000.0 + 0.5);
	HelivetimeUp = 0.0001 * int(HelivetimeUp * 10000.0 + 0.5);
	HelivetimeDown = 0.0001 * int(HelivetimeDown * 10000.0 + 0.5);
	BeamlivetimeUp = 0.0001 * int(BeamlivetimeUp * 10000.0 + 0.5);
	BeamlivetimeDown = 0.0001 * int(BeamlivetimeDown * 10000.0 + 0.5);
	cout << "HeChargeScale: " << HeChargeScale << "C, Helivetime: " << Helivetime << endl;
	cout << "HeChargeScaleUp: " << HeChargeScaleUp << "C, HelivetimeUp: " << HelivetimeUp << endl;
	cout << "HeChargeScaleDown: " << HeChargeScaleDown << "C, HelivetimeDown: " << HelivetimeDown << endl;
	cout << "BeamChargeScaleUp: " << BeamChargeScaleUp << "C, BeamlivetimeUp: " << BeamlivetimeUp << endl;
	cout << "BeamChargeScaleDown: " << BeamChargeScaleDown << "C, BeamlivetimeDown: " << BeamlivetimeDown << endl;

// **********************************************************************************************


// The section below will plot the ToF spectra
// **********************************************************************************************
	int tofBins = 100;
//	int tofMin = 0;
//	int tofMax = 1600;
	int tofMin = 200;
	int tofMax = 1300;
//	int tofCutMin = 500;
//	int tofCutMax = 800;
	int tofCutMin = 660;
	int tofCutMax = 690;
/*
	TString ToFOCanvasName = "tofOcanvas";
	TString ToFOCanvasTitle = "Time of Flight[0]";
	TCanvas *handCanvas = new TCanvas(ToFOCanvasName,ToFOCanvasTitle,1400,770); //x,y
	tofOpad01 =  new TPad("tofOpad01","tofOpad01",0.0000,0.0000,0.3333,1.0000,0,0,0);
	tofOpad02 =  new TPad("tofOpad02","tofOpad02",0.3333,0.0000,0.6666,1.0000,0,0,0);
	tofOpad03 =  new TPad("tofOpad03","tofOpad03",0.6666,0.0000,1.0000,1.0000,0,0,0);
	tofOpad01->Draw(); tofOpad02->Draw(); tofOpad03->Draw();

	tofOpad01->cd();
	TString titleToFO = "ToF[0] with basic cuts";
	cout << titleToFO << "..." << endl;
	cout << "Drawing " << titleToFO << "..." << endl;
	TString plotToFO = "HANDToFO";
	TH1F *HANDToFO = new TH1F(plotToFO,titleToFO,tofBins,tofMin,tofMax);
	TString HANDToFOString = "NA.n.tof[0]";
	HANDToFOString += ">>";
	HANDToFOString += plotToFO;
	chainHe->Draw(HANDToFOString, cuts ,"");
	HANDToFO->SetMinimum(0);
	HANDToFO->Write();
	HANDToFO->Draw();
	tofOpad01->Update();

	tofOpad02->cd();
	TString titleToFOUp = "ToF[0] with basic cuts and spin Up";
	cout << titleToFOUp << "..." << endl;
	cout << "Drawing " << titleToFOUp << "..." << endl;
	TString plotToFOUp = "HANDToFOUp";
	TH1F *HANDToFOUp = new TH1F(plotToFOUp,titleToFOUp,tofBins,tofMin,tofMax);
	TString HANDToFOUpString = "NA.n.tof[0]";
	HANDToFOUpString += ">>";
	HANDToFOUpString += plotToFOUp;
	chainHe->Draw(HANDToFOUpString, cuts && "he3R.Spin==1 && he3R.IsSpinValid==1","");
	HANDToFOUp->SetMinimum(0);
	HANDToFOUp->Write();
	HANDToFOUp->Draw();
	tofOpad02->Update();

	tofOpad03->cd();
	TString titleToFODown = "ToF[0] with basic cuts and spin Down";
	cout << titleToFODown << "..." << endl;
	cout << "Drawing " << titleToFODown << "..." << endl;
	TString plotToFODown = "HANDToFODown";
	TH1F *HANDToFODown = new TH1F(plotToFODown,titleToFODown,tofBins,tofMin,tofMax);
	TString HANDToFODownString = "NA.n.tof[0]";
	HANDToFODownString += ">>";
	HANDToFODownString += plotToFODown;
	chainHe->Draw(HANDToFODownString, cuts && "he3R.Spin==-1 && he3R.IsSpinValid==1","");
	HANDToFODown->SetMinimum(0);
	HANDToFODown->Write();
	HANDToFODown->Draw();
	tofOpad03->Update();
*/
// The section below plots the HAND data
// **********************************************************************************************
//	int whichplane = 0;
	int whichplane = 2;
	int endplane = 5;
//	int endplane = 3;
	if (SinglePlane) {whichplane = singleplane; endplane = singleplane+1;}
	int whichbar=0;
//	int whichbar=10;
	TString titleTotalSpinUpx = "Total Target Spin Up vs. xBj";
	if (includeVetos) {titleTotalSpinUpx += " with vetos";}
	else {titleTotalSpinUpx += " without vetos";}
	titleTotalSpinUpx += " with goodTDC cuts";
	cout << "Drawing " << titleTotalSpinUpx << "..." << endl;
	TString plotTotalSpinUpx = "HANDTotalSpinUpx";
	TH1F *HANDTotalSpinUpx = new TH1F(plotTotalSpinUpx,titleTotalSpinUpx,nuBins,nuMin,nuMax);
	TString titleTotalSpinDownx = "Total Target Spin Down vs. xBj";
	if (includeVetos) {titleTotalSpinDownx += " with vetos";}
	else {titleTotalSpinDownx += " without vetos";}
	titleTotalSpinDownx += " with goodTDC cuts";
	cout << "Drawing " << titleTotalSpinDownx << "..." << endl;
	TString plotTotalSpinDownx = "HANDTotalSpinDownx";
	TH1F *HANDTotalSpinDownx = new TH1F(plotTotalSpinDownx,titleTotalSpinDownx,nuBins,nuMin,nuMax);
	TString allGoodBarCutsStr = "";
	TString allGoodBarCutsTillNow = "";
	for (int nplane=whichplane; nplane<endplane; nplane++)
	{
//		if (nplane==0) {maxbars=32;}
//		if (nplane==1) {maxbars=30;}
//		if (nplane==2) {maxbars=24;}
//		if (nplane==3) {maxbars=22;}
//		if (nplane==4) {maxbars=12;}

//		if (nplane==0) {maxbars=32; whichbar=16;}
//		if (nplane==1) {maxbars=20; whichbar=10;}
//		if (nplane==2) {maxbars=16; whichbar=8;}
//		if (nplane==3) {maxbars=15; whichbar=7;}
//		if (nplane==4) {maxbars=7; whichbar=4;}

		if (nplane==0) {maxbars=32; whichbar=16;}
		if (nplane==1) {maxbars=17; whichbar=12;}
		if (nplane==2) {maxbars=13; whichbar=10;}
		if (nplane==3) {maxbars=12; whichbar=9;}
		if (nplane==4) {maxbars=6; whichbar=5;}

		if (SingleBar) {whichbar = singlebar; maxbars = singlebar + 1;}
		for (int thisbar=whichbar; thisbar<maxbars; thisbar++)
		{

			TString goodPlane = nplane;
			TString goodPMT = thisbar;
			hand_define_vetos(includeVetos, includeAntivetos, antivetosAsVetos, nplane, thisbar, veto1plane, veto2plane, veto3plane, veto4plane, veto5plane, veto6plane, veto1bar, veto2bar, veto3bar, veto4bar, veto5bar, veto6bar, antiveto1plane, antiveto2plane, antiveto3plane, antiveto1bar, antiveto2bar, antiveto3bar, allVetos, allAntivetos, vetoTDCslSt, vetoTDCsrSt, vetoTDCsl, vetoTDCsr, vetoTDCs, vetoTDCcutmin, vetoTDCcutmax, antivetosTDCslSt, antivetosTDCsrSt);


			hand_define_bar_th(Q2, nplane, thisbar, thetaMin, thetaMax, thetaCutSt, thetaCut);
			
			TString goodBar = "nd.p";
			goodBar += nplane;
			goodBar += ".";
			goodBar += thisbar;
			goodBar += " ";
			cout << "Good Bar: " << goodBar << endl;

			TString goodTDCl = "NA.nd.p";
			goodTDCl += nplane;
			if (nplane == 0) goodTDCl = "NA.veto";
			goodTDCl += ".lt_c[";
			goodTDCl += thisbar;
			goodTDCl += "]";
			TString goodTDCr = "NA.nd.p";
			goodTDCr += nplane;
			if (nplane == 0) goodTDCr = "NA.veto";
			goodTDCr += ".rt_c[";
			goodTDCr += thisbar;
			goodTDCr += "]";
			TString goodTDCs = goodTDCl;
			goodTDCs += ":";
			goodTDCs += goodTDCr;
		
                        TString goodADCl = "NA.nd.p";
                        goodADCl += nplane;
                        if (nplane == 0) goodADCl = "NA.veto";
                        goodADCl += ".la_c[";
                        goodADCl += thisbar;
                        goodADCl += "]";
                        TString goodADCr = "NA.nd.p";
                        goodADCr += nplane;
                        if (nplane == 0) goodADCr = "NA.veto";
                        goodADCr += ".ra_c[";
                        goodADCr += thisbar;
                        goodADCr += "]";
                        TString goodADCs = goodADCl;
                        goodADCs += ":";
                        goodADCs += goodADCr;
	
			TString canvasName = "handp";
			canvasName += nplane;
			canvasName += "b";
			canvasName += thisbar;
			TString canvasTitle = "HAND - Plane ";
			canvasTitle += nplane;
			canvasTitle += ", Bar ";
			canvasTitle += thisbar;
			TCanvas *handCanvas = new TCanvas(canvasName,canvasTitle,1400,770); //x,y
			handpad01 =  new TPad("handpad01","handpad01",0.0000,0.0000,0.1000,1.0000,0,0,0);
			handpad02 =  new TPad("handpad02","handpad02",0.1000,0.6666,0.5500,1.0000,0,0,0);
			handpad03 =  new TPad("handpad03","handpad03",0.5500,0.6666,1.0000,1.0000,0,0,0);
			handpad04 =  new TPad("handpad04","handpad04",0.1000,0.3333,0.5500,0.6666,0,0,0);
			handpad05 =  new TPad("handpad05","handpad05",0.5500,0.3333,1.0000,0.6666,0,0,0);
			handpad06 =  new TPad("handpad06","handpad06",0.1000,0.0000,0.5500,0.3333,0,0,0);
			handpad07 =  new TPad("handpad07","handpad07",0.5500,0.0000,1.0000,0.3333,0,0,0);
			handpad01->Draw(); handpad02->Draw(); handpad03->Draw(); handpad04->Draw(); handpad05->Draw();
			handpad06->Draw(); handpad07->Draw();

			// This section will run hand_draw.h which will draw the HAND in handpad01.
			handpad01->cd();
			hand_draw(HeRunNumber, endHeRunNumber, antivetosAsVetos, allVetos, goodBar, allAntivetos);
			handpad01->Update();


			TString goodTDCrightcutString = "";
			TString goodTDCleftcutString = "";
			TCut goodTDCrightcut = "";
			TCut goodTDCleftcut = "";
			// The two sections below define good TDC cut to be where the neutron peak is
//			vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
			if (!backgroundOnly)
			{
				cout << "Peak ONLY Events" << endl;
				goodTDCleftcutString = "(NA.nd.p";
				goodTDCleftcutString += nplane;
				if (nplane == 0) {goodTDCleftcutString = "(NA.veto";}
				goodTDCleftcutString += ".lt_c[";
				goodTDCleftcutString += thisbar;
				goodTDCleftcutString += "]>";
				goodTDCleftcutString += goodTDCleftcutmin;
				if (nplane > 0)
				{
					goodTDCleftcutString += " && NA.nd.p";
					goodTDCleftcutString += nplane;
				}
				if (nplane == 0) {goodTDCleftcutString += " && NA.veto";}
				goodTDCleftcutString += ".lt_c[";
				goodTDCleftcutString += thisbar;
				goodTDCleftcutString += "]<";
				goodTDCleftcutString += goodTDCleftcutmax;
				goodTDCleftcutString += ")";
				cout << "goodTDCleftcutString = " << goodTDCleftcutString << endl;
				goodTDCleftcut = goodTDCleftcutString;
		
				goodTDCrightcutString = "(NA.nd.p";
				goodTDCrightcutString += nplane;
				if (nplane == 0) {goodTDCrightcutString = "(NA.veto";}
				goodTDCrightcutString += ".rt_c[";
				goodTDCrightcutString += thisbar;
				goodTDCrightcutString += "]>";
				goodTDCrightcutString += goodTDCrightcutmin;
				if (nplane > 0)
				{
					goodTDCrightcutString += " && NA.nd.p";
					goodTDCrightcutString += nplane;
				}
				if (nplane == 0) {goodTDCrightcutString += " && NA.veto";}
				goodTDCrightcutString += ".rt_c[";
				goodTDCrightcutString += thisbar;
				goodTDCrightcutString += "]<";
				goodTDCrightcutString += goodTDCrightcutmax;
				goodTDCrightcutString += ")";
				cout << "goodTDCrightcutString = " << goodTDCrightcutString << endl;
				goodTDCrightcut = goodTDCrightcutString;
			}
//			^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//			The section below defines the good TDC cut to be background events
//			vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
			if (backgroundOnly)
			{
				cout << "Background ONLY Events" << endl;
				goodTDCleftcutString = "(NA.nd.p";
				goodTDCleftcutString += nplane;
				if (nplane == 0) {goodTDCleftcutString = "(NA.veto";}
				goodTDCleftcutString += ".lt_c[";
				goodTDCleftcutString += thisbar;
				goodTDCleftcutString += "]<";
				goodTDCleftcutString += goodTDCleftcutmin;
				if (nplane > 0)
				{
					goodTDCleftcutString += " || NA.nd.p";
					goodTDCleftcutString += nplane;
				}
				if (nplane == 0) {goodTDCleftcutString += " || NA.veto";}
				goodTDCleftcutString += ".lt_c[";
				goodTDCleftcutString += thisbar;
				goodTDCleftcutString += "]>";
				goodTDCleftcutString += goodTDCleftcutmax;
				goodTDCleftcutString += ")";
				cout << "goodTDCleftcutString = " << goodTDCleftcutString << endl;
				goodTDCleftcut = goodTDCleftcutString;
		
				goodTDCrightcutString = "(NA.nd.p";
				goodTDCrightcutString += nplane;
				if (nplane == 0) {goodTDCrightcutString = "(NA.veto";}
				goodTDCrightcutString += ".rt_c[";
				goodTDCrightcutString += thisbar;
				goodTDCrightcutString += "]<";
				goodTDCrightcutString += goodTDCrightcutmin;
				if (nplane > 0)
				{
					goodTDCrightcutString += " || NA.nd.p";
					goodTDCrightcutString += nplane;
				}
				if (nplane == 0) {goodTDCrightcutString += " || NA.veto";}
				goodTDCrightcutString += ".rt_c[";
				goodTDCrightcutString += thisbar;
				goodTDCrightcutString += "]>";
				goodTDCrightcutString += goodTDCrightcutmax;
				goodTDCrightcutString += ")";
				cout << "goodTDCrightcutString = " << goodTDCrightcutString << endl;
				goodTDCrightcut = goodTDCrightcutString;
			}
//			^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
			TString firstTrackString = "NA.n.plane==";
			firstTrackString += (nplane - 1);
			firstTrackString += " && NA.n.pad==";
			firstTrackString += thisbar;
			TCut firstTrack = firstTrackString;

			cout << "goodTDCcut = (" << goodTDCleftcutString << " || " << goodTDCrightcutString << ");" << endl;	
			goodTDCcut = (goodTDCleftcut || goodTDCrightcut);

//			cout << "Cuts: " << cutstring << endl;
			TString vetoCutString = TString(vetoTDCs);
//			cout << "Veto Cuts: " << vetoCutString << endl; 

			handpad02->cd();
/*			TString titleHANDleft = "Left TDC for Plane #";
			titleHANDleft += nplane;
			titleHANDleft += ", PMT # ";
			titleHANDleft += thisbar;
			if (includeVetos) {titleHANDleft += " with vetos";}
			else {titleHANDleft += " without vetos";}
			TString spinUpTitleHANDleft = "Spin Up Events in ";
			spinUpTitleHANDleft += titleHANDleft;
			TString spinDownTitleHANDleft = "Spin Down Events in ";
			spinDownTitleHANDleft += titleHANDleft;
			cout << "Drawing " << titleHANDleft << "..." << endl;
			TString plotHANDleft = "HANDleft_p";
			plotHANDleft += nplane;
			plotHANDleft += "_b";
			plotHANDleft += thisbar;
			TString spinUpPlotHANDleft = "spinUp_";
			spinUpPlotHANDleft += plotHANDleft;
			TString spinDownPlotHANDleft = "spinDown_";
			spinDownPlotHANDleft += plotHANDleft;
			TString plotHANDleftcut = plotHANDleft;
			plotHANDleftcut += "_cut";
			TString spinUpPlotHANDleftcut = spinUpPlotHANDleft;
			spinUpPlotHANDleftcut += "_cut";
			TString spinDownPlotHANDleftcut = spinDownPlotHANDleft;
			spinDownPlotHANDleftcut += "_cut";
//			cout << "plotHANDleft: " << plotHANDleft << ", plotHANDleftcut: " << plotHANDleftcut << endl;
			cout << "goodTDCl: " << goodTDCl << endl;
			TH1F *HANDleft = new TH1F(plotHANDleft,titleHANDleft,TDCbins,TDCmin,TDCmax);
			TH1F *HANDleftUp = new TH1F(spinUpPlotHANDleft,spinUpTitleHANDleft,TDCbins,TDCmin,TDCmax);
			TH1F *HANDleftDown = new TH1F(spinDownPlotHANDleft,spinDownTitleHANDleft,TDCbins,TDCmin,TDCmax);
			HANDleft->SetMinimum(0);
			HANDleftUp->SetMinimum(0);
			HANDleftDown->SetMinimum(0);
			TH1F *HANDleftcut = new TH1F(plotHANDleftcut,titleHANDleft,TDCbins,TDCmin,TDCmax);
			TH1F *HANDleftUpcut = new TH1F(spinUpPlotHANDleftcut,spinUpTitleHANDleft,TDCbins,TDCmin,TDCmax);
			TH1F *HANDleftDowncut = new TH1F(spinDownPlotHANDleftcut,spinDownTitleHANDleft,TDCbins,TDCmin,TDCmax);
			HANDleftcut->SetMinimum(0);
			HANDleftUpcut->SetMinimum(0);
			HANDleftDowncut->SetMinimum(0);
			TString HANDleftTDC = goodTDCl;
			HANDleftTDC += ">>";
			TString HANDleftTDCUp = HANDleftTDC;
			HANDleftTDCUp += spinUpPlotHANDleft;
			TString HANDleftTDCDown = HANDleftTDC;
			HANDleftTDCDown += spinDownPlotHANDleft;
			TString HANDleftTDCUpcut = HANDleftTDC;
			HANDleftTDCUpcut += spinUpPlotHANDleftcut;
			TString HANDleftTDCDowncut = HANDleftTDC;
			HANDleftTDCDowncut += spinDownPlotHANDleftcut;
			HANDleftTDC += plotHANDleft;
			TString HANDleftTDCcut = goodTDCl;
			HANDleftTDCcut += ">>";
			HANDleftTDCcut += plotHANDleftcut;
			chainHe->Draw(HANDleftTDC, cuts && vetoTDCs && firstTrack && thetaCut,"");
			chainHe->Draw(HANDleftTDCUp, cuts && vetoTDCs && firstTrack && thetaCut && "he3R.Spin==1" ,"");
			chainHe->Draw(HANDleftTDCDown, cuts && vetoTDCs && firstTrack && thetaCut && "he3R.Spin==-1","");
//			chainHe->Draw(HANDleftTDC, vetoTDCs,"");
//			HANDleft->Scale(1/(HeChargeScale*Helivetime));
			HANDleft->Write();
			HANDleftUp->Write();
			HANDleftDown->Write();
			HANDleft->Draw();
			HANDleftUp->Draw();
			HANDleftDown->Draw();
			if (!includeVetos) {chainHe->Draw(HANDleftTDCcut, cuts && goodTDCleftcut && firstTrack && thetaCut,"same");}
			if (!includeVetos) {chainHe->Draw(HANDleftTDCUpcut, cuts && goodTDCleftcut && firstTrack && thetaCut && "he3R.Spin==1","same");}
			if (!includeVetos) {chainHe->Draw(HANDleftTDCDowncut, cuts && goodTDCleftcut && firstTrack && thetaCut && "he3R.Spin==-1","same");}
			if (includeVetos) {chainHe->Draw(HANDleftTDCcut, cuts && vetoTDCs && goodTDCleftcut && firstTrack && thetaCut,"same");}
			if (includeVetos) {chainHe->Draw(HANDleftTDCUpcut, cuts && vetoTDCs && goodTDCleftcut && firstTrack && thetaCut && "he3R.Spin==1","same");}
			if (includeVetos) {chainHe->Draw(HANDleftTDCDowncut, cuts && vetoTDCs && goodTDCleftcut && firstTrack && thetaCut && "he3R.Spin==-1","same");}
			HANDleftcut->SetFillColor(kViolet);
			HANDleftUpcut->SetFillColor(kViolet);
			HANDleftDowncut->SetFillColor(kViolet);
//			HANDleftcut->Scale(1/(HeChargeScale*Helivetime));
			HANDleftcut->Write();
			HANDleftUpcut->Write();
			HANDleftDowncut->Write();
			HANDleftcut->Draw("same");
			HANDleftUpcut->Draw("same");
			HANDleftDowncut->Draw("same");
			// ********************************************************************************
			// This section below gathers and prints some statistics on the plot
//			double numHANDleftcutEvents = 0;
//			for (int i=0; i<TDCbins; i++){ numHANDleftcutEvents = numHANDleftcutEvents + HANDleftcut->GetBinContent(i);}
//			TString HANDleftFactorsString = "Total Charge for Runs: ";
//			HANDleftFactorsString += HeChargeScale;
//			HANDleftFactorsString += " C";
//			TString HANDleftFactorsString1 = "Total Livetime for Runs: ";
//			HANDleftFactorsString1 += Helivetime;
//			TString HANDleftFactorsString2 = "# of Cut (Purple) Events: ";
//			HANDleftFactorsString2 += numHANDleftcutEvents;
//			HANDleftFactors = new TPaveText(0.11,0.69,0.4,0.89,"NDC");
//			TText *t1 = HANDleftFactors->AddText(HANDleftFactorsString);
//			TText *t2 = HANDleftFactors->AddText(HANDleftFactorsString1);
//			TText *t2 = HANDleftFactors->AddText(HANDleftFactorsString2);
//			HANDleftFactors->Write();
//			HANDleftFactors->Draw("same");
//			// ********************************************************************************

			TString titleToF = "ToF for Plane ";
			titleToF += nplane;
			titleToF += " and bar ";
			titleToF += thisbar;
			cout << titleToF << "..." << endl;
			cout << "Drawing " << titleToF << "..." << endl;
			TString plotToF = "HANDToF_p";
			plotToF += nplane;
			plotToF += "_b";
			plotToF += thisbar;
			TH1F *HANDToF = new TH1F(plotToF,titleToF,tofBins,tofMin,tofMax);
			TString HANDToFString = "NA.n.tof[0]";
			HANDToFString += ">>";
			HANDToFString += plotToF;
//			chainHe->Draw(HANDToFString, cuts && firstTrack && thetaCut,"same");
			chainHe->Draw(HANDToFString, cuts && firstTrack,"same");
			HANDToF->SetMinimum(0);
			HANDToF->Write();
			HANDToF->Draw();

			TString titleToFUp = "ToFUp for Plane ";
			titleToFUp += nplane;
			titleToFUp += " and bar ";
			titleToFUp += thisbar;
			cout << titleToFUp << "..." << endl;
			cout << "Drawing " << titleToFUp << "..." << endl;
			TString plotToFUp = "HANDToFUp_p";
			plotToFUp += nplane;
			plotToFUp += "_b";
			plotToFUp += thisbar;
			TH1F *HANDToFUp = new TH1F(plotToFUp,titleToFUp,tofBins,tofMin,tofMax);
			TString HANDToFUpString = "NA.n.tof[0]";
			HANDToFUpString += ">>";
			HANDToFUpString += plotToFUp;
//			chainHe->Draw(HANDToFUpString, cuts && firstTrack && thetaCut && "he3R.Spin==1 && he3R.IsSpinValid==1","same");
			chainHe->Draw(HANDToFUpString, cuts && firstTrack && "he3R.Spin==1 && he3R.IsSpinValid==1","same");
			HANDToFUp->SetMinimum(0);
			HANDToFUp->Write();
			HANDToFUp->Draw();


			TString titleToFDown = "ToFDown for Plane ";
			titleToFDown += nplane;
			titleToFDown += " and bar ";
			titleToFDown += thisbar;
			cout << titleToFDown << "..." << endl;
			cout << "Drawing " << titleToFDown << "..." << endl;
			TString plotToFDown = "HANDToFDown_p";
			plotToFDown += nplane;
			plotToFDown += "_b";
			plotToFDown += thisbar;
			TH1F *HANDToFDown = new TH1F(plotToFDown,titleToFDown,tofBins,tofMin,tofMax);
			TString HANDToFDownString = "NA.n.tof[0]";
			HANDToFDownString += ">>";
			HANDToFDownString += plotToFDown;
//			chainHe->Draw(HANDToFDownString, cuts && firstTrack && thetaCut && "he3R.Spin==-1 && he3R.IsSpinValid==1","same");
			chainHe->Draw(HANDToFDownString, cuts && firstTrack && "he3R.Spin==-1 && he3R.IsSpinValid==1","same");
			HANDToFDown->SetMinimum(0);
			HANDToFDown->Write();
			HANDToFDown->Draw();


*/
			handpad02->Update();

			handpad03->cd();
/*			TString titleTDC = "TDC for Plane #";
			titleTDC += nplane;
			titleTDC += ", PMT # ";
			titleTDC += thisbar;
			TString titleHANDright = "Right ";
			titleHANDright += titleTDC;
			if (includeVetos) {titleHANDright += " with vetos";}
			else {titleHANDright += " without vetos";}
			TString spinUpTitleHANDright = "Spin Up Events in ";
			spinUpTitleHANDright += titleHANDright;
			TString spinUpTitleTDC = "Spin Up Events in ";
			spinUpTitleTDC += titleTDC;
			TString spinDownTitleTDC = "Spin Down Events in ";
			spinDownTitleTDC += titleTDC;
			TString spinUpAddTitle = spinUpTitleTDC;
			spinUpAddTitle += " - Add";	
			TString spinUpUnionTitle = spinUpTitleTDC;
			spinUpUnionTitle += " - Union";
			TString spinUpAmUTitle = spinUpTitleTDC;
			spinUpAmUTitle += " - AmU";
			TString spinDownTitleHANDright = "Spin Down Events in ";
			spinDownTitleHANDright += titleHANDright;
			TString plotHANDright = "HANDright_p";
			plotHANDright += nplane;
			plotHANDright += "_b";
			plotHANDright += thisbar;
			TString spinUpPlotHANDright = "spinUp_";
			spinUpPlotHANDright += plotHANDright;
			TString spinDownPlotHANDright = "spinDown_";
			spinDownPlotHANDright += plotHANDright;
			TString plotHANDrightcut = plotHANDright;
			plotHANDrightcut += "_cut";
			TString spinUpPlotHANDrightcut = spinUpPlotHANDright;
			spinUpPlotHANDrightcut += "_cut";
			TString spinDownPlotHANDrightcut = spinDownPlotHANDright;
			spinDownPlotHANDrightcut += "_cut";
			cout << "Drawing " << titleHANDright << "..." << endl;
			TH1F *HANDright = new TH1F(plotHANDright,titleHANDright,TDCbins,TDCmin,TDCmax);
			TH1F *HANDrightUp = new TH1F(spinUpPlotHANDright,spinUpTitleHANDright,TDCbins,TDCmin,TDCmax);
			TH1F *HANDrightDown = new TH1F(spinDownPlotHANDright,spinDownTitleHANDright,TDCbins,TDCmin,TDCmax);
			HANDright->SetMinimum(0);
			HANDrightUp->SetMinimum(0);
			HANDrightDown->SetMinimum(0);
			TH1F *HANDrightcut = new TH1F(plotHANDrightcut,titleHANDright,TDCbins,TDCmin,TDCmax);
			TH1F *HANDrightUpcut = new TH1F(spinUpPlotHANDrightcut,spinUpTitleHANDright,TDCbins,TDCmin,TDCmax);
			TH1F *HANDrightDowncut = new TH1F(spinDownPlotHANDrightcut,spinDownTitleHANDright,TDCbins,TDCmin,TDCmax);
			HANDrightcut->SetMinimum(0);
			HANDrightUpcut->SetMinimum(0);
			HANDrightDowncut->SetMinimum(0);
			TString HANDrightTDC = goodTDCr;
			HANDrightTDC += ">>";
			TString HANDrightTDCUp = HANDrightTDC;
			HANDrightTDCUp += spinUpPlotHANDright;
			TString HANDrightTDCDown = HANDrightTDC;
			HANDrightTDCDown += spinDownPlotHANDright;
			TString HANDrightTDCUpcut = HANDrightTDC;
			HANDrightTDCUpcut += spinUpPlotHANDrightcut;
			TString HANDrightTDCDowncut = HANDrightTDC;
			HANDrightTDCDowncut += spinDownPlotHANDrightcut;
			HANDrightTDC += plotHANDright;
			TString HANDrightTDCcut = goodTDCr;
			HANDrightTDCcut += ">>";
			HANDrightTDCcut += plotHANDrightcut;
			TString spinUpPlotHANDrightcut = spinUpPlotHANDright;
			spinUpPlotHANDrightcut += "_cut";
			TString spinDownPlotHANDrightcut = spinDownPlotHANDright;
			spinDownPlotHANDrightcut += "_cut";
			chainHe->Draw(HANDrightTDC, cuts && vetoTDCs && firstTrack && thetaCut,"");
			chainHe->Draw(HANDrightTDCUp, cuts && vetoTDCs && firstTrack && thetaCut && "he3R.Spin==1" ,"");
			chainHe->Draw(HANDrightTDCDown, cuts && vetoTDCs && firstTrack && thetaCut && "he3R.Spin==-1","");
//			HANDright->Scale(1/(HeChargeScale*Helivetime));
			HANDright->Write();
			HANDrightUp->Write();
			HANDrightDown->Write();
			HANDright->Draw();
			HANDrightUp->Draw();
			HANDrightDown->Draw();
			if (!includeVetos) {chainHe->Draw(HANDrightTDCcut, cuts && firstTrack && goodTDCrightcut && thetaCut,"same");}
			if (!includeVetos) {chainHe->Draw(HANDrightTDCUpcut, cuts && goodTDCrightcut && firstTrack && thetaCut && "he3R.Spin==1","same");}
			if (!includeVetos) {chainHe->Draw(HANDrightTDCDowncut, cuts && goodTDCrightcut && firstTrack && thetaCut && "he3R.Spin==-1","same");}
			if (includeVetos) {chainHe->Draw(HANDrightTDCcut, cuts && vetoTDCs && goodTDCrightcut && firstTrack && thetaCut,"same");}
			if (includeVetos) {chainHe->Draw(HANDrightTDCUpcut, cuts && vetoTDCs && goodTDCrightcut && firstTrack && thetaCut && "he3R.Spin==1","same");}
			if (includeVetos) {chainHe->Draw(HANDrightTDCDowncut, cuts && vetoTDCs && goodTDCrightcut && firstTrack && thetaCut && "he3R.Spin==-1","same");}
			HANDrightcut->SetFillColor(kViolet);
			HANDrightUpcut->SetFillColor(kViolet);
			HANDrightDowncut->SetFillColor(kViolet);
//			HANDrightcut->Scale(1/(HeChargeScale*Helivetime));
			HANDrightcut->Write();
			HANDrightUpcut->Write();
			HANDrightDowncut->Write();
			HANDright->Draw();
			HANDrightcut->Draw("same");
*/
			handpad03->Update();
/*
			HANDrightUpcut->Draw("same");
			HANDrightDowncut->Draw("same");

			// The bit below begins adding of both left and right TDCs and their union
			TString planeAndBar = "_p";
			planeAndBar += nplane;
			planeAndBar += "_b";
			planeAndBar += thisbar;
			TString spinUpPlotHANDbothAdd = "spinUp_HANDbothAdd";
			spinUpPlotHANDbothAdd += planeAndBar;
			TString spinDownPlotHANDbothAdd = "spinDown_HANDbothAdd";
			spinDownPlotHANDbothAdd += planeAndBar;
			TString spinUpPlotHANDbothUnion = "spinUp_HANDbothUnion";
			spinUpPlotHANDbothUnion += planeAndBar;
			TString spinDownPlotHANDbothUnion = "spinDown_HANDbothUnion";
			spinDownPlotHANDbothUnion += planeAndBar;
			TString spinUpPlotHANDbothAmU = "spinUp_HANDbothAmU";
			spinUpPlotHANDbothAmU += planeAndBar;
			TString spinDownPlotHANDbothAmU = "spinDown_HANDbothAmU";
			spinDownPlotHANDbothAmU += planeAndBar;
			TH1F *HANDbothAddUp = new TH1F(spinUpPlotHANDbothAdd,spinUpPlotHANDbothAdd,TDCbins,TDCmin,TDCmax);
			TH1F *HANDbothAddDown = new TH1F(spinDownPlotHANDbothAdd,spinDownPlotHANDbothAdd,TDCbins,TDCmin,TDCmax);
			TH1F *HANDbothUnionUp = new TH1F(spinUpPlotHANDbothUnion,spinUpPlotHANDbothUnion,TDCbins,TDCmin,TDCmax);
			TH1F *HANDbothUnionDown = new TH1F(spinDownPlotHANDbothUnion,spinDownPlotHANDbothUnion,TDCbins,TDCmin,TDCmax);
			TH1F *HANDbothAmUUp = new TH1F(spinUpPlotHANDbothAmU,spinUpPlotHANDbothAmU,TDCbins,TDCmin,TDCmax);
			TH1F *HANDbothAmUDown = new TH1F(spinDownPlotHANDbothAmU,spinDownPlotHANDbothAmU,TDCbins,TDCmin,TDCmax);
			HANDbothAddUp->SetMinimum(0);
			HANDbothAddDown->SetMinimum(0);
			HANDbothUnionUp->SetMinimum(0);
			HANDbothUnionDown->SetMinimum(0);
			HANDbothAmUUp->SetMinimum(0);
			HANDbothAmUDown->SetMinimum(0);
			TString HANDbothTDCUnionUp = "(";
			HANDbothTDCUnionUp += goodTDCr;
			HANDbothTDCUnionUp += "+";
			HANDbothTDCUnionUp += goodTDCl;
			HANDbothTDCUnionUp += ")>>";
			HANDbothTDCUnionUp += spinUpPlotHANDbothUnion;
			TString HANDbothTDCUnionDown = "(";
			HANDbothTDCUnionDown += goodTDCr;
			HANDbothTDCUnionDown += "+";
			HANDbothTDCUnionDown += goodTDCl;
			HANDbothTDCUnionDown += ")>>";
			HANDbothTDCUnionDown += spinDownPlotHANDbothUnion;

			if (!includeVetos) {chainHe->Draw(HANDbothTDCUnionUp, cuts && goodTDCrightcut && goodTDCleftcut && firstTrack && thetaCut && "he3R.Spin==1","same");}
			if (!includeVetos) {chainHe->Draw(HANDbothTDCUnionDown, cuts && goodTDCrightcut && goodTDCleftcut && firstTrack && thetaCut && "he3R.Spin==-1","same");}
			if (!includeVetos) {chainHe->Draw(HANDbothTDCUnionUp, cuts && vetoTDCs && goodTDCrightcut && goodTDCleftcut && firstTrack && thetaCut && "he3R.Spin==1","same");}
			if (!includeVetos) {chainHe->Draw(HANDbothTDCUnionDown, cuts && vetoTDCs && goodTDCrightcut && goodTDCleftcut && firstTrack && thetaCut && "he3R.Spin==-1","same");}
			HANDbothAddUp->Add(HANDleftUpcut);
			HANDbothAddUp->Add(HANDrightUpcut);
			HANDbothAddDown->Add(HANDleftDowncut);
			HANDbothAddDown->Add(HANDrightDowncut);
			HANDbothAmUUp->Add(HANDbothAddUp);
			HANDbothAmUUp->Add(HANDbothUnionUp,-1);
			HANDbothAmUDown->Add(HANDbothAddDown);
			HANDbothAmUDown->Add(HANDbothUnionDown,-1);
			HANDbothAddUp->Write();
			HANDbothAddDown->Write();
			HANDbothUnionUp->Write();
			HANDbothUnionDown->Write();
			HANDbothAmUUp->Write();
			HANDbothAmUDown->Write();
			HANDbothAddUp->Draw("same");
			HANDbothAddDown->Draw("same");
			HANDbothUnionUp->Draw("same");
			HANDbothUnionDown->Draw("same");
			HANDbothAmUUp->Draw("same");
			HANDbothAmUDown->Draw("same");

			// ********************************************************************************
//			// This section below gathers and prints some statistics on the plot
//			double numHANDrightcutEvents = 0;
//			for (int j=0; j<TDCbins; j++){ numHANDrightcutEvents = numHANDrightcutEvents + HANDrightcut->GetBinContent(j);}
//			TString HANDrightFactorsString = "Total Charge for Runs: ";
//			HANDrightFactorsString += HeChargeScale;
//			HANDrightFactorsString += " C";
//			TString HANDrightFactorsString1 = "Total Livetime for Runs: ";
//			HANDrightFactorsString1 += Helivetime;
//			TString HANDrightFactorsString2 = "# of Cut (Purple) Events: ";
//			HANDrightFactorsString2 += numHANDrightcutEvents;
//			HANDrightFactors = new TPaveText(0.11,0.69,0.4,0.89,"NDC");
//			TText *t1 = HANDrightFactors->AddText(HANDrightFactorsString);
//			TText *t2 = HANDrightFactors->AddText(HANDrightFactorsString1);
//			TText *t2 = HANDrightFactors->AddText(HANDrightFactorsString2);
//			HANDrightFactors->Write();
//			// ********************************************************************************
*/
			handpad03->Update();

			handpad04->cd();
			TString goodToFcutstr = "(NA.n.tof[0]>";
			goodToFcutstr += tofCutMin;
			goodToFcutstr += " && NA.n.tof[0]<";
			goodToFcutstr += tofCutMax;
			goodToFcutstr += ")";
			TCut goodToFcut = goodToFcutstr;
/*			cout << "Drawing Target Spin Up vs. xBj..." << endl;
			TString titleSpinUpx = "Target Spin Up vs. xBj for Plane #";
			titleSpinUpx += nplane;
			titleSpinUpx += ", PMT # ";
			titleSpinUpx += thisbar;
			if (includeVetos) {titleSpinUpx += " with vetos";}
			else {titleSpinUpx += " without vetos";}
			TString titleSpinUpxcut = titleSpinUpx;
			titleSpinUpxcut += " with goodTDC cuts";
			cout << "Drawing " << titleSpinUpx << "..." << endl;
			TString plotSpinUpx = "HANDSpinUpx_p";
			plotSpinUpx += nplane;
			plotSpinUpx += "_b";
			plotSpinUpx += thisbar;
			TH1F *HANDSpinUpx = new TH1F(plotSpinUpx,titleSpinUpxcut,nuBins,nuMin,nuMax);
			TString HANDSpinUpxString = "PriKineR.nu";
			HANDSpinUpxString += ">>";
			HANDSpinUpxString += plotSpinUpx;
//			if (includeVetos) {chainHe->Draw(HANDSpinUpxString, cuts && vetoTDCs && goodTDCcut && firstTrack && thetaCut && "he3R.Spin==1","");}
//			if (!includeVetos) {chainHe->Draw(HANDSpinUpxString, cuts && goodTDCcut && firstTrack && thetaCut && "he3R.Spin==1","");}
//			if (includeVetos) {chainHe->Draw(HANDSpinUpxString, cuts && vetoTDCs && goodToFcut && firstTrack && thetaCut && "he3R.Spin==1 && he3R.IsSpinValid==1","");}
			if (includeVetos) {chainHe->Draw(HANDSpinUpxString, cuts && vetoTDCs && goodToFcut && firstTrack && "he3R.Spin==1 && he3R.IsSpinValid==1","");}
//			if (!includeVetos) {chainHe->Draw(HANDSpinUpxString, cuts && goodToFcut && firstTrack && thetaCut && "he3R.Spin==1 && he3R.IsSpinValid==1","");}
			if (!includeVetos) {chainHe->Draw(HANDSpinUpxString, cuts && goodToFcut && firstTrack && "he3R.Spin==1 && he3R.IsSpinValid==1","");}
			HANDSpinUpx->SetMinimum(0);
			HANDSpinUpx->Write();


			cout << "Drawing Theta..." << endl;
			TString titleThetaCut = "Theta for plane ";
			titleThetaCut += nplane;
			titleThetaCut += ", bar ";
			titleThetaCut += thisbar;
			TString plotThetaCut = "th_p";
			plotThetaCut += nplane;
			plotThetaCut += "_b";
			plotThetaCut += thisbar;
			TH1F *HeThetaCut = new TH1F(plotThetaCut,titleThetaCut,60,-0.06,0.06);
			TString plotTh = "ExTgtCor_R.th>>";
			plotTh += plotThetaCut;
//			chainHe->Draw(plotTh, cuts && firstTrack && (goodTDCrightcut || goodTDCleftcut) && thetaCut, "");
			chainHe->Draw(plotTh, cuts && firstTrack && thetaCut, "");
			HeThetaCut->Write();
			HeThetaCut->Draw();
*/			handpad04->Update();

			handpad05->cd();
/*			cout << "Drawing Target Spin Down vs. xBj..." << endl;
			TString titleSpinDownx = "Target Spin Down vs. xBj for Plane #";
			titleSpinDownx += nplane;
			titleSpinDownx += ", PMT # ";
			titleSpinDownx += thisbar;
			if (includeVetos) {titleSpinDownx += " with vetos";}
			else {titleSpinDownx += " without vetos";}
			TString titleSpinDownxcut = titleSpinDownx;
			titleSpinDownxcut += " with goodTDC cuts";
			cout << "Drawing " << titleSpinDownx << "..." << endl;
			TString plotSpinDownx = "HANDSpinDownx_p";
			plotSpinDownx += nplane;
			plotSpinDownx += "_b";
			plotSpinDownx += thisbar;
			TH1F *HANDSpinDownx = new TH1F(plotSpinDownx,titleSpinDownxcut,nuBins,nuMin,nuMax);
			TString HANDSpinDownxString = "PriKineR.nu";
			HANDSpinDownxString += ">>";
			HANDSpinDownxString += plotSpinDownx;
//			if (includeVetos) {chainHe->Draw(HANDSpinDownxString, cuts && vetoTDCs && goodTDCcut && firstTrack && thetaCut && "he3R.Spin==-1","");}
//			if (!includeVetos) {chainHe->Draw(HANDSpinDownxString, cuts && goodTDCcut && firstTrack && thetaCut && "he3R.Spin==-1","");}
//			if (includeVetos) {chainHe->Draw(HANDSpinDownxString, cuts && vetoTDCs && goodToFcut && firstTrack && thetaCut && "he3R.Spin==-1 && he3R.IsSpinValid==1","");}
			if (includeVetos) {chainHe->Draw(HANDSpinDownxString, cuts && vetoTDCs && goodToFcut && firstTrack && "he3R.Spin==-1 && he3R.IsSpinValid==1","");}
//			if (!includeVetos) {chainHe->Draw(HANDSpinDownxString, cuts && goodToFcut && firstTrack && thetaCut && "he3R.Spin==-1 && he3R.IsSpinValid==1","");}
			if (!includeVetos) {chainHe->Draw(HANDSpinDownxString, cuts && goodToFcut && firstTrack && "he3R.Spin==-1 && he3R.IsSpinValid==1","");}
			HANDSpinDownx->SetMinimum(0);
			HANDSpinDownx->Write();
			HANDSpinDownx->Draw();

			TString titlePhiCut = "Phi plane ";
			titlePhiCut += nplane;
			titlePhiCut += ", bar ";
			titlePhiCut += thisbar;
			cout << "Drawing " << titlePhiCut << "..." << endl;
			TString plotPhiCut = "ph_p";
			plotPhiCut += nplane;
			plotPhiCut += "_b";
			plotPhiCut += thisbar;
			TH1F *HePhiCut = new TH1F(plotPhiCut,titlePhiCut,60,-0.027,0.027);
			TString plotPh = "ExTgtCor_R.ph>>";
			plotPh += plotPhiCut;
//			chainHe->Draw(plotPh, cuts && firstTrack && (goodTDCrightcut || goodTDCleftcut) && thetaCut, "");
			chainHe->Draw(plotPh, cuts && firstTrack && thetaCut, "");
			HePhiCut->Write();
			HePhiCut->Draw();
*/
			handpad05->Update();

			handpad06->cd();
/*			cout << "Drawing Total Target Spin Up vs. xBj..." << endl;
//			TString titleTotalSpinUpx = "Total Spin Up vs. xBj";
//			if (includeVetos) {titleTotalSpinUpx += " with vetos";}
//			else {titleTotalSpinUpx += " without vetos";}
//			titleTotalSpinUpx += " with goodTDC cuts";
//			cout << "Drawing " << titleTotalSpinUpx << "..." << endl;
//			TString plotTotalSpinUpx = "HANDTotalSpinUpx";
//			TH1F *HANDTotalSpinUpx = new TH1F(plotTotalSpinUpx,titleTotalSpinUpx,nuBins,nuMin,nuMax);
			HANDTotalSpinUpx->Add(HANDSpinUpx);
			HANDTotalSpinUpx->SetMinimum(0);
			HANDTotalSpinUpx->Write();
			HANDTotalSpinUpx->Draw();

			TString titleThetaPhiCut = "Theta & Phi for Plane ";
			titleThetaPhiCut += nplane;
			titleThetaPhiCut += ", Bar ";
			titleThetaPhiCut += thisbar;
			cout << "Drawing " << titleThetaPhiCut << "..." << endl;
			TString plotThetaPhiCut = "thph_p";
			plotThetaPhiCut += nplane;
			plotThetaPhiCut += "_b";
			plotThetaPhiCut += thisbar;
			TH2F *HeThetaPhiCut = new TH2F(plotThetaPhiCut,titleThetaPhiCut,60,-0.027,0.027,60,-0.06,0.06);
			TString plotThPh = "ExTgtCor_R.th:ExTgtCor_R.ph>>";
			plotThPh += plotThetaPhiCut;
//			chainHe->Draw(plotThPh, cuts && firstTrack && (goodTDCrightcut || goodTDCleftcut) && thetaCut, "COLZ");
			chainHe->Draw(plotThPh, cuts && firstTrack && thetaCut, "COLZ");
			HeThetaPhiCut->Write();
			HeThetaPhiCut->Draw("COLZ");
*/
			handpad06->Update();

			handpad07->cd();
/*			cout << "Drawing Total Target Spin Down vs. xBj..." << endl;
//			TString titleTotalSpinDownx = "Total Spin Down vs. xBj";
//			if (includeVetos) {titleTotalSpinDownx += " with vetos";}
//			else {titleTotalSpinDownx += " without vetos";}
//			titleTotalSpinDownx += " with goodTDC cuts";
//			cout << "Drawing " << titleTotalSpinDownx << "..." << endl;
//			TString plotTotalSpinDownx = "HANDTotalSpinDownx";
//			TH1F *HANDTotalSpinDownx = new TH1F(plotTotalSpinDownx,titleTotalSpinDownx,nuBins,nuMin,nuMax);
			HANDTotalSpinDownx->Add(HANDSpinDownx);
			HANDTotalSpinDownx->SetMinimum(0);
			HANDTotalSpinDownx->Write();
			HANDTotalSpinDownx->Draw();
*/			handpad07->Update();



/*
			TString imageTitle = outputPlotsHere;
			imageTitle += "TDC_plots_for_target_asym_Run_Num_";
			imageTitle += HeRunNumber;
			imageTitle += "-";
			imageTitle += endHeRunNumber;
			imageTitle += "_p";
			imageTitle += nplane;
			imageTitle += "_b";
			if (thisbar < 10) {imageTitle += "0";}
			imageTitle += thisbar;
			if (includeVetos) {imageTitle += "_with_vetos";}
			if (includeAntivetos) {imageTitle += "_with_antivetos";}
			if (antivetosAsVetos && includeAntivetos) {imageTitle += "_as_vetos";}
			imageTitle+= ".png";
			handCanvas->Print(imageTitle);

			TString imageAntivetosTitle = outputPlotsHere;
			imageAntivetosTitle += "antivetos_for_target_asym_for_Run_Num_";
			imageAntivetosTitle += HeRunNumber;
			imageAntivetosTitle += "-";
			imageAntivetosTitle += endHeRunNumber;
			imageAntivetosTitle += "_p";
			imageAntivetosTitle += nplane;
			imageAntivetosTitle += "_b";
			imageAntivetosTitle += thisbar;
			if (includeVetos) {imageAntivetosTitle += "_with_vetos";}
			if (includeAntivetos) {imageAntivetosTitle += "_with_antivetos";}
			if (antivetosAsVetos && includeAntivetos) {imageAntivetosTitle += "_as_vetos";}
			imageAntivetosTitle += ".png";
*/
//			if (includeAntivetos) {hand_draw_antivetos(antiveto1plane, antiveto1bar, antiveto2plane, antiveto2bar, antiveto3plane, antiveto3bar, HeRunNumber, endHeRunNumber, chainHe, TDCbins, TDCmin, TDCmax, cuts, goodTDCcut, vetoTDCs, imageAntivetosTitle, nplane, thisbar, includeVetos, includeAntivetos, antivetosAsVetos, veto1plane, veto1bar, veto2plane, veto2bar, veto3plane, veto3bar, veto4plane, veto4bar, veto5plane, veto5bar, veto6plane, veto6bar, allVetos, allAntivetos);}

// *********************************************************************************************************
// The section below will plot the bars used for vetos for the previous canvas. It will consist of two
// canvases, one without the veto cuts made and one with to show the different.
			TString imageVetosWithoutVetosTitle = outputPlotsHere;
			imageVetosWithoutVetosTitle += "vetos_without_veto_cut_for_target_asym_for_Run_Num_";
			imageVetosWithoutVetosTitle += HeRunNumber;
			imageVetosWithoutVetosTitle += "-";
			imageVetosWithoutVetosTitle += endHeRunNumber;
			imageVetosWithoutVetosTitle += "_p";
			imageVetosWithoutVetosTitle += nplane;
			imageVetosWithoutVetosTitle += "_b";
			imageVetosWithoutVetosTitle += thisbar;
			if (includeVetos) {imageVetosWithoutVetosTitle += "_with_vetos";}
			if (includeAntivetos) {imageVetosWithoutVetosTitle += "_with_antivetos";}
			if (antivetosAsVetos && includeAntivetos) {imageVetosWithoutVetosTitle += "_as_vetos";}
			imageVetosWithoutVetosTitle+= ".png";

			TString imageVetosWithVetosTitle = outputPlotsHere;
			imageVetosWithVetosTitle += "vetos_with_veto_cut_for_target_asym_Run_Num_";
			imageVetosWithVetosTitle += HeRunNumber;
			imageVetosWithVetosTitle += "-";
			imageVetosWithVetosTitle += endHeRunNumber;
			imageVetosWithVetosTitle += "_p";
			imageVetosWithVetosTitle += nplane;
			imageVetosWithVetosTitle += "_b";
			imageVetosWithVetosTitle += thisbar;
			if (includeVetos) {imageVetosWithVetosTitle += "_with_vetos";}
			if (includeAntivetos) {imageVetosWithVetosTitle += "_with_antivetos";}
			if (antivetosAsVetos && includeAntivetos) {imageVetosWithVetosTitle += "_as_vetos";}
			imageVetosWithVetosTitle+= ".png";

//			if (includeVetos) {hand_draw_vetos(veto1plane, veto2plane, veto3plane, veto4plane, veto5plane, veto6plane,veto1bar, veto2bar, veto3bar, veto4bar, veto5bar, veto6bar, imageVetosWithoutVetosTitle, imageVetosWithVetosTitle, HeRunNumber, endHeRunNumber, chainHe, nplane, thisbar, TDCbins, TDCmin, TDCmax, cuts, vetoTDCs, antivetosAsVetos, allVetos, allAntivetos);}

//		if ((nplane==1) && (thisbar==15)) { nplane = 2; thisbar = 7;}
//		if ((nplane==2) && (thisbar==12)) { nplane = 3; thisbar = 6;}
//		if ((nplane==3) && (thisbar==11)) { nplane = 4; thisbar = 3;}
//		if ((nplane==4) && (thisbar==7))  { nplane = 4; thisbar = 99;}

		

		allGoodBarCutsStr += "(((";
		allGoodBarCutsStr += firstTrackString;
//		allGoodBarCutsStr += ") && (";
//		allGoodBarCutsStr += goodTDCleftcutString;
//		allGoodBarCutsStr += " || ";
//		allGoodBarCutsStr += goodTDCrightcutString;	
//		allGoodBarCutsStr += ") && (";
//		allGoodBarCutsStr += thetaCutSt;
		allGoodBarCutsStr += ")";
		if (includeVetos)
		{
		allGoodBarCutsStr += " && ((";
		allGoodBarCutsStr += vetoTDCslSt;
		allGoodBarCutsStr += ") && (";
		allGoodBarCutsStr += vetoTDCsrSt;
		allGoodBarCutsStr += "))";
		}
		allGoodBarCutsStr += "))";
		cout << "nplane: " << nplane << ", endplane: " << endplane-1 << ", thisbar: " << thisbar << ", maxbars = " << thisbar << endl;
		allGoodBarCutsTillNow = allGoodBarCutsStr;
		allGoodBarCutsStr += " || ";
		if (nplane==(endplane-1))
		{
			cout << "Am I here?" << endl;
			if (thisbar==(maxbars-1))
			{
				cout << "Made it here!" << endl;
				allGoodBarCutsStr = allGoodBarCutsTillNow;
			}
		}

		}
	}


	cout << endl << endl << "allGoodBarCutsStr: " << allGoodBarCutsStr << endl << endl;
	TCut allGoodBarCuts = allGoodBarCutsStr;



	TString ToFcutCanvasName = "tofcutcanvas";
	TString ToFcutCanvasTitle = "Time of Flight[0] Cut";
	TCanvas *handCanvas = new TCanvas(ToFcutCanvasName,ToFcutCanvasTitle,1400,770); //x,y
	tofcutpad01 =  new TPad("tofcutpad01","tofcutpad01",0.0000,0.0000,0.3333,1.0000,0,0,0);
	tofcutpad02 =  new TPad("tofcutpad02","tofcutpad02",0.3333,0.0000,0.6666,1.0000,0,0,0);
	tofcutpad03 =  new TPad("tofcutpad03","tofcutpad03",0.6666,0.0000,1.0000,1.0000,0,0,0);
	tofcutpad01->Draw(); tofcutpad02->Draw(); tofcutpad03->Draw();

	tofcutpad01->cd();
	TString titleToFcut = "ToF[0] with all cuts";
	cout << titleToFcut << "..." << endl;
	cout << "Drawing " << titleToFcut << "..." << endl;
	TString plotToFcut = "HANDToFcut";
	TH1F *HANDToFcut = new TH1F(plotToFcut,titleToFcut,tofBins,tofMin,tofMax);
	TString HANDToFcutString = "NA.n.tof[0]";
	HANDToFcutString += ">>";
	HANDToFcutString += plotToFcut;
cout << "Drawing the plot..." << endl;
	chainHe->Draw(HANDToFcutString, cuts && allGoodBarCuts ,"");
//	chainHe->Draw(HANDToFcutString, cuts ,"");
cout << "SetMinimum..." << endl;
	HANDToFcut->SetMinimum(0);
cout << "Write..." << endl;
	HANDToFcut->Write();
cout << "Draw..." << endl;
	HANDToFcut->Draw();
cout << "Update..." << endl;
	tofcutpad01->Update();

	tofcutpad02->cd();
	TString titleToFcutUp = "ToF[0] with all cuts and spin Up";
	cout << titleToFcutUp << "..." << endl;
	cout << "Drawing " << titleToFcutUp << "..." << endl;
	TString plotToFcutUp = "HANDToFcutUp";
	TH1F *HANDToFcutUp = new TH1F(plotToFcutUp,titleToFcutUp,tofBins,tofMin,tofMax);
	TString HANDToFcutUpString = "NA.n.tof[0]";
	HANDToFcutUpString += ">>";
	HANDToFcutUpString += plotToFcutUp;
	chainHe->Draw(HANDToFcutUpString, cuts && allGoodBarCuts && "he3R.Spin==1 && he3R.IsSpinValid==1","");
	HANDToFcutUp->SetMinimum(0);
	HANDToFcutUp->Write();
	HANDToFcutUp->Draw();
	tofcutpad02->Update();

	tofcutpad03->cd();
	TString titleToFcutDown = "ToF[0] with all cuts and spin Down";
	cout << titleToFcutDown << "..." << endl;
	cout << "Drawing " << titleToFcutDown << "..." << endl;
	TString plotToFcutDown = "HANDToFcutDown";
	TH1F *HANDToFcutDown = new TH1F(plotToFcutDown,titleToFcutDown,tofBins,tofMin,tofMax);
	TString HANDToFcutDownString = "NA.n.tof[0]";
	HANDToFcutDownString += ">>";
	HANDToFcutDownString += plotToFcutDown;
	chainHe->Draw(HANDToFcutDownString, cuts && allGoodBarCuts && "he3R.Spin==-1 && he3R.IsSpinValid==1","");
	HANDToFcutDown->SetMinimum(0);
	HANDToFcutDown->Write();
	HANDToFcutDown->Draw();
	tofcutpad03->Update();

/*
	TString canvasTotalSpinTest = "TotalSpinTest";
	TString canvasTitleTotalSpinTest = "HAND - Total Spin (Not Scaled)";
	TCanvas *totalSpinTestCanvas = new TCanvas(canvasTotalSpinTest,canvasTitleTotalSpinTest,1400,770); //x,y
	totalspintestpad01 =  new TPad("totalspintestpad01","totalspintestpad01",0.0000,0.5000,0.5000,1.0000,0,0,0);
	totalspintestpad02 =  new TPad("totalspintestpad02","totalspintestpad02",0.5000,0.5000,1.0000,1.0000,0,0,0);
	totalspintestpad03 =  new TPad("totalspintestpad03","totalspintestpad03",0.0000,0.0000,1.0000,0.5000,0,0,0);
	totalspintestpad01->Draw(); totalspintestpad02->Draw(); totalspintestpad03->Draw();

	totalspintestpad01->cd();
	HANDTotalSpinUpx->SetTitle("Total Spin Up (Not Scaled)");
	HANDTotalSpinUpx->Write();
	HANDTotalSpinUpx->Draw();
	totalspintestpad01->Update();

	totalspintestpad02->cd();
	HANDTotalSpinDownx->SetTitle("Total Spin Down (Not Scaled)");
	HANDTotalSpinDownx->Write();
	HANDTotalSpinDownx->Draw();
	totalspintestpad02->Update();

	totalspintestpad03->cd();
        TF1 *fitasymtest = new TF1("fitasymtest","[0]",nuMin,nuMax);
	HANDAsymTest = HANDTotalSpinUpx->GetAsymmetry(HANDTotalSpinDownx);
	TString AsymTestTitle = "Target Asymmerty with Neutron Cuts vs. xBj for runs ";
	AsymTestTitle += HeRunNumber;
	AsymTestTitle += "-";
	AsymTestTitle += endHeRunNumber;
	HANDAsymTest->SetTitle(AsymTestTitle);
	HANDAsymTest->Write();
	HANDAsymTest->Draw();
        fitasymtest->SetLineColor(kBlue);
        HANDAsymTest->Fit("fitasymtest","R");
	totalspintestpad03->Update();


	TString asymTitle = "Target Asymmetry for Runs ";
	asymTitle += HeRunNumber;
	asymTitle += "-";
	asymTitle += endHeRunNumber;
	TCanvas *asymCanvas = new TCanvas("asymCanvas",asymTitle,1400,770); //x,y
	asymCanvas->cd();
	asymCanvas->SetGrid();
	Double_t x[nuBins], y[nuBins], errorx[nuBins], errory[nuBins];
	double minError;
	double maxError;
	double posStuff;
	double negStuff;
	double UpEvents;
	double DownEvents;
	asymOutFile << "Asymmetry Type:	Target SSA" << endl;
	asymOutFile << "dataset:	" << dataset << endl;
	if (includeVetos) {asymOutFile << "WITH Vetos	";}
	if (!includeVetos) {asymOutFile << "WITHOUT Vetos	";}
	if (backgroundOnly) {asymOutFile << "Background Events";}
	if (!backgroundOnly) {asymOutFile << "Peak Events";}
	asymOutFile << otherSpecs << endl;
	asymOutFile << "Run	" << HeRunNumber << endl;
	cout << "Run	" << HeRunNumber << endl;
	asymOutFile << "xBj	Asymmetry	Stat. Error	# BeamPos Events	BeamPos Charge	PosBeam LT	# Neg Events	BeamNeg Charge	NegBeam LT" << endl;
	cout << "xBj	Asymmetry	Stat. Error	# BeamPos Events	BeamPos Charge	PosBeam LT	# Neg Events	BeamNeg Charge	NegBeam LT" << endl;
	for (int i=0; i<nuBins; i++)
	{	
		UpEvents = HANDTotalSpinUpx->GetBinContent(i);
		DownEvents = HANDTotalSpinDownx->GetBinContent(i);
		x[i] = HANDTotalSpinUpx->GetBinCenter(i);
		if (x[i] != (HANDTotalSpinDownx->GetBinCenter(i))) { cout << endl << endl << "!!!!!!!!!!!!!!!!!!!!!!!!!! STOP! THERE'S A PROBLEM!!!!!!!!!!!!!!!!!!!!!!" << endl << endl << endl;}
		posStuff = UpEvents/((BeamChargeScaleUp * BeamlivetimeUp) + 1e-15);
		negStuff = DownEvents/((BeamChargeScaleDown * BeamlivetimeDown) + 1e-15);
		y[i] = ((posStuff - negStuff)/(posStuff + negStuff + 1e-15));
		errory[i] = 2*(DownEvents*sqrt(UpEvents) + UpEvents*sqrt(DownEvents))/((BeamChargeScaleUp*BeamlivetimeUp)*(BeamChargeScaleDown*BeamlivetimeDown)*pow((UpEvents/(BeamChargeScaleUp*BeamlivetimeUp + 1e-15)) + (DownEvents/(BeamChargeScaleDown*BeamlivetimeDown + 1e-15)),2) + 1e-15);
		if ((UpEvents == 0) || (DownEvents == 0)) { errory[i] = 1;}
		if ((UpEvents == 0) || (DownEvents == 0)) { y[i] = NULL;}
		if (i==0)
		{
			minError = y[i] - 2*errory[i];
			maxError = y[i] + 2*errory[i];
		}
		if ((y[i] - 2*errory[i]) < minError) { minError = y[i] - 2*errory[i];}
		if ((y[i] + 2*errory[i]) > maxError) { maxError = y[i] + 2*errory[i];}
		errorx[i] = ((nuMax - nuMin)/nuBins)/2;
		asymOutFile << x[i] << "	" << y[i] << "	" << errory[i] << "	" << UpEvents << "	" << BeamChargeScaleUp << "	" << BeamlivetimeUp << "	" << DownEvents << "	" << BeamChargeScaleDown << "	" << BeamlivetimeDown << endl;
		cout << x[i] << "	" << y[i] << "	" << errory[i] << "	" << UpEvents << "	" << BeamChargeScaleUp << "	" << BeamlivetimeUp << "	" << DownEvents << "	" << BeamChargeScaleDown << "	" << BeamlivetimeDown << endl;
	}
	asymGraph = new TGraphErrors(nuBins, x, y, errorx, errory);
	asymGraph->SetMarkerStyle(21);
	asymGraph->SetMarkerColor(4);
	asymGraph->SetTitle(asymTitle);
	asymTestHist = new TH2F("asymTestHist",asymTitle,nuBins,nuMin,nuMax,100,minError,maxError);
	asymTestHist->SetStats(kFALSE);
	asymTestHist->Write();
	asymTestHist->Draw();
	cout << "Fit min = " << nuMin << "; Fit max = " << nuMax << endl;
	TF1 *fitAsymGraph = new TF1("fitAsymGraph", "[0]", nuMin, nuMax);
	asymGraph->Draw("P");
	fitAsymGraph->SetLineColor(kBlue);
	asymGraph->Fit("fitAsymGraph","R");
	asymGraph->Write();
	asymCanvas->Update();

	TString TotalAsymOutTitle = outputPlotsHere;
	TotalAsymOutTitle += "target_asymmetry_good_for_Run_Num_";
	TotalAsymOutTitle += HeRunNumber;
	TotalAsymOutTitle += "-";
	TotalAsymOutTitle += endHeRunNumber;
	if (includeVetos) {TotalAsymOutTitle += "_with_vetos";}
	if (includeAntivetos) {TotalAsymOutTitle += "_with_antivetos";}
	if (antivetosAsVetos && includeAntivetos) {TotalAsymOutTitle += "_as_vetos";}
	TotalAsymOutTitle += ".png";
	asymCanvas->Print(TotalAsymOutTitle);



	TString canvasTotalSpin = "TotalSpin";
	TString canvasTitleTotalSpin = "HAND - Total Spin";
	TCanvas *totalSpinCanvas = new TCanvas(canvasTotalSpin,canvasTitleTotalSpin,1400,770); //x,y
	totalspinpad01 =  new TPad("totalspinpad01","totalspinpad01",0.0000,0.5000,0.5000,1.0000,0,0,0);
	totalspinpad02 =  new TPad("totalspinpad02","totalspinpad02",0.5000,0.5000,1.0000,1.0000,0,0,0);
	totalspinpad03 =  new TPad("totalspinpad03","totalspinpad03",0.0000,0.0000,1.0000,0.5000,0,0,0);
	totalspinpad01->Draw(); totalspinpad02->Draw(); totalspinpad03->Draw();

	totalspinpad01->cd();
	cout << "HeChargeScaleUp: " << HeChargeScaleUp << "   HelivetimeUp: " << HelivetimeUp << endl;
	HANDTotalSpinUpx->Scale(1/(BeamChargeScaleUp * BeamlivetimeUp + 1e-20));
	HANDTotalSpinUpx->SetTitle("Total Spin Up (Scaled by Charge, LT)");
	HANDTotalSpinUpx->Write();
	HANDTotalSpinUpx->Draw();
	// ********************************************************************************
	// This section below gathers and prints some statistics on the plot
	TString HANDUpFactorsString = "Total Positive Charge for Runs: ";
	HANDUpFactorsString += BeamChargeScaleUp;
	HANDUpFactorsString += " C";
	TString HANDUpFactorsString1 = "Total Positive Livetime for Runs: ";
	HANDUpFactorsString1 += BeamlivetimeUp;
	HANDUpFactors = new TPaveText(0.11,0.69,0.4,0.89,"NDC");
	TText *t1 = HANDUpFactors->AddText(HANDUpFactorsString);
	TText *t2 = HANDUpFactors->AddText(HANDUpFactorsString1);
	HANDUpFactors->Write();
	HANDUpFactors->Draw("same");
	// ********************************************************************************
	totalspinpad01->Update();

	totalspinpad02->cd();
	cout << "HeChargeScaleDown: " << HeChargeScaleDown << "   HelivetimeDown: " << HelivetimeDown << endl;
	HANDTotalSpinDownx->Scale(1/(BeamChargeScaleDown * BeamlivetimeDown + 1e-20));
	HANDTotalSpinDownx->SetTitle("Total Spin Down (Scaled by Charge, LT)");
	HANDTotalSpinDownx->Write();
	HANDTotalSpinDownx->Draw();
	// ********************************************************************************
	// This section below gathers and prints some statistics on the plot
	TString HANDDownFactorsString = "Total Negative Charge for Runs: ";
	HANDDownFactorsString += BeamChargeScaleDown;
	HANDDownFactorsString += " C";
	TString HANDDownFactorsString1 = "Total Negative Livetime for Runs: ";
	HANDDownFactorsString1 += BeamlivetimeDown;
	HANDDownFactors = new TPaveText(0.11,0.69,0.4,0.89,"NDC");
	TText *t1 = HANDDownFactors->AddText(HANDDownFactorsString);
	TText *t2 = HANDDownFactors->AddText(HANDDownFactorsString1);
	HANDDownFactors->Write();
	HANDDownFactors->Draw("same");
	// ********************************************************************************
	totalspinpad02->Update();

	totalspinpad03->cd();
        TF1 *fitasym = new TF1("fitasym","[0]",nuMin,nuMax);
	HANDAsym = HANDTotalSpinUpx->GetAsymmetry(HANDTotalSpinDownx);
	TString AsymTitle = "Target Asymmerty (Scaled by Charge, LT) with Neutron Cuts vs. xBj for runs ";
	AsymTitle += HeRunNumber;
	AsymTitle += "-";
	AsymTitle += endHeRunNumber;
	HANDAsym->SetTitle(AsymTitle);
	HANDAsym->Write();
	HANDAsym->Draw();
        fitasym->SetLineColor(kBlue);
        HANDAsym->Fit("fitasym","R");
	totalspinpad03->Update();

	TString TotalSpinOutTitle = outputPlotsHere;
	TotalSpinOutTitle += "target_asymmetry_for_Run_Num_";
	TotalSpinOutTitle += HeRunNumber;
	TotalSpinOutTitle += "-";
	TotalSpinOutTitle += endHeRunNumber;
	if (includeVetos) {TotalSpinOutTitle += "_with_vetos";}
	if (includeAntivetos) {TotalSpinOutTitle += "_with_antivetos";}
	if (antivetosAsVetos && includeAntivetos) {TotalSpinOutTitle += "_as_vetos";}
	TotalSpinOutTitle += ".png";
	totalSpinCanvas->Print(TotalSpinOutTitle);


	asymOutFile.close();

	outputRoot1->Close();
*/
	cout << "All done!" << endl;

//	gROOT->ProcessLine(".q");

}







































