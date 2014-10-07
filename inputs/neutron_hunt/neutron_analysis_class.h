//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Oct  6 11:22:43 2014 by ROOT version 5.34/13
// from TChain T/
//////////////////////////////////////////////////////////

#ifndef neutron_analysis_class_h
#define neutron_analysis_class_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "./src/THaEvent.h"
#include "./src/THaEvent.h"

// Fixed size dimensions of array or collections stored in the TTree if any.

class neutron_analysis_class {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        R_sv_x;
   Double_t        R_sv_y;
   Double_t        IsReftHelicity;
   Double_t        IsRightHelicity;
   Double_t        InclusiveEvt;
   Double_t        GoodRTrack;
   Double_t        GoodElectron;
   Double_t        InclCut;
   Double_t        InvMass;
   Double_t        ScaAngle;
   Int_t           Ndata_D_edtmND;
   Double_t        D_edtmND[1];   //[Ndata.D.edtmND]
   Int_t           Ndata_D_edtmNDadc;
   Double_t        D_edtmNDadc[1];   //[Ndata.D.edtmNDadc]
   Int_t           Ndata_NA_n_pad;
   Double_t        NA_n_pad[42];   //[Ndata.NA.n.pad]
   Int_t           Ndata_NA_n_plane;
   Double_t        NA_n_plane[42];   //[Ndata.NA.n.plane]
   Int_t           Ndata_NA_n_tof;
   Double_t        NA_n_tof[42];   //[Ndata.NA.n.tof]
   Int_t           Ndata_NA_nd_p1_la;
   Double_t        NA_nd_p1_la[30];   //[Ndata.NA.nd.p1.la]
   Int_t           Ndata_NA_nd_p1_la_c;
   Double_t        NA_nd_p1_la_c[30];   //[Ndata.NA.nd.p1.la_c]
   Int_t           Ndata_NA_nd_p1_lt;
   Double_t        NA_nd_p1_lt[30];   //[Ndata.NA.nd.p1.lt]
   Int_t           Ndata_NA_nd_p1_lt_c;
   Double_t        NA_nd_p1_lt_c[30];   //[Ndata.NA.nd.p1.lt_c]
   Int_t           Ndata_NA_nd_p1_ra;
   Double_t        NA_nd_p1_ra[30];   //[Ndata.NA.nd.p1.ra]
   Int_t           Ndata_NA_nd_p1_ra_c;
   Double_t        NA_nd_p1_ra_c[30];   //[Ndata.NA.nd.p1.ra_c]
   Int_t           Ndata_NA_nd_p1_rt;
   Double_t        NA_nd_p1_rt[30];   //[Ndata.NA.nd.p1.rt]
   Int_t           Ndata_NA_nd_p1_rt_c;
   Double_t        NA_nd_p1_rt_c[30];   //[Ndata.NA.nd.p1.rt_c]
   Int_t           Ndata_NA_nd_p2_la;
   Double_t        NA_nd_p2_la[24];   //[Ndata.NA.nd.p2.la]
   Int_t           Ndata_NA_nd_p2_la_c;
   Double_t        NA_nd_p2_la_c[24];   //[Ndata.NA.nd.p2.la_c]
   Int_t           Ndata_NA_nd_p2_lt;
   Double_t        NA_nd_p2_lt[24];   //[Ndata.NA.nd.p2.lt]
   Int_t           Ndata_NA_nd_p2_lt_c;
   Double_t        NA_nd_p2_lt_c[24];   //[Ndata.NA.nd.p2.lt_c]
   Int_t           Ndata_NA_nd_p2_ra;
   Double_t        NA_nd_p2_ra[24];   //[Ndata.NA.nd.p2.ra]
   Int_t           Ndata_NA_nd_p2_ra_c;
   Double_t        NA_nd_p2_ra_c[24];   //[Ndata.NA.nd.p2.ra_c]
   Int_t           Ndata_NA_nd_p2_rt;
   Double_t        NA_nd_p2_rt[24];   //[Ndata.NA.nd.p2.rt]
   Int_t           Ndata_NA_nd_p2_rt_c;
   Double_t        NA_nd_p2_rt_c[24];   //[Ndata.NA.nd.p2.rt_c]
   Int_t           Ndata_NA_nd_p3_la;
   Double_t        NA_nd_p3_la[22];   //[Ndata.NA.nd.p3.la]
   Int_t           Ndata_NA_nd_p3_la_c;
   Double_t        NA_nd_p3_la_c[22];   //[Ndata.NA.nd.p3.la_c]
   Int_t           Ndata_NA_nd_p3_lt;
   Double_t        NA_nd_p3_lt[22];   //[Ndata.NA.nd.p3.lt]
   Int_t           Ndata_NA_nd_p3_lt_c;
   Double_t        NA_nd_p3_lt_c[22];   //[Ndata.NA.nd.p3.lt_c]
   Int_t           Ndata_NA_nd_p3_ra;
   Double_t        NA_nd_p3_ra[22];   //[Ndata.NA.nd.p3.ra]
   Int_t           Ndata_NA_nd_p3_ra_c;
   Double_t        NA_nd_p3_ra_c[22];   //[Ndata.NA.nd.p3.ra_c]
   Int_t           Ndata_NA_nd_p3_rt;
   Double_t        NA_nd_p3_rt[22];   //[Ndata.NA.nd.p3.rt]
   Int_t           Ndata_NA_nd_p3_rt_c;
   Double_t        NA_nd_p3_rt_c[22];   //[Ndata.NA.nd.p3.rt_c]
   Int_t           Ndata_NA_nd_p4_la;
   Double_t        NA_nd_p4_la[12];   //[Ndata.NA.nd.p4.la]
   Int_t           Ndata_NA_nd_p4_la_c;
   Double_t        NA_nd_p4_la_c[12];   //[Ndata.NA.nd.p4.la_c]
   Int_t           Ndata_NA_nd_p4_lt;
   Double_t        NA_nd_p4_lt[12];   //[Ndata.NA.nd.p4.lt]
   Int_t           Ndata_NA_nd_p4_lt_c;
   Double_t        NA_nd_p4_lt_c[12];   //[Ndata.NA.nd.p4.lt_c]
   Int_t           Ndata_NA_nd_p4_ra;
   Double_t        NA_nd_p4_ra[12];   //[Ndata.NA.nd.p4.ra]
   Int_t           Ndata_NA_nd_p4_ra_c;
   Double_t        NA_nd_p4_ra_c[12];   //[Ndata.NA.nd.p4.ra_c]
   Int_t           Ndata_NA_nd_p4_rt;
   Double_t        NA_nd_p4_rt[12];   //[Ndata.NA.nd.p4.rt]
   Int_t           Ndata_NA_nd_p4_rt_c;
   Double_t        NA_nd_p4_rt_c[12];   //[Ndata.NA.nd.p4.rt_c]
   Int_t           Ndata_NA_tr_firstpad;
   Double_t        NA_tr_firstpad[9];   //[Ndata.NA.tr.firstpad]
   Int_t           Ndata_NA_tr_firstplane;
   Double_t        NA_tr_firstplane[9];   //[Ndata.NA.tr.firstplane]
   Int_t           Ndata_NA_veto_ishit;
   Double_t        NA_veto_ishit[32];   //[Ndata.NA.veto.ishit]
   Int_t           Ndata_NA_veto_la;
   Double_t        NA_veto_la[32];   //[Ndata.NA.veto.la]
   Int_t           Ndata_NA_veto_la_c;
   Double_t        NA_veto_la_c[32];   //[Ndata.NA.veto.la_c]
   Int_t           Ndata_NA_veto_lt;
   Double_t        NA_veto_lt[32];   //[Ndata.NA.veto.lt]
   Int_t           Ndata_NA_veto_lt_c;
   Double_t        NA_veto_lt_c[32];   //[Ndata.NA.veto.lt_c]
   Int_t           Ndata_NA_veto_ra;
   Double_t        NA_veto_ra[32];   //[Ndata.NA.veto.ra]
   Int_t           Ndata_NA_veto_ra_c;
   Double_t        NA_veto_ra_c[32];   //[Ndata.NA.veto.ra_c]
   Int_t           Ndata_NA_veto_rt;
   Double_t        NA_veto_rt[32];   //[Ndata.NA.veto.rt]
   Int_t           Ndata_NA_veto_rt_c;
   Double_t        NA_veto_rt_c[32];   //[Ndata.NA.veto.rt_c]
   Int_t           Ndata_R_tr_beta;
   Double_t        R_tr_beta[1];   //[Ndata.R.tr.beta]
   Int_t           Ndata_R_tr_ph;
   Double_t        R_tr_ph[1];   //[Ndata.R.tr.ph]
   Int_t           Ndata_R_tr_th;
   Double_t        R_tr_th[1];   //[Ndata.R.tr.th]
   Int_t           Ndata_R_tr_x;
   Double_t        R_tr_x[1];   //[Ndata.R.tr.x]
   Int_t           Ndata_R_tr_y;
   Double_t        R_tr_y[1];   //[Ndata.R.tr.y]
   Double_t        D_evtypebits;
   Double_t        ExTgtCor_R_dp;
   Double_t        ExTgtCor_R_p;
   Double_t        ExTgtCor_R_ph;
   Double_t        ExTgtCor_R_th;
   Double_t        ExTgtCor_R_x;
   Double_t        ExTgtCor_R_y;
   Double_t        NA_veto_ishitl;
   Double_t        NA_veto_ishitr;
   Double_t        PriKineR_Q2;
   Double_t        PriKineR_W2;
   Double_t        PriKineR_angle;
   Double_t        PriKineR_nu;
   Double_t        PriKineR_x_bj;
   Double_t        PriKineRHe3_x_bj;
   Double_t        R_cer_asum_c;
   Double_t        R_gold_dp;
   Double_t        R_gold_p;
   Double_t        R_gold_ph;
   Double_t        R_gold_th;
   Double_t        R_gold_y;
   Double_t        R_ps_e;
   Double_t        R_sh_e;
   Double_t        R_tr_n;
   Double_t        R_vdc_u1_nclust;
   Double_t        R_vdc_u1_nhit;
   Double_t        R_vdc_u2_nclust;
   Double_t        R_vdc_u2_nhit;
   Double_t        R_vdc_v1_nclust;
   Double_t        R_vdc_v1_nhit;
   Double_t        R_vdc_v2_nclust;
   Double_t        R_vdc_v2_nhit;
   Double_t        ReactPt_R_z;
   Double_t        adchel_R_adc;
   Double_t        adchel_R_adc_hel;
   Double_t        adchel_R_gate_adc;
   Double_t        adchel_R_helicity;
   Double_t        g_evlen;
   Double_t        g_evnum;
   Double_t        g_evtime;
   Double_t        g_evtyp;
   Double_t        g_runnum;
   Double_t        g_runtime;
   Double_t        g_runtype;
   Double_t        g0hel_R_gate;
   Double_t        g0hel_R_helicity;
   Double_t        g0hel_R_nqrt;
   Double_t        g0hel_R_pread;
   Double_t        g0hel_R_qrt;
   Double_t        g0hel_R_quad;
   Double_t        g0hel_R_tdiff;
   Double_t        g0hel_R_timestamp;
   Double_t        g0hel_R_validHel;
   Double_t        g0hel_R_validtime;
   Double_t        he3R_IsSpinValid;
   Double_t        he3R_Spin;
   Double_t        he3R_radc1_DownADC;
   Double_t        he3R_radc1_IsSpinValid;
   Double_t        he3R_radc1_Spin;
   Double_t        he3R_radc1_UpADC;
   Double_t        IPM1H04B_XPOS;
   Double_t        IPM1H04B_YPOS;
   Double_t        hac_bcm_average;
   Double_t        hac_bcm_dvm1_read;
   Double_t        hac_bcm_dvm2_read;
   Double_t        hac_bcm_dvm1_current;
   Double_t        hac_bcm_dvm2_current;
   Double_t        hac_unser_current;
   Double_t        HacL_D1_NMR_SIG;
   Double_t        IBC0L02Current;
   Double_t        IFY1H04_rtd_target;
   Double_t        IFY1H04_rtd_P11042;
   Double_t        IFY1H04_rtd_P11047;
   Double_t        IFY1H04_rtd_P11044;
   Double_t        IFY1H04_rtd_P11048;
   Double_t        IFY1H04_rtd_P11055;
   Double_t        IFY1H04_rtd_P11051;
   Double_t        right_trigger_1;
   Double_t        right_trigger_2;
   Double_t        right_trigger_3;
   Double_t        right_trigger_4;
   Double_t        right_trigger_5;
   Double_t        right_trigger_6;
   Double_t        right_trigger_7;
   Double_t        right_trigger_8;
   Double_t        right_trigger_9;
   Double_t        right_trigger_10;
   Double_t        right_trigger_11;
   Double_t        right_trigger_12;
   Double_t        right_bcm_u1;
   Double_t        right_bcm_u3;
   Double_t        right_bcm_u10;
   Double_t        right_bcm_d1;
   Double_t        right_bcm_d3;
   Double_t        right_bcm_d10;
   Double_t        right_clock;
   Double_t        right_TS_accept;
   Double_t        right_edtpulser;
   Double_t        right_strobe;
   Double_t        right_dclock;
   Double_t        right_T1cnt;
   Double_t        right_T2cnt;
   Double_t        right_T3cnt;
   Double_t        right_T4cnt;
   Double_t        right_T5cnt;
   Double_t        right_T6cnt;
   Double_t        right_T7cnt;
   Double_t        right_Tacc_cnt;
   Double_t        right_P_T1cnt;
   Double_t        right_P_T2cnt;
   Double_t        right_P_T3cnt;
   Double_t        right_P_T4cnt;
   Double_t        right_P_T5cnt;
   Double_t        right_P_T6cnt;
   Double_t        right_P_T7cnt;
   Double_t        right_P_Tacc_cnt;
   Double_t        right_M_T1cnt;
   Double_t        right_M_T2cnt;
   Double_t        right_M_T3cnt;
   Double_t        right_M_T4cnt;
   Double_t        right_M_T5cnt;
   Double_t        right_M_T6cnt;
   Double_t        right_M_T7cnt;
   Double_t        right_M_Tacc_cnt;
   Double_t        right_clkcount;
   Double_t        right_P_clkcount;
   Double_t        right_M_clkcount;
   Double_t        right_bcmu1cnt;
   Double_t        right_bcmu3cnt;
   Double_t        right_bcmu10cnt;
   Double_t        right_bcmd1cnt;
   Double_t        right_bcmd3cnt;
   Double_t        right_bcmd10cnt;
   Double_t        right_P_bcmu1cnt;
   Double_t        right_P_bcmu3cnt;
   Double_t        right_P_bcmu10cnt;
   Double_t        right_P_bcmd1cnt;
   Double_t        right_P_bcmd3cnt;
   Double_t        right_P_bcmd10cnt;
   Double_t        right_M_bcmu1cnt;
   Double_t        right_M_bcmu3cnt;
   Double_t        right_M_bcmu10cnt;
   Double_t        right_M_bcmd1cnt;
   Double_t        right_M_bcmd3cnt;
   Double_t        right_M_bcmd10cnt;
   Double_t        right_T1;
   Double_t        right_T2;
   Double_t        right_T3;
   Double_t        right_T4;
   Double_t        right_T5;
   Double_t        right_T6;
   Double_t        right_T7;
   Double_t        right_Tacc;
   Double_t        right_P_T1;
   Double_t        right_P_T2;
   Double_t        right_P_T3;
   Double_t        right_P_T4;
   Double_t        right_P_T5;
   Double_t        right_P_T6;
   Double_t        right_P_T7;
   Double_t        right_P_Tacc;
   Double_t        right_M_T1;
   Double_t        right_M_T2;
   Double_t        right_M_T3;
   Double_t        right_M_T4;
   Double_t        right_M_T5;
   Double_t        right_M_T6;
   Double_t        right_M_T7;
   Double_t        right_M_Tacc;
   Double_t        right_clk;
   Double_t        right_P_clk;
   Double_t        right_M_clk;
   Double_t        right_bcmu1;
   Double_t        right_bcmu3;
   Double_t        right_bcmu10;
   Double_t        right_bcmd1;
   Double_t        right_bcmd3;
   Double_t        right_bcmd10;
   Double_t        right_P_bcmu1;
   Double_t        right_P_bcmu3;
   Double_t        right_P_bcmu10;
   Double_t        right_P_bcmd1;
   Double_t        right_P_bcmd3;
   Double_t        right_P_bcmd10;
   Double_t        right_M_bcmu1;
   Double_t        right_M_bcmu3;
   Double_t        right_M_bcmu10;
   Double_t        right_M_bcmd1;
   Double_t        right_M_bcmd3;
   Double_t        right_M_bcmd10;
   Double_t        evright_t1c;
   Double_t        evright_t2c;
   Double_t        evright_t3c;
   Double_t        evright_t4c;
   Double_t        evright_clkc;
   Double_t        evright_l1ac;
   Double_t        evright_u1cnt;
   Double_t        evright_u3cnt;
   Double_t        evright_u10cnt;
   Double_t        evright_d1cnt;
   Double_t        evright_d3cnt;
   Double_t        evright_d10cnt;
   Double_t        evright_fclkc;
   Double_t        evright_u1c;
   Double_t        evright_u3c;
   Double_t        evright_u10c;
   Double_t        evright_d1c;
   Double_t        evright_d3c;
   Double_t        evright_d10c;
   Double_t        evright_t1r;
   Double_t        evright_t2r;
   Double_t        evright_t3r;
   Double_t        evright_t4r;
   Double_t        evright_u1r;
   Double_t        evright_u3r;
   Double_t        evright_u10r;
   Double_t        evright_d1r;
   Double_t        evright_d3r;
   Double_t        evright_d10r;
   Double_t        evright_clkr;
   Double_t        evright_l1ar;
   Double_t        evright_fclkr;
   Double_t        evright_l1app;
   Double_t        evright_l1apm;
   Double_t        evright_l1amp;
   Double_t        evright_l1amm;
   Double_t        evright_clkpp;
   Double_t        evright_clkpm;
   Double_t        evright_clkmp;
   Double_t        evright_clkmm;
   Double_t        evright_fclkpp;
   Double_t        evright_fclkpm;
   Double_t        evright_fclkmp;
   Double_t        evright_fclkmm;
   Double_t        evright_u1pp;
   Double_t        evright_u1pm;
   Double_t        evright_u1mp;
   Double_t        evright_u1mm;
   Double_t        evright_u3pp;
   Double_t        evright_u3pm;
   Double_t        evright_u3mp;
   Double_t        evright_u3mm;
   Double_t        evright_u10pp;
   Double_t        evright_u10pm;
   Double_t        evright_u10mp;
   Double_t        evright_u10mm;
   Double_t        evright_d1pp;
   Double_t        evright_d1pm;
   Double_t        evright_d1mp;
   Double_t        evright_d1mm;
   Double_t        evright_d3pp;
   Double_t        evright_d3pm;
   Double_t        evright_d3mp;
   Double_t        evright_d3mm;
   Double_t        evright_d10pp;
   Double_t        evright_d10pm;
   Double_t        evright_d10mp;
   Double_t        evright_d10mm;
   Double_t        evright_t1pp;
   Double_t        evright_t1pm;
   Double_t        evright_t1mp;
   Double_t        evright_t1mm;
   Double_t        evright_t2pp;
   Double_t        evright_t2pm;
   Double_t        evright_t2mp;
   Double_t        evright_t2mm;
   Double_t        evright_t3pp;
   Double_t        evright_t3pm;
   Double_t        evright_t3mp;
   Double_t        evright_t3mm;
   Double_t        evright_t4pp;
   Double_t        evright_t4pm;
   Double_t        evright_t4mp;
   Double_t        evright_t4mm;
   Double_t        R_sv_x;
   Double_t        R_sv_y;
   Double_t        IsReftHelicity;
   Double_t        IsRightHelicity;
   Double_t        InclusiveEvt;
   Double_t        GoodRTrack;
   Double_t        GoodElectron;
   Double_t        InclCut;
   Double_t        InvMass;
   Double_t        ScaAngle;
 //THaEvent        *Event_Branch;
   ULong64_t       fEvtHdr_fEvtTime;
   UInt_t          fEvtHdr_fEvtNum;
   Int_t           fEvtHdr_fEvtType;
   Int_t           fEvtHdr_fEvtLen;
   Int_t           fEvtHdr_fHelicity;
   Int_t           fEvtHdr_fTargetPol;
   Int_t           fEvtHdr_fRun;

