// Copyright AbraceTI Ltd.


#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankTrack.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\SprungWheel.h"
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\SpawnPoint.h"



UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}
/*No need, fixed suspesion in tank
void UTankTrack::BeginPlay() 
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);

}
*/
/*No need, fixed suspesion in tank
void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Warning, TEXT("OnHit"))


	
	//Apply sideways force
	ApplySidewaysForce();	
	
	CurrentThrottle = 0;

}*/
/*No need, fixed suspesion in tank
void UTankTrack::ApplySidewaysForce()
{
	
	//Calculate the slipage speed
	//Work out the required acceleration this frame to correct
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	
	auto DeltaTime = GetWorld()->GetDeltaSeconds();

	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	//calculate and aply sideways for ( F = m a )  
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());

	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; //divide by 2 because are 2 tracks

	TankRoot->AddForce(CorrectionForce);

}*/


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
