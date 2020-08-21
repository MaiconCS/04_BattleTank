// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\AIModule\Classes\AIController.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\TankPlayerController.h"
#include "TankAIController.generated.h"//generetade is last include

//Forward declarations
class ATankPawn;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	///tank controlled by player	
	ATankPawn* GetTankPlayer(); 
	///this is the tank itself	
	ATankPawn* GetTankPawn();  

};
