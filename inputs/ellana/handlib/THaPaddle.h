#ifndef ROOT_THaPaddle
#define ROOT_THaPaddle

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// THaPaddle                                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TObject.h"

class THaPaddle : public TObject {

 public: 
  virtual ~THaPaddle();
  THaPaddle();
  void SetPaddleNumber(int number);
  Int_t GetPaddleNumber() { return fPaddleNumber; }
  Double_t GetX() { return fX; }
  Double_t GetY() { return fY; }
  Double_t GetZ() { return fZ; }
  virtual Double_t GetYPos() = 0;

  void SetX( double x ) { fX=x; }
  void SetY( double y ) { fY=y; }
  void SetZ( double z ) { fZ=z; }

  virtual Bool_t IsHit() = 0;

 protected:
  Int_t fPaddleNumber;
  Double_t fX, fY, fZ;

  ClassDef(THaPaddle,0)   // Generic scintillator paddle class
};

////////////////////////////////////////////////////////////////////////////////

#endif


    



