// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Processing_Functional_Data.h"
#include "Essentials.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VREYE_API UEssentials : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEssentials();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(BlueprintReadWrite, Category = "Color_Plates_Info")
		TArray<FColor_info> all_plates;

	UFUNCTION(BlueprintCallable, Category = "Function")
	static void Cleareverything(FColor_info fi);
};

