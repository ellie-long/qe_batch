#ifndef ROOT_THaNDNeutron
#define ROOT_THaNDNeutron

//////////////////////////////////////////////////////////////////////////
//
// THaNDNeutron
//
//////////////////////////////////////////////////////////////////////////


#include "TObject.h"
#include "THaNAScintHit.h"
#include <cstdio>

class THaNAScintHit;

class THaNDNeutron : public TObject {

 public:
  
  THaNDNeutron(Double_t phi=100.0, Double_t theta=100.0, Double_t tof=-1.0, Double_t energy=-1.0, Double_t distance=-1.0, Int_t plane=-1, Int_t pad=-1, THaNAScintHit* h=0) :
    fPhi(phi), fTheta(theta), fTOF(tof), fEnergyDeposit(energy),
    fDistance(distance),
    fHitPlane(plane), fHitPaddle(pad), fHit(h), fCosine(-1.0) {}
  virtual ~THaNDNeutron() {}
  
  THaNAScintHit* GetHit() {return fHit;}
  Double_t GetPhi() {return fPhi;}
  Double_t GetTheta() {return fTheta;}
  Double_t GetTOF() {return fTOF;}
  Double_t GetEnergyDeposit() {return fEnergyDeposit;}
  Double_t GetDistance() {return fDistance;}
  Int_t GetHitPaddle() {return fHitPaddle;}
  Int_t GetHitPlane() {return fHitPlane;}
  Double_t GetCosine() {return fCosine;}
  void SetCosine( Double_t cosine ) {fCosine=cosine;}
  //  Int_t GetVetoHit() {return fVetoHit;}
  
  //  void SetVetoHit( Int_t veto ) {fVetoHit=veto;}
  //  void ResetVetoHit() {fVetoHit=0;}

  void Clear( const Option_t* opt );

 private:

  Double_t fPhi;  
  Double_t fTheta;
  Double_t fTOF;
  Double_t fEnergyDeposit;
  Double_t fDistance;
  Int_t fHitPlane;
  Int_t fHitPaddle;
  THaNAScintHit* fHit;
  Double_t fCosine;

  ClassDef(THaNDNeutron,0)

};

  
#endif
