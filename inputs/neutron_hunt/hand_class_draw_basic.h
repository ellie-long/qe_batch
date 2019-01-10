// *************************************************************************
//
// This script will be used to define the basic cuts that I've been using
// over and over again with regards to the Hall A Neutron Detector. It 
// should allow me to call this header file and run the basic cuts in one 
// line of code instead of having a big chunk of code in each different file
// 
// To run this, first include the header file:
/*
	#include "hand_class_basic_cuts.h"
*/
//
// Then declare the cut variables:
/*
	TCut isGood; TCut kinematicsGood; TCut eventtypeGood; TCut dpGood; TCut targetGood;
	TCut tracksGood; TCut thphGood; TCut xbjGood; TCut psshGood; TCut cerenkovGood;
	TCut q2nuGood; TCut basicGood; TCut isGoodForAllBasic;
*/
//
// Be sure to also declare these, although they will change depending on Q^2
// and run number (once I get a better handle on the data, I can include these
// variables in this script and define them based just on run number):
/*
	double numin = 0.3;
	double numax = 0.7;
	double q2min = 0.75;
	double q2max = 1.2;
	int bins = 50;
	double xmin = 0.6;
	double xmax = 3.0;
*/ 
// And be sure to define TString imageCutsTitle. This will be different for each 
// file, but an example (to be changed) is below:
/*
        TString imageCutsTitle = "/home/ellie/physics/e05-102/images/plots_for_hand/left_right_position_test/HAND_plots_Run_Num_";
        imageCutsTitle += HeRunNumber;
        imageCutsTitle += "_basic_cuts"; 
        if (includeVetos) imageCutsTitle += "_with_vetos";
        if (includeAntivetos) {imageCutsTitle += "_with_antivetos";} 
        if (antivetosAsVetos && includeAntivetos) {imageCutsTitle += "_as_vetos";}
        imageCutsTitle += ".png";
*/
//
// Include a boolean value to decide whether or not you actually want to
// draw the cuts, or just define them:
/*
	bool drawCuts = true;
*/
// Finally, just run the code:
/*
	hand_basic_cuts(isGood, kinematicsGood, eventtypeGood, dpGood, targetGood, tracksGood, thphGood, xbjGood, psshGood, cerenkovGood, q2nuGood, basicGood, isGoodForAllBasic, imageCutsTitle, HeRunNumber, endHeRunNumber, chainHe, numin, numax, q2min, q2max, bins, xmin, xmax, drawCuts, Q2)
*/
//
// Elena Long
// 2010-12-08
//
// *************************************************************************


//#include "MyClass.h"

