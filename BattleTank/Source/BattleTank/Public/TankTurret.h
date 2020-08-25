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
		// left and rigth movement
		void Rotator(float RelativeSpeed);

private:
	//test speed
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxRotationPerSecond = 4;
	
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxRotationDegrees = 180;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinRotationDegrees = -180;
};
