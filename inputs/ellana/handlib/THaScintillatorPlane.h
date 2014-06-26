#ifndef ROOT_THaScintillatorPlane
#define ROOT_THaScintillatorPlane

#include "THaPlane.h"
#include "TClonesArray.h"

class THaNAScintHit;

class PaddleMultiHits {
 public:
  PaddleMultiHits() : fNLHits(0), fNRHits(0) {}
  static const Int_t kMAXHITS = 6;
  Int_t GetNLHits() {return fNLHits;}
  void SetNLHits(Int_t n) {fNLHits=n;}
  Int_t GetNRHits() {return fNRHits;}
  Int_t GetLHit(Int_t i) {return fLeftHits[i];}
  Int_t GetRHit(Int_t i) {return fRightHits[i];}
  void SetNRHits(Int_t n) {fNRHits=n;}
  Int_t fLeftHits[kMAXHITS];
  Int_t fRightHits[kMAXHITS];
  Bool_t fIsLeftHit() {return fLeftHits[0]>1;}
  Int_t AddLeftHit(Int_t data) {
    if ( fNLHits < kMAXHITS ) {
      fLeftHits[fNLHits]=data; fNLHits++; return data;
    }
    return 0;   // failed -- out of range and unexpected
  }
  Int_t AddRightHit(Int_t data) {
    if ( fNRHits < kMAXHITS ) {
      fRightHits[fNRHits]=data; fNRHits++; return data;
    }
    return 0;   // failed -- out of range and unexpected
  }

 private:
  Int_t fNLHits, fNRHits;
};
  

class THaScintillatorPlane : public THaPlane {
//class THaScintillatorPlane : public THaNonTrackingDetector {

 public:
  THaScintillatorPlane( const char* name, const char* description = "", 
		   THaApparatus* a = NULL );
  virtual ~THaScintillatorPlane();

  virtual Int_t Decode( const THaEvData& );
  virtual EStatus Init( const TDatime& run_time );
  virtual Int_t CoarseProcess( TClonesArray& tracks );
  virtual Int_t FineProcess( TClonesArray& tracks );

  Bool_t        IsHit();
  void          HitCount();

  Double_t GetTDCCorLeft(int i)      { return fLT_c[i];}
  Double_t GetTDCCorRight(int i)     { return fRT_c[i];}
  Double_t GetADCCorLeft(int i)      { return fLA_c[i];}
  Double_t GetADCCorRight(int i)     { return fRA_c[i];}
  Double_t GetADCLeft(int i)      { return fLA[i];}
  Double_t GetADCRight(int i)     { return fRA[i];}
  Double_t GetTDCLeft(int i)      { return fLT[i];}
  Double_t GetTDCRight(int i)     { return fRT[i];}

  Double_t GetTDCOffLeft(int i) { return fLToff[i];}
  Double_t GetTDCOffRight(int i) { return fRToff[i];}
  Double_t GetADCPedLeft(int i) { return fLAped[i];}
  Double_t GetADCPedRight(int i) { return fRAped[i];}
  Double_t GetADCGainLeft(int i) { return fLAgain[i];}
  Double_t GetADCGainRight(int i) { return fRAgain[i];}

  void SetTDCOff(int i, Double_t loff, Double_t roff) 
    { fLToff[i] = loff; fRToff[i] = roff;}
  void SetADCPed(int i, Double_t lped, Double_t rped) 
    { fLAped[i] = lped; fRAped[i] = rped;}
  void SetADCGain(int i, Double_t lgain, Double_t rgain) 
    { fLAgain[i] = lgain; fRAgain[i] = rgain;}
  void SetYPos(int i, Double_t offset, Double_t scale) 
    { fYOffset[i] = offset; fYScale[i] = scale;}
  void SetXYZBar(int i, Double_t x, Double_t y, Double_t z) 
    { fXBar[i] = x; fYBar[i] = y; fZBar[i] = z;}
  void SetTOFPar(int i, Double_t offset, Double_t scale)
    { fTOFOffset[i] = offset; fTOFScale[i] = scale;}
  void SetBlockingBarRange(int i, Int_t bar_min, Int_t bar_max)
    { fIBlockingBarMin[i] = bar_min; fIBlockingBarMax[i] = bar_max;}
  Int_t GetBlockingBarMin(int i) { return fIBlockingBarMin[i]; }
  Int_t GetBlockingBarMax(int i) { return fIBlockingBarMax[i]; }
   
