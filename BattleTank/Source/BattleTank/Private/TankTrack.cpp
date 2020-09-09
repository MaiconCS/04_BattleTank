// Copyright AbraceTI Ltd.


#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankTrack.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UTankTrack::BeginPlay() 
{
	Super::BeginPlay();

	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);

}


void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("OnHit"))

	//Drive the tracks
	DriveTrack();
	
	//Apply sideways force
	ApplySidewaysForce();	
	
	CurrentThrottle = 0;

}


void UTankTrack::ApplySidewaysForce()
{

	//UE_LOG(LogTemp, Warning, TEXT("Tick TRACK"))

	//Calculate the slipage speed
	//Work out the required accelelration this frame to correct
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	
	auto DeltaTime = GetWorld()->GetDeltaSeconds();

	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();

	//calculate and aply sideways for ( F = m a )  
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());

	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; //divide by 2 because are 2 tracks

	TankRoot->AddForce(CorrectionForce);

}


void UTankTrack::SetThrottle(float Throttle) 
{
	
	
	//TODO clamp actual throttle value so player can´t overdrive
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + Throttle, -1, 1);
	
}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;

	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
