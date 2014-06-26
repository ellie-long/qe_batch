//*-- Author :    Olivier Gayou  23-Feb-04
// After THaSpectrometer
 
/////////////////////////////////////////////////////////////////////////
//
// THaNA
//
// Abstract base class for an apparatus that is not a spectrometer (ex: neutron
// detector
//
/////////////////////////////////////////////////////////////////////////

#include "THaNA.h"
#include "THaNonTrackingDetector.h"
#include "TClass.h"
#include "TMath.h"
#include "THaTrack.h"
#include "VarDef.h"
#include <cmath>
#include "THaNAScintHit.h"

#include <cstring>
#include <cstdio>
#include <iostream>

#include "THaNeutronDetector.h"
#include "THaNDTrack.h"
#include "THaNDNeutron.h"


using namespace std;

//__________________________________________________________________________
THaNA::THaNA(  const char* name,const char* desc ) :
  THaApparatus( name,desc ), fThetaGeo(0.0), fPhiGeo(0.0), fDistance(0.0), 
  fCoarseDone(kFALSE)
{
  fTracks     = new TClonesArray( "THaNDTrack",   kInitTrackMultiplicity );
  fwovTracks     = new TClonesArray( "THaNDTrack",   kInitTrackMultiplicity );
  fwvTracks     = new TClonesArray( "THaNDTrack",   kInitTrackMultiplicity );
  fTracks     = new TClonesArray( "THaNDTrack",   kInitTrackMultiplicity );
  fNeutrons   = new TClonesArray( "THaNDNeutron", kInitNeutronMultiplicity );
  // Constructor
  // Protected. Can only be called by derived classes.

  SetNeutronVetoTimeLimits(-18.0,22.0);	// Set default (time window) values. Creates veto.
  //SetNeutronVetoTimeLimits(18.0,-22.0);	// This sets no time window. Does not create veto.
  //SetNeutronVetoTimeLimits(-10.0,12.0);	// Set default (small time window) values
  // SetNeutronVetoTimeLimits(-10000.0,10000.0);// This is equivalent to -infinity to +infinity time window.
  Setup( name , desc, "nd", "veto" );
  Clear();

}

//__________________________________________________________________________
THaNA::~THaNA() {

  // This should be uncommented when we figure out when the replay is crashing with it on.
  delete fVeto;
  delete fNeutronDetector;
  delete fTracks;
  delete fwovTracks;
  delete fwvTracks;
  delete fNeutrons;

}

//__________________________________________________________________________

THaAnalysisObject::EStatus THaNA::Init( const TDatime& run_time )
{
  // Default method for initializing an apparatus. 
  // First, call default THaAnalysisObject::Init(), which
  //  - Creates the fPrefix for this apparatus.
  //  - Opens database file and reads database for this apparatus, if custom 
  //    ReadDatabase() defined.
  //  - Sets up global variables for this apparatus via DefineVariables().
  // Then, call Init() for all defined detectors in turn. Pass run_time argument.
  // Return kOK if all detectors initialized correctly, or kInitError
  // if any detector failed to initialize. Init() will be called for
  // all detectors, even if one or more detectors fail.

  if( THaAnalysisObject::Init( run_time ) )
    return fStatus;
  
  fNeutronDetector->Init(run_time);
  fVeto->Init(run_time);
  InitBlockingBars(run_time); // This has problem with ndSim-package. Commenting this works.
  // 
  return fStatus;

}

