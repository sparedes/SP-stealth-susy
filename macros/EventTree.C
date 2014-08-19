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

   TH1F *histoGenPtPhotonfromX = new TH1F("histoGenPtPhotonfromX","histoGenPtPhotonfromX",150,0.,500.);


       //Reco histo
   TH1F *histoRecoPtPhoton = new TH1F("histoRecoPtPhoton","histoRecoPtPhoton",150,0.,500.);
   TH1F *histoRecoIsoPtPhoton = new TH1F("histoRecoIsoPtPhoton","histoRecoIsoPtPhoton",150,0.,500.);
   TH1F *histoRecoPhiPhoton = new TH1F("histoRecoPhiPhoton","histoRecoPhiPhoton",20,-3.1,3.1);

       //Matching	 
   TH1F *histoPtMatchIsoPhoton = new TH1F("histoPtMatchIsoPhoton","histoPtMatchIsoPhoton",150,0.,500.);
   TH1F *histoDeltaEta = new TH1F("histoDeltaEta","histoDeltaEta",500,-6.,6.);
   TH1F *histoDeltaPhi = new TH1F("histoDeltaPhi","histoDeltaPhi",600,-7.,7.);
   TH1F *histoNumMatch = new TH1F("histoNumMatch","histoNumMatch",4,0.,4.);
   TH1F *histoNumMatchFromX = new TH1F("histoNumMatchFromX","histoNumMatchFromX",4,0.,4.);
   
   TH1F *histoNPho = new TH1F("histoNPho","histoNPho",10,0.,10.);
   TH1F *histoLooseIso = new TH1F("histoLooseIso","histoLooseIso",4,0.,4.);
   TH1F *histoMedIso = new TH1F("histoMedIso","histoMedIso",4,0.,4.);
   TH1F *histoTightIso = new TH1F("histoTightIso","histoTightIso",4,0.,4.);

   Float_t DEta;
   Float_t DPhi;

       //JETS	 
   TH1F *nJet = new TH1F("nJet","nJet",12,0.,12.);				  
   TH1F *nJetEtCut = new TH1F("nJetEtCut","nJetEtCut",10,0.,10.);
   TH1F *nJetEtPmassCut = new TH1F("nJetEtPmassCut","nJetEtPmassCut",10,0.,10.);
   TH1F *JetPmass = new TH1F("JetPmass","JetPmass",200,0.,400.);
   TH1F *JetPmassACut = new TH1F("JetPmassACut","JetPmassACut",200,0.,400.);

      //sorting according to number of iso. photons
    
   TH1F *histoGenPtPhoton_NMid0 = new TH1F("histoGenPtPhoton_NMid0","histoGenPtPhoton_NMid0",150,0.,500.);
   TH1F *histoGenPtPhoton_NMid1 = new TH1F("histoGenPtPhoton_NMid1","histoGenPtPhoton_NMid1",150,0.,500.);
   TH1F *histoGenPtPhoton_NMi1o0 = new TH1F("histoGenPtPhoton_NMi1o0","histoGenPtPhoton_NMi1o0",150,0.,500.);
    
   
   TH1F *histoGenPtPhotonfromX_NMid0 = new TH1F("histoGenPtPhotonfromX_NMid0","histoGenPtPhotonfromX_NMid0",150,0.,500.);
   TH1F *histoGenPtPhotonfromX_NMid1 = new TH1F("histoGenPtPhotonfromX_NMid1","histoGenPtPhotonfromX_NMid1",150,0.,500.);
   TH1F *histoGenPtPhotonfromX_NMi1o0 = new TH1F("histoGenPtPhotonfromX_NMi1o0","histoGenPtPhotonfromX_NMi1o0",150,0.,500.);
      
   TH1F *nJet_NMid1  = new TH1F("nJet_NMid1","nJet_NMid1",12,0.,12.);				  
   TH1F *nJetEtCut_NMid1   = new TH1F("nJetEtCut_NMid1","nJetEtCut_NMid1  ",10,0.,10.);
   TH1F *nJetEtPmassCut_NMid1   = new TH1F("nJetEtPmassCut_NMid1","nJetEtPmassCut_NMid1  ",10,0.,10.);
   TH1F *JetPmass_NMid1   = new TH1F("JetPmass_NMid1  ","JetPmass_NMid1",200,0.,400.);
   TH1F *JetPmassACut_NMid1   = new TH1F("JetPmassACut_NMid1","JetPmassACut_NMid1",200,0.,400.);
 
   TH1F *nJet_NMid0  = new TH1F("nJet_NMid0","nJet_NMid0",12,0.,12.);				  
   TH1F *nJetEtCut_NMid0   = new TH1F("nJetEtCut_NMid0","nJetEtCut_NMid0  ",10,0.,10.);
   TH1F *nJetEtPmassCut_NMid0   = new TH1F("nJetEtPmassCut_NMid0","nJetEtPmassCut_NMid0  ",10,0.,10.);
   TH1F *JetPmass_NMid0   = new TH1F("JetPmass_NMid0  ","JetPmass_NMid0",200,0.,400.);
   TH1F *JetPmassACut_NMid0   = new TH1F("JetPmassACut_NMid0","JetPmassACut_NMid0",200,0.,400.);
 
   TH1F *nJet_NMid1o0  = new TH1F("nJet_NMid1o0","nJet_NMid1o0",12,0.,12.);				  
   TH1F *nJetEtCut_NMid1o0   = new TH1F("nJetEtCut_NMid1o0","nJetEtCut_NMid1o0  ",10,0.,10.);
   TH1F *nJetEtPmassCut_NMid1o0   = new TH1F("nJetEtPmassCut_NMid1o0","nJetEtPmassCut_NMid1o0  ",10,0.,10.);
   TH1F *JetPmass_NMid1o0   = new TH1F("JetPmass_NMid1o0  ","JetPmass_NMid1o0",200,0.,400.);
   TH1F *JetPmassACut_NMid1o0   = new TH1F("JetPmassACut_NMid1o0","JetPmassACut_NMid1o0",200,0.,400.);
 
   
