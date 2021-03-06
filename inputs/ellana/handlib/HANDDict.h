/********************************************************************
* HANDDict.h
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************************/
#ifdef __CINT__
#error HANDDict.h/C is only for compilation. Abort cint.
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
extern void G__cpp_setup_tagtableHANDDict();
extern void G__cpp_setup_inheritanceHANDDict();
extern void G__cpp_setup_typetableHANDDict();
extern void G__cpp_setup_memvarHANDDict();
extern void G__cpp_setup_globalHANDDict();
extern void G__cpp_setup_memfuncHANDDict();
extern void G__cpp_setup_funcHANDDict();
extern void G__set_cpp_environmentHANDDict();
}


#include "TObject.h"
#include "TMemberInspector.h"
#include "THaNeutronDetector.h"
#include "THaNA.h"
#include "THaPlane.h"
#include "THaPlaneHit.h"
#include "THaPaddle.h"
#include "THaNAScintHit.h"
#include "THaScintillatorPlane.h"
#include "THaNDTrack.h"
#include "THaNDNeutron.h"
#include "THaVeto.h"
#include <algorithm>
namespace std { }
using namespace std;

#ifndef G__MEMFUNCBODY
#endif

extern G__linked_taginfo G__HANDDictLN_TClass;
extern G__linked_taginfo G__HANDDictLN_TBuffer;
extern G__linked_taginfo G__HANDDictLN_TMemberInspector;
extern G__linked_taginfo G__HANDDictLN_TObject;
extern G__linked_taginfo G__HANDDictLN_TNamed;
extern G__linked_taginfo G__HANDDictLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR;
extern G__linked_taginfo G__HANDDictLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__HANDDictLN_TClonesArray;
extern G__linked_taginfo G__HANDDictLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR;
extern G__linked_taginfo G__HANDDictLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__HANDDictLN_TDatime;
extern G__linked_taginfo G__HANDDictLN_THaEvData;
extern G__linked_taginfo G__HANDDictLN_THaAnalysisObject;
extern G__linked_taginfo G__HANDDictLN_THaAnalysisObjectcLcLEStatus;
extern G__linked_taginfo G__HANDDictLN_THaAnalysisObjectcLcLEMode;
extern G__linked_taginfo G__HANDDictLN_vectorlEstringcOallocatorlEstringgRsPgR;
extern G__linked_taginfo G__HANDDictLN_reverse_iteratorlEvectorlEstringcOallocatorlEstringgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTBaselEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTBaselEdoublegR;
extern G__linked_taginfo G__HANDDictLN_TVectorTlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TVectorTlEdoublegR;
extern G__linked_taginfo G__HANDDictLN_TElementActionTlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TElementPosActionTlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTRow_constlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTRowlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTDiag_constlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTColumn_constlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTFlat_constlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTSub_constlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTSparseRow_constlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTSparseDiag_constlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTColumnlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTDiaglEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTFlatlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTSublEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTSparseRowlEfloatgR;
extern G__linked_taginfo G__HANDDictLN_TMatrixTSparseDiaglEfloatgR;
extern G__linked_taginfo G__HANDDictLN_THaDetectorBase;
extern G__linked_taginfo G__HANDDictLN_vectorlEintcOallocatorlEintgRsPgR;
extern G__linked_taginfo G__HANDDictLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G__HANDDictLN_THaDetector;
extern G__linked_taginfo G__HANDDictLN_THaApparatus;
extern G__linked_taginfo G__HANDDictLN_THaSpectrometerDetector;
extern G__linked_taginfo G__HANDDictLN_THaNonTrackingDetector;
extern G__linked_taginfo G__HANDDictLN_THaPlane;
extern G__linked_taginfo G__HANDDictLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR;
extern G__linked_taginfo G__HANDDictLN_THaNAScintHit;
extern G__linked_taginfo G__HANDDictLN_PaddleMultiHits;
extern G__linked_taginfo G__HANDDictLN_THaScintillatorPlane;
extern G__linked_taginfo G__HANDDictLN_THaScintillatorPlanecLcLDataDest;
extern G__linked_taginfo G__HANDDictLN_THaNDTrack;
extern G__linked_taginfo G__HANDDictLN_THaNeutronDetector;
extern G__linked_taginfo G__HANDDictLN_THaNeutronDetectorcLcLdA;
extern G__linked_taginfo G__HANDDictLN_THaVeto;
extern G__linked_taginfo G__HANDDictLN_THaNDTrackcLcLdA;
extern G__linked_taginfo G__HANDDictLN_THaNDNeutron;
extern G__linked_taginfo G__HANDDictLN_THaNA;
extern G__linked_taginfo G__HANDDictLN_THaNAcLcLdA;
extern G__linked_taginfo G__HANDDictLN_THaPaddle;
extern G__linked_taginfo G__HANDDictLN_THaPlaneHit;

/* STUB derived class for protected member access */
