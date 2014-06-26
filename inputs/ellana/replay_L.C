//////////////////////////////////////////////////////////////////////////
//
//  Left arm detector replay script
//
//////////////////////////////////////////////////////////////////////////
//	
//	Author : Vincent A. Sulkosky & Jin Huang
//
//////////////////////////////////////////////////////////////////////////


#include "def.h"

using namespace std;

void replay_L(Int_t runnumber=0,Int_t all=0,Int_t fstEvt=0,Bool_t QuietRun = kFALSE)
{

  /////////////////////////////////////
  ///    Beams
  ////////////////////////////////////

  cout<<"replay: Adding Idea Beam"<< endl;

  THaApparatus* B = new THaIdealBeam("B","Idea Beam, for Test Only");
  gHaApps->Add( B );
  
  cout<<"replay: Adding L-arm Helicity"<< endl;
  B->AddDetector( new THaADCHelicity("adchel.L","Beam helicity L-arm") );
  B->AddDetector( new THaADCHelicity("adchel2.L","Beam helicity-2 L-arm") );
  B->AddDetector( new THaG0Helicity("g0hel.L","Left arm G0 helicity") );	
  
  cout<<"replay: Adding UnRastered and Rastered Beam ..."<<endl;
  gHaApps->Add(new THaUnRasteredBeam("urb","Unrastered beam"));
  gHaApps->Add(new THaRasteredBeam("rb","Rastered Beam"));


  //////////////////////////////////////////
  ///   Other Modules
  ///////////////////////////////////////////
  
  cout<<"replay: Adding Decoder Data ..."<<endl;
  gHaApps->Add(new THaDecData("DL","Misc. Decoder Data"));



  ////////////////////////////////////////////
  ///    Big Bite
  ///////////////////////////////////////////
  
  THaBigBite* pB=new THaBigBite("BB","BigBite"); 
  pB->AddDetector(new TreeSearch::MWDC("mwdc","MWDC",pB));
  pB->AddDetector(new THaTriggerPlane("tp","Trigger Plane",pB));
  pB->MountOptics(new THaOpticsAnalytical("optics","Analytical Bigbite Optics model",pB,"B"));
  gHaApps->Add(pB);

  ////////////////////////////////////////////
  ///    LHRS
  ///////////////////////////////////////////
  
  cout<<"replay: Adding HRS-L ..."<<endl;
  THaApparatus* HRSL = new THaHRS("L","Left HRS");
  gHaApps->Add( HRSL );
  
  // add detectors that are not in the default config
  HRSL->AddDetector( new THaCherenkov("cer", "Gas Cherenkov counter" ));
   HRSL->AddDetector( new THaCherenkov("a1", "A1 Cherenkov counter" ));
  HRSL->AddDetector( new THaShower("prl1", "Pre-shower pion rej." ));
  HRSL->AddDetector( new THaShower("prl2", "Show pion rej." ));

   cout<<"replay: adding RICH detector ..."<<endl;
   //HRSL->AddDetector( new THaRICH("rich","The RICH")); 
  
  cout<<"replay: adding LHRS track(physics) modules ..."<<endl;
  
  gHaPhysics->Add( new THaGoldenTrack("L.gold","Golden track for LHRS", "L") );
  
  THaPhysicsModule *Rpt_l = new THaReactionPoint(
  						 "ReactPt_L","Reaction vertex for Left","L","B");
gHaPhysics->Add( Rpt_l );
 
//   Correct for using an Extended target
// This needs information about the Point of interaction (hence a THaVertexModule)
  THaPhysicsModule* TgC_l = new THaExtTarCor("ExTgtCor_L",
  					     "Corrected for extended target, HRS-L",
  			     "L","ReactPt_L");
 gHaPhysics->Add( TgC_l );
  
  cout<<"replay: Adding Target ..."<<endl;
  THaHe3Target* pT=new THaHe3Target("he3","Hall A Polarized he3 target");
  gHaApps->Add(pT);
  
  // add scalers
  THaScalerGroup* LeftScalers = new THaScalerGroup("Left");
  gHaScalers->Add(LeftScalers);


  //////////////////////////////////////
  ///    Physics
  /////////////////////////////////////

  cout<<"replay: adding Physics modules ..."<<endl;
  gHaPhysics->Add(new THaPrimaryKine("PriKineL","kinematics of scattering of electron to HRS","L","urb",.939565));
  gHaPhysics->Add(new THaPrimaryKine("PriKineLHe3","kinematics of scattering of electron to HRS","L","urb",3.016*0.931494));

  
  ////////////////////////////////////////
  //    Norm Ana
  ////////////////////////////////////////

  char buff[1000]="";
  sprintf(buff,"./summaryfiles/LNormAna%d.log",runnumber);

  cout<<"replay: Adding NormAna & saving result to "<<buff<<endl;
  NormAna* norm = new NormAna("N","Normalization Analysis",buff,8);
  gHaPhysics->Add(norm);


 ////////////////////////////////////////
  //   Do replay
  ////////////////////////////////////////

  THaAnalyzer* analyzer = THaAnalyzer::GetInstance();
  if( !analyzer ) {
  analyzer = new THaAnalyzer;
  }
  analyzer->EnableBenchmarks();
  analyzer->EnableHelicity();
  analyzer->EnableScalers();


  ReplayCore(
	    runnumber,            //run #
	    all,                  //-1=replay all;0=ask for a number
	    100000,                   //defaut replay event num
	    "%s/e05102_L_%d.root", //output file format
	    "replay_L.odef",	//out define
	    "replay_L.cdef", 	//empty cut define
	    kTRUE,                 	//replay scalar?
	    fstEvt,					//First Event To Replay
		QuietRun				//whether ask user for inputs
	    );
}
