// Fill out your copyright notice in the Description page of Project Settings.


#include "MetamorphopsiaController.h"

// Sets default values
AMetamorphopsiaController::AMetamorphopsiaController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMetamorphopsiaController::Initiate() {
	for (int32 i = 0; i < past_meta_l.Num(); i++) {
		meta_l.Add(past_meta_l[i]);
	}
	for (int32 i = 0; i < past_meta_r.Num(); i++) {
		meta_r.Add(past_meta_l[i]);
	}
}

FLinearColor AMetamorphopsiaController::ConvertLocationToUV(Eye eye, FVector location) {
	return FLinearColor::Red;
}

void AMetamorphopsiaController::UpdatePosition(Eye eye, int32 layer, FVector location, Move_Along direction) {
	FLinearColor updated;
	if (eye == Eye::Left) {
		updated = ConvertLocationToUV(eye, location);
		switch (direction)
		{
		case Move_Along::Left:
			meta_l[layer].MeanColor.R = meta_l[layer].MeanColor.R+delta[0];
			break;
		default:
			break;
		}
	}
}

void AMetamorphopsiaController::UpdateMetamorphopsia(Eye eye, int32 layer, int32 property) {

}

// Called when the game starts or when spawned
void AMetamorphopsiaController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMetamorphopsiaController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

