// Fill out your copyright notice in the Description page of Project Settings.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankPawn.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"




// Sets default values
ATankPawn::ATankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//No need to protecet points as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}


void ATankPawn::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}


// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATankPawn::AimAt(FVector HitLocation)
{	
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

	
}


