///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// THaPlaneHit                                                               //
//                                                                           //
// Class representing a single hit for the plane                             //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "THaPlaneHit.h"


//_____________________________________________________________________________
THaPlaneHit::THaPlaneHit() : TObject() {
  // Normal constructor
}
//_____________________________________________________________________________
THaPlaneHit::THaPlaneHit( THaPaddle* paddle ) : TObject() {
  // Normal constructor
  SetPaddle( paddle );
}

//_____________________________________________________________________________
THaPlaneHit::~THaPlaneHit() {
  // Normal destructor
}

ClassImp(THaPlaneHit)
