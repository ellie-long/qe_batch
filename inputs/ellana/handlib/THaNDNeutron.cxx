//*-- Author :    Stephen A. Wood  2 August 2005

//////////////////////////////////////////////////////////////////////////
//
// THaNDNeutron
//
// A "neutron" in the neutron detector.
// A neutron is defined as a hit in a bar with no hits nearby in time in
// any bars or vetos in front of the hit bar.
// For now the energy is the ADC sum for that bar, but later might include
// energy in all the bars that are behind the "neutron".
// Should probably include in the object a list of bars or vetos that
// were empty of hits.
//
//////////////////////////////////////////////////////////////////////////

#include "THaNDNeutron.h"
#include "THaNAScintHit.h"

ClassImp(THaNDNeutron)

//#include <iostream>

//using namespace std;

//_____________________________________________________________________________
void THaNDNeutron::Clear( const Option_t* opt )
{
  // If *opt == 'F' then reset all "neutron" quantities, else just
  // delete memory managed by this neutron.
  // (We need this behavior so we can Clear("C") the track TClonesArray
  // without the overhead of clearing everything.)

  if( opt && (*opt == 'F') ) {
    fTheta = fPhi = 100.0;
    fTOF = 0.0;
    fEnergyDeposit = 0.;
    fDistance = -1.0;
    fHitPlane = -1;
    fHitPaddle = -1;
    fHit = (THaNAScintHit *) 0;
    fCosine=-1.0;
  }
}
