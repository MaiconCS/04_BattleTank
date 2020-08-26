// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\PlayerController.h"
#include "TankPlayerController.generated.h"//generetade is last include

class ATankPawn;
;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATankPawn* GetControlledTank();

	virtual void BeginPlay() override;

	void Tick(float DeltaTime);

	//Start the tank moving the barrel so that a shot would hit where
	//the crosshair intersects the world
	void AimTowardsCrosshair();
	
	//return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation)const;

	//max range of the tank (in cm)
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;


	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	//Return hit if is visible = ECC_Visibility (if you see, you hit).
	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;


	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333;

};