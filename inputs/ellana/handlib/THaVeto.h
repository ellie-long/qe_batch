#ifndef ROOT_THaVeto
#define ROOT_THaVeto

#include "THaScintillatorPlane.h"

class THaVeto : public THaScintillatorPlane {

 public:

  THaVeto( const char* name, const char* description = "", 
		   THaApparatus* a = NULL );
  virtual ~THaVeto();

  virtual Int_t Decode( const THaEvData& );

  Double_t GetNegRegionLimit() { return fNegRegionLimit;}
  Double_t GetPosRegionLimit() { return fPosRegionLimit;}

  Double_t GetMinAngle() {return fMinAngle;}

  Bool_t GetLeftIsHit(Int_t i) {return fLeftIsHit[i];}
  Bool_t GetRightIsHit(Int_t i) {return fRightIsHit[i];}

  Int_t GetHitRegion(Int_t i) {return fHitRegion[i];}

 private:
  
  Int_t* fHitRegion; // [fNelem]

  Double_t fPaddleOverlap;

  Double_t fMinAngle;
  Double_t fNegRegionLimit;
  Double_t fPosRegionLimit;

  Bool_t*  fLeftIsHit;
  Bool_t*  fRightIsHit;
  
  void           ClearEvent();
  void           DeleteArrays();

  virtual Int_t  ReadDatabase( const TDatime& date );
  virtual Int_t  DefineVariables( EMode mode = kDefine );

  ClassDef(THaVeto,0)   // Generic trigger scintillator plane class
};

////////////////////////////////////////////////////////////////////////////////

#endif
