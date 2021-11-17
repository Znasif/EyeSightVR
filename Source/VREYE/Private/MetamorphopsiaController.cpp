// Fill out your copyright notice in the Description page of Project Settings.


#include "MetamorphopsiaController.h"

#define MAX_LAYERS 3

// Sets default values
AMetamorphopsiaController::AMetamorphopsiaController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMetamorphopsiaController::Initiate(TArray<UMaterialInstanceDynamic*> distortion_mats) {
	//get scotoma values from past_meta into meta
	simulated_distortions = distortion_mats;
	
	//create material instance from current meta

	//adjust chart based on past chart info

	//set the material to the chart
}

void AMetamorphopsiaController::Simulate(int which_distortion, UStaticMeshComponent* distortion_plane) {
	simulated_distortions[which_distortion]->SetScalarParameterValue(FName("monocular_l"), 1.0f);
	simulated_distortions[which_distortion]->SetScalarParameterValue(FName("monocular_r"), 0.0f);
	distortion_plane->SetMaterial(0, simulated_distortions[which_distortion]);
}

void AMetamorphopsiaController::fromMaterialtoScotoma_C(Eye eye, UMaterialInstanceDynamic* mat, FScotoma_C& scotomas) {
	float j;
	FScotoma_C sc;
	TMap<Eye, FString> prefix_mat = { {Eye::Left, "Left_"}, {Eye::Right, "Right_"} };

	for (int8 layer = 0; layer < MAX_LAYERS; layer++) {
		mat->GetScalarParameterValue(FName(prefix_mat[eye] + "Sigma" + FString::FromInt(layer)), j);
		FScotomata_C s;
		if (j > 0) {
			sc.layers_active[layer] = true;
			s.Sigma = j;
			FLinearColor mean;
			mat->GetVectorParameterValue(FName(prefix_mat[eye] + "Mean" + FString::FromInt(layer)), mean);
			s.MeanColor = mean;
			mat->GetScalarParameterValue(FName(prefix_mat[eye] + "Rotation" + FString::FromInt(layer)), j);
			s.Rotation = j;
			mat->GetScalarParameterValue(FName(prefix_mat[eye] + "Distortion" + FString::FromInt(layer)), j);
			s.Distortion = j;
			mat->GetScalarParameterValue(FName(prefix_mat[eye] + "Weight" + FString::FromInt(layer)), j);
			s.Weight = j;
			mat->GetVectorParameterValue(FName(prefix_mat[eye] + "Boundary" + FString::FromInt(layer)), mean);
			s.Boundary = mean;
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

void AMetamorphopsiaController::fromScotoma_CtoMaterial(Eye eye, bool post, FScotoma_C scotomas, UStaticMeshComponent* distortion_plane, UMaterial* bin_mat, UMaterialInstanceDynamic*& mat) {
	mat = UMaterialInstanceDynamic::Create(bin_mat, this);
	TMap<Eye, FString> prefix_mat = { {Eye::Left, "Left_"}, {Eye::Right, "Right_"} };
	TMap<Eye, FString> monocular_prefix = { {Eye::Left, "monocular_r"}, {Eye::Right, "monocular_l"} };

	mat->SetScalarParameterValue(FName("monocular_l"), 1.0f);
	mat->SetScalarParameterValue(FName("monocular_r"), 1.0f);
	if (post) {
		mat->SetScalarParameterValue(FName(monocular_prefix[eye]), 0.0f);
		for (int8 i = 0; i < scotomas.layers_active.Num(); i++) {
			if (scotomas.layers_active[i]) {
				mat->SetVectorParameterValue(FName(prefix_mat[eye] + "Mean" + FString::FromInt(i)), scotomas.layers[i].MeanColor);
				mat->SetScalarParameterValue(FName(prefix_mat[eye] + "Sigma" + FString::FromInt(i)), scotomas.layers[i].Sigma);
				mat->SetScalarParameterValue(FName(prefix_mat[eye] + "Rotation" + FString::FromInt(i)), scotomas.layers[i].Rotation);
				mat->SetScalarParameterValue(FName(prefix_mat[eye] + "Distortion" + FString::FromInt(i)), scotomas.layers[i].Distortion);
				mat->SetScalarParameterValue(FName(prefix_mat[eye] + "Weight" + FString::FromInt(i)), scotomas.layers[i].Weight);
				mat->SetVectorParameterValue(FName(prefix_mat[eye] + "Boundary" + FString::FromInt(i)), scotomas.layers[i].Boundary);
			}
		}
		if (distortion_plane) distortion_plane->SetMaterial(0, mat);
	}
	else {
		FLinearColor temp_mean;
		float temp_float;
		mat->SetScalarParameterValue(FName(monocular_prefix[eye]), 0.0f);
		for (int8 i = 0; i < scotomas.layers_active.Num(); i++) {
			if (scotomas.layers_active[i]) {
				temp_mean = scotomas.layers[i].MeanColor;
				mat->SetVectorParameterValue(FName(prefix_mat[eye] + "Mean" + FString::FromInt(i)), temp_mean);
				temp_float = scotomas.layers[i].Sigma;
				mat->SetScalarParameterValue(FName(prefix_mat[eye] + "Sigma" + FString::FromInt(i)), temp_float);
				temp_float = scotomas.layers[i].Rotation;
				mat->SetScalarParameterValue(FName(prefix_mat[eye] + "Rotation" + FString::FromInt(i)), temp_float);
				temp_float = scotomas.layers[i].Distortion;
				mat->SetScalarParameterValue(FName(prefix_mat[eye] + "Distortion" + FString::FromInt(i)), temp_float);
				mat->SetScalarParameterValue(FName(prefix_mat[eye] + "Weight" + FString::FromInt(i)), scotomas.layers[i].Weight);
				mat->SetVectorParameterValue(FName(prefix_mat[eye] + "Boundary" + FString::FromInt(i)), scotomas.layers[i].Boundary);
			}
		}
		TArray<FWeightedBlendable> postArray;
		postArray.Add(FWeightedBlendable(1.0, mat));
		FPostProcessSettings postSetting;
		postSetting.WeightedBlendables = postArray;
		camera->PostProcessSettings = postSetting;
	}
}

void AMetamorphopsiaController::manipulationLayer(FScotoma_C replica, int32& which_layer, FScotoma_C& out) {
	int8 i=0;

	which_layer = -1;

	FScotoma_C sc;

	for (i = 0; i < replica.layers_active.Num(); i++) {
		if (replica.layers_active[i]) {
			sc.layers_active[i] = true;
			sc.layers.Add(replica.layers[i]);
		}
		else {
			sc.layers_active[i] = true;

			FScotomata_C new_sc;
			new_sc.MeanColor = FLinearColor(0.5f, 0.5f, 0.0f, 1.0f);
			new_sc.Sigma = 0.01f;
			new_sc.Rotation = 0.0f;
			new_sc.Distortion = 0.0f;
			new_sc.Weight = 1.0;
			which_layer = i;

			sc.layers.Add(new_sc);
			break;
		}
	}

	out = sc;
}

void AMetamorphopsiaController::move_location(FScotoma_C sc, TArray<int32> which_layers, Move_Along direction, float val, FScotoma_C& out) {
	for (int8 i = 0; i < which_layers.Num(); i++)
	{
		switch (direction)
		{
		case Move_Along::Up:
			sc.layers[which_layers[i]].MeanColor.G -= val/500;
			break;
		case Move_Along::Left:
			sc.layers[which_layers[i]].MeanColor.R += val/500;
			break;
		case Move_Along::Right:
			sc.layers[which_layers[i]].MeanColor.R += val/500;
			break;
		case Move_Along::Down:
			sc.layers[which_layers[i]].MeanColor.G -= val/500;
			break;
		default:
			break;
		}
	}
	out = sc;
}

void AMetamorphopsiaController::alter_scotoma_property(FScotoma_C sc, int32 which_layer, int32 which_property, float val, FScotoma_C& out) {	
	float temp;
	if (sc.layers_active[which_layer]) {
		switch (which_property)
		{
		case 1:
			temp = sc.layers[which_layer].Sigma + val * 0.001f;
			if (min_limit[1] < temp && max_limit[1] > temp) sc.layers[which_layer].Sigma = temp;
			sc.layers[which_layer].Weight = 1.0;
			sc.layers[which_layer].Boundary = FLinearColor::Red;
			break;
		case 2:
			sc.layers[which_layer].Weight = 0.0;
			temp = sc.layers[which_layer].Rotation + val * 1.0f;
			if (min_limit[2] < temp && max_limit[2] > temp) sc.layers[which_layer].Rotation = temp;
			break;
		case 3:
			sc.layers[which_layer].Weight = 0.0;
			temp = sc.layers[which_layer].Distortion + val * 0.01f;
			if (min_limit[3] < temp && max_limit[3] > temp) sc.layers[which_layer].Distortion = temp;
			break;
		case 4:
			sc.layers[which_layer].Boundary = FLinearColor::Black;
			temp = sc.layers[which_layer].Weight + val * 0.15f;
			if (min_limit[4] < temp && max_limit[4] > temp) sc.layers[which_layer].Weight = temp;
			break;
		default:
			break;
		}
	}
	else {
		manipulationLayer(sc, which_layer, sc);
	}
	out = sc;
}

void AMetamorphopsiaController::save_patientData(TArray<FScotomata_C> arr_sc, bool simulation) {
	TArray<FString> modeling_responses = { "Example Scotoma, Measure Mean.X, Measured Mean.Y, Measured Size, Measured Rotational Distortion, Spatial Distortion" };

	for (int8 i = 0; i < arr_sc.Num(); i++)
	{
		FString temp = FString::FromInt(i)+",";
		temp += FString::SanitizeFloat(arr_sc[i].MeanColor.R) + "," + FString::SanitizeFloat(arr_sc[i].MeanColor.G) +",";
		temp += FString::SanitizeFloat(arr_sc[i].Sigma) + ",";
		temp += FString::SanitizeFloat(arr_sc[i].Rotation) + ",";
		temp += FString::SanitizeFloat(arr_sc[i].Distortion) + ",";
		modeling_responses.Add(temp);
	}
	
	UProcessing_Functional_Data::SaveArrayText("E:\\Unreal Projects\\VREYE\\Saved\\Processed_Data", "current_data.csv", modeling_responses, true);
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

