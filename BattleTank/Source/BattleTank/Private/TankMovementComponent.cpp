// Fill out your copyright notice in the Description page of Project Settings.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankMovementComponent.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankPawn.h"

UTankMovementComponent::UTankMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;



}

void UTankMovementComponent::IntendMoveForward(float Throw) 
{
	//auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);

};