//_____________________________________________________________________________
THaDetectorBase::EStatus THaNA::InitBlockingBars( const TDatime& run_time )
  // Initialize the lists of bars that constitute the veto for each bar.
  // Must be called after the Neutron Detector and Veto have been inited
{
  // Assume that postions are positions of center of bar or veto
  // Assume that database will be updated to correct positions, including the
  // alternating z position of the veto planes

  THaScintillatorPlane* planes[5];
    
  fPlane1 = fNeutronDetector->GetPlane1();
  fPlane2 = fNeutronDetector->GetPlane2();
  fPlane3 = fNeutronDetector->GetPlane3();
  fPlane4 = fNeutronDetector->GetPlane4();

  planes[0]= fVeto;
  planes[1]= fPlane1;
  planes[2]= fPlane2;
  planes[3]= fPlane3;
  planes[4]= fPlane4;
  Double_t xsizes[]={0.11, 0.1, 0.125, 0.15, 0.25};// height (bar depth normal to beam direction)
  Double_t zsizes[]={0.02, 0.1, 0.1, 0.1, 0.1};// Thickness (bar length parallel to beam direction)

   cout << " " << endl;
   cout << "Veto bar list" << endl;

  for(int p=1;p<=4;p++) {
    Double_t xb_c, zb_c;
    Double_t xv_c, zv_c;
    Double_t xb_size, zb_size;
    Double_t xv_size, zv_size;

    THaScintillatorPlane *plane=planes[p];
    THaScintillatorPlane *veto=planes[p-1];

    zb_size = zsizes[p];// always 0.1 (i. e., 10 cm)
    xb_size = xsizes[p];
    zv_size = zsizes[p-1];
    xv_size = xsizes[p-1];

//     cout<<"test, "<<xb_size<<", "<<xv_size<<", "<< zb_size<<", "<<zv_size<<endl;
    //test, 0.1, 0.11, 0.1, 0.02  // for p=1
    //test, 0.125, 0.1, 0.1, 0.1  // for p=2
    //test, 0.15, 0.125, 0.1, 0.1 // for p=3
    //test, 0.25, 0.15, 0.1, 0.1  // for p=4

    // cout<<"test, "<<xv_size<<", "<<xb_size<<", "<<zv_size<<", "<< zb_size<<endl;
    //test, 0.11, 0.1, 0.02, 0.1  // for p=1
    //test, 0.1, 0.125, 0.1, 0.1  // for p=2
    //test, 0.125, 0.15, 0.1, 0.1 // for p=3
    //test, 0.15, 0.25, 0.1, 0.1  // for p=4

    for(int ib=0;ib<plane->GetNelem();ib++) {// ib is bar number.
      int nblocking_bars = 0;
      int barlist[35];
      xb_c = plane->GetXBar(ib);// x position of a bar starting from top (1st bar)
      zb_c = fDistance + plane->GetZBar(ib);// z postion of a bar (from target) starting from top (1st bar)

//       cout << "Plane: " << p << "  Bar: " << ib << endl;
//       cout<<"test, "<< xb_c<<", "<<zb_c<<", "<<fDistance<<", "<<plane->GetZBar(ib)<<"\n"<<endl;

      if(p==3) {		// Variety of sizes in plane 3
	if(ib<6 || ib >=16) {
	  xb_size=0.15;
	} else if(ib==10 || ib==11) {
	  xb_size=0.125;
	} else {
	  xb_size=0.10;
	}
      }
//       cout << "xb_size=" << xb_size << endl;
      // Get min and max slopes from corners of bar
      Double_t max_slope=-100.0;
      Double_t min_slope=100.0;
      for(int ic_x=-1;ic_x<=1;ic_x += 2) { // Visit four corners // viewed from the side-view of the ND.
	for(int ic_z=-1;ic_z<=1;ic_z += 2) {
	  Double_t slope = (xb_c+ic_x*xb_size/2.0)/(zb_c+ic_z*zb_size/2.0);
// 	  //////////////
//  	  	  if(p==1 && ib==14) {
//  	  	    cout << "test, " << ib << ", " << ic_x << ", " << ic_z << ", " << slope << endl;
//  	  	    cout << xb_c << ", " << ic_x*xb_size/2.0 << ", " << zb_c << ", " << ic_z*zb_size/2.0 
//                        <<",  "<<(xb_c+ic_x*xb_size/2.0)/(zb_c+ic_z*zb_size/2.0)<<"\n"<< endl;
//  	  	  }
// 		  ///////////
	  if(slope>max_slope) max_slope = slope;
	  if(slope<min_slope) min_slope = slope;

	}

      }
//       cout <<"Max/Min, "<<max_slope<<", "<<min_slope<<"\n"<<endl;
//            if(p==1) {
//       	cout << p << " "<< ib<< " Min/Max slope: " << min_slope <<" " << max_slope << endl;
//            }
      for(int iv=0;iv<veto->GetNelem();iv++) {
	xv_c = veto->GetXBar(iv);
	zv_c = fDistance + veto->GetZBar(iv);
	//cout << "IV: " << iv << " " << xv_c << " " << zv_c <<endl;
	if(p==4) {		// Variety of sizes in plane 3
	  if(iv<6 || iv >=16) {
	    xv_size=0.15;
	  } else if(iv==10 || iv==11) {
	    xv_size=0.125;
	  } else {
	    xv_size=0.10;
	  }
	}
	// Compare corners of potential Blocking bar to slope range
	// subtended by the bar.  If any corner is in the range, or if all
	// corners are outside the range, but some are above and below the
	// the range, then this is a blocking bar.
	int blocking=0;
	int nabove=0;
	int nbelow=0;
	for(int ic_x=-1;ic_x<=1;ic_x += 2) { // Visit four corners
	  for(int ic_z=-1;ic_z<=1;ic_z += 2) {
	    Double_t vslope = (xv_c+ic_x*xv_size/2.0)/(zv_c+ic_z*zv_size/2.0);
// 	    	    if(p==1&&ib==14) {
// 	    	      cout << "      " << iv << " " << ic_x << " " << ic_z << " " << vslope << endl;
// 		    }
	    if(vslope<=max_slope && vslope>=min_slope) {
	      blocking = 1;
	    }
	    if(vslope<min_slope) {
	      nbelow++;
	    } else if(vslope>max_slope) {
	      nabove++;
	    }
	  }
	}
	if(nabove>0 && nbelow>0) blocking=1;
// 	cout << "nblocking_bars = " << nblocking_bars << endl;
	if(blocking) barlist[nblocking_bars++]=iv;
// 	cout << "Here" << endl;
      }
//       cout << "AND OUT" << endl;
      // Assume bars are numbered sequentially in order and find minimum and
      // maximum bar numbers
      Int_t min_blockingbar=1000;
      Int_t max_blockingbar=-1;
      for(Int_t i=0;i<nblocking_bars;i++) {
	if(barlist[i]>max_blockingbar) max_blockingbar=barlist[i];
	if(barlist[i]<min_blockingbar) min_blockingbar=barlist[i];
      }
      plane->SetBlockingBarRange(ib, min_blockingbar, max_blockingbar);

      cout << p << " "<< ib<< " " << nblocking_bars << " " << min_blockingbar<< " " << max_blockingbar << endl;
    }
  }// closes for(int p=1;p<=4;p++) {
  cout << " " << endl;
  fStatus = kOK;
  return(fStatus);
}

