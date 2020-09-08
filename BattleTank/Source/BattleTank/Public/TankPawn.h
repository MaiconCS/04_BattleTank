// Copyright AbraceTI Ltd.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\Pawn.h"
#include "TankPawn.generated.h"//generetade is last include

//Forward declarations
//class UTankTurret; ReFactoring
//class UTankBarrel; ReFactoring
//class UTankAimingComponent; ReFactoring
//class AProjectile; ReFactoring


UCLASS()
class BATTLETANK_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	
	//void AimAt(FVector HitLocation); ReFactoring


	/* ReFactoring
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();
	*/

protected:
	/* ReFactoring

	//Property of a C++ method readable from blueprint
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;
	
	*/

private:	

	// Sets default values for this pawn's properties
	ATankPawn();

	virtual void BeginPlay() override;

	/* ReFactoring 
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 10000; 
	*/

	/* ReFactoring
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	//TSubclassOf<AProjectile> ProjectileBlueprint;//Alternative https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/TSubclassOf/index.html
	TSubclassOf<AProjectile> ProjectileBlueprint;
	*/

	/* ReFactoring
	//local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;//TODO remove
	*/

	/* ReFactoring
	//EditDefaultsOnly make this values default for all tanks, not allow each tank has different values
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;
	*/
};
