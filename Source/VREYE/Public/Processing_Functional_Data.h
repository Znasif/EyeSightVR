// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Processing_Functional_Data.generated.h"

/*
*
* 
*/

UCLASS()
class VREYE_API UProcessing_Functional_Data : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Load"))
	static bool LoadTextFromFile(FString FileName, TArray<FString>& TextArray, FString& TextString);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Save"))
	static bool SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverwriting);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Save"))
	static bool DeleteTextFile(FString SaveDirectory, FString FileName);
};

USTRUCT(BlueprintType)
struct FColor_info
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(BlueprintReadWrite, Category = "Color_Plate_Info")
		TArray<FLinearColor> background_color;
	UPROPERTY(BlueprintReadWrite, Category = "Color_Plate_Info")
		TArray<FLinearColor> normal_color;
	UPROPERTY(BlueprintReadWrite, Category = "Color_Plate_Info")
		TArray<FLinearColor> cvd_color;
	UPROPERTY(BlueprintReadWrite, Category = "Color_Plate_Info")
		TArray<FLinearColor> invisible_color;
	UPROPERTY(BlueprintReadWrite, Category = "Color_Plate_Info")
		TArray<int32> normal_f;
	UPROPERTY(BlueprintReadWrite, Category = "Color_Plate_Info")
		TArray<int32> normal_s;
	UPROPERTY(BlueprintReadWrite, Category = "Color_Plate_Info")
		TArray<int32> cvd_f;
	UPROPERTY(BlueprintReadWrite, Category = "Color_Plate_Info")
		TArray<int32> cvd_s;
	UPROPERTY(BlueprintReadWrite, Category = "Color_Plate_Info")
		TArray<int32> invisible;
	UPROPERTY(BlueprintReadWrite, Category = "Color_Plate_Info")
		TArray<FString> validResponses;
};
