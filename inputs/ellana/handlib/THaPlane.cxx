//*-- Author :    Olivier Gayou, Apr-1-2004

//////////////////////////////////////////////////////////////////////////
//
// THaPlane
//
//////////////////////////////////////////////////////////////////////////

#include "THaPlane.h"

ClassImp(THaPlane)

//______________________________________________________________________________
THaPlane::THaPlane( const char* name, 
		    const char* description,
		    THaApparatus* apparatus )
  : THaNonTrackingDetector(name,description,apparatus)
{
  // Normal constructor with name and description

}

//______________________________________________________________________________
THaPlane::~THaPlane()
{
  // Destructor

}