//____________________________________________________________________________
Int_t THaNA::Decode( const THaEvData& evdata )
{
  // Decode neutron arm. Calls Decode() of fNeutronDetector and fVeto.
  // Return the return value of fNeutronDetector->Decode().

  if( !IsOK() ) 
    return -1;

  Int_t stat=fVeto->Decode( evdata );
  stat= fNeutronDetector->Decode( evdata );
  return stat;
}


//_____________________________________________________________________________
void THaNA::Setup( const char* name,
			    const char* description,
			    const char* ndname,
			    const char* vname)
{
  // Set up the total shower counter. Called by constructor.

  static const char* const here = "Setup()";
  static const char* const message = 
    "Must construct %s detector with valid name! Object construction failed.";

  // Base class constructor failed?
  if( IsZombie()) return;

  size_t t, a;
  if( !ndname || (t = strlen(ndname)) == 0 ) {
    Error( Here(here), message, "Neutron Detector" );
    MakeZombie();
    return;
  }
  if( !vname || (a = strlen(vname)) == 0 ) {
    Error( Here(here), message, "Veto" );
    MakeZombie();
    return;
  }

  size_t slen = TMath::Max(t,a);
  size_t len = slen;
  char* subname = new char[ len+1 ];
  const char* sname;
  sname = ndname;

  char* desc = new char[ 50+strlen(description) ];
  if( description && strlen(description)>0 )
    strcpy( desc, description );
  else {
    strcpy( desc, "Neutron Arm apparatus" );
    SetTitle( desc );
  }
  size_t dlen = strlen(desc);
  strcat( desc, " Neutron Detector" );

  fNeutronDetector = new THaNeutronDetector( sname, desc );
  if( !fNeutronDetector || fNeutronDetector->IsZombie() ) {
    MakeZombie();
    goto exit;
  }

  sname = vname;
  strcpy( desc+dlen, " Veto detector" );

  fVeto = new THaVeto( sname, desc );
  if( !fVeto && fVeto->IsZombie() ) {
    MakeZombie();
    goto exit;
  }

  fNeutronDetector->SetApparatus(this);
  fVeto->SetApparatus(this);

 exit:
  delete [] subname;
  delete [] desc;
  return;
}

//_____________________________________________________________________________
void THaNA::Clear( Option_t* opt )
{
  // Clear the spectrometer data for next event.

  THaApparatus::Clear(opt);
  fCoarseDone = kFALSE;

  fNTracks = fNwvTracks = fNwovTracks = 0;

  for (Int_t i=0;i<kMAXTRACKS;i++) {
    fLeftIsHit[i] = 0;
    fRightIsHit[i] = 0;
  }
  
  fNNeutrons = 0;

  fNeutronDetector->Clear(opt);
  fNeutrons->Clear("C");
  fTracks->Clear("C");
  fwovTracks->Clear("C");
  fwvTracks->Clear("C");

}

