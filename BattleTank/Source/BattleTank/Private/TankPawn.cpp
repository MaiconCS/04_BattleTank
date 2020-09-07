// Copyright AbraceTI Ltd.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankPawn.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankBarrel.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\Projectile.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankAimingcomponent.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\Misc\AssertionMacros.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Engine\World.h"




// Sets default values
ATankPawn::ATankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	
	//UE_LOG(LogTemp, Warning, TEXT("%s PREFIX: Tank C++ Construct"), *TankName)
}

void ATankPawn::BeginPlay()
{	
	Super::BeginPlay(); // Needed for BP Begin Play to run



	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

void ATankPawn::AimAt(FVector HitLocation)
{	
	if (!ensure(TankAimingComponent)) { return; }

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

	
}

void ATankPawn::Fire()
{
	if (!ensure (Barrel) ) { return; }

	bool isReload = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	
	if ( isReload ) 
	{ 
		//spaw a projectile at the socket projectile
		auto Projectile = GetWorld()->SpawnActor<AProjectile>
			(
				ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("Projectile")),
				Barrel->GetSocketRotation(FName("Projectile"))
			);

		Projectile->LaunchProjectile(LaunchSpeed);
		
		LastFireTime = FPlatformTime::Seconds();
	}	   
	


}
