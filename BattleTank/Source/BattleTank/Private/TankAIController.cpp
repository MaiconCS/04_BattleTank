// Copyright AbraceTI Ltd.


#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankAIController.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankAimingComponent.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\Misc\AssertionMacros.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Engine\World.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankPawn.h" // Implement OnDeath() delegate
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"
//Depends on movement component via pathfinding system


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::SetPawn(APawn * InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn) 
	{
		auto PossessedTank = Cast<ATankPawn>(InPawn);
		if (!PossessedTank) { return; }
		//TODO subscribe our local method to the  tank death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);


	}
}

void ATankAIController::OnPossessedTankDeath()
{
	//UE_LOG(LogTemp, Warning, TEXT(" Received delegate broadcasting ") )
	
	if (!ensure(GetPawn())) { return; } //TODO remove ensure if ok
	GetPawn()->DetachFromControllerPendingDestroy();

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	///tank controlled by player
	//ReFactoring
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	///this is the tank itself	
	auto ControlledTank = GetPawn();
	/*
	Ensure removed from if condition
	Ensure condition failed: PlayerTank && ControlledTank [File:H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Private\TankAIController.cpp] [Line: 53] 
	*/
	if (!(PlayerTank && ControlledTank)) { return;	}
	
	//Todo MOVE TOWARDS the player
	MoveToActor(PlayerTank, AcceptanceRadius); 

	//Aim towards the player( name of the method is different)
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	
	if (!ensure(AimingComponent)) { return; }
	AimingComponent->AimAt(PlayerTank->GetActorLocation());


	if (AimingComponent->GetFiringState() == EFiringState::Locked) 
	{
		AimingComponent->Fire();
	}
	

}


