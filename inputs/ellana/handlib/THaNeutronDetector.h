#ifndef ROOT_THaNeutronDetector
#define ROOT_THaNeutronDetector

//////////////////////////////////////////////////////////////////////////
//
// THaNeutronDetector
//
//////////////////////////////////////////////////////////////////////////

#include "THaNonTrackingDetector.h"
#include "THaScintillatorPlane.h"
//#include "THaNA.h"

class THaNDTrack;

//class THaNDNeutron;

class THaNeutronDetector : public THaNonTrackingDetector {

 public:
  virtual ~THaNeutronDetector();
  THaNeutronDetector( const char* name, const char* description );
  
  Int_t          Decode( const THaEvData& );
  EStatus        Init( const TDatime& run_time);
  THaScintillatorPlane* GetPlane1() const { return fPlane1; }
  THaScintillatorPlane* GetPlane2() const { return fPlane2; }
  THaScintillatorPlane* GetPlane3() const { return fPlane3; }
  THaScintillatorPlane* GetPlane4() const { return fPlane4; }


  //  THaScintillatorPlane* GetVeto() const { return fVeto; }
  
  void           SetApparatus( THaApparatus* );

  virtual Int_t      CoarseProcess( TClonesArray& tracks );
  virtual Int_t      FineProcess( TClonesArray& tracks );
  
  Int_t ConstructTracks( TClonesArray * tracks = NULL );

  Int_t AddTrack(THaNDTrack* t);
  THaNDTrack** GetNDTracks() { return fNDTracks; }
  THaNDTrack* GetNDTrack(Int_t i) { return fNDTracks[i]; }

  Int_t GetNTracks() {return fNTracks;}

  void Clear(const Option_t* opt);

  Double_t GetMinimumAngle(Int_t i) {return fMinAngle[i];}

 protected:

  // Subdetectors
  THaScintillatorPlane* fPlane1;
  THaScintillatorPlane* fPlane2;
  THaScintillatorPlane* fPlane3;
  THaScintillatorPlane* fPlane4;

  THaNeutronDetector& operator=( const THaNeutronDetector& ) {return *this; }

  virtual Int_t  DefineVariables( EMode mode = kDefine );

 private:

  enum { kMAXTRACKS = 20 };

  Int_t fNPlanesHit;
  
  THaNDTrack* fNDTracks[kMAXTRACKS];
  Int_t      fNTracks;        // Number of tracks found in ConstructTracks
  Double_t   fTheta[kMAXTRACKS]; 
  Double_t   fPhi[kMAXTRACKS];   
  Int_t      fNHits[kMAXTRACKS]; 
  Double_t   fTOF[kMAXTRACKS]; 
  Double_t   fDist[kMAXTRACKS];   
  Double_t   fEnergyDeposit[kMAXTRACKS];   
  Bool_t   fVetoHit[kMAXTRACKS];   

  
  Double_t   fMinAngle[4];

  // Track variables
  
/*   Int_t  fNPlane [300];       // Track Plane */
/*   Int_t  fNPaddle[300];       // Track Paddle */
/*   Double_t  fXPos[300];       // Track hit x pos */
/*   Double_t  fYPos[300];       // Track hit y pos */
/*   Double_t  fZPos[300];       // Track hit z pos */
/*   Double_t  fla  [300];       // Track cor left  adc */
/*   Double_t  fra  [300];       // Track cor right adc */
/*   Double_t  fTheta[300];      // Track Theta */
/*   Double_t  fPhi  [300];      // Track Phi */
/*   Double_t  fTOF  [300];      // Track hit TOF   */
/*   Double_t  fDist [300];      // Track hit distance from target */
/*   Double_t  fP    [300];      // Track momentum by tof */
/*   Bool_t    fPID  [300];      // Track veto hit flag */

  void           Setup( const char* name,  const char* desc, 
			const char* p1nam, const char* p2nam,
			const char* p3nam, const char* p4nam,
			bool mode );


  ClassDef(THaNeutronDetector,0)
    };

#endif

