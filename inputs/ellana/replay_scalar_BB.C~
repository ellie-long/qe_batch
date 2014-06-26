//////////////////////////////////////////////////////////////////////////
//
// Hall A analyzer replay script Example
//
//////////////////////////////////////////////////////////////////////////
//	
//	Author : Jin Huang (jinhuang@jlab.org)   May 2008
//
//////////////////////////////////////////////////////////////////////////


#include "def.h"

using namespace std;

void replay_scalar_BB(Int_t runnumber=0,Int_t all=0,Int_t fstEvt=0,Bool_t QuietRun = kFALSE)
{

//   //Add BigBite 
//   THaBigBite* pB=new THaBigBite("BB","BigBite"); 
//   //THaBBTotalShower* ts=new THaBBTotalShower("ts","BigBite total shower");
//   //pB->AddDetector(ts);
//   pB->AddDetector(new TreeSearch::MWDC("mwdc","MWDC",pB));
//   pB->AddDetector( new THaScintPlaneDet( "s", "BB Scintillator",pB ));
//   pB->AddDetector( new THaScintPlaneDet( "sum", "BB Total sum",pB));
//   pB->AddDetector( new THaScintPlaneDet( "psum", "BB Preshower sum",pB));
//   pB->AddDetector( new THaBBTotalShower( "ts", "BB Total shower",pB));
//   pB->AddDetector( new THaCherenkov("cer", "gas Cerenkov counter", pB ));
	// 
	THaApparatus* B = new THaIdealBeam("B","Idea Beam, for Test Only");
	gHaApps->Add( B );
 
	cout<<"replay: Adding BigBite Helicity"<< endl;
	B->AddDetector( new THaADCHelicity("adchel.BB","Beam helicity BB") );
	B->AddDetector( new THaADCHelicity("adchel2.BB","Beam helicity BB") );
//    B->AddDetector( new THaG0Helicity("g0hel.L","Left arm G0 helicity

//   gHaApps->Add(new THaUnRasteredBeam("BBurb","Unrastered beam"));
//   gHaApps->Add(new THaRasteredBeam("BBrb","Rastered Beam"));
//   pB->MountOptics(new THaOpticsAnalytical("optics","Analytical Bigbite Optics model",pB,"BBurb"));
//   gHaPhysics->Add( new THaGoldenTrack("BB.gold","Golden track for Bigbite", "BB") );


  //Decode miscellaneous things
// 	THaApparatus* DECDAT = new THaDecData("DBB","Misc. Decoder Data");
// 	gHaApps->Add( DECDAT );
//   gHaApps->Add(pB);
    
	////////////////////////////////////////
  //   Scalars
	////////////////////////////////////////
  // add scalers

	cout<<"replay: Adding Scalar ..."<<endl;
	gHaScalers->Add(new THaScalerGroup("Left"));
	gHaScalers->Add(new THaScalerGroup("bbite"));

// 	gHaScalers->Add(new THaScalerGroup("evLeft"));
// 	gHaScalers->Add(new THaScalerGroup("evbbite"));


	////////////////////////////////////////
  //   BB Norm Ana
	////////////////////////////////////////
	char buff[1000]="";
	sprintf(buff,"./summaryfiles/BBScalar%d.log",runnumber);

	cout<<"replay: Adding BBNormAna & saving result to "<<buff<<endl;
	BBNormAna* norm = new BBNormAna("N","Normalization Analysis",buff,8);
	gHaPhysics->Add(norm);
 
	////////////////////////////////////////
  //   Do replay
	////////////////////////////////////////
	THaAnalyzer* analyzer = THaAnalyzer::GetInstance();
	if( !analyzer ) {
		analyzer = new THaAnalyzer;
	}
// 	analyzer->EnableBenchmarks();
	analyzer->EnableHelicity();
	analyzer->EnableScalers();
  //analyzer->EnableSlowControl();
	analyzer->SetMarkInterval(20000);


  
	ReplayCore(
			runnumber,            //run #
	all,                  //-1=replay all;0=ask for a number
	1000000,                   //defaut replay event num
	"%s/e06014_scalar_BB_%d.root", //output file format
	"replay_scalar_BB.odef",       //out define
	"replay_scalar_BB.cdef",       //cut define
	true,//Enable Scalar?
	fstEvt,					//First Event To Replay
	QuietRun				//whether ask user for inputs
			  );
}
