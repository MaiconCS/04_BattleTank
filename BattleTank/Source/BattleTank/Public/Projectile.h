// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Core\Public\CoreMinimal.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\Actor.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\ProjectileMovementComponent.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	void LaunchProjectile(float Speed);

//protected only for tick ??
protected:
	// Called every frame
	virtual void Tick(float DeltaTime) override;	
	
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	//https://docs.unrealengine.com/en-US/API/Runtime/Engine/GameFramework/UProjectileMovementComponent/index.html
	UProjectileMovementComponent* ProjectileMovement = nullptr;


};
