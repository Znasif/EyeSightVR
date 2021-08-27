// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Processing_Functional_Data.generated.h"

/**
 * 
 */
UCLASS()
class VREYE_API UProcessing_Functional_Data : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Load"))
	static bool LoadTextFromFile(FString FileName, TArray<FString>& TextArray, FString& TextString);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Save"))
	static bool SaveArrayText(FString SaveDirectory, FString FileName, TArray<FString> SaveText, bool AllowOverwriting);

	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Save"))
	static bool DeleteTextFile(FString SaveDirectory, FString FileName);
};
