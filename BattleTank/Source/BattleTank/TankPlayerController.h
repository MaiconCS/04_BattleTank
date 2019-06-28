// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/TankPawn.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"//generetade is last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATankPawn* GetControlledTank();
	
	virtual void BeginPlay() override;
};