   // List of branches
   TBranch        *b_R_sv_x;   //!
   TBranch        *b_R_sv_y;   //!
   TBranch        *b_IsReftHelicity;   //!
   TBranch        *b_IsRightHelicity;   //!
   TBranch        *b_InclusiveEvt;   //!
   TBranch        *b_GoodRTrack;   //!
   TBranch        *b_GoodElectron;   //!
   TBranch        *b_InclCut;   //!
   TBranch        *b_InvMass;   //!
   TBranch        *b_ScaAngle;   //!
   TBranch        *b_Ndata_D_edtmND;   //!
   TBranch        *b_D_edtmND;   //!
   TBranch        *b_Ndata_D_edtmNDadc;   //!
   TBranch        *b_D_edtmNDadc;   //!
   TBranch        *b_Ndata_NA_n_pad;   //!
   TBranch        *b_NA_n_pad;   //!
   TBranch        *b_Ndata_NA_n_plane;   //!
   TBranch        *b_NA_n_plane;   //!
   TBranch        *b_Ndata_NA_n_tof;   //!
   TBranch        *b_NA_n_tof;   //!
   TBranch        *b_Ndata_NA_nd_p1_la;   //!
   TBranch        *b_NA_nd_p1_la;   //!
   TBranch        *b_Ndata_NA_nd_p1_la_c;   //!
   TBranch        *b_NA_nd_p1_la_c;   //!
   TBranch        *b_Ndata_NA_nd_p1_lt;   //!
   TBranch        *b_NA_nd_p1_lt;   //!
   TBranch        *b_Ndata_NA_nd_p1_lt_c;   //!
   TBranch        *b_NA_nd_p1_lt_c;   //!
   TBranch        *b_Ndata_NA_nd_p1_ra;   //!
   TBranch        *b_NA_nd_p1_ra;   //!
   TBranch        *b_Ndata_NA_nd_p1_ra_c;   //!
   TBranch        *b_NA_nd_p1_ra_c;   //!
   TBranch        *b_Ndata_NA_nd_p1_rt;   //!
   TBranch        *b_NA_nd_p1_rt;   //!
   TBranch        *b_Ndata_NA_nd_p1_rt_c;   //!
   TBranch        *b_NA_nd_p1_rt_c;   //!
   TBranch        *b_Ndata_NA_nd_p2_la;   //!
   TBranch        *b_NA_nd_p2_la;   //!
   TBranch        *b_Ndata_NA_nd_p2_la_c;   //!
   TBranch        *b_NA_nd_p2_la_c;   //!
   TBranch        *b_Ndata_NA_nd_p2_lt;   //!
   TBranch        *b_NA_nd_p2_lt;   //!
   TBranch        *b_Ndata_NA_nd_p2_lt_c;   //!
   TBranch        *b_NA_nd_p2_lt_c;   //!
   TBranch        *b_Ndata_NA_nd_p2_ra;   //!
   TBranch        *b_NA_nd_p2_ra;   //!
   TBranch        *b_Ndata_NA_nd_p2_ra_c;   //!
   TBranch        *b_NA_nd_p2_ra_c;   //!
   TBranch        *b_Ndata_NA_nd_p2_rt;   //!
   TBranch        *b_NA_nd_p2_rt;   //!
   TBranch        *b_Ndata_NA_nd_p2_rt_c;   //!
   TBranch        *b_NA_nd_p2_rt_c;   //!
   TBranch        *b_Ndata_NA_nd_p3_la;   //!
   TBranch        *b_NA_nd_p3_la;   //!
   TBranch        *b_Ndata_NA_nd_p3_la_c;   //!
   TBranch        *b_NA_nd_p3_la_c;   //!
   TBranch        *b_Ndata_NA_nd_p3_lt;   //!
   TBranch        *b_NA_nd_p3_lt;   //!
   TBranch        *b_Ndata_NA_nd_p3_lt_c;   //!
   TBranch        *b_NA_nd_p3_lt_c;   //!
   TBranch        *b_Ndata_NA_nd_p3_ra;   //!
   TBranch        *b_NA_nd_p3_ra;   //!
   TBranch        *b_Ndata_NA_nd_p3_ra_c;   //!
   TBranch        *b_NA_nd_p3_ra_c;   //!
   TBranch        *b_Ndata_NA_nd_p3_rt;   //!
   TBranch        *b_NA_nd_p3_rt;   //!
   TBranch        *b_Ndata_NA_nd_p3_rt_c;   //!
   TBranch        *b_NA_nd_p3_rt_c;   //!
   TBranch        *b_Ndata_NA_nd_p4_la;   //!
   TBranch        *b_NA_nd_p4_la;   //!
   TBranch        *b_Ndata_NA_nd_p4_la_c;   //!
   TBranch        *b_NA_nd_p4_la_c;   //!
   TBranch        *b_Ndata_NA_nd_p4_lt;   //!
   TBranch        *b_NA_nd_p4_lt;   //!
   TBranch        *b_Ndata_NA_nd_p4_lt_c;   //!
   TBranch        *b_NA_nd_p4_lt_c;   //!
   TBranch        *b_Ndata_NA_nd_p4_ra;   //!
   TBranch        *b_NA_nd_p4_ra;   //!
   TBranch        *b_Ndata_NA_nd_p4_ra_c;   //!
   TBranch        *b_NA_nd_p4_ra_c;   //!
   TBranch        *b_Ndata_NA_nd_p4_rt;   //!
   TBranch        *b_NA_nd_p4_rt;   //!
   TBranch        *b_Ndata_NA_nd_p4_rt_c;   //!
   TBranch        *b_NA_nd_p4_rt_c;   //!
   TBranch        *b_Ndata_NA_tr_firstpad;   //!
   TBranch        *b_NA_tr_firstpad;   //!
   TBranch        *b_Ndata_NA_tr_firstplane;   //!
   TBranch        *b_NA_tr_firstplane;   //!
   TBranch        *b_Ndata_NA_veto_ishit;   //!
   TBranch        *b_NA_veto_ishit;   //!
   TBranch        *b_Ndata_NA_veto_la;   //!
   TBranch        *b_NA_veto_la;   //!
   TBranch        *b_Ndata_NA_veto_la_c;   //!
   TBranch        *b_NA_veto_la_c;   //!
   TBranch        *b_Ndata_NA_veto_lt;   //!
   TBranch        *b_NA_veto_lt;   //!
   TBranch        *b_Ndata_NA_veto_lt_c;   //!
   TBranch        *b_NA_veto_lt_c;   //!
   TBranch        *b_Ndata_NA_veto_ra;   //!
   TBranch        *b_NA_veto_ra;   //!
   TBranch        *b_Ndata_NA_veto_ra_c;   //!
   TBranch        *b_NA_veto_ra_c;   //!
   TBranch        *b_Ndata_NA_veto_rt;   //!
   TBranch        *b_NA_veto_rt;   //!
   TBranch        *b_Ndata_NA_veto_rt_c;   //!
   TBranch        *b_NA_veto_rt_c;   //!
   TBranch        *b_Ndata_R_tr_beta;   //!
   TBranch        *b_R_tr_beta;   //!
   TBranch        *b_Ndata_R_tr_ph;   //!
   TBranch        *b_R_tr_ph;   //!
   TBranch        *b_Ndata_R_tr_th;   //!
   TBranch        *b_R_tr_th;   //!
   TBranch        *b_Ndata_R_tr_x;   //!
   TBranch        *b_R_tr_x;   //!
   TBranch        *b_Ndata_R_tr_y;   //!
   TBranch        *b_R_tr_y;   //!
   TBranch        *b_D_evtypebits;   //!
   TBranch        *b_ExTgtCor_R_dp;   //!
   TBranch        *b_ExTgtCor_R_p;   //!
   TBranch        *b_ExTgtCor_R_ph;   //!
   TBranch        *b_ExTgtCor_R_th;   //!
   TBranch        *b_ExTgtCor_R_x;   //!
   TBranch        *b_ExTgtCor_R_y;   //!
   TBranch        *b_NA_veto_ishitl;   //!
   TBranch        *b_NA_veto_ishitr;   //!
   TBranch        *b_PriKineR_Q2;   //!
   TBranch        *b_PriKineR_W2;   //!
   TBranch        *b_PriKineR_angle;   //!
   TBranch        *b_PriKineR_nu;   //!
   TBranch        *b_PriKineR_x_bj;   //!
   TBranch        *b_PriKineRHe3_x_bj;   //!
   TBranch        *b_R_cer_asum_c;   //!
   TBranch        *b_R_gold_dp;   //!
   TBranch        *b_R_gold_p;   //!
   TBranch        *b_R_gold_ph;   //!
   TBranch        *b_R_gold_th;   //!
   TBranch        *b_R_gold_y;   //!
   TBranch        *b_R_ps_e;   //!
   TBranch        *b_R_sh_e;   //!
   TBranch        *b_R_tr_n;   //!
   TBranch        *b_R_vdc_u1_nclust;   //!
   TBranch        *b_R_vdc_u1_nhit;   //!
   TBranch        *b_R_vdc_u2_nclust;   //!
   TBranch        *b_R_vdc_u2_nhit;   //!
   TBranch        *b_R_vdc_v1_nclust;   //!
   TBranch        *b_R_vdc_v1_nhit;   //!
   TBranch        *b_R_vdc_v2_nclust;   //!
   TBranch        *b_R_vdc_v2_nhit;   //!
   TBranch        *b_ReactPt_R_z;   //!
   TBranch        *b_adchel_R_adc;   //!
   TBranch        *b_adchel_R_adc_hel;   //!
   TBranch        *b_adchel_R_gate_adc;   //!
   TBranch        *b_adchel_R_helicity;   //!
   TBranch        *b_g_evlen;   //!
   TBranch        *b_g_evnum;   //!
   TBranch        *b_g_evtime;   //!
   TBranch        *b_g_evtyp;   //!
   TBranch        *b_g_runnum;   //!
   TBranch        *b_g_runtime;   //!
   TBranch        *b_g_runtype;   //!
   TBranch        *b_g0hel_R_gate;   //!
   TBranch        *b_g0hel_R_helicity;   //!
   TBranch        *b_g0hel_R_nqrt;   //!
   TBranch        *b_g0hel_R_pread;   //!
   TBranch        *b_g0hel_R_qrt;   //!
   TBranch        *b_g0hel_R_quad;   //!
   TBranch        *b_g0hel_R_tdiff;   //!
   TBranch        *b_g0hel_R_timestamp;   //!
   TBranch        *b_g0hel_R_validHel;   //!
   TBranch        *b_g0hel_R_validtime;   //!
   TBranch        *b_he3R_IsSpinValid;   //!
   TBranch        *b_he3R_Spin;   //!
   TBranch        *b_he3R_radc1_DownADC;   //!
   TBranch        *b_he3R_radc1_IsSpinValid;   //!
   TBranch        *b_he3R_radc1_Spin;   //!
   TBranch        *b_he3R_radc1_UpADC;   //!
   TBranch        *b_IPM1H04B_XPOS;   //!
   TBranch        *b_IPM1H04B_YPOS;   //!
   TBranch        *b_hac_bcm_average;   //!
   TBranch        *b_hac_bcm_dvm1_read;   //!
   TBranch        *b_hac_bcm_dvm2_read;   //!
   TBranch        *b_hac_bcm_dvm1_current;   //!
   TBranch        *b_hac_bcm_dvm2_current;   //!
   TBranch        *b_hac_unser_current;   //!
   TBranch        *b_HacL_D1_NMR_SIG;   //!
   TBranch        *b_IBC0L02Current;   //!
   TBranch        *b_IFY1H04_rtd_target;   //!
   TBranch        *b_IFY1H04_rtd_P11042;   //!
   TBranch        *b_IFY1H04_rtd_P11047;   //!
   TBranch        *b_IFY1H04_rtd_P11044;   //!
   TBranch        *b_IFY1H04_rtd_P11048;   //!
   TBranch        *b_IFY1H04_rtd_P11055;   //!
   TBranch        *b_IFY1H04_rtd_P11051;   //!
   TBranch        *b_right_trigger_1;   //!
   TBranch        *b_right_trigger_2;   //!
   TBranch        *b_right_trigger_3;   //!
   TBranch        *b_right_trigger_4;   //!
   TBranch        *b_right_trigger_5;   //!
   TBranch        *b_right_trigger_6;   //!
   TBranch        *b_right_trigger_7;   //!
   TBranch        *b_right_trigger_8;   //!
   TBranch        *b_right_trigger_9;   //!
   TBranch        *b_right_trigger_10;   //!
   TBranch        *b_right_trigger_11;   //!
   TBranch        *b_right_trigger_12;   //!
   TBranch        *b_right_bcm_u1;   //!
   TBranch        *b_right_bcm_u3;   //!
   TBranch        *b_right_bcm_u10;   //!
   TBranch        *b_right_bcm_d1;   //!
   TBranch        *b_right_bcm_d3;   //!
   TBranch        *b_right_bcm_d10;   //!
   TBranch        *b_right_clock;   //!
   TBranch        *b_right_TS_accept;   //!
   TBranch        *b_right_edtpulser;   //!
   TBranch        *b_right_strobe;   //!
   TBranch        *b_right_dclock;   //!
   TBranch        *b_right_T1cnt;   //!
   TBranch        *b_right_T2cnt;   //!
   TBranch        *b_right_T3cnt;   //!
   TBranch        *b_right_T4cnt;   //!
   TBranch        *b_right_T5cnt;   //!
   TBranch        *b_right_T6cnt;   //!
   TBranch        *b_right_T7cnt;   //!
   TBranch        *b_right_Tacc_cnt;   //!
   TBranch        *b_right_P_T1cnt;   //!
   TBranch        *b_right_P_T2cnt;   //!
   TBranch        *b_right_P_T3cnt;   //!
   TBranch        *b_right_P_T4cnt;   //!
   TBranch        *b_right_P_T5cnt;   //!
   TBranch        *b_right_P_T6cnt;   //!
   TBranch        *b_right_P_T7cnt;   //!
   TBranch        *b_right_P_Tacc_cnt;   //!
   TBranch        *b_right_M_T1cnt;   //!
   TBranch        *b_right_M_T2cnt;   //!
   TBranch        *b_right_M_T3cnt;   //!
   TBranch        *b_right_M_T4cnt;   //!
   TBranch        *b_right_M_T5cnt;   //!
   TBranch        *b_right_M_T6cnt;   //!
   TBranch        *b_right_M_T7cnt;   //!
   TBranch        *b_right_M_Tacc_cnt;   //!
   TBranch        *b_right_clkcount;   //!
   TBranch        *b_right_P_clkcount;   //!
   TBranch        *b_right_M_clkcount;   //!
   TBranch        *b_right_bcmu1cnt;   //!
   TBranch        *b_right_bcmu3cnt;   //!
   TBranch        *b_right_bcmu10cnt;   //!
   TBranch        *b_right_bcmd1cnt;   //!
   TBranch        *b_right_bcmd3cnt;   //!
   TBranch        *b_right_bcmd10cnt;   //!
   TBranch        *b_right_P_bcmu1cnt;   //!
   TBranch        *b_right_P_bcmu3cnt;   //!
   TBranch        *b_right_P_bcmu10cnt;   //!
   TBranch        *b_right_P_bcmd1cnt;   //!
   TBranch        *b_right_P_bcmd3cnt;   //!
   TBranch        *b_right_P_bcmd10cnt;   //!
   TBranch        *b_right_M_bcmu1cnt;   //!
   TBranch        *b_right_M_bcmu3cnt;   //!
   TBranch        *b_right_M_bcmu10cnt;   //!
   TBranch        *b_right_M_bcmd1cnt;   //!
   TBranch        *b_right_M_bcmd3cnt;   //!
   TBranch        *b_right_M_bcmd10cnt;   //!
   TBranch        *b_right_T1;   //!
   TBranch        *b_right_T2;   //!
   TBranch        *b_right_T3;   //!
   TBranch        *b_right_T4;   //!
   TBranch        *b_right_T5;   //!
   TBranch        *b_right_T6;   //!
   TBranch        *b_right_T7;   //!
   TBranch        *b_right_Tacc;   //!
   TBranch        *b_right_P_T1;   //!
   TBranch        *b_right_P_T2;   //!
   TBranch        *b_right_P_T3;   //!
   TBranch        *b_right_P_T4;   //!
   TBranch        *b_right_P_T5;   //!
   TBranch        *b_right_P_T6;   //!
   TBranch        *b_right_P_T7;   //!
   TBranch        *b_right_P_Tacc;   //!
   TBranch        *b_right_M_T1;   //!
   TBranch        *b_right_M_T2;   //!
   TBranch        *b_right_M_T3;   //!
   TBranch        *b_right_M_T4;   //!
   TBranch        *b_right_M_T5;   //!
   TBranch        *b_right_M_T6;   //!
   TBranch        *b_right_M_T7;   //!
   TBranch        *b_right_M_Tacc;   //!
   TBranch        *b_right_clk;   //!
   TBranch        *b_right_P_clk;   //!
   TBranch        *b_right_M_clk;   //!
   TBranch        *b_right_bcmu1;   //!
   TBranch        *b_right_bcmu3;   //!
   TBranch        *b_right_bcmu10;   //!
   TBranch        *b_right_bcmd1;   //!
   TBranch        *b_right_bcmd3;   //!
   TBranch        *b_right_bcmd10;   //!
   TBranch        *b_right_P_bcmu1;   //!
   TBranch        *b_right_P_bcmu3;   //!
   TBranch        *b_right_P_bcmu10;   //!
   TBranch        *b_right_P_bcmd1;   //!
   TBranch        *b_right_P_bcmd3;   //!
   TBranch        *b_right_P_bcmd10;   //!
   TBranch        *b_right_M_bcmu1;   //!
   TBranch        *b_right_M_bcmu3;   //!
   TBranch        *b_right_M_bcmu10;   //!
   TBranch        *b_right_M_bcmd1;   //!
   TBranch        *b_right_M_bcmd3;   //!
   TBranch        *b_right_M_bcmd10;   //!
   TBranch        *b_evright_t1c;   //!
   TBranch        *b_evright_t2c;   //!
   TBranch        *b_evright_t3c;   //!
   TBranch        *b_evright_t4c;   //!
   TBranch        *b_evright_clkc;   //!
   TBranch        *b_evright_l1ac;   //!
   TBranch        *b_evright_u1cnt;   //!
   TBranch        *b_evright_u3cnt;   //!
   TBranch        *b_evright_u10cnt;   //!
   TBranch        *b_evright_d1cnt;   //!
   TBranch        *b_evright_d3cnt;   //!
   TBranch        *b_evright_d10cnt;   //!
   TBranch        *b_evright_fclkc;   //!
   TBranch        *b_evright_u1c;   //!
   TBranch        *b_evright_u3c;   //!
   TBranch        *b_evright_u10c;   //!
   TBranch        *b_evright_d1c;   //!
   TBranch        *b_evright_d3c;   //!
   TBranch        *b_evright_d10c;   //!
   TBranch        *b_evright_t1r;   //!
   TBranch        *b_evright_t2r;   //!
   TBranch        *b_evright_t3r;   //!
   TBranch        *b_evright_t4r;   //!
   TBranch        *b_evright_u1r;   //!
   TBranch        *b_evright_u3r;   //!
   TBranch        *b_evright_u10r;   //!
   TBranch        *b_evright_d1r;   //!
   TBranch        *b_evright_d3r;   //!
   TBranch        *b_evright_d10r;   //!
   TBranch        *b_evright_clkr;   //!
   TBranch        *b_evright_l1ar;   //!
   TBranch        *b_evright_fclkr;   //!
   TBranch        *b_evright_l1app;   //!
   TBranch        *b_evright_l1apm;   //!
   TBranch        *b_evright_l1amp;   //!
   TBranch        *b_evright_l1amm;   //!
   TBranch        *b_evright_clkpp;   //!
   TBranch        *b_evright_clkpm;   //!
   TBranch        *b_evright_clkmp;   //!
   TBranch        *b_evright_clkmm;   //!
   TBranch        *b_evright_fclkpp;   //!
   TBranch        *b_evright_fclkpm;   //!
   TBranch        *b_evright_fclkmp;   //!
   TBranch        *b_evright_fclkmm;   //!
   TBranch        *b_evright_u1pp;   //!
   TBranch        *b_evright_u1pm;   //!
   TBranch        *b_evright_u1mp;   //!
   TBranch        *b_evright_u1mm;   //!
   TBranch        *b_evright_u3pp;   //!
   TBranch        *b_evright_u3pm;   //!
   TBranch        *b_evright_u3mp;   //!
   TBranch        *b_evright_u3mm;   //!
   TBranch        *b_evright_u10pp;   //!
   TBranch        *b_evright_u10pm;   //!
   TBranch        *b_evright_u10mp;   //!
   TBranch        *b_evright_u10mm;   //!
   TBranch        *b_evright_d1pp;   //!
   TBranch        *b_evright_d1pm;   //!
   TBranch        *b_evright_d1mp;   //!
   TBranch        *b_evright_d1mm;   //!
   TBranch        *b_evright_d3pp;   //!
   TBranch        *b_evright_d3pm;   //!
   TBranch        *b_evright_d3mp;   //!
   TBranch        *b_evright_d3mm;   //!
   TBranch        *b_evright_d10pp;   //!
   TBranch        *b_evright_d10pm;   //!
   TBranch        *b_evright_d10mp;   //!
   TBranch        *b_evright_d10mm;   //!
   TBranch        *b_evright_t1pp;   //!
   TBranch        *b_evright_t1pm;   //!
   TBranch        *b_evright_t1mp;   //!
   TBranch        *b_evright_t1mm;   //!
   TBranch        *b_evright_t2pp;   //!
   TBranch        *b_evright_t2pm;   //!
   TBranch        *b_evright_t2mp;   //!
   TBranch        *b_evright_t2mm;   //!
   TBranch        *b_evright_t3pp;   //!
   TBranch        *b_evright_t3pm;   //!
   TBranch        *b_evright_t3mp;   //!
   TBranch        *b_evright_t3mm;   //!
   TBranch        *b_evright_t4pp;   //!
   TBranch        *b_evright_t4pm;   //!
   TBranch        *b_evright_t4mp;   //!
   TBranch        *b_evright_t4mm;   //!
   TBranch        *b_R_sv_x;   //!
   TBranch        *b_R_sv_y;   //!
   TBranch        *b_IsReftHelicity;   //!
   TBranch        *b_IsRightHelicity;   //!
   TBranch        *b_InclusiveEvt;   //!
   TBranch        *b_GoodRTrack;   //!
   TBranch        *b_GoodElectron;   //!
   TBranch        *b_InclCut;   //!
   TBranch        *b_InvMass;   //!
   TBranch        *b_ScaAngle;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtTime;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtNum;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtType;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fEvtLen;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fHelicity;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fTargetPol;   //!
   TBranch        *b_Event_Branch_fEvtHdr_fRun;   //!

