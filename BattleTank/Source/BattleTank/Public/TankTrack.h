// Fill out your copyright notice in the Descript,on page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to aply force to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))

class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Sets a throttle between -1 and +1. 
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

	//Max Force in Newtons
	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000;

};
