/************************************************
* Author: Fan Ruirui
* email:fanrr@ihep.ac.cn
* Last modified: 2014-09-18 15:09
* Filename: tmva.cc
* Description: 
*************************************************/
{
	TFile*f=new TFile("results.root");
        TTree *output = (TTree *) f->Get("output");
	TCut sigcut="type==0";
	TCut bkgcut="type!=0";
	TString outfileName( "TMVA.root" );
	TFile* outputFile = TFile::Open( outfileName, "RECREATE" );
	TMVA::Factory *factory = new TMVA::Factory( "TMVAClassification", outputFile,
         "!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification" );
	factory->AddVariable( "dE1", 'F' );
	factory->AddVariable( "dE2", 'F' );
	factory->AddVariable( "E", 'F' );
	factory->SetInputTrees(output,sigcut,bkgcut);
	factory->BookMethod( TMVA::Types::kMLP, "MLP", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:!UseRegulator" );
	factory->TrainAllMethods();
	factory->TestAllMethods();
	factory->EvaluateAllMethods();
	outputFile->Close();
	delete factory;
}
