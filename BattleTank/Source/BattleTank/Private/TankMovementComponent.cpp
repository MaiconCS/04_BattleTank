// Fill out your copyright notice in the Description page of Project Settings.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankMovementComponent.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankTrack.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankPawn.h"



UTankMovementComponent::UTankMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UTankMovementComponent::RequestDirectMove( const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No Need to call super as We're replacing the functionality
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *TankName, *MoveVelocityString)
}



void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw) 
{	//KEY W
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//TODO prevent double speed due to dual controls
};

void UTankMovementComponent::IntendTurnRight(float Throw)
{	//KEY D
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Intend turn right: %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

};

void UTankMovementComponent::IntendTurnLeft(float Throw)
{	//KEY A	
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Intend turn right: %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);

};

void UTankMovementComponent::IntendMoveBackwards(float Throw)
{	//KEY S 
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("Intend turn right: %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);

};

