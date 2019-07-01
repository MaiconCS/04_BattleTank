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

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("TICK OK"));
	//Aim towards chrosshair();
}

ATankPawn* ATankPlayerController::GetControlledTank()
{
	return Cast<ATankPawn>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	//get world location if linetrace through crosshair
	//if it hits the landscape
	//tell controlled tank to aim at this point
	
}
