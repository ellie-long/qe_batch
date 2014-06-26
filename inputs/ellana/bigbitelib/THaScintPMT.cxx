///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// THaScintPMT                                                               //
//                                                                           //
// Class to represent a PMT on the neutron bars                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "THaScintPMT.h"
#include "THaScintBar.h"

//_____________________________________________________________________________
THaScintPMT::THaScintPMT( Double_t gain, Int_t ped, Double_t res, Double_t off,
			  Double_t walk, THaScintBar* bar, Int_t barnum,
			  Int_t side,
			  Int_t lowlim, Int_t uplim, Double_t wraparound,
			  Double_t wexp ) :
  fGain(gain), fPed(ped), fTDCRes(res), fTOffset(off), fTimeWalkPar(walk),
  fTimeWalkExp(wexp), fScBar(bar), fBarNum(barnum), fSide(side),
  fRawLowLim(lowlim), fRawUpLim(uplim), fRawWrapAround(wraparound) { ; }

//_____________________________________________________________________________
THaScintPMT::~THaScintPMT(void) { ; }

//_____________________________________________________________________________
void THaScintPMT::SetScintBar(THaScintBar* bar)
{
  fScBar=bar;
}

//_____________________________________________________________________________
ClassImp(THaScintPMT)

///////////////////////////////////////////////////////////////////////////////
