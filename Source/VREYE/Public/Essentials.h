// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/StaticMeshActor.h"
#include "Processing_Functional_Data.h"
#include "Essentials.generated.h"

UCLASS()
class VREYE_API AEssentials : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	AEssentials();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadWrite, Category = "Color_Plates_Info")
	TArray<FColor_info> all_plates;

	UFUNCTION(BlueprintCallable, Category = "Function")
	static void Cleareverything(FColor_info &fi);

	UFUNCTION(BlueprintCallable, Category = "Function")
	void InitializePlates();


	UFUNCTION(BlueprintCallable, Category = "Function")
	void ColorThesePlates(TArray<AStaticMeshActor*> ovalPlates, int32 coloredPlate);

	UFUNCTION(BlueprintCallable, Category = "Function")
	void AssessResponses(TMap<int32, FString> responses, FString& out);
};