//void MyClass::hand_class_draw_basic(TH1F* HedpNoCut, TH1F* HedpCut, TH1F* HeReactZNoCut, TH1F* HeReactZCut, TH2F* HeThetaPhiCut, TH2F* HePsShNoCut, TH2F* histQ2Nu, TH1F* histcerenkov, TH1F* histcerenkovcut, TH2F* HePsShCut, TH1F* histx, TH1F* histxcut, TString outputRootString, int HeRunNumber)
void neutron_analysis_class::hand_class_draw_basic(TH1F* HedpNoCut, TH1F* HedpCut, TH1F* HeReactZNoCut, TH1F* HeReactZCut, TH2F* HeThetaPhiCut, TH2F* HePsShNoCut, TH2F* histQ2Nu, TH1F* histcerenkov, TH1F* histcerenkovcut, TH2F* HePsShCut, TH1F* histx, TH1F* histxcut, TString outputRootString, int HeRunNumber)
{

	cout << "vvvvvvvvvvvvvvvvvvvvvvv hand_class_draw_basic.h vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;

//	cout << "outputRootString: " << outputRootString << endl;
	TFile *outputRoot = new TFile(outputRootString,"UPDATE");

	gStyle->SetPalette(1);

	double thboundlow = -0.055;
	double thboundhigh = 0.055;
//	double thboundlow = -0.000;
//	double thboundhigh = 0.010;
//	double phbound = 0.03;
	double phbound = 0.025;

/*	// The section below plots the basic cuts used throughout the HAND plots
	// **********************************************************************************************
	// Defines Canvas
	TCanvas *cutsCanvas = new TCanvas("cutsCanvas","Cuts",1360,768); //x,y
	cutpad1  =  new  TPad("cutpad1","cutpad1",0.0000,0.5000,0.2500,1.0000,0,0,0);
	cutpad2  =  new  TPad("cutpad2","cutpad2",0.2500,0.5000,0.5000,1.0000,0,0,0);
	cutpad3  =  new  TPad("cutpad3","cutpad3",0.5000,0.5000,0.7500,1.0000,0,0,0);
	cutpad4  =  new  TPad("cutpad4","cutpad4",0.7500,0.5000,1.0000,1.0000,0,0,0);
	cutpad5  =  new  TPad("cutpad5","cutpad5",0.0000,0.0000,0.2500,0.5000,0,0,0);
	cutpad6  =  new  TPad("cutpad6","cutpad6",0.2500,0.0000,0.5000,0.5000,0,0,0);
	cutpad7  =  new  TPad("cutpad7","cutpad7",0.5000,0.0000,0.7500,0.5000,0,0,0);
	cutpad8  =  new  TPad("cutpad8","cutpad8",0.7500,0.0000,1.0000,0.5000,0,0,0);
	cutpad1->Draw();cutpad2->Draw();cutpad3->Draw();cutpad4->Draw();cutpad5->Draw();cutpad6->Draw();cutpad7->Draw();cutpad8->Draw();
*/
	// Everything below here makes graphs for each section of the canvas

//	cutpad1->cd();
	TString titledp = "dp Cut, Run ";
	titledp += HeRunNumber;
	cout << "Drawing " << titledp << "..." << endl;
	HedpNoCut->Write();
//	HedpNoCut->Draw();
	HedpCut->SetLineColor(kBlack);
	HedpCut->SetFillColor(kViolet);
	HedpCut->Write();
//	HedpCut->Draw("same");
//	cutpad1->Update();

//	cutpad2->cd();
	cout << "Drawing Target Cut..." << endl;
	HeReactZNoCut->Write();
//	HeReactZNoCut->Draw();
	HeReactZCut->SetLineColor(kBlack);
	HeReactZCut->SetFillColor(kViolet);
	HeReactZCut->Write();
//	HeReactZCut->Draw("same");
//	cutpad2->Update();

//	cutpad3->cd();
	cout << "Drawing Theta and Phi Cut..." << endl;
	HeThetaPhiCut->Write();
//	HeThetaPhiCut->Draw("COLZ");
	bottom = new TLine(-phbound,thboundlow,phbound,thboundlow);
	top = new TLine(-phbound,thboundhigh,phbound,thboundhigh);
	left = new TLine(-phbound,thboundlow,-phbound,thboundhigh);
	right = new TLine(phbound,thboundlow,phbound,thboundhigh);
	bottom->SetLineColor(kViolet);
	top->SetLineColor(kViolet);
	left->SetLineColor(kViolet);
	right->SetLineColor(kViolet);
	bottom->SetLineWidth(3);
	top->SetLineWidth(3);
	left->SetLineWidth(3);
	right->SetLineWidth(3);
//	bottom->Draw("same");
//	top->Draw("same");
//	left->Draw("same");
//	right->Draw("same");
//	cutpad3->Update();

//	cutpad7->cd();
	cout << "Drawing Preshower/Shower, No Cut..." << endl;
	HePsShNoCut->SetStats(kFALSE);
	HePsShNoCut->Write();
//	HePsShNoCut->Draw("COLZ");
	if ((HeRunNumber>20403) && (HeRunNumber<20408)) {psshcut = new TLine(0,200,450,0);}
	else {psshcut = new TLine(0,900,450,0);}
	psshcut->SetLineColor(kViolet);
	psshcut->SetLineWidth(3);
//	psshcut->Draw("same");
//	cutpad7->Update();

//	cutpad4->cd();
	TString titleQ2Nu = "Q2 and Nu";
	cout << "Drawing " << titleQ2Nu << "..." << endl;
	histQ2Nu->Write();
//	histQ2Nu->Draw("COLZ");
//	cutpad4->Update();

//	cutpad5->cd();
	TString titlecerenkov = "Cerenkov Cut";
	cout << "Drawing " << titlecerenkov << "..." << endl;
	histcerenkov->SetStats(kFALSE);
	histcerenkovcut->SetFillColor(kViolet);
	histcerenkov->Write();
//	histcerenkov->Draw();
	histcerenkovcut->Write();
//	histcerenkovcut->Draw("same");
//	cutpad5->Update();

//	cutpad8->cd();
	cout << "Drawing Preshower/Shower with All Cut..." << endl;
	HePsShCut->SetStats(kFALSE);
	HePsShCut->Write();
//	HePsShCut->Draw("COLZ");
	psshcut->SetLineColor(kViolet);
	psshcut->SetLineWidth(3);
//	psshcut->Draw("same");
//	cutpad8->Update();

//	cutpad6->cd(); 
	TString titlex = "Bjorken x ";
	cout << "Drawing " << titlex << "..." << endl;
	histx->Write();
//	histx->Draw();
	histxcut->SetFillColor(kViolet);
	histxcut->Write();
//	histxcut->Draw("same");
//	cutpad6->Update();

//	cutsCanvas->Print(imageCutsTitle);

	outputRoot->Close();
	cout << "^^^^^^^^^^^^^^^^^^^^^^^ hand_class_draw_basic.h ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}
