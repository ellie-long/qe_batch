

void neutron_analysis_class::hand_class_draw_tof_nu(TH1F* ToFbasic, TH1F* ToFgoodEventTotal, TH1F* ToFcutTotal, TH1F* ToFupTotal, TH1F* ToFdownTotal, TH1F* nuAllCutsTotal, TH1F* ToFgoodEvent, TH1F* ToFcut, TH1F* ToFup, TH1F* ToFdown, TH1F* nuAllCuts, TH1F* nuUp, TH1F* nuDown, TString outputRootString, int HeRunNumber, int iterator, TH1F* nuUpAllCuts, TH1F* nuDownAllCuts, TH1F* TDC1up, TH1F* TDC1dn, TH1F* TDC2up, TH1F* TDC2dn, TH1F* TDC3up, TH1F* TDC3dn, TH1F* TDC4up, TH1F* TDC4dn)
{
	if (iterator==0){cout << "vvvvvvvvvvvvvvvvvvvvvvv hand_class_draw_tof_nu.h vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl << "Plotting nu bins: ";}
	cout << iterator << " ";
//	cout << "outputRootFile: " << outputRootString << endl;
	int i = iterator;
	TFile *outputRoot = new TFile(outputRootString,"UPDATE");

	gStyle->SetPalette(1);

	// Output the TDC plots
	TDC1up->Write();	
	TDC1dn->Write();	
	TDC2up->Write();	
	TDC2dn->Write();	
	TDC3up->Write();	
	TDC3dn->Write();	
	TDC4up->Write();	
	TDC4dn->Write();

	// The section below plots the ToF and Nu plots
	// **********************************************************************************************
	// Defines Canvas
/*	TString ToFCanvasName;

	ToFCanvasName = "ToFCanvas_bin_";
	ToFCanvasName += i;
	if (i==0) {ToFCanvasName = "ToFCanvas_Total";}
	cout << "Making " << ToFCanvasName << endl;
	TCanvas *ToFCanvas = new TCanvas(ToFCanvasName,ToFCanvasName,1360,768); //x,y
	tofpad1  =  new  TPad("tofpad1","tofpad1",0.0000,0.5000,0.5000,1.0000,0,0,0);
	tofpad2  =  new  TPad("tofpad2","tofpad2",0.5000,0.5000,1.0000,1.0000,0,0,0);
	tofpad3  =  new  TPad("tofpad3","tofpad3",0.0000,0.0000,0.5000,0.5000,0,0,0);
	tofpad4  =  new  TPad("tofpad4","tofpad4",0.5000,0.0000,1.0000,0.5000,0,0,0);
	tofpad1->Draw();tofpad2->Draw(); tofpad3->Draw();tofpad4->Draw();
*/
	// Everything below here makes graphs for each section of the canvas
//	tofpad1->cd();
	nuUpAllCuts->SetFillColor(kViolet);
	nuUpAllCuts->SetMinimum(0);
	nuUpAllCuts->Write();
//	nuUpAllCuts->Draw("same");
	nuDownAllCuts->SetFillColor(kViolet);
	nuDownAllCuts->SetMinimum(0);
	nuDownAllCuts->Write();
//	nuDownAllCuts->Draw("same");
	nuAllCutsTotal->SetFillColor(kWhite);
	nuAllCutsTotal->SetMinimum(0);
//	nuAllCutsTotal->Draw();
	nuAllCutsTotal->Write();
	nuAllCuts->SetFillColor(kViolet);
	nuAllCuts->SetMinimum(0);
	nuAllCuts->Write();
//	nuAllCuts->Draw("same");
//	tofpad1->Update();

//	tofpad2->cd();
	ToFgoodEventTotal->SetFillColor(kWhite);
	ToFgoodEventTotal->SetMinimum(0);
//	ToFgoodEventTotal->Draw();
	ToFgoodEventTotal->Write();
	ToFgoodEvent->SetFillColor(kViolet);
	ToFgoodEvent->SetMinimum(0);
	ToFgoodEvent->Write();
//	ToFgoodEvent->Draw("same");
//	tofpad2->Update();

//	tofpad3->cd();
	ToFupTotal->SetFillColor(kWhite);
	ToFupTotal->SetMinimum(0);
	ToFupTotal->Write();
//	ToFupTotal->Draw();
	ToFup->SetFillColor(kViolet);
	ToFup->SetMinimum(0);
	ToFup->Write();
//	ToFup->Draw("same");
//	tofpad3->Update();

//	tofpad4->cd();
	ToFdownTotal->SetFillColor(kWhite);
	ToFdownTotal->SetMinimum(0);
//	ToFdownTotal->Draw();
	ToFdownTotal->Write();
	ToFdown->SetFillColor(kViolet);
	ToFdown->SetMinimum(0);
	ToFdown->Write();
//	ToFdown->Draw("same");
//	tofpad4->Update();

	if (i==4)
	{
		// The section below plots the nu plots
		// **********************************************************************************************
		// Defines Canvas
/*		TCanvas *nuCanvas = new TCanvas("nuCanvas","nu",1360,768); //x,y
		nupad1  =  new  TPad("nupad1","nupad1",0.0000,0.0000,0.3333,1.0000,0,0,0);
		nupad2  =  new  TPad("nupad2","nupad2",0.3333,0.0000,0.6666,1.0000,0,0,0);
		nupad3  =  new  TPad("nupad2","nupad2",0.6666,0.0000,1.0000,1.0000,0,0,0);
		nupad1->Draw();nupad2->Draw();nupad3->Draw();
*/
		// Everything below here makes graphs for each section of the canvas
//		nupad1->cd();
//		nuAllCutsTotal->Draw();
		nuAllCutsTotal->Write();
//		nupad1->Update();

//		nupad2->cd();
		nuUp->Write();
//		nuUp->Draw();
//		nupad2->Update();

//		nupad3->cd();
		nuDown->Write();
//		nuDown->Draw();
//		nupad3->Update();
	}


	outputRoot->Close();
	if (iterator==4){cout << endl << "^^^^^^^^^^^^^^^^^^^^^^^ hand_class_draw_tof_nu.h ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;}
}