//loop over all the events
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;


	//      
      for (Int_t i = 0;i < nMC; i++){
        
        	//recognize QUARKS
              if(mcPID->at(i) < 9 && mcPID->at(i) > 0) {
        	    histoGenEtaQuark->Fill(mcEta->at(i));		    
        	    histoGenPhiQuark->Fill(mcPhi->at(i));		    
        	    histoGenPtQuark->Fill(mcPt->at(i));
              }
        	//recognize GLUONS
              else if (mcPID->at(i) == 21) {
        	    histoGenEtaGluon->Fill(mcEta->at(i));		    
        	    histoGenPhiGluon->Fill(mcPhi->at(i));		    
        	    histoGenPtGluon->Fill(mcPt->at(i));
              } 
       //recognize PHOTONS
       else if (mcPID->at(i) == 22) {
        	    histoGenEtaPhoton->Fill(mcEta->at(i));		    
        	    histoGenPhiPhoton->Fill(mcPhi->at(i));		    
        	    histoGenPtPhoton->Fill(mcPt->at(i));
        	    if (mcMomPID->at(i)>=1000022 && mcMomPID->at(i)<=1000035) histoGenPtPhotonfromX->Fill(mcPt->at(i));
        		} 
        }	       




      Int_t nMatch = 0;
      Int_t nMatchFromX = 0;
        
        //loop over all the RECO photons in the event
      for (Int_t j = 0;j < nPho; j++){

        histoRecoPtPhoton->Fill(phoEt->at(j));	      
        //isolation conditions
        if (phoPFChIso->at(j)<1.5 && phoPFNeuIso->at(j)<(1.0+(0.4*phoEt->at(j))) && phoPFPhoIso->at(j)<(0.7+(0.005*phoEt->at(j))) ) {
        	
        	histoRecoIsoPtPhoton->Fill(phoEt->at(j));
        	
        	
        	
        	//loop over all the GEN particles
        	for (Int_t i = 0;i < nMC; i++){
        	
        		//check  paticle is PHOTON FROM NEUTRALINO
        		if(mcPID->at(i) == 22 && mcMomPID->at(i) >= 1000022 && mcMomPID->at(i) <= 1000035){				    
        		     
        			
        			DEta = mcEta->at(i)-phoEta->at(j); 
        			DPhi = mcPhi->at(i)-phoPhi->at(j); 
        			histoDeltaEta->Fill(DEta);
        			histoDeltaPhi->Fill(DPhi);
        			
        			//Matching
        			if(abs(DEta) <= 0.1 && abs(DPhi) <= 0.1){						
        				
        				histoPtMatchIsoPhoton->Fill(mcPt->at(i));
        				nMatch++;
					if (mcMomPID->at(i) >= 1000022 && mcMomPID->at(i) <= 1000035) nMatchFromX++;					
        				}
        			
        			}					
        		}
        			       
        	} 
      	 }

      histoNumMatch->Fill(nMatch);
      histoNumMatchFromX->Fill(nMatchFromX);
      
      Int_t phoCount = 0;
      Int_t MidIsoCount = 0;
      Int_t TightIsoCount = 0;
      Int_t LooseIsoCount = 0;
      for (Int_t i = 0;i < nPho; i++){
      	phoCount++;
      	if (phoPFChIso->at(i)<0.7 && phoPFNeuIso->at(i)<(0.4+(0.4*phoEt->at(i))) && phoPFPhoIso->at(i)<(0.5+(0.005*phoEt->at(i)))) TightIsoCount++;
       	if (phoPFChIso->at(i)<1.5 && phoPFNeuIso->at(i)<(1.0+(0.4*phoEt->at(i))) && phoPFPhoIso->at(i)<(0.7+(0.005*phoEt->at(i)))) MidIsoCount++;
     	if (phoPFChIso->at(i)<2.6 && phoPFNeuIso->at(i)<(3.5+(4*phoEt->at(i))) && phoPFPhoIso->at(i)<(1.3+(0.005*phoEt->at(i)))) LooseIsoCount++;
	}
      histoNPho->Fill(phoCount); 
      histoMedIso->Fill(MidIsoCount);
      histoTightIso->Fill(TightIsoCount); 
      histoLooseIso->Fill(LooseIsoCount); 
      
      
      //sorting according to number of iso. photons
      
      Int_t countEtCut_NMid0 = 0;
      Int_t countEtPmassCut_NMid0 = 0;
      Int_t countJet_NMid0 = 0;
      
      Int_t countEtCut_NMid1 = 0;
      Int_t countEtPmassCut_NMid1 = 0;
      Int_t countJet_NMid1 = 0;
      
      Int_t countEtCut_NMid1o0 = 0;
      Int_t countEtPmassCut_NMid1o0 = 0;
      Int_t countJet_NMid1o0 = 0;
      
     if(MidIsoCount == 0){
      	
      	};
      if(MidIsoCount == 1){
      	
	};
      if(MidIsoCount <= 1){
      	
	};
      
      //JETS


      Int_t countEtCut = 0;
      Int_t countEtPmassCut = 0;
      Int_t countJet = 0;
      for (Int_t k = 0;k < nCA8Jet; k++){

              TLorentzVector jetVec;
              jetVec->SetPtEtaPhiM(CA8JetPt->at(k),CA8JetEta->at(k),CA8JetPhi->at(k),CA8JetMass->at(k));
              if(jetVec->Energy() > 250){
	      	countEtCut++;
		if (MidIsoCount == 0) countEtCut_NMid0++;		
		if (MidIsoCount == 1) countEtCut_NMid1++;		
		if (MidIsoCount <= 1) countEtCut_NMid1o0++;		
		}
              if(jetVec->Energy() > 250 && CA8prunedJetMass->at(k)>50){
	      	countEtPmassCut++;
		if (MidIsoCount == 0) countEtPmassCut_NMid0++;  	
		if (MidIsoCount == 1) countEtPmassCut_NMid1++;  	
		if (MidIsoCount <= 1) countEtPmassCut_NMid1o0++;		
		}
              JetPmass->Fill(CA8prunedJetMass->at(k));
              if (CA8Jet_tau3->at(k)/CA8Jet_tau1->at(k) < 0.35) JetPmassACut->Fill(CA8prunedJetMass->at(k));
              countJet++;
	      if (MidIsoCount == 0) {
	      	countJet_NMid0++;
	      	JetPmass_NMid0->Fill(CA8prunedJetMass->at(k));
		if (CA8Jet_tau3->at(k)/CA8Jet_tau1->at(k) < 0.35) JetPmassACut_NMid0->Fill(CA8prunedJetMass->at(k));
		}
	      if (MidIsoCount == 1) {
	      	countJet_NMid1++;
	      	JetPmass_NMid1->Fill(CA8prunedJetMass->at(k));
		if (CA8Jet_tau3->at(k)/CA8Jet_tau1->at(k) < 0.35) JetPmassACut_NMid1->Fill(CA8prunedJetMass->at(k));
		}
	      if (MidIsoCount <= 1) {
	      	countJet_NMid1o0++;
	      	JetPmass_NMid1o0->Fill(CA8prunedJetMass->at(k));
		if (CA8Jet_tau3->at(k)/CA8Jet_tau1->at(k) < 0.35) JetPmassACut_NMid1o0->Fill(CA8prunedJetMass->at(k));
		}
           }
      nJetEtCut->Fill(countEtCut);
      nJetEtPmassCut->Fill(countEtPmassCut);
      nJet->Fill(countJet);
      
      nJetEtCut_NMid0->Fill(countEtCut_NMid0);
      nJetEtPmassCut_NMid0->Fill(countEtPmassCut_NMid0);
      nJet_NMid0->Fill(countJet_NMid0);
      
      nJetEtCut_NMid1->Fill(countEtCut_NMid1);
      nJetEtPmassCut_NMid1->Fill(countEtPmassCut_NMid1);
      nJet_NMid1->Fill(countJet_NMid1);
      
      nJetEtCut_NMid1o0->Fill(countEtCut_NMid1o0);
      nJetEtPmassCut_NMid1o0->Fill(countEtPmassCut_NMid1o0);
      nJet_NMid1o0->Fill(countJet_NMid1o0);
      
      for (Int_t i = 0;i < nMC; i++){
      	if (mcPID->at(i) == 22) {
        	    //histoGenEtaPhoton->Fill(mcEta->at(i));		    
        	    //histoGenPhiPhoton->Fill(mcPhi->at(i));
		    
		    if (MidIsoCount ==0) {
		      histoGenPtPhoton_NMid0->Fill(mcPt->at(i));
		      if (mcMomPID->at(i)>=1000022 && mcMomPID->at(i)<=1000035) histoGenPtPhotonfromX_NMid0->Fill(mcPt->at(i));
		      }
		    if (MidIsoCount == 1) {
		      histoGenPtPhoton_NMid1->Fill(mcPt->at(i));
		      if (mcMomPID->at(i)>=1000022 && mcMomPID->at(i)<=1000035) histoGenPtPhotonfromX_NMid1->Fill(mcPt->at(i));
		      }
		    if (MidIsoCount <= 1) {
		      histoGenPtPhoton_NMid1->Fill(mcPt->at(i));
		      if (mcMomPID->at(i)>=1000022 && mcMomPID->at(i)<=1000035) histoGenPtPhotonfromX_NMid1->Fill(mcPt->at(i));
		      }
        	} 
        }      
      
      
      //if (ientry > 100) break;
      
            // if (Cut(ientry) < 0) continue;
   }
 TFile* fOut = new TFile("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/ggNtupleTest.root","RECREATE");
 
