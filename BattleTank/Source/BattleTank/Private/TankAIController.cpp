// Copyright AbraceTI Ltd.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankAIController.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankPawn.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\Misc\AssertionMacros.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Engine\World.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"
//Depends on movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	///tank controlled by player	
	auto PlayerTank = Cast<ATankPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
	///this is the tank itself	
	auto ControlledTank = Cast<ATankPawn>(GetPawn());
	
	if (ensure(PlayerTank))
	{
		//Todo MOVE TOWARDS the player
		MoveToActor(PlayerTank, AcceptanceRadius ); //TODO check radius in cm
			   
		//Aim towards the player( name of the method is different)
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
			
		//Fire if ready
		ControlledTank->Fire();//TODO FIRE RATE
			
		
	}

}
