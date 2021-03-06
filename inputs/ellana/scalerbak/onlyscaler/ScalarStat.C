// Scalar Display Script

//It is modified for Ay experiment since Left and Right arm are synchronized, 
// but data replay is seperate on two root files. Here evleft and evright are
// used, which means that 1 entry for each 100 events.

//   by Jin Huang <jinhuang@jlab.org>
//
// This is part of online display script for E06010 Transvesity scalar replay

#include <stdlib.h>
#include <TString.h>

UInt_t totEntL=200000;
UInt_t totEntR=200000;

UInt_t lowentry = 0;
UInt_t highentry = 0;

/*
Double_t GetDiffRate(TString chan, TTree *T1, TTree *T2)
{
 for(int ii=0; ii<20; ii++)
 {

        Double_t ll=0,lh=0, rl=0,rh=0;
        TString sl="", sr = "";
        sl+=chan;sr+=chan;

        cout<<"GetDiffRate : Set Branch of "<<sl<<" and "<<sr<<endl;
        T1->SetBranchAddress(sl.Data(),&ll);
        T2->SetBranchAddress(sr.Data(),&rl);
        T1->GetEntry(lowentry+ii);
        T2->GetEntry(lowentry+ii);

        T1->SetBranchAddress(sl.Data(),&lh);
        T2->SetBranchAddress(sr.Data(),&rh);
        T1->GetEntry(totEntL);
        T2->GetEntry(totEntR-2);
        T1->ResetBranchAddresses();
        T2->ResetBranchAddresses();

//      cout << ll << " " << rl << ",   " << ll-rl << endl;

        cout<<"GetDiffRate : "<<"ll="<<ll<<"; lh="<<lh<<"; rl="<<rl<<"; rh="<<rh<<endl;
 }
        return 2 * ((lh-ll) - (rh-rl)) / ((lh-ll) + (rh-rl)+1e-10);

}
*/


Double_t GetDiffRate(TString chan, TTree *T1, TTree *T2)
{

	Double_t ll=0,lh=0, rl=0,rh=0;
	TString sl="", sr = "";
	sl+=chan;sr+=chan;
			
	cout<<"GetDiffRate : Set Branch of "<<sl<<" and "<<sr<<endl;
	T1->SetBranchAddress(sl.Data(),&ll);
	T2->SetBranchAddress(sr.Data(),&rl);
	T1->GetEntry(lowentry);
	T2->GetEntry(lowentry);
	
	T1->SetBranchAddress(sl.Data(),&lh);
	T2->SetBranchAddress(sr.Data(),&rh);
	T1->GetEntry(totEntL);
	T2->GetEntry(totEntR);
	T1->ResetBranchAddresses();
	T2->ResetBranchAddresses();
		
	cout<<"GetDiffRate : "<<"ll="<<ll<<"; lh="<<lh<<"; rl="<<rl<<"; rh="<<rh<<endl;

	return 2 * ((lh-ll) - (rh-rl)) / ((lh-ll) + (rh-rl)+1e-10);
}


