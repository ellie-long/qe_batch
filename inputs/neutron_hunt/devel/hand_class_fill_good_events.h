



//void neutron_analysis_class::hand_class_fill_good_events(TH1F* ToFgoodEvent[], TH1F* ToFcut[], TH1F* ToFup[], TH1F* ToFdown[], TH1F* nuAllCuts[], TH1F* nuUp, TH1F* nuDown, int tofCutMin, int tofCutMax, double numin, double numax, int nuBins, TString asymType)
void neutron_analysis_class::hand_class_fill_good_events(TH1F* ToFgoodEvent, TH1F* ToFcut, TH1F* ToFup, TH1F* ToFdown, TH1F* nuAllCuts, TH1F* nuUp, TH1F* nuDown, int tofCutMin, int tofCutMax, double numin, double numax, int nuBins, TString asymType, int iterator)
{
//	cout << "vvvvvvvvvvvvvvvvvvv hand_class_fill_good_events.h vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
//	cout << "asymType: " << asymType << endl;

	bool goodToFcut = true;
	bool spinUp = true;
	bool spinDown = true;
	bool nuBinCut = true;
	double nuBinCutMin;
	double nuBinCutMax;
	double nuBinSize;

	nuBinSize = (numax - numin)/nuBins;
	goodToFcut = ((NA_n_tof[0]>tofCutMin) && (NA_n_tof[0]<tofCutMax));
	if (asymType == "dsa")
	{
		spinUp = ((g0hel_R_helicity==-1 && g_runnum>20403 && g_runnum<20684) || (g0hel_R_helicity==-1 && g_runnum>20728 && g_runnum<20829) || (g0hel_R_helicity==-1 && g_runnum>21178 && g_runnum<21326) || (g0hel_R_helicity==-1 && g_runnum>21540 && g_runnum<21724) || (g0hel_R_helicity==-1 && g_runnum>21782 && g_runnum<21851) || (g0hel_R_helicity==-1 && g_runnum>21881 && g_runnum<21894) || (g0hel_R_helicity==-1 && g_runnum>21910 && g_runnum<22054) || (g0hel_R_helicity==-1 && g_runnum>22195 && g_runnum<22309)  || (g0hel_R_helicity==-1 && g_runnum>22323 && g_runnum<22441) || (g0hel_R_helicity==-1 && g_runnum>22468 && g_runnum<22490));
		spinUp = (spinUp || (g0hel_R_helicity==1 && g_runnum>20683 && g_runnum<20728) ||  (g0hel_R_helicity==1 && g_runnum>20829 && g_runnum<21179) || (g0hel_R_helicity==1 && g_runnum>21325 && g_runnum<21541) || (g0hel_R_helicity==1 && g_runnum>21718 && g_runnum<21783) || (g0hel_R_helicity==1 && g_runnum>21847 && g_runnum<21882) || (g0hel_R_helicity==1 && g_runnum>21893 && g_runnum<21911) || (g0hel_R_helicity==1 && g_runnum>22052 && g_runnum<22196) || (g0hel_R_helicity==1 && g_runnum>22308 && g_runnum<22324) || (g0hel_R_helicity==1 && g_runnum>22440 && g_runnum<22467));
//		spinUp = ((g0hel_R_helicity==-1 && g_runnum>20403 && g_runnum<20684) || (g0hel_R_helicity==1 && g_runnum>20683 && g_runnum<20728) || (g0hel_R_helicity==-1 && g_runnum>20728 && g_runnum<20829) || (g0hel_R_helicity==1 && g_runnum>20829 && g_runnum<21179) || (g0hel_R_helicity==-1 && g_runnum>21178 && g_runnum<21326) || (g0hel_R_helicity==1 && g_runnum>21325 && g_runnum<21541) || (g0hel_R_helicity==-1 && g_runnum>21540 && g_runnum<21724) || (g0hel_R_helicity==1 && g_runnum>21718 && g_runnum<21783) || (g0hel_R_helicity==-1 && g_runnum>21782 && g_runnum<21851) || (g0hel_R_helicity==1 && g_runnum>21847 && g_runnum<21882) || (g0hel_R_helicity==-1 && g_runnum>21881 && g_runnum<21894) || (g0hel_R_helicity==1 && g_runnum>21893 && g_runnum<21911) || (g0hel_R_helicity==-1 && g_runnum>21910 && g_runnum<22054) || (g0hel_R_helicity==1 && g_runnum>22052 && g_runnum<22196) || (g0hel_R_helicity==-1 && g_runnum>22195 && g_runnum<22309) || (g0hel_R_helicity==1 && g_runnum>22308 && g_runnum<22324) || (g0hel_R_helicity==-1 && g_runnum>22323 && g_runnum<22441) || (g0hel_R_helicity==1 && g_runnum>22440 && g_runnum<22467) || (g0hel_R_helicity==-1 && g_runnum>22468 && g_runnum<22490));


		spinDown = ((g0hel_R_helicity==1 && g_runnum>20403 && g_runnum<20684) || (g0hel_R_helicity==1 && g_runnum>20728 && g_runnum<20829) || (g0hel_R_helicity==1 && g_runnum>21178 && g_runnum<21326) || (g0hel_R_helicity==1 && g_runnum>21540 && g_runnum<21724) || (g0hel_R_helicity==1 && g_runnum>21782 && g_runnum<21851) || (g0hel_R_helicity==1 && g_runnum>21881 && g_runnum<21894) || (g0hel_R_helicity==1 && g_runnum>21910 && g_runnum<22054) || (g0hel_R_helicity==1 && g_runnum>22195 && g_runnum<22309) || (g0hel_R_helicity==1 && g_runnum>22323 && g_runnum<22441) || (g0hel_R_helicity==1 && g_runnum>22468 && g_runnum<22490));
		spinDown = (spinDown || (g0hel_R_helicity==-1 && g_runnum>20683 && g_runnum<20728) || (g0hel_R_helicity==-1 && g_runnum>20829 && g_runnum<21179) || (g0hel_R_helicity==-1 && g_runnum>21325 && g_runnum<21541) || (g0hel_R_helicity==-1 && g_runnum>21718 && g_runnum<21783) || (g0hel_R_helicity==-1 && g_runnum>21847 && g_runnum<21882) || (g0hel_R_helicity==-1 && g_runnum>21893 && g_runnum<21911) || (g0hel_R_helicity==-1 && g_runnum>22052 && g_runnum<22196) || (g0hel_R_helicity==-1 && g_runnum>22308 && g_runnum<22324) || (g0hel_R_helicity==-1 && g_runnum>22440 && g_runnum<22467));
//		spinDown = ((g0hel_R_helicity==1 && g_runnum>20403 && g_runnum<20684) || (g0hel_R_helicity==-1 && g_runnum>20683 && g_runnum<20728) || (g0hel_R_helicity==1 && g_runnum>20728 && g_runnum<20829) || (g0hel_R_helicity==-1 && g_runnum>20829 && g_runnum<21179) || (g0hel_R_helicity==1 && g_runnum>21178 && g_runnum<21326) || (g0hel_R_helicity==-1 && g_runnum>21325 && g_runnum<21541) || (g0hel_R_helicity==1 && g_runnum>21540 && g_runnum<21724) || (g0hel_R_helicity==-1 && g_runnum>21718 && g_runnum<21783) || (g0hel_R_helicity==1 && g_runnum>21782 && g_runnum<21851) || (g0hel_R_helicity==-1 && g_runnum>21847 && g_runnum<21882) || (g0hel_R_helicity==1 && g_runnum>21881 && g_runnum<21894) || (g0hel_R_helicity==-1 && g_runnum>21893 && g_runnum<21911) || (g0hel_R_helicity==1 && g_runnum>21910 && g_runnum<22054) || (g0hel_R_helicity==-1 && g_runnum>22052 && g_runnum<22196) || (g0hel_R_helicity==1 && g_runnum>22195 && g_runnum<22309) || (g0hel_R_helicity==-1 && g_runnum>22308 && g_runnum<22324) || (g0hel_R_helicity==1 && g_runnum>22323 && g_runnum<22441) || (g0hel_R_helicity==-1 && g_runnum>22440 && g_runnum<22467) || (g0hel_R_helicity==1 && g_runnum>22468 && g_runnum<22490));
	}

	if (asymType == "ssa")
	{
		spinUp = ((he3R_Spin==1) && (he3R_IsSpinValid==1));
		spinDown = ((he3R_Spin==-1) && (he3R_IsSpinValid==1));
	}
	if (iterator==0) 
	{
//		ToFgoodEvent[0]->Fill(NA_n_tof[0]);
		ToFgoodEvent->Fill(NA_n_tof[0]);
//		nuAllCuts[0]->Fill(PriKineR_nu);
		nuAllCuts->Fill(PriKineR_nu);
		
		if (spinUp) 
		{
//			ToFup[0]->Fill(NA_n_tof[0]);
			ToFup->Fill(NA_n_tof[0]);
			nuUp->Fill(PriKineR_nu);
		}
		if (spinDown) 
		{
//			ToFdown[0]->Fill(NA_n_tof[0]);
			ToFdown->Fill(NA_n_tof[0]);
			nuDown->Fill(PriKineR_nu);
		}
	}
	if (iterator>0)
	{
		int i = iterator;
		nuBinCutMin = i*nuBinSize - nuBinSize + numin;
		nuBinCutMax = i*nuBinSize + numin;
//		cout << "nuBinSize: " << nuBinSize << ", nuBinCutMin: " << nuBinCutMin << ", nuBinCutMax: " << nuBinCutMax << ", nuBins: " << nuBins << ", numin: " << numin << ", numax: " << numax << endl;
		nuBinCut = ((PriKineR_nu>nuBinCutMin) && (PriKineR_nu<nuBinCutMax));
		if (nuBinCut)
		{
//			ToFgoodEvent[i]->Fill(NA_n_tof[0]);
			ToFgoodEvent->Fill(NA_n_tof[0]);
//			nuAllCuts[i]->Fill(PriKineR_nu);
			nuAllCuts->Fill(PriKineR_nu);
			if (spinUp)
 			{
//				ToFup[i]->Fill(NA_n_tof[0]);
				ToFup->Fill(NA_n_tof[0]);
			}
			if (spinDown) 
			{
//				ToFdown[i]->Fill(NA_n_tof[0]);
				ToFdown->Fill(NA_n_tof[0]);
			}
		}
	}



/*

	if (goodToFcut) 
	{
		ToFcut->Fill(NA_n_tof[0]);
		nuAllCuts->Fill(PriKineR_nu);
		if (spinUp) { nuUpAllCuts->Fill(PriKineR_nu);}
		if (spinDown) { nuDownAllCuts->Fill(PriKineR_nu);}
	}
*/
//	cout << "^^^^^^^^^^^^^^^^^^^ hand_class_fill_good_events.h ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}
