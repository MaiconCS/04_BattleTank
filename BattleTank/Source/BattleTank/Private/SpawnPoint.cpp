// Copyright AbraceTI Ltd.


#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\public\SpawnPoint.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\GameFramework\Actor.h"
#include "C:\Program Files\Epic Games\UE_4.22\Engine\Source\Runtime\Engine\Classes\Kismet\GameplayStatics.h"											  
#include "H:\repos\04_BattleTank\BattleTank\Source\BattleTank\BattleTank.h"

// Sets default values for this component's properties
USpawnPoint::USpawnPoint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	auto NewActor = GetWorld()->SpawnActorDeferred<AActor>(SpawnClass, GetComponentTransform() );
	
	if (!NewActor) return;	

	NewActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);//keep it in that place

	UGameplayStatics::FinishSpawningActor(NewActor, GetComponentTransform());

}


// Called every frame
void USpawnPoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

