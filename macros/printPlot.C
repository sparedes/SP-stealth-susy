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
 
 
//  TCanvas *canvas1 = new TCanvas("canvas1","canvas1",100,100,700,500);
// 
//  jetEtvsMass->GetXaxis()->SetTitle("Mass (GeV)"); 
//  jetEtvsMass->GetYaxis()->SetTitle("Et (GeV)"); 
//  jetEtvsMass->SetTitle("Et vs Jet Mass");
//  jetEtvsMass->SetStats(kFALSE); 
//  jetEtvsMass->Draw("colz");
//  canvas1->SetLogz(kTRUE); 
//  canvas1->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetEtvsMass.png"); 
//  
//  
//   TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);
// 
//  jetEnergyvsPrunMass->GetXaxis()->SetTitle("PrunMass (GeV)"); 
//  jetEnergyvsPrunMass->GetYaxis()->SetTitle("Energy (GeV)"); 
//  jetEnergyvsPrunMass->SetTitle("Energy vs Jet PrunMass");
//  jetEnergyvsPrunMass->SetStats(kFALSE); 
//  jetEnergyvsPrunMass->Draw("colz");
//  canvas2->SetLogz(kTRUE); 
//  canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetEnergyvsPrunMass.png"); 
// 
//  TCanvas *canvas3 = new TCanvas("canvas3","canvas3",100,100,700,500);
// 
//  jetEnergyvsMass->GetXaxis()->SetTitle("Mass (GeV)"); 
//  jetEnergyvsMass->GetYaxis()->SetTitle("Energy (GeV)"); 
//  jetEnergyvsMass->SetTitle("Energy vs Jet Mass");
//  jetEnergyvsMass->SetStats(kFALSE); 
//  jetEnergyvsMass->Draw("colz");
//  canvas3->SetLogz(kTRUE); 
//  canvas3->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetEnergyvsMass.png"); 
//  
//  
//  
//  TCanvas *canvas4 = new TCanvas("canvas4","canvas4",100,100,700,500);
// 
//  jetEtvsPrunMass->GetXaxis()->SetTitle("PrunMass (GeV)"); 
//  jetEtvsPrunMass->GetYaxis()->SetTitle("Et (GeV)"); 
//  jetEtvsPrunMass->SetTitle("Et vs et PrunMass ");
//  jetEtvsPrunMass->SetStats(kFALSE); 
//  jetEtvsPrunMass->Draw("colz");
//  canvas4->SetLogz(kTRUE); 
//  canvas4->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/jetEtvsPrunMass.png"); 
//  
//  
 TCanvas *canvas5 = new TCanvas("canvas5","canvas5",100,100,700,500);

 quarkFromSquarkJetMassvsTauRatio->GetXaxis()->SetTitle("Tau3 "); 
 quarkFromSquarkJetMassvsTauRatio->GetYaxis()->SetTitle("Energy (GeV)"); 
 quarkFromSquarkJetMassvsTauRatio->SetTitle("  quark-from-squark-Jet Mass vs TauRatio ");
 quarkFromSquarkJetMassvsTauRatio->SetStats(kTRUE); 
 quarkFromSquarkJetMassvsTauRatio->Draw("colz");
 canvas5->SetLogz(kFALSE); 
 gPad->Update();
 TPaletteAxis *palette = (TPaletteAxis*)quarkFromSquarkJetMassvsTauRatio->GetListOfFunctions()->FindObject("palette");
 palette->SetY2NDC(0.67);
  
 canvas5->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/quarkFromSquarkJetMassvsTauRatio.png"); 
 
 
 TCanvas *canvas6 = new TCanvas("canvas6","canvas6",100,100,700,500);

 singlinoFromNtrlioJetMassvsTauRatio->GetXaxis()->SetTitle("TauRatio "); 
 singlinoFromNtrlioJetMassvsTauRatio->GetYaxis()->SetTitle("Energy (GeV)"); 
 singlinoFromNtrlioJetMassvsTauRatio->SetTitle("  singlino-from-neutralino-Jet Mass vs TauRatio ");
 singlinoFromNtrlioJetMassvsTauRatio->SetStats(kTRUE); 
 singlinoFromNtrlioJetMassvsTauRatio->Draw("colz");
 canvas6->SetLogz(kFALSE); 
 gPad->Update();
 TPaletteAxis *palette2 = (TPaletteAxis*)singlinoFromNtrlioJetMassvsTauRatio->GetListOfFunctions()->FindObject("palette");
 palette2->SetY2NDC(0.67);
 canvas6->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/singlinoFromNtrlioJetMassvsTauRatio.png"); 

 
 TCanvas *canvas7 = new TCanvas("canvas7","canvas7",100,100,700,500);

 quarkJetMassvsTauRatio->GetXaxis()->SetTitle("Tau3 "); 
 quarkJetMassvsTauRatio->GetYaxis()->SetTitle("Mass (GeV)"); 
 quarkJetMassvsTauRatio->SetTitle(" quark Jet Mass vs TauRatio  ");
 quarkJetMassvsTauRatio->SetStats(kTRUE); 
 quarkJetMassvsTauRatio->Draw("colz");
 canvas7->SetLogz(kFALSE); 
 gPad->Update();
 TPaletteAxis *palette3 = (TPaletteAxis*)quarkJetMassvsTauRatio->GetListOfFunctions()->FindObject("palette");
 palette3->SetY2NDC(0.67);
  
 canvas7->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/quarkJetMassvsTauRatio.png"); 
 
 
 TCanvas *canvas8 = new TCanvas("canvas8","canvas8",100,100,700,500);

 neutralinoJetMassvsTauRatio->GetXaxis()->SetTitle("TauRatio "); 
 neutralinoJetMassvsTauRatio->GetYaxis()->SetTitle("Mass (GeV)"); 
 neutralinoJetMassvsTauRatio->SetTitle("neutralino Jet Mass vs TauRatio ");
 neutralinoJetMassvsTauRatio->SetStats(kTRUE); 
 neutralinoJetMassvsTauRatio->Draw("colz");
 canvas8->SetLogz(kTRUE); 
 gPad->Update();
 TPaletteAxis *palette4 = (TPaletteAxis*)neutralinoJetMassvsTauRatio->GetListOfFunctions()->FindObject("palette");
 palette4->SetY2NDC(0.67);
  
 canvas8->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/neutralinoJetMassvsTauRatio.png"); 
 
 
 TCanvas *canvas10 = new TCanvas("canvas10","canvas10",100,100,700,500);

 quarkFromSquarkJetMassvsTauRatioEtCut->GetXaxis()->SetTitle("TauRatio "); 
 quarkFromSquarkJetMassvsTauRatioEtCut->GetYaxis()->SetTitle("Mass (GeV)"); 
 quarkFromSquarkJetMassvsTauRatioEtCut->SetTitle("quark Jet Mass vs TauRatio, Et > 250 ");
 quarkFromSquarkJetMassvsTauRatioEtCut->SetStats(kTRUE); 
 quarkFromSquarkJetMassvsTauRatioEtCut->Draw("colz");
 canvas10->SetLogz(kTRUE); 
 gPad->Update();
 TPaletteAxis *palette4 = (TPaletteAxis*)quarkFromSquarkJetMassvsTauRatioEtCut->GetListOfFunctions()->FindObject("palette");
 palette4->SetY2NDC(0.67);
  
 canvas10->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/quarkFromSquarkJetMassvsTauRatioEtCut.png");
  
 TCanvas *canvas10 = new TCanvas("canvas10","canvas10",100,100,700,500);

 singlinoFromNtrlioJetMassvsTauRatioEtCut->GetXaxis()->SetTitle("TauRatio "); 
 singlinoFromNtrlioJetMassvsTauRatioEtCut->GetYaxis()->SetTitle("Mass (GeV)"); 
 singlinoFromNtrlioJetMassvsTauRatioEtCut->SetTitle("neutralino Jet Mass vs TauRatio, Et > 250 ");
 singlinoFromNtrlioJetMassvsTauRatioEtCut->SetStats(kTRUE); 
 singlinoFromNtrlioJetMassvsTauRatioEtCut->Draw("colz");
 canvas10->SetLogz(kTRUE); 
 gPad->Update();
 TPaletteAxis *palette4 = (TPaletteAxis*)singlinoFromNtrlioJetMassvsTauRatioEtCut->GetListOfFunctions()->FindObject("palette");
 palette4->SetY2NDC(0.67);
  
 canvas10->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/singlinoFromNtrlioJetMassvsTauRatioEtCut.png"); 
 
 TCanvas *canvas11 = new TCanvas("canvas11","canvas11",100,100,700,500);

 singlinoFromNtrlioJetMassvsEtTauRatioCut->GetXaxis()->SetTitle("TauRatio "); 
 singlinoFromNtrlioJetMassvsEtTauRatioCut->GetYaxis()->SetTitle("Mass (GeV)"); 
 singlinoFromNtrlioJetMassvsEtTauRatioCut->SetTitle("neutralino Jet Mass vs Et, TauRatio < 0.35 ");
 singlinoFromNtrlioJetMassvsEtTauRatioCut->SetStats(kTRUE); 
 singlinoFromNtrlioJetMassvsEtTauRatioCut->Draw("colz");
 canvas11->SetLogz(kFALSE); 
 gPad->Update();
 TPaletteAxis *palette4 = (TPaletteAxis*)singlinoFromNtrlioJetMassvsEtTauRatioCut->GetListOfFunctions()->FindObject("palette");
 palette4->SetY2NDC(0.67);
  
 canvas11->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/singlinoFromNtrlioJetMassvsEtTauRatioCut.png"); 
 
 TCanvas *canvas12 = new TCanvas("canvas12","canvas12",100,100,700,500);

 quarkFromSquarkJetMassvsEtTauRatioCut->GetXaxis()->SetTitle("TauRatio "); 
 quarkFromSquarkJetMassvsEtTauRatioCut->GetYaxis()->SetTitle("Mass (GeV)"); 
 quarkFromSquarkJetMassvsEtTauRatioCut->SetTitle("neutralino Jet Mass vs Et, TauRatio < 0.35 ");
 quarkFromSquarkJetMassvsEtTauRatioCut->SetStats(kTRUE); 
 quarkFromSquarkJetMassvsEtTauRatioCut->Draw("colz");
 canvas12->SetLogz(kTRUE); 
 gPad->Update();
 TPaletteAxis *palette4 = (TPaletteAxis*)quarkFromSquarkJetMassvsEtTauRatioCut->GetListOfFunctions()->FindObject("palette");
 palette4->SetY2NDC(0.67);
  
 canvas12->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/quarkFromSquarkJetMassvsEtTauRatioCut.png"); 
  
 
 TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);
 quarkFromSquarkJetPt->SetTitle("Quark Jet Pt");
 quarkFromSquarkJetPt->GetXaxis()->SetTitle("GeV");
 quarkFromSquarkJetPt->Draw();
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/quarkFromSquarkJetPt.png");

 TCanvas *canvas2 = new TCanvas("canvas2","canvas2");
 quarkFromSquarkJetMass->SetTitle("Quark Jet Mass");
 quarkFromSquarkJetMass->GetXaxis()->SetTitle("GeV");
 quarkFromSquarkJetMass->Draw();
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/quarkFromSquarkJetMass.png");

 TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);
 singlinoFromNtrlioJetPt->SetTitle("Neutralino Jet Pt");
 singlinoFromNtrlioJetPt->GetXaxis()->SetTitle("GeV");
 singlinoFromNtrlioJetPt->Draw();
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/singlinoFromNtrlioJetPt.png");

 TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);
 singlinoFromNtrlioJetMass->SetTitle("Neutralino Jet Mass");
 singlinoFromNtrlioJetMass->GetXaxis()->SetTitle("GeV");
 singlinoFromNtrlioJetMass->Draw();
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/singlinoFromNtrlioJetMass.png");

 TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);
 quarkFromSquarkJetEta->SetTitle("Quark Jet Eta");
 quarkFromSquarkJetEta->GetXaxis()->SetTitle("GeV");
 quarkFromSquarkJetEta->Draw();
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/quarkFromSquarkJetEta.png");

 TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);
 quarkFromSquarkJetEt->SetTitle("Quark Jet Et");
 quarkFromSquarkJetEt->GetXaxis()->SetTitle("GeV");
 quarkFromSquarkJetEt->Draw();
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/quarkFromSquarkJetEt.png");

 TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);
 quarkFromSquarkJetTauRatio->SetTitle("Quark Jet Tau3/Tau1");
 quarkFromSquarkJetTauRatio->Draw();
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/quarkFromSquarkJetTauRatio.png");

 TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);
 singlinoFromNtrlioJetEta->SetTitle("Neutralino Jet Eta");
 singlinoFromNtrlioJetEta->GetXaxis()->SetTitle("GeV");
 singlinoFromNtrlioJetEta->Draw();
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/singlinoFromNtrlioJetEta.png");
   
 TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);
 singlinoFromNtrlioJetEt->SetTitle("Neutralino Jet Et");
 singlinoFromNtrlioJetEt->GetXaxis()->SetTitle("GeV");
 singlinoFromNtrlioJetEt->Draw();
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/singlinoFromNtrlioJetEt.png");
   
 TCanvas *canvas2 = new TCanvas("canvas2","canvas2",100,100,700,500);
 singlinoFromNtrlioJetTauRatio->SetTitle("Neutralino Jet Tau3/Tau1");
 singlinoFromNtrlioJetTauRatio->Draw();
 canvas2->Print("/uscms_data/d3/sparedes/stealthSUSY/CMSSW_5_3_12/src/ggNtuple_test1/Plots/singlinoFromNtrlioJetTauRatio.png");

 
 
 	
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






























































