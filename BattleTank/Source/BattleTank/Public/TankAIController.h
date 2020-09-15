// Copyright AbraceTI Ltd.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\AIModule\Classes\AIController.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\TankPlayerController.h"
#include "TankAIController.generated.h"//generetade is last include


//Forward declarations
class ATankAimingComponent;
/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()


protected:

	//How close can the AI get
	UPROPERTY(EditAnywhere, Category = "Range AI") //Consider EditDefaultsOnly
	float AcceptanceRadius = 10000;

private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
};
