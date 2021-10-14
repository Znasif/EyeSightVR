// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VREYE.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, VREYE, "VREYE" );

FString UAssessmentMetrics_C::LogMARtoDecimal(float logMAR) {
	return FString::SanitizeFloat(FMath::Pow(10, -logMAR));
}


FString UAssessmentMetrics_C::LogMARtoSnellenM(float logMAR) {
	FString retSnellenM = "6/";
	retSnellenM.Append(FString::SanitizeFloat(6 / FMath::Pow(10, -logMAR)));
	return retSnellenM;
}

FString UAssessmentMetrics_C::LogMARtoSnellenft(float logMAR) {
	FString retSnellenM = "20/";
	retSnellenM.Append(FString::SanitizeFloat(20 / FMath::Pow(10, -logMAR)));
	return retSnellenM;
}

FString UAssessmentMetrics_C::LogCStoWeber(float logCS) {
	return FString::SanitizeFloat(100 * FMath::Pow(10, -logCS));
}

FString UAssessmentMetrics_C::LogCStoMichelson(float logCS) {
	float weber = FMath::Pow(10, -logCS);
	return FString::SanitizeFloat((100 * weber) / (2 - weber));
}

FString UAssessmentMetrics_C::LogMAR(float logMAR) {
	return FString::SanitizeFloat(logMAR);
}

FString UAssessmentMetrics_C::LogCS(float logCS) {
	return FString::SanitizeFloat(logCS);
}

float UAssessmentMetrics_C::MichelsontoLogCS(float michelson) {
	return -FMath::LogX(10, 2 * michelson / (1 + michelson));
}

float UAssessmentMetrics_C::MARtoLogMAR(float MAR) {
	return FMath::LogX(10, MAR);
}