// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

		UTankMovementComponent();

		UFUNCTION(BlueprintCallable, Category = Input)
		void IntendMoveForward(float Throw);

};
