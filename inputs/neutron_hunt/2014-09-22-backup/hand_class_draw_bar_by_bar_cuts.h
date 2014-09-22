


#include "hand_draw.h"

//void MyClass::hand_class_draw_bar_by_bar_cuts(int HeRunNumber, int nplane, int thisbar, TH1F* HANDleft, TH1F* HANDleftcut, TH1F* HANDright, TH1F* HANDrightcut, TH1F* HeThetaCut, TH1F* HePhiCut, TH2F* HeThetaPhiCut, TString allVetos, TString outputRootString)
void neutron_analysis_class::hand_class_draw_bar_by_bar_cuts(int HeRunNumber, int nplane, int thisbar, TH1F* HANDleft, TH1F* HANDleftcut, TH1F* HANDright, TH1F* HANDrightcut, TH1F* HeThetaCut, TH1F* HePhiCut, TH2F* HeThetaPhiCut, TString allVetos, TString outputRootString)
{
//	cout << "vvvvvvvvvvvvvvvvv hand_class_draw_bar_by_bar_cuts.h vvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
//	cout << "outputRootString: " << outputRootString << endl;
	TFile *outputRoot = new TFile(outputRootString,"UPDATE");
	gStyle->SetPalette(1);
//	cout << "allVetos: " << allVetos << endl;
	TString goodBar = "nd.p";
	goodBar += nplane;
	goodBar += ".";
	goodBar += thisbar;
	goodBar += " ";

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
	handpad02 =  new TPad("handpad02","handpad02",0.1000,0.5000,0.5500,1.0000,0,0,0);
	handpad03 =  new TPad("handpad03","handpad03",0.5500,0.5000,1.0000,1.0000,0,0,0);
	handpad04 =  new TPad("handpad04","handpad04",0.1000,0.0000,0.4000,0.5000,0,0,0);
	handpad05 =  new TPad("handpad05","handpad05",0.4000,0.0000,0.7000,0.5000,0,0,0);
	handpad06 =  new TPad("handpad06","handpad06",0.7000,0.0000,1.0000,0.5000,0,0,0);
	handpad01->Draw(); handpad02->Draw(); handpad03->Draw(); handpad04->Draw(); 
	handpad05->Draw(); handpad06->Draw();

	// This section will run hand_draw.h which will draw the HAND in handpad01.
	handpad01->cd();
	hand_draw(HeRunNumber, HeRunNumber, false, allVetos, goodBar, "");
	handpad01->Update();

	handpad02->cd();
	HANDleft->Write();
	HANDleft->Draw();
	HANDleftcut->SetFillColor(kViolet);
	HANDleftcut->Write();
	HANDleftcut->Draw("same");
	handpad02->Update();

	handpad03->cd();
	HANDright->Write();
	HANDright->Draw();
	HANDrightcut->SetFillColor(kViolet);
	HANDrightcut->Write();
	HANDrightcut->Draw("same");
	handpad03->Update();

	handpad04->cd();
	HeThetaCut->Write();
	HeThetaCut->Draw();
	handpad04->Update();

	handpad05->cd();
	HeThetaPhiCut->Write();
	HeThetaPhiCut->Draw("COLZ");
	handpad05->Update();

	handpad06->cd();
	HePhiCut->Write();
	HePhiCut->Draw();
	handpad06->Update();
	outputRoot->Close();

//	cout << "^^^^^^^^^^^^^^^^^ hand_class_draw_bar_by_bar_cuts.h ^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}
