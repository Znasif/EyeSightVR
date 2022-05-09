// Fill out your copyright notice in the Description page of Project Settings.


#include "VoiceChat.h"

// Sets default values
AVoiceChat::AVoiceChat()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVoiceChat::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AVoiceChat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

