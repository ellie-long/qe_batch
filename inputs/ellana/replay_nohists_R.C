//////////////////////////////////////////////////////////////////////////
//
//  Right arm detector replay script
//
//////////////////////////////////////////////////////////////////////////
//	
//	Author : Vincent A. Sulkosky & Jin Huang
//
//////////////////////////////////////////////////////////////////////////


#include "def.h"

using namespace std;

void replay_nohists_R(Int_t runnumber=0,Int_t all=0,Int_t fstEvt=0,Bool_t QuietRun = kFALSE)

{

  //////////////////////////////////////////
  ///     Beams
  //////////////////////////////////////////

  THaApparatus* B = new THaIdealBeam("B","Idea Beam, for Test Only");
  gHaApps->Add( B );
  
  //cout<<"replay: Adding R-arm Helicity"<< endl;
  B->AddDetector( new THaADCHelicity("adchel.R","Beam helicity R-arm") );
  B->AddDetector( new THaG0Helicity("g0hel.R","Right arm G0 helicity") );	
  
  cout<<"replay: Adding UnRastered and Rastered Beam ..."<<endl;
  gHaApps->Add(new THaUnRasteredBeam("Rurb","Unrastered beam"));
  gHaApps->Add(new THaRasteredBeam("Rrb","Rastered Beam"));

  cout<<"replay: Adding Decoder Data ..."<<endl;
   gHaApps->Add(new THaDecData("D","Misc. Decoder Data"));

   ////////////////////////////////////////////
   ///     RHRS
   ////////////////////////////////////////////
  
  cout<<"replay: Adding HRS-R ..."<<endl;
  THaApparatus* HRSR = new THaHRS("R","Right HRS");
  gHaApps->Add( HRSR );
  
  // add detectors that are not in the default config
  HRSR->AddDetector( new THaCherenkov("cer", "Gas Cherenkov counter" ));
  HRSR->AddDetector( new THaShower("ps", "Pre-shower" ));
  HRSR->AddDetector( new THaShower("sh", "Shower" ));


  // add neutron detector
  THaNA* NA=new THaNA("NA","NeutronDetector"); 
  gHaApps->Add(NA);


  
  cout<<"replay: adding Physics modules ..."<<endl;
  
  gHaPhysics->Add( new THaGoldenTrack("R.gold","Golden track for RHRS", "R") );
  
  THaPhysicsModule *Rpt_r = new THaReactionPoint(
						 "ReactPt_R","Reaction vertex for Right","R","B");
  gHaPhysics->Add( Rpt_r );
  
  // Correct for using an Extended target
  // This needs information about the Point of interaction (hence a THaVertexModule)
  THaPhysicsModule* TgC_r = new THaExtTarCor("ExTgtCor_R",
					     "Corrected for extended target, HRS-R",
					     "R","ReactPt_R");
  gHaPhysics->Add( TgC_r );
  gHaPhysics->Add(new THaPrimaryKine("PriKineR","kinematics of scattering of electron to HRS","R","Rurb",.939565));
  gHaPhysics->Add(new THaPrimaryKine("PriKineRHe3","kinematics of scattering of electron to HRS","R","Rurb",3.016*0.931494));
  
  cout<<"replay: Adding Target ..."<<endl;
  THaHe3Target* pT=new THaHe3Target("he3R","Hall A Polarized he3 target for RHRS DAQ");
  gHaApps->Add(pT);
  
  // add scalers
  cout << "replay: Adding Scalar ..." << endl;
// Note: Elie took out the next two lines. If there's a problem, delete the two
// after the next two lines and uncomment the two lines immediately below this
//  THaScalerGroup* RightScalers = new THaScalerGroup("Right");
//  gHaScalers->Add(RightScalers);
  gHaScalers->Add(new THaScalerGroup("Right"));
  gHaScalers->Add(new THaScalerGroup("evRight")); 
// The two lines above are what I was talking about in previous comment 

  ////////////////////////////////////////
  //    Norm Ana
  ////////////////////////////////////////
  char buff[1000]="";
//  sprintf(buff,"./summaryfiles/RNormAna%d.log",runnumber);
  sprintf(buff,"./RNormAna%d.log",runnumber);

  cout<<"replay: Adding NormAna_R & saving result to "<<buff<<endl;
  NormAna_R* norm = new NormAna_R("N","Normalization Analysis",buff,8);
  cout << endl;
  gHaPhysics->Add(norm);

 
  //   Do replay
  ////////////////////////////////////////
  THaAnalyzer* analyzer = THaAnalyzer::GetInstance();
  if( !analyzer ) {
  analyzer = new THaAnalyzer;
  }
  analyzer->EnableBenchmarks();
  analyzer->EnableHelicity();
  analyzer->EnableScalers();

  if (runnumber<20000)
   analyzer->SetCrateMapFileName("cratemap");
  else if(runnumber>20000)
   analyzer->SetCrateMapFileName("cratemap_R");


  ReplayCore(
	    runnumber,            //run #
	    all,                  //-1=replay all;0=ask for a number
	    100000000000,                   //defaut replay event num
	    "%s/e05102_R_%d.root", //output file format
	    "/w/halla-scifs17exp/e05102/disk1/ellie/batch/inputs/ellana/replay_nohists_R.odef",	//out define
	    "/w/halla-scifs17exp/e05102/disk1/ellie/batch/inputs/ellana/replay_nohists_R.cdef", 	//empty cut define
	    kTRUE,                 	//replay scalar?
	    fstEvt,					//First Event To Replay
		QuietRun				//whether ask user for inputs
	    );

  // cout << endl;
  // cout << "Look at histograms for Right arm" << endl
  //   << "\t online(\"detectorR\"," << runnumber << ")" << endl;
  // cout << "And Neutron Detector.. " << endl
  //      << "\t online(\"detectorND\"," << runnumber << ")" << endl << endl;

  // cout << "Exit ROOT session before performing another analysis:" << endl
  //     << "  .q" << endl << endl;
 analyzer->SetCrateMapFileName("cratemap");
}
