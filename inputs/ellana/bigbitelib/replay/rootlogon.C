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
    printf("\nrootlogon.C: Loading BigBite Library...");
    gSystem->Load("libBigBite.so");

    //Load more libs here, if necessary. 
    //Make sure it's in path of $LD_LIBRARY_PATH


    printf("\nrootlogon.C: Adding include directories...");
    gSystem->AddIncludePath("-I$BIGBITELIB");
    gInterpreter->AddIncludePath("$BIGBITELIB/");

    gSystem->AddIncludePath("-I$ANALYZER");
    gInterpreter->AddIncludePath("$ANALYZER/");

    gSystem->AddIncludePath("-I$ANALYZER/src");
    gInterpreter->AddIncludePath("$ANALYZER/src/");

    gSystem->AddIncludePath("-I$ANALYZER/hana_decode");
    gInterpreter->AddIncludePath("$ANALYZER/hana_decode/");

    gSystem->AddIncludePath("-I$ANALYZER/hana_scaler");
    gInterpreter->AddIncludePath("$ANALYZER/hana_scaler/");

    //add extra directory of header file here. 


    char* macros[] =
    {   //list of scripts to load, end with '\0'
        "replay.C+",
        "OpticsCali.C+",
        "OpticsMiss.C+",
		//"Pi0OpticsSel.C+",
        //"HallA_style.cxx",,
        //"AnaShowRun.C",
        //"onlineGUI/online.C+",
        "\0"
    };

    if (*macros[0]!=0)
        cout << "\nrootlogon.C: Loading macro's:" << endl;
    for(UInt_t i=0; *macros[i]!=0; i++) {
        cout << "\t " << macros[i] << endl;
        gROOT->LoadMacro(macros[i]);
    }

    printf("\nrootlogon.C: Done!\n\n");
}

