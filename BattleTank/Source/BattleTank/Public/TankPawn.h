// Copyright AbraceTI Ltd.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\Pawn.h"
#include "TankPawn.generated.h"//generetade is last include

//Forward declarations
class UTankTurret;
class UTankBarrel;
class UTankAimingComponent;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATankPawn : public APawn
{
	GENERATED_BODY()

public:
	
	void AimAt(FVector HitLocation);


	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

protected:
	//Property of a C++ method readable from blueprint
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;


private:

	

	// Sets default values for this pawn's properties
	ATankPawn();

		virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 10000; 


	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		//TSubclassOf<AProjectile> ProjectileBlueprint;//Alternative https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/TSubclassOf/index.html
		TSubclassOf<AProjectile> ProjectileBlueprint;

	
	//local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;//TODO remove

	//EditDefaultsOnly make this values default for all tanks, not allow each tank has different values
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

};
