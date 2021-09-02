// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "VREYE.generated.h"

USTRUCT(BlueprintType)
struct FScotoma1
{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "Scotoma")
	FLinearColor MeanColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f);
	UPROPERTY(BlueprintReadWrite, Category = "Scotoma")
	float Sigma = 0.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Scotoma")
	float Weight = 0.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Scotoma")
	float Rotation = 0.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Scotoma")
	float Distortion = 0.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Scotoma")
	float Tesselation = 0.0f;
};