#define EventTree_cxx
#include "EventTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TLorentzVector.h>

void EventTree::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L EventTree.C
//      Root > EventTree t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   

    TH1F *histoGenPtQuark = new TH1F("histoGenPtQuark","histoGenPtQuark",200,0.,500.);
    TH1F *histoGenPtGluon = new TH1F("histoGenPtGluon","histoGenPtGluon",200,0.,500.);
    TH1F *histoGenPtPhoton = new TH1F("histoGenPtPhoton","histoGenPtPhoton",150,0.,500.);
    TH1F *histoGenEtaQuark = new TH1F("histoGenEtaQuark","histoGenEtaQuark",20,-5.,5.);
    TH1F *histoGenEtaGluon = new TH1F("histoGenEtaGluon","histoGenEtaGluon",20,-5.,5.);
    TH1F *histoGenEtaPhoton = new TH1F("histoGenEtaPhoton","histoGenEtaPhoton",20,-5.,5.);
    TH1F *histoGenPhiQuark = new TH1F("histoGenPhiQuark","histoGenPhiQuark",20,-3.1,3.1);
    TH1F *histoGenPhiGluon = new TH1F("histoGenPhiGluon","histoGenPhiGluon",20,-3.1,3.1);
    TH1F *histoGenPhiPhoton = new TH1F("histoGenPhiPhoton","histoGenPhiPhoton",20,-3.1,3.1);

    TH1F *histoRecoPtPhoton = new TH1F("histoRecoPtPhoton","histoRecoPtPhoton",150,0.,500.);
    TH1F *histoRecoIsoPtPhoton = new TH1F("histoRecoIsoPtPhoton","histoRecoIsoPtPhoton",150,0.,500.);
    TH1F *histoRecoPhiPhoton = new TH1F("histoRecoPhiPhoton","histoRecoPhiPhoton",20,-3.1,3.1);
    TH1F *histoGenPtPhotonfromX = new TH1F("histoGenPtPhotonfromX","histoGenPtPhotonfromX",150,0.,500.);

    
//    TH1F *histoRecoPtQuark = new TH1F("histoRecoPtQuark","histoRecoPtQuark",200,0.,1000.);
//    TH1F *histoRecoPtGluon = new TH1F("histoRecoPtGluon","histoRecoPtGluon",200,0.,500.);
//   TH1F *histoRecoEtaQuark = new TH1F("histoRecoEtaQuark","histoRecoEtaQuark",20,-5.,5.);
//   TH1F *histoRecoEtaGluon = new TH1F("histoRecoEtaGluon","histoRecoEtaGluon",20,-5.,5.);
//   TH1F *histoRecoEtaPhoton = new TH1F("histoRecoEtaPhoton","histoRecoEtaPhoton",20,-5.,5.);
//   TH1F *histoRecoPhiQuark = new TH1F("histoRecoPhiQuark","histoRecoPhiQuark",20,-3.1,3.1);
//   TH1F *histoRecoPhiGluon = new TH1F("histoRecoPhiGluon","histoRecoPhiGluon",20,-3.1,3.1);
//
    
    TH1F *histoPtMatchPhoton = new TH1F("histoPtMatchPhoton","histoPtMatchPhoton",150,0.,500.);
    TH1F *histoDeltaEta = new TH1F("histoDeltaEta","histoDeltaEta",500,-6.,6.);
    TH1F *histoDeltaPhi = new TH1F("histoDeltaPhi","histoDeltaPhi",600,-7.,7.);
    TH1F *histoNumMatch = new TH1F("histoNumMatch","histoNumMatch",5,0.,5.);

      //gStyle->SetOptStat(0);


        Float_t DEta;
        Float_t DPhi;
	
	
	
	//JETS
	TH1F *nJet = new TH1F("nJet","nJet",12,0.,12.);
	TH1F *nJetEtCut = new TH1F("nJetEtCut","nJetEtCut",12,0.,12.);
	TH1F *nJetEtPmassCut = new TH1F("nJetEtPmassCut","nJetEtPmassCut",12,0.,12.);
	TH1F *JetPmass = new TH1F("JetPmass","JetPmass",200,0.,600.);
	TH1F *JetPmassACut = new TH1F("JetPmassACut","JetPmassACut",200,0.,600.);

