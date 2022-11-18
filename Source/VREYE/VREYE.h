// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/UnrealMathUtility.h"
#include "opencv2/core/mat.hpp"
#include "opencv2/core.hpp"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VREYE.generated.h"


UCLASS()
class UAssessmentMetrics_C : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
		static FString LogMARtoDecimal(float logMAR);
	UFUNCTION(BlueprintCallable)
		static FString LogMARtoSnellenM(float logMAR);
	UFUNCTION(BlueprintCallable)
		static FString LogMARtoSnellenft(float logMAR);
	UFUNCTION(BlueprintCallable)
		static FString LogCStoWeber(float logCS);
	UFUNCTION(BlueprintCallable)
		static FString LogCStoMichelson(float logCS);
	UFUNCTION(BlueprintCallable)
		static FString LogMAR(float logMAR);
	UFUNCTION(BlueprintCallable)
		static FString LogCS(float logCS);
	UFUNCTION(BlueprintCallable)
		static float MichelsontoLogCS(float michelson);
	UFUNCTION(BlueprintCallable)
		static float MARtoLogMAR(float MAR);
};

UENUM(BlueprintType)
enum class Eye :uint8
{
	Left     UMETA(DisplayName = "Left"),
	Right      UMETA(DisplayName = "Right"),
	Both   UMETA(DisplayName = "Both"),
};

UENUM(BlueprintType)
enum class Move_Along :uint8
{
	Up   UMETA(DisplayName = "Up"),
	Left     UMETA(DisplayName = "Left"),
	Right      UMETA(DisplayName = "Right"),
	Down   UMETA(DisplayName = "Down"),
};

USTRUCT(BlueprintType)
struct FScotomata_C
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "Scotomata")
		FLinearColor MeanColor = FLinearColor(0.5f, 0.5f, 0.0f, 0.0f);
	UPROPERTY(BlueprintReadWrite, Category = "Scotomata")
		float Sigma = 0.015f;
	UPROPERTY(BlueprintReadWrite, Category = "Scotomata")
		float Weight = 0.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Scotomata")
		float Rotation = 0.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Scotomata")
		float Distortion = 0.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Scotomata")
		FLinearColor Boundary = FLinearColor::Black;
	UPROPERTY(BlueprintReadWrite, Category = "Scotomata")
		float Tesselation = 0.0f;
};

USTRUCT(BlueprintType)
struct FScotoma_C {
	GENERATED_USTRUCT_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "Scotoma")
		TArray<FScotomata_C> layers;

	UPROPERTY(BlueprintReadWrite, Category = "Scotoma")
		TArray<bool> layers_active = {false, false, false};
};

USTRUCT(BlueprintType)
struct FPatient_Assessment_C
{
	GENERATED_USTRUCT_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "Patient_Assessment")
		bool StaticVAValid = false;
	UPROPERTY(BlueprintReadWrite, Category = "Patient_Assessment")
		bool DynamicVAValid = false;
	UPROPERTY(BlueprintReadWrite, Category = "Patient_Assessment")
		bool CSValid = false;
	UPROPERTY(BlueprintReadWrite, Category = "Patient_Assessment")
		bool ScotomaParametersValid = false;
	UPROPERTY(BlueprintReadWrite, Category = "Patient_Assessment")
		TMap<FString, float> StaticVA;
	UPROPERTY(BlueprintReadWrite, Category = "Patient_Assessment")
		float DynamicVA = 0.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Patient_Assessment")
		float CS = 0.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Patient_Assessment")
		TArray<FScotoma_C> ScotomaParameters;
	UPROPERTY(BlueprintReadWrite, Category = "Patient_Assessment")
		FDateTime Time;
};

USTRUCT(BlueprintType)
struct FPatient_C {
	GENERATED_USTRUCT_BODY()
	UPROPERTY(BlueprintReadWrite, Category = "Patient")
		FString Name = "John Doe";
	UPROPERTY(BlueprintReadWrite, Category = "Patient")
		int32 ID = 0;
	UPROPERTY(BlueprintReadWrite, Category = "Patient")
		int32 Age = 25;
	UPROPERTY(BlueprintReadWrite, Category = "Patient")
		FString Sex = "Male";
	UPROPERTY(BlueprintReadWrite, Category = "Patient")
		FPatient_Assessment_C Assessments;
};


USTRUCT(BlueprintType)
struct FAmsler_Chart_C {
	GENERATED_USTRUCT_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "Amsler Grid")
		float GridThickness = 0.02;
	UPROPERTY(BlueprintReadWrite, Category = "Amsler Grid")
		int32 Lines = 5;
	UPROPERTY(BlueprintReadWrite, Category = "Amsler Grid")
		float scale = 4.0f;
	UPROPERTY(BlueprintReadWrite, Category = "Amsler Grid")
		FLinearColor BackgroundColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f);
	UPROPERTY(BlueprintReadWrite, Category = "Amsler Grid")
		FLinearColor LineColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.0f);
};

USTRUCT(BlueprintType)
struct FColor_lxy
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "Luminance in cd/m2")
		float l;
	UPROPERTY(BlueprintReadWrite, Category = "chromaticity x")
		float x;
	UPROPERTY(BlueprintReadWrite, Category = "chromaticity y")
		float y;
};

USTRUCT(BlueprintType)
struct FColor_Luv
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "Luminance in cd/m2")
		float L;
	UPROPERTY(BlueprintReadWrite, Category = "u")
		float u;
	UPROPERTY(BlueprintReadWrite, Category = "v")
		float v;
};

USTRUCT(BlueprintType)
struct FColor_XYZ
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "Tristimulus")
		float X;
	UPROPERTY(BlueprintReadWrite, Category = "Tristimulus")
		float Y;
	UPROPERTY(BlueprintReadWrite, Category = "Tristimulus")
		float Z;
};

USTRUCT(BlueprintType)
struct FColor_primaries_lxy
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "Red")
		FColor_lxy Red;
	UPROPERTY(BlueprintReadWrite, Category = "Red")
		FColor_lxy Green;
	UPROPERTY(BlueprintReadWrite, Category = "Red")
		FColor_lxy Blue;
	UPROPERTY(BlueprintReadWrite, Category = "Red")
		FColor_lxy White;
};