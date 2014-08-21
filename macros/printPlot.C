{ 
  TFile *file0 = TFile::Open("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/ggNtupleTest.root");
  
 
/*
 TCanvas *canvas1 = new TCanvas("canvas1","canvas1",100,100,700,500);
 histoLooseIso->SetTitle("Photon Isolation Loose Cut");
 histoLooseIso->GetXaxis()->SetTitle("Number of photons per event");
 histoLooseIso->Draw();
 canvas1->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/phoIsoCutLoose.png");
 
 TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);
 histoMedIso->SetTitle("Photon Isolation Mid Cut");
 histoMedIso->GetXaxis()->SetTitle("Number of photons per event");
 histoMedIso->Draw();
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/phoIsoCutMed.png");
 
 TCanvas *canvas3 = new TCanvas("canvas3","canvas3",100,100,700,500);
 histoTightIso->SetTitle("Photon Isolation Tight Cut");
 histoTightIso->GetXaxis()->SetTitle("Number of photons per event");
 histoTightIso->Draw();
 canvas3->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/phoIsoCutTight.png");
 
 
 TCanvas *canvas4 = new TCanvas("canvas4","canvas4",100,100,700,500);
 JetPmass->SetTitle("Pruned jet mass before and after tau3/tau1 < 0.35 cut");
 JetPmass->GetXaxis()->SetTitle("Jet Mass (GeV)");
 JetPmass->Draw();
 JetPmassACut->SetLineColor(kRed);
 JetPmassACut->Draw("same");
 TLegend *legend1 = new TLegend(0.65,0.66,0.6,0.8);
 legend1->SetTextSize(0.04);
 legend1->SetFillColor(kWhite);
 legend1->SetLineColor(kWhite);
 legend1->AddEntry(JetPmass,"  Before Cut","l");
 legend1->AddEntry(JetPmassACut,"  After Cut","l");
 legend1->Draw(); 
 canvas4->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetMassBefNaftTauCut.png");
 
 TCanvas *canvas5 = new TCanvas("canvas5","canvas5",100,100,700,500);
 nJet->SetTitle("Number of Jets Per Event");
 nJet->GetXaxis()->SetTitle("Number of jets per event");
 nJet->Draw();
 canvas5->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJets.png");
 
 TCanvas *canvas6 = new TCanvas("canvas6","canvas6",100,100,700,500);
 nJetEtCut->SetTitle("Number of Jets Per Event, Et>250GeV Cut");
 nJetEtCut->GetXaxis()->SetTitle("Number of jets per event");
 nJetEtCut->Draw();
 canvas6->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJetsEtCut.png"); 
 
 TCanvas *canvas7 = new TCanvas("canvas7","canvas7",100,100,700,500);
 nJetEtPmassCut->SetTitle("Number of Jets Per Event, Et>250GeV && Prun. Mass>50 Cut");
 nJetEtPmassCut->GetXaxis()->SetTitle("Number of jets per event");
 nJetEtPmassCut->Draw();
 canvas7->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJetsEtPmassCut.png"); 
 
 TCanvas *canvas8 = new TCanvas("canvas8","canvas8",100,100,700,500);
 histoGenPtPhoton->SetTitle("Pt of Photons from Neutralino and of all Photons ");
 histoGenPtPhoton->GetXaxis()->SetTitle("Pt (GeV)");
 histoGenPtPhoton->Draw();
 histoGenPtPhotonfromX->SetLineColor(kRed);
 histoGenPtPhotonfromX->Draw("same");
 TLegend *legend1 = new TLegend(0.65,0.66,0.6,0.8);
 legend1->SetTextSize(0.04);
 legend1->SetFillColor(kWhite);
 legend1->SetLineColor(kWhite);
 legend1->AddEntry(histoGenPtPhoton,"  All Photons","l");
 legend1->AddEntry(histoGenPtPhotonfromX,"  Photons from #chi","l");
 legend1->Draw(); 
 canvas8->SetLogy(1);
 canvas8->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/photonPtCompared.png");	
 
 
 // Aug 20
 
 TCanvas *canvas4 = new TCanvas("canvas4","canvas4",100,100,700,500);
 JetPmass_NMid0->SetTitle("Pruned jet mass before and after tau3/tau1 < 0.35 cut, nIsoPho = 0");
 JetPmass_NMid0->GetXaxis()->SetTitle("Jet Mass (GeV)");
 JetPmass_NMid0->Draw();
 JetPmassACut_NMid0->SetLineColor(kRed);
 JetPmassACut_NMid0->Draw("same");
 TLegend *legend1 = new TLegend(0.65,0.66,0.6,0.8);
 legend1->SetTextSize(0.04);
 legend1->SetFillColor(kWhite);
 legend1->SetLineColor(kWhite);
 legend1->AddEntry(JetPmass_NMid0,"  Before Cut","l");
 legend1->AddEntry(JetPmassACut_NMid0,"  After Cut","l");
 legend1->Draw(); 
 canvas4->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetMassBefNaftTauCut_NMid0.png");
 
 TCanvas *canvas5 = new TCanvas("canvas5","canvas5",100,100,700,500);
 nJet_NMid0->SetTitle("Number of Jets Per Event, nIsoPho = 0");
 nJet_NMid0->GetXaxis()->SetTitle("Number of jets per event");
 nJet_NMid0->Draw();
 canvas5->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJet_NMid0s.png");
 
 TCanvas *canvas6 = new TCanvas("canvas6","canvas6",100,100,700,500);
 nJetEtCut_NMid0->SetTitle("Number of Jets Per Event, Et>250GeV Cut, nIsoPho = 0");
 nJetEtCut_NMid0->GetXaxis()->SetTitle("Number of jets per event");
 nJetEtCut_NMid0->Draw();
 canvas6->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJetEtCut_NMid0.png"); 
 
 TCanvas *canvas7 = new TCanvas("canvas7","canvas7",100,100,700,500);
 nJetEtPmassCut_NMid0->SetTitle("Number of Jets Per Event, Et>250GeV && Prun. Mass>50 Cut, nIsoPho = 0");
 nJetEtPmassCut_NMid0->GetXaxis()->SetTitle("Number of jets per event");
 nJetEtPmassCut_NMid0->Draw();
 canvas7->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJetEtPmassCut_NMid0.png"); 
  

 TCanvas *canvas8 = new TCanvas("canvas8","canvas8",100,100,700,500);
 histoGenPtPhoton_NMid0->SetTitle("Pt of Photon from Neutralino and of all Photons, nIsoPho = 0 ");
 histoGenPtPhoton_NMid0->GetXaxis()->SetTitle("Pt (GeV)");
 histoGenPtPhoton_NMid0->Draw();
 histoGenPtPhotonfromX_NMid0->SetLineColor(kRed);
 histoGenPtPhotonfromX_NMid0->Draw("same");
 TLegend *legend1 = new TLegend(0.65,0.66,0.6,0.8);
 legend1->SetTextSize(0.04);
 legend1->SetFillColor(kWhite);
 legend1->SetLineColor(kWhite);
 legend1->AddEntry(histoGenPtPhoton_NMid0,"  All Photons","l");
 legend1->AddEntry(histoGenPtPhotonfromX_NMid0,"  Photons from #chi","l");
 legend1->Draw(); 
 canvas8->SetLogy(1);
 canvas8->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/photonPtCompared_NMid0.png");	
 
 
 
 TCanvas *canvas9 = new TCanvas("canvas4","canvas4",100,100,700,500);
 JetPmass_NMid1->SetTitle("Pruned jet mass before and after tau3/tau1 < 0.35 cut, nIsoPho = 1");
 JetPmass_NMid1->GetXaxis()->SetTitle("Jet Mass (GeV)");
 JetPmass_NMid1->Draw();
 JetPmassACut_NMid1->SetLineColor(kRed);
 JetPmassACut_NMid1->Draw("same");
 TLegend *legend1 = new TLegend(0.65,0.66,0.6,0.8);
 legend1->SetTextSize(0.04);
 legend1->SetFillColor(kWhite);
 legend1->SetLineColor(kWhite);
 legend1->AddEntry(JetPmass_NMid1,"  Before Cut","l");
 legend1->AddEntry(JetPmassACut_NMid1,"  After Cut","l");
 legend1->Draw(); 
 canvas9->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetMassBefNaftTauCut_NMid1.png");
 
 TCanvas *canvas10 = new TCanvas("canvas5","canvas5",100,100,700,500);
 nJet_NMid1->SetTitle("Number of Jets Per Event, nIsoPho = 1");
 nJet_NMid1->GetXaxis()->SetTitle("Number of jets per event");
 nJet_NMid1->Draw();
 canvas10->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJet_NMid1s.png");
 
 TCanvas *canvas11 = new TCanvas("canvas6","canvas6",100,100,700,500);
 nJetEtCut_NMid1->SetTitle("Number of Jets Per Event, Et>250GeV Cut, nIsoPho = 1");
 nJetEtCut_NMid1->GetXaxis()->SetTitle("Number of jets per event");
 nJetEtCut_NMid1->Draw();
 canvas11->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJetEtCut_NMid1.png"); 
 
 TCanvas *canvas12 = new TCanvas("canvas7","canvas7",100,100,700,500);
 nJetEtPmassCut_NMid1->SetTitle("Number of Jets Per Event, Et>250GeV && Prun. Mass>50 Cut, nIsoPho = 1");
 nJetEtPmassCut_NMid1->GetXaxis()->SetTitle("Number of jets per event");
 nJetEtPmassCut_NMid1->Draw();
 canvas12->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJetEtPmassCut_NMid1.png"); 
  

 TCanvas *canvas13 = new TCanvas("canvas8","canvas8",100,100,700,500);
 histoGenPtPhoton_NMid1->SetTitle("Pt of Photon from Neutralino and of all Photons, nIsoPho = 1 ");
 histoGenPtPhoton_NMid1->GetXaxis()->SetTitle("Pt (GeV)");
 histoGenPtPhoton_NMid1->Draw();
 histoGenPtPhotonfromX_NMid1->SetLineColor(kRed);
 histoGenPtPhotonfromX_NMid1->Draw("same");
 TLegend *legend1 = new TLegend(0.65,0.66,0.6,0.8);
 legend1->SetTextSize(0.04);
 legend1->SetFillColor(kWhite);
 legend1->SetLineColor(kWhite);
 legend1->AddEntry(histoGenPtPhoton_NMid1,"  All Photons","l");
 legend1->AddEntry(histoGenPtPhotonfromX_NMid1,"  Photons from #chi","l");
 legend1->Draw(); 
 canvas13->SetLogy(1);
 canvas13->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/photonPtCompared_NMid1.png");	
 
 
 
 TCanvas *canvas14 = new TCanvas("canvas4","canvas4",100,100,700,500);
 JetPmass_NMid1o0->SetTitle("Pruned jet mass before and after tau3/tau1 < 0.35 cut, nIsoPho <= 1");
 JetPmass_NMid1o0->GetXaxis()->SetTitle("Jet Mass (GeV)");
 JetPmass_NMid1o0->Draw();
 JetPmassACut_NMid1o0->SetLineColor(kRed);
 JetPmassACut_NMid1o0->Draw("same");
 TLegend *legend1 = new TLegend(0.65,0.66,0.6,0.8);
 legend1->SetTextSize(0.04);
 legend1->SetFillColor(kWhite);
 legend1->SetLineColor(kWhite);
 legend1->AddEntry(JetPmass_NMid1o0,"  Before Cut","l");
 legend1->AddEntry(JetPmassACut_NMid1o0,"  After Cut","l");
 legend1->Draw(); 
 canvas14->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetMassBefNaftTauCut_NMid1o0.png");
 
 TCanvas *canvas15 = new TCanvas("canvas5","canvas5",100,100,700,500);
 nJet_NMid1o0->SetTitle("Number of Jets Per Event, nIsoPho <= 1");
 nJet_NMid1o0->GetXaxis()->SetTitle("Number of jets per event");
 nJet_NMid1o0->Draw();
 canvas15->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJet_NMid1o0s.png");
 
 TCanvas *canvas16 = new TCanvas("canvas6","canvas6",100,100,700,500);
 nJetEtCut_NMid1o0->SetTitle("Number of Jets Per Event, Et>250GeV Cut, nIsoPho <= 1");
 nJetEtCut_NMid1o0->GetXaxis()->SetTitle("Number of jets per event");
 nJetEtCut_NMid1o0->Draw();
 canvas16->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJetEtCut_NMid1o0.png"); 
 
 TCanvas *canvas17 = new TCanvas("canvas7","canvas7",100,100,700,500);
 nJetEtPmassCut_NMid1o0->SetTitle("Number of Jets Per Event, Et>250GeV && Prun. Mass>50 Cut, nIsoPho <= 1");
 nJetEtPmassCut_NMid1o0->GetXaxis()->SetTitle("Number of jets per event");
 nJetEtPmassCut_NMid1o0->Draw();
 canvas17->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/nJetEtPmassCut_NMid1o0.png"); 
  

 TCanvas *canvas18 = new TCanvas("canvas8","canvas8",100,100,700,500);
 histoGenPtPhoton_NMid1o0->SetTitle("Pt of Photon from Neutralino and of all Photons, nIsoPho <= 1 ");
 histoGenPtPhoton_NMid1o0->GetXaxis()->SetTitle("Pt (GeV)");
 histoGenPtPhoton_NMid1o0->Draw();
 histoGenPtPhotonfromX_NMid1o0->SetLineColor(kRed);
 histoGenPtPhotonfromX_NMid1o0->Draw("same");
 TLegend *legend1 = new TLegend(0.65,0.66,0.6,0.8);
 legend1->SetTextSize(0.04);
 legend1->SetFillColor(kWhite);
 legend1->SetLineColor(kWhite);
 legend1->AddEntry(histoGenPtPhoton_NMid1o0,"  All Photons","l");
 legend1->AddEntry(histoGenPtPhotonfromX_NMid1o0,"  Photons from #chi","l");
 legend1->Draw(); 
 canvas18->SetLogy(1);
 canvas18->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/photonPtCompared_NMid1o0.png"); */
 
 
 TCanvas *canvas1 = new TCanvas("canvas1","canvas1",100,100,700,500);

 jetEtvsPrunMass->GetXaxis()->SetTitle("PrunMass (GeV)"); 
 jetEtvsPrunMass->GetYaxis()->SetTitle("Et (GeV)"); 
 jetEtvsPrunMass->SetTitle("Jet PrunMass vs Et");
 jetEtvsPrunMass->SetStats(kFALSE); 
 jetEtvsPrunMass->Draw("colz");
 canvas1->SetLogz(kTRUE); 
 canvas1->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetEtvsPrunMass.png"); 
 
 
  TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);

 jetEtvsPrunMass->GetXaxis()->SetTitle("PrunMass (GeV)"); 
 jetEtvsPrunMass->GetYaxis()->SetTitle("Energy (GeV)"); 
 jetEtvsPrunMass->SetTitle("Jet PrunMass vs Energy");
 jetEtvsPrunMass->SetStats(kFALSE); 
 jetEtvsPrunMass->Draw("colz");
 canvas2->SetLogz(kTRUE); 
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetEnergyvsPrunMass.png"); 

 
 
 TCanvas *canvas1 = new TCanvas("canvas1","canvas1",100,100,700,500);

 jetEtvsMass->GetXaxis()->SetTitle("Mass (GeV)"); 
 jetEtvsMass->GetYaxis()->SetTitle("Et (GeV)"); 
 jetEtvsMass->SetTitle("Jet Mass vs Et");
 jetEtvsMass->SetStats(kFALSE); 
 jetEtvsMass->Draw("colz");
 canvas1->SetLogz(kTRUE); 
 canvas1->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetEtvsMass.png"); 
 
 
  TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);

 jetEtvsMass->GetXaxis()->SetTitle("Mass (GeV)"); 
 jetEtvsMass->GetYaxis()->SetTitle("Energy (GeV)"); 
 jetEtvsMass->SetTitle("Jet Mass vs Energy");
 jetEtvsMass->SetStats(kFALSE); 
 jetEtvsMass->Draw("colz");
 canvas2->SetLogz(kTRUE); 
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetEnergyvsMass.png"); 
 
 
 
 
   
 
 
 
 	
//  TCanvas *canvas1 = new TCanvas("canvas1","canvas1",100,100,700,500);
//  histoA->SetTitle("Title");
//  histoA->Draw();
//  histoB->SetLineColor(kRed);
//  histoB->Draw("same");





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

}






























































