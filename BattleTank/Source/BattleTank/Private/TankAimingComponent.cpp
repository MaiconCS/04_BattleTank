// Fill out your copyright notice in the Description page of Project Settings.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankAimingComponent.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankBarrel.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; 

	// ...
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet) 
{	
	
	Turret = TurretToSet;

}



void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	
	Barrel = BarrelToSet;

}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//Protect Barrel
	if (!Barrel) { return; }
	

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
		//auto TankName = GetOwner()->GetName();
			//UE_LOG(LogTemp, Warning, TEXT(" %s Aim at %s "), *TankName, *AimDirection.ToString());
		/*pseudo code for move barrel

			start program

		
			see the game through the screen (first thing its happen in a game, camera component???)

			input mouse move left or right (axi x ??)
			input mouse move up dow (axi y ??)
		
		
			output mouse move left or right in camera and turret movement (same move for both ???)
			output mouse move up or down  in camera and barrel movement

			see the game through the screen

			end program

			*/
		
		MoveBarrelTowards(AimDirection);


		auto Time = GetWorld()->GetTimeSeconds();

		UE_LOG(LogTemp, Warning, TEXT("%f: aim solution found"), Time);
	}
	else 
	{
		auto Time = GetWorld()->GetTimeSeconds();

		UE_LOG(LogTemp, Warning, TEXT("%f: no aim solve found"), Time);
	}
}




void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//work out difference between current reaction, and aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	//elevated(-1) down (1) up
	Barrel->Elevated(DeltaRotator.Pitch); 

	Turret->Rotator(DeltaRotator.Yaw);
}	

