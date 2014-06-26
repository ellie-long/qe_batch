




void MyClass::hand_class_fill_bar_by_bar_cuts(int HeRunNumber, int nplane, int thisbar, bool pastThetaCut, bool madePastLVetoCuts, bool madePastRVetoCuts, bool madePastVetoCuts,TH1F* HANDleft, TH1F* HANDleftcut, TH1F* HANDright, TH1F* HANDrightcut, TH1F* HeThetaCut, TH1F* HePhiCut, TH2F* HeThetaPhiCut)
{


	cout << "vvvvvvvvvvvvvvvvv hand_class_fill_bar_by_bar_cuts.h vvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;


// vvvvvvvvvvvvvvvvvvvvvvvvvvvvv Defining goodTDC cut vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvv Defining goodTDC cut vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;
	bool goodLTDC = true;
	bool goodRTDC = true;
	if (nplane==0) 
	{
		goodLTDC = (NA_veto_lt_c[thisbar]>goodTDCleftcutmin) && (NA_veto_lt_c[thisbar]>goodTDCleftcutmax);
		goodRTDC = (NA_veto_rt_c[thisbar]>goodTDCrightcutmin) && (NA_veto_rt_c[thisbar]>goodTDCrightcutmax);
	}
	if (nplane==1) 
	{
		goodLTDC = (NA_nd_p1_lt_c[thisbar]>goodTDCleftcutmin) && (NA_nd_p1_lt_c[thisbar]>goodTDCleftcutmax);
		goodRTDC = (NA_nd_p1_rt_c[thisbar]>goodTDCrightcutmin) && (NA_nd_p1_rt_c[thisbar]>goodTDCrightcutmax);
	}
	if (nplane==2) 
	{
		goodLTDC = (NA_nd_p2_lt_c[thisbar]>goodTDCleftcutmin) && (NA_nd_p2_lt_c[thisbar]>goodTDCleftcutmax);
		goodRTDC = (NA_nd_p2_rt_c[thisbar]>goodTDCrightcutmin) && (NA_nd_p2_rt_c[thisbar]>goodTDCrightcutmax);
	}
	if (nplane==3) 
	{
		goodLTDC = (NA_nd_p3_lt_c[thisbar]>goodTDCleftcutmin) && (NA_nd_p3_lt_c[thisbar]>goodTDCleftcutmax);
		goodRTDC = (NA_nd_p3_rt_c[thisbar]>goodTDCrightcutmin) && (NA_nd_p3_rt_c[thisbar]>goodTDCrightcutmax);
	}
	if (nplane==4) 
	{
		goodLTDC = (NA_nd_p4_lt_c[thisbar]>goodTDCleftcutmin) && (NA_nd_p4_lt_c[thisbar]>goodTDCleftcutmax);
		goodRTDC = (NA_nd_p4_rt_c[thisbar]>goodTDCrightcutmin) && (NA_nd_p4_rt_c[thisbar]>goodTDCrightcutmax);
	}
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Defining goodTDC cut ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



// vvvvvvvvvvvvvvvvvv Fill Bar-by-Bar Cut Plots vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
// The chunk below will fill all of the Bar-by-Bar Cut Plots
cout << "Filling HANDleft/right..." << endl;
	if (nplane==0)
	{
		HANDleft[nplane][thisbar]->Fill(NA_veto_lt_c[thisbar]);
		if (madePastLVetoCuts && goodLTDC) {HANDleftcut[nplane][thisbar]->Fill(NA_veto_lt_c[thisbar]);}
		HANDright[nplane][thisbar]->Fill(NA_veto_rt_c[thisbar]);
		if (madePastRVetoCuts && goodRTDC) {HANDrightcut[nplane][thisbar]->Fill(NA_veto_rt_c[thisbar]);}
	}
	if (nplane==1)
	{
		HANDleft[nplane][thisbar]->Fill(NA_nd_p1_lt_c[thisbar]);
		if (madePastLVetoCuts && goodLTDC) {HANDleftcut[nplane][thisbar]->Fill(NA_nd_p1_lt_c[thisbar]);}
		HANDright[nplane][thisbar]->Fill(NA_nd_p1_rt_c[thisbar]);
		if (madePastRVetoCuts && goodRTDC) {HANDrightcut[nplane][thisbar]->Fill(NA_nd_p1_rt_c[thisbar]);}
	}
	if (nplane==2)
	{
		HANDleft[nplane][thisbar]->Fill(NA_nd_p2_lt_c[thisbar]);
		if (madePastLVetoCuts && goodLTDC) {HANDleftcut[nplane][thisbar]->Fill(NA_nd_p2_lt_c[thisbar]);}
		HANDright[nplane][thisbar]->Fill(NA_nd_p2_rt_c[thisbar]);
		if (madePastRVetoCuts && goodRTDC) {HANDrightcut[nplane][thisbar]->Fill(NA_nd_p2_rt_c[thisbar]);}
	}
	if (nplane==3)
	{
		HANDleft[nplane][thisbar]->Fill(NA_nd_p3_lt_c[thisbar]);
		if (madePastLVetoCuts && goodLTDC) {HANDleftcut[nplane][thisbar]->Fill(NA_nd_p3_lt_c[thisbar]);}
		HANDright[nplane][thisbar]->Fill(NA_nd_p3_rt_c[thisbar]);
		if (madePastRVetoCuts && goodRTDC) {HANDrightcut[nplane][thisbar]->Fill(NA_nd_p3_rt_c[thisbar]);}
	}
	if (nplane==4)
	{
		HANDleft[nplane][thisbar]->Fill(NA_nd_p4_lt_c[thisbar]);
		if (madePastLVetoCuts && goodLTDC) {HANDleftcut[nplane][thisbar]->Fill(NA_nd_p4_lt_c[thisbar]);}
		HANDright[nplane][thisbar]->Fill(NA_nd_p4_rt_c[thisbar]);
		if (madePastRVetoCuts && goodRTDC) {HANDrightcut[nplane][thisbar]->Fill(NA_nd_p4_rt_c[thisbar]);}
	}
cout << "Filling Theta/Phi..." << endl;
	if (pastThetaCut) {HeThetaCut[nplane][thisbar]->Fill(ExTgtCor_R_th);}
	HePhiCut[nplane][thisbar]->Fill(ExTgtCor_R_ph);
	if (pastThetaCut) {HeThetaPhiCut[nplane][thisbar]->Fill(ExTgtCor_R_ph,ExTgtCor_R_th);}
// ^^^^^^^^^^^^^^^^^^ Fill Bar-by-Bar Cut Plots ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


	cout << "^^^^^^^^^^^^^^^^^ hand_class_fill_bar_by_bar_cuts.h ^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}
