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
	void Elevated(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSeconds = 2; 

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaximumElevationDegrees = 17; //work fine

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinimunElevationDegrees = -2;  //work fine





};
