// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Processing_Functional_Data.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "../VREYE.h"
#include "MetamorphopsiaController.generated.h"

UCLASS()
class VREYE_API AMetamorphopsiaController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMetamorphopsiaController();

	UPROPERTY(EditAnywhere, Category = "Subject Information")
		TArray <float> min_limit = {0.0f, 0.0f, -180.0f, -1.0f, 0.0f};

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	TArray <float> max_limit = { 1.0f, 1.0f, 180.0f, 1.0f, 1.0f };

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TArray <float> mean_close;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TArray <float> mean_far;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TArray <UMaterialInstanceDynamic*> simulated_distortions;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	int32 Subject_ID;

	UMaterial* StoredMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void Initiate(TArray<UMaterialInstanceDynamic*> distortion_mats);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void Simulate(int which_distortion, UStaticMeshComponent* distortion_plane);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void fromMaterialtoScotoma_C(Eye eye, UMaterialInstanceDynamic* mat, FScotoma_C& scotomas);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void printScotomata(FScotomata_C s, FString& print_s);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void fromScotoma_CtoMaterial(Eye eye, bool monocular, FScotoma_C scotomas, UStaticMeshComponent* distortion_plane, UMaterial* bin_mat, UMaterialInstanceDynamic*& mat);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void manipulationLayer(FScotoma_C replica, int32& which_layer, FScotoma_C& out);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void move_location(FScotoma_C sc, TArray<int32> which_layers, Move_Along direction, float val, FScotoma_C& out);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void alter_scotoma_property(FScotoma_C sc, int32 which_layer, int32 which_property, float val, FScotoma_C& out);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void save_patientData(TArray<FScotomata_C> arr_sc, bool simulation);
};
