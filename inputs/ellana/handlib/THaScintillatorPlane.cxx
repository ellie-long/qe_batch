//////////////////////////////////////////////////////////////////////////////
//                                                                           //
// THaScintillatorPlane                                                         //
//                                                                           //
// Class for trigger plane  consisting of multiple                           //
// paddles with phototubes on both ends.                                     //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////


#include <cstring>
#include <cstdio>
#include <iostream>

#include "THaScintillatorPlane.h"
#include "THaEvData.h"
#include "THaDetMap.h"
#include "VarDef.h"
#include "VarType.h"
#include "THaTrack.h"
#include "TClonesArray.h"
#include "TMath.h"
#include "THaNAScintHit.h"
#include "THaNA.h"


#include "THaTrackProj.h"
// #include "THaDB.h"

using namespace std;

//____________________________________________________________________________
THaScintillatorPlane::THaScintillatorPlane( const char* name, const char* description, 
					    THaApparatus* apparatus ) :
  THaPlane(name, description, apparatus)
{

  fHits = new TClonesArray("THaNAScintHit", 200);
  // Constructor
  //  fTWalkPar = 0;

  // Constructor has not initialization at this point

  //  fTrackProj = new TClonesArray( "THaTrackProj", 5 );
}

Int_t THaScintillatorPlane::ReadDatabase( const TDatime& date )
{
  // Read this detector's parameters from the database file 'fi'.
  // This function is called by THaDetectorBase::Init() once at the
  // beginning of the analysis.
  // 'date' contains the date/time of the run being analyzed.

  static const char* const here = "ReadDatabase()";
  const int LEN = 200;
  char buf[LEN];
  Int_t nelem;

  // Read data from database 

  FILE* fi = OpenFile( date );
  if( !fi ) return kFileError;

 


  // Search for any date tags that follow, and start reading from
  // the best matching tag if any are found. If none found, but we have a
  // configuration string, search for it.
  if( SeekDBdate( fi, date ) == 0 && fConfig.Length() > 0 && 
      SeekDBconfig( fi, fConfig.Data() ));

  

  while ( ReadComment( fi, buf, LEN ) );
  fscanf ( fi, "%d", &nelem );                        // Number of  paddles
  fgets ( buf, LEN, fi );

  // Reinitialization only possible for same basic configuration 
  if( fIsInit && nelem != fNelem ) {
    Error( Here(here), "Cannot re-initalize with different number of paddles. "
	   "(was: %d, now: %d). Detector not re-initialized.", fNelem, nelem );
    return kInitError;
  }
  fNelem = nelem;

  // Read detector map. Unless a model-number is given
  // for the detector type, this assumes that the first half of the entries 
  // is for ADCs and the second half, for TDCs
  while ( ReadComment( fi, buf, LEN ) );
  int i = 0;
  fDetMap->Clear();
  while (1) {
    int pos;
    Int_t first_chan, model;
    Int_t crate, slot, first, last;
    fgets ( buf, LEN, fi );
    sscanf( buf, "%d%d%d%d%d%n", &crate, &slot, &first, &last, &first_chan, &pos );
    
    if( crate < 0 ) break;
    model=atoi(buf+pos); // if there is no model number given, set to zero
    
    if( fDetMap->AddModule( crate, slot, first, last, first_chan, model ) < 0 ) {
      Error( Here(here), "Too many DetMap modules (maximum allowed - %d).", 
	     THaDetMap::kDetMapSize);
      fclose(fi);
      return kInitError;
    }
  }
  while ( ReadComment( fi, buf, LEN ) );

  if( !fIsInit ) {
    fIsInit = true;
  }

  // Dimension of arrays

  fLT     = new Double_t[fNelem];
  fRT     = new Double_t[fNelem];
  fLToff  = new Double_t[fNelem];
  fRToff  = new Double_t[fNelem];
  fLT_c   = new Double_t[fNelem];
  fRT_c   = new Double_t[fNelem];
  fLA     = new Double_t[fNelem];
  fRA     = new Double_t[fNelem];
  fLAped  = new Double_t[fNelem];
  fRAped  = new Double_t[fNelem];
  fLAgain = new Double_t[fNelem];
  fRAgain = new Double_t[fNelem];
  fLA_c   = new Double_t[fNelem];
  fRA_c   = new Double_t[fNelem];
  fTDiff  = new Double_t[fNelem]; 
  fYPos   = new Double_t[fNelem];
  fYBar   = new Double_t[fNelem];
  fXBar   = new Double_t[fNelem];
  fZBar   = new Double_t[fNelem];
  fDist   = new Double_t[fNelem];
  fTOFOffset = new Double_t[fNelem];
  fTOFScale  = new Double_t[fNelem];
  fYOffset   = new Double_t[fNelem];
  fYScale    = new Double_t[fNelem];
  fTOF    = new Double_t[fNelem];
  fIsHit  = new Bool_t[fNelem];
  fNRHits  = new Int_t[fNelem];
  fNLHits  = new Int_t[fNelem];
  fMultiHits = new PaddleMultiHits[fNelem];
  fIBlockingBarMin = new Int_t[fNelem];
  fIBlockingBarMax = new Int_t[fNelem];


  // Read calibration data
  
  while ( ReadComment( fi, buf, LEN ) );// TDC time offsets
  
  Float_t nL,nR,nD;
  for (i=0;i<fNelem;i++) {
    fscanf(fi,"%f%f",&nL,&nR);
    SetTDCOff(i,nL,nR);
    fgets ( buf, LEN, fi );
  
}
 

  while ( ReadComment( fi, buf, LEN ) );// ADC pedestals
  for (i=0;i<fNelem;i++) {
    fscanf(fi,"%f%f",&nL,&nR);
    SetADCPed(i,nL,nR);
    fgets ( buf, LEN, fi );
    //  cout<<"Pedastal, "<<nL<<"  "<<nR<<endl;    
  }
  
  while ( ReadComment( fi, buf, LEN ) ); // ADC gains
  for (i=0;i<fNelem;i++) {
    fscanf(fi,"%f%f",&nL,&nR);
    SetADCGain(i,nL,nR);
    fgets ( buf, LEN, fi );

  }

  while ( ReadComment( fi, buf, LEN ) ); // Position offsets and scale parameters
  for (i=0;i<fNelem;i++) {
    fscanf(fi,"%f%f",&nL,&nR);
    SetYPos(i,nL,nR);
    fgets ( buf, LEN, fi ); 
  } 
  
  while ( ReadComment( fi, buf, LEN ) ); // TOF offset and scale parameters
 for (i=0;i<fNelem;i++) {
   fscanf(fi,"%f%f",&nL,&nR);
   SetTOFPar(i,nL,nR);
   fgets ( buf, LEN, fi );
 }

 while ( ReadComment( fi, buf, LEN ) ); // x, y, z coordinates
 for (i=0;i<fNelem;i++) {
   fscanf(fi,"%f%f%f",&nL,&nD,&nR);
   SetXYZBar(i,nL,nD,nR);
   fgets ( buf, LEN, fi );
 }

 return kOK;
}



