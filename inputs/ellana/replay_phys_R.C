//////////////////////////////////////////////////////////////////////////
//
// Transversity Physics Replay Script
//
//////////////////////////////////////////////////////////////////////////
//	
// Nov 2008 : Jin Huang : Init the script with ref to detector replays
//
//////////////////////////////////////////////////////////////////////////



#include "def.h"

using namespace std;


void replay_phys_R(Int_t runnumber=0,Int_t all=0,Int_t fstEvt=0)
{


  ////////////////////////////////////////
  //   Beams
  ////////////////////////////////////////

  cout<<"replay: Adding Idea Beam"<< endl;

  THaApparatus* B = new THaIdealBeam("B","Idea Beam, for Test Only");
  gHaApps->Add( B );
  
  cout<<"replay: Adding R-arm Helicity"<< endl;
  B->AddDetector( new THaADCHelicity("adchel.R","Beam helicity R-arm") );
  B->AddDetector( new THaADCHelicity("adchel2.R","Beam helicity-2 R-arm") );
  B->AddDetector( new THaG0Helicity("g0hel.R","Reft arm G0 helicity") );	
    cout<<"replay: Adding UnRastered and Rastered Beam ..."<<endl;
  gHaApps->Add(new THaUnRasteredBeam("urb","Unrastered beam"));
  gHaApps->Add(new THaRasteredBeam("rb","Rastered Beam"));
  
  

  ////////////////////////////////////////
  //   RHRS
  ////////////////////////////////////////

  cout<<"replay: Adding HRS-R ..."<<endl;
  THaApparatus* HRSR = new THaHRS("R","Reft HRS");
  gHaApps->Add( HRSR );
  
  // add R detectors that are not in the default config
  HRSR->AddDetector( new THaCherenkov("cer", "Gas Cherenkov counter" ));
//   HRSR->AddDetector( new THaCherenkov("a1", "A1 Cherenkov counter" ));
  HRSR->AddDetector( new THaShower("prl1", "Pre-shower pion rej." ));
  HRSR->AddDetector( new THaShower("prl2", "Show pion rej." ));

  //cout<<"replay: adding RICH detector ..."<<endl;
  //HRSR->AddDetector( new THaRICH("rich","The RICH")); 
  

  cout<<"replay: adding RHRS track modules ..."<<endl;
  gHaPhysics->Add( new THaGoldenTrack("R.gold","Golden track for RHRS", "R") );

  THaPhysicsModule *Rpt_l = new THaReactionPoint("ReactPt_R","Reaction vertex for Reft","R","B");
  gHaPhysics->Add( Rpt_l );

  // Correct for using an Extended target
  // This needs information about the Point of interaction (hence a THaVertexModule)
  THaPhysicsModule* TgC_l = new THaExtTarCor("ExTgtCor_R","Corrected for extended target, HRS-R","R","ReactPt_R");
  gHaPhysics->Add( TgC_l );

  ////////////////////////////////////////
  //   Other Modules
  ////////////////////////////////////////

  
//   cout<<"replay: Adding Target ..."<<endl;
//   THaHe3Target* pT=new THaHe3Target("he3","Hall A Polarized he3 target");
//   gHaApps->Add(pT);

  cout<<"replay: Adding Decoder Data ..."<<endl;
  gHaApps->Add(new THaDecData("DL","Misc. Decoder Data"));


//   cout<<"replay: Adding A Quick Hack Code to Extract t3[0] ..."<<endl;
//   THaApparatus* DL1 = new THaIdealBeam("DL1","Base Apparatus for extract t3[0]");
//   gHaApps->Add( DL1 );
//   DL1->AddDetector(new THaADCHe3Spin("t3","copy of DL.t3[0], for .odef file",DL1));

  ////////////////////////////////////////
  //   Physics
  ////////////////////////////////////////

  cout<<"replay: adding Physics modules ..."<<endl;
  gHaPhysics->Add(new THaPrimaryKine("PriKineR","kinematics of scattering of electron to HRS","R","urb",.939565));
  gHaPhysics->Add(new THaPrimaryKine("PriKineRHe3","kinematics of scattering of electron to HRS","R","urb",3.016*0.931494));
  
//  THaSecondaryKine *SecKineP=new THaSecondaryKine(
//                "SecKineP","secondary kinematics of scattering proton into RHRS",
//                "ExTgtCor_R","PriKineBB", .938);
//  gHaPhysics->Add(SecKineP);
  
  
  ////////////////////////////////////////
  //   Scalars
  ////////////////////////////////////////
  // add scalers
  
//   gHaScalers->Add(new THaScalerGroup("Reft"));
//   gHaScalers->Add(new THaScalerGroup("bbite"));
//   gHaScalers->Add(new THaScalerGroup("evReft"));
//   gHaScalers->Add(new THaScalerGroup("evbbite"));

  ////////////////////////////////////////
  //   Do replay
  ////////////////////////////////////////

  
  ReplayCore(
	    runnumber,            //run #
	    all,                  //-1=replay all;0=ask for a number
	    100000,                   //defaut replay event num
	    "%s/e05102_phys_R_%d.root", //output file format
	    "replay_phys_R.odef",    	//out define
	    "replay_test.cdef",    	//empty cut define
	    kTRUE,                 	//replay scalar?
	    fstEvt					//First Event To Replay
	    );

}
