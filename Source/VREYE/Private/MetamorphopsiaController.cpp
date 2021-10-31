// Fill out your copyright notice in the Description page of Project Settings.


#include "MetamorphopsiaController.h"

#define MAX_LAYERS 3

// Sets default values
AMetamorphopsiaController::AMetamorphopsiaController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMetamorphopsiaController::Initiate(TArray<UMaterialInstanceDynamic*> distortion_mats, UStaticMeshComponent* plane) {
	//get scotoma values from past_meta into meta
	simulated_distortions = distortion_mats;
	distortion_plane = plane;
	
	//create material instance from current meta

	//adjust chart based on past chart info

	//set the material to the chart
}

void AMetamorphopsiaController::Simulate(int which_distortion) {
	distortion_plane->SetMaterial(0, simulated_distortions[which_distortion]);
}

void AMetamorphopsiaController::fromMaterialtoScotoma_C(UMaterialInstanceDynamic* mat, FScotoma_C& scotomas) {
	float j;
	FScotoma_C sc;
	for (int8 layer = 0; layer < MAX_LAYERS; layer++) {
		mat->GetScalarParameterValue(FName("Sigma" + FString::FromInt(layer)), j);
		FScotomata_C s;
		if (j > 0) {
			sc.layers_active[layer] = true;
			s.Sigma = j;
			FLinearColor mean;
			mat->GetVectorParameterValue(FName("Mean" + FString::FromInt(layer)), mean);
			s.MeanColor = mean;
			mat->GetScalarParameterValue(FName("Rotation" + FString::FromInt(layer)), j);
			s.Rotation = j;
			mat->GetScalarParameterValue(FName("Distortion" + FString::FromInt(layer)), j);
			s.Distortion = j;
			mat->GetScalarParameterValue(FName("Weight" + FString::FromInt(layer)), j);
			s.Weight = j;
		}
		sc.layers.Add(s);
		
	}
	scotomas = sc;
}

void AMetamorphopsiaController::printScotomata(FScotomata_C s, FString& print_s) {
	FString ret = "Mean : ";
	ret += FString::SanitizeFloat(s.MeanColor.R) + " " + FString::SanitizeFloat(s.MeanColor.G);
	ret += "\nSigma: ";
	ret += FString::SanitizeFloat(s.Sigma);
	ret += "\nRotation: ";
	ret += FString::SanitizeFloat(s.Rotation);
	ret += "\nDistortion: ";
	ret += FString::SanitizeFloat(s.Distortion);
	ret += "\nWeight: ";
	ret += FString::SanitizeFloat(s.Weight);
	print_s = ret;
}

void AMetamorphopsiaController::fromScotoma_CtoMaterial(Eye eye, FScotoma_C scotomas, UMaterial* Left_mat, UMaterial* Right_mat, UMaterialInstanceDynamic*& mat) {
	if (eye == Eye::Left) {
		mat = UMaterialInstanceDynamic::Create(Left_mat, this);
	}
	else {
		mat = UMaterialInstanceDynamic::Create(Right_mat, this);
	}

	for (int8 i = 0; i < scotomas.layers_active.Num(); i++) {
		if (scotomas.layers_active[i]) {
			mat->SetVectorParameterValue(FName("Mean" + FString::FromInt(i)), scotomas.layers[i].MeanColor);
			mat->SetScalarParameterValue(FName("Sigma" + FString::FromInt(i)), scotomas.layers[i].Sigma);
			mat->SetScalarParameterValue(FName("Rotation" + FString::FromInt(i)), scotomas.layers[i].Rotation);
			mat->SetScalarParameterValue(FName("Distortion" + FString::FromInt(i)), scotomas.layers[i].Distortion);
			mat->SetScalarParameterValue(FName("Weight" + FString::FromInt(i)), scotomas.layers[i].Weight);
		}
	}
}

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

