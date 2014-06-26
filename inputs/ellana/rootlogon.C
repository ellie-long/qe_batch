//////////////////////////////////////////////////////////////////////////
//                                                                          
// rootlogon.C                                                            
//                                                                          
// Load Lib, paths and possible scripts to the analyzer upon start
//                                                                          
//////////////////////////////////////////////////////////////////////////
//	
// Author : Jin Huang <mailto:jinhuang@jlab.org>    Mar 2008
//
//////////////////////////////////////////////////////////////////////////
{
	printf("\nrootlogon.C: Adding include directories...");
	gSystem->AddIncludePath("-I$ANALYZER");
	gSystem->AddIncludePath("-I$ANALYZER/hana_decode");
	gSystem->AddIncludePath("-I$ANALYZER/hana_scaler");
	gSystem->AddIncludePath("-I$ANALYZER/src");
//	gSystem->AddIncludePath("-I$ROOTSYS");
	gInterpreter->AddIncludePath("$ANALYZER");
	gInterpreter->AddIncludePath("$ANALYZER/hana_decode");
	gInterpreter->AddIncludePath("$ANALYZER/hana_scaler");
	gInterpreter->AddIncludePath("$ANALYZER/src");
//	gInterpreter->AddIncludePath("$ROOTSYS/");

	// Line below added by Ellie to fix an error thrown
//	gROOT->GetPluginManager()->AddHandler("TVirtualStreamerInfo","*","TStreamerInfo","RIO","TStreamerInfo()");

	
	printf("\nrootlogon.C: Loading BigBite Library...");
	gSystem->Load("libBigBite.so");

	printf("\nrootlogon.C: Loading HAND Library...");
	gSystem->Load("libHAND.so");
    //gSystem->Load("/usr/lib/gcc-lib/i386-redhat-linux/3.2.3/libg2c.so");

    //Load more libs here, if necessary. 
    //Make sure it's in path of $LD_LIBRARY_PATH

	printf("\nrootlogon.C: Loading BB Normalization Analysis Library...");
	gSystem->Load("libBBNormAna.so");

	printf("\nrootlogon.C: Loading L-HRS Normalization Analysis Library...");
	gSystem->Load("libNormAna.so");
    
	printf("\nrootlogon.C: Loading R-HRS Normalization Analysis Library...");
	gSystem->Load("libNormAna_R.so");

    //add extra directory of header file here. 

 	gSystem->Load("$ROOTSYS/cint/cint/stl/exception");


/*	char* macros[] =
	{   //list of scripts to load, end with "\0"
		"def.h",
		"HallA_style.cxx",
		"AnaShowRun.C",
		"online_C.so",
// 	If there is a problem, uncomment the ReplayCore_C.so and comment out ReplayCore.C
//		"ReplayCore_C.so",
		"ReplayCore.C",
		"replay_L.C",
		"replay_R.C",
// 		"replay_det_L.C",
		"replay_det_R.C",
		"replay_det_BB.C",
//  		"replay_phys_L.C",
		"replay_scalar.C",
		"ScalarStat.C",
		"replay_scalar_BB.C",
//		"lumi_plotsAuto.C",
		"replay_R_src.C",
		"replay_nohists_R.C",
		"replay_nohists_L.C",
		"replay_noHAND_R.C",
		"replay_cosmics.C",
		"replay_neutrons.C",
		"\0"
	};
*/

	char* macros[] =
	{   //list of scripts to load, end with "\0"
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/def.h",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/HallA_style.cxx",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/AnaShowRun.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/online_C.so",
// 	If there is a problem, uncomment the ReplayCore_C.so and comment out ReplayCore.C
//		"ReplayCore_C.so",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/ReplayCore.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_L.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_R.C",
// 		"replay_det_L.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_det_R.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_det_BB.C",
//  		"replay_phys_L.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_scalar.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/ScalarStat.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_scalar_BB.C",
//		"lumi_plotsAuto.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_R_src.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_nohists_R.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_nohists_L.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_noHAND_R.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_cosmics.C",
		".L /w/halla-1/e05102/ellie/batch/inputs/ellana/replay_neutrons.C",
		"\0"
	};

	if (*macros[0]!=0)	cout << "\nrootlogon.C: Loading macro's:" << endl;
	for(UInt_t i=0; *macros[i]!=0; i++) {
		cout << "\t " << macros[i] << endl;
//		gROOT->LoadMacro(macros[i]);
		gROOT->ProcessLine(macros[i]);
	}

	gStyle->SetPalette(1);
	printf("\nrootlogon.C: Done!\n\n"); 

	printf("----------------------------------------------------\n"
			"To Do Shift Worker Replay & Show Data, just call:\n\n"
			"  do_all(<your run number>)\n\n"
			"Please do replay on adaql4 to adaql7.\n"
			"Please start replay as soon as starting a run.\n"
			"----------------------------------------------------\n"
			"https://hallaweb.jlab.org/wiki/index.php/Transversity/Online_Replay\n"
			"----------------------------------------------------\n"
			"\n");
}

