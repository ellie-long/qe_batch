#ifndef ROOT_THaPlane
#define ROOT_THaPlane

//////////////////////////////////////////////////////////////////////////////
//                         
// THaPlane
//
// Abstract class for a Bigbite scintillator plane
// 
//////////////////////////////////////////////////////////////////////////////

#include "THaNonTrackingDetector.h"

class THaPlane : public THaNonTrackingDetector {
  
 public:
  virtual ~THaPlane();

  THaPlane( const char* name, const char* description,
			  THaApparatus* a = NULL);

  virtual Int_t CoarseProcess( TClonesArray& tracks ) = 0;
  virtual Int_t    FineProcess( TClonesArray& tracks )  = 0;
          Bool_t   IsTracking() { return kFALSE; }
  virtual Bool_t   IsPid()      { return kFALSE; }

protected:

  //Only derived classes may construct me

  ClassDef(THaPlane,0)  //ABC for a BigBite scintillator detector
};

#endif

