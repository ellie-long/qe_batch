#ifndef ROOT_THaNAScintHit
#define ROOT_THaNAScintHit

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// THaNAScintHit                                                             //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include <cstdio>

class THaNAScintHit : public TObject {

 public:
  THaNAScintHit(Int_t paddle=0, Double_t ypos=0.0, 
	      Double_t tof=0.0, Double_t energy=0.0) :
    fPaddleNumber(paddle), fHitYPos(ypos), fHitTOF(tof), 
    fEnergyDeposit(energy) {}
  virtual ~THaNAScintHit() {}

  Int_t GetPaddleNumber() {return fPaddleNumber;}
  Double_t GetHitYPos() {return fHitYPos;}
  Double_t GetHitTOF() {return fHitTOF;}
  Double_t GetHitTheta() {return fHitTheta;}
  Double_t GetHitPhi() {return fHitPhi;}
  Double_t GetEnergyDeposit() {return fEnergyDeposit;}

  void SetPaddleNumber(Int_t paddle) {fPaddleNumber = paddle;}
  void SetYHitPos(Double_t ypos) {fHitYPos = ypos;}
  void SetHitTOF(Double_t tof) {fHitTOF = tof;}
  void SetEnergyDeposit(Double_t energy) {fEnergyDeposit = energy;}
  void SetHitAngles(Double_t theta, Double_t phi) {
    fHitTheta=theta; fHitPhi=phi;}

 private:
  Int_t fPaddleNumber;
  Double_t fHitYPos;
  Double_t fHitTOF;
  Double_t fHitTheta;
  Double_t fHitPhi;
  Double_t fEnergyDeposit;

  ClassDef(THaNAScintHit,1)
};
/////////////////////////////////////////////////////////////////
#endif
