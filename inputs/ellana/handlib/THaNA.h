#ifndef ROOT_THaNA
#define ROOT_THaNA

////////////////////////////////////////////////////////////////////////////
//
// THaNA
//
////////////////////////////////////////////////////////////////////////////

#include "THaApparatus.h"
#include "TClonesArray.h"
#include "THaScintillatorPlane.h"
#include "THaVeto.h"
#include "THaNeutronDetector.h"
#include "THaNDTrack.h"
#include "THaNDNeutron.h"


class THaNDTrack;

//class THaNDNeutron;

class THaNA : public THaApparatus {

  // silly comment

 public:
  
  THaNA( const char* name, const char* description);
  virtual ~THaNA();

  THaNeutronDetector* GetNeutronDetector() const {return fNeutronDetector;}
  THaVeto* GetVeto() const {return fVeto;}

  Int_t GetNTracks() { return fNTracks; }
  THaNDTrack* GetNDTrack(Int_t i) { return static_cast<THaNDTrack*>((*fTracks)[i]); }

  Int_t GetNNeutrons() {return fNNeutrons;}
  THaNDNeutron* GetNDNeutron(Int_t i) { return static_cast<THaNDNeutron*>((*fNeutrons)[i]); }
  

  virtual EStatus      Init( const TDatime& run_time );
  virtual EStatus      InitBlockingBars( const TDatime& run_time );

  virtual void             Clear( Option_t* opt="");
  virtual Int_t            CoarseProcess();
  virtual Int_t            Reconstruct();
  virtual Int_t            TrackReconstruct();
  virtual Int_t            GetTrackCharge();
  virtual Bool_t           GetTrackVetos();

  Int_t        Decode( const THaEvData& );

          Double_t         GetThetaGeo() const { return fThetaGeo; }
          Double_t         GetPhiGeo()   const { return fPhiGeo; }
          Double_t         GetThetaSph() const { return fThetaSph; }
          Double_t         GetPhiSph()   const { return fPhiSph; }
          Double_t         GetDistance() const { return fDistance; }

  Int_t AddwvTrack(THaNDTrack* t);

  Int_t AddwovTrack(THaNDTrack* t);

  void SetNeutronVetoTimeLimits(Double_t min, Double_t max) {
    VetoTimeMin = min; VetoTimeMax = max;}
  
 protected:

  enum { kMAXTRACKS = 20 };

  static const Int_t kInitTrackMultiplicity = 200;

  TClonesArray*   fTracks;              //Tracks
  TClonesArray*   fwvTracks;              //Tracks
  TClonesArray*   fwovTracks;              //Tracks

  THaNDTrack*    fNDTracks[kMAXTRACKS];            // Tracks

  Double_t   fTheta[kMAXTRACKS]; 
  Double_t   fPhi[kMAXTRACKS];   
  Int_t      fNHits[kMAXTRACKS]; 
  Double_t   fTOF[kMAXTRACKS];  
  Double_t   fDist[kMAXTRACKS];
  Double_t   fEnergyDeposit[kMAXTRACKS]; 
  Int_t   fFirstHitPaddle[kMAXTRACKS];  
  Int_t   fFirstHitPlane[kMAXTRACKS];  

  THaNDTrack*    fNDwvTracks[kMAXTRACKS];            // Tracks with veto hit

  Double_t   fwvTheta[kMAXTRACKS]; 
  Double_t   fwvPhi[kMAXTRACKS];   
  Int_t      fwvNHits[kMAXTRACKS]; 
  Double_t   fwvTOF[kMAXTRACKS];   
  Double_t   fwvEnergyDeposit[kMAXTRACKS]; 
  Int_t      fLeftIsHit[kMAXTRACKS];
  Int_t      fRightIsHit[kMAXTRACKS];


  THaNDTrack*   fNDwovTracks[kMAXTRACKS];            // Tracks without veto hit

  Double_t   fwovTheta[kMAXTRACKS]; 
  Double_t   fwovPhi[kMAXTRACKS];   
  Int_t      fwovNHits[kMAXTRACKS]; 
  Double_t   fwovTOF[kMAXTRACKS];   
  Double_t   fwovEnergyDeposit[kMAXTRACKS];   

  Double_t        fThetaGeo;            //In-plane geographic central angle (rad)
  Double_t        fPhiGeo;              //Out-of-plane geographic central angle (rad) 
  Double_t        fThetaSph, fPhiSph;   //Central angles in spherical coords. (rad)
  Double_t        fSinThGeo, fCosThGeo; //Sine and cosine of central angles
  Double_t        fSinPhGeo, fCosPhGeo; // in geographical coordinates
  Double_t        fSinThSph, fCosThSph; //Sine and cosine of central angles in 
  Double_t        fSinPhSph, fCosPhSph; // spherical coordinates
  Double_t        fDistance;            //Distance from apparatus to target center (m)  
  Bool_t          fCoarseDone;          //Coarse Reconstruct done
  
  THaNeutronDetector* fNeutronDetector;
  THaVeto* fVeto;
  
  Int_t      fNTracks;        // Number of tracks found in ConstructTracks
  Int_t      fNwvTracks;        // Number of tracks found with veto hit
  Int_t      fNwovTracks;        // Number of tracks found without veto hit


  enum { kMAXNEUTRONS = 50 };
  Int_t fNNeutrons; // Number of neutrons found in NeutronProcess
  //THaNDNeutron* fNDNeutrons[kMAXNEUTRONS];// uncommented

  Double_t   fNTOF[kMAXNEUTRONS]; // [fNNeutrons] Neutron Time
  Int_t   fNPaddle[kMAXNEUTRONS]; // [fNNeutrons] Neutron Bar #
  Int_t   fNPlane[kMAXNEUTRONS];  // [fNNeutrons] Neutron Array Plane
  Double_t  fNTheta[kMAXNEUTRONS]; // [fNNeutrons] Neutron Theta 
  Double_t  fNPhi  [kMAXNEUTRONS]; // [fNNeutrons] Neutron Phi 
  Double_t  fNEnergyDeposit  [kMAXNEUTRONS]; // [fNNeutrons] Neutron Energy Deposit

  Double_t   fNDist[kMAXNEUTRONS];  // [fNNeutrons] Distance of hit bar to target
 

 
  static const Int_t kInitNeutronMultiplicity = 200;
  TClonesArray*   fNeutrons;  // Neutrons passing veto criteria
  
  
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
  
  
  // Veto array 
  
  Int_t  fVetoPairs [300][10];       // Track Plane
  
  
  // Subdetectors
  THaScintillatorPlane* fPlane1;
  THaScintillatorPlane* fPlane2;
  THaScintillatorPlane* fPlane3;
  THaScintillatorPlane* fPlane4;
  //  THaScintillatorPlane* fVeto;
  
  virtual Int_t  ReadRunDatabase( const TDatime& date );
  virtual Int_t  DefineVariables( EMode mode = kDefine );

 private:

  virtual Int_t            NeutronProcess();
  void           Setup( const char* name,  const char* desc, 
			const char* ndnam, const char* vnam );
  
  Double_t VetoTimeMin;
  Double_t VetoTimeMax;

  ClassDef(THaNA,0)     //A generic non spectrometer apparatus
    };
    
#endif

