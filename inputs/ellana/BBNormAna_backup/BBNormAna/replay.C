//////////////////////////////////////////////////////////////////////////
//
// Hall A analyzer replay script
//
// if there is no rootlogon.C, execute following command in analyzer first
// gSystem->Load("<your lib name>.so");
// gSystem->AddIncludePath("-I<your include path>");
// gInterpreter->AddIncludePath("<your include path>");
//
//////////////////////////////////////////////////////////////////////////
//	
//	Author : Jin Huang (jinhuang@jlab.org)    Aug 2007
//
//	Modify History:
//      Mar 2008    Jin Huang
//          add physics module support
//      Mar 2008    Jin Huang
//          separate two modes: physics replay and detector replay
//          also make it smarter
//      Apr 2008    Jin Huang
//          rootfile overwrite proof
//
//////////////////////////////////////////////////////////////////////////

#define TESTCODE

#include "def.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>



#ifndef __CINT__
//header file for compile

#include "TSystem.h"
#include "TROOT.h"
#include "THaEvent.h"
#include "THaRun.h"
#include "THaAnalyzer.h"
#include "THaTriggerPlane.h"
#include "THaScintPlane.h"

#include "THaBigBiteTpMwdc.h"
#include "THaTriggerPlane.h"
#include "THaScintPlane.h"
#include "MWDC.h"
#include "THaOpticsAnalytical.h"

#include "THaHRS.h"
#include "THaADCHelicity.h"
#include "THaG0Helicity.h"
#include "THaUnRasteredBeam.h"
#include "THaRasteredBeam.h"
#include "THaDecData.h"
#include "THaCherenkov.h"
#include "THaShower.h"
#include "THaGoldenTrack.h"
#include "THaReactionPoint.h"
#include "THaExtTarCor.h"
#include "THaScalerGroup.h"
#include "THaPrimaryKine.h"
#include "THaSecondaryKine.h"
#include "THaIdealBeam.h"
#include "THaNormAna.h"

#include "TTree.h"
#include "TFile.h"
#include "TString.h"
#endif//#ifdef __CINT__



using namespace std;

