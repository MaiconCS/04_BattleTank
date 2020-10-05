// Copyright AbraceTI Ltd.


#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankTrack.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\SprungWheel.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\SpawnPoint.h"



UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UTankTrack::SetThrottle(float Throttle) 
{		
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	//Drive the tracks
	DriveTrack(CurrentThrottle);
}


TArray<class ASprungWheel*> UTankTrack::GetWheels() const
{	
	TArray<ASprungWheel*> ResultArray;
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children); //USE WITH TArray
	for (USceneComponent* Child : Children) 
	{
		auto SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) { continue; }

		AActor* SpawnedChild = SpawnPointChild->GetSpawnedActor();
		auto SprungWheel = Cast<ASprungWheel>(SpawnedChild);
		if (!SprungWheel) {	continue; }

		ResultArray.Add(SprungWheel);
	}
	return ResultArray;
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{	
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;

	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();

	
	for (ASprungWheel* Wheel : Wheels) 
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}

		
}
