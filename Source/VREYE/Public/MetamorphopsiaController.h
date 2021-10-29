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
	TArray<FScotoma_C> past_meta_l;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TArray<FScotoma_C> meta_l;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	TArray<FScotoma_C> past_meta_r;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TArray<FScotoma_C> meta_r;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	TArray <float> delta_vector;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	TArray <float> delta;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	TArray <float> mean_close;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	TArray <float> mean_far;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	int32 Subject_ID;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	FLinearColor ConvertLocationToUV(Eye eye, FVector location);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void UpdatePosition(Eye eye, int32 layer, FVector location, Move_Along direction);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void UpdateMetamorphopsia(Eye eye, int32 layer, int32 property);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void Initiate();
};