//loop over all the events
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
       if (Cut(ientry) < 0) continue;
      
		//loop over all the GEN particles      
	      for (Int_t i = 0;i < nMC; i++){
	      	
	 		//recognize QUARKS
		      if(mcPID.at(i) < 9 && mcPID.at(i) > 0) {
			    histoGenEtaQuark->Fill(mcEta.at(i));		    
			    histoGenPhiQuark->Fill(mcPhi.at(i));		    
			    histoGenPtQuark->Fill(mcPt.at(i));
		      }
       	       		//recognize GLUONS
		      else if (mcPID.at(i) == 21) {
			    histoGenEtaGluon->Fill(mcEta.at(i));		    
			    histoGenPhiGluon->Fill(mcPhi.at(i));		    
			    histoGenPtGluon->Fill(mcPt.at(i));
		      } 
       	       //recognize PHOTONS
	       else if (mcPID.at(i) == 22) {
			    histoGenEtaPhoton->Fill(mcEta.at(i));		    
			    histoGenPhiPhoton->Fill(mcPhi.at(i));		    
			    histoGenPtPhoton->Fill(mcPt.at(i));
			    if (mcMomPID.at(i)>=1000022 && mcMomPID.at(i)<=1000035) histoGenPtPhotonfromX->Fill(mcPt.at(i));
				} 
		}              
	      
	      
	      
	      Int_t nMatch = 0;
	        
                //loop over all the RECO photons in the event
              for (Int_t j = 0;j < nPho; j++){
	      
	      	histoRecoPtPhoton->Fill(phoEt.at(j));         
		//isolation conditions
		if (phoPFChIso.at(j)<1.5 && phoPFNeuIso.at(j)<(1.0+(0.4*phoEt.at(j))) && phoPFPhoIso.at(j)<(0.7+(0.005*phoEt.at(j))) ) {
			
			histoRecoIsoPtPhoton->Fill(phoEt.at(j));
                        
			
			
			//loop over all the GEN particles
			for (Int_t i = 0;i < nMC; i++){
			
				//check  paticle is PHOTON FROM NEUTRALINO
				if(mcPID.at(i) == 22 && mcMomPID.at(i)>=1000022 && mcMomPID.at(i)<=1000035){                                
	                             
					
					DEta = mcEta.at(i)-phoEta.at(j); 
        	                        DPhi = mcPhi.at(i)-phoPhi.at(j); 
                	                histoDeltaEta->Fill(DEta);
                        	        histoDeltaPhi->Fill(DPhi);
					
					//Matching
					if(abs(DEta)<=0.1 && abs(DPhi)<=0.1){						
						
						histoPtMatchPhoton->Fill(mcPt.at(i));
						nMatch++;					
						}
					
					}					
                                }
			                       
                        } 
                }
	
	histoNumMatch->Fill(nMatch);
	
	//JETS
	
	
	Int_t countEtCut = 0;
	Int_t countEtPmassCut = 0;
	Int_t countJet = 0;
	for (Int_t k = 0;k < nCA8Jet; k++){
	
		TLorentzVector jetVec;
		jetVec->SetPtEtaPhiM(CA8JetPt.at(k),CA8JetEta.at(k),CA8JetPhi.at(k),CA8JetMass.at(k));
		if(jetVec->Energy() > 250) countEtCut++;
		if(jetVec->Energy() > 250 && CA8prunedJetMass.at(k)>50) countEtPmassCut++;
		JetPmass->Fill(CA8prunedJetMass.at(k));
		if (CA8Jet_tau3.at(k)/CA8Jet_tau1.at(k) > 0.35) JetPmassACut->Fill(CA8prunedJetMass.at(k));
		countJet++;
	}
	nJetEtCut->Fill(countEtCut);
	nJetEtPmassCut->Fill(countEtPmassCut);
	nJet->Fill(countJet);
	
	
      //if (ientry >= 100) break;
      
   }
   
	TFile* fOut = new TFile("ggNtupleTest.root","recreate");

     histoGenPtPhoton->Write();
     histoRecoPtPhoton->Write();
	nJetEtCut->Write();
	nJetEtPmassCut->Write();
	JetPmass->Write();
	JetPmassACut->Write();
	
	histoGenPtQuark->Write();
	histoGenPtGluon->Write(); 

	histoRecoIsoPtPhoton->Write();
	histoGenPtPhotonfromX->Write();
	histoDeltaEta->Write();
	histoDeltaPhi->Write();
	histoPtMatchPhoton->Write();
	histoGenPtPhoton->Write();
	histoNumMatch->Write();
	
	
       TCanvas *canvas1 = new TCanvas("canvas1","canvas1",100,100,700,500);
       JetPmass->SetTitle("Pruned Jet Mass Before and after tau3/tau1>0.35 cut ");
       JetPmass->Draw();
       JetPmassACut->SetLineColor(kRed);
       JetPmassACut->Draw("same");

	//Plotting the historgrams and saving to files
// 
//     TCanvas *canvas1 = new TCanvas("canvas1","canvas1",100,100,700,500);  
 	  //histoDeltaEta->Draw();
// 	  histoGenPtPhoton->SetTitle("Generated and Matched #\gamma Pt");      
// 	  histoGenPtPhoton->Draw();
//     canvas1->SetLogy(1);
     //TCanvas *canvas2 = new TCanvas("canvas2","canvas2",200,200,700,500);  
// 	  histoPtMatchPhoton->SetLineColor(kRed);
	  //histoDeltaPhi->Draw();
// 	  histoPtMatchPhoton->Draw("same");
     //canvas2->SetLogy(1);
// 

//     TCanvas *canvas4 = new TCanvas("canvas4","canvas4",100,100,700,500);  
//     TLegend *legend1 = new TLegend(0.65,0.66,0.6,0.8);    
//     legend1->SetTextSize(0.04);
//     legend1->SetFillColor(kWhite);
//     legend1->SetLineColor(kWhite);
//    
//    histoGenPtPhoton->SetTitle("Pt of Gen and Reco photons");
//    histoRecoPtPhoton->SetLineColor(kRed);
//    histoGenPtPhoton->Draw();
//    histoRecoPtPhoton->Draw("same");
//    
// 
// 
//    legend1->AddEntry(histoPtMatchPhoton,"Matched","l");
//    legend1->AddEntry(histoGenPtPhoton,"Generated","l");
//    legend1->Draw();
// 
// 
// 
// 
// 
// 
// 
// 
// 
    
    
        	  
//     TCanvas *canvas5 = new TCanvas("canvas5","canvas5",100,100,700,500);  
//     histoGenEtaQuark->Write();
//     histoGenEtaQuark->Draw();
//    TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500); 
// 	 histoNumMatch->Draw();
// 
     
	       
   
   

  
//    canvas1->Print("/uscms_data/d3/sparedes/stealthSUSY/Ntuplizer_538v1/src/SusyAnalysis/SusyNtuplizer/macro/ggNtuple_test1/Plots/histoGenPhotons.png");
   
}





























 








