// Fill out your copyright notice in the Description page of Project Settings.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankAIController.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Engine\World.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto TankPlayer = GetTankPlayer();

	if (!TankPlayer) {

		UE_LOG(LogTemp, Warning, TEXT("TankAI can't find TankPlayer"));

	}
	else {
	
		UE_LOG(LogTemp, Warning, TEXT("TankAI found TankPlayer %s"), *(GetTankPlayer()->GetName()));
	
	}
	
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!GetTankPlayer()) { return; }
	
	if (GetTankPlayer()) {
		//Todo MOVE TOWARDS the player

		//Aim towards the player
		GetTankPlayer()->AimAt(GetTankPawn()->GetActorLocation());
		//Fire if ready

	}

}

ATankPawn* ATankAIController::GetTankPlayer()
{
	return Cast<ATankPawn>(GetPawn());

}

ATankPawn * ATankAIController::GetTankPawn()
{
	auto TankPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!TankPawn) { return nullptr;}
	
	return Cast<ATankPawn>(TankPawn);
}
