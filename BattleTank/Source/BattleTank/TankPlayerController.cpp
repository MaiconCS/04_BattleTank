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

	AimTowardsCrosshair();
}

ATankPawn* ATankPlayerController::GetControlledTank()
{
	return Cast<ATankPawn>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	FVector HitLocation;//out parameter
	if (GetSightRayHitLocation(HitLocation)) //has "side-effect", is going to line trace.
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *HitLocation.ToString());
		//TODO tell controlled tank to aim at this point

	}	
}

//get world location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation)const
{
	OutHitLocation = FVector(1.0);
	return true;

}