// Copyright AbraceTI Ltd.
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankAimingComponent.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankBarrel.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankTurret.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\Misc\AssertionMacros.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; 

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//Protect Barrel
	if (!ensure(Barrel)) { return; }
	

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity ///calculate the OutLaunchVelocity, if true
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false, //bool bhighArch >> projectile travel is more slow ??
		0,    //float CollisionRadius.
		0,   //float OverrrideGravityZ.
		ESuggestProjVelocityTraceOption::DoNotTrace // all down this option is for debugger
		//const FCollisionResponseParams & ResponseParam,
		//const TArray < AActor * > & ActorsToIgnore,
		//bool bDrawDebug
	);
	if (bHaveAimSolution)	    
	{		
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			
		MoveBarrelTowards(AimDirection);
	}
	//UE_LOG(LogTemp, Warning, TEXT("%f: no aim solve found"), Time);
}




void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!ensure(Turret) || !ensure(Barrel) ) { return; }

	//UE_LOG(LogTemp, Warning, TEXT(" HERE "))
	//work out difference between current ROTATION, and aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	//elevated (-1)down (+1)up	
	Turret->Rotator(DeltaRotator.Yaw);

	Barrel->Elevated(DeltaRotator.Pitch);
}	

void UTankAimingComponent::Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{

	Barrel = BarrelToSet;
	Turret = TurretToSet;
}