// *****************************************************
//
// This script should automatically make the MyClass.h
// files for a given chain of a run.
//
// Elena Long
// 2011-10-06
//
// *****************************************************

void makeMyClassFiles()
{
	cout << "Running hand_target_asymmetry_vs_nu..." << endl;

	TString otherSpecs = ", No thetacuts on ToF";

	string line = "";
	ifstream runNumberInputFile ("./input.file");
	getline(runNumberInputFile, line);
	int inRunNumber = atoi(line.c_str());
	int HeRunNumber = inRunNumber;
	cout << "HeRunNumber: " << HeRunNumber << endl;

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

	chainHe->MakeClass("MyClass");
	gROOT->ProcessLine(".L neutron_analysis_class.C");
	MyClass m;
	m.Loop();
}
