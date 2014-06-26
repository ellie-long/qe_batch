///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// THaNeutronDetector                                                           //
//                                                                           //
// A neutron array for BigBite, consisting of 5 plane and a veto.        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "THaNeutronDetector.h"
#include "THaScintillatorPlane.h"
#include "VarType.h"
#include "VarDef.h"
#include "TMath.h"
#include <cstring>
#include "THaNAScintHit.h"
#include "THaNA.h"

#include "THaNDTrack.h"
#include "TClonesArray.h"

#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

ClassImp(THaNeutronDetector)

//_____________________________________________________________________________
THaNeutronDetector::THaNeutronDetector( const char* name, const char* description ) :
  THaNonTrackingDetector(name,description), 
  fPlane1(NULL), fPlane2(NULL), fPlane3(NULL), fPlane4(NULL)
{
  // Constructor. With this method, the subdetectors are created using
  // this detector's prefix followed by "p1...p4", respectively,
  // and variable names like "BB.nd.p1.nhits".

  Setup( name, "p1", "p2", "p3", "p4", description, true );
}

//_____________________________________________________________________________
void THaNeutronDetector::Setup( const char* name,
			    const char* p1_name,
			    const char* p2_name,
			    const char* p3_name,
			    const char* p4_name,
			    const char* description,
			    bool subnames )
{
  // Set up the total shower counter. Called by constructor.

  static const char* const here = "Setup()";
  static const char* const message = 
    "Must construct %s detector with valid name! Object construction failed.";

  // Base class constructor failed?
  if( IsZombie()) return;

  size_t p1, p2, p3, p4;
  if( !p1_name || (p1 = strlen(p1_name)) == 0 ) {
    Error( Here(here), message, "Plane 1" );
    MakeZombie();
    return;
  }
  if( !p2_name || (p2 = strlen(p2_name)) == 0 ) {
    Error( Here(here), message, "Plane 2" );
    MakeZombie();
    return;
  }
  if( !p3_name || (p3 = strlen(p3_name)) == 0 ) {
    Error( Here(here), message, "Plane 3" );
    MakeZombie();
    return;
  }
  if( !p4_name || (p4 = strlen(p4_name)) == 0 ) {
    Error( Here(here), message, "Plane 4" );
    MakeZombie();
    return;
  }

  size_t nlen = strlen(name);
  size_t slen = TMath::Max(p1,p2);
  slen = TMath::Max(slen,p3);
  slen = TMath::Max(slen,p4);
  size_t len = slen;
  if( subnames )
    len += nlen+1;
  char* subname = new char[ len+1 ];
  const char* sname;
  if( subnames ) {
    strcpy( subname, name );
    strcat( subname, "." );
    strcat( subname, p1_name );
    sname = subname;
  } else 
    sname = p1_name;
  
  char* desc = new char[ 50+strlen(description) ];
  if( description && strlen(description)>0 )
    strcpy( desc, description );
  else {
    strcpy( desc, "Neutron Plane 1" );
    SetTitle( desc );
  }
  size_t dlen = strlen(desc);
  strcat( desc, " plane 1 subdetector" );

  fPlane1 = new THaScintillatorPlane( sname, desc );
  if( !fPlane1 || fPlane1->IsZombie() ) {
    MakeZombie();
    goto exit;
  }

  if( subnames )
    strcpy( subname+nlen+1, p2_name );
  else
    sname = p2_name;
  strcpy( desc+dlen, " plane 2 subdetector" );

  fPlane2 = new THaScintillatorPlane( sname, desc );
  if( !fPlane2 && fPlane2->IsZombie() ) {
    MakeZombie();
    goto exit;
  }

  if( subnames )
    strcpy( subname+nlen+1, p3_name );
  else
    sname = p3_name;
  strcpy( desc+dlen, " plane 3 subdetector" );

  fPlane3 = new THaScintillatorPlane( sname, desc );
  if( !fPlane3 && fPlane3->IsZombie() ) {
    MakeZombie();
    goto exit;
  }

  if( subnames )
    strcpy( subname+nlen+1, p4_name );
  else
    sname = p4_name;
  strcpy( desc+dlen, " plane 4 subdetector" );

  fPlane4 = new THaScintillatorPlane( sname, desc );
  if( !fPlane4 && fPlane4->IsZombie() ) {
    MakeZombie();
    goto exit;
  }

 exit:
  delete [] subname;
  delete [] desc;
  return;
  }

