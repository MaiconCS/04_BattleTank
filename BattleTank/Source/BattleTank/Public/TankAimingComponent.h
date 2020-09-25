// Copyright AbraceTI Ltd.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Components\ActorComponent.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\Actor.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Kismet\GameplayStatics.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\CoreUObject\Public\UObject\Class.h"
#include "TankAimingComponent.generated.h"//generetade is last include

//Enum for aimming state 
UENUM()

enum class EFiringState:uint8
{	
	Locked,
	Aiming,
	Reloading,
	OutOfAmmo

};


// Foward Declaration
class UTankTurret;
class UTankBarrel;
class AProjectile;



//Holds barrel properties and elevated method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	
	// Sets default values for this component's properties
	UTankAimingComponent();	
	   	
	void AimAt(FVector HitLocation);
	
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;

protected:
	
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:	

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	bool IsBarrelMoving();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	//TSubclassOf<AProjectile> ProjectileBlueprint;//Alternative https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/TSubclassOf/index.html
	TSubclassOf<AProjectile> ProjectileBlueprint;


	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 10000;


	//EditDefaultsOnly make this values default for all tanks, not allow each tank has different values
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;


	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 RoundsLeft = 40;

	double LastFireTime = 0;

	FVector AimDirection;

	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;	

	void MoveBarrelTowards(FVector TargetAimDirection);
	
};