void replay(Int_t runnumber=0,Int_t all=0,sReplaySetUp ReplaySetUp=DefaultReplay)
{
    //general replay script
    //for detector or physics replay, please use replay_det or physics reply 

    Int_t ReplayMode=ReplaySetUp.ReplayMode;
    char* OutFileFormat=ReplaySetUp.OutFileFormat;
    Int_t DefReplayNum=ReplaySetUp.DefReplayNum;

    cout<<"replay: Init analyzer ..."<<endl;
    THaAnalyzer* analyzer = THaAnalyzer::GetInstance();
    if( analyzer ) {
        analyzer->Close();
    } else {
        analyzer = new THaAnalyzer;
    }


    // step 1: add detectors
    THaBigBite* pB=0;
    if (ReplayMode&(kReplayBigBiteTp+kReplayBigBiteMWDC+kReplayBigBiteOther))
    {
        cout<<"replay: Adding BigBite ..."<<endl;
        pB=new THaBigBite("BB","BigBite"); 
        gHaApps->Add(pB);
    }
    if (ReplayMode&(kReplayBigBiteTp))
        pB->AddDetector(new THaTriggerPlane("tp","Trigger Plane",pB));

    if (ReplayMode&(kReplayBigBiteMWDC))
        pB->AddDetector(new TreeSearch::MWDC("mwdc","MWDC",pB));

    if (ReplayMode&(kReplayBigBiteOther))
        pB->MountOptics(new THaOpticsAnalytical("optics","BigBite Optics Child Class",pB,"B"));

    /*if (ReplayMode&(kReplayBeam))
    {
    cout<<"replay: Adding Beam ..."<<endl;

    THaApparatus* B = new THaIdealBeam("B","Idea Beam, for Test Only");
    gHaApps->Add( B );

    }*/

    if (ReplayMode&(kReplayHRSL))
    {
        THaApparatus* B = new THaIdealBeam("B","Idea Beam, for Test Only");
        gHaApps->Add( B );

        cout<<"replay: Adding L-arm Helicity"<< endl;
        B->AddDetector( new THaADCHelicity("adchel.L","Beam helicity L-arm") );
        B->AddDetector( new THaADCHelicity("adchel2.L","Beam helicity-2 L-arm") );
        //B->AddDetector( new THaG0Helicity("g0hel.L","Left arm G0 helicity") );	

        cout<<"replay: Adding UnRastered and Rastered Beam ..."<<endl;
        gHaApps->Add(new THaUnRasteredBeam("urb","Unrastered beam"));
        gHaApps->Add(new THaRasteredBeam("rb","Rastered Beam"));

        cout<<"replay: Adding Decoder Data ..."<<endl;
        gHaApps->Add(new THaDecData("DL","Misc. Decoder Data"));

        cout<<"replay: Adding HRS-L ..."<<endl;
        THaApparatus* HRSL = new THaHRS("L","Left HRS");
        gHaApps->Add( HRSL );

        // add detectors that are not in the default config
        HRSL->AddDetector( new THaCherenkov("cer", "Gas Cherenkov counter" ));
        HRSL->AddDetector( new THaShower("prl1", "Pre-shower pion rej." ));
        HRSL->AddDetector( new THaShower("prl2", "Show pion rej." ));

        cout<<"replay: adding Physics modules ..."<<endl;

        gHaPhysics->Add( new THaGoldenTrack("L.gold","Golden track for LHRS", "L") );

        THaPhysicsModule *Rpt_l = new THaReactionPoint(
            "ReactPt_L","Reaction vertex for Left","L","B");
        gHaPhysics->Add( Rpt_l );

        // Correct for using an Extended target
        // This needs information about the Point of interaction (hence a THaVertexModule)
        THaPhysicsModule* TgC_l = new THaExtTarCor("ExTgtCor_L",
            "Corrected for extended target, HRS-L",
            "L","ReactPt_L");
        gHaPhysics->Add( TgC_l );
    }

    if (ReplayMode&(kReplayHRSR))
    {
        THaApparatus* B = new THaIdealBeam("B","Idea Beam, for Test Only");
        gHaApps->Add( B );

        cout<<"replay: Adding R-arm Helicity"<< endl;
        B->AddDetector(new THaADCHelicity("adchel.R","Beam helicity R-arm"));
        //B->AddDetector( new THaG0Helicity("g0hel.R","Right arm G0 helicity") );

        cout<<"replay: Adding UnRastered and Rastered Beam ..."<<endl;
        gHaApps->Add(new THaUnRasteredBeam("Rurb","Unrastered beam"));
        gHaApps->Add(new THaRasteredBeam("Rrb","Rastered Beam"));

        cout<<"replay: Adding Decoder Data ..."<<endl;
        gHaApps->Add(new THaDecData("D","Misc. Decoder Data"));
        cout<<"replay: Adding HRS-R ..."<<endl;
        THaApparatus* HRSR = new THaHRS("R","Right HRS");
        gHaApps->Add( HRSR );

        // add detectors that are not in the default config
        HRSR->AddDetector( new THaCherenkov("cer", "Gas Cherenkov counter" ));
        HRSR->AddDetector( new THaShower("ps", "Pre-shower" ));
        HRSR->AddDetector( new THaShower("sh", "Shower" ));

        cout<<"replay: adding Physics modules ..."<<endl;

        gHaPhysics->Add( new THaGoldenTrack("R.gold","Golden track for RHRS", "R") );

        THaPhysicsModule *Rpt_r = new THaReactionPoint(
            "ReactPt_R","Reaction vertex for Left","R","B");
        gHaPhysics->Add( Rpt_r );

        // Correct for using an Extended target
        // This needs information about the Point of interaction (hence a THaVertexModule)
        THaPhysicsModule* TgC_r = new THaExtTarCor("ExTgtCor_R",
            "Corrected for extended target, HRS-R",
            "R","ReactPt_R");
        gHaPhysics->Add( TgC_r );
    }

    //Step 1.5: load Physics modules
    if (ReplayMode&(kReplayPhysics))
    {

        //The CORRECTED Electron kinematics
        THaPrimaryKine *PriKine=new THaPrimaryKine(
            "PriKine","kinematics of scattering of the primary (beam) particle",
            "ExTgtCor_L","B",.938272029);
        gHaPhysics->Add(PriKine);

        if (ReplayMode&(kReplayBigBiteTp+kReplayBigBiteMWDC+kReplayBigBiteOther)){
            THaSecondaryKine *SecKine=new THaSecondaryKine(
                "SecKine","kinematics of scattering of the primary (beam) particle",
                "BB","PriKine",.938272029);
            gHaPhysics->Add(SecKine);
        }

        // add scalers
        THaScalerGroup* LeftScalers = new THaScalerGroup("Left");
        gHaScalers->Add(LeftScalers);
        // Enable scalers
        analyzer->EnableScalers();
    }

    if (ReplayMode&(kReplayPhysicsHRSR))
    {
        //The CORRECTED Electron kinematics
        THaPrimaryKine *PriKine_r=new THaPrimaryKine(
            "PriKine_r","kinematics of scattering of the primary (beam) particle",
            "ExTgtCor_R","B",.938272029);
        gHaPhysics->Add(PriKine_r);

        //THaSecondaryKine *SecKine_r=new THaSecondaryKine(
        //    "SecKine_r","kinematics of scattering of the primary (beam) particle",
        //    "R","PriKine_r",.938272029);
        //gHaPhysics->Add(SecKine_r);

        // add scalers
        THaScalerGroup* RightScalers = new THaScalerGroup("Right");
        gHaScalers->Add(RightScalers);
        // Enable scalers
        analyzer->EnableScalers();
    }

    THaNormAna* norm = new THaNormAna("N","Normalization Analysis"); 
    Int_t evint[10];  // event intervals of stable beam
    evint[0]=4;       // Number of intervals
    evint[1]=450;
    evint[2]=2000;    // beam stable in [450,2000]
    evint[3]=4000;    // [4000,8000].
    evint[4]=8000;
    norm->DoBcmCalib();
    norm->SetEventInt(evint);
    gHaPhysics->Add(norm);


    // step 2: setup run information

    int nrun, nev;
    int found = 0;
    const char** path = 0;
    char filename[300],buf[300];  
    FILE *fd;

    while( found==0 ) {
        if (runnumber<=0)
        {
            cout << "\nreplay: Please enter a Run Number (-1 to exit):";
            cin >> nrun;
            fgets(buf,300,stdin);//get the extra '\n' from stdin
            if( nrun<=0 ) break;
        }
        else 
            nrun=runnumber;

        path=PATHS;

        while ( path && *path ) {
            sprintf(filename,RAW_DATA_FORMAT,*path,nrun);
            cout<<"replay: Try file "<<filename<<endl;
            fd = fopen(filename,"r");
            if (fd != NULL) {
                found = 1;
                cout << "replay: Will analyze file "<<filename<<endl;
                fclose(fd);
                break;
            }
            path++;
        }
        if ( (!path || !*path) && !found ) {
            cout << "replay: File not found. \n";
            if (runnumber>0) runnumber=0;
        }
    }
    if(nrun<=0) return;


    if (all==0)
    {
        cout << "\nreplay: Number of Events to analyze "
            <<" (default=";
        if (DefReplayNum>0)
            cout<<DefReplayNum<<"):";
        else 
            cout<<"replay all):";


        //trick to support blank inputs
        fgets(buf,300,stdin);
        if (sscanf(buf,"%d\n",&nev)<1)
            nev=DefReplayNum;
    }
    else 
        nev=all;


    char outname[300];
    sprintf(outname,OutFileFormat,STD_REPLAY_OUTPUT_DIR,nrun);
    found=0;    

    //rootfile overwrite proof
    while (found==0)
    {
      cout << "replay: Testing file "<<outname<<" for overwrite proof."<<endl;
        fd = fopen(outname,"r");

	if (fd == NULL) {found=1;break;}
        else
        {
            fclose(fd);
            Long64_t NEnt=0;
            TFile *f=new TFile(outname);
            if (f)
            {
                TTree *t=(TTree *)f->Get("T");
                if (t) NEnt=t->GetEntries();
            }
            delete f;
            TString DefOverWriting;
            if (NEnt==DefReplayNum or DefReplayNum<0 or NEnt==0)
	        DefOverWriting="no";
            else DefOverWriting="yes";

            if (NEnt<=0) {
                cout <<endl << "replay: "<<outname
		     <<" is an invalid root file, "
		     <<"or other people is replaying it. ";
            }
	    else{
	      cout << "replay: "<<outname<<", which contains "<<NEnt
		   <<" events, already exists. ";
	    }

	    cout<<"Do you want to overwrite it?"
		   <<"(default="<<DefOverWriting.Data()<<"):";

            //trick to support blank inputs
            fgets(buf,300,stdin);
            TString s(buf);
            s.Chop();
            s.ToLower();
            if (s.IsNull()) s=DefOverWriting;

            if (s=="y" or s=="yes") {found=1;break;}
            else if (s=="n" or s=="no"){
                sprintf(outname,OutFileFormat,
                    CUSTOM_REPLAY_OUTPUT_DIR,nrun);
                cout<<endl
		    <<"replay: please enter the output root file name. "<<endl
		    <<"        leave blank = "<<outname<<endl
		    <<"Root File:";

                //trick to support blank inputs
                fgets(buf,300,stdin);
                if (buf[0]!='\n' and buf[0]!=0)
                    strcpy(outname,buf);
            }
            else {
	      cout<<"replay: " <<s.Data()<<"is not a valid input; Exiting."<<endl;
                return;
            }
        }
    }

    cout<<endl<<"----------------------------------------------"<<endl;
    cout<<"replay: Inputs Summary:"<<endl;
    cout<<"        Raw data: "<<filename<<endl;
    cout<<"        Event   : ";
    if (nev<0) cout<<"all events"<<endl;
    else cout<<"first "<<nev<<" events"<<endl;
    cout<<"        Outputs : "<<outname<<endl;
    cout<<"----------------------------------------------"<<endl<<endl;

    cout<<"replay: Setup run inputs/outputs ..."<<endl;

    analyzer->SetOutFile( outname );
    THaRun run(filename);
    run.SetFirstEvent( 1 );
    if(nev>-1) run.SetLastEvent(nev);

    analyzer->SetOdefFile(ReplaySetUp.OutDefineFile);
    analyzer->SetCutFile(ReplaySetUp.CutDefineFile);  
    char sumname[300];
    sprintf(sumname,SUMMARY_PHYSICS_FORMAT,nrun);
    analyzer->SetSummaryFile(sumname); // optional
    analyzer->SetEvent( new THaEvent );



    // step 3: run it
    cout<<"replay: Start Process ..."<<endl;
    analyzer->Process(run);     // start the actual analysis



    // step 3: clean up
    run.Close();
    gHaApps->Delete();
    gHaPhysics->Delete();
    analyzer->Close();

    cout<<"replay: YOU JUST ANALYZED RUN number "<<nrun<<"."<<endl;
}

