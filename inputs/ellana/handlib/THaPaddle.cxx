//*-- Author :    Olivier Gayou   1-Apr-04

//////////////////////////////////////////////////////////////////////////
//
// THaPaddle
//
//////////////////////////////////////////////////////////////////////////

#include "THaPaddle.h"

ClassImp(THaPaddle)

//______________________________________________________________________________
  THaPaddle::THaPaddle() : TObject(), fPaddleNumber(0), fX(0), fY(0), fZ(0)
{
  // Normal constructor
}

//______________________________________________________________________________
THaPaddle::~THaPaddle()
{
  // Destructor

}

//______________________________________________________________________________
void THaPaddle::SetPaddleNumber(Int_t number) 
{
  fPaddleNumber=number;
}

