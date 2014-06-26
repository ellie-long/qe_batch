// *****************************************************
//
// This script should automatically make the MyClass.h
// files for a given chain of a run.
//
// Elena Long
// 2011-10-06
//
// *****************************************************

void make_target_asymmetry_class_files()
{
	cout << "Running make_target_asymmetry_class_files..." << endl;

//	gROOT->SetStyle("classic");

	TString otherSpecs = ", No thetacuts on ToF";

	string line = "";
	ifstream runNumberInputFile ("./input.file");
	getline(runNumberInputFile, line);
	int inRunNumber = atoi(line.c_str());
	int HeRunNumber = inRunNumber;
	cout << "HeRunNumber: " << HeRunNumber << endl;

	TChain *chainHe = new TChain("T"); 
	TString filenameHe;
	for (int t=0; t<10; t++)
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

//	cout << "Running MakeClass..." << endl;
//	chainHe->MakeClass("MyClass");
	cout << "Running neutron_analysis_class..." << endl;
	chainHe->MakeClass("neutron_analysis_class");
//	chainHe->MakeClass("target_asymmetry_analysis_class");
	cout << "Loading target_asymmetry_analysis_class.*..." << endl;
	gROOT->ProcessLine(".L neutron_analysis_class.C");
	gROOT->ProcessLine(".L neutron_analysis_class.h");
	gROOT->ProcessLine(".L neutron_analysis_class.cxx");
//	cout << "Defining MyClass ..." << endl;
	cout << "Defining neutron_analsis_class ..." << endl;
//	MyClass m;
//	neutron_analysis_class m;
	gROOT->ProcessLine("neutron_analysis_class m");
//	target_asymmetry_analysis_class m;
//	cout << "Running m.Loop()..." << endl;
	cout << "Running m.AsymLoop(1)..." << endl;
	gROOT->ProcessLine("m.AsymLoop(1)");
	cout << "m.AsymLoop(1) ran successfully!" << endl;
/*	cout << "Running m.AsymLoop(2)..." << endl;
	gROOT->ProcessLine("m.AsymLoop(2)");
	cout << "m.AsymLoop(2) ran successfully!" << endl;
	cout << "Running m.AsymLoop(3)..." << endl;
	gROOT->ProcessLine("m.AsymLoop(3)");
	cout << "m.AsymLoop(3) ran successfully!" << endl;
*/


//	TString exitst;
//	cout << "Are you ready to finish?" << endl;
//	cin >> exitst;

	cout << "All done with make_target_asymmetry_class_files!" << endl;
	gROOT->ProcessLine(".q");
	return;
	cout << "Uh-oh? I shouldn't be here..." << endl;
}
