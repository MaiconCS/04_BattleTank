// Copyright AbraceTI Ltd.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\Pawn.h"
#include "TankPawn.generated.h"//generetade is last include



UCLASS()
class BATTLETANK_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	//Called By the Engine when actor damage is deal
	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const & DamageEvent,
		class AController * EventInstigator,
		AActor * DamageCauser
	)
	override;

	//Return Current Health as a percentage of starting health, between 0 and 1.
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

protected:


private:	
	// Sets default values for this pawn's properties
	ATankPawn();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentlyHealth = StartingHealth;

	//float DamageAmount;
	

	virtual void BeginPlay() override;

	
};
