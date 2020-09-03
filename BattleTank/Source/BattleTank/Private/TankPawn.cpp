// Copyright AbraceTI Ltd.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankPawn.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankBarrel.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\Projectile.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankAimingcomponent.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankMovementcomponent.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Engine\World.h"




// Sets default values
ATankPawn::ATankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}


void ATankPawn::AimAt(FVector HitLocation)
{	
	if (!TankAimingComponent) { return; }

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

	
}

void ATankPawn::Fire()
{
	bool isReload = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	
	if (Barrel && isReload ) 
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
