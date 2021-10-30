// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	TMap<Eye, FScotoma_C> past_meta;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TMap<Eye, FScotoma_C> meta;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	TMap <Move_Along, float> delta_vector;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	TArray <float> delta;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	TArray <float> mean_close;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	TArray <float> mean_far;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	int32 Subject_ID;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
		TArray<FAmsler_Chart_C> past_charts;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
		TArray<FAmsler_Chart_C> current_charts;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void Initiate();

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void InactiveLayers(Eye eye, TArray<int8>& idx);
	
	/*UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void CreateScotomaLayer(Eye eye, int8& layer);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void CreateMaterialfromScotoma_C(Eye eye, TArray<int32> met_layers, UMaterialInstanceDynamic& distortion_mat);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void ConvertLocationToUV(Eye eye, FVector location, FLinearColor& UV);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void UpdatePosition(Eye eye, TArray<int32> met_layers, Move_Along direction);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void UpdatePositionfromVector(Eye eye, TArray<int32> met_layers, FVector location);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void UpdateMetamorphopsia(Eye eye, int32 met_layers, int32 property);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void TrackGazeFixation(FVector GazeDirection, bool& reliable);*/
};
