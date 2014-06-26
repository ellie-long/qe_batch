#ifndef ROOT_THaPlaneHit
#define ROOT_THaPlaneHit

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// THaPlaneHit                                                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "THaPaddle.h"

class THaPaddle;
class THaPlane;
class THaTrack;

class THaPlaneHit : public TObject { 

 public: 
  THaPlaneHit( ) ;
  THaPlaneHit( THaPaddle* paddle ) ;
  virtual ~THaPlaneHit();

  
  THaPaddle* GetPaddle()    const { return fPaddle; }
  Int_t      GetPaddleNum() const { return fPaddle->GetPaddleNumber(); }
  Double_t   GetXPos()      const { return fPaddle->GetX(); }
  Double_t   GetYPos()      const { return fPaddle->GetYPos(); }
  THaPlane*  GetPlane()     const { return fPlane; }

  void       SetPlane( THaPlane* plane ) { fPlane = plane; }
  void       SetPaddle(THaPaddle* paddle) { fPaddle = paddle; }

 protected:

  THaPaddle* fPaddle;

  THaPlane*  fPlane;

  THaPlaneHit( const THaPlaneHit& ) {}
  THaPlaneHit& operator=( const THaPlaneHit& ) { return *this; }

  ClassDef(THaPlaneHit,1)
};

#endif