//_____________________________________________________________________________
THaAnalysisObject::EStatus THaScintillatorPlane::Init( const TDatime& date )
{
  // Extra initialization for scintillator plane: set up DataDest map

  if( THaNonTrackingDetector::Init( date ) ) 
    return fStatus;

  const DataDest tmp[NDEST] = {
    { &fLTNhit, &fLANhit, fLT, fLA },
    { &fRTNhit, &fRANhit, fRT, fRA }
  };
  memcpy( fDataDest, tmp, NDEST*sizeof(DataDest) );

  return fStatus = kOK;

}

//_____________________________________________________________________________
Int_t THaScintillatorPlane::DefineVariables( EMode mode )
{
  // Initialize global variables and lookup table for decoder

  if( mode == kDefine && fIsSetup ) return kOK;
  fIsSetup = ( mode == kDefine );

  // Register variables in global list

  RVarDef vars[] = {
    { "nhit",   "Number of hits",                    "GetNHits()"},
    { "mypos",   "Y position of hits",     "fHits.THaNAScintHit.GetHitYPos()" },
    { "mtof",    "Time of Flight of hits", "fHits.THaNAScintHit.GetHitTOF()" },
    { "pad",    "Paddle number of hit","fHits.THaNAScintHit.GetPaddleNumber()" },
    { "nlthit", "Number of Left paddles TDC times",  "fLTNhit" },
    { "nrthit", "Number of Right paddles TDC times", "fRTNhit" },
    { "nlahit", "Number of Left paddles ADCs amps",  "fLANhit" },
    { "nrahit", "Number of Right paddles ADCs amps", "fRANhit" },
    { "lt",     "TDC time left side",                "fLT"     },
    { "rt",     "TDC time right side",               "fRT"     },
    { "lt_c",   "Corrected TDC time left side",      "fLT_c"   },
    { "rt_c",   "Corrected TDC time right side",     "fRT_c"   },
    { "la",     "ADC amp left side",                 "fLA"     },
    { "ra",     "ADC amp right side",                "fRA"     },
    { "la_c",   "Corrected ADC amp left side",       "fLA_c"   },
    { "ra_c",   "Corrected ADC amp right side",      "fRA_c"   },
    { "tdiff",  "Left - Right TDC time", 	     "fTDiff"  }, 
    { "ypos",   "Y position along paddle", 	     "fYPos"   },
    { "ybar",   "Y position of bar",          	     "fYBar"   },
    { "xbar",   "X position of bar",                 "fXBar"   },
    { "zbar",   "Z position of bar",                 "fZBar"   },
    { "dist",   "Distance (ND at 6m) of a bar from the target", "fDist"   },
    { "tof",    "Corrected tof to paddle",           "fTOF"  },
    { "npadhit","Number of paddles hit",             "fNPaddlesHit"},
    { "ishit",  "Is Hit",                            "fIsHit"},
    { "nhitspadl",  "Number of hits in left paddle",       "fNLHits"},
    { "nhitspadr",  "Number of hits in right paddle",      "fNRHits"},
    { 0 }
  };

  return DefineVarsFromList( vars, mode );
}

