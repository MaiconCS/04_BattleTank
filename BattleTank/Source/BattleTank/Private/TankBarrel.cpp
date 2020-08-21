// Fill out your copyright notice in the Description page of Project Settings.


#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankBarrel.h"

void UTankBarrel::Elevated(float RelativeSpeed)
{
	// TODO move the barrel the right amount this frame	
	// TODO givem a max elevation speed and the frame time

	auto Time = GetWorld()->GetTimeSeconds();

	UE_LOG(LogTemp, Warning, TEXT("%f: barrel elevated: %f"), Time, RelativeSpeed);

}