// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Components\ActorComponent.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\Actor.h"
/// replaced by foward declarition #include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Components\StaticMeshComponent.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Kismet\GameplayStatics.h"
///for debugger #include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Kismet\GameplayStaticsTypes.h"
#include "TankAimingComponent.generated.h"//generetade is last include

class UTankBarrel;// Foward Declarition

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

	//TODO add SetTurretReference
	   	

private:	
	
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
		
};
