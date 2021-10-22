// Fill out your copyright notice in the Description page of Project Settings.


#include "Essentials.h"

// Sets default values for this component's properties
AEssentials::AEssentials()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryActorTick.bCanEverTick = true;

}

void AEssentials::Cleareverything(FColor_info &fi)
{
	// Set complete file path
	fi.background_color.Empty();
	fi.normal_color.Empty();
	fi.cvd_color.Empty();
	fi.invisible_color.Empty();
	fi.normal_f.Empty();
	fi.cvd_f.Empty();
	fi.invisible.Empty();

	fi.normal_s.Empty();
	fi.cvd_s.Empty();
	fi.validResponses.Empty();
}

void AEssentials::InitializePlates()
{
	FColor_info c_info;

	// 12
	c_info.background_color.Add(FLinearColor(FColor(145, 155, 144, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(246, 93, 36, 1)));
	c_info.normal_f = { 49,51,52,53,54,55,82,83,84,85,86,87,88,90,125,126,127,137,138,139,176,178,179,180,181,182,183,197,198,199,200,201,268,269,270,353 };
	c_info.normal_s = { 20,30,31,32,33,34,39,40,41,42,61,62,63,69,70,74,77,78,94,95,98,99,100,106,107,108,109,110,111,120,121,149,150,151,157,158,165,166,167,169,210,211,211,214,219,220,221,222,223,224,225,230,231,232,233,234,235,287,288,290,291,292,293,303,304,305,306,307,308,309,310,311,312,313,314,315 };
	c_info.cvd_f = {};
	c_info.cvd_s = {};
	c_info.invisible = {};
	c_info.validResponses = {"12", "12", "12", "12", "12"};
	all_plates.Add(c_info);
	Cleareverything(c_info);


	// 8-3
	c_info.background_color.Add(FLinearColor(FColor(190, 163, 87, 1)));
	c_info.background_color.Add(FLinearColor(FColor(147, 127, 56, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(232, 155, 103, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(191, 99, 45, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(227, 161, 137, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(208, 115, 116, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(136, 137, 82, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(197, 194, 114, 1)));
	c_info.normal_f = { 1,6,18,19,33,34,35,36,37,38,65,66,67,71,72,73,81,99,100,101,102,114,115,116,117,118,119,124,125,139,146,147,148,149,150,151,161,162,163,164,165,174,175,176,198,199,200,206,207,208,209,210,211,229,235,236,237,238,239,240,241,269,270,271,272,273,275,276,277,278,279,280,281,284,321,322,323,355,358,359,361 };
	c_info.normal_s = {};
	c_info.cvd_f = { 2,9,10,11,12,23,24,25,26,47,48,49,50,54,55,82,87,88,90,136,137,138,196,197,266 };
	c_info.cvd_s = {};
	c_info.invisible = { 45,80,91,140,201 };
	c_info.validResponses = { "8-", "3-", "3-", "3-", "3-" };
	all_plates.Add(c_info);
	Cleareverything(c_info);


	//29-70
	c_info.background_color.Add(FLinearColor(FColor(139, 120, 49, 1)));
	c_info.background_color.Add(FLinearColor(FColor(206, 179, 103, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(232, 145, 97, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(196, 104, 49, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(206, 113, 114, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(214, 148, 124, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(136, 137, 82, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(213, 199, 142, 1)));
	c_info.normal_f = { 2,9,10,11,12,22,25,26,46,45,44,54,56,79,80,91,94,128,129,140,142,185,195,199,200,201,202,265,267,270,271,272,273,350,352,353,457,458 };
	c_info.normal_s = { 18,34,35,36,37,38,63,64,68,69,98,99,104,105,106,107,108,110,156,157,205 };
	c_info.cvd_f = { 18,34,35,36,37,38,47,55,63,64,68,69,80,88,98,99,104,105,106,107,108,110,122,123,124,125,136,156,157,178,179,180,182,183,184,186,196,198,205,247,248,249,250,251,252,253,266,268,269,354,355 };
	c_info.cvd_s = { 19,20,37,39,40,62,73,74,75,76,95,96,97,118,119,145,146,153,154,155,163,164,207,208,211,212,213,214,215,216,217,218,219,220,223,228,229,230,231,284,285,286,287,288,289,292,293,301,302,303,304,305,306,307,310,311,312,313,314 };
	c_info.invisible = { 5,6,7,16,17,18,23,24,30,31,32,48,49,50,51,52,53,81,86,87,126,138,139,171,172,173,181,197 };
	c_info.validResponses = { "29", "70", "70", "70", "70" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//5-2
	c_info.background_color.Add(FLinearColor(FColor(225, 124, 81, 1)));
	c_info.background_color.Add(FLinearColor(FColor(205, 87, 50, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(143, 116, 40, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(205, 180, 96, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(127, 141, 98, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(186, 189, 126, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(219, 153, 129, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(185, 85, 80, 1)));
	c_info.normal_f = { 2,7,8,9,10,11,12,20,21,24,25,34,35,66,67,68,69,80,101,102,103,105,106,107,119,120,121,122,123,149,150,151,152,166,167,168,169,170,171,172,173,202,203,204,205,206,207,211,211,232,273,274,276,278,279,284,317 };
	c_info.normal_s = {};
	c_info.cvd_f = { 19,23,24,35,36,37,46,45,47,70,92,93,140,141,142,147,148,164,165,174,199,200,201,208,209,210,233,235,239,240,270,271 };
	c_info.cvd_s = {};
	c_info.invisible = { 4,5,6,14,15,16,17,18,28,29,48,49,50,57,58,61,62,71,81,82,94,95,96,97,98,112,114,115,116,117,124,125,126,143,144,145,146,160,161,162,163,175,176,226,227,228,229,230,231,234,236,237,241,319,320,321,322,323,358 };
	c_info.validResponses = { "5-", "2-", "2-", "2-", "2-" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//3-5
	c_info.background_color.Add(FLinearColor(FColor(201, 84, 38, 1)));
	c_info.background_color.Add(FLinearColor(FColor(239, 153, 112, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(150, 125, 40, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(208, 181, 105, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(128, 143, 100, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(166, 175, 118, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(170, 70, 65, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(223, 157, 133, 1)));
	c_info.normal_f = { 7,8,20,37,38,47,71,72,73,80,81,114,116,117,118,123,124,161,162,163,174,175,234,236,237,238,239,240,319,320,321,322,323,324,325 };
	c_info.normal_s = {};
	c_info.cvd_f = { 1,2,3,6,12,13,18,19,34,35,45,44,66,67,68,69,79,91,101,102,103,119,122,138,139,140,146,148,149,150,151,152,164,165,166,197,198,199,200,201,204,206,207,208,209,210,211,228,229,230,231,233,235,269,270,271,272,273,274,275,276,277,278,279,280,281,284,355 };
	c_info.cvd_s = {};
	c_info.invisible = { 9,10,11,12,22,46,44,166,167,168,169,170,171,172,173,232,315 };
	c_info.validResponses = { "3-", "5-", "5-", "5-", "5-" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//15-17
	c_info.background_color.Add(FLinearColor(FColor(199, 81, 43, 1)));
	c_info.background_color.Add(FLinearColor(FColor(251, 164, 124, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(175, 149, 72, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(159, 133, 56, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(134, 149, 105, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(184, 190, 121, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(188, 88, 83, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(220, 154, 130, 1)));
	c_info.normal_f = { 48,49,50,51,52,53,54,55,81,82,83,85,86,87,88,89,90,124,125,126,127,128,137,138,139,175,181,184,185,197,198,199,269,270,271,272,273,354,355,356,357,358,458,459,460,461,532 };
	c_info.normal_s = { 76,77,108,109,110,111,118,119,120,162,163,164,166,207,208,225,226,227,228,229,230,284,307,308,309,310,311,312,313 };
	c_info.cvd_f = {};
	c_info.cvd_s = { 6,7,19,20,21,30,36,37,41,59,60,61,62,70,93,94,95,96,104,105,112,142,143,144,145,153,154,155,156,204,205,206,211,212,213,285,286,287,288,289 };
	c_info.invisible = { 67,68,69,99,100,101,102,106,107,113,147,148,149,150,151,158,159,208,209,221,222,224 };
	c_info.validResponses = { "15", "17", "17", "17", "17" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//74-21
	c_info.background_color.Add(FLinearColor(FColor(205, 87, 49, 1)));
	c_info.background_color.Add(FLinearColor(FColor(239, 152, 112, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(148, 123, 38, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(210, 185, 98, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(128, 142, 99, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(188, 190, 127, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(218, 153, 128, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(181, 81, 76, 1)));
	c_info.normal_f = { 23,24,25,47,50,51,52,53,81,86,87,90,126,127,134,138,139,181,197,248,250,333,348,334,350,335,352,355,356,357 };
	c_info.normal_s = { 4,5,6,15,16,17,19,29,30,31,32,33,37,38,59,63,64,65,66,67,100,101,150,154,203,214,215,295,296,298,300 };
	c_info.cvd_f = { 25,46,45,54,55,69,79,80,88,122,123,124,125,136,137,175,178,179,180,182,183,186,187,188,196,197,198,199,246,247,249,251,252,253,266,268,269,270,271,354 };
	c_info.cvd_s = { 71,72,92,102,103,104,105,108,109,110,111,113,114,116,117,151,152,153,156,157,158,159,160,161,162,208,209,210,211,211,212,221,222,224,225,226,227,228,285,286,287,289,307,310,311,312,313,314,374,376,405 };
	c_info.invisible = { 2,3,8,9,10,11,12,13,21,22,26,41,42,43,44,56,78,128,129,130,184,185,189,195,200,201,202,203,265,267,271,291,353,457,458,459,461,608 };
	c_info.validResponses = { "74", "21", "21", "21", "21" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//6
	c_info.background_color.Add(FLinearColor(FColor(207, 180, 111, 1)));
	c_info.background_color.Add(FLinearColor(FColor(135, 106, 46, 1)));
	c_info.background_color.Add(FLinearColor(FColor(134, 145, 126, 1)));
	c_info.background_color.Add(FLinearColor(FColor(185, 175, 140, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(238, 159, 116, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(195, 93, 50, 1)));
	c_info.normal_f = { 1,2,3,4,5,6,12,13,18,19,25,26,33,34,35,48,49,50,51,52,53,54,55,56,57,65,66,67,72,73,81,82,83,84,85,86,87,88,89,90,91,100,101,102,114,115,116,117,118,123,124,125,126,127,129,131,137,138,139,149,150,151,159,160,161,162,163,164,165,167,175,197,198,199,200,206,207,208,209,210,211,226,227,228,229,230,235,236,237,238,269,270,271,273,274,275,276,277,278,279,280,281,283,284,285 };
	c_info.normal_s = {};
	c_info.cvd_f = {};
	c_info.cvd_s = {};
	c_info.invisible = {};
	c_info.validResponses = { "6", "0-", "0-", "0-", "0-" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//45
	c_info.background_color.Add(FLinearColor(FColor(150, 121, 61, 1)));
	c_info.background_color.Add(FLinearColor(FColor(130, 99, 48, 1)));
	c_info.background_color.Add(FLinearColor(FColor(190, 181, 145, 1)));
	c_info.background_color.Add(FLinearColor(FColor(136, 146, 127, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(198, 96, 53, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(240, 162, 118, 1)));
	c_info.normal_f = { 11,12,16,23,24,25,26,29,30,46,47,48,49,51,56,57,58,59,60,80,81,82,83,84,90,91,92,123,124,129,130,132,133,135,137,138,139,140,141,142,173,175,189,191,193,194,195,196,197,200,201,202,203,261,262,263,264,265,271,272,273,274,347,348,349,355,357,358 };
	c_info.normal_s = { 36,63,70,71,72,73,74,75,76,97,98,99,109,110,111,114,117,118,119,146,147,148,154,155,156,157,158,162,163,164,208,213,214,215,216,217,218,219,227,228,229,230,284,285,286,288,289,290,291,292,293,302,309,310,311,312,313,374,404 };
	c_info.cvd_f = {};
	c_info.cvd_s = {};
	c_info.invisible = {};
	c_info.validResponses = { "45", "0-", "0-", "0-", "0-" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//5
	c_info.background_color.Add(FLinearColor(FColor(244, 153, 137, 1)));
	c_info.background_color.Add(FLinearColor(FColor(194, 59, 58, 1)));
	c_info.background_color.Add(FLinearColor(FColor(251, 155, 32, 1)));
	c_info.background_color.Add(FLinearColor(FColor(253, 185, 30, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(180, 184, 113, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(127, 109, 86, 1)));
	c_info.normal_f = { 7,8,9,10,11,19,20,21,24,25,34,35,36,37,47,48,50,51,52,65,66,67,68,69,80,81,91,97,99,100,101,102,120,121,122,123,124,139,140,146,147,148,149,150,151,165,166,167,168,169,170,171,172,173,174,175,176,199,200,201,202,203,204,205,206,208,209,234,236,237,238,239,240,241,270,271,273,274,276,278,279,317,318 };
	c_info.normal_s = {};
	c_info.cvd_f = {};
	c_info.cvd_s = {};
	c_info.invisible = {};
	c_info.validResponses = { "5", "0-", "0-", "0-", "0-" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//7
	c_info.background_color.Add(FLinearColor(FColor(246, 148, 135, 1)));
	c_info.background_color.Add(FLinearColor(FColor(172, 58, 42, 1)));
	c_info.background_color.Add(FLinearColor(FColor(240, 142, 28, 1)));
	c_info.background_color.Add(FLinearColor(FColor(249, 181, 26, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(134, 151, 91, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(101, 111, 53, 1)));
	c_info.normal_f = { 1,4,5,6,7,16,17,19,20,29,30,37,38,39,48,49,51,59,61,62,72,73,74,75,76,77,78,79,80,81,82,83,84,85,94,95,96,97,117,118,119,120,121,122,124,125,126,143,144,145,146,163,164,166,169,171,204,205,206,229,278,279 };
	c_info.normal_s = {};
	c_info.cvd_f = {};
	c_info.cvd_s = {};
	c_info.invisible = {};
	c_info.validResponses = { "7", "0-", "0-", "0-", "0-" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//16
	c_info.background_color.Add(FLinearColor(FColor(250, 159, 143, 1)));
	c_info.background_color.Add(FLinearColor(FColor(179, 57, 44, 1)));
	c_info.background_color.Add(FLinearColor(FColor(239, 152, 18, 1)));
	c_info.background_color.Add(FLinearColor(FColor(253, 195, 28, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(178, 181, 110, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(124, 141, 81, 1)));
	c_info.normal_f = { 25,48,49,50,51,52,53,54,55,56,81,82,83,85,86,87,89,90,91,124,125,126,127,128,137,138,139,175,181,184,185,197,198,199,200,202,269,270,271,354,355 };
	c_info.normal_s = { 1,4,5,6,7,16,17,18,19,20,21,30,31,32,35,36,39,40,41,62,68,69,70,73,74,75,76,77,96,97,98,103,104,105,106,107,108,109,118,119,146,147,152,153,163,164,208,209,210,211,212,224,227,228,229,230,231,285,286,287,288,304,305,306,307,308,309,310,311,312,313 };
	c_info.cvd_f = {};
	c_info.cvd_s = {};
	c_info.invisible = {};
	c_info.validResponses = { "16", "0-", "0-", "0-", "0-" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//73
	c_info.background_color.Add(FLinearColor(FColor(172, 50, 37, 1)));
	c_info.background_color.Add(FLinearColor(FColor(247, 148, 135, 1)));
	c_info.background_color.Add(FLinearColor(FColor(246, 151, 20, 1)));
	c_info.background_color.Add(FLinearColor(FColor(245, 185, 27, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(169, 173, 102, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(101, 119, 59, 1)));
	c_info.normal_f = { 23,24,25,46,45,47,50,52,53,54,55,80,81,86,87,88,89,90,114,122,123,124,125,136,137,138,139,171,172,173,174,175,178,179,180,182,183,196,197,198,246,247,248,249,250,251,252,253,266,268,269,333,348,354 };
	c_info.normal_s = { 30,35,36,39,61,62,63,70,72,73,74,75,76,94,95,96,97,98,104,105,107,108,109,110,111,113,118,119,144,145,146,147,153,154,155,156,157,158,159,163,164,208,209,210,211,212,213,222,223,224,225,229,230,231,285,286,287,288,305,307,309,310,311,312,313,314 };
	c_info.cvd_f = {};
	c_info.cvd_s = {};
	c_info.invisible = {};
	c_info.validResponses = { "73", "0-", "0-", "0-", "0-" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//5-D
	c_info.background_color.Add(FLinearColor(FColor(129, 69, 35, 1)));
	c_info.background_color.Add(FLinearColor(FColor(169, 115, 62, 1)));
	c_info.background_color.Add(FLinearColor(FColor(218, 116, 73, 1)));
	c_info.background_color.Add(FLinearColor(FColor(85, 127, 58, 1)));
	c_info.background_color.Add(FLinearColor(FColor(180, 160, 97, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(144, 123, 107, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(164, 181, 121, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(224, 126, 105, 1)));
	c_info.normal_f = { 23,24,25,48,49,50,51,52,64,65,91,98,99,100,139,140,147,148,149,168,169,170,171,199,208,209,234,238,317,318 };
	c_info.normal_s = {};
	c_info.cvd_f = { 2,8,9,10,11,12,23,34,36,37,47,66,67,71,80,81,101,124,150,151,165,167,203,204,235,236,237,274,276 };
	c_info.cvd_s = {};
	c_info.invisible = { 7,8,19,20,21,22,35,68,69,70,97,102,103,106,123,141,145,146,172,173,174,175,176,200,201,202,204,205,206,239,240,241,270,271,273,279,325,326 };
	c_info.validResponses = { "0-", "5-", "5-", "5-", "5-" };
	all_plates.Add(c_info);
	Cleareverything(c_info);

	//45-D
	c_info.background_color.Add(FLinearColor(FColor(123, 65, 38, 1)));
	c_info.background_color.Add(FLinearColor(FColor(157, 95, 46, 1)));
	c_info.background_color.Add(FLinearColor(FColor(209, 100, 59, 1)));
	c_info.background_color.Add(FLinearColor(FColor(65, 98, 36, 1)));
	c_info.background_color.Add(FLinearColor(FColor(169, 149, 78, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(138, 117, 101, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(145, 171, 108, 1)));
	c_info.invisible_color.Add(FLinearColor(FColor(229, 123, 105, 1)));
	c_info.normal_f = { 2,3,11,12,15,16,23,24,25,29,30,48,49,50,58,59,60,81,82,92,141,193,194,195,259,260,261,262,263,347 };
	c_info.normal_s = { 56,109,110,111,113,118,158,162,163,164,208,209,228,229,230,284,285 };
	c_info.cvd_f = { 45,79,80,122,123,124,132,133,135,136,171,173,174,175,189,190,191,192,202,271,273,274 };
	c_info.cvd_s = { 62,63,64,96,97,98,99,145,146,147,148,153,154,155,156,157,158,205,213,218,219,225,227,288,292,302,307,308,309,310,311,312,313,314,403,404 };
	c_info.invisible = { 27,28,56,57,83,84,85,88,89,90,91,92,129,130,131,137,138,139,140,200,201,264,348,36,37,38,70,71,72,73,112,114,116,210,214,215,216,217,286,287,289 };
	c_info.validResponses = { "0-", "45", "45", "45", "45" };
	all_plates.Add(c_info);
	Cleareverything(c_info);


	//26-6
	c_info.background_color.Add(FLinearColor(FColor(67, 44, 44, 1)));
	c_info.background_color.Add(FLinearColor(FColor(112, 89, 89, 1)));
	c_info.background_color.Add(FLinearColor(FColor(162, 141, 125, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(224, 48, 37, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(237, 89, 92, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(149, 44, 72, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(205, 92, 115, 1)));
	c_info.normal_f = { 2,8,9,10,11,12,22,25,26,43,46,45,44,54,55,56,61,79,80,88,93,94,122,123,129,130,136,137,141,142,173,175,176,177,178,180,182,183,184,185,186,187,195,196,198,199,200,201,202,246,248,249,250,251,252,253,265,266,267,268,269,270,271,350,352,353,354,457,458 };
	c_info.normal_s = {  };
	c_info.cvd_f = {  };
	c_info.cvd_s = { 5,6,7,16,17,18,19,20,31,32,33,35,36,37,38,39,40,62,63,70,71,72,73,74,75,76,98,111,112,113,118,119,147,148,154,155,158,163,164,209,210,213,214,215,216,217,218,219,229,230,231,232,286,287,288,289,290,291,292,293,301,302,304,305,306,307,308,309,312,313,314,315,402,403,404,405 };
	c_info.invisible = {  };
	c_info.validResponses = { "26", "6-", "26", "2-", "26" };
	all_plates.Add(c_info);
	Cleareverything(c_info);


	//42-2
	c_info.background_color.Add(FLinearColor(FColor(58, 43, 40, 1)));
	c_info.background_color.Add(FLinearColor(FColor(146, 125, 109, 1)));
	c_info.background_color.Add(FLinearColor(FColor(113, 90, 90, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(241, 94, 97, 1)));
	c_info.normal_color.Add(FLinearColor(FColor(217, 42, 24, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(219, 132, 138, 1)));
	c_info.cvd_color.Add(FLinearColor(FColor(152, 47, 71, 1)));
	c_info.normal_f = { 20,21,34,37,38,39,40,41,42,62,63,64,65,66,67,68,69,72,74,77,78,96,97,98,99,100,101,105,106,107,108,110,120,121,145,147,148,149,156,157,158,164,165,166,167,169,209,210,218,219,220,221,222,223,224,230,231,232,233,234,235,286,287,288,289,290,291,294,303,304,305,306,307,308,309,310,312,313,314,315,374 };
	c_info.normal_s = {  };
	c_info.cvd_f = {  };
	c_info.cvd_s = { 11,12,15,16,23,24,25,26,27,29,30,46,47,48,49,50,56,57,58,59,60,61,80,81,82,83,84,85,89,90,91,92,123,124,129,130,132,133,136,137,138,139,140,141,175,189,191,192,193,194,195,196,197,200,201,202,203,240,261,262,263,264,265,266,270,271,272,347,348,349,350,351,355,454 };
	c_info.invisible = { };
	c_info.validResponses = { "42", "2-", "42", "4-", "42" };
	all_plates.Add(c_info);
	Cleareverything(c_info);
}


void AEssentials::ColorThesePlates(TArray<AStaticMeshActor*> ovalPlates, int32 coloredPlate)
{
	int32 selected_color;


	//background coloring
	for (int32 i = 0; i < ovalPlates.Num(); i++) {
		selected_color = FMath::RandRange(0, all_plates[coloredPlate].background_color.Num()-1);
		UMaterialInstanceDynamic* plate_material = ovalPlates[i]->GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamic(0);
		FLinearColor current_color = all_plates[coloredPlate].background_color[selected_color];
		if (plate_material) 
		{
			plate_material->SetVectorParameterValue(TEXT("plate"), current_color);
		}
	}

	//normal coloring

	for (int32 i = 0; i < all_plates[coloredPlate].normal_f.Num(); i++) {
		selected_color = FMath::RandRange(0, all_plates[coloredPlate].normal_color.Num() - 1);
		int32 j = all_plates[coloredPlate].normal_f[i];
		j = j > 211 ? j : j - 1;
		UMaterialInstanceDynamic* plate_material = ovalPlates[j]->GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamic(0);
		FLinearColor current_color = all_plates[coloredPlate].normal_color[selected_color];
		if (plate_material)
		{
			plate_material->SetVectorParameterValue(TEXT("plate"), current_color);
		}
	}

	for (int32 i = 0; i < all_plates[coloredPlate].normal_s.Num(); i++) {
		selected_color = FMath::RandRange(0, all_plates[coloredPlate].normal_color.Num() - 1);
		int32 j = all_plates[coloredPlate].normal_s[i];
		j = j > 211 ? j : j - 1;
		UMaterialInstanceDynamic* plate_material = ovalPlates[j]->GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamic(0);
		FLinearColor current_color = all_plates[coloredPlate].normal_color[selected_color];
		if (plate_material)
		{
			plate_material->SetVectorParameterValue(TEXT("plate"), current_color);
		}
	}

	//cvd coloring
	for (int32 i = 0; i < all_plates[coloredPlate].cvd_f.Num(); i++) {
		selected_color = FMath::RandRange(0, all_plates[coloredPlate].cvd_color.Num() - 1);
		int32 j = all_plates[coloredPlate].cvd_f[i];
		j = j > 211 ? j : j - 1;
		UMaterialInstanceDynamic* plate_material = ovalPlates[j]->GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamic(0);
		FLinearColor current_color = all_plates[coloredPlate].cvd_color[selected_color];
		if (plate_material)
		{
			plate_material->SetVectorParameterValue(TEXT("plate"), current_color);
		}
	}

	for (int32 i = 0; i < all_plates[coloredPlate].cvd_s.Num(); i++) {
		selected_color = FMath::RandRange(0, all_plates[coloredPlate].cvd_color.Num() - 1);
		int32 j = all_plates[coloredPlate].cvd_s[i];
		j = j > 211 ? j : j - 1;
		UMaterialInstanceDynamic* plate_material = ovalPlates[j]->GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamic(0);
		FLinearColor current_color = all_plates[coloredPlate].cvd_color[selected_color];
		if (plate_material)
		{
			plate_material->SetVectorParameterValue(TEXT("plate"), current_color);
		}
	}


	//invisible coloring
	for (int32 i = 0; i < all_plates[coloredPlate].invisible.Num(); i++) {
		selected_color = FMath::RandRange(0, all_plates[coloredPlate].invisible_color.Num() - 1);
		int32 j = all_plates[coloredPlate].invisible[i];
		j = j > 211 ? j : j - 1;
		UMaterialInstanceDynamic* plate_material = ovalPlates[j]->GetStaticMeshComponent()->CreateAndSetMaterialInstanceDynamic(0);
		FLinearColor current_color = all_plates[coloredPlate].invisible_color[selected_color];
		if (plate_material)
		{
			plate_material->SetVectorParameterValue(TEXT("plate"), current_color);
		}
	}
	return;
}

void AEssentials::AssessResponses(TMap<int32, FString> responses, FString& out)
{
	TArray<int32> count = {0, 0, 0, 0, 0};
	
	for (int32 i = 0; i < all_plates.Num(); i++)
	{
		for (int32 j = 0; j < 5; j++)
		{
			if (responses.Find(i)->Equals(all_plates[i].validResponses[j])) count[j]++;
		}
	}
	int32 max = -1, max_idx = -1;
	for (int32 j = 0; j < 5; j++)
	{
		if (max < count[j]) {
			max = count[j];
			max_idx = j;
		}
	}
	TArray<FString> which = { "normal","strong_protan", "mild_protan", "strong_deutan", "mild_deutan" };
	if (max_idx < 0) out = which[max_idx];
	else out = "uncertain";
	return;
}

// Called when the game starts
void AEssentials::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void AEssentials::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// ...
}

