// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VREYE.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, VREYE, "VREYE" );

FString UAssessmentMetrics_C::LogMARtoDecimal(float logMAR) {
	return FString::SanitizeFloat(FMath::Pow(10, -logMAR));
}

/*
UFUNCTION(BlueprintCallable)
FString LogMARtoSnellenM(float logMAR) {
	FString retSnellenM = "6/";
	retSnellenM.Append(FString::SanitizeFloat(6 / FMath::Pow(10, -logMAR)));
	return retSnellenM;
}

UFUNCTION(BlueprintCallable)
FString LogMARtoSnellenft(float logMAR) {
	FString retSnellenM = "20/";
	retSnellenM.Append(FString::SanitizeFloat(20 / FMath::Pow(10, -logMAR)));
	return retSnellenM;
}

UFUNCTION(BlueprintCallable)
FString LogCStoWeber(float logCS) {
	return FString::SanitizeFloat(100 * FMath::Pow(10, -logCS));
}

UFUNCTION(BlueprintCallable)
FString LogCStoMichelson(float logCS) {
	float weber = FMath::Pow(10, -logCS);
	return FString::SanitizeFloat((100 * weber) / (2 - weber));
}

UFUNCTION(BlueprintCallable)
FString LogMAR(float logMAR) {
	return FString::SanitizeFloat(logMAR);
}
UFUNCTION(BlueprintCallable)
FString LogCS(float logCS) {
	return FString::SanitizeFloat(logCS);
}

UFUNCTION(BlueprintCallable)
FString LogCStoWeber(float logCS) {
	return FString::SanitizeFloat(100 * FMath::Pow(10, -logCS));
}

UFUNCTION(BlueprintCallable)
float MichelsontoLogCS(float michelson) {
	return -FMath::LogX(10, 2 * michelson / (1 + michelson));
}

UFUNCTION(BlueprintCallable)
float MARtoLogMAR(float MAR) {
	return FMath::LogX(10, MAR);
}
*/