/////////////////////////////////////////////////////////////////

void replay_det(Int_t runnumber=0,Int_t all=0)
{
    //detector reply 

    replay(runnumber,all,Det_Replay);
}

/////////////////////////////////////////////////////////////////


void replay_phys(Int_t runnumber=0,Int_t all=0)
{
    //physics reply 

    replay(runnumber,all,Phys_Replay);
}

/////////////////////////////////////////////////////////////////

void replay_phys_L(Int_t runnumber=0,Int_t all=0)
{
    //physics reply , Left HRS only

    replay(runnumber,all,L_HRS_Phys_Replay);
}

/////////////////////////////////////////////////////////////////


void replay_det_L(Int_t runnumber=0,Int_t all=0)
{
    //detector reply, Left HRS only

    replay(runnumber,all,L_HRS_Det_Replay);
}

/////////////////////////////////////////////////////////////////

void replay_phys_R(Int_t runnumber=0,Int_t all=0)
{
    //physics reply , Right HRS only

    replay(runnumber,all,R_HRS_Phys_Replay);
}


/////////////////////////////////////////////////////////////////

void replay_det_R(Int_t runnumber=0,Int_t all=0)
{
    //detector reply, Right HRS only

    replay(runnumber,all,R_HRS_Det_Replay);
}

/////////////////////////////////////////////////////////////////


void replay_ped(Int_t runnumber=0,Int_t all=0)
{
    //pedstal check reply

    replay(runnumber,all,PED_Replay);
}