Double_t GetTgspinDiffRate(TString chan, TString tgspin, TTree *T1, TTree *T2)
{
	Double_t ll1=0,lh1=0, rl1=0,rh1=0;
	Double_t ll2=0,lh2=0, rl2=0,rh2=0;
	TString sl1="", sr1 = "";
	TString sl2="", sr2 = "";
	
	sl1 = sl1 + chan + tgspin + "p"; sr1 = sr1 + chan + tgspin + "p";
	
	cout<<"GetDiffRate : Set Branch of "<<sl1<<" and "<<sr1<<endl;
	T1->SetBranchAddress(sl1.Data(),&ll1);
	T2->SetBranchAddress(sr1.Data(),&rl1);
	T1->GetEntry(lowentry);
	T2->GetEntry(lowentry);
	
	T1->SetBranchAddress(sl1.Data(),&lh1);
	T2->SetBranchAddress(sr1.Data(),&rh1);
	T1->GetEntry(totEntL);
	T2->GetEntry(totEntR);
	T1->ResetBranchAddresses();
	T2->ResetBranchAddresses();
		
	cout<<"GetDiffRate : "<<"ll1="<<ll1<<"; lh1="<<lh1<<"; rl1="<<rl1<<"; rh1="<<rh1<<endl;
	
//	return 2 * ((lh1-ll1) - (rh1-rl1)) / ((lh1-ll1) + (rh1-rl1)+1e-10);
	
	sl2 = sl2 + chan + tgspin + "m"; sr2 = sr2 + chan + tgspin + "m";
	
	cout<<"GetDiffRate : Set Branch of "<<sl2<<" and "<<sr2<<endl;
	T1->SetBranchAddress(sl2.Data(),&ll2);
	T2->SetBranchAddress(sr2.Data(),&rl2);
	T1->GetEntry(lowentry);
	T2->GetEntry(lowentry);
	
	T1->SetBranchAddress(sl2.Data(),&lh2);
	T2->SetBranchAddress(sr2.Data(),&rh2);
	T1->GetEntry(totEntL);
	T2->GetEntry(totEntR);
	T1->ResetBranchAddresses();
	T2->ResetBranchAddresses();
	
	cout<<"GetDiffRate : "<<"ll2="<<ll2<<"; lh2="<<lh2<<"; rl2="<<rl2<<"; rh2="<<rh2<<endl;
	
	return 2 * ((lh1-ll1) + (lh2-ll2) - (rh1-rl1) - (rh2-rl2)) / ((lh1-ll1) + (lh2-ll2) + (rh1-rl1) + (rh2-rl2) +1e-10);
}

Double_t GetHeliDiffRate(TString chan,TString SpinState)
{

	Double_t pl=0,ph=0,ml=0,mh=0;
	
	TString pre="";
	TString sp=pre+chan+SpinState, sm=pre+chan+SpinState;
	sp+="p";sm+="m";
	
	cout<<"GetDiffRate : Set Branch of "<<sp<<" and "<<sm<<endl;
	T->SetBranchAddress(sp.Data(),&pl);
	T->SetBranchAddress(sm.Data(),&ml);
	T->GetEntry(100);
	T->SetBranchAddress(sp.Data(),&ph);
	T->SetBranchAddress(sm.Data(),&mh);
	T->GetEntry(totEnt-100);
	T->ResetBranchAddresses();
		
	return 2 * ((ph-pl) - (mh-ml)) / ((ph-pl) + (mh-ml)+1e-10);
}

Double_t GetBCMDiffRate(TString chan,TString SpinHelState)
{

	Double_t pl=0,ph=0,ml=0,mh=0;
	
	TString pre="evbbite_";
	TString sp=pre+"u"+chan+SpinHelState, sm=pre+"d"+chan+SpinHelState;
	
	cout<<"GetDiffRate : Set Branch of "<<sp<<" and "<<sm<<endl;
	T->SetBranchAddress(sp.Data(),&pl);
	T->SetBranchAddress(sm.Data(),&ml);
	T->GetEntry(100);
	T->SetBranchAddress(sp.Data(),&ph);
	T->SetBranchAddress(sm.Data(),&mh);
	T->GetEntry(totEnt-100);
	T->ResetBranchAddresses();
	
	cout<<"GetDiffRate : "<<"pl="<<pl<<"; ph="<<ph<<"; ml="<<ml<<"; mh="<<mh<<endl;
	return 2 * ((ph-pl) - (mh-ml)) / ((ph-pl) + (mh-ml)+1e-10);
}

Double_t GetBCMLossRate(TString chan)
{

	Double_t th,tl,pph,ppl,pmh,pml,mph,mpl,mmh,mml;
	
	TString pre="evbbite_";
	TString st=pre+chan+"c",
		spp=pre+chan+"pp",
		spm=pre+chan+"pm",
		smp=pre+chan+"mp",
		smm=pre+chan+"mm";
	
	cout<<"GetDiffRate : Set Branch of "<<st<<spp<<spm<<smp<<smm<<endl;
	T->SetBranchAddress(st.Data(),&tl);
	T->SetBranchAddress(spp.Data(),&ppl);
	T->SetBranchAddress(spm.Data(),&pml);
	T->SetBranchAddress(smp.Data(),&mpl);
	T->SetBranchAddress(smm.Data(),&mml);
	T->GetEntry(100);
	T->SetBranchAddress(st.Data(),&th);
	T->SetBranchAddress(spp.Data(),&pph);
	T->SetBranchAddress(spm.Data(),&pmh);
	T->SetBranchAddress(smp.Data(),&mph);
	T->SetBranchAddress(smm.Data(),&mmh);
	T->GetEntry(totEnt-100);
	T->ResetBranchAddresses();
	
	return ((th-tl)- (pph-ppl) - (pmh-pml) - (mph-mpl) - (mmh-mml)) / (th-tl+1e-10);
}

