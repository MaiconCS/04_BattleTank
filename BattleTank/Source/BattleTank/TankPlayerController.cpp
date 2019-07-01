// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayer No Possessed"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayer possessed %s"), *(ControlledTank->GetName()));
	}
	
}

ATankPawn* ATankPlayerController::GetControlledTank()
{
	return Cast<ATankPawn>(GetPawn());
}
