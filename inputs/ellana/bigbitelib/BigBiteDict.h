/********************************************************************
* BigBiteDict.h
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************************/
#ifdef __CINT__
#error BigBiteDict.h/C is only for compilation. Abort cint.
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define G__ANSIHEADER
#define G__DICTIONARY
#define G__PRIVATE_GVALUE
#include "G__ci.h"
#include "FastAllocString.h"
extern "C" {
extern void G__cpp_setup_tagtableBigBiteDict();
extern void G__cpp_setup_inheritanceBigBiteDict();
extern void G__cpp_setup_typetableBigBiteDict();
extern void G__cpp_setup_memvarBigBiteDict();
extern void G__cpp_setup_globalBigBiteDict();
extern void G__cpp_setup_memfuncBigBiteDict();
extern void G__cpp_setup_funcBigBiteDict();
extern void G__set_cpp_environmentBigBiteDict();
}


#include "TObject.h"
#include "TMemberInspector.h"
#include "THaBigBite.h"
#include "THaBigBiteTpMwdc.h"
#include "BBDecData.h"
#include "THaOptics.h"
#include "THaOpticsAGen.h"
#include "THaOpticsHRS.h"
#include "THaOpticsAnalytical.h"
#include "THaOpticsNoFeild.h"
#include "THaTriggerPlane.h"
#include "THaTriggerPlaneHit.h"
#include "THaScintPlane.h"
#include "THaAdcHit.h"
#include "THaPartialHit.h"
#include "THaScintBar.h"
#include "THaScintHit.h"
#include "THaScintPMT.h"
#include "THaTdcHit.h"
#include "THaMWDC.h"
#include "THaMWDCPlane.h"
#include "THaMWDCGroup.h"
#include "THaMWDCHit.h"
#include "THaMWDCLine.h"
#include "THaVDCTableTTDConv.h"
#include "THaVDC2DTableTTDConv.h"
#include "THaVDCFuncTTDConv.h"
#include "THaVDCLinearTTDConv.h"
#include "THaBBTotalShower.h"
#include "THaTimingPlane.h"
#include "THaScintPlaneDet.h"
#include "THaBBShower.h"
#include "THaBBShowerCluster.h"
#include "THaBBShowerBlock.h"
#include "MWDC.h"
#include "WirePlane.h"
#include "Hit.h"
#include "TimeToDistConv.h"
#include "Hitpattern.h"
#include "Projection.h"
#include "Pattern.h"
#include "PatternTree.h"
#include "PatternGenerator.h"
#include "TreeWalk.h"
#include "Road.h"
#include "BigBite.h"
#include "THaHe3Target.h"
#include "THaADCHe3Spin.h"
#include "THaBitHe3Spin.h"
#include "THaHe3SpinModule.h"
#include "Helper.h"
#include "Types.h"
#include <algorithm>
namespace std { }
using namespace std;

#ifndef G__MEMFUNCBODY
#endif

