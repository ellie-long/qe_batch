//////////////////////////////////////////////////////////////////////////
//
// Bigbite lib replay script definition header
//
// It is suggested to use this file set replay environmental variable for 
// different machine. So, they can use same replay script
//	
//////////////////////////////////////////////////////////////////////////
//	
//	Author : Jin Huang (jinhuang@jlab.org)    Aug 2007
//	Modify History:
//
//      27 Mar 08 ole  Change ROOT file names for DetL and PhysL replays
//                     from _det_nnnn to _det_L_nnnn etc.
//
//////////////////////////////////////////////////////////////////////////

#ifndef ROOT_REPLAY_DEF
#define ROOT_REPLAY_DEF


//////////////////////////////////////////////////////////////////
// extra structures
//////////////////////////////////////////////////////////////////

#include "TObject.h" //trick to avoid error: `Int_t' does not name a type
typedef enum 
{// see replay.C for interpretation of these flags
    kReplayBigBiteTp    =1<<0,
    kReplayBigBiteMWDC  =1<<1,
    kReplayBigBiteOther =1<<2,
    kReplayBigBiteSet   =kReplayBigBiteTp+kReplayBigBiteMWDC+kReplayBigBiteOther,
    kReplayHRSL         =1<<3,
    kReplayHRSR         =1<<4,
    //kReplayBeam         =1<<5,
    kReplayAllDet=kReplayBigBiteTp+kReplayBigBiteMWDC
    +kReplayBigBiteOther+kReplayHRSL+kReplayHRSR,
    kReplayPhysics      =1<<11,
    kReplayPhysicsHRSR  =1<<12,
    kReplayScalers      =1<<20,
    kReplayDecData      =1<<21
}eReplayMode;

typedef struct _sReplaySetUp
{
    Int_t ReplayMode;   //use members of eReplayMode to specify detector to run
    Int_t DefReplayNum; //defaut replay event num
    char* OutFileFormat;//output file format
    char* OutDefineFile;//out define
    char* CutDefineFile;//cut define
}sReplaySetUp;


//////////////////////////////////////////////////////////////////
// common defines
//////////////////////////////////////////////////////////////////

static const char* PATHS[] = {
    "/adaql2/data1",
    "/adaql2/data2",
    "/adaql2/data3",
    "/adaql2/data4",
    "/adaql1/data1",
    "/adaql1/data2",
    "/adaql1/data3",
    "/adaql1/data4",
    "/adaqfs/home/adaq/rawdata_links",
    "/local/scratch/home/jinhuang/BigBite/RawData",
    ".","./raw/",
    "/agen4/data1/raw/hadron/",
    "/agen4/data2/raw/hadron/hadron",
    "/cache/mss/halla/e04007/raw/",
    0
};

static const char* RAW_DATA_FORMAT="%s/e04007_%d.dat.%d";

static const char* STD_REPLAY_OUTPUT_DIR="./ROOTfiles";
static const char* CUSTOM_REPLAY_OUTPUT_DIR="./ScratchROOTfiles";

static const char* SUMMARY_PHYSICS_FORMAT="./summaryfiles/summaryphy_%d.log";

static const Int_t ANA_MARK_INTERVAL=1000;

//////////////////////////////////////////////////////////////////
// replay specific defines
//////////////////////////////////////////////////////////////////

sReplaySetUp DefaultReplay=
{
    kReplayBigBiteTp+kReplayBigBiteMWDC,//Int_t ReplayMode
    -1,//Int_t DefReplayNum
    "%s/e04007_test_%d.root",//char* OutFileFormat
    "./replay_test.odef",//char* OutDefineFile
    "./replay_test.cdef"//char* CutDefineFile
};

/////////////////////////////////////////////////////////////////
sReplaySetUp Det_Replay=
{
    kReplayAllDet-kReplayHRSR,//Int_t ReplayMode
    10000,//Int_t DefReplayNum
    "%s/e04007_det_%d.root",//char* OutFileFormat
    "./replay_det.odef",//char* OutDefineFile
    "./replay_det.cdef"//char* CutDefineFile
};

sReplaySetUp Phys_Replay=
{
    kReplayAllDet-kReplayHRSR+kReplayPhysics,//Int_t ReplayMode
    -1,//Int_t DefReplayNum
    "%s/e04007_phys_%d.root",//char* OutFileFormat
    "./replay_phys.odef",//char* OutDefineFile
    "./replay_phys.cdef"//char* CutDefineFile
};


sReplaySetUp L_HRS_Phys_Replay=
{
    kReplayHRSL+kReplayPhysics,//Int_t ReplayMode
    -1,//Int_t DefReplayNum
    "%s/e04007_phys_L_%d.root",//char* OutFileFormat
    "./replay_phys.odef",//char* OutDefineFile
    "./replay_phys.cdef"//char* CutDefineFile
};

sReplaySetUp L_HRS_Det_Replay=
{
    kReplayHRSL,//Int_t ReplayMode
    10000,//Int_t DefReplayNum
    "%s/e04007_det_L_%d.root",//char* OutFileFormat
    "./replay_det.odef",//char* OutDefineFile
    "./replay_det.cdef"//char* CutDefineFile
};

sReplaySetUp R_HRS_Phys_Replay=
{
    kReplayHRSR+kReplayPhysicsHRSR,//Int_t ReplayMode
    -1,//Int_t DefReplayNum
    "%s/e04007_phys_R_%d.root",//char* OutFileFormat
    "./replay_R.odef",//char* OutDefineFile
    "./replay_R.cdef"//char* CutDefineFile
};

sReplaySetUp R_HRS_Det_Replay=
{
    kReplayHRSR,//Int_t ReplayMode
    10000,//Int_t DefReplayNum
    "%s/e04007_det_R_%d.root",//char* OutFileFormat
    "./replay_R.odef",//char* OutDefineFile
    "./replay_R.cdef"//char* CutDefineFile
};

sReplaySetUp PED_Replay=
{
    kReplayHRSL+kReplayBigBiteTp,//Int_t ReplayMode
    -1,//Int_t DefReplayNum
    "%s/e04007_ped_%d.root",//char* OutFileFormat
    "./replay_det.odef",//char* OutDefineFile
    "./replay_det.cdef"//char* CutDefineFile
};

sReplaySetUp DEC_Replay=
{
    kReplayDecData,//Int_t ReplayMode
    -1,//Int_t DefReplayNum
    "%s/e04007_dec_%d.root",//char* OutFileFormat
    "./replay_test.odef",//char* OutDefineFile
    "./replay_test.cdef"//char* CutDefineFile
};



//////////////////////////////////////////////////////////////////
// variables for replay_test.C
//////////////////////////////////////////////////////////////////


#define DEFAULT_RUN_NUM		1435
#define	DEFAULT_EVENT_NUM	1
#define REPLAY_LOG_FILE		"replay_test.log"
#define REPLAY_LOG_FILE2	"replay_test_old_code.log"


#endif//#define ROOT_REPLAY_DEF

