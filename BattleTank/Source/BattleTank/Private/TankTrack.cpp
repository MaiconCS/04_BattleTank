// Copyright AbraceTI Ltd.


#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankTrack.h"



void UTankTrack::SetThrottle(float Throttle) 
{
	
	
	//TODO clamp actual throttle value so player can´t overdrive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	
};