//_____________________________________________________________________________
Int_t THaNA::CoarseProcess()
{
  // The Coarse processing step of Reconstruct is a separate callable
  // routine so tests can be done after this stage.
  // This code is called automatically by Reconstruct if not
  // explicitly called earlier.
  // All detectors are assumed to be non-tracking detectors.



//   TIter next( fDetectors );

//   next.Reset();
//   while( THaNonTrackingDetector* theDetector = static_cast<THaNonTrackingDetector*>( 
// next() )) {
// #ifdef WITH_DEBUG
//     if( fDebug>0 ) cout << "Call CoarseProcess() for " 
// 			<< theDetector->GetName() << "... ";
// #endif
//     theDetector->CoarseProcess( *fTracks );


#ifdef WITH_DEBUG
  if( fDebug>0 ) cout << "Call CoarseProcess() for NeutronDetector ... ";
#endif

  fNeutronDetector->CoarseProcess( *fTracks ); 

#ifdef WITH_DEBUG
    if( fDebug>0 ) cout << "done.\n";
    if( fDebug>0 ) cout << "Call CoarseProcess() for Veto ... ";
#endif

  fVeto->CoarseProcess( *fTracks );

#ifdef WITH_DEBUG
    if( fDebug>0 ) cout << "done.\n";
#endif

  fCoarseDone = kTRUE;
  return 0;
}

//_____________________________________________________________________________
Int_t THaNA::NeutronProcess()
{
  // Loop over all the hits and identify those that
  // meet the neutron criteria.

  THaScintillatorPlane* planes[5];
 
    
  planes[0]= fVeto;
  planes[1]= fPlane1;
  planes[2]= fPlane2;
  planes[3]= fPlane3;
  planes[4]= fPlane4;


  fNNeutrons = 0;
  for (Int_t p=1;p<=4;p++) {

    Int_t NHits=planes[p]->GetNHits();

    for (Int_t i=0;i<NHits;i++){

      // Identify the current hit.
      
      THaNAScintHit* hit = planes[p]->GetHit(i);

      Int_t pad = hit->GetPaddleNumber(); 

      //////////// Get distance of the hit position from the target.///////////
      Double_t x=planes[p]->GetXBar(pad); 
       Double_t y=hit->GetHitYPos()/100.;
      Double_t z=planes[p]->GetZBar(pad);
      Double_t Dist2trg=fDistance;
      Double_t dist=sqrt(x*x + y*y + (z+Dist2trg)*(z+Dist2trg));
      ///////////////////////////////////distance calculation finished//////////


      Double_t time= hit->GetHitTOF();
      Bool_t vetoed = false;

      Int_t min_blockingbar=planes[p]->GetBlockingBarMin(pad);
      Int_t max_blockingbar=planes[p]->GetBlockingBarMax(pad);
      // Loop over all hits in "veto" plane
      //cout << "Plane " << p << endl;
      Int_t NVHits=planes[p-1]->GetNHits();
      //      if(p==1) printf("HIT: %d %d %f   %d Veto Hits\n",p,pad,time,NVHits);
      for(Int_t iv=0;iv<NVHits;iv++) {
	THaNAScintHit* hitv = planes[p-1]->GetHit(iv);
      
	Int_t padv = hitv->GetPaddleNumber();
	//if(p==1)printf("      %d %d %f\n",p-1,padv,hitv->GetHitTOF());
	if(padv>=min_blockingbar && padv<=max_blockingbar) {
	  Double_t timev= hitv->GetHitTOF();

	  //	  cout<<VetoTimeMax<<",  "<<VetoTimeMin<<"\n"<<endl;

	  //	  if(p==1)printf("VETO: %d %d %f\n",p-1,padv,timev);
	  if((timev-time) < VetoTimeMax && (timev-time) > VetoTimeMin) {
	    vetoed = true;
	    break;
	  }
	}
      }
	
      if(!vetoed) {
	new( (*fNeutrons)[fNNeutrons++] ) THaNDNeutron(hit->GetHitPhi(),
						       hit->GetHitTheta(),
						       time,
						       hit->GetEnergyDeposit(),
						       dist, p-1, pad, hit);
      }
    }
  }
  return fNNeutrons;
}