void ScalarStat(Int_t RunL, Int_t RunR, Int_t CallType)
{
	char leftfile[1000]="";
	sprintf(leftfile,"./ROOTfiles/e05102_scalar_%d.root", RunL); 
	char rightfile[1000]="";
	sprintf(rightfile,"./ROOTfiles/e05102_scalar_%d.root", RunR); 
	
	TFile lfile(leftfile);
	TFile rfile(rightfile);
	
	TTree *EVLEFT = (TTree*)lfile.Get("EVLEFT");
	TTree *EVRIGHT = (TTree*)rfile.Get("EVRIGHT");
	
	TString lclock = "clkc";
	TString rclock = "clkc";
	
	Double_t clockcntL = 0, clockcntR = 0, clkcL = 0, clkcR=0;
	EVLEFT->SetBranchAddress(lclock.Data(), &clkcL);			
	EVLEFT->GetEntry(EVLEFT->GetEntries()-1-highentry); 
	clockcntL = clkcL;
	totEntL = EVLEFT->GetEntries()-1-highentry;
	
	EVRIGHT->SetBranchAddress(rclock.Data(), &clkcR);
	EVRIGHT->GetEntry(EVRIGHT->GetEntries()-1-highentry);	
	clockcntR = clkcR;
	totEntR = EVRIGHT->GetEntries()-1-highentry;
	
	cout << EVLEFT->GetEntries() << " , " << EVRIGHT->GetEntries() << endl;
	cout << clockcntL << " , " << clockcntR << endl;
	
// Here is a trick to get the same run time for L and R arms
// get the clock counts from right arm, then use it to get scalar 
// from left arm with the same clock counts.	
	/*	
	int rlow = (int) floor( totEntR*(clockcntL/clockcntR - 0.2) );
	int rhigh = (int) floor( totEntR*(clockcntL/clockcntR + 0.2) );
	Double_t minvalue=fabs(clockcntR-clockcntL);
	
	for(int ii=rhigh; ii>rlow; ii--)
	{
		EVRIGHT->GetEntry(ii);	
//		cout << ii <<  " "  << clockcntL << ", "<< clkcR << " " << minvalue << endl;

		if(fabs(clkcR - clockcntL) < minvalue)
		{
			totEntR = ii;
			minvalue = fabs(clkcR - clockcntL);
		}		
	}	
	*/
	
//	cout << totEntL << " " << totEntR << endl;
		
	switch (CallType){
//////////////////////////////////////////////
//      Scalar Fast Clock Count Diff 1D
//////////////////////////////////////////////		
	case 11:
		cout<<GetDiffRate("t1c")<<endl;
		break;
	case 12:
		cout<<GetDiffRate("t3c")<<endl;
		break;
	case 14:
		cout<<GetHeliDiffRate("t3","p")<<endl;
		break;
	case 15:
		cout<<GetBCMDiffRate("1","c")<<endl;
		break;
	case 16:
		cout<<GetBCMLossRate("d3")<<endl;
		break;
	case 1://helicity diff + vs -
		Double_t rate[12][5]={0};	
		TString rowname[]={"l1a","t1","t3","t5","t6","fclk","u1","u3","u10","d1","d3","d10"};
		TString colname[]={"p","m"};
		TString collabel[]={"Spin = +1","Spin = -1"};
		TPaveText *t=new TPaveText(0.05,0.05,0.95,0.95);
		t->SetTextFont(82);

		t->AddText("Scalar Counts Difference Rate (Hel=+1 - Hel=-1)/Average");
		t->AddText("=======================================================");
		TString tmpline="";
		for (Int_t i=0;i<12;i++)
			for (Int_t j=0;j<2;j++)
			{
				rate[i][j]=GetHeliDiffRate(rowname[i],colname[j]);
				//cout<<rowname[i]+colname[j]<<" = "<<rate[i][j]<<endl;
			}

		tmpline="Chan";
		for (Int_t j=0;j<2;j++)
		{
			char buff[1000]="";
			sprintf(buff,"%10s",collabel[j].Data());
			tmpline+=buff;
		}
		t->AddText(tmpline);

		t->AddText("------------------------------------------------------");
		for (Int_t i=0;i<12;i++)
		{
			char buff[1000]="";
			sprintf(buff,"%4s",rowname[i].Data());
			tmpline=buff;
			for (Int_t j=0;j<2;j++)
			{
				char buff[1000]="";
				sprintf(buff,"%10.2g",rate[i][j]);
				tmpline+=buff;
			}
			t->AddText(tmpline);
			
		}
		
		t->AddText("======================================================");
		t->AddText("");
		t->Draw();
		break;
	case 2://bcm diff upstream vs down stream
		Double_t rate[12]={0};	
		TString rowname[]={"l1a","t1","t3","t5","t6","fclk","u1","u3","u10","d1","d3","d10"};
		TPaveText *t=new TPaveText(0.05,0.05,0.95,0.95);
		t->SetTextFont(82);

		t->AddText("Flip Loss (Ungated - Sum All Gated)/Ungated");
		t->AddText("Scalar Count Diff due to Hel. and Spin Flip");
		t->AddText("===========================================");
		TString tmpline="";
		for (Int_t i=0;i<12;i++)
			for (Int_t j=0;j<2;j++)
			{
				rate[i]=GetBCMLossRate(rowname[i]);
				//cout<<rowname[i]+colname[j]<<" = "<<rate[i][j]<<endl;
			}

		for (Int_t i=0;i<12;i++)
		{
			char buff[1000]="";
			sprintf(buff,"Loss Rate of %4s",rowname[i].Data());
			tmpline=buff;
			sprintf(buff," = %10.2g",rate[i]);
			tmpline+=buff;
			t->AddText(tmpline);
			
		}
		
		t->AddText("===========================================");
		t->AddText("");
		t->Draw();
		break;
	case 3://scalar diff left vs bbite
		Double_t rate[12][7]={0};	
		TString rowname[]={"clk","t1","t2","t3","t4","fclk","u1","u3","u10","d1","d3","d10"};
		TString colname[]={"c","pp","pm","mp","mm", "p", "m"};
		TString collabel[]={"ungated","s=+,h=+","s=+,h=-","s=-,h=+","s=-,h=-", "s=+", "s=-"};
		TPaveText *t=new TPaveText(0.05,0.05,0.95,0.95);
		t->SetTextFont(82);

		t->AddText("Scalar Counts Difference Rate (LHRS - RHRS)/Average");
		t->AddText("===========================================================================");
		TString tmpline="";
		for (Int_t i=0;i<12;i++)
		{	
			for (Int_t j=0;j<5;j++)
			{
				rate[i][j]=GetDiffRate(rowname[i]+colname[j], EVLEFT, EVRIGHT);
			//	rate[i][j]=GetDiffRate(rowname[i]+colname[j]);
				//cout<<rowname[i]+colname[j]<<" = "<<rate[i][j]<<endl;
			}
			
			for (Int_t jj=5;jj<7;jj++)
				rate[i][jj]=GetTgspinDiffRate(rowname[i], colname[jj], EVLEFT, EVRIGHT);
		}

		tmpline="Chan";
		for (Int_t j=0;j<7;j++)
		{
			char buff[1000]="";
			sprintf(buff,"%10s",collabel[j].Data());
			tmpline+=buff;
		}
		t->AddText(tmpline);

		t->AddText("---------------------------------------------------------------------------");
		for (Int_t i=0;i<12;i++)
		{
			char buff[1000]="";
			sprintf(buff,"%4s",rowname[i].Data());
			tmpline=buff;
			for (Int_t j=0;j<7;j++)
			{
				char buff[1000]="";
				sprintf(buff,"%10.2g",rate[i][j]);
				tmpline+=buff;
			}
			t->AddText(tmpline);
			
		}
		
		t->AddText("===========================================================================");
		t->AddText("");
		t->Draw();
		break;
		
	default :
		cout<<"ScalarStat : Unknown Call Type "<<CallType<<endl;
	}
	
	
	
}
