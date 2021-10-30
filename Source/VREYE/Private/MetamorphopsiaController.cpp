// Fill out your copyright notice in the Description page of Project Settings.


#include "MetamorphopsiaController.h"

#define MAX_LAYERS 3

// Sets default values
AMetamorphopsiaController::AMetamorphopsiaController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMetamorphopsiaController::Initiate() {
	//get scotoma values from past_meta into meta
	meta[Eye::Left].layers_active = past_meta[Eye::Left].layers_active;
	meta[Eye::Right].layers_active = past_meta[Eye::Right].layers_active;

	meta[Eye::Left].layers = past_meta[Eye::Left].layers;
	meta[Eye::Right].layers = past_meta[Eye::Right].layers;
	
	//create material instance from current meta

	//adjust chart based on past chart info

	//set the material to the chart
}

void AMetamorphopsiaController::InactiveLayers(Eye eye, TArray<int8>& idx) {
	idx = {};
	for (int8 i = 0; i < meta[eye].layers_active.Num(); i++)
	{
		if (!meta[eye].layers_active[i]) idx.Add(i);
	}
}
/*
void AMetamorphopsiaController::CreateScotomaLayer(Eye eye, int8& layer) {
	FScotomata_C new_sc;

	TArray<int8> idx;
	InactiveLayers(eye, idx);
	if (idx.Num() == 0) {
		// all layers are active
		layer = MAX_LAYERS - 1;
	}
	else if (idx.Num() == MAX_LAYERS) {
		// all layers inactive
		meta[eye].layers.Empty();
		meta[eye].layers.Add(new_sc);
		layer = 0;
	}
	else {
		//at least one layer active
		layer = idx[0];
		new_sc.MeanColor = meta[eye].layers[layer - 1].MeanColor;
		new_sc.Sigma = meta[eye].layers[layer - 1].Sigma;
		meta[eye].layers[layer] = new_sc;
	}
	meta[eye].layers_active[layer] = true;
}
void AMetamorphopsiaController::CreateMaterialfromScotoma_C(Eye eye, TArray<int32> met_layers, UMaterialInstanceDynamic& distortion_mat) {

}

void AMetamorphopsiaController::ConvertLocationToUV(Eye eye, FVector location, FLinearColor& UV) {

}

void AMetamorphopsiaController::UpdatePosition(Eye eye, TArray<int32> met_layers, Move_Along direction) {

}

void AMetamorphopsiaController::UpdatePositionfromVector(Eye eye, TArray<int32> met_layers, FVector location) {

}

void AMetamorphopsiaController::UpdateMetamorphopsia(Eye eye, int32 met_layers, int32 property) {

}

void AMetamorphopsiaController::TrackGazeFixation(FVector GazeDirection, bool& reliable) {

}*/

// Called when the game starts or when spawned
void AMetamorphopsiaController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMetamorphopsiaController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