//_____________________________________________________________________________
THaScintillatorPlane::~THaScintillatorPlane()
{
  // Destructor. Remove variables from global list.

  if( fIsSetup )
    RemoveVariables();
  if( fIsInit )
    DeleteArrays();
}

//_____________________________________________________________________________
void THaScintillatorPlane::DeleteArrays()
{
  // Delete member arrays. Used by destructor.

  delete [] fLT;         fLT      = NULL;
  delete [] fRT;         fRT      = NULL;
  delete [] fLToff;      fLToff   = NULL;
  delete [] fRToff;      fRToff   = NULL;
  delete [] fLT_c;       fLT_c    = NULL;
  delete [] fRT_c;       fRT_c    = NULL;
  delete [] fLA;         fLA      = NULL;
  delete [] fRA;         fRA      = NULL;
  delete [] fLAped;      fLAped   = NULL;
  delete [] fRAped;      fRAped   = NULL;
  delete [] fLAgain;     fLAgain  = NULL;
  delete [] fRAgain;     fRAgain  = NULL;
  delete [] fLA_c;       fLA_c    = NULL;
  delete [] fRA_c;       fRA_c    = NULL;
  delete [] fTDiff;      fTDiff   = NULL;
  delete [] fYPos;       fYPos    = NULL;
  delete [] fYBar;       fYBar    = NULL;
  delete [] fXBar;       fXBar    = NULL;
  delete [] fZBar;       fZBar    = NULL;
  delete [] fDist;       fDist    = NULL;
  delete [] fTOF;   fTOF  = NULL;
  delete [] fTOFScale;   fTOFScale  = NULL;
  delete [] fTOFOffset;  fTOFOffset = NULL;
  delete [] fYScale;     fYScale  = NULL;
  delete [] fYOffset;    fYOffset = NULL;
  delete [] fIsHit;      fIsHit   = NULL;
  delete [] fMultiHits;  fMultiHits= NULL;
  delete [] fNRHits;      fNRHits= NULL;
  delete [] fNLHits;      fNLHits= NULL;
  delete [] fIBlockingBarMin; fIBlockingBarMin = NULL;
  delete [] fIBlockingBarMax; fIBlockingBarMax = NULL;
  delete fHits;

}

