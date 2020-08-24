// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Components\StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()


public:
	// -1 is max downard speed, and +1 is max up movement
	void Elevated(float RelativeSpeed);

private:
	// test between 2 to 5
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSeconds = 4;  
	// 10 to 20 realistic
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaximumElevationDegrees = 16; 
	//-3.5 realistic, 180 turret not make the barrel into the tank
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinimunElevationDegrees = -3.5; 





};
