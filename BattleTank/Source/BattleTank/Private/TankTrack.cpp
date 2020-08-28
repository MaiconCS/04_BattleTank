// Fill out your copyright notice in the Description page of Project Settings.


#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\Public\TankTrack.h"



void UTankTrack::SetThrottle(float Throttle) 
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: Throttle %f"), *Name, Throttle);
	
	//TODO clamp actual throttle value so player can´t overdrive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	
	auto ForceLocation = GetComponentLocation();

	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	
};