   neutron_analysis_class(TTree *tree=0);
   virtual ~neutron_analysis_class();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef neutron_analysis_class_cxx
neutron_analysis_class::neutron_analysis_class(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f || !f->IsOpen()) {
         f = new TFile("Memory Directory");
      }
      f->GetObject("T",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("T","");
      chain->Add("./e05102_R_20494.root/T");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

neutron_analysis_class::~neutron_analysis_class()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t neutron_analysis_class::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t neutron_analysis_class::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void neutron_analysis_class::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("R_sv_x", &R_sv_x, &b_R_sv_x);
   fChain->SetBranchAddress("R_sv_y", &R_sv_y, &b_R_sv_y);
   fChain->SetBranchAddress("IsReftHelicity", &IsReftHelicity, &b_IsReftHelicity);
   fChain->SetBranchAddress("IsRightHelicity", &IsRightHelicity, &b_IsRightHelicity);
   fChain->SetBranchAddress("InclusiveEvt", &InclusiveEvt, &b_InclusiveEvt);
   fChain->SetBranchAddress("GoodRTrack", &GoodRTrack, &b_GoodRTrack);
   fChain->SetBranchAddress("GoodElectron", &GoodElectron, &b_GoodElectron);
   fChain->SetBranchAddress("InclCut", &InclCut, &b_InclCut);
   fChain->SetBranchAddress("InvMass", &InvMass, &b_InvMass);
   fChain->SetBranchAddress("ScaAngle", &ScaAngle, &b_ScaAngle);
   fChain->SetBranchAddress("Ndata.D.edtmND", &Ndata_D_edtmND, &b_Ndata_D_edtmND);
   fChain->SetBranchAddress("D.edtmND", D_edtmND, &b_D_edtmND);
   fChain->SetBranchAddress("Ndata.D.edtmNDadc", &Ndata_D_edtmNDadc, &b_Ndata_D_edtmNDadc);
   fChain->SetBranchAddress("D.edtmNDadc", D_edtmNDadc, &b_D_edtmNDadc);
   fChain->SetBranchAddress("Ndata.NA.n.pad", &Ndata_NA_n_pad, &b_Ndata_NA_n_pad);
   fChain->SetBranchAddress("NA.n.pad", NA_n_pad, &b_NA_n_pad);
   fChain->SetBranchAddress("Ndata.NA.n.plane", &Ndata_NA_n_plane, &b_Ndata_NA_n_plane);
   fChain->SetBranchAddress("NA.n.plane", NA_n_plane, &b_NA_n_plane);
   fChain->SetBranchAddress("Ndata.NA.n.tof", &Ndata_NA_n_tof, &b_Ndata_NA_n_tof);
   fChain->SetBranchAddress("NA.n.tof", NA_n_tof, &b_NA_n_tof);
   fChain->SetBranchAddress("Ndata.NA.nd.p1.la", &Ndata_NA_nd_p1_la, &b_Ndata_NA_nd_p1_la);
   fChain->SetBranchAddress("NA.nd.p1.la", NA_nd_p1_la, &b_NA_nd_p1_la);
   fChain->SetBranchAddress("Ndata.NA.nd.p1.la_c", &Ndata_NA_nd_p1_la_c, &b_Ndata_NA_nd_p1_la_c);
   fChain->SetBranchAddress("NA.nd.p1.la_c", NA_nd_p1_la_c, &b_NA_nd_p1_la_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p1.lt", &Ndata_NA_nd_p1_lt, &b_Ndata_NA_nd_p1_lt);
   fChain->SetBranchAddress("NA.nd.p1.lt", NA_nd_p1_lt, &b_NA_nd_p1_lt);
   fChain->SetBranchAddress("Ndata.NA.nd.p1.lt_c", &Ndata_NA_nd_p1_lt_c, &b_Ndata_NA_nd_p1_lt_c);
   fChain->SetBranchAddress("NA.nd.p1.lt_c", NA_nd_p1_lt_c, &b_NA_nd_p1_lt_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p1.ra", &Ndata_NA_nd_p1_ra, &b_Ndata_NA_nd_p1_ra);
   fChain->SetBranchAddress("NA.nd.p1.ra", NA_nd_p1_ra, &b_NA_nd_p1_ra);
   fChain->SetBranchAddress("Ndata.NA.nd.p1.ra_c", &Ndata_NA_nd_p1_ra_c, &b_Ndata_NA_nd_p1_ra_c);
   fChain->SetBranchAddress("NA.nd.p1.ra_c", NA_nd_p1_ra_c, &b_NA_nd_p1_ra_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p1.rt", &Ndata_NA_nd_p1_rt, &b_Ndata_NA_nd_p1_rt);
   fChain->SetBranchAddress("NA.nd.p1.rt", NA_nd_p1_rt, &b_NA_nd_p1_rt);
   fChain->SetBranchAddress("Ndata.NA.nd.p1.rt_c", &Ndata_NA_nd_p1_rt_c, &b_Ndata_NA_nd_p1_rt_c);
   fChain->SetBranchAddress("NA.nd.p1.rt_c", NA_nd_p1_rt_c, &b_NA_nd_p1_rt_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p2.la", &Ndata_NA_nd_p2_la, &b_Ndata_NA_nd_p2_la);
   fChain->SetBranchAddress("NA.nd.p2.la", NA_nd_p2_la, &b_NA_nd_p2_la);
   fChain->SetBranchAddress("Ndata.NA.nd.p2.la_c", &Ndata_NA_nd_p2_la_c, &b_Ndata_NA_nd_p2_la_c);
   fChain->SetBranchAddress("NA.nd.p2.la_c", NA_nd_p2_la_c, &b_NA_nd_p2_la_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p2.lt", &Ndata_NA_nd_p2_lt, &b_Ndata_NA_nd_p2_lt);
   fChain->SetBranchAddress("NA.nd.p2.lt", NA_nd_p2_lt, &b_NA_nd_p2_lt);
   fChain->SetBranchAddress("Ndata.NA.nd.p2.lt_c", &Ndata_NA_nd_p2_lt_c, &b_Ndata_NA_nd_p2_lt_c);
   fChain->SetBranchAddress("NA.nd.p2.lt_c", NA_nd_p2_lt_c, &b_NA_nd_p2_lt_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p2.ra", &Ndata_NA_nd_p2_ra, &b_Ndata_NA_nd_p2_ra);
   fChain->SetBranchAddress("NA.nd.p2.ra", NA_nd_p2_ra, &b_NA_nd_p2_ra);
   fChain->SetBranchAddress("Ndata.NA.nd.p2.ra_c", &Ndata_NA_nd_p2_ra_c, &b_Ndata_NA_nd_p2_ra_c);
   fChain->SetBranchAddress("NA.nd.p2.ra_c", NA_nd_p2_ra_c, &b_NA_nd_p2_ra_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p2.rt", &Ndata_NA_nd_p2_rt, &b_Ndata_NA_nd_p2_rt);
   fChain->SetBranchAddress("NA.nd.p2.rt", NA_nd_p2_rt, &b_NA_nd_p2_rt);
   fChain->SetBranchAddress("Ndata.NA.nd.p2.rt_c", &Ndata_NA_nd_p2_rt_c, &b_Ndata_NA_nd_p2_rt_c);
   fChain->SetBranchAddress("NA.nd.p2.rt_c", NA_nd_p2_rt_c, &b_NA_nd_p2_rt_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p3.la", &Ndata_NA_nd_p3_la, &b_Ndata_NA_nd_p3_la);
   fChain->SetBranchAddress("NA.nd.p3.la", NA_nd_p3_la, &b_NA_nd_p3_la);
   fChain->SetBranchAddress("Ndata.NA.nd.p3.la_c", &Ndata_NA_nd_p3_la_c, &b_Ndata_NA_nd_p3_la_c);
   fChain->SetBranchAddress("NA.nd.p3.la_c", NA_nd_p3_la_c, &b_NA_nd_p3_la_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p3.lt", &Ndata_NA_nd_p3_lt, &b_Ndata_NA_nd_p3_lt);
   fChain->SetBranchAddress("NA.nd.p3.lt", NA_nd_p3_lt, &b_NA_nd_p3_lt);
   fChain->SetBranchAddress("Ndata.NA.nd.p3.lt_c", &Ndata_NA_nd_p3_lt_c, &b_Ndata_NA_nd_p3_lt_c);
   fChain->SetBranchAddress("NA.nd.p3.lt_c", NA_nd_p3_lt_c, &b_NA_nd_p3_lt_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p3.ra", &Ndata_NA_nd_p3_ra, &b_Ndata_NA_nd_p3_ra);
   fChain->SetBranchAddress("NA.nd.p3.ra", NA_nd_p3_ra, &b_NA_nd_p3_ra);
   fChain->SetBranchAddress("Ndata.NA.nd.p3.ra_c", &Ndata_NA_nd_p3_ra_c, &b_Ndata_NA_nd_p3_ra_c);
   fChain->SetBranchAddress("NA.nd.p3.ra_c", NA_nd_p3_ra_c, &b_NA_nd_p3_ra_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p3.rt", &Ndata_NA_nd_p3_rt, &b_Ndata_NA_nd_p3_rt);
   fChain->SetBranchAddress("NA.nd.p3.rt", NA_nd_p3_rt, &b_NA_nd_p3_rt);
   fChain->SetBranchAddress("Ndata.NA.nd.p3.rt_c", &Ndata_NA_nd_p3_rt_c, &b_Ndata_NA_nd_p3_rt_c);
   fChain->SetBranchAddress("NA.nd.p3.rt_c", NA_nd_p3_rt_c, &b_NA_nd_p3_rt_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p4.la", &Ndata_NA_nd_p4_la, &b_Ndata_NA_nd_p4_la);
   fChain->SetBranchAddress("NA.nd.p4.la", NA_nd_p4_la, &b_NA_nd_p4_la);
   fChain->SetBranchAddress("Ndata.NA.nd.p4.la_c", &Ndata_NA_nd_p4_la_c, &b_Ndata_NA_nd_p4_la_c);
   fChain->SetBranchAddress("NA.nd.p4.la_c", NA_nd_p4_la_c, &b_NA_nd_p4_la_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p4.lt", &Ndata_NA_nd_p4_lt, &b_Ndata_NA_nd_p4_lt);
   fChain->SetBranchAddress("NA.nd.p4.lt", NA_nd_p4_lt, &b_NA_nd_p4_lt);
   fChain->SetBranchAddress("Ndata.NA.nd.p4.lt_c", &Ndata_NA_nd_p4_lt_c, &b_Ndata_NA_nd_p4_lt_c);
   fChain->SetBranchAddress("NA.nd.p4.lt_c", NA_nd_p4_lt_c, &b_NA_nd_p4_lt_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p4.ra", &Ndata_NA_nd_p4_ra, &b_Ndata_NA_nd_p4_ra);
   fChain->SetBranchAddress("NA.nd.p4.ra", NA_nd_p4_ra, &b_NA_nd_p4_ra);
   fChain->SetBranchAddress("Ndata.NA.nd.p4.ra_c", &Ndata_NA_nd_p4_ra_c, &b_Ndata_NA_nd_p4_ra_c);
   fChain->SetBranchAddress("NA.nd.p4.ra_c", NA_nd_p4_ra_c, &b_NA_nd_p4_ra_c);
   fChain->SetBranchAddress("Ndata.NA.nd.p4.rt", &Ndata_NA_nd_p4_rt, &b_Ndata_NA_nd_p4_rt);
   fChain->SetBranchAddress("NA.nd.p4.rt", NA_nd_p4_rt, &b_NA_nd_p4_rt);
   fChain->SetBranchAddress("Ndata.NA.nd.p4.rt_c", &Ndata_NA_nd_p4_rt_c, &b_Ndata_NA_nd_p4_rt_c);
   fChain->SetBranchAddress("NA.nd.p4.rt_c", NA_nd_p4_rt_c, &b_NA_nd_p4_rt_c);
   fChain->SetBranchAddress("Ndata.NA.tr.firstpad", &Ndata_NA_tr_firstpad, &b_Ndata_NA_tr_firstpad);
   fChain->SetBranchAddress("NA.tr.firstpad", NA_tr_firstpad, &b_NA_tr_firstpad);
   fChain->SetBranchAddress("Ndata.NA.tr.firstplane", &Ndata_NA_tr_firstplane, &b_Ndata_NA_tr_firstplane);
   fChain->SetBranchAddress("NA.tr.firstplane", NA_tr_firstplane, &b_NA_tr_firstplane);
   fChain->SetBranchAddress("Ndata.NA.veto.ishit", &Ndata_NA_veto_ishit, &b_Ndata_NA_veto_ishit);
   fChain->SetBranchAddress("NA.veto.ishit", NA_veto_ishit, &b_NA_veto_ishit);
   fChain->SetBranchAddress("Ndata.NA.veto.la", &Ndata_NA_veto_la, &b_Ndata_NA_veto_la);
   fChain->SetBranchAddress("NA.veto.la", NA_veto_la, &b_NA_veto_la);
   fChain->SetBranchAddress("Ndata.NA.veto.la_c", &Ndata_NA_veto_la_c, &b_Ndata_NA_veto_la_c);
   fChain->SetBranchAddress("NA.veto.la_c", NA_veto_la_c, &b_NA_veto_la_c);
   fChain->SetBranchAddress("Ndata.NA.veto.lt", &Ndata_NA_veto_lt, &b_Ndata_NA_veto_lt);
   fChain->SetBranchAddress("NA.veto.lt", NA_veto_lt, &b_NA_veto_lt);
   fChain->SetBranchAddress("Ndata.NA.veto.lt_c", &Ndata_NA_veto_lt_c, &b_Ndata_NA_veto_lt_c);
   fChain->SetBranchAddress("NA.veto.lt_c", NA_veto_lt_c, &b_NA_veto_lt_c);
   fChain->SetBranchAddress("Ndata.NA.veto.ra", &Ndata_NA_veto_ra, &b_Ndata_NA_veto_ra);
   fChain->SetBranchAddress("NA.veto.ra", NA_veto_ra, &b_NA_veto_ra);
   fChain->SetBranchAddress("Ndata.NA.veto.ra_c", &Ndata_NA_veto_ra_c, &b_Ndata_NA_veto_ra_c);
   fChain->SetBranchAddress("NA.veto.ra_c", NA_veto_ra_c, &b_NA_veto_ra_c);
   fChain->SetBranchAddress("Ndata.NA.veto.rt", &Ndata_NA_veto_rt, &b_Ndata_NA_veto_rt);
   fChain->SetBranchAddress("NA.veto.rt", NA_veto_rt, &b_NA_veto_rt);
   fChain->SetBranchAddress("Ndata.NA.veto.rt_c", &Ndata_NA_veto_rt_c, &b_Ndata_NA_veto_rt_c);
   fChain->SetBranchAddress("NA.veto.rt_c", NA_veto_rt_c, &b_NA_veto_rt_c);
   fChain->SetBranchAddress("Ndata.R.tr.beta", &Ndata_R_tr_beta, &b_Ndata_R_tr_beta);
   fChain->SetBranchAddress("R.tr.beta", R_tr_beta, &b_R_tr_beta);
   fChain->SetBranchAddress("Ndata.R.tr.ph", &Ndata_R_tr_ph, &b_Ndata_R_tr_ph);
   fChain->SetBranchAddress("R.tr.ph", R_tr_ph, &b_R_tr_ph);
   fChain->SetBranchAddress("Ndata.R.tr.th", &Ndata_R_tr_th, &b_Ndata_R_tr_th);
   fChain->SetBranchAddress("R.tr.th", R_tr_th, &b_R_tr_th);
   fChain->SetBranchAddress("Ndata.R.tr.x", &Ndata_R_tr_x, &b_Ndata_R_tr_x);
   fChain->SetBranchAddress("R.tr.x", R_tr_x, &b_R_tr_x);
   fChain->SetBranchAddress("Ndata.R.tr.y", &Ndata_R_tr_y, &b_Ndata_R_tr_y);
   fChain->SetBranchAddress("R.tr.y", R_tr_y, &b_R_tr_y);
   fChain->SetBranchAddress("D.evtypebits", &D_evtypebits, &b_D_evtypebits);
   fChain->SetBranchAddress("ExTgtCor_R.dp", &ExTgtCor_R_dp, &b_ExTgtCor_R_dp);
   fChain->SetBranchAddress("ExTgtCor_R.p", &ExTgtCor_R_p, &b_ExTgtCor_R_p);
   fChain->SetBranchAddress("ExTgtCor_R.ph", &ExTgtCor_R_ph, &b_ExTgtCor_R_ph);
   fChain->SetBranchAddress("ExTgtCor_R.th", &ExTgtCor_R_th, &b_ExTgtCor_R_th);
   fChain->SetBranchAddress("ExTgtCor_R.x", &ExTgtCor_R_x, &b_ExTgtCor_R_x);
   fChain->SetBranchAddress("ExTgtCor_R.y", &ExTgtCor_R_y, &b_ExTgtCor_R_y);
   fChain->SetBranchAddress("NA.veto.ishitl", &NA_veto_ishitl, &b_NA_veto_ishitl);
   fChain->SetBranchAddress("NA.veto.ishitr", &NA_veto_ishitr, &b_NA_veto_ishitr);
   fChain->SetBranchAddress("PriKineR.Q2", &PriKineR_Q2, &b_PriKineR_Q2);
   fChain->SetBranchAddress("PriKineR.W2", &PriKineR_W2, &b_PriKineR_W2);
   fChain->SetBranchAddress("PriKineR.angle", &PriKineR_angle, &b_PriKineR_angle);
   fChain->SetBranchAddress("PriKineR.nu", &PriKineR_nu, &b_PriKineR_nu);
   fChain->SetBranchAddress("PriKineR.x_bj", &PriKineR_x_bj, &b_PriKineR_x_bj);
   fChain->SetBranchAddress("PriKineRHe3.x_bj", &PriKineRHe3_x_bj, &b_PriKineRHe3_x_bj);
   fChain->SetBranchAddress("R.cer.asum_c", &R_cer_asum_c, &b_R_cer_asum_c);
   fChain->SetBranchAddress("R.gold.dp", &R_gold_dp, &b_R_gold_dp);
   fChain->SetBranchAddress("R.gold.p", &R_gold_p, &b_R_gold_p);
   fChain->SetBranchAddress("R.gold.ph", &R_gold_ph, &b_R_gold_ph);
   fChain->SetBranchAddress("R.gold.th", &R_gold_th, &b_R_gold_th);
   fChain->SetBranchAddress("R.gold.y", &R_gold_y, &b_R_gold_y);
   fChain->SetBranchAddress("R.ps.e", &R_ps_e, &b_R_ps_e);
   fChain->SetBranchAddress("R.sh.e", &R_sh_e, &b_R_sh_e);
   fChain->SetBranchAddress("R.tr.n", &R_tr_n, &b_R_tr_n);
   fChain->SetBranchAddress("R.vdc.u1.nclust", &R_vdc_u1_nclust, &b_R_vdc_u1_nclust);
   fChain->SetBranchAddress("R.vdc.u1.nhit", &R_vdc_u1_nhit, &b_R_vdc_u1_nhit);
   fChain->SetBranchAddress("R.vdc.u2.nclust", &R_vdc_u2_nclust, &b_R_vdc_u2_nclust);
   fChain->SetBranchAddress("R.vdc.u2.nhit", &R_vdc_u2_nhit, &b_R_vdc_u2_nhit);
   fChain->SetBranchAddress("R.vdc.v1.nclust", &R_vdc_v1_nclust, &b_R_vdc_v1_nclust);
   fChain->SetBranchAddress("R.vdc.v1.nhit", &R_vdc_v1_nhit, &b_R_vdc_v1_nhit);
   fChain->SetBranchAddress("R.vdc.v2.nclust", &R_vdc_v2_nclust, &b_R_vdc_v2_nclust);
   fChain->SetBranchAddress("R.vdc.v2.nhit", &R_vdc_v2_nhit, &b_R_vdc_v2_nhit);
   fChain->SetBranchAddress("ReactPt_R.z", &ReactPt_R_z, &b_ReactPt_R_z);
   fChain->SetBranchAddress("adchel.R.adc", &adchel_R_adc, &b_adchel_R_adc);
   fChain->SetBranchAddress("adchel.R.adc_hel", &adchel_R_adc_hel, &b_adchel_R_adc_hel);
   fChain->SetBranchAddress("adchel.R.gate_adc", &adchel_R_gate_adc, &b_adchel_R_gate_adc);
   fChain->SetBranchAddress("adchel.R.helicity", &adchel_R_helicity, &b_adchel_R_helicity);
   fChain->SetBranchAddress("g.evlen", &g_evlen, &b_g_evlen);
   fChain->SetBranchAddress("g.evnum", &g_evnum, &b_g_evnum);
   fChain->SetBranchAddress("g.evtime", &g_evtime, &b_g_evtime);
   fChain->SetBranchAddress("g.evtyp", &g_evtyp, &b_g_evtyp);
   fChain->SetBranchAddress("g.runnum", &g_runnum, &b_g_runnum);
   fChain->SetBranchAddress("g.runtime", &g_runtime, &b_g_runtime);
   fChain->SetBranchAddress("g.runtype", &g_runtype, &b_g_runtype);
   fChain->SetBranchAddress("g0hel.R.gate", &g0hel_R_gate, &b_g0hel_R_gate);
   fChain->SetBranchAddress("g0hel.R.helicity", &g0hel_R_helicity, &b_g0hel_R_helicity);
   fChain->SetBranchAddress("g0hel.R.nqrt", &g0hel_R_nqrt, &b_g0hel_R_nqrt);
   fChain->SetBranchAddress("g0hel.R.pread", &g0hel_R_pread, &b_g0hel_R_pread);
   fChain->SetBranchAddress("g0hel.R.qrt", &g0hel_R_qrt, &b_g0hel_R_qrt);
   fChain->SetBranchAddress("g0hel.R.quad", &g0hel_R_quad, &b_g0hel_R_quad);
   fChain->SetBranchAddress("g0hel.R.tdiff", &g0hel_R_tdiff, &b_g0hel_R_tdiff);
   fChain->SetBranchAddress("g0hel.R.timestamp", &g0hel_R_timestamp, &b_g0hel_R_timestamp);
   fChain->SetBranchAddress("g0hel.R.validHel", &g0hel_R_validHel, &b_g0hel_R_validHel);
   fChain->SetBranchAddress("g0hel.R.validtime", &g0hel_R_validtime, &b_g0hel_R_validtime);
   fChain->SetBranchAddress("he3R.IsSpinValid", &he3R_IsSpinValid, &b_he3R_IsSpinValid);
   fChain->SetBranchAddress("he3R.Spin", &he3R_Spin, &b_he3R_Spin);
   fChain->SetBranchAddress("he3R.radc1.DownADC", &he3R_radc1_DownADC, &b_he3R_radc1_DownADC);
   fChain->SetBranchAddress("he3R.radc1.IsSpinValid", &he3R_radc1_IsSpinValid, &b_he3R_radc1_IsSpinValid);
   fChain->SetBranchAddress("he3R.radc1.Spin", &he3R_radc1_Spin, &b_he3R_radc1_Spin);
   fChain->SetBranchAddress("he3R.radc1.UpADC", &he3R_radc1_UpADC, &b_he3R_radc1_UpADC);
   fChain->SetBranchAddress("IPM1H04B.XPOS", &IPM1H04B_XPOS, &b_IPM1H04B_XPOS);
   fChain->SetBranchAddress("IPM1H04B.YPOS", &IPM1H04B_YPOS, &b_IPM1H04B_YPOS);
   fChain->SetBranchAddress("hac_bcm_average", &hac_bcm_average, &b_hac_bcm_average);
   fChain->SetBranchAddress("hac_bcm_dvm1_read", &hac_bcm_dvm1_read, &b_hac_bcm_dvm1_read);
   fChain->SetBranchAddress("hac_bcm_dvm2_read", &hac_bcm_dvm2_read, &b_hac_bcm_dvm2_read);
   fChain->SetBranchAddress("hac_bcm_dvm1_current", &hac_bcm_dvm1_current, &b_hac_bcm_dvm1_current);
   fChain->SetBranchAddress("hac_bcm_dvm2_current", &hac_bcm_dvm2_current, &b_hac_bcm_dvm2_current);
   fChain->SetBranchAddress("hac_unser_current", &hac_unser_current, &b_hac_unser_current);
   fChain->SetBranchAddress("HacL_D1_NMR_SIG", &HacL_D1_NMR_SIG, &b_HacL_D1_NMR_SIG);
   fChain->SetBranchAddress("IBC0L02Current", &IBC0L02Current, &b_IBC0L02Current);
   fChain->SetBranchAddress("IFY1H04_rtd_target", &IFY1H04_rtd_target, &b_IFY1H04_rtd_target);
   fChain->SetBranchAddress("IFY1H04_rtd_P11042", &IFY1H04_rtd_P11042, &b_IFY1H04_rtd_P11042);
   fChain->SetBranchAddress("IFY1H04_rtd_P11047", &IFY1H04_rtd_P11047, &b_IFY1H04_rtd_P11047);
   fChain->SetBranchAddress("IFY1H04_rtd_P11044", &IFY1H04_rtd_P11044, &b_IFY1H04_rtd_P11044);
   fChain->SetBranchAddress("IFY1H04_rtd_P11048", &IFY1H04_rtd_P11048, &b_IFY1H04_rtd_P11048);
   fChain->SetBranchAddress("IFY1H04_rtd_P11055", &IFY1H04_rtd_P11055, &b_IFY1H04_rtd_P11055);
   fChain->SetBranchAddress("IFY1H04_rtd_P11051", &IFY1H04_rtd_P11051, &b_IFY1H04_rtd_P11051);
   fChain->SetBranchAddress("right_trigger_1", &right_trigger_1, &b_right_trigger_1);
   fChain->SetBranchAddress("right_trigger_2", &right_trigger_2, &b_right_trigger_2);
   fChain->SetBranchAddress("right_trigger_3", &right_trigger_3, &b_right_trigger_3);
   fChain->SetBranchAddress("right_trigger_4", &right_trigger_4, &b_right_trigger_4);
   fChain->SetBranchAddress("right_trigger_5", &right_trigger_5, &b_right_trigger_5);
   fChain->SetBranchAddress("right_trigger_6", &right_trigger_6, &b_right_trigger_6);
   fChain->SetBranchAddress("right_trigger_7", &right_trigger_7, &b_right_trigger_7);
   fChain->SetBranchAddress("right_trigger_8", &right_trigger_8, &b_right_trigger_8);
   fChain->SetBranchAddress("right_trigger_9", &right_trigger_9, &b_right_trigger_9);
   fChain->SetBranchAddress("right_trigger_10", &right_trigger_10, &b_right_trigger_10);
   fChain->SetBranchAddress("right_trigger_11", &right_trigger_11, &b_right_trigger_11);
   fChain->SetBranchAddress("right_trigger_12", &right_trigger_12, &b_right_trigger_12);
   fChain->SetBranchAddress("right_bcm_u1", &right_bcm_u1, &b_right_bcm_u1);
   fChain->SetBranchAddress("right_bcm_u3", &right_bcm_u3, &b_right_bcm_u3);
   fChain->SetBranchAddress("right_bcm_u10", &right_bcm_u10, &b_right_bcm_u10);
   fChain->SetBranchAddress("right_bcm_d1", &right_bcm_d1, &b_right_bcm_d1);
   fChain->SetBranchAddress("right_bcm_d3", &right_bcm_d3, &b_right_bcm_d3);
   fChain->SetBranchAddress("right_bcm_d10", &right_bcm_d10, &b_right_bcm_d10);
   fChain->SetBranchAddress("right_clock", &right_clock, &b_right_clock);
   fChain->SetBranchAddress("right_TS_accept", &right_TS_accept, &b_right_TS_accept);
   fChain->SetBranchAddress("right_edtpulser", &right_edtpulser, &b_right_edtpulser);
   fChain->SetBranchAddress("right_strobe", &right_strobe, &b_right_strobe);
   fChain->SetBranchAddress("right_dclock", &right_dclock, &b_right_dclock);
   fChain->SetBranchAddress("right_T1cnt", &right_T1cnt, &b_right_T1cnt);
   fChain->SetBranchAddress("right_T2cnt", &right_T2cnt, &b_right_T2cnt);
   fChain->SetBranchAddress("right_T3cnt", &right_T3cnt, &b_right_T3cnt);
   fChain->SetBranchAddress("right_T4cnt", &right_T4cnt, &b_right_T4cnt);
   fChain->SetBranchAddress("right_T5cnt", &right_T5cnt, &b_right_T5cnt);
   fChain->SetBranchAddress("right_T6cnt", &right_T6cnt, &b_right_T6cnt);
   fChain->SetBranchAddress("right_T7cnt", &right_T7cnt, &b_right_T7cnt);
   fChain->SetBranchAddress("right_Tacc_cnt", &right_Tacc_cnt, &b_right_Tacc_cnt);
   fChain->SetBranchAddress("right_P_T1cnt", &right_P_T1cnt, &b_right_P_T1cnt);
   fChain->SetBranchAddress("right_P_T2cnt", &right_P_T2cnt, &b_right_P_T2cnt);
   fChain->SetBranchAddress("right_P_T3cnt", &right_P_T3cnt, &b_right_P_T3cnt);
   fChain->SetBranchAddress("right_P_T4cnt", &right_P_T4cnt, &b_right_P_T4cnt);
   fChain->SetBranchAddress("right_P_T5cnt", &right_P_T5cnt, &b_right_P_T5cnt);
   fChain->SetBranchAddress("right_P_T6cnt", &right_P_T6cnt, &b_right_P_T6cnt);
   fChain->SetBranchAddress("right_P_T7cnt", &right_P_T7cnt, &b_right_P_T7cnt);
   fChain->SetBranchAddress("right_P_Tacc_cnt", &right_P_Tacc_cnt, &b_right_P_Tacc_cnt);
   fChain->SetBranchAddress("right_M_T1cnt", &right_M_T1cnt, &b_right_M_T1cnt);
   fChain->SetBranchAddress("right_M_T2cnt", &right_M_T2cnt, &b_right_M_T2cnt);
   fChain->SetBranchAddress("right_M_T3cnt", &right_M_T3cnt, &b_right_M_T3cnt);
   fChain->SetBranchAddress("right_M_T4cnt", &right_M_T4cnt, &b_right_M_T4cnt);
   fChain->SetBranchAddress("right_M_T5cnt", &right_M_T5cnt, &b_right_M_T5cnt);
   fChain->SetBranchAddress("right_M_T6cnt", &right_M_T6cnt, &b_right_M_T6cnt);
   fChain->SetBranchAddress("right_M_T7cnt", &right_M_T7cnt, &b_right_M_T7cnt);
   fChain->SetBranchAddress("right_M_Tacc_cnt", &right_M_Tacc_cnt, &b_right_M_Tacc_cnt);
   fChain->SetBranchAddress("right_clkcount", &right_clkcount, &b_right_clkcount);
   fChain->SetBranchAddress("right_P_clkcount", &right_P_clkcount, &b_right_P_clkcount);
   fChain->SetBranchAddress("right_M_clkcount", &right_M_clkcount, &b_right_M_clkcount);
   fChain->SetBranchAddress("right_bcmu1cnt", &right_bcmu1cnt, &b_right_bcmu1cnt);
   fChain->SetBranchAddress("right_bcmu3cnt", &right_bcmu3cnt, &b_right_bcmu3cnt);
   fChain->SetBranchAddress("right_bcmu10cnt", &right_bcmu10cnt, &b_right_bcmu10cnt);
   fChain->SetBranchAddress("right_bcmd1cnt", &right_bcmd1cnt, &b_right_bcmd1cnt);
   fChain->SetBranchAddress("right_bcmd3cnt", &right_bcmd3cnt, &b_right_bcmd3cnt);
   fChain->SetBranchAddress("right_bcmd10cnt", &right_bcmd10cnt, &b_right_bcmd10cnt);
   fChain->SetBranchAddress("right_P_bcmu1cnt", &right_P_bcmu1cnt, &b_right_P_bcmu1cnt);
   fChain->SetBranchAddress("right_P_bcmu3cnt", &right_P_bcmu3cnt, &b_right_P_bcmu3cnt);
   fChain->SetBranchAddress("right_P_bcmu10cnt", &right_P_bcmu10cnt, &b_right_P_bcmu10cnt);
   fChain->SetBranchAddress("right_P_bcmd1cnt", &right_P_bcmd1cnt, &b_right_P_bcmd1cnt);
   fChain->SetBranchAddress("right_P_bcmd3cnt", &right_P_bcmd3cnt, &b_right_P_bcmd3cnt);
   fChain->SetBranchAddress("right_P_bcmd10cnt", &right_P_bcmd10cnt, &b_right_P_bcmd10cnt);
   fChain->SetBranchAddress("right_M_bcmu1cnt", &right_M_bcmu1cnt, &b_right_M_bcmu1cnt);
   fChain->SetBranchAddress("right_M_bcmu3cnt", &right_M_bcmu3cnt, &b_right_M_bcmu3cnt);
   fChain->SetBranchAddress("right_M_bcmu10cnt", &right_M_bcmu10cnt, &b_right_M_bcmu10cnt);
   fChain->SetBranchAddress("right_M_bcmd1cnt", &right_M_bcmd1cnt, &b_right_M_bcmd1cnt);
   fChain->SetBranchAddress("right_M_bcmd3cnt", &right_M_bcmd3cnt, &b_right_M_bcmd3cnt);
   fChain->SetBranchAddress("right_M_bcmd10cnt", &right_M_bcmd10cnt, &b_right_M_bcmd10cnt);
   fChain->SetBranchAddress("right_T1", &right_T1, &b_right_T1);
   fChain->SetBranchAddress("right_T2", &right_T2, &b_right_T2);
   fChain->SetBranchAddress("right_T3", &right_T3, &b_right_T3);
   fChain->SetBranchAddress("right_T4", &right_T4, &b_right_T4);
   fChain->SetBranchAddress("right_T5", &right_T5, &b_right_T5);
   fChain->SetBranchAddress("right_T6", &right_T6, &b_right_T6);
   fChain->SetBranchAddress("right_T7", &right_T7, &b_right_T7);
   fChain->SetBranchAddress("right_Tacc", &right_Tacc, &b_right_Tacc);
   fChain->SetBranchAddress("right_P_T1", &right_P_T1, &b_right_P_T1);
   fChain->SetBranchAddress("right_P_T2", &right_P_T2, &b_right_P_T2);
   fChain->SetBranchAddress("right_P_T3", &right_P_T3, &b_right_P_T3);
   fChain->SetBranchAddress("right_P_T4", &right_P_T4, &b_right_P_T4);
   fChain->SetBranchAddress("right_P_T5", &right_P_T5, &b_right_P_T5);
   fChain->SetBranchAddress("right_P_T6", &right_P_T6, &b_right_P_T6);
   fChain->SetBranchAddress("right_P_T7", &right_P_T7, &b_right_P_T7);
   fChain->SetBranchAddress("right_P_Tacc", &right_P_Tacc, &b_right_P_Tacc);
   fChain->SetBranchAddress("right_M_T1", &right_M_T1, &b_right_M_T1);
   fChain->SetBranchAddress("right_M_T2", &right_M_T2, &b_right_M_T2);
   fChain->SetBranchAddress("right_M_T3", &right_M_T3, &b_right_M_T3);
   fChain->SetBranchAddress("right_M_T4", &right_M_T4, &b_right_M_T4);
   fChain->SetBranchAddress("right_M_T5", &right_M_T5, &b_right_M_T5);
   fChain->SetBranchAddress("right_M_T6", &right_M_T6, &b_right_M_T6);
   fChain->SetBranchAddress("right_M_T7", &right_M_T7, &b_right_M_T7);
   fChain->SetBranchAddress("right_M_Tacc", &right_M_Tacc, &b_right_M_Tacc);
   fChain->SetBranchAddress("right_clk", &right_clk, &b_right_clk);
   fChain->SetBranchAddress("right_P_clk", &right_P_clk, &b_right_P_clk);
   fChain->SetBranchAddress("right_M_clk", &right_M_clk, &b_right_M_clk);
   fChain->SetBranchAddress("right_bcmu1", &right_bcmu1, &b_right_bcmu1);
   fChain->SetBranchAddress("right_bcmu3", &right_bcmu3, &b_right_bcmu3);
   fChain->SetBranchAddress("right_bcmu10", &right_bcmu10, &b_right_bcmu10);
   fChain->SetBranchAddress("right_bcmd1", &right_bcmd1, &b_right_bcmd1);
   fChain->SetBranchAddress("right_bcmd3", &right_bcmd3, &b_right_bcmd3);
   fChain->SetBranchAddress("right_bcmd10", &right_bcmd10, &b_right_bcmd10);
   fChain->SetBranchAddress("right_P_bcmu1", &right_P_bcmu1, &b_right_P_bcmu1);
   fChain->SetBranchAddress("right_P_bcmu3", &right_P_bcmu3, &b_right_P_bcmu3);
   fChain->SetBranchAddress("right_P_bcmu10", &right_P_bcmu10, &b_right_P_bcmu10);
   fChain->SetBranchAddress("right_P_bcmd1", &right_P_bcmd1, &b_right_P_bcmd1);
   fChain->SetBranchAddress("right_P_bcmd3", &right_P_bcmd3, &b_right_P_bcmd3);
   fChain->SetBranchAddress("right_P_bcmd10", &right_P_bcmd10, &b_right_P_bcmd10);
   fChain->SetBranchAddress("right_M_bcmu1", &right_M_bcmu1, &b_right_M_bcmu1);
   fChain->SetBranchAddress("right_M_bcmu3", &right_M_bcmu3, &b_right_M_bcmu3);
   fChain->SetBranchAddress("right_M_bcmu10", &right_M_bcmu10, &b_right_M_bcmu10);
   fChain->SetBranchAddress("right_M_bcmd1", &right_M_bcmd1, &b_right_M_bcmd1);
   fChain->SetBranchAddress("right_M_bcmd3", &right_M_bcmd3, &b_right_M_bcmd3);
   fChain->SetBranchAddress("right_M_bcmd10", &right_M_bcmd10, &b_right_M_bcmd10);
   fChain->SetBranchAddress("evright_t1c", &evright_t1c, &b_evright_t1c);
   fChain->SetBranchAddress("evright_t2c", &evright_t2c, &b_evright_t2c);
   fChain->SetBranchAddress("evright_t3c", &evright_t3c, &b_evright_t3c);
   fChain->SetBranchAddress("evright_t4c", &evright_t4c, &b_evright_t4c);
   fChain->SetBranchAddress("evright_clkc", &evright_clkc, &b_evright_clkc);
   fChain->SetBranchAddress("evright_l1ac", &evright_l1ac, &b_evright_l1ac);
   fChain->SetBranchAddress("evright_u1cnt", &evright_u1cnt, &b_evright_u1cnt);
   fChain->SetBranchAddress("evright_u3cnt", &evright_u3cnt, &b_evright_u3cnt);
   fChain->SetBranchAddress("evright_u10cnt", &evright_u10cnt, &b_evright_u10cnt);
   fChain->SetBranchAddress("evright_d1cnt", &evright_d1cnt, &b_evright_d1cnt);
   fChain->SetBranchAddress("evright_d3cnt", &evright_d3cnt, &b_evright_d3cnt);
   fChain->SetBranchAddress("evright_d10cnt", &evright_d10cnt, &b_evright_d10cnt);
   fChain->SetBranchAddress("evright_fclkc", &evright_fclkc, &b_evright_fclkc);
   fChain->SetBranchAddress("evright_u1c", &evright_u1c, &b_evright_u1c);
   fChain->SetBranchAddress("evright_u3c", &evright_u3c, &b_evright_u3c);
   fChain->SetBranchAddress("evright_u10c", &evright_u10c, &b_evright_u10c);
   fChain->SetBranchAddress("evright_d1c", &evright_d1c, &b_evright_d1c);
   fChain->SetBranchAddress("evright_d3c", &evright_d3c, &b_evright_d3c);
   fChain->SetBranchAddress("evright_d10c", &evright_d10c, &b_evright_d10c);
   fChain->SetBranchAddress("evright_t1r", &evright_t1r, &b_evright_t1r);
   fChain->SetBranchAddress("evright_t2r", &evright_t2r, &b_evright_t2r);
   fChain->SetBranchAddress("evright_t3r", &evright_t3r, &b_evright_t3r);
   fChain->SetBranchAddress("evright_t4r", &evright_t4r, &b_evright_t4r);
   fChain->SetBranchAddress("evright_u1r", &evright_u1r, &b_evright_u1r);
   fChain->SetBranchAddress("evright_u3r", &evright_u3r, &b_evright_u3r);
   fChain->SetBranchAddress("evright_u10r", &evright_u10r, &b_evright_u10r);
   fChain->SetBranchAddress("evright_d1r", &evright_d1r, &b_evright_d1r);
   fChain->SetBranchAddress("evright_d3r", &evright_d3r, &b_evright_d3r);
   fChain->SetBranchAddress("evright_d10r", &evright_d10r, &b_evright_d10r);
   fChain->SetBranchAddress("evright_clkr", &evright_clkr, &b_evright_clkr);
   fChain->SetBranchAddress("evright_l1ar", &evright_l1ar, &b_evright_l1ar);
   fChain->SetBranchAddress("evright_fclkr", &evright_fclkr, &b_evright_fclkr);
   fChain->SetBranchAddress("evright_l1app", &evright_l1app, &b_evright_l1app);
   fChain->SetBranchAddress("evright_l1apm", &evright_l1apm, &b_evright_l1apm);
   fChain->SetBranchAddress("evright_l1amp", &evright_l1amp, &b_evright_l1amp);
   fChain->SetBranchAddress("evright_l1amm", &evright_l1amm, &b_evright_l1amm);
   fChain->SetBranchAddress("evright_clkpp", &evright_clkpp, &b_evright_clkpp);
   fChain->SetBranchAddress("evright_clkpm", &evright_clkpm, &b_evright_clkpm);
   fChain->SetBranchAddress("evright_clkmp", &evright_clkmp, &b_evright_clkmp);
   fChain->SetBranchAddress("evright_clkmm", &evright_clkmm, &b_evright_clkmm);
   fChain->SetBranchAddress("evright_fclkpp", &evright_fclkpp, &b_evright_fclkpp);
   fChain->SetBranchAddress("evright_fclkpm", &evright_fclkpm, &b_evright_fclkpm);
   fChain->SetBranchAddress("evright_fclkmp", &evright_fclkmp, &b_evright_fclkmp);
   fChain->SetBranchAddress("evright_fclkmm", &evright_fclkmm, &b_evright_fclkmm);
   fChain->SetBranchAddress("evright_u1pp", &evright_u1pp, &b_evright_u1pp);
   fChain->SetBranchAddress("evright_u1pm", &evright_u1pm, &b_evright_u1pm);
   fChain->SetBranchAddress("evright_u1mp", &evright_u1mp, &b_evright_u1mp);
   fChain->SetBranchAddress("evright_u1mm", &evright_u1mm, &b_evright_u1mm);
   fChain->SetBranchAddress("evright_u3pp", &evright_u3pp, &b_evright_u3pp);
   fChain->SetBranchAddress("evright_u3pm", &evright_u3pm, &b_evright_u3pm);
   fChain->SetBranchAddress("evright_u3mp", &evright_u3mp, &b_evright_u3mp);
   fChain->SetBranchAddress("evright_u3mm", &evright_u3mm, &b_evright_u3mm);
   fChain->SetBranchAddress("evright_u10pp", &evright_u10pp, &b_evright_u10pp);
   fChain->SetBranchAddress("evright_u10pm", &evright_u10pm, &b_evright_u10pm);
   fChain->SetBranchAddress("evright_u10mp", &evright_u10mp, &b_evright_u10mp);
   fChain->SetBranchAddress("evright_u10mm", &evright_u10mm, &b_evright_u10mm);
   fChain->SetBranchAddress("evright_d1pp", &evright_d1pp, &b_evright_d1pp);
   fChain->SetBranchAddress("evright_d1pm", &evright_d1pm, &b_evright_d1pm);
   fChain->SetBranchAddress("evright_d1mp", &evright_d1mp, &b_evright_d1mp);
   fChain->SetBranchAddress("evright_d1mm", &evright_d1mm, &b_evright_d1mm);
   fChain->SetBranchAddress("evright_d3pp", &evright_d3pp, &b_evright_d3pp);
   fChain->SetBranchAddress("evright_d3pm", &evright_d3pm, &b_evright_d3pm);
   fChain->SetBranchAddress("evright_d3mp", &evright_d3mp, &b_evright_d3mp);
   fChain->SetBranchAddress("evright_d3mm", &evright_d3mm, &b_evright_d3mm);
   fChain->SetBranchAddress("evright_d10pp", &evright_d10pp, &b_evright_d10pp);
   fChain->SetBranchAddress("evright_d10pm", &evright_d10pm, &b_evright_d10pm);
   fChain->SetBranchAddress("evright_d10mp", &evright_d10mp, &b_evright_d10mp);
   fChain->SetBranchAddress("evright_d10mm", &evright_d10mm, &b_evright_d10mm);
   fChain->SetBranchAddress("evright_t1pp", &evright_t1pp, &b_evright_t1pp);
   fChain->SetBranchAddress("evright_t1pm", &evright_t1pm, &b_evright_t1pm);
   fChain->SetBranchAddress("evright_t1mp", &evright_t1mp, &b_evright_t1mp);
   fChain->SetBranchAddress("evright_t1mm", &evright_t1mm, &b_evright_t1mm);
   fChain->SetBranchAddress("evright_t2pp", &evright_t2pp, &b_evright_t2pp);
   fChain->SetBranchAddress("evright_t2pm", &evright_t2pm, &b_evright_t2pm);
   fChain->SetBranchAddress("evright_t2mp", &evright_t2mp, &b_evright_t2mp);
   fChain->SetBranchAddress("evright_t2mm", &evright_t2mm, &b_evright_t2mm);
   fChain->SetBranchAddress("evright_t3pp", &evright_t3pp, &b_evright_t3pp);
   fChain->SetBranchAddress("evright_t3pm", &evright_t3pm, &b_evright_t3pm);
   fChain->SetBranchAddress("evright_t3mp", &evright_t3mp, &b_evright_t3mp);
   fChain->SetBranchAddress("evright_t3mm", &evright_t3mm, &b_evright_t3mm);
   fChain->SetBranchAddress("evright_t4pp", &evright_t4pp, &b_evright_t4pp);
   fChain->SetBranchAddress("evright_t4pm", &evright_t4pm, &b_evright_t4pm);
   fChain->SetBranchAddress("evright_t4mp", &evright_t4mp, &b_evright_t4mp);
   fChain->SetBranchAddress("evright_t4mm", &evright_t4mm, &b_evright_t4mm);
//    fChain->SetBranchAddress("R_sv_x", &R_sv_x, &b_R_sv_x);
//    fChain->SetBranchAddress("R_sv_y", &R_sv_y, &b_R_sv_y);
//    fChain->SetBranchAddress("IsReftHelicity", &IsReftHelicity, &b_IsReftHelicity);
//    fChain->SetBranchAddress("IsRightHelicity", &IsRightHelicity, &b_IsRightHelicity);
//    fChain->SetBranchAddress("InclusiveEvt", &InclusiveEvt, &b_InclusiveEvt);
//    fChain->SetBranchAddress("GoodRTrack", &GoodRTrack, &b_GoodRTrack);
//    fChain->SetBranchAddress("GoodElectron", &GoodElectron, &b_GoodElectron);
//    fChain->SetBranchAddress("InclCut", &InclCut, &b_InclCut);
//    fChain->SetBranchAddress("InvMass", &InvMass, &b_InvMass);
//    fChain->SetBranchAddress("ScaAngle", &ScaAngle, &b_ScaAngle);
   fChain->SetBranchAddress("fEvtHdr.fEvtTime", &fEvtHdr_fEvtTime, &b_Event_Branch_fEvtHdr_fEvtTime);
   fChain->SetBranchAddress("fEvtHdr.fEvtNum", &fEvtHdr_fEvtNum, &b_Event_Branch_fEvtHdr_fEvtNum);
   fChain->SetBranchAddress("fEvtHdr.fEvtType", &fEvtHdr_fEvtType, &b_Event_Branch_fEvtHdr_fEvtType);
   fChain->SetBranchAddress("fEvtHdr.fEvtLen", &fEvtHdr_fEvtLen, &b_Event_Branch_fEvtHdr_fEvtLen);
   fChain->SetBranchAddress("fEvtHdr.fHelicity", &fEvtHdr_fHelicity, &b_Event_Branch_fEvtHdr_fHelicity);
   fChain->SetBranchAddress("fEvtHdr.fTargetPol", &fEvtHdr_fTargetPol, &b_Event_Branch_fEvtHdr_fTargetPol);
   fChain->SetBranchAddress("fEvtHdr.fRun", &fEvtHdr_fRun, &b_Event_Branch_fEvtHdr_fRun);
   Notify();
}

Bool_t neutron_analysis_class::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void neutron_analysis_class::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t neutron_analysis_class::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef neutron_analysis_class_cxx
