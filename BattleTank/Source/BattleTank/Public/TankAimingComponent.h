// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Components\ActorComponent.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\Actor.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Kismet\GameplayStatics.h"
#include "TankAimingComponent.generated.h"//generetade is last include

// Foward Declaration
class UTankTurret;
class UTankBarrel;


//Holds barrel properties and elevated method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetTurretReference(UTankTurret* TurretToSet);

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	
	



	void AimAt(FVector HitLocation, float LaunchSpeed);


	   	

private:	
	
	UTankTurret* Turret = nullptr;

	UTankBarrel* Barrel = nullptr;

	void MoveTurretTowards(FVector AimDirection);

	void MoveBarrelTowards(FVector AimDirection);
		
};
