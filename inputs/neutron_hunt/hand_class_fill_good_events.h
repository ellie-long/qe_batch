



//void neutron_analysis_class::hand_class_fill_good_events(TH1F* ToFgoodEvent[], TH1F* ToFcut[], TH1F* ToFup[], TH1F* ToFdown[], TH1F* nuAllCuts[], TH1F* nuUp, TH1F* nuDown, int tofCutMin, int tofCutMax, double numin, double numax, int nuBins, TString asymType)
void neutron_analysis_class::hand_class_fill_good_events(TH1F* ToFgoodEvent, TH1F* ToFcut, TH1F* ToFup, TH1F* ToFdown, TH1F* nuAllCuts, TH1F* nuUp, TH1F* nuDown, int tofCutMin, int tofCutMax, double numin, double numax, int nuBins, TString asymType, int iterator, TH1F* nuUpAllCuts, TH1F* nuDownAllCuts)
{
//	cout << "vvvvvvvvvvvvvvvvvvv hand_class_fill_good_events.h vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
//	cout << "asymType: " << asymType << endl;

	bool goodToFcut = true;
//	bool spinUp = true;
	bool spinUp = false;
	bool spinUp1 = true;
//	bool spinDown = true;
	bool spinDown = false;
	bool spinDown1 = true;
	bool nuBinCut = true;
	double nuBinCutMin;
	double nuBinCutMax;
	double nuBinSize;

//	nuBinSize = (numax - numin)/nuBins;
	nuBinSize = (numax - numin)/10;
	goodToFcut = ((NA_n_tof[0]>tofCutMin) && (NA_n_tof[0]<tofCutMax));
	if (asymType == "dsa")
	{
//		spinUp1 = ((g0hel_R_helicity==-1 && g_runnum>20403 && g_runnum<20684) || (g0hel_R_helicity==-1 && g_runnum>20728 && g_runnum<20829) || (g0hel_R_helicity==-1 && g_runnum>21178 && g_runnum<21326) || (g0hel_R_helicity==-1 && g_runnum>21540 && g_runnum<21724) || (g0hel_R_helicity==-1 && g_runnum>21782 && g_runnum<21851) || (g0hel_R_helicity==-1 && g_runnum>21881 && g_runnum<21894) || (g0hel_R_helicity==-1 && g_runnum>21910 && g_runnum<22054) || (g0hel_R_helicity==-1 && g_runnum>22195 && g_runnum<22309)  || (g0hel_R_helicity==-1 && g_runnum>22323 && g_runnum<22441) || (g0hel_R_helicity==-1 && g_runnum>22468 && g_runnum<22490));
//		spinUp = (spinUp1 || (g0hel_R_helicity==1 && g_runnum>20683 && g_runnum<20728) ||  (g0hel_R_helicity==1 && g_runnum>20829 && g_runnum<21179) || (g0hel_R_helicity==1 && g_runnum>21325 && g_runnum<21541) || (g0hel_R_helicity==1 && g_runnum>21718 && g_runnum<21783) || (g0hel_R_helicity==1 && g_runnum>21847 && g_runnum<21882) || (g0hel_R_helicity==1 && g_runnum>21893 && g_runnum<21911) || (g0hel_R_helicity==1 && g_runnum>22052 && g_runnum<22196) || (g0hel_R_helicity==1 && g_runnum>22308 && g_runnum<22324) || (g0hel_R_helicity==1 && g_runnum>22440 && g_runnum<22467));
//		spinUp = ((g0hel_R_helicity==-1 && g_runnum>20403 && g_runnum<20684) || (g0hel_R_helicity==-1 && g_runnum>20728 && g_runnum<20829) || (g0hel_R_helicity==-1 && g_runnum>21178 && g_runnum<21326) || (g0hel_R_helicity==-1 && g_runnum>21540 && g_runnum<21724) || (g0hel_R_helicity==-1 && g_runnum>21782 && g_runnum<21851) || (g0hel_R_helicity==-1 && g_runnum>21881 && g_runnum<21894) || (g0hel_R_helicity==-1 && g_runnum>21910 && g_runnum<22054) || (g0hel_R_helicity==-1 && g_runnum>22195 && g_runnum<22309)  || (g0hel_R_helicity==-1 && g_runnum>22323 && g_runnum<22441) || (g0hel_R_helicity==-1 && g_runnum>22468 && g_runnum<22490));
//		spinUp = (spinUp || (g0hel_R_helicity==1 && g_runnum>20683 && g_runnum<20728) ||  (g0hel_R_helicity==1 && g_runnum>20829 && g_runnum<21179) || (g0hel_R_helicity==1 && g_runnum>21325 && g_runnum<21541) || (g0hel_R_helicity==1 && g_runnum>21718 && g_runnum<21783) || (g0hel_R_helicity==1 && g_runnum>21847 && g_runnum<21882) || (g0hel_R_helicity==1 && g_runnum>21893 && g_runnum<21911) || (g0hel_R_helicity==1 && g_runnum>22052 && g_runnum<22196) || (g0hel_R_helicity==1 && g_runnum>22308 && g_runnum<22324) || (g0hel_R_helicity==1 && g_runnum>22440 && g_runnum<22467));

//		spinUp = ((g0hel_R_helicity==-1 && g_runnum>20403 && g_runnum<20684) || (g0hel_R_helicity==1 && g_runnum>20683 && g_runnum<20728) || (g0hel_R_helicity==-1 && g_runnum>20728 && g_runnum<20829) || (g0hel_R_helicity==1 && g_runnum>20829 && g_runnum<21179) || (g0hel_R_helicity==-1 && g_runnum>21178 && g_runnum<21326) || (g0hel_R_helicity==1 && g_runnum>21325 && g_runnum<21541) || (g0hel_R_helicity==-1 && g_runnum>21540 && g_runnum<21724) || (g0hel_R_helicity==1 && g_runnum>21718 && g_runnum<21783) || (g0hel_R_helicity==-1 && g_runnum>21782 && g_runnum<21851) || (g0hel_R_helicity==1 && g_runnum>21847 && g_runnum<21882) || (g0hel_R_helicity==-1 && g_runnum>21881 && g_runnum<21894) || (g0hel_R_helicity==1 && g_runnum>21893 && g_runnum<21911) || (g0hel_R_helicity==-1 && g_runnum>21910 && g_runnum<22054) || (g0hel_R_helicity==1 && g_runnum>22052 && g_runnum<22196) || (g0hel_R_helicity==-1 && g_runnum>22195 && g_runnum<22309) || (g0hel_R_helicity==1 && g_runnum>22308 && g_runnum<22324) || (g0hel_R_helicity==-1 && g_runnum>22323 && g_runnum<22441) || (g0hel_R_helicity==1 && g_runnum>22440 && g_runnum<22467) || (g0hel_R_helicity==-1 && g_runnum>22468 && g_runnum<22490));



		spinUp = ((g0hel_R_helicity==-1 && ((g_runnum>20403 && g_runnum<20684) || (g_runnum>20728 && g_runnum<20829) || (g_runnum>21178 && g_runnum<21326) || (g_runnum>21540 && g_runnum<21724) || (g_runnum>21782 && g_runnum<21851) || (g_runnum>21881 && g_runnum<21894) || (g_runnum>21910 && g_runnum<22054) || (g_runnum>22195 && g_runnum<22309) || (g_runnum>22323 && g_runnum<22441) || (g_runnum>22468 && g_runnum<22490))) || (g0hel_R_helicity==1 && ((g_runnum>20683 && g_runnum<20728) || (g_runnum>20829 && g_runnum<21179) || (g_runnum>21325 && g_runnum<21541) || (g_runnum>21718 && g_runnum<21783) || (g_runnum>21847 && g_runnum<21882) || (g_runnum>21893 && g_runnum<21911) || (g_runnum>22052 && g_runnum<22196) || (g_runnum>22308 && g_runnum<22324) || (g_runnum>22440 && g_runnum<22467))));

//		spinUp = (g0hel_R_helicity==1);




//		spinDown1 = ((g0hel_R_helicity==1 && g_runnum>20403 && g_runnum<20684) || (g0hel_R_helicity==1 && g_runnum>20728 && g_runnum<20829) || (g0hel_R_helicity==1 && g_runnum>21178 && g_runnum<21326) || (g0hel_R_helicity==1 && g_runnum>21540 && g_runnum<21724) || (g0hel_R_helicity==1 && g_runnum>21782 && g_runnum<21851) || (g0hel_R_helicity==1 && g_runnum>21881 && g_runnum<21894) || (g0hel_R_helicity==1 && g_runnum>21910 && g_runnum<22054) || (g0hel_R_helicity==1 && g_runnum>22195 && g_runnum<22309) || (g0hel_R_helicity==1 && g_runnum>22323 && g_runnum<22441) || (g0hel_R_helicity==1 && g_runnum>22468 && g_runnum<22490));
//		spinDown = (spinDown1 || (g0hel_R_helicity==-1 && g_runnum>20683 && g_runnum<20728) || (g0hel_R_helicity==-1 && g_runnum>20829 && g_runnum<21179) || (g0hel_R_helicity==-1 && g_runnum>21325 && g_runnum<21541) || (g0hel_R_helicity==-1 && g_runnum>21718 && g_runnum<21783) || (g0hel_R_helicity==-1 && g_runnum>21847 && g_runnum<21882) || (g0hel_R_helicity==-1 && g_runnum>21893 && g_runnum<21911) || (g0hel_R_helicity==-1 && g_runnum>22052 && g_runnum<22196) || (g0hel_R_helicity==-1 && g_runnum>22308 && g_runnum<22324) || (g0hel_R_helicity==-1 && g_runnum>22440 && g_runnum<22467));
//		spinDown = ((g0hel_R_helicity==1 && g_runnum>20403 && g_runnum<20684) || (g0hel_R_helicity==1 && g_runnum>20728 && g_runnum<20829) || (g0hel_R_helicity==1 && g_runnum>21178 && g_runnum<21326) || (g0hel_R_helicity==1 && g_runnum>21540 && g_runnum<21724) || (g0hel_R_helicity==1 && g_runnum>21782 && g_runnum<21851) || (g0hel_R_helicity==1 && g_runnum>21881 && g_runnum<21894) || (g0hel_R_helicity==1 && g_runnum>21910 && g_runnum<22054) || (g0hel_R_helicity==1 && g_runnum>22195 && g_runnum<22309) || (g0hel_R_helicity==1 && g_runnum>22323 && g_runnum<22441) || (g0hel_R_helicity==1 && g_runnum>22468 && g_runnum<22490));
//		spinDown = (spinDown || (g0hel_R_helicity==-1 && g_runnum>20683 && g_runnum<20728) || (g0hel_R_helicity==-1 && g_runnum>20829 && g_runnum<21179) || (g0hel_R_helicity==-1 && g_runnum>21325 && g_runnum<21541) || (g0hel_R_helicity==-1 && g_runnum>21718 && g_runnum<21783) || (g0hel_R_helicity==-1 && g_runnum>21847 && g_runnum<21882) || (g0hel_R_helicity==-1 && g_runnum>21893 && g_runnum<21911) || (g0hel_R_helicity==-1 && g_runnum>22052 && g_runnum<22196) || (g0hel_R_helicity==-1 && g_runnum>22308 && g_runnum<22324) || (g0hel_R_helicity==-1 && g_runnum>22440 && g_runnum<22467));

//		spinDown = ((g0hel_R_helicity==1 && g_runnum>20403 && g_runnum<20684) || (g0hel_R_helicity==-1 && g_runnum>20683 && g_runnum<20728) || (g0hel_R_helicity==1 && g_runnum>20728 && g_runnum<20829) || (g0hel_R_helicity==-1 && g_runnum>20829 && g_runnum<21179) || (g0hel_R_helicity==1 && g_runnum>21178 && g_runnum<21326) || (g0hel_R_helicity==-1 && g_runnum>21325 && g_runnum<21541) || (g0hel_R_helicity==1 && g_runnum>21540 && g_runnum<21724) || (g0hel_R_helicity==-1 && g_runnum>21718 && g_runnum<21783) || (g0hel_R_helicity==1 && g_runnum>21782 && g_runnum<21851) || (g0hel_R_helicity==-1 && g_runnum>21847 && g_runnum<21882) || (g0hel_R_helicity==1 && g_runnum>21881 && g_runnum<21894) || (g0hel_R_helicity==-1 && g_runnum>21893 && g_runnum<21911) || (g0hel_R_helicity==1 && g_runnum>21910 && g_runnum<22054) || (g0hel_R_helicity==-1 && g_runnum>22052 && g_runnum<22196) || (g0hel_R_helicity==1 && g_runnum>22195 && g_runnum<22309) || (g0hel_R_helicity==-1 && g_runnum>22308 && g_runnum<22324) || (g0hel_R_helicity==1 && g_runnum>22323 && g_runnum<22441) || (g0hel_R_helicity==-1 && g_runnum>22440 && g_runnum<22467) || (g0hel_R_helicity==1 && g_runnum>22468 && g_runnum<22490));


		spinDown = ((g0hel_R_helicity==1 && ((g_runnum>20403 && g_runnum<20684) || (g_runnum>20728 && g_runnum<20829) || (g_runnum>21178 && g_runnum<21326) || (g_runnum>21540 && g_runnum<21724) || (g_runnum>21782 && g_runnum<21851) || (g_runnum>21881 && g_runnum<21894) || (g_runnum>21910 && g_runnum<22054) || (g_runnum>22195 && g_runnum<22309) || (g_runnum>22323 && g_runnum<22441) || (g_runnum>22468 && g_runnum<22490))) || (g0hel_R_helicity==-1 && ((g_runnum>20683 && g_runnum<20728) || (g_runnum>20829 && g_runnum<21179) || (g_runnum>21325 && g_runnum<21541) || (g_runnum>21718 && g_runnum<21783) || (g_runnum>21847 && g_runnum<21882) || (g_runnum>21893 && g_runnum<21911) || (g_runnum>22052 && g_runnum<22196) || (g_runnum>22308 && g_runnum<22324) || (g_runnum>22440 && g_runnum<22467))));

//		spinDown = (g0hel_R_helicity==-1);

		if (he3R_Spin==1 && he3R_IsSpinValid==1)
		{
			spinUp1 = spinUp;
			spinDown1 = spinDown;
		}
		if (he3R_Spin==-1 && he3R_IsSpinValid==1)
		{
			spinUp1 = !spinUp;
			spinDown1 = !spinDown;
		}
		if (he3R_Spin==0)
		{
			spinUp1 = false;
			spinDown1 = false;
		}

		spinUp = spinUp1;
		spinDown = spinDown1;
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
			nuUpAllCuts->Fill(PriKineR_nu);
		}
		if (spinDown) 
		{
//			ToFdown[0]->Fill(NA_n_tof[0]);
			ToFdown->Fill(NA_n_tof[0]);
			nuDown->Fill(PriKineR_nu);
			nuDownAllCuts->Fill(PriKineR_nu);
		}
	}
	if (iterator>0)
	{
		int i = iterator;
		nuBinCutMin = i*nuBinSize - nuBinSize + numin;
		nuBinCutMax = i*nuBinSize + numin;

		// ********* The bit below sets the nu bins to be the same as Yawei's cuts *********************
		if (asymType=="ssa")
		{

         // Q^2=0.1 GeV^2
			if (i==1 && g_runnum<20541)
			{
				nuBinCutMin = 0;
				nuBinCutMax = 0.035;
			}
			if (i==2 && g_runnum<20541)
			{
				nuBinCutMin = 0.035;
				nuBinCutMax = 0.065;
			}
			if (i==3 && g_runnum<20541)
			{
				nuBinCutMin = 0.065;
				nuBinCutMax = 0.095;
			}
			if (i==4 && g_runnum<20541)
			{
				nuBinCutMin = 0.095;
				nuBinCutMax = 0.125;
			}

			// Q^2=0.5 GeV^2
			if (i==1 && g_runnum>20881 && g_runnum<21010)
			{
				nuBinCutMin = 0.12;
				nuBinCutMax = 0.18;
			}
			if (i==2 && g_runnum>20881 && g_runnum<21010)
			{
				nuBinCutMin = 0.18;
				nuBinCutMax = 0.24;
			}
			if (i==3 && g_runnum>20881 && g_runnum<21010)
			{
				nuBinCutMin = 0.24;
				nuBinCutMax = 0.30;
			}
			if (i==4 && g_runnum>20881 && g_runnum<21010)
			{
				nuBinCutMin = 0.30;
				nuBinCutMax = 0.36;
			}

			// Q^2=1.0 GeV^2
			if (i==1 && g_runnum>20541 && g_runnum<20880)
			{
				nuBinCutMin = 0.36;
				nuBinCutMax = 0.44;
			}
			if (i==2 && g_runnum>20541 && g_runnum<20880)
			{
				nuBinCutMin = 0.44;
				nuBinCutMax = 0.52;
			}
			if (i==3 && g_runnum>20541 && g_runnum<20880)
			{
				nuBinCutMin = 0.52;
				nuBinCutMax = 0.60;
			}
			if (i==4 && g_runnum>20541 && g_runnum<20880)
			{
				nuBinCutMin = 0.60;
				nuBinCutMax = 0.68;
			}

		}

		if (asymType=="dsa")
		{
			// Q^2=0.4 GeV^2
			if (i==1 && g_runnum>21690 && g_runnum<22313)
			{
				nuBinCutMin = 0.12;
				nuBinCutMax = 0.18;
			}
			if (i==2 && g_runnum>21690 && g_runnum<22313)
			{
				nuBinCutMin = 0.18;
				nuBinCutMax = 0.24;
			}
			if (i==3 && g_runnum>21690 && g_runnum<22313)
			{
				nuBinCutMin = 0.24;
				nuBinCutMax = 0.30;
			}
			if (i==4 && g_runnum>21690 && g_runnum<22313)
			{
				nuBinCutMin = 0.30;
				nuBinCutMax = 0.36;
			}

			// Q^2=1.0 GeV^2
			if (i==1 && g_runnum>22390 && g_runnum<22490)
			{
				nuBinCutMin = 0.36;
				nuBinCutMax = 0.44;
			}
			if (i==2 && g_runnum>22390 && g_runnum<22490)
			{
				nuBinCutMin = 0.44;
				nuBinCutMax = 0.52;
			}
			if (i==3 && g_runnum>22390 && g_runnum<22490)
			{
				nuBinCutMin = 0.52;
				nuBinCutMax = 0.60;
			}
			if (i==4 && g_runnum>22390 && g_runnum<22490)
			{
				nuBinCutMin = 0.60;
				nuBinCutMax = 0.68;
			}

		}

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
				nuUpAllCuts->Fill(PriKineR_nu);
			}
			if (spinDown) 
			{
//				ToFdown[i]->Fill(NA_n_tof[0]);
				ToFdown->Fill(NA_n_tof[0]);
				nuDownAllCuts->Fill(PriKineR_nu);
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
