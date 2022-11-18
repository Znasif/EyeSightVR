// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../VREYE.h"
#include "opencv2/core/mat.hpp"
#include "opencv2/core.hpp"
#include "ColorCalibration.generated.h"

UCLASS()
class AColorCalibration : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AColorCalibration();
	cv::Mat XYZ_to_RGB;
	cv::Mat RGB_to_XYZ;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable, Category = "Conversion", meta = (Keywords = "OpenCV"))
		bool solve(FColor_primaries_lxy recorded);

	UFUNCTION(BlueprintCallable, Category = "Conversion", meta = (Keywords = "lxy"))
		void convertFromlxy(FColor_lxy lxy, FLinearColor& retColor);

	UFUNCTION(BlueprintCallable, Category = "Conversion", meta = (Keywords = "lxy"))
		void convertFromlxyToXYZ(FColor_lxy lxy, FColor_XYZ& retColor);

	UFUNCTION(BlueprintCallable, Category = "Conversion", meta = (Keywords = "Luv"))
		void convertFromLuv(FColor_Luv Luv, FLinearColor& retColor);

	UFUNCTION(BlueprintCallable, Category = "Conversion", meta = (Keywords = "lxy"))
		void convertFromLuvToXYZ(FColor_Luv lxy, FColor_XYZ& retColor);

	UFUNCTION(BlueprintCallable, Category = "Conversion", meta = (Keywords = "XYZ"))
		void convertFromXYZ(FColor_XYZ XYZ, FLinearColor& retColor);

	UFUNCTION(BlueprintCallable, Category = "Conversion", meta = (Keywords = "XYZ"))
		void convertFromRGB(FLinearColor RGB, FColor_XYZ& retColor);
};
