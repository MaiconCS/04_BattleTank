// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "BattleTank.h"


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