//_____________________________________________________________________________
inline 
void THaScintillatorPlane::ClearEvent()
{
  // Reset per-event data.
 
  const int lf = fNelem*sizeof(Double_t);
  const int lfb = fNelem*sizeof(Bool_t);
  const int li = fNelem*sizeof(Int_t);
  const int lfm = fNelem*sizeof(PaddleMultiHits);
  fLTNhit = 0;                       // Number of Left paddles TDC times
  fRTNhit = 0;                       // Number of Right paddles TDC times
  fLANhit = 0;                       // Number of Left paddles ADC amps
  fRANhit = 0;                       // Number of Right paddles ADC amps
  memset( fLT, 0, lf );                   // Left paddles TDCs
  memset( fLT_c, 0, lf );                 // Left paddles corrected TDCs
  memset( fRT, 0, lf );                   // Right paddles TDCs
  memset( fRT_c, 0, lf );                 // Right paddles corrected TDCs
  memset( fLA, 0, lf );                   // Left paddles ADCs
  memset( fLA_c, 0, lf );                 // Left paddles corrected ADCs
  memset( fRA, 0, lf );                   // Right paddles ADCs
  memset( fRA_c, 0, lf );                 // Right paddles corrected ADCs
  memset( fTDiff, 0, lf );                // Left - Right
  memset( fYPos, 0, lf );  		  // Y position along paddle
  memset( fTOF, 0, lf );  		  // Y position along paddle
  memset( fIsHit, 0, lfb );               // Is  paddle Hit
  memset( fDist, 0, lf);                  // distance of a track from the target when ND is 6 meter.
  memset( fMultiHits, 0, lfm);            // Multihits array 
  memset( fNLHits, 0, li);            // Number of hits in left paddle 
  memset( fNRHits, 0, li);            // Number of hits in right paddle 
  fHits->Clear();

}