//_____________________________________________________________________________
Int_t THaNA::AddwvTrack( THaNDTrack* t ) 
{

  if (fNwvTracks >= kMAXTRACKS) 
    return 1;
  
  fNDwvTracks[fNwvTracks++] = t;
  return 0;

}

//_____________________________________________________________________________
Int_t THaNA::AddwovTrack( THaNDTrack* t ) 
{

  if (fNwovTracks >= kMAXTRACKS) 
    return 1;
  
  fNDwovTracks[fNwovTracks++] = t;
  return 0;

}

//_____________________________________________________________________________
Int_t THaNA::Reconstruct()
{

  if( !fCoarseDone ) CoarseReconstruct();
  
#ifdef WITH_DEBUG
  if( fDebug>0 ) cout << "Call FineProcess() for NeutronDetector ... ";
#endif

  fNTracks =  fNeutronDetector->FineProcess( *fTracks ); 

  if(fNTracks>kMAXTRACKS) fNTracks=kMAXTRACKS;
  for (Int_t itrack=0;itrack<fNTracks;itrack++) {
    //    cout << " Track = " << itrack << endl;

    THaNDTrack* theTrack = static_cast<THaNDTrack*>((*fTracks)[itrack]);
    
    Bool_t charged = false;
    
    for (Int_t iveto=0;iveto<fVeto->GetNelem();iveto++) {
      
      Bool_t vetohit=false;
      if (theTrack->GetPhi()>fVeto->GetPosRegionLimit() &&
	  fVeto->GetLeftIsHit(iveto)) vetohit=true;
      if (theTrack->GetPhi()<fVeto->GetNegRegionLimit() &&
	  fVeto->GetRightIsHit(iveto)) vetohit=true;

      Double_t xveto = fVeto->GetXBar(iveto);
      Double_t zveto = fDistance+fVeto->GetZBar(iveto);
      Double_t thveto = atan(xveto/zveto);
      if (abs(theTrack->GetTheta()-thveto)<fVeto->GetMinAngle() &&
	  vetohit) {
	
	fLeftIsHit[fNwvTracks]=0;
	fRightIsHit[fNwvTracks]=0;

	charged=true;
	if (fVeto->GetLeftIsHit(iveto)) { fLeftIsHit[fNwvTracks]=1; }
	if (fVeto->GetRightIsHit(iveto)){ fRightIsHit[fNwvTracks]=1;}

	new ((*fwvTracks)[fNwvTracks++]) THaNDTrack(*theTrack);
	break;
      }
      
      
    }
    
    if (!charged) {
      new ((*fwovTracks)[fNwovTracks++]) THaNDTrack(*theTrack);
    }

   }

  fNNeutrons = NeutronProcess();



#ifdef WITH_DEBUG
  if( fDebug>0 ) cout << "done.\n";
  if( fDebug>0 ) cout << "Call FineProcess() for Veto ... ";
#endif
  
  
#ifdef WITH_DEBUG
  if( fDebug>0 ) cout << "done.\n";
#endif
    
  return 0;
}

//_____________________________________________________________________________
Int_t THaNA::ReadRunDatabase( const TDatime& date )
{
  // Query the run database for parameters specific to this apparatus
  // (central angles, distance,...)

  
  Int_t err = THaApparatus::ReadRunDatabase( date );
  if( err ) return err;

  FILE* file = OpenRunDBFile( date );
  if( !file ) return kFileError;

  static const Double_t degrad = TMath::Pi()/180.0;
  Double_t th = 0.0, ph = 0.0;

  const TagDef tags[] = { 
    { "theta",    &th }, 
    { "distance", &fDistance },
    { 0 }
  };
  err = LoadDB( file, date, tags, fPrefix );
  if( err ) {    
    if( err>0 )
      Error( Here("ReadRunDatabase()"), "Required tag %s%s missing in the "
	     "run database.\nSpectrometer initialization failed.",
	     fPrefix, tags[err-1].name );
    fclose(file);
    return kInitError;
  }

  // Compute central angles in spherical coordinates and save trig. values
  // of angles for later use.
  // Note: negative theta corresponds to beam RIGHT.
  // phi should be close to zero unless this is a true out-of-plane spectrometer.
  fThetaGeo = degrad*th; fPhiGeo = degrad*ph;
  GeoToSph( fThetaGeo, fPhiGeo, fThetaSph, fPhiSph );
  fSinThGeo = sin( fThetaGeo ); fCosThGeo = cos( fThetaGeo );
  fSinPhGeo = sin( fPhiGeo );   fCosPhGeo = cos( fPhiGeo );
  return kOK;
}

