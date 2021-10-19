// Fill out your copyright notice in the Description page of Project Settings.


#include "Essentials.h"

// Sets default values for this component's properties
UEssentials::UEssentials()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
	FColor_info c_info;

	// 12
	c_info.background_color.Add(FLinearColor(145, 155, 144, 0));
	c_info.normal_color.Add(FLinearColor(145, 155, 144, 0));
	c_info.normal_f = { 49,51,52,53,54,55,81,82,83,84,85,86,87,88,90,125,126,127,131,137,138,139,176,178,179,180,181,182,183,184,185,197,198,199,200,201,268,269,270 };
	c_info.normal_s = { 20,30,31,32,33,34,39,40,41,42,61,62,63,69,70,74,77,78,94,95,98,99,100,106,107,108,109,110,111,120,121,149,150,151,157,158,165,166,167,169,210,211,211,214,219,220,221,222,223,224,225,230,231,232,233,234,235,287,288,290,291,292,293,303,304,305,306,307,308,309,310,311,312,313,314,315 };

	all_plates.Add(c_info);
	Cleareverything(c_info);

}

void UEssentials::Cleareverything(FColor_info fi)
{
	// Set complete file path
	fi.background_color.Empty();
	fi.normal_color.Empty();
	fi.cvd_color.Empty();
	fi.invisible_color.Empty();
	fi.normal_f.Empty();
	fi.cvd_f.Empty();
	fi.invisible_f.Empty();

	fi.normal_s.Empty();
	fi.cvd_s.Empty();
	fi.invisible_s.Empty();
}


// Called when the game starts
void UEssentials::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEssentials::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

