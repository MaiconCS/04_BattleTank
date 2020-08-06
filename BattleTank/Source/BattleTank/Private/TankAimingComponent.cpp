// Fill out your copyright notice in the Description page of Project Settings.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankAimingComponent.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet) 
{
	Barrel = BarrelToSet;

}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//Protect Barrel
	if(!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity ///calculate the OutLaunchVelocity, if true
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		//false, //bool bhighArch >> projectile travel is more slow ??
		//0,    //float CollisionRadius.
		//0,   //float OverrrideGravityZ.
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
		}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//work out difference between current reaction, and aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimRotator: %s"), *AimAsRotator.ToString());


	// TODO move the barrel the right amount this frame
	// TODO givem a max elevation speed and the frame time
}	