//_____________________________________________________________________________
THaNeutronDetector::~THaNeutronDetector()
{
  // Destructor. Remove variables from global list.

  delete fPlane1;
  delete fPlane2;
  delete fPlane3;
  delete fPlane4;
  if( fIsSetup )
    RemoveVariables();
}

//_____________________________________________________________________________
THaDetectorBase::EStatus THaNeutronDetector::Init( const TDatime& run_time )
{
  // Set up neutron detector counter. This function 
  // reads the neturon detector parameters from local database files 
  // (e.g. "db_BB.nd.p1.dat"), then calls Init() for
  // neutron planes and veto subdetectors, respectively.

  if( IsZombie() || !fPlane1 || !fPlane2 || !fPlane3 || !fPlane4 )
    return fStatus = kInitError;

  MakePrefix();

  EStatus status;
  if( (status = THaDetector::Init( run_time )) ||
      (status = fPlane1->Init( run_time )) ||
      (status = fPlane2->Init( run_time )) ||
      (status = fPlane3->Init( run_time )) ||
      (status = fPlane4->Init( run_time )) )
    return fStatus = status;

  // Get minimum angle between tracks depending on plane hit


//   THaNA* app = static_cast<THaNA*>(fApparatus.GetObject());
  THaNA* app = static_cast<THaNA*>(GetApparatus());
  Double_t Dist2trg = app->GetDistance();

  Int_t middleBar = fPlane1->GetNelem()/2;
  fMinAngle[0] = 
    2.*TMath::Abs((fPlane1->GetXBar(middleBar)-fPlane1->GetXBar(middleBar-1))/
	(Dist2trg+fPlane1->GetZBar(middleBar)));

  middleBar = fPlane2->GetNelem()/2;
  fMinAngle[1] = 
    2.*TMath::Abs((fPlane2->GetXBar(middleBar)-fPlane2->GetXBar(middleBar-1))/
	(Dist2trg+fPlane2->GetZBar(middleBar)));

  middleBar = fPlane3->GetNelem()/2;
  fMinAngle[2] = 
    2.*TMath::Abs((fPlane3->GetXBar(middleBar)-fPlane3->GetXBar(middleBar-1))/
	(Dist2trg+fPlane3->GetZBar(middleBar)));

  middleBar = fPlane4->GetNelem()/2;
  fMinAngle[3] = 
    TMath::Abs((fPlane4->GetXBar(middleBar)-fPlane4->GetXBar(middleBar-1))/
	(Dist2trg+fPlane4->GetZBar(middleBar)));


  fNPlanesHit = -1;
  
  return fStatus;
}

//_____________________________________________________________________________
void THaNeutronDetector::Clear(const Option_t* opt)
{

  for (Int_t i=0;i<kMAXTRACKS;i++) {
    fTheta[i] = 100.;
    fPhi[i] = 100.;
    fTOF[i] = 0.;
    fDist[i] = 0;
    fEnergyDeposit[i] = 0.;
    fNHits[i] = 0;
  }
  fNTracks=0;

}

//_____________________________________________________________________________
Int_t THaNeutronDetector::Decode( const THaEvData& evdata )
{
  // Decode neutron detector. Calls Decode() of each plane and veto. 
  // Return the return value of fVeto->Decode().




  if( !IsOK() ) 
    return -1;
  fPlane1->Decode( evdata );
  fPlane2->Decode( evdata );
  fPlane3->Decode( evdata );
  Int_t stat=fPlane4->Decode( evdata );
  return stat;
 

}

//_____________________________________________________________________________
void THaNeutronDetector::SetApparatus( THaApparatus* app )
{
  // Set the apparatus of this detector as well as the subdetectors

  THaDetector::SetApparatus( app );
  fPlane1->SetApparatus( app );
  fPlane2->SetApparatus( app );
  fPlane3->SetApparatus( app );
  fPlane4->SetApparatus( app );
  return;
}

//_____________________________________________________________________________
Int_t THaNeutronDetector::DefineVariables( EMode mode )
{
  // Initialize global variables and lookup table for decoder

  if( mode == kDefine && fIsSetup ) return kOK;
  fIsSetup = ( mode == kDefine );

  // Register variables in global list

  RVarDef vars[] = {
    { "nplaneshit", "Number of Planes hit",  "fNPlanesHit" },
    { 0 }
  };

  return DefineVarsFromList( vars, mode );
}