//  histoGenPtQuark->Write();			
//  histoGenPtGluon->Write();
  histoGenPtPhoton->Write();
//  histoGenEtaQuark->Write();
//  histoGenEtaGluon->Write();
//  histoGenEtaPhoton->Write();
//  histoGenPhiQuark->Write();
//  histoGenPhiGluon->Write();
//  histoGenPhiPhoton->Write();
//  histoGenPtPhoton->Write();
//  histoGenPtPhotonfromX->Write();
//  histoRecoPtPhoton->Write();
//  histoRecoIsoPtPhoton->Write();
//  histoRecoPhiPhoton->Write();
//  histoPtMatchIsoPhoton->Write();
//  histoDeltaEta->Write();
//  histoDeltaPhi->Write();
//  histoNumMatch->Write();
//  histoNumMatchFromX->Write();
//  histoNPho->Write();
//  histoLooseIso->Write();
//  histoMedIso->Write();
//  histoTightIso->Write();
//  nJet->Write();
//  nJetEtCut->Write();
//  nJetEtPmassCut->Write();
//  JetPmass->Write();
//  JetPmassACut->Write();
 nJet_NMid0->Write();
 nJetEtCut_NMid0->Write();
 nJetEtPmassCut_NMid0->Write();
 JetPmass_NMid0->Write();
 JetPmassACut_NMid0->Write();
  
 nJet_NMid1->Write();
 nJetEtCut_NMid1->Write();
 nJetEtPmassCut_NMid1->Write();
 JetPmass_NMid1->Write();
 JetPmassACut_NMid1->Write();
  
 nJet_NMid1o0->Write();
 nJetEtCut_NMid1o0->Write();
 nJetEtPmassCut_NMid1o0->Write();
 JetPmass_NMid1o0->Write();
 JetPmassACut_NMid1o0->Write();
 
 histoGenPtPhoton_NMid0->Write(); 
 histoGenPtPhoton_NMid1->Write();
 histoGenPtPhoton_NMi1o0->Write();


 histoGenPtPhotonfromX_NMid0->Write(); 
 histoGenPtPhotonfromX_NMid1->Write(); 
 histoGenPtPhotonfromX_NMi1o0->Write();
  
}










