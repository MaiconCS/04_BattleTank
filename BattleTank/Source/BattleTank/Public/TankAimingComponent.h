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
	Reloading

};


// Foward Declaration
class UTankTurret;
class UTankBarrel;


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


	//void AimAt(FVector HitLocation, float LaunchSpeed); ReFactoring

	void AimAt(FVector HitLocation);

protected:
	
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Aiming;

private:	

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 10000;
	
	UTankTurret* Turret = nullptr;
	UTankBarrel* Barrel = nullptr;	

	void MoveBarrelTowards(FVector AimDirection);	

};