extern G__linked_taginfo G__BigBiteDictLN_TClass;
extern G__linked_taginfo G__BigBiteDictLN_TBuffer;
extern G__linked_taginfo G__BigBiteDictLN_TMemberInspector;
extern G__linked_taginfo G__BigBiteDictLN_TObject;
extern G__linked_taginfo G__BigBiteDictLN_TNamed;
extern G__linked_taginfo G__BigBiteDictLN_TString;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEunsignedsPshortcOallocatorlEunsignedsPshortgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEunsignedsPintcOallocatorlEunsignedsPintgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEfloatcOallocatorlEfloatgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEdoublecOallocatorlEdoublegRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_basic_ostreamlEcharcOchar_traitslEchargRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_TClonesArray;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_THaRunBase;
extern G__linked_taginfo G__BigBiteDictLN_TDatime;
extern G__linked_taginfo G__BigBiteDictLN_RVarDef;
extern G__linked_taginfo G__BigBiteDictLN_THaEvData;
extern G__linked_taginfo G__BigBiteDictLN_TVector3;
extern G__linked_taginfo G__BigBiteDictLN_THaOutput;
extern G__linked_taginfo G__BigBiteDictLN_THaAnalysisObject;
extern G__linked_taginfo G__BigBiteDictLN_THaAnalysisObjectcLcLEStatus;
extern G__linked_taginfo G__BigBiteDictLN_THaAnalysisObjectcLcLEMode;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEstringcOallocatorlEstringgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlEstringcOallocatorlEstringgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_THaDetector;
extern G__linked_taginfo G__BigBiteDictLN_THaApparatus;
extern G__linked_taginfo G__BigBiteDictLN_TVector2;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTBaselEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTBaselEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TVectorTlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TVectorTlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TElementActionTlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TElementPosActionTlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TElementActionTlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TElementPosActionTlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTRow_constlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTRowlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTDiag_constlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTColumn_constlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTFlat_constlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSub_constlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSparseRow_constlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSparseDiag_constlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTColumnlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTDiaglEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTFlatlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSublEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSparseRowlEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSparseDiaglEfloatgR;
extern G__linked_taginfo G__BigBiteDictLN_TRotation;
extern G__linked_taginfo G__BigBiteDictLN_THaVertexModule;
extern G__linked_taginfo G__BigBiteDictLN_THaTrack;
extern G__linked_taginfo G__BigBiteDictLN_THaSpectrometer;
extern G__linked_taginfo G__BigBiteDictLN_THaTrackingModule;
extern G__linked_taginfo G__BigBiteDictLN_TIterator;
extern G__linked_taginfo G__BigBiteDictLN_TSeqCollection;
extern G__linked_taginfo G__BigBiteDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR;
extern G__linked_taginfo G__BigBiteDictLN_THaPidDetector;
extern G__linked_taginfo G__BigBiteDictLN_TBits;
extern G__linked_taginfo G__BigBiteDictLN_THaBenchmark;
extern G__linked_taginfo G__BigBiteDictLN_THaDetMap;
extern G__linked_taginfo G__BigBiteDictLN_THaDetectorBase;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEintcOallocatorlEintgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_TRef;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSymlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTRow_constlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTRowlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTDiag_constlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTColumn_constlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTFlat_constlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSub_constlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSparseRow_constlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSparseDiag_constlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTColumnlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTDiaglEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTFlatlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSublEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSparseRowlEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_TMatrixTSparseDiaglEdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_THaOptics;
extern G__linked_taginfo G__BigBiteDictLN_THaBigBite;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearch;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLMWDC;
extern G__linked_taginfo G__BigBiteDictLN_THaTriggerPlane;
extern G__linked_taginfo G__BigBiteDictLN_THaBigBiteTpMwdc;
extern G__linked_taginfo G__BigBiteDictLN_THashTable;
extern G__linked_taginfo G__BigBiteDictLN_BBdataLoc;
extern G__linked_taginfo G__BigBiteDictLN_BBDecData;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEBBdataLocmUcOallocatorlEBBdataLocmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlEBBdataLocmUcOallocatorlEBBdataLocmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETH1FmUcOallocatorlETH1FmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETH1FmUcOallocatorlETH1FmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_THaOpticscLcLTOpticsDir;
extern G__linked_taginfo G__BigBiteDictLN_THaOpticscLcLTOpticsPos;
extern G__linked_taginfo G__BigBiteDictLN_THaOpticscLcLTOpticsDircLcLECoordSys;
extern G__linked_taginfo G__BigBiteDictLN_THaOpticsAGen;
extern G__linked_taginfo G__BigBiteDictLN_THaOpticsHRS;
extern G__linked_taginfo G__BigBiteDictLN_THaOpticsHRScLcLEFPMatrixElemTags;
extern G__linked_taginfo G__BigBiteDictLN_THaOpticsHRScLcLdA;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETHaOpticsHRScLcLTHaMatrixElementcOallocatorlETHaOpticsHRScLcLTHaMatrixElementgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETHaOpticsHRScLcLTHaMatrixElementcOallocatorlETHaOpticsHRScLcLTHaMatrixElementgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_TComplex;
extern G__linked_taginfo G__BigBiteDictLN_THaOpticsAnalytical;
extern G__linked_taginfo G__BigBiteDictLN_THaOpticsNoFeild;
extern G__linked_taginfo G__BigBiteDictLN_THaSpectrometerDetector;
extern G__linked_taginfo G__BigBiteDictLN_THaNonTrackingDetector;
extern G__linked_taginfo G__BigBiteDictLN_THaScintPlane;
extern G__linked_taginfo G__BigBiteDictLN_THaScintPMT;
extern G__linked_taginfo G__BigBiteDictLN_THaScintHit;
extern G__linked_taginfo G__BigBiteDictLN_THaScintBar;
extern G__linked_taginfo G__BigBiteDictLN_THaTriggerPlaneHit;
extern G__linked_taginfo G__BigBiteDictLN_THaScintBarcLcLEBarType;
extern G__linked_taginfo G__BigBiteDictLN_THaSubDetector;
extern G__linked_taginfo G__BigBiteDictLN_THaAdcHit;
extern G__linked_taginfo G__BigBiteDictLN_THaTdcHit;
extern G__linked_taginfo G__BigBiteDictLN_THaPartialHit;
extern G__linked_taginfo G__BigBiteDictLN_THaScintPlanecLcLESide;
extern G__linked_taginfo G__BigBiteDictLN_THaTrackingDetector;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDCPlane;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDCGroup;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDCHit;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDC;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETHaMWDCGroupmUcOallocatorlETHaMWDCGroupmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETHaMWDCGroupmUcOallocatorlETHaMWDCGroupmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDCcLcLdA;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDCcLcLETrackingMode;
extern G__linked_taginfo G__BigBiteDictLN_THaVar;
extern G__linked_taginfo G__BigBiteDictLN_THaVDCWire;
extern G__linked_taginfo G__BigBiteDictLN_THaVDCTimeToDistConv;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDCPlanecLcLEPlaneType;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETHaMWDCHitmUcOallocatorlETHaMWDCHitmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETHaMWDCHitmUcOallocatorlETHaMWDCHitmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDCGroupcLcLEGroupStatus;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDCGroupcLcLETrackingMode;
extern G__linked_taginfo G__BigBiteDictLN_THaVDCHit;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDCHitcLcLELR;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDCHitcLcLEHitStatus;
extern G__linked_taginfo G__BigBiteDictLN_THaMWDCLine;
extern G__linked_taginfo G__BigBiteDictLN_THaVDCTableTTDConv;
extern G__linked_taginfo G__BigBiteDictLN_THaVDC2DTableTTDConv;
extern G__linked_taginfo G__BigBiteDictLN_THaVDCFuncTTDConv;
extern G__linked_taginfo G__BigBiteDictLN_THaVDCLinearTTDConv;
extern G__linked_taginfo G__BigBiteDictLN_THaBBShower;
extern G__linked_taginfo G__BigBiteDictLN_THaBBTotalShower;
extern G__linked_taginfo G__BigBiteDictLN_THaTimingPlane;
extern G__linked_taginfo G__BigBiteDictLN_THaScintPlaneDet;
extern G__linked_taginfo G__BigBiteDictLN_THaScintPlaneDetcLcLESide;
extern G__linked_taginfo G__BigBiteDictLN_THaBBShowerBlock;
extern G__linked_taginfo G__BigBiteDictLN_THaBBShowerCluster;
extern G__linked_taginfo G__BigBiteDictLN_THaDetMapcLcLModule;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLEProjType;
extern G__linked_taginfo G__BigBiteDictLN_pairlEdoublecOdoublegR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEpairlEdoublecOdoublegRcOallocatorlEpairlEdoublecOdoublegRsPgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlEpairlEdoublecOdoublegRcOallocatorlEpairlEdoublecOdoublegRsPgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLWirePlane;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLProjection;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLRoad;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLThreadCtrl;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETreeSearchcLcLRoadmUcOallocatorlETreeSearchcLcLRoadmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETreeSearchcLcLRoadmUcOallocatorlETreeSearchcLcLRoadmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_binary_functionlETreeSearchcLcLRoadmUcOTreeSearchcLcLRoadmUcOboolgR;
extern G__linked_taginfo G__BigBiteDictLN_setlETreeSearchcLcLRoadmUcOlesslETreeSearchcLcLRoadmUgRcOallocatorlETreeSearchcLcLRoadmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETreeSearchcLcLWirePlanemUcOallocatorlETreeSearchcLcLWirePlanemUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETreeSearchcLcLWirePlanemUcOallocatorlETreeSearchcLcLWirePlanemUgRsPgRcLcLiterator;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETreeSearchcLcLWirePlanemUcOallocatorlETreeSearchcLcLWirePlanemUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETreeSearchcLcLProjectionmUcOallocatorlETreeSearchcLcLProjectionmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETreeSearchcLcLProjectionmUcOallocatorlETreeSearchcLcLProjectionmUgRsPgRcLcLiterator;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETreeSearchcLcLProjectionmUcOallocatorlETreeSearchcLcLProjectionmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLMWDCcLcLdA;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLMWDCcLcLFitRes_t;
extern G__linked_taginfo G__BigBiteDictLN_pairlEdoublecOvectorlETreeSearchcLcLRoadmUcOallocatorlETreeSearchcLcLRoadmUgRsPgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_listlEpairlEdoublecOvectorlETreeSearchcLcLRoadmUcOallocatorlETreeSearchcLcLRoadmUgRsPgRsPgRcOallocatorlEpairlEdoublecOvectorlETreeSearchcLcLRoadmUcOallocatorlETreeSearchcLcLRoadmUgRsPgRsPgRsPgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEvectorlETreeSearchcLcLRoadmUcOallocatorlETreeSearchcLcLRoadmUgRsPgRcOallocatorlEvectorlETreeSearchcLcLRoadmUcOallocatorlETreeSearchcLcLRoadmUgRsPgRsPgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlEvectorlETreeSearchcLcLRoadmUcOallocatorlETreeSearchcLcLRoadmUgRsPgRcOallocatorlEvectorlETreeSearchcLcLRoadmUcOallocatorlETreeSearchcLcLRoadmUgRsPgRsPgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLTimeToDistConv;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLHit;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLFitCoord;
extern G__linked_taginfo G__BigBiteDictLN_binary_functionlETreeSearchcLcLWirePlanemUcOTreeSearchcLcLWirePlanemUcOboolgR;
extern G__linked_taginfo G__BigBiteDictLN_unary_functionlETreeSearchcLcLWirePlanemUcOboolgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLWirePlanecLcLdA;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLLinearTTD;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLTanhFitTTD;
extern G__linked_taginfo G__BigBiteDictLN_binary_functionlETreeSearchcLcLHitmUcOTreeSearchcLcLHitmUcOboolgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLMCTrack;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLMCHit;
extern G__linked_taginfo G__BigBiteDictLN_pairlETObjectmUcOTObjectmUgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLHitPairIter;
extern G__linked_taginfo G__BigBiteDictLN_setlETreeSearchcLcLHitmUcOTreeSearchcLcLHitcLcLWireNumLesscOallocatorlETreeSearchcLcLHitmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLHitSet;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLPattern;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLLink;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLNodeDescriptor;
extern G__linked_taginfo G__BigBiteDictLN_pairlETreeSearchcLcLNodeDescriptorcOTreeSearchcLcLHitSetgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLNodeVisitor;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLNodeVisitorcLcLETreeOp;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLTreeWalk;
extern G__linked_taginfo G__BigBiteDictLN_maplETreeSearchcLcLPatternmUcOintcOlesslETreeSearchcLcLPatternmUgRcOallocatorlEpairlETreeSearchcLcLPatternmUsPconstcOintgRsPgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLBits;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLPatternTree;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLHitpattern;
extern G__linked_taginfo G__BigBiteDictLN_pairlEunsignedsPintcOunsignedsPintgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETreeSearchcLcLHitmUcOallocatorlETreeSearchcLcLHitmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETreeSearchcLcLHitmUcOallocatorlETreeSearchcLcLHitmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEvectorlETreeSearchcLcLHitmUcOallocatorlETreeSearchcLcLHitmUgRsPgRcOallocatorlEvectorlETreeSearchcLcLHitmUcOallocatorlETreeSearchcLcLHitmUgRsPgRsPgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlEvectorlETreeSearchcLcLHitmUcOallocatorlETreeSearchcLcLHitmUgRsPgRcOallocatorlEvectorlETreeSearchcLcLHitmUcOallocatorlETreeSearchcLcLHitmUgRsPgRsPgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLProjectioncLcLdA;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEpairlETreeSearchcLcLNodeDescriptorcOTreeSearchcLcLHitSetgRmUcOallocatorlEpairlETreeSearchcLcLNodeDescriptorcOTreeSearchcLcLHitSetgRmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlEpairlETreeSearchcLcLNodeDescriptorcOTreeSearchcLcLHitSetgRmUcOallocatorlEpairlETreeSearchcLcLNodeDescriptorcOTreeSearchcLcLHitSetgRmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLTreeParam_t;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETreeSearchcLcLPatterncOallocatorlETreeSearchcLcLPatterngRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETreeSearchcLcLPatterncOallocatorlETreeSearchcLcLPatterngRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETreeSearchcLcLLinkcOallocatorlETreeSearchcLcLLinkgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETreeSearchcLcLLinkcOallocatorlETreeSearchcLcLLinkgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLPatternGenerator;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLPatternGeneratorcLcLStatistics_t;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLPatternGeneratorcLcLHashNode;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETreeSearchcLcLPatternGeneratorcLcLHashNodecOallocatorlETreeSearchcLcLPatternGeneratorcLcLHashNodegRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETreeSearchcLcLPatternGeneratorcLcLHashNodecOallocatorlETreeSearchcLcLPatternGeneratorcLcLHashNodegRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLBuildInfo_t;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLRoadcLcLPoint;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETreeSearchcLcLRoadcLcLPointmUcOallocatorlETreeSearchcLcLRoadcLcLPointmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETreeSearchcLcLRoadcLcLPointmUcOallocatorlETreeSearchcLcLRoadcLcLPointmUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_listlEconstsPpairlETreeSearchcLcLNodeDescriptorcOTreeSearchcLcLHitSetgRmUcOallocatorlEconstsPpairlETreeSearchcLcLNodeDescriptorcOTreeSearchcLcLHitSetgRmUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLRoadcLcLCorners;
extern G__linked_taginfo G__BigBiteDictLN_vectorlEvectorlETreeSearchcLcLRoadcLcLPointmUcOallocatorlETreeSearchcLcLRoadcLcLPointmUgRsPgRcOallocatorlEvectorlETreeSearchcLcLRoadcLcLPointmUcOallocatorlETreeSearchcLcLRoadcLcLPointmUgRsPgRsPgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlEvectorlETreeSearchcLcLRoadcLcLPointmUcOallocatorlETreeSearchcLcLRoadcLcLPointmUgRsPgRcOallocatorlEvectorlETreeSearchcLcLRoadcLcLPointmUcOallocatorlETreeSearchcLcLRoadcLcLPointmUgRsPgRsPgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_TreeSearchcLcLBigBite;
extern G__linked_taginfo G__BigBiteDictLN_maplEstringcOTObjArraymUcOlesslEstringgRcOallocatorlEpairlEconstsPstringcOTObjArraymUgRsPgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_THaHe3SpinModule;
extern G__linked_taginfo G__BigBiteDictLN_THaHe3SpinModulecLcLEHe3Spin;
extern G__linked_taginfo G__BigBiteDictLN_THaHe3Target;
extern G__linked_taginfo G__BigBiteDictLN_vectorlETHaHe3SpinModulemUcOallocatorlETHaHe3SpinModulemUgRsPgR;
extern G__linked_taginfo G__BigBiteDictLN_reverse_iteratorlEvectorlETHaHe3SpinModulemUcOallocatorlETHaHe3SpinModulemUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__BigBiteDictLN_THaADCHe3Spin;
extern G__linked_taginfo G__BigBiteDictLN_THaADCHe3SpincLcLADCStateBound;
extern G__linked_taginfo G__BigBiteDictLN_THaADCHe3SpincLcLChanDef_t;
extern G__linked_taginfo G__BigBiteDictLN_THaBitHe3Spin;

/* STUB derived class for protected member access */
typedef vector<TreeSearch::WirePlane*,allocator<TreeSearch::WirePlane*> > G__vectorlETreeSearchcLcLWirePlanemUcOallocatorlETreeSearchcLcLWirePlanemUgRsPgR;
typedef vector<TreeSearch::Projection*,allocator<TreeSearch::Projection*> > G__vectorlETreeSearchcLcLProjectionmUcOallocatorlETreeSearchcLcLProjectionmUgRsPgR;
typedef pair<TObject*,TObject*> G__pairlETObjectmUcOTObjectmUgR;
typedef pair<TreeSearch::NodeDescriptor,TreeSearch::HitSet> G__pairlETreeSearchcLcLNodeDescriptorcOTreeSearchcLcLHitSetgR;