  Double_t GetTOF(int i)   { return fTOF[i];}
  Double_t GetYPos(int i)  { return fYPos[i];}
  Double_t GetYBar(int i)  { return fYBar[i];}
  Double_t GetXBar(int i)  { return fXBar[i];}
  Double_t GetZBar(int i)  { return fZBar[i];}
  Bool_t   IsHit(int i)  { return fIsHit[i];}

  Int_t GetNHits() const { return fHits->GetLast()+1; }
  TClonesArray* GetHits() const {return fHits;}
  THaNAScintHit* GetHit(Int_t i) const
    {return (THaNAScintHit*)fHits->At(i);}

 protected:

  Int_t           fNPaddlesHit;

  struct mhitarray {
    Int_t channel;
    Int_t time;
  };

  // Mapping
  UShort_t*  fFirstChan;  // Beginning channels for each detmap module

  TClonesArray* fHits;  // Hits in paddles (including multihits)
  
  // Per-event data
  Int_t      fLTNhit;    // Number of Left paddles TDC times
  Int_t      fRTNhit;    // Number of Right paddles TDC times 
  Int_t      fLANhit;    // Number of Left paddles ADC amplitudes
  Int_t      fRANhit;    // Number of Right paddles ADC amplitudes
  
  Double_t*   fLT;        // [fNelem] Left TDC time array
  Double_t*   fRT;        // [fNelem] Right TDC time array
  Double_t*   fLToff;     // [fNelem] Left TDC offset array
  Double_t*   fRToff;     // [fNelem] Right TDC offset array
  Double_t*   fLAped;     // [fNelem] Left ADC pedestal array
  Double_t*   fRAped;     // [fNelem] Right ADC pedestal array
  Double_t*   fLAgain;    // [fNelem] Left ADC gain array
  Double_t*   fRAgain;    // [fNelem] Right ADC gain array
  Double_t*   fLT_c;      // [fNelem] Left corrected TDC time array
  Double_t*   fRT_c;      // [fNelem] Right corrected TDC time array
  Double_t*   fLA;        // [fNelem] Left ADC amp array
  Double_t*   fRA;        // [fNelem] Right ADC amp array
  Double_t*   fLA_c;      // [fNelem] Left corrected ADC amp array
  Double_t*   fRA_c;      // [fNelem] Right corrected ADC amp array
  Double_t*   fTDiff;     // [fNelem] Left minus Right TDC times   
  Double_t*   fYPos;      // [fNelem] Y position along paddle
  Double_t*   fYBar;      // [fNelem] Y position of the paddle
  Double_t*   fXBar;      // [fNelem] X position of the paddle
  Double_t*   fZBar;      // [fNelem] Z position of the paddle
  Double_t*   fDist;      // [fNelem] Distance of the paddle from the target at Hall center (Neutron Detector at 6m).
  Double_t*   fTOFOffset; // [fNelem] Offset for TOF
  Double_t*   fTOFScale;  // [fNelem] Scale factor for TOF
  Double_t*   fYOffset;   // [fNelem] Offset for Y
  Double_t*   fYScale;    // [fNelem] Scale factor for Y
  Double_t*   fTOF;       // [fNelem] TOF to  paddle
  Bool_t*     fIsHit;     // [fNelem] Is Paddle hit 
  Int_t*     fNLHits;     // [fNelem] Number of hits in left paddle
  Int_t*     fNRHits;     // [fNelem] Number of hits in right paddle
  Int_t*      fIBlockingBarMin; // [fNelem] Smallest blocking bar id
  Int_t*      fIBlockingBarMax; // [fNelem] Smallest blocking bar id

  PaddleMultiHits* fMultiHits; // [fNelem] Array of multihits

  static const char NDEST = 2;
  struct DataDest {
    Int_t*    nthit;
    Int_t*    nahit;
    Double_t*  tdc;
    Double_t*  adc;
  } fDataDest[NDEST];     // Lookup table for decoder
  
  void           ClearEvent();
  void           DeleteArrays();
  virtual Int_t  ReadDatabase( const TDatime& date );
  virtual Int_t  DefineVariables( EMode mode = kDefine );

  ClassDef(THaScintillatorPlane,0)   // Generic trigger scintillator plane class
};

////////////////////////////////////////////////////////////////////////////////

#endif
