// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Essentials.h"
#include "TriVectorManager.generated.h"

/**
 * 
 */
UCLASS()
class VREYE_API ATriVectorManager : public AEssentials
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "TriVector")
		TArray<FString> protan_hex;

	UPROPERTY(BlueprintReadWrite, Category = "TriVector")
		TArray<FString> deutan_hex;

	UPROPERTY(BlueprintReadWrite, Category = "TriVector")
		TArray<FString> tritan_hex;

	UPROPERTY(BlueprintReadWrite, Category = "TriVector")
		TArray<int> threshold_along_confusion_lines;

	virtual	void InitializePlates() override;

	virtual void ColorThesePlates(TArray<AStaticMeshActor*> ovalPlates, int32 coloredPlate) override;

	virtual void AssessResponses(TMap<int32, FString> responses, FString& out);

	UFUNCTION(BlueprintCallable, Category = "TriVector")
	void InitializeColors();
};
