// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorCalibration.h"

// Sets default values
AColorCalibration::AColorCalibration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AColorCalibration::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AColorCalibration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


bool AColorCalibration::solve(FColor_primaries_lxy recorded) {
	//first convert from lxy
	FColor_XYZ temps[4];
	convertFromlxyToXYZ(recorded.Red, temps[0]);
	convertFromlxyToXYZ(recorded.Green, temps[1]);
	convertFromlxyToXYZ(recorded.Blue, temps[2]);
	convertFromlxyToXYZ(recorded.White, temps[3]);

	cv::Mat src1(4, 3, CV_32F, cv::Scalar(0)), src2(4, 3, CV_32F, cv::Scalar(0));
	src1.at<float>(0, 0) = temps[0].X;
	src1.at<float>(0, 1) = temps[0].Y;
	src1.at<float>(0, 2) = temps[0].Z;

	src1.at<float>(1, 0) = temps[1].X;
	src1.at<float>(1, 1) = temps[1].Y;
	src1.at<float>(1, 2) = temps[1].Z;

	src1.at<float>(2, 0) = temps[2].X;
	src1.at<float>(2, 1) = temps[2].Y;
	src1.at<float>(2, 2) = temps[2].Z;

	src1.at<float>(3, 0) = temps[3].X;
	src1.at<float>(3, 1) = temps[3].Y;
	src1.at<float>(3, 2) = temps[3].Z;

	src2.at<float>(0, 0) = 1;
	src2.at<float>(0, 1) = 0;
	src2.at<float>(0, 2) = 0;

	src2.at<float>(1, 0) = 0;
	src2.at<float>(1, 1) = 1;
	src2.at<float>(1, 2) = 0;

	src2.at<float>(2, 0) = 0;
	src2.at<float>(2, 1) = 0;
	src2.at<float>(2, 2) = 1;

	src2.at<float>(3, 0) = 1;
	src2.at<float>(3, 1) = 1;
	src2.at<float>(3, 2) = 1;
	bool done = cv::solve(src1, src2, XYZ_to_RGB, cv::DECOMP_SVD);
	RGB_to_XYZ = XYZ_to_RGB.inv(cv::DECOMP_SVD);
	return done;
}

void AColorCalibration::convertFromlxy(FColor_lxy lxy, FLinearColor& retColor)
{
	FColor_XYZ temp;
	convertFromlxyToXYZ(lxy, temp);

}

void AColorCalibration::convertFromlxyToXYZ(FColor_lxy lxy, FColor_XYZ& retColor)
{
	float Y, x, y;
	Y = lxy.l / 100.0f;
	x = lxy.x;
	y = lxy.y;
	if (y == 0.0f) {
		retColor.X = 0.0f;
		retColor.Y = 0.0f;
		retColor.Z = 0.0f;
	}
	else {
		retColor.X = x * Y / y;
		retColor.Y = Y;
		retColor.Z = (1 - x - y) * Y / y;
	}
}

void AColorCalibration::convertFromLuv(FColor_Luv Luv, FLinearColor& retColor)
{
	float d;
	FColor_lxy lxy;
	lxy.l = Luv.L;
	d = 6 * Luv.u - 16 * Luv.v + 12;
	lxy.x = 9 * Luv.u / d;
	lxy.y = 4 * Luv.v / d;
	convertFromlxy(lxy, retColor);
}

void AColorCalibration::convertFromLuvToXYZ(FColor_Luv Luv, FColor_XYZ& retColor)
{
	float d;
	FColor_lxy lxy;
	lxy.l = Luv.L;
	d = 6 * Luv.u - 16 * Luv.v + 12;
	lxy.x = 9 * Luv.u / d;
	lxy.y = 4 * Luv.v / d;
	convertFromlxyToXYZ(lxy, retColor);
}

void AColorCalibration::convertFromXYZ(FColor_XYZ XYZ, FLinearColor& retColor)
{
	cv::Mat temp(1, 3, CV_32F, cv::Scalar(0));
	temp.at<float>(0, 0) = XYZ.X;
	temp.at<float>(0, 1) = XYZ.Y;
	temp.at<float>(0, 2) = XYZ.Z;

	cv::Mat dst;
	cv::multiply(temp, XYZ_to_RGB, dst);
	retColor.R = dst.at<float>(0, 0);
	retColor.G = dst.at<float>(0, 1);
	retColor.B = dst.at<float>(0, 2);
}

void AColorCalibration::convertFromRGB(FLinearColor RGB, FColor_XYZ& retColor)
{
	cv::Mat temp(1, 3, CV_32F, cv::Scalar(0));
	temp.at<float>(0, 0) = RGB.R;
	temp.at<float>(0, 1) = RGB.G;
	temp.at<float>(0, 2) = RGB.B;

	cv::Mat dst;
	cv::multiply(temp, RGB_to_XYZ, dst);
	retColor.X = dst.at<float>(0, 0);
	retColor.Y = dst.at<float>(0, 1);
	retColor.Z = dst.at<float>(0, 2);
}
