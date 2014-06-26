//*-- Author :    Olivier Gayou  8 December 2004

//////////////////////////////////////////////////////////////////////////
//
// THaNDTrack
//
// A neutron detector track.
//
//////////////////////////////////////////////////////////////////////////

#include "THaNDTrack.h"
#include "THaNAScintHit.h"
#include <iostream>

using namespace std;

THaNDTrack::THaNDTrack(const THaNDTrack& track) :
  fPhi(track.fPhi), fTheta(track.fTheta), fTOF(track.fTOF),
  fEnergyDeposit(track.fEnergyDeposit), fDist(track.fDist),
  fFirstHitPlane(track.fFirstHitPlane),
  fFirstHitPaddle(track.fFirstHitPaddle), fNHits(track.fNHits)
{
  for(Int_t ihit=0;ihit<track.fNHits;ihit++) {
    fHits[ ihit ] = track.fHits[ihit];
  }
}
  
//_____________________________________________________________________________
void THaNDTrack::Clear( const Option_t* opt )
{
  // If *opt == 'F' then reset all track quantities, else just
  // delete memory managed by this track.
  // (We need this behavior so we can Clear("C") the track TClonesArray
  // without the overhead of clearing everything.)

  if( opt && (*opt == 'F') ) {
    fTheta = fPhi = 100.0;
    fNHits = 0;
    fTOF = 0.0;
    fDist = 0.0;
    fEnergyDeposit = 0.;
  }
}

//_____________________________________________________________________________
Int_t THaNDTrack::AddHit( THaNAScintHit* h)
{
  // Add a hit to the internal list of pointers.

  if( fNHits >= kMAXHIT )
    return 1;

  fHits[ fNHits++ ] = h;
  fTheta = (fTheta+h->GetHitTheta())/2.;
  fPhi = (fPhi+h->GetHitPhi())/2.;
  //  fTOF = (fTOF+h->GetHitTOF())/2.;  
  fEnergyDeposit = fEnergyDeposit+h->GetEnergyDeposit();

  return 0;
}


ClassImp(THaNDTrack)
