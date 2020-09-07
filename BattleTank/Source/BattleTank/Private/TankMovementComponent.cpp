// Copyright AbraceTI Ltd.

#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankMovementComponent.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\Math\Vector.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankTrack.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankPawn.h"



void UTankMovementComponent::RequestDirectMove( const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//No Need to call super as We're replacing the functionality
	
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);

	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForward, AIForwardIntention).Z;

	IntendTurnRight(RightThrow);
	
	//UE_LOG(LogTemp, Warning, TEXT("Right: %f, forward %f"), RightThrow, ForwardThrow)
}


void UTankMovementComponent::IntendMoveForward(float Throw) 
{	//KEY W
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
		
};

void UTankMovementComponent::IntendTurnRight(float Throw)
{	//KEY D
	
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

};

void UTankMovementComponent::IntendTurnLeft(float Throw)
{	//KEY A	

	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);

};

void UTankMovementComponent::IntendMoveBackwards(float Throw)
{	//KEY S 
	
	if (!ensure(LeftTrack && RightTrack)) { return; }

	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);

};

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}