//_____________________________________________________________________________
//Int_t THaNeutronDetector::AddTrack( THaNDTrack* t ) 
//{
//
//  if (fNTracks >= kMAXTRACKS) 
//    return 1;
//  
//  fNDTracks[fNTracks++] = t;
//  return 0;
//
//}

//_____________________________________________________________________________
Int_t THaNeutronDetector::FineProcess( TClonesArray& tracks )
{

  
  THaScintillatorPlane* planes[4];
  planes[0]= fPlane1;
  planes[1]= fPlane2;
  planes[2]= fPlane3;
  planes[3]= fPlane4;

  //  static const Double_t TIME=4.4;//(TIME in ns)1m thick nd travel time
  
//   THaNA* app = static_cast<THaNA*>(fApparatus.GetObject());
  THaNA* app = static_cast<THaNA*>(GetApparatus());
  Double_t Dist2trg = app->GetDistance();

  Int_t ntracks = 0 ;
  for (Int_t p=0;p<4;p++) {  
    
    Int_t NHits=planes[p]->GetNHits();
    
    for (Int_t i=0;i<NHits;i++){
      
      // Identify the current hit.
      
      THaNAScintHit* hit = planes[p]->GetHit(i);
      
      Int_t pad = hit->GetPaddleNumber();  
      Double_t x=planes[p]->GetXBar(pad); 
      Double_t y=hit->GetHitYPos()/100.;// Now y is in meter
      Double_t z=planes[p]->GetZBar(pad);
      Double_t phi = atan(y/(z+Dist2trg));
      Double_t theta = atan(x/(z+Dist2trg));
      Double_t time= hit->GetHitTOF();
      Double_t dist=sqrt(x*x + y*y + (z+Dist2trg)*(z+Dist2trg));
      hit->SetHitAngles(theta,phi);
      Bool_t assigned = false; 
      
      // Compare the current hit with the previously defined tracks
      // and if the hit is in an existing track, add it to this track.
      
      for (Int_t j=0;j<ntracks;j++) {
	THaNDTrack *t = static_cast<THaNDTrack*>(tracks[j]);
	if(TMath::Abs(t->GetTheta() - theta)<fMinAngle[p]
	   && TMath::Abs(t->GetPhi() - phi)<fMinAngle[p]) { 
	  //	    && TMath::Abs(fNDTracks[j]->GetTOF() - time)<TIME){
	  t->AddHit(hit);
	  //	  cout << "Adding hit at " << theta << " " << phi <<
	  //	    " to track " << j << " at " << t->GetTheta() << " " << t->GetPhi() << endl;
	  assigned=true;
	  break;
	}
      }  
      
      // if the current hit corresponds to no existing track, 
      // create a new track.
      
      if (!assigned) {
// 	THaNDTrack* newNDTrack = 
// 	  new THaNDTrack(phi,theta,time,hit->GetEnergyDeposit(),p,hit->GetPaddleNumber());
// 	AddTrack(newNDTrack);
//	assigned=true;
//	delete newNDTrack;

//	if (fNTracks>=kMAXTRACKS) break;

	new( (tracks)[ntracks++] ) THaNDTrack(phi, theta, time,
				   hit->GetEnergyDeposit(),dist,p,
				   hit->GetPaddleNumber());
	THaNDTrack *t = static_cast<THaNDTrack*>(tracks[ntracks-1]);
	t->AddHit(hit);
	assigned=true;
      }
    }
  }
  
  return ntracks;
}

//_____________________________________________________________________________
Int_t THaNeutronDetector::CoarseProcess( TClonesArray& tracks )
{


  // Scintillator coarse processing.

  // Counts the number of planes hit (note that the logical method 
  // THaScintillatorPlane::IsHit() will return 0 if false and 1 if true).

  fNPlanesHit = fPlane1->IsHit()+fPlane2->IsHit()+
    fPlane3->IsHit()+fPlane4->IsHit();

  fPlane1->CoarseProcess( tracks );
  fPlane2->CoarseProcess( tracks );
  fPlane3->CoarseProcess( tracks );
  fPlane4->CoarseProcess( tracks );
 
  return 0;
}
	

//////////////////////////////////////////////////////////////////////////////