//_____________________________________________________________________________
Int_t THaScintillatorPlane::Decode( const THaEvData& evdata )
{
  // Decode scintillator data, correct TDC times and ADC amplitudes, and copy
  // the data to the local data members.
  // This implementation makes the following assumptions about the detector map:
  // - The first half of the map entries corresponds to ADCs, 
  //   the second half, to TDCs.
  // - The first fNelem detector channels correspond to the PMTs on the
  //   right hand side, the next fNelem channels, to the left hand side.
  //   (Thus channel numbering for each module must be consecutive.)

  ClearEvent();

  Int_t nextHit=0;
  // static const Double_t target_dist = 6.04;

 
  //THaNA* app = static_cast<THaNA*>(fApparatus);
  THaNA* app = static_cast<THaNA*>(GetApparatus());
  Double_t Dist2trg = app->GetDistance();

  // cout <<"Distance, "<< Dist2trg<<", "<<nextHit<<endl;// why does it repeat six times each event?


  
  // Loop over all modules defined for Scintillator 1 detector

  for( Int_t i = 0; i < fDetMap->GetSize(); i++ ) {
    THaDetMap::Module* d = fDetMap->GetModule( i );
        bool adc = (i < fDetMap->GetSize()/2);

    // Loop over all channels that have a hit.
      for( Int_t j = 0; j < evdata.GetNumChan( d->crate, d->slot ); j++) {

      Int_t chan = evdata.GetNextChan( d->crate, d->slot, j );

      if( chan < d->lo || chan > d->hi ) continue;   // Not one of my channels

      // Get the detector channel number, starting at 0
      Int_t k = d->first + chan - d->lo - 1; 

#ifdef WITH_DEBUG      
      if( k<0 || k>NDEST*fNelem ) {
	// Indicates bad database
	Warning( Here("Decode()"), "Illegal detector channel: %d", k );
	continue;
      }
//        cout << "adc,j,k = " <<adc<<","<<j<< ","<<k<< endl;
#endif
      // Copy the data to the local variables.
      DataDest* dest = fDataDest + k/fNelem;
      Int_t kbefore = k;
      k = k % fNelem;	// k is the paddle number
      // Get the data.
      Int_t data = evdata.GetData( d->crate, d->slot, chan, 0 );

      if( adc ) {
	Int_t data = evdata.GetData( d->crate, d->slot, chan, 0 );
	dest->adc[k]   = static_cast<Double_t>( data );
	(*dest->nahit)++;
      } else {
	  dest->tdc[k]   = static_cast<Double_t>( data );
	  (*dest->nthit)++;
      } // end if
// Handles Multihit in TDCs
      if (!adc) {
  	Int_t nHits = evdata.GetNumHits(d->crate,d->slot,chan);
	  if (kbefore == k) {
	    fNLHits[k]=nHits;
	  }
	  else {
	    fNRHits[k]=nHits;
	  }
  	for (Int_t hit=0; hit<nHits; hit++) {
	  Int_t data = evdata.GetData( d->crate, d->slot, chan, hit);
	  if (kbefore == k) {
	    fMultiHits[k].AddLeftHit(data);
	  }
	  else {
	    fMultiHits[k].AddRightHit(data);
	  }
	  
	} // end multihit loop
      } //end if !adc

      } // end for loop
  }

  for(Int_t i=0;i<fNelem;i++) {
    fLT_c[i]=fLT[i]-fLToff[i];
    fRT_c[i]=fRT[i]-fRToff[i];
    fLA_c[i]=( fLA[i] - fLAped[i] ) * fLAgain[i];
    fRA_c[i]=( fRA[i] - fRAped[i] ) * fRAgain[i];
    fTDiff[i]=fLT_c[i]-fRT_c[i];
    
    // fIsHit[i]=(fMultiHits[i].GetNLHits()>0 && fMultiHits[i].GetNRHits()>0&&fLA_c[i]>0 && fRA_c[i]>0);

    // 30.08.2005 (saw) Remove ADC requirement for now
    fIsHit[i]=(fMultiHits[i].GetNLHits()>0 && fMultiHits[i].GetNRHits()>0);

 // Feb 17,2006 (ramesh) accept adc window.
    // fIsHit[i]=(fMultiHits[i].GetNLHits()>0 && fMultiHits[i].GetNRHits()>0&&fLA_c[i]>0 && fRA_c[i]>0);

    
    
    if (fIsHit[i]) {
      fDist[i] = sqrt(fXBar[i]*fXBar[i]+fYBar[i]*fYBar[i]+(fZBar[i] + Dist2trg)*(fZBar[i] + Dist2trg));
      for (Int_t ii=0; ii<fMultiHits[i].GetNLHits(); ii++) {
	for (Int_t jj=0; jj<fMultiHits[i].GetNRHits(); jj++) {
	  Int_t left =(Int_t)fMultiHits[i].GetLHit(ii)-(Int_t)fLToff[i];
	  Int_t right =(Int_t)fMultiHits[i].GetRHit(jj)-(Int_t)fRToff[i];
	  //	  Int_t left =(Int_t)fMultiHits[i].GetLHit(ii);
	  //	  Int_t right =(Int_t)fMultiHits[i].GetRHit(jj);
	  Double_t energy = (fLA_c[i]+fRA_c[i])/2.;
	  Double_t tof = 1.0*fTOFScale[i]*(left+right)/2.0+fTOFOffset[i];
	  //      Double_t tof = 1.0*fTOFScale[i]*(left+right)/2.0;
	  
	  
	  //////////////////////////////////////////////////// 

// 	  // ypos is used to calculate distance of Neutron Detector form target 
// 	  // and the distance is used to recunstruct momentum from time-of-flight.

// 	  Double_t ypos = -3000.;
// 	  ypos = fYScale[i]*((fLT[i]-fRT[i])+fYOffset[i]);

// 	  // In calibration of ypos it is set in cm unit by making the scaling to cover 100.
	    
// 	  if (ypos>-2000. && ypos<2000.) {
// 	    new( (*fHits)[nextHit++] )  THaNAScintHit( i, ypos, tof, energy );
// 	    fYPos[i]=ypos;
// 	  }
	  ////////////////////////////////////////////////
	  
	  /////////////////////////////////////////////////////
	  	  Double_t ypos = -300.;	  
	  	  if ( left>0 && right>0 ) {
	  	    ypos = 100.*((left-right)+fYOffset[i]-fYScale[i]/2.)/fYScale[i];	    
	  	    if (ypos>-100. && ypos<100.) {
	  	      new( (*fHits)[nextHit++] )  THaNAScintHit( i, ypos, tof, energy );
	  	      fYPos[i]=ypos;
	  	    }	    
	   	  } // end if ypos
	   ////////////////////////////////////////////////////
	  
	} // end for jj
       } // end for ii
    } // end if IsHit
  } // end for i
  
  HitCount();
  return fLTNhit+fRTNhit;
}


//_____________________________________________________________________________
Int_t THaScintillatorPlane::CoarseProcess( TClonesArray& tracks )
{
 
  HitCount();

 return 0;
}

//_____________________________________________________________________________
Int_t THaScintillatorPlane::FineProcess( TClonesArray& tracks )
{
  return 0;
}

//_____________________________________________________________________________
Bool_t THaScintillatorPlane::IsHit() 
{
  int i=0;
  bool Success = fIsHit[0];
  while (!Success && i<fNelem-1) 
    {
      i++;
      Success = fIsHit[i];
    }
  return Success;
}
  
//_____________________________________________________________________________

void THaScintillatorPlane::HitCount()
{
  fNPaddlesHit = 0;
  for (Int_t i = 0; i < fNelem; i++)
    {
      if (fIsHit[i])
	{
	  fNPaddlesHit++;
        }
    }
  // return;  // No zero after the return!
}  
//_______________________________________________________________________________

