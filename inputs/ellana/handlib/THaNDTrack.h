#ifndef ROOT_THaNDTrack
#define ROOT_THaNDTrack

//////////////////////////////////////////////////////////////////////////
//
// THaNDTrack
//
//////////////////////////////////////////////////////////////////////////


#include "TObject.h"

class THaNAScintHit;

class THaNDTrack : public TObject {

 public:
  
  THaNDTrack(Double_t phi=100.0, Double_t theta=100.0, Double_t tof=0.0,
	     Double_t energy=0.0,Double_t dist=0.0, Int_t plane=-1,
	     Int_t pad=-1) :
    fPhi(phi), fTheta(theta), fTOF(tof), fEnergyDeposit(energy), fDist(dist),
    fFirstHitPlane(plane), fFirstHitPaddle(pad), fNHits(0) {}

  THaNDTrack(const THaNDTrack& track);

  virtual ~THaNDTrack() {}
  
  Int_t GetNHits() {return fNHits;}
  THaNAScintHit* GetHit( Int_t i ) {return fHits[i];}
  Double_t GetPhi() {return fPhi;}
  Double_t GetTheta() {return fTheta;}
  Double_t GetTOF() {return fTOF;}
  Double_t GetDist() {return fDist;}
  Double_t GetEnergyDeposit() {return fEnergyDeposit;}
  Int_t GetFirstHitPaddle() {return fFirstHitPaddle;}
  Int_t GetFirstHitPlane() {return fFirstHitPlane;}
  //  Int_t GetVetoHit() {return fVetoHit;}
  
  //  void SetVetoHit( Int_t veto ) {fVetoHit=veto;}
  //  void ResetVetoHit() {fVetoHit=0;}

  void Clear( const Option_t* opt );

  Int_t AddHit( THaNAScintHit* h);

/*   THaNDTrack operator=(THaNDTrack rhs) { */
/*     fNHits = rhs.GetNHits(); */
/*     fPhi = rhs.GetPhi(); */
/*     fTheta = rhs.GetTheta(); */
/*     fEnergyDeposit = rhs.GetEnergyDeposit(); */
/*     fTOF = rhs.GetTOF(); */
/*     //    fHits = rhs.fHits; */
/*     return *this; */
/*   } */

 private:

  enum { kMAXHIT = 35 };
  
  Double_t fPhi;  
  Double_t fTheta;
  Double_t fTOF;
  Double_t fEnergyDeposit;
  Double_t fDist;
  Int_t fFirstHitPlane;
  Int_t fFirstHitPaddle;
  Int_t fNHits;   
  //  Int_t fVetoHit;

  THaNAScintHit* fHits[kMAXHIT];

  ClassDef(THaNDTrack,0)

};

  
#endif
