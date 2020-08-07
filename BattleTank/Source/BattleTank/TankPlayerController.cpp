// Fill out your copyright notice in the Description page of Project Settings.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\TankPlayerController.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Engine\World.h"


#define OUT //does nothing


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
		//report tank aim to location.
		GetControlledTank()->AimAt(HitLocation);
	}	
}

//get world location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation)const
{
	//Find the crosshair position, in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	

	//"de-project" the screen position of the crosshair toa world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{	
		
		//UE_LOG(LogTemp, Warning, TEXT("Look direction %s"), *LookDirection.ToString());
		//line-trace along that LookDirection, and see what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}
	   
	return true;

}
//!!!!!!!!!!!!!!LineTraceSingleByChannel()!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;

	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	///Line Trace (Ray Cast)
	if (GetWorld()->LineTraceSingleByChannel
		(
			OUT HitResult, // FHitResult &OutHit
			StartLocation,// FVector &Start
			EndLocation, // FVector &End
			ECC_Visibility // hit "target" channel				
		)
			)//if suceeds
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);//if dont hit anything (like sky) return in XYZ all 0(zero)
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const 
{
	//"de-project" the screen position of the crosshair toa world direction
	FVector CameraWorldLocation; // to be discarted
	return DeprojectScreenPositionToWorld
	(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
	
}