//_____________________________________________________________________________

Int_t THaNA::TrackReconstruct()

{
       
  return 0;
}


//_____________________________________________________________________________
Int_t THaNA::DefineVariables( EMode mode )
{
  // Initialize global variables and lookup table for decoder

  if( mode == kDefine && fIsSetup ) return kOK;
  fIsSetup = ( mode == kDefine );

  // Register variables in global list

  RVarDef vars[] = {
    { "ntracks", "Number of tracks ",        "fNTracks" },
    { "tr.theta","out-of-plane ang",    "fTracks.THaNDTrack.GetTheta()"},
    { "tr.phi  ","in-plane ang","fTracks.THaNDTrack.GetPhi()"},
    { "tr.nhits  ","Number of hits in track","fTracks.THaNDTrack.GetNHits()"},
    { "tr.tof  ","Time of flight","fTracks.THaNDTrack.GetTOF()"},
    { "tr.dist  ","Distance of a first hit in track from the target","fTracks.THaNDTrack.GetDist()"},
    { "tr.energy  ","Energy deposit","fTracks.THaNDTrack.GetEnergyDeposit()"},
    { "tr.firstpad ", "Paddle number of the first hit","fTracks.THaNDTrack.GetFirstHitPaddle()"},
    { "tr.firstplane ", "Plane number of the first hit","fTracks.THaNDTrack.GetFirstHitPlane()"},
    { "wv.ntracks", "Number of tracks ",        "fNwvTracks" },
    { "tr.wv.theta","in-plane ang",    "fwvTracks.THaNDTrack.GetTheta()"},
    { "tr.wv.phi  ","out-of-plane ang","fwvTracks.THaNDTrack.GetPhi()"},
    { "tr.wv.nhits  ","Number of hits in track","fwvTracks.THaNDTrack.GetNHits()"},
    { "tr.wv.tof  ","Time of flight","fwvTracks.THaNDTrack.GetTOF()"},
    { "tr.wv.energy  ","Energy deposit","fwvTracks.THaNDTrack.GetEnergyDeposit()"},
    { "wov.ntracks", "Number of tracks ",        "fNwovTracks" },
    { "tr.wov.theta","in-plane ang",    "fwovTracks.THaNDTrack.GetTheta()"},
    { "tr.wov.phi  ","out-of-plane ang","fwovTracks.THaNDTrack.GetPhi()"},
    { "tr.wov.nhits  ","Number of hits in track","fwovTracks.THaNDTrack.GetNHits()"},
    { "tr.wov.tof  ","Time of flight","fwovTracks.THaNDTrack.GetTOF()"},
    { "tr.wov.energy  ","Energy deposit","fwovTracks.THaNDTrack.GetEnergyDeposit()"},
    { "nneutrons", "Number of neutrons per event ","fNNeutrons"},
    { "n.tof"    , "Tof of neutron", "fNeutrons.THaNDNeutron.GetTOF()"},
    { "n.plane"  , "Plane of neutron", "fNeutrons.THaNDNeutron.GetHitPlane()"},
    { "n.pad"    , "Paddle number of neutron", "fNeutrons.THaNDNeutron.GetHitPaddle()"},
    { "n.phi"    , "in-plane ang", "fNeutrons.THaNDNeutron.GetPhi()"},
    { "n.theta"  , "out-of-plane ang", "fNeutrons.THaNDNeutron.GetTheta()"},
    { "n.energy" , "Paddle number of neutron", "fNeutrons.THaNDNeutron.GetEnergyDeposit()"},
    { "n.dist","Distance of paddle from target","fNeutrons.THaNDNeutron.GetDistance()"},
    { "n.cosine","Cosine of angle between neutron and predicted neutron"
      ,"fNeutrons.THaNDNeutron.GetCosine()"},

    { 0 }
    //    { "tr.wv.lveto  ","Left veto hit","fLeftIsHit"},
    //    { "tr.wv.rveto  ","Right veto hit","fRightIsHit"},
  };

  return DefineVarsFromList( vars, mode );
}

//_____________________________________________________________________________

Int_t THaNA::GetTrackCharge()
{  
  return 0;
}

//_____________________________________________________________________________

Bool_t THaNA::GetTrackVetos()
{
  return 0;
}



//_____________________________________________________________________________
ClassImp(THaNA)

  
