/////////////////////////////////////////////////////////
//
//  chainruns.cc
//  This script will chain together runs entered into it
//  and make cuts on it as defined immediately under the
//  declaration of the script.
//
//  Elena Long (ellie@jlab.org)
//  05/28/09
//
/////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>


void chainruns()
{
  TCut rhrs = "";
  TCut cut1 = "";
  TCut cut2 = "";
  TString vartodraw = "PriKineR.Q2";
  TString rangetodraw = "";
  TString type = "";

  ifstream inp;
  ofstream out;

  int runnumber;
  TString filename;
  TChain* chain = new TChain("T");
  TString whattodraw;
  TString yesno = "y";

  while (yesno == "y")
  {
    cout << "What Run # would you like to chain together?" << endl;
    cin >> runnumber;

    for (int t=0; t<100; t++)
    {
      filename = "./ROOTfiles/e05102_R_";
      filename += runnumber;
      if (t!=0)
      {
        filename += "_";
        filename += t;
      }
      filename += ".root";

      inp.open(filename);
      inp.close();
      if (inp.fail())
      {
        t = 100;
        cout << filename << " does not exist. Ending search." << endl;
      }
      else
      {
        cout << "Adding file to chain: " << filename << endl;
        chain->Add(filename);
      }
    }
    cout << "Would you like to chain this run to another? (y/n)" << endl;
    cin >> yesno;
  }


  whattodraw = vartodraw;
  whattodraw += ">>Run # ";
  whattodraw += runnumber;
  whattodraw += rangetodraw;

  cout << "Drawing histogram of " << whattodraw << endl;
  chain->Draw(whattodraw,rhrs && cut1 && cut2,type);
  cout << "Histogram drawn." << endl;

}
