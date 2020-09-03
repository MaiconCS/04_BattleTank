// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Components\StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
		// -1 is max downard speed, and +1 is max up movement
		void Rotator(float RelativeSpeed);

private:
	//test speed
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxRotationPerSecond = 10;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxRotationDegrees = 179.9f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MinRotationDegrees = -179.9f;
};
