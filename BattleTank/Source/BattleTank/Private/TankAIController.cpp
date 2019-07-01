// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {

		UE_LOG(LogTemp, Warning, TEXT("TankAI No Possessed"));

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAI Possessed %s"), *(ControlledTank->GetName()));

	}
	
}
ATankPawn* ATankAIController::GetControlledTank() 
{
	return Cast<ATankPawn>(GetPawn());

}
