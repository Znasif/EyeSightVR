// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "../VREYE.h"
#include "MetamorphopsiaController.generated.h"

UCLASS()
class VREYE_API AMetamorphopsiaController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMetamorphopsiaController();
	
	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TMap<Eye, FScotoma_C> past_meta;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TMap<Eye, FScotoma_C> meta;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TMap <Move_Along, float> delta_vector;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TArray <float> delta;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TArray <float> mean_close;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TArray <float> mean_far;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TArray <UMaterialInstanceDynamic*> simulated_distortions;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	UStaticMeshComponent* distortion_plane;

	UPROPERTY(EditAnywhere, Category = "Subject Information")
	int32 Subject_ID;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TArray<FAmsler_Chart_C> past_charts;

	UPROPERTY(BlueprintReadWrite, Category = "Subject Information")
	TArray<FAmsler_Chart_C> current_charts;

	UMaterial* StoredMaterial;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void Initiate(TArray<UMaterialInstanceDynamic*> distortion_mats, UStaticMeshComponent* plane);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void Simulate(int which_distortion);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void fromMaterialtoScotoma_C(UMaterialInstanceDynamic* mat, FScotoma_C& scotomas);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void printScotomata(FScotomata_C s, FString& print_s);

	UFUNCTION(BlueprintCallable, Category = "Update Metamorphopsia")
	void fromScotoma_CtoMaterial(Eye eye, FScotoma_C scotomas, UMaterial* Left_mat, UMaterial* Right_mat, UMaterialInstanceDynamic*& mat);
};
