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

void replay_det_BB(Int_t runnumber=0,Int_t all=0,Int_t fstEvt=0,Bool_t QuietRun = kFALSE)
{

  //Add BigBite 
	THaBigBite* pB=new THaBigBite("BB","BigBite"); 
 	pB->AddDetector(new TreeSearch::MWDC("mwdc","MWDC",pB));
	pB->AddDetector(new THaTriggerPlane("tp","Trigger Plane",pB));
	//pB->MountOptics(new THaOpticsAnalytical("optics","BigBite Optics Child Class",pB,"B"));
	THaApparatus* B = new THaIdealBeam("B","Idea Beam, for Test Only");
 	//gHaApps->Add( B );
 
// 	cout<<"replay: Adding BigBite Helicity"<< endl;
// 	B->AddDetector( new THaADCHelicity("adchel.BB","Beam helicity BB") );
// 	B->AddDetector( new THaADCHelicity("adchel2.BB","Beam helicity BB") );
// 	B->AddDetector( new THaG0Helicity("g0hel.L","Left arm G0 helicity") );

 	//gHaApps->Add(new THaUnRasteredBeam("BBurb","Unrastered beam"));
 	//gHaApps->Add(new THaRasteredBeam("BBrb","Rastered Beam"));
 	pB->MountOptics(new THaOpticsAnalytical("optics","Analytical Bigbite Optics model",pB,"B"));
// 	gHaPhysics->Add( new THaGoldenTrack("BB.gold","Golden track for Bigbite", "BB") );


  //Decode miscellaneous things
	THaApparatus* DECDAT = new THaDecData("DL","Misc. Decoder Data");
	gHaApps->Add( DECDAT );
	gHaApps->Add(pB);
  
  
	////////////////////////////////////////
  //   Physics
	////////////////////////////////////////

// 	cout<<"replay: adding Physics modules ..."<<endl;
// 	gHaPhysics->Add(new THaPrimaryKine("PriKineBB","kinematics of scattering of electron to BB","BB","BBrb",.939565));
// 	gHaPhysics->Add(new THaPrimaryKine("PriKineBBHe3","kinematics of scattering of electron to BB","BB","BBrb",3.016*0.931494));
    
	////////////////////////////////////////
  //   Scalars
	////////////////////////////////////////
  // add scalers

// 	cout<<"replay: Adding Scalar ..."<<endl;
// 	gHaScalers->Add(new THaScalerGroup("Left"));
// 	gHaScalers->Add(new THaScalerGroup("bbite"));

// 	gHaScalers->Add(new THaScalerGroup("evLeft"));
// 	gHaScalers->Add(new THaScalerGroup("evbbite"));


// 	////////////////////////////////////////
//   //   BB Norm Ana
// 	////////////////////////////////////////
// 	char buff[1000]="";
// 	sprintf(buff,"./summaryfiles/BBNormAna%d.log",runnumber);

// 	cout<<"replay: Adding BBNormAna & saving result to "<<buff<<endl;
// 	BBNormAna* norm = new BBNormAna("N","Normalization Analysis",buff,8);
// 	gHaPhysics->Add(norm);
 
	////////////////////////////////////////
  //   Do replay
	////////////////////////////////////////
	THaAnalyzer* analyzer = THaAnalyzer::GetInstance();
	if( !analyzer ) {
		analyzer = new THaAnalyzer;
	}
	analyzer->EnableBenchmarks();
// 	analyzer->EnableHelicity();
// 	analyzer->EnableScalers();
  //analyzer->EnableSlowControl();
  analyzer->SetMarkInterval(1000);


  
	ReplayCore(
			runnumber,            //run #
	all,                  //-1=replay all;0=ask for a number
	50000,                   //defaut replay event num
	"%s/e05102_det_BB_%d.root", //output file format
	"replay_det_BB.odef",       //out define
	"replay_det_BB.cdef",       //cut define
	true,//Enable Scalar?
	fstEvt,					//First Event To Replay
	QuietRun				//whether ask user for inputs
			  );
}
