// Fill out your copyright notice in the Description page of Project Settings.


#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankTurret.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\Math\UnrealMathUtility.h"

void UTankTurret::Rotator(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationChange = RelativeSpeed * MaxRotationPerSecond * GetWorld()->DeltaTimeSeconds;

	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	//for realistic setiings clamp rotation
	auto RotationClamp = FMath::Clamp<float>(RawNewRotation, MinRotationDegrees, MaxRotationDegrees);

	SetRelativeRotation(FRotator(0, RotationClamp,